# Progress log

`BOOT.BIN` of `ULES01213`, from the objdiff report (`ninja report`): 1089072 bytes of
code and 3573 functions in all, the regions not built by Metrowerks included
(`notes/SPLITS.md`). Every unit listed is at 100 %. The badges and the card in
`progress/ULES01213/` are drawn by `python tools/common/progress_badges.py --record`,
which also appends the `HEAD` commit to `progress/ULES01213/history.csv`.

Commits before `15e9c9d` (first units, from `unit_088A6024` on) were not measured.

| Date | Commit | Matched code | Matched functions | Units | Milestone |
|---|---|---|---|---|---|
| 2026-11-11 | `15e9c9d` | 5584 / 1089072 bytes (0.51 %) | 198 / 3573 | 77 | Hand-written units; two need C++ |
| 2026-11-11 | `f1f4ce3` | 9452 / 1089072 bytes (0.87 %) | 380 / 3573 | 219 | First automated batch: m2c drafts that match as they are |
| 2026-11-11 | `63972ce` | 12044 / 1089072 bytes (1.11 %) | 412 / 3573 | 248 | Same, up to 0x80 bytes |
| 2026-11-11 | `3b31751` | 12668 / 1089072 bytes (1.16 %) | 444 / 3573 | 276 | Calls that pass the incoming arguments |
| 2026-11-11 | `8df885e` | 13100 / 1089072 bytes (1.20 %) | 447 / 3573 | 279 | Drafts up to 0x100 bytes |
| 2026-11-11 | `1e2fb78` | 14532 / 1089072 bytes (1.33 %) | 487 / 3573 | 314 | Unused leading arguments |
| 2026-11-11 | `1da47ed` | 15496 / 1089072 bytes (1.42 %) | 556 / 3573 | 375 | Tail-call forwarders written from their assembly |
| 2026-11-11 | `69ab44c` | 16080 / 1089072 bytes (1.48 %) | 569 / 3573 | 386 | Indexed accesses as arrays, unsigned stores |
| 2026-11-11 | `dba09a7` | 16332 / 1089072 bytes (1.50 %) | 584 / 3573 | 400 | More tail-call forwarders |
| 2026-11-11 | `cd81dfe` | 22692 / 1089072 bytes (2.08 %) | 664 / 3573 | 472 | First batch from `tools/psp/batch_units.py` (m2c prototypes kept) |
| 2026-11-11 | `c830e67` | 25572 / 1089072 bytes (2.35 %) | 676 / 3573 | 484 | `batch_units.py` up to 0x200 bytes, 6 calls |
| 2026-11-11 | `82bbd44` | 34092 / 1089072 bytes (3.13 %) | 774 / 3573 | 566 | Drafts with unknown types kept (as `int`) |
| 2026-11-12 | `73fedbd` | 37140 / 1089072 bytes (3.41 %) | 804 / 3573 | 591 | One argument count per function (`tools/psp/prototypes.py`); known prototypes given to m2c as context |
| 2026-11-12 | `ba091ee` | 40060 / 1089072 bytes (3.68 %) | 847 / 3573 | 624 | Callees still in assembly given to m2c with the argument count they read |
| 2026-11-12 | `b05ac32` | 41020 / 1089072 bytes (3.77 %) | 858 / 3573 | 633 | Indexed loads from a symbol typed by element size |
| 2026-11-12 | `67c8af9` | 41324 / 1089072 bytes (3.79 %) | 862 / 3573 | 637 | Stack buffers sized from the original frame |
| 2026-11-12 | `f84b2f1` | 4.71 % | 977 / 3572 | 739 | Draft fixes in batches: bool flag tests, large field offsets, stack structures |
| 2026-11-13 | `2d515ec` | 6.79 % | 1079 / 3572 | 797 | Call arguments, goto tails written out; progress card by region |
| 2026-11-14 | `3b01c13` | 8.32 % | 1202 / 3573 | 907 | Structures by value, FPU code; `.data` and `.rodata` counted in the report |
| 2026-11-16 | `9646129` | 10.02 % | 1320 / 3573 | 996 | Jump-table functions linked with their tables; NonMatching units; speed setting per unit |
| 2026-11-17 | `4a10c1d` | 14.30 % | 1411 / 3573 | 1085 | Region by region, one function at a time; initialised local arrays as unit `.data` |
| 2026-11-18 | `e57bc89` | 16.50 % | 1506 / 3573 | 1167 | Region around 0x088B0000 |
| 2026-11-19 | `12bf4da` | 20.02 % | 1678 / 3575 | 1264 | VFPU code in `asm` blocks, C++ units with virtual calls |
| 2026-11-20 | `c8059f8` | 25.51 % | 1802 / 3575 | 1312 | IJG JPEG library linked from its unmodified sources |
| 2026-11-21 | `41f80a9` | 436188 / 1089072 bytes (40.05 %) | 2066 / 3576 | 1402 | Region 0x088EF380-0x089038C4 complete but for four functions; build flag `-inline bottomup`; 50 NonMatching functions retried with the newer source forms now match; static callees defined before their callers keep argument registers across calls (three units merged); region 0x088A0000: 0x088A00D0-0x088A4504 matched but for func_088A2498 |
| 2026-11-22 | `0296b3e` | 543940 / 1089072 bytes (49.95 %) | 2390 / 3579 | 1719 | Region 0x088A0000: 0x088A4504-0x088A88C4 matched but for func_088A812C; func_088A9660 matches with its static callee func_088A91F4 (five units merged); region 0x08890000 complete (func_08893894 matched with decomp-permuter), region 0x08880000 complete but for two VFPU functions, region 0x08870000: 0x088701D8-0x088800C0 matched but for func_088727CC (func_08871444 split from func_0887142C) (`__ptmf_null` named), sound wrappers 0x088972A0-0x08897E1C set aside as not Metrowerks (two functions without a return split in symbol_addrs.txt; first variadic functions, `va_start` from the mwccpsp builtins) |
| 2026-11-23 | `9ac6cce` | 585824 / 1089072 bytes (53.79 %) | 2518 / 3579 | 1847 | Region 0x08860000: 0x0886025C-0x08870194 matched but for VFPU code (128 functions; func_0886171C and func_0886477C linked although try_unit.py shows 99.83 / 99.81 %, their only differences being relocations of a spilled `lui`; func_0886AA28 (99.12 %), func_0886BEA4 (99.33 %) and func_0886C59C (99.61 %) left in assembly; func_0886F7FC owns its `s16[35]` initializer as .data) |
| 2026-11-24 | `587993a` | 589856 / 1089072 bytes (54.16 %) | 2539 / 3580 | 1858 | Region 0x08850000, first batch: 0x08850078-0x0885148C (21 functions; func_0885115C split at its tail call, func_088511B4 now a function of its own; func_08850618 left in assembly) |
| 2026-11-24 | `36ab30b` | 593796 / 1089072 bytes (54.52 %) | 2559 / 3580 | 1878 | Region 0x08850000, second batch: 0x08851D3C-0x08853004 (20 functions; func_08852200 needs one `volatile` field; func_08852F1C, func_08852740 and func_08852834 left in assembly) |
| 2026-11-24 | `52ec086` | 603108 / 1089072 bytes (55.38 %) | 2578 / 3580 | 1897 | Region 0x08850000, third batch: 0x088530C4-0x08856BC8 (19 functions; func_088542EC needs C++; func_08855F98 left in assembly at 99.30 %, registers only) |
| 2026-11-24 | `b759d9f` | 606052 / 1089072 bytes (55.65 %) | 2598 / 3580 | 1917 | Region 0x08850000, fourth batch: 0x08856CA0-0x08857E6C (20 functions; func_088575C0 cut out and left in assembly) |
| 2026-11-24 | `5c49c2e` | 612508 / 1089072 bytes (56.24 %) | 2617 / 3580 | 1936 | Region 0x08850000, fifth batch: 0x08857E74-0x08859AE4 (19 of 20 functions; func_08859B44 left in assembly at 86.9 %) |
| 2026-11-24 | `0fd201f` | 618380 / 1089072 bytes (56.78 %) | 2634 / 3580 | 1953 | Region 0x08850000, sixth batch: 0x08859C40-0x0885C124 (17 of 20 functions, two jump tables; func_08859D14, func_0885ACA8, func_0885B3A0 left in assembly) |
| 2026-11-25 | `2a74d00` | 624040 / 1089072 bytes (57.30 %) | 2654 / 3580 | 1973 | Region 0x08850000, seventh batch: 0x0885C13C-0x0885E478 (20 of 20 functions, one jump table) |
| 2026-11-25 | `7aa8427` | 629424 / 1089072 bytes (57.79 %) | 2680 / 3580 | 1999 | Region 0x08850000, eighth batch: 0x0885E478-0x0885FFBC (26 of 26 functions) |
| 2026-11-25 | `72ac3a6` | 639552 / 1089072 bytes (58.72 %) | 2698 / 3580 | 2017 | Region 0x08840000, first batch: 0x08841908-0x08845C68 (18 of 20 functions; func_08843A7C and func_08845C68 NonMatching) |
| 2026-11-26 | `546d811` | 647312 / 1089072 bytes (59.44 %) | 2717 / 3580 | 2036 | Region 0x08840000, second batch: 0x08846FAC-0x0884A958 (19 of 20 functions; func_08849D7C NonMatching) |
| 2026-11-26 | `8f72e79` | 657284 / 1089072 bytes (60.35 %) | 2738 / 3581 | 2056 | Region 0x08840000, third batch: 0x0884A958-0x0884E7FC (20 of 20 functions, plus func_0884E678 found in the piece of func_0884E5B4) |
| 2026-11-26 | `e74e289` | 661244 / 1089072 bytes (60.72 %) | 2761 / 3581 | 2079 | Region 0x08840000, fourth batch: 0x0884E7FC-0x0884FFB8 (23 of 24 functions; func_0884F190 NonMatching) |
| 2026-11-26 | `bbfd3c5` | 664828 / 1089072 bytes (61.05 %) | 2765 / 3581 | 2083 | Region 0x08840000, retry of the leftovers: func_088415D0, func_08843A7C, func_0884424C, func_08845C68 (func_08849D7C 99.21 % and func_0884F190 97.33 % NonMatching) |
| 2026-11-26 | `4e53c55` | 673636 / 1089072 bytes (61.85 %) | 2785 / 3581 | 2103 | Region 0x08830000, first batch: 0x08830078-0x08832548 (20 of 20 functions, one with its jump tables) |
| 2026-11-26 | `2f16450` | 683124 / 1089072 bytes (62.73 %) | 2804 / 3581 | 2122 | Region 0x08830000, second batch: 0x08832684-0x08839B30 (19 of 20 functions; func_08833290 still in assembly, two units with their jump tables, one with an initialised local record) |
| 2026-11-26 | `a3dc3e0` | 698428 / 1089072 bytes (64.13 %) | 2823 / 3581 | 2141 | Region 0x08830000, third batch: 0x08839B30-0x0883DF88 (19 of 20 functions; func_0883A07C NonMatching, two units with an initialised local) |
| 2026-11-26 | `94290d7` | 705004 / 1089072 bytes (64.73 %) | 2829 / 3581 | 2147 | Region 0x08830000, fourth batch: 0x0883DF88-0x08840000 (6 of 6 functions, two with their jump tables, two with initialised locals; func_0883A07C retried to 98.0 %) |
| 2026-11-26 | `e968d4f` | 711972 / 1089072 bytes (65.37 %) | 2849 / 3581 | 2167 | Region 0x08820000, first batch: 0x08820B74-0x08822C58 (20 of 20 functions, one with its jump table) |
| 2026-11-26 | `cd2ce63` | 725088 / 1089072 bytes (66.58 %) | 2868 / 3581 | 2186 | Region 0x08820000, second batch: 0x08822C58-0x0882693C (19 of 20 functions, two with their jump tables, one with an initialised local; func_08825148 NonMatching) |
| 2026-11-26 | `a0ce7c1` | 734452 / 1089072 bytes (67.44 %) | 2887 / 3581 | 2205 | Region 0x08820000, third batch: 0x088269C0-0x088292AC (19 of 20 functions, two with their jump tables; func_088291B4 NonMatching) |
| 2026-11-26 | `bafafda` | 743900 / 1089072 bytes (68.31 %) | 2907 / 3581 | 2225 | Region 0x08820000, fourth batch: 0x088292AC-0x0882B94C (20 of 20 functions) |
| 2026-11-27 | `0135a77` | 755100 / 1089072 bytes (69.33 %) | 2925 / 3581 | 2243 | Region 0x08820000, fifth batch: 0x0882B94C-0x0882FB38 (18 of 20 functions) |
| 2026-11-27 | `3486bf5` | 756240 / 1089072 bytes (69.44 %) | 2928 / 3581 | 2246 | Region 0x08820000, last three: 0x0882FB38-0x08830078 (3 of 3 functions) |
| 2026-11-27 | `287d405` | 762496 / 1089072 bytes (70.01 %) | 2947 / 3581 | 2265 | Region 0x08811C84, first batch: 0x08811C84-0x08814D84 (19 of 20 functions) |
| 2026-11-27 | `eba6ebe` | 771760 / 1089072 bytes (70.86 %) | 2967 / 3581 | 2285 | Region 0x08811C84, second batch: 0x08814D84-0x08818950 (20 of 20 functions) |
| 2026-11-27 | `36db31a` | 781340 / 1089072 bytes (71.74 %) | 2986 / 3581 | 2304 | Region 0x08811C84, third batch: 0x08818F74-0x0881C398 (19 of 20 functions) |
| 2026-11-27 | `558c19f` | 791444 / 1089072 bytes (72.67 %) | 2998 / 3581 | 2316 | Region 0x08811C84, last batch: 0x0881C398-0x08820B74 (12 of 13 functions) |
| 2026-11-27 | `8761a3f` | 795360 / 1089072 bytes (73.03 %) | 3005 / 3581 | 2323 | Retry of the NonMatching units above 98 % (7 of 15 functions) |
| 2026-11-27 | `60fd437` | 833744 / 1089072 bytes (76.56 %) | 3022 / 3581 | 2340 | Leftovers of 0x08855428-0x088CBBAC (17 of 17 functions) |
| 2026-11-27 | `eccd77f` | 851464 / 1089072 bytes (78.18 %) | 3034 / 3581 | 2352 | Retry of the leftovers (12 of 19 functions) |
| 2026-11-27 | `2f3ddce` | 855716 / 1089072 bytes (78.57 %) | 3049 / 3581 | 2367 | C++ runtime 0x0890BE54-0x0890CD14 (15 of 20 functions) |
| 2026-11-27 | `29c52ff` | 856228 / 1089072 bytes (78.62 %) | 3051 / 3581 | 2369 | C++ exception runtime names, 2 functions |
| 2026-11-27 | `607011e` | 856772 / 1089072 bytes (78.67 %) | 3052 / 3581 | 2370 | func_0890BFE0, rewritten from the assembly |
| 2026-11-27 | `986b579` | 858544 / 1089072 bytes (78.83 %) | 3060 / 3581 | 2378 | C++ runtime 0x0890D4C4-0x0890DE38 (8 of 10 functions) |
| 2026-11-27 | `6cba423` | 858772 / 1089072 bytes (78.85 %) | 3061 / 3581 | 2379 | func_0890BEC0 as C |
| 2026-11-27 | `e6ba807` | 867608 / 1089072 bytes (79.66 %) | 3083 / 3581 | 2401 | VFPU 0x08812DB8-0x0881B9A0 (22 of 22 functions) |
| 2026-11-27 | `aa8051c` | 881256 / 1089072 bytes (80.92 %) | 3102 / 3581 | 2420 | VFPU 0x08825EE8-0x08844A78 (19 of 20 functions) |
| 2026-11-27 | `a1868fe` | 891500 / 1089072 bytes (81.86 %) | 3122 / 3581 | 2440 | VFPU 0x08844FC8-0x088607F8 (20 of 20 functions) |
| 2026-11-27 | `8b9d231` | 898996 / 1089072 bytes (82.55 %) | 3142 / 3581 | 2460 | VFPU 0x08860EC0-0x08865648 (20 of 20 functions) |
| 2026-11-28 | `4bc7351` | 917904 / 1089072 bytes (84.28 %) | 3161 / 3581 | 2479 | VFPU 0x08865E78-0x0888A8C0 (19 of 20 functions; func_08886E50 NonMatching) |
| 2026-11-28 | `53da03b` | 931472 / 1089072 bytes (85.53 %) | 3181 / 3581 | 2499 | VFPU 0x0888AFEC-0x0888FACC (20 of 20 functions) |
| 2026-11-28 | `6d435ff` | 943400 / 1089072 bytes (86.62 %) | 3201 / 3581 | 2519 | VFPU 0x088949EC-0x088CBD20 (20 of 20 functions) |
| 2026-11-28 | `d8d5633` | 950440 / 1089072 bytes (87.27 %) | 3205 / 3581 | 2523 | Retry: func_08838B08, func_08886E50, func_088CAF54, func_088D168C |

From 2026-11-12 (`f84b2f1`) on, one row per day: the last commit recorded that
day in `progress/ULES01213/history.csv`, which has every measured commit. Rows
taken from that file give the matched code as a percentage only (the file
does not keep the byte count); the units are the `c` / `cpp` pieces of the
splat yaml at that commit.
