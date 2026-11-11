# Monster Hunter Freedom Unite (PSP) decompilation — specification

## Goal

Rebuild Monster Hunter Freedom Unite (PlayStation Portable) from C source written from
scratch so that, compiled with the original compiler and flags, it produces game
executables identical byte for byte to the original files.

Out of scope: a port, game assets, any redistribution of game files.

## Versions

| Version | Release | Status |
|---|---|---|
| `ULES01213` | Europe, `DISC_VERSION 1.01`, `PSP_SYSTEM_VER 5.03` | active |
| `ULUS10391` | USA, `DISC_VERSION 1.01`, `PSP_SYSTEM_VER 5.03` | all-assembly build matches |
| `ULJM05500` | Japan, Monster Hunter Portable 2nd G | all-assembly build matches |

Each version has its own `config/<version>/` and `orig/<version>/`; decompilation
work targets the European one first.

| Version | ISO SHA-1 | `BOOT.BIN` | Notes |
|---|---|---|---|
| `ULUS10391` | `f5cb0eaebbf5008bd8d486832229ae97a16bbee6` (886702080 bytes) | 1910332 bytes, SHA-1 `518673c61ef41b4906cedfbe93811d2a974be793` | same layout as `ULES01213`, `.text` 0x120 bytes longer |
| `ULJM05500` | `951d1a360eec83af294a7a51ec4bba08f8633a6e` (895582208 bytes) | 1889772 bytes, SHA-1 `de96bd007ef69b59af9188bee5e7de53987ea2b6` | `.text` 0x1078E0 bytes, 33 import libraries (290 functions); `.data` starts at 0x0890D38C, not 8-aligned, so its first word is a separate splat piece |

A Korean disc (ISO SHA-1 `8d48f800cbe735dab83b3f165101a6a2e3f31ba7`) carries the same
disc ID `ULUS10391` and `DISC_VERSION 1.01`, with `PSP_SYSTEM_VER 5.50`. Its `BOOT.BIN`
is all zeros and its `EBOOT.BIN` (1910672 bytes, same size as the US one) is
encrypted differently: it can only be compared once `EBOOT.BIN` is decrypted.

## Target (ULES01213)

| Item | Value | Evidence |
|---|---|---|
| ISO SHA-1 | `b67f57e2ea0d5a31d3c58eb0c7e54c4ef47ea838` (886702080 bytes) | `tools/extract.py` |
| Target executable | `PSP_GAME/SYSDIR/BOOT.BIN`, 1910044 bytes, SHA-1 `439f0a3454c14225dcbaa457d3102f5be65f1690` | `config/ULES01213/build.sha1` |
| Format | unencrypted static ELF (ET_EXEC, flags 0x10A23001), 300 program headers (1 PT_LOAD, 299 empty overlay slots), 620 section headers, no relocations, no symbol table | `tools/psp/prx_info.py` |
| Program header 0 | file 0x25B4, vram 0x08804000, filesz 0x1C7A90, memsz 0x1561480 | program headers |
| Sections | `.text` 0x08804000 (0x109E38), `.sceStub.text` 0x0890DE38 (0x880), `.lib.*`, `.rodata.sceModuleInfo` 0x0890E980, `.rodata.sceResident`, `.rodata.sceNid`, `.data` 0x0890F8F8 (0xBC198), `.bss` 0x089CBA90; no separate `.rodata` | section headers |
| Module | name `MonsterHunterPortable2ndG`, version 1.1, `$gp` 0x089D3A80 | `.rodata.sceModuleInfo` |
| Entry | `module_start` 0x08906934, `module_stop` 0x08906CD8 | `.lib.ent` (standard SDK export NIDs) |
| Imports | 34 system libraries, 272 functions, all named from their NID | `.lib.stub`, `config/ULES01213/symbol_addrs.boot.txt` |
| Compiler | `.comment`: `MW MIPS C Compiler (2.4.1.01)` | `notes/COMPILER.md` |
| Overlays | 299 sections without data at 5 load addresses (`*_task.ovl`, `emXX.ovl`, `stageNNN.ovl`, `debug.elf`) | `notes/OVERLAYS.md` |

`SYSDIR/EBOOT.BIN` is the encrypted (`~PSP`) form of the same executable: its header
gives an ELF size of 0x1D251C bytes and the entry 0x08906934, both those of
`BOOT.BIN`. Checking this byte for byte needs the decryption (later).

## Toolchain

- splat **0.50.1** (`splat64[mips]`, spimdisasm 1.42.4): assembly, data and linker
  script from `config/ULES01213/splat.boot.yaml`.
- binutils from [decompals/binutils-mips-ps2-decompals](https://github.com/decompals/binutils-mips-ps2-decompals)
  **v0.10** (`as -march=mips32r2 -mabi=32`, `ld`, `objcopy`), downloaded by `ninja`
  into `tools/binutils/`. This GNU as knows neither Allegrex nor the VFPU:
  `tools/psp/vfpu_words.py` turns VFPU instructions and the Allegrex-only ones (`min`,
  `max`, `clz`, `madd`, `wsbw`...) into `.word`, and NaN floats into their bytes.
- objdiff-cli **v3.8.3** (report, diff), objdiff GUI.
- m2c for a first C draft.
- Compiler: Metrowerks CodeWarrior for PSP. The exact build (2.4.1.01) is not
  available; the closest one on decomp.me is tried first (`notes/COMPILER.md`).
- Shared tools: the `tools/psp` submodule
  ([psp-decomp-tools](https://github.com/YggdrasziI/psp-decomp-tools)), configured by
  `decomp.toml`.

## Build pipeline

1. `tools/extract.py`: `BOOT.BIN` from the ISO, SHA-1 checks.
2. splat splits `BOOT.BIN` as is (no relocation step: it is not a PRX): ELF header
   and tail (section headers, `.shstrtab`, `.comment`) as `bin`, `.text` and the
   import stubs as assembly, the module tables as rodata, `.data`, then `.bss`.
3. `as` for assembly (through `tools/psp/assemble.py`), the compiler for `src/`,
   `objcopy -I binary`, then `ld` with the splat linker script and `objcopy -O
   binary`: `build/ULES01213/BOOT.BIN`, checked by `tools/psp/sha1.py`.

## Acceptance criteria

- Every build ends with `build/ULES01213/BOOT.BIN: OK` (`ninja`), locally and in CI.
- A unit is matching only when objdiff reports 100 % for all its functions and data
  and the build still matches. An unfinished function stays assembly.
- Every name, compiler fact or structure layout rests on evidence (strings with their
  address, import/export tables, library signatures, an objdiff diff, a build
  result). Without evidence it is labelled a hypothesis.
- Reused code or data from another project is logged with its commit and license in
  `notes/PROVENANCE.md`.
- No local paths or attribution trailers in the repository
  (`tools/psp/check_traces.py`, pre-commit and CI).

## Naming conventions

- splat default names stay until proven: `func_<vram>`, `D_<vram>`, `jtbl_<vram>`.
- System imports: the NID's name from `tools/psp/nids.txt` (PPSSPP HLE tables).
- Module exports: the standard SDK names of their NIDs (`module_start`...).
- Game units: `src/unit_<start vram>.c` until a source name is proven.
- Code, comments, notes and commit messages are in English.

## Repository layout

```
README.md SPEC.md LICENSE decomp.toml
config/<version>/         build.sha1, splat.boot.yaml, symbol_addrs.txt,
                          symbol_addrs.boot.txt (generated)
orig/<version>/           the ISO and the extracted files (git-ignored)
asm/                      splat output (git-ignored)
build/                    build output (git-ignored)
src/  include/            sources and headers
tools/                    configure.py, extract.py
tools/psp/                shared tools (git submodule)
notes/                    reference documentation
.github/workflows/        CI: rebuild and check the executable in a private image
```
