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

## Candidates

| Compiler | Where | Status |
|---|---|---|
| `mwccpsp_3.0.1` builds 121 to 219 (11 builds) | decomp.me compiler archive | first probes |
| `mwcps2` 2.4 / 3.0.x | decomp.me compiler archive | same back end family; fallback if no PSP build matches |

Method: `python tools/psp/compiler_probe.py <probe.c> --cc <mwccpsp.exe> -- <flags>`
on small leaf functions (no VFPU), named `func_<vram>` in the probe file; the tool
compares each one with `BOOT.BIN`, relocated fields masked.

## Open questions

- Which build and optimisation flags.
- Whether the code is C or C++ (no mangled names seen yet).
- Location of the read-only data.
