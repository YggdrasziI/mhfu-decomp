# References

## Tools

- [splat](https://github.com/ethteck/splat), [spimdisasm](https://github.com/Decompollaborate/spimdisasm),
  [rabbitizer](https://github.com/Decompollaborate/rabbitizer) (Allegrex support).
- [decompals/binutils-mips-ps2-decompals](https://github.com/decompals/binutils-mips-ps2-decompals).
- [objdiff](https://github.com/encounter/objdiff), [m2c](https://github.com/matt-kempster/m2c),
  [decomp-permuter](https://github.com/simonlindholm/decomp-permuter): useful on
  register swaps of functions already above 99 % (one process only on Windows,
  about 10 tries per second); it matched func_08893894.
- [decomp.me compiler archive](https://github.com/decompme/compilers) (`mwccpsp`, `pspsnc`, `psp-gcc` builds).
- [pspdev/gcc](https://github.com/pspdev/gcc) and the prebuilt
  [pspdev toolchain](https://github.com/pspdev/pspdev/releases) (GPL): homebrew GCC
  for the PSP, branches from GCC 4.6.4 to 15.x; not the Sony SDK lineage. Run by the
  `Compiler probe` workflow (`compiler: pspdev-<release tag>`).
- [wibo](https://github.com/decompals/wibo) to run the Windows compiler on Linux.
- [Ghidra](https://github.com/NationalSecurityAgency/ghidra) with
  [ghidra-allegrex](https://github.com/kotcrab/ghidra-allegrex).
- [PPSSPP](https://github.com/hrydgard/ppsspp): runtime debugging, HLE NID tables,
  reference for the PSP loader and `~PSP` decryption (GPL-2.0-or-later: behaviour
  only, no code copied).

## Reference projects

- [sotn-decomp](https://github.com/Xeeynamo/sotn-decomp): PSP version of Castlevania:
  Symphony of the Night, built with Metrowerks (`mwccpsp`) through
  [mwccgap](https://github.com/mkst/mwccgap). AGPL-3.0: ideas only.
