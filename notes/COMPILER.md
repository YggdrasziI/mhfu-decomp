# Compiler

## Evidence

| Fact | Evidence |
|---|---|
| Metrowerks CodeWarrior MIPS toolchain | `.comment` of `BOOT.BIN` in all three versions: `MW MIPS C Compiler (2.4.1.01)` then `PSP` (ULES01213: file 0x1D24F8) |
| Static executable linked by the SDK linker layout | `.sceStub.text`, `.lib.ent*`, `.lib.stub*`, `.rodata.sceModuleInfo`, `.rodata.sceResident`, `.rodata.sceNid`, `.rodata.sceVstub` sections |
| Sony SDK of each version | start-up code calls `sceKernelSetCompiledSdkVersion500_505` in ULES01213 and ULUS10391 (SDK 5.00-5.05), `sceKernelSetCompiledSdkVersion370` in ULJM05500 (SDK 3.70): the library regions of `notes/SPLITS.md` may differ between the Japanese and the Western builds |
| No separate `.rodata` | section headers: read-only data sits in `.text` or `.data` (to be located) |
| No source file paths in the strings | `strings BOOT.BIN` |

## What "2.4.1.01" means

`MW MIPS C Compiler (x)` is the version of the MIPS back end that Metrowerks shares
between its PlayStation 2 and PSP products, not the product version. Strings found
in the decomp.me compiler archives (2026-11-11):

| Archive | `mwcc*.exe` | `mwld*.exe` |
|---|---|---|
| `mwcps2-2.3.3-000906` | 2.3.1.01 | 2.4.1.01 |
| `mwcps2-2.4-001213` | 2.4.1.01 | 2.4.1.01 |
| `mwcps2-3.0-011126` | 2.4.1.01 | (no linker) |
| `mwcps2-3.0.1-020123` | 2.4.1.01 | (no linker) |
| `mwcps2-3.0.1b210-060308` | 3.0.0 | **2.4.1.01** |
| `mwccpsp_3.0.1_121`, `mwccpsp_3.0.1_219` | 3.0.0 | (no linker) |

The PS2 linker still carries `2.4.1.01` in a 2006 build whose compiler says `3.0.0`,
and the `.comment` of `BOOT.BIN` is a single string, not one per object file: it is
most likely written by the linker (`mwld`). Hypothesis until checked: the string does
not date the compiler, and a `mwccpsp 3.0.1` build (2006-2008, like the game) is a
plausible candidate. Check: link an object with a PSP `mwld` if one is found, or
compare the `.comment` of objects from each compiler (running `mwccpsp.exe` natively
hung on the license manager; run it through wibo as the build does).

An object compiled by `mwccpsp_3.0.1_219` carries `MW MIPS C Compiler (3.0.0)`
without `PSP` (2026-11-11), while `BOOT.BIN` has `(2.4.1.01)` then `PSP`: consistent
with a `.comment` written at link time.

## Probes

`tools/probes/mw_leaf.c`: 7 leaf functions of ULES01213 (string length, table
store and load, struct field store with a tail call, byte test, 4-way switch, float
compare in an array of structs).

| Date | Compiler | Flags | Result |
|---|---|---|---|
| 2026-11-11 | `mwccpsp_3.0.1_219` | `-O0`, `-O2`, `-Op` | 0/7 |
| 2026-11-11 | `mwccpsp_3.0.1_219` | `-O3`, `-O4`, `-O4,p`, `-O4,s`, `-O3,s`, `-O4` + `-opt nointrinsics` / `nopeephole` / `noschedule`, `-inline off` | **5/7**, all identical |
| 2026-11-11 | `mwccpsp_3.0.1` builds 147, 151, 180, 192, 201, 205, 210, 219 | `-O4` | 5/7, identical output |
| 2026-11-11 | `mwccpsp_3.0.1` builds 121, 134, 139 | `-O4` | 3/7 (worse code for the byte test, the float compare and the switch) |
| 2026-11-11 | `mwccpsp_3.0.1_219` | `-O4 -char unsigned` | breaks the float compare (`lb` becomes `lbu`): plain `char` is signed |
| 2026-11-11 | `mwccpsp_3.0.1` builds 147 to 219 | `-O3`, `-O4`, `-O4,p`, `-O4,s`, `-O3,s`, `-opt full`, `-opt level=4,space`, `-g`, `-sdatathreshold 0` | **6/7** after the switch fix; still all identical |

Findings so far:

- The game's code is Metrowerks `mwccpsp` output: `addu $rd, $rs, $zero` moves,
  branch-likely with the delay slot filled, identical register use and scheduling
  on 5 of 7 functions.
- Build 147 or later, optimisation `-O3` or higher (the probes do not separate the
  builds from 147 on, nor `-O3` from `-O4`).
- `switch` cases are compared in reverse source order: `func_08866284` compares
  with 2, 1, then 0, so its source lists `case 0`, `case 1`, `case 2` (matches).
- `func_0880EDF8` (string length) still misses: same instructions, the loaded byte
  and the start pointer swap `$v0`/`$v1`. About 30 source forms tried (pointer and
  index loops, `do`/`while`/`for`, MSL's `len = -1` form, C++ and C99 modes), none
  matches. It sits among library string functions (a word-at-a-time `strcpy` with
  the 0x80808080 / 0xFEFEFEFF constants at 0x0880ED70, a case-insensitive compare
  through a character-class table at 0x0880EE10), so it may come from a prebuilt C
  library built with another compiler or version (hypothesis, not checked).

Running mwccpsp natively on Windows: `tools/psp/lmgr_patch.py` (applied by the
compiler download) stubs the FLEXlm checkout like wibo does.

## Small data and read-only data

- No `$gp`-relative access anywhere in `.text` (0 of the loads and stores use
  `($gp)`), although `.rodata.sceModuleInfo` gives a gp value (0x089D3A80). By
  default mwccpsp addresses small globals through `$gp` (`.sbss`, `R_MIPS_GPREL16`);
  `-sdatathreshold 0` turns that off (`%hi`/`%lo` pairs instead). The build uses it
  (`tools/configure.py`). Proof (2026-11-11): the four functions of
  `src/unit_088AEFCC.c` (tests and getters on `u16` / `s8` globals) match with
  `-sdatathreshold 0` and all differ without it (0/4).
- mwccpsp sections, seen on a test object: string literals in `.data` (strings are
  writable by default, `-str readonly` changes it), `const` tables and switch jump
  tables in `.rodata`, one `.text`/`.data`/`.rodata` group per function.
- `BOOT.BIN` has no `.rodata` section: jump tables, float constants and strings all
  sit in `.data` (0x0890F8F8-0x089CBA90). The addresses of the float constants grow
  with the address of the code that loads them (from 0x0890FB38 for code at
  0x0880xxxx up to 0x089B9230 for code at 0x0890xxxx), so the linker seems to lay
  out each object's data in the same order as its code, `.rodata` merged into
  `.data` (inference from the reference pattern, not proven).
- Jump tables (splat `jtbl_`): 5 at 0x08910490-0x08910928, 144 at
  0x08930968-0x0893325C.
- A unit's own data (2026-11-16): each object's `.rodata` is renamed `.data`
  (`rename_sections` in decomp.toml, done by tools/psp/compile.py) and the splat
  yaml gives the unit a `.data` subsegment at the address of its data, cut out of
  the `data` piece (`[0x1306A8, .data, unit_088ADDF4]`, then
  `[0x1306D8, data, data_08932124]`). First case: the two jump tables of
  `unit_088ADDF4` (0x089320F4-0x08932124), linked from the C object, `BOOT.BIN`
  identical. The tables of its two functions follow each other in code order, and
  the next table (0x08932124) belongs to the next function with a `switch`
  (func_088ADEAC): same order as the code, as inferred above. A data piece may now
  start at an address that is not a multiple of 8: tools/psp/assemble.py writes
  `.double` as two words so that the assembler does not align the piece on 8.
- Two data streams per object (2026-11-17): mwccpsp puts switch jump tables in
  `.rodata` and the constant of an initialised local array
  (`s16 t[7] = {...}`, copied to the stack by a loop) in `.data`. In the image
  both follow the code order, the jump tables first (0x08910490-0x0893325C),
  the `.data` constants later, among the strings (`func_0887D884`: table at
  0x08931934, array at 0x089A89E4). So the sections are no longer renamed: a
  unit's jump tables are a `.rodata` entry placed in the `.data` group of the
  linker script (`{ start: 0x12FEE8, type: .rodata, name: unit_0887D884,
  linker_section_order: .data }`) and its `.data` a second entry at its own
  address (`[0x1A6F98, .data, unit_0887D884]`).
- `.data` from 0x089BB8F8 to its end is mostly pointers into `.text` (function
  tables).

## Code at the start of `.text`

The two probe misses are both near the start of `.text`: `func_0880B420` (global
getter: `lui $v1` / `lw $v0, ($v1)`, mwccpsp uses `$v0` for both) and
`func_0880EDF8` (string length, the same kind of register swap), next to library
string functions. All six matching probes are at 0x08822990 or above. Hypothesis:
the start of `.text` is library code built with another compiler or version;
`notes/SPLITS.md` maps it (0x08804000 to about 0x08811C00, and a second such region
from about 0x08904000 to the end of `.text`) and probes it: no mwccpsp build and not
SNC 1.2.7503.0; GCC (psp-gcc 1.3.1 / 1.7.1 at `-O2 -G0`) reproduces one function and
comes within two instructions of another, but is not the exact version.

## C and C++

At least some of the game code is C++. `func_088131B8` and `func_088298E4` turn a
comparison into a value (`xor`/`sltiu` or `sltu`) and then compare that value with 1:

```
lhu   $a3, 0x1E6($a1)        lw    $v0, -0x50EC($v0)
lbu   $a2, 0x28($a2)         andi  $v0, $v0, 0x1
addiu $v1, $zero, 0x1        sltu  $v0, $zero, $v0
xor   $a2, $a3, $a2          bnel  $v0, $v1, ...
sltiu $a2, $a2, 0x1
bne   $a2, $v1, ...
```

In C, mwccpsp folds `(a == b) == 1` and `((x & 1) != 0) != 1` into one branch,
whatever the form tried (local variable, `inline` helper). Compiled as C++, with
`(a == b) == true` and `(bool)(x & 1) == true`, both functions match
(`src/unit_088131B8.cpp`, `src/unit_088298E4.cpp`). So these comparisons involve a
C++ `bool`. Every other unit matches as C as well as C++, so the units stay `.c`
unless C++ is needed. Function names are not mangled because the binary has no
symbols at all, so they are kept as `func_<addr>` with `extern "C"`.

Other C++ shapes, not proven: functions that store a table address in their first
argument and then, when a 16-bit flag is positive, pass it to another function
(`func_0884B010` to `func_08897298`, `func_08860710` to `func_08860760`,
`func_0886159C` to `func_0890BFA4`; `func_088129B8`, `func_08816AE4` and
`func_08816B24` without the store, to `func_0890BFA4`) look like destructors
(`this`, deletion flag, vtable pointer, `operator delete`).

Virtual calls (2026-11-14): mwccpsp loads the target of a call through a vtable
into `$t9` (`lw $t9, 0($a0)`, `lw $t9, 0x10($t9)`, `jalr $t9`) when the source is a
C++ virtual call; a C call through a function pointer read from the same place uses
`$v0`. `func_088DC774` only matches as C++ with a class of three virtual functions,
the call going to the third one: the first slot is at vtable offset 8
(`src/unit_088DC774.cpp`). 108 functions still in assembly call through `$t9`.

Pointers to member functions (2026-11-14). Compiled from a C++ member function
pointer, mwccpsp emits calls to its runtime by name, and the original has the same
calls to 0x0890C370 and 0x0890C3D8:

| Source | mwccpsp output | Original (e.g. func_08864634) |
|---|---|---|
| `if (pmf)` | `addiu $a0, this, off`, `jal __ptmf_test` | `jal func_0890C3D8` with `$a0 = this + 0x3FC` |
| `(this->*pmf)()` | `addu $a0, this`, `jal __ptmf_scall`, `addiu $t9, this, off` (delay slot) | `jal func_0890C370`, `addiu $t9, $s0, 0x3FC` |
| `pmf == pmf2` | `jal __ptmf_cmpr` (`$a0`, `$a1` the two), then `sltu`, `xori` | no caller; 0x0890C3A4 xors the three words of `$a0` and `$a1` and returns `!= 0` |
| `pmf = &A::f` | three `lwc1`/`swc1` from a compiler constant, one `lui` per word | func_08906744, func_0890682C (12-byte constants {0, 0x10 or -1, 0 or a code address}) |

The pointer is three words {this offset, vtable offset, function}: 0x0890C370 adds the
first to `this`, then calls the function directly when the vtable offset is negative,
else through the vtable. So these are named `__ptmf_scall`, `__ptmf_cmpr`, `__ptmf_test`
(config/ULES01213/symbol_addrs.txt); splat had joined `__ptmf_cmpr` to `__ptmf_scall`
(no caller). `(bool) (flags & 1) != 0` gives the `andi`/`sltu`/`beqz` flag test seen
with them.

## Registers kept across a call (2026-11-16)

func_088A6BA0 calls func_088A6A78(&r, x), then func_088A6E44(&r, 0x10000003)
without loading `&r` into $a0 again: the original relies on func_088A6A78 leaving
$a0 alone. mwccpsp 3.0.1 (build 219) reloads it, even with func_088A6A78 defined
earlier in the same file, and has no `-ipa` option. Hypothesis: the original
compiler (2.4.1.01) tracks the registers a callee compiled earlier in the file
uses; if so, other calls between functions of one object will show the same gap.

Second case: func_088AD378 keeps a list pointer in $a3 across its call to
func_088AD2FC (same heap code); with func_088AD2FC defined earlier in the same
file, mwccpsp 3.0.1 still moves the pointer to a saved register (NonMatching
unit_088AD378, 92.87 %). func_088AD4EC passes the heap to func_088AD378 in $a0
left by func_088AD348 (NonMatching unit_088AD4EC, 97.98 %).

## Speed and space (2026-11-16)

`-O4` alone and `-O4,p` (`-opt speed`) give the same code on almost every function,
but not on all, and both kinds exist in the game:

| Function | Original | `-O4` | `-O4,p` |
|---|---|---|---|
| func_0889EB84 (16-word fill loop) | unrolled by 8 | one store per pass | identical |
| func_088A7E44 (`0.000001 * x` in double) | constant as `lui`/`ori` pairs | constant read from the data | identical |
| byte-wise clear of include/unk_msg.h (every user) | one byte per pass | identical | unrolled by 8 |

With `-O4,p` for the whole build, 23 matching functions stop matching (all the
users of the clear helper, func_088662B8, func_088C2CE0); `#pragma opt_unroll_loops
off` around the helper does not bring them back. func_0889EB84 sits between two
users of the helper (func_0889EAE8, func_0889ECB8), so the setting changes inside
what looks like one object (hypothesis: pragmas in the source or in a header, not
the command line). func_088FB2B0 (NonMatching) points the same way: in speed
mode the compiler unrolls its `v /= 12` loop by 8 while the original divides once
per pass; `#pragma opt_unroll_loops off` gives the original loop (hypothesis: the
original source turned unrolling off there). The build keeps `-O4`; a unit that needs the speed setting says
`#pragma optimize_for_size off` at its top, with the reason in its header comment.

The socket functions of 0x088AA370-0x088AAE10 match only with `#pragma
opt_rebuildconditionals off` for three of them (func_088AA520, func_088AA83C,
func_088AAC80); the others there match with or without it. Across the 27
NonMatching units, the pragma changes only func_088415D0 (89.9 % to 95.6 %) and
func_088A8E3C (99.0 % to 98.3 %). Hypothesis: that source file was built with
the option off (pragma or command line), like the unrolling setting above.

mwccpsp calls `__extendsfdf2`, `__muldf3`, `__adddf3` and `__truncdfsf2` for
`(double) f`, `d * d`, `d + d` and `(float) d`; func_088A7E44 calls 0x08905294,
0x08905B10, 0x08905AA4 and 0x089066E0 at those places, so these addresses carry the
names (config/ULES01213/symbol_addrs.txt). They sit in the region labelled "VFPU
code (unidentified)" in notes/SPLITS.md, which therefore also holds the soft-float
library.

## VFPU in `asm` blocks (2026-11-17)

mwccpsp_3.0.1_219 assembles VFPU mnemonics inside an `asm { }` block, with C
pointer locals as base registers:

```c
static inline float sin_vfpu(float x) {
    float r;
    float *px = &x;
    float *pr = &r;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}
```

Matrix registers keep their name: `vmidt.q M000` and `vmidt.q E000` (the
transposed view) assemble to different words; func_088CAA00 needs `E000`
(0xF38380A0), as spimdisasm prints it.

The object holds the same words as func_088429EC at 0x08842A5C-0x08842A6C
(`lv.s` 0xC8400000, `vcst.s` 0xD0650020, `vmul.s` 0x64200000, `vsin.s`
0xD0120001, `sv.s` 0xE8410000), with the same frame shape: the operand stored
to one stack slot, both slot addresses taken first, the result read back with
`lwc1`. `src/unit_088429EC.c` and `src/unit_08841100.cpp` (two sines in one
function) match this way. So VFPU code no longer has to stay in assembly: write
it as an inline helper with an `asm` block. `lv.q` / `sv.q` with pointer
locals are checked too (func_088CE5D4, func_088CEE68), and so are `vrot.q`
with its `[C,0,-S,0]` operand, `vidt.q`, `vmmul.t`, `vtfm3.t` and `vadd.t`
(func_088D28DC, func_088D2B90). What spimdisasm prints as
`vcst.t R203, INVALID_0` (0xD060802B) is written `vcst.t R203, 0`; `.word`
is accepted too. Not checked yet: VFPU register allocation across several
blocks.

Branches work in a block (2026-11-20, func_088D2E18): `bvt 4, label`,
`bvtl`, `bvfl` and `b label` with labels local to the block, also when the
helper is inlined twice. The assembler then adds a `nop` after each branch
unless the block starts with `.set noreorder`; with it the next instruction
is the delay slot, as in the original arc tangent. The `nop` after
`vcmp.s ez` in the normalization is written out (func_088D3ADC).
`vcmp` always takes both operands (`vcmp.s ez, S000, S000`,
`vcmp.p es, C000, C000`). `vpfxd` takes bracketed ranges,
`vpfxd [-1:1],[-1:1],[-1:1],[-1:1]` (0xDE0000FF) and `[0:1]` x4
(0xDE000055); no accepted syntax was found for `vpfxs` / `vpfxt`, a partial
`vpfxd` or `vfim.s` with a negative value, so those are `.word`. Also
checked: `vsub.t`, `vscl.t`, `vdot.t`, `vcrsp.t`, `vrsq.s`, `vrcp.s`,
`vsqrt.s`, `vasin.s`, `vsgn`, `vocp.s`, `vone.s`, `vzero.s`, `vi2f.s`,
`vcmovt.s`, `vdiv.t`, `vneg.t`, `vfad.t`, `vmmul.q`, `vmmov.q`, `vmidt.q`,
`vrot.q` with `[C,S,0,0]`, `[-S,C,0,0]`, `[0,C,S,0]`, `[0,-S,C,0]`.

The phase before such a sine is `K * (float) phase` in the original, with the
constant loaded after the conversion. `ang = phase; ang = K * (float) ang;`
gives it: with a plain `ang` the compiler swaps the `mul.s` operands, with
the conversion inside the product it loads the constant first.
## Candidates

| Compiler | Where | Status |
|---|---|---|
| `mwccpsp_3.0.1` builds 147 to 219 | decomp.me compiler archive | **matching**: 219 used by the build |
| `mwccpsp_3.0.1` builds 121 to 139 | decomp.me compiler archive | ruled out by the probes |
| `mwcps2` 2.4 / 3.0.x | decomp.me compiler archive | same back end family; not needed so far |

Method: `python tools/psp/compiler_probe.py <probe.c> --cc <mwccpsp.exe> -- <flags>`
on small leaf functions (no VFPU), named `func_<vram>` in the probe file; the tool
compares each one with `BOOT.BIN`, relocated fields masked.

## Open questions

- Exact build among 147-219 and whether `-O3` or `-O4`: needs probes that tell them
  apart (larger functions, loops, inlining).
- Which parts are C++ (two functions proven, see C and C++), and which are C.
