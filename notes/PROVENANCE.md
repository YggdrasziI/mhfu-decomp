# Provenance of reused code and data

Every file, function or data set taken from another project, with the project, its
commit, its license and the changes made.

## Shared tools (`tools/psp/`)

The [psp-decomp-tools](https://github.com/YggdrasziI/psp-decomp-tools) submodule, the
owner's own project (CC0-1.0); its README lists the provenance of each tool.

## Build scripts (`tools/`)

| Our file | Source | Changes |
|---|---|---|
| `tools/configure.py` | the owner's jd-tlf-decomp project (CC0-1.0) | modules and versions from `decomp.toml`, relocation step only for PRX modules, Metrowerks compiler |
| `tools/extract.py` | the owner's jd-tlf-decomp project (CC0-1.0) | versions and files of this game |

`LICENSE` (CC0-1.0) is the same as the sibling projects'.

## IJG JPEG library, release 6b (`src/jpeg-6b/`)

The game links the Independent JPEG Group's library. Evidence (2026-11-20): the
unmodified sources of release 6b, built with the project's compiler, give the
original code byte for byte - all 4 functions of `jcomapi.c` at 0x088DE804, 6 of the
9 functions of `jdapimin.c` from 0x088DE8EC and 3 of the 6 of `jdapistd.c` from
0x088DEF50, each following the previous one exactly; the other 6 functions are not
in the image (hypothesis: unused, dropped by the original linker).

- Source: `jpegsrc.v6b.tar.gz` from https://www.ijg.org/files/ (SHA-256
  `75c3ec241e9996504fe02a9ed4d12f16b74ade713972f3db9e65ce95cd27e35d`).
- License: the terms of the library's own `README` ("LEGAL ISSUES"), kept unaltered
  in `src/jpeg-6b/README` as they require. Those files stay under these terms, not
  under the project's `LICENSE`. This software is based in part on the work of the
  Independent JPEG Group.
- Build: `-O4,p` (speed) and the settings of `jconfig.h` (`decomp.toml`,
  `[compiler.dir_flags]`).

| Our file | Source | Changes |
|---|---|---|
| `src/jpeg-6b/README`, `jcomapi.c`, `jdapimin.c`, `jdapistd.c`, `jdcoefct.c`, `jdcolor.c`, `jdhuff.c`, `jdinput.c`, `jdmainct.c`, `jdmarker.c`, `jdmaster.c`, `jdmerge.c`, `jdphuff.c`, `jdpostct.c`, `jdsample.c`, `jidctflt.c`, `jidctfst.c`, `jidctint.c`, `jidctred.c`, `jmemmgr.c`, `jquant1.c`, `jquant2.c`, `jutils.c`, `jinclude.h`, `jpeglib.h`, `jpegint.h`, `jerror.h`, `jdhuff.h`, `jdct.h`, `jmemsys.h` | release 6b | none |
| `src/jpeg-6b/jmorecfg.h` | release 6b | one line: `MAX_COMPONENTS` is 4 instead of 10 (the value its own comment gives for builds short on memory). Evidence: with 10, six words of `jdcoefct.c` differ (private structure 0x18 bytes larger) and `jdinput.c`, `jdmainct.c`, `jdsample.c` do not match; with 4 all their functions are byte for byte |
| `src/jpeg-6b/jconfig.h` | not from the distribution: written for this project from the options of its `jconfig.doc` | `boolean` is `unsigned char` (one byte in the original code); `NO_GETENV` (`jinit_memory_mgr` reads no environment variable) |
| `include/libc/*.h` | written for this project | minimal `<stddef.h>`, `<stdlib.h>`, `<stdio.h>`, `<string.h>` for the library sources |

Only the files a linked unit needs are in the repository; any change to a file of
the distribution is listed in this table.

Functions of a file that are not in the image (`[compiler.drop_functions]` of
`decomp.toml`) are removed from the compiled object by `tools/psp/compile.py`; the
source files are not edited for it.

## Project documents

`SPEC.md` and `notes/` follow the structure of the owner's sibling projects, rewritten
for this game.
