# Compiler

## Evidence

| Fact | Evidence |
|---|---|
| Metrowerks CodeWarrior MIPS toolchain | `.comment` of `BOOT.BIN` in all three versions: `MW MIPS C Compiler (2.4.1.01)` then `PSP` (ULES01213: file 0x1D24F8) |
| Static executable linked by the SDK linker layout | `.sceStub.text`, `.lib.ent*`, `.lib.stub*`, `.rodata.sceModuleInfo`, `.rodata.sceResident`, `.rodata.sceNid`, `.rodata.sceVstub` sections |
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

Findings so far:

- The game's code is Metrowerks `mwccpsp` output: `addu $rd, $rs, $zero` moves,
  branch-likely with the delay slot filled, identical register use and scheduling
  on 5 of 7 functions.
- Build 147 or later, optimisation `-O3` or higher (the probes do not separate the
  builds from 147 on, nor `-O3` from `-O4`).
- The two misses are most likely source shape: `func_0880EDF8` (string length: same
  instructions, `$v0`/`$v1` swapped; maybe the library's `strlen`, built separately)
  and `func_08866284` (switch on 0/1/2 lowered differently). 15 source variants
  tried, none matches.

Running mwccpsp natively on Windows: `tools/psp/lmgr_patch.py` (applied by the
compiler download) stubs the FLEXlm checkout like wibo does.

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
- Whether the code is C or C++ (no mangled names seen yet).
- Location of the read-only data.
