# Progress log

`BOOT.BIN` of `ULES01213`, from the objdiff report (`ninja report`): 1089072 bytes of
code and 3573 functions in all, the regions not built by Metrowerks included
(`notes/SPLITS.md`). Every unit listed is at 100 %. The badges and the card in
`progress/ULES01213/` are drawn by `python tools/psp/progress_badges.py --record`,
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
