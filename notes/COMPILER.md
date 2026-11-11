# Compiler

## Evidence (ULES01213)

| Fact | Evidence |
|---|---|
| Metrowerks CodeWarrior for PSP, version 2.4.1.01 | `.comment` of `BOOT.BIN` (file 0x1D24F8): `MW MIPS C Compiler (2.4.1.01)` then `PSP` |
| Static executable linked by the SDK linker layout | `.sceStub.text`, `.lib.ent*`, `.lib.stub*`, `.rodata.sceModuleInfo`, `.rodata.sceResident`, `.rodata.sceNid`, `.rodata.sceVstub` sections |
| No separate `.rodata` | section headers: read-only data sits in `.text` or `.data` (to be located) |
| No source file paths in the strings | `strings BOOT.BIN` |

## Candidates

| Compiler | Where | Status |
|---|---|---|
| `mwccpsp` 2.4.1.01 | not found | the exact build: wanted |
| `mwccpsp_3.0.1_219` | decomp.me compiler archive | first probe (closest available) |
| other `mwccpsp` builds of the decomp.me archive | decomp.me compiler archive | to probe if 3.0.1 build 219 does not match |

Method: `python tools/psp/compiler_probe.py <probe.c> --cc <mwccpsp.exe> -- <flags>`
on small leaf functions (no VFPU), named `func_<vram>` in the probe file; the tool
compares each one with `BOOT.BIN`, relocated fields masked.

## Open questions

- Optimisation flags.
- Whether the code is C or C++ (no mangled names seen yet).
- Location of the read-only data.
