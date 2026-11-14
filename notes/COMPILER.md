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
