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

From 2026-11-12 (`f84b2f1`) on, one row per day: the last commit recorded that
day in `progress/ULES01213/history.csv`, which has every measured commit. Rows
taken from that file give the matched code as a percentage only (the file
does not keep the byte count); the units are the `c` / `cpp` pieces of the
splat yaml at that commit.
