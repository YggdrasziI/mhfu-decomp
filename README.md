Monster Hunter Freedom Unite (PSP)
==================================

> [!IMPORTANT]
> AI Disclosure:
> AI was used for the following tasks:
> - Writing commentary (primarily translating into English and formatting).
> - Documenting and citing the various sources used in the project (see PROVENANCE.md, REFERENCE.md, and more generally the files contained within the "notes" directory).
> - Writing code (C, C++, Python, etc.—I used it as a tool) and reviewing my own work (yes, some code was written by AI, but it was verified by a human; I didn't simply type "Claude, decompile this for me").

A work-in-progress matching decompilation of Monster Hunter Freedom Unite (Monster
Hunter Portable 2nd G) for the PlayStation Portable, built with
[splat](https://github.com/ethteck/splat) and the shared
[psp-decomp-tools](https://github.com/YggdrasziI/psp-decomp-tools).

> [!NOTE]
> No port to PC or other platforms is planned for the time being, but should that change, the link will appear here

This repository does **not** contain any game assets or assembly whatsoever. An
existing copy of the game is required.

Supported versions:

Version   | Release | Input | SHA1 hash
--------- | ------- | ----- | ------------------------------------------
ULES01213 | Monster Hunter Freedom Unite (Europe), `DISC_VERSION 1.01` | ISO | `b67f57e2ea0d5a31d3c58eb0c7e54c4ef47ea838`
ULES01213 | | `PSP_GAME/SYSDIR/BOOT.BIN` | `439f0a3454c14225dcbaa457d3102f5be65f1690`
ULUS10391 | Monster Hunter Freedom Unite (USA), `DISC_VERSION 1.01` | ISO | `f5cb0eaebbf5008bd8d486832229ae97a16bbee6`
ULUS10391 | | `PSP_GAME/SYSDIR/BOOT.BIN` | `518673c61ef41b4906cedfbe93811d2a974be793`
ULJM05500 | Monster Hunter Portable 2nd G (Japan) | ISO | `951d1a360eec83af294a7a51ec4bba08f8633a6e`
ULJM05500 | | `PSP_GAME/SYSDIR/BOOT.BIN` | `de96bd007ef69b59af9188bee5e7de53987ea2b6`

Progress
========

| Release | Disc ID | Progress |
|---|---|---|
| Monster Hunter Freedom Unite (Europe) | `ULES01213` | not measured yet: the whole executable is still assembly |
| Monster Hunter Freedom Unite (USA) | `ULUS10391` | not measured yet |
| Monster Hunter Portable 2nd G (Japan) | `ULJM05500` | not measured yet |

Dependencies
============

- [Python](https://www.python.org/downloads/) 3.11+ in `%PATH%`, then
  `pip install -r tools/requirements.txt`.
- [ninja](https://github.com/ninja-build/ninja/releases) in `%PATH%`
  (`pip install ninja` works too).
- [7-Zip](https://www.7-zip.org/) to extract the ISO.
- On Windows use native tooling; WSL or msys2 are not required.

The MIPS binutils, the compiler (from the decomp.me compiler archive), wibo (on Linux
and macOS) and objdiff-cli are downloaded by the first `ninja` run.

Building
========

1. Clone with the shared tools:

   ```
   git clone --recursive https://github.com/YggdrasziI/mhfu-decomp.git
   ```

2. Copy the ISO to `orig/<version>/` (any file name ending in `.iso`).
3. Run:

   ```
   python tools/extract.py --version <version>
   python tools/configure.py --version <version>
   ninja
   ```

   A build ends with `build/<version>/BOOT.BIN: OK`. The version defaults to
   `ULES01213`.
4. `ninja report` writes the objdiff report (`build/<version>/report.json`);
   `objdiff.json` is there for the objdiff GUI.

Contributors: `python tools/psp/check_traces.py --install-hooks` installs the
pre-commit checks.

Documentation
=============

- `SPEC.md`: target executable, toolchain, build pipeline, acceptance criteria, naming.
- `notes/`: compiler evidence, overlays, references and provenance of reused code.
