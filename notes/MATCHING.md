# Matching techniques (mwccpsp, game code)

Lessons that made functions of `BOOT.BIN` match, each checked by a build. Read this
when a function is stuck below 100 %: look the symptom up, try the form. Most of them
are also tried automatically by `tools/psp/batch_units.py` (variant name in brackets).
Compiler facts (version, flags, C vs C++) are in `notes/COMPILER.md`.

## Block order and branches

mwccpsp lays basic blocks out in source order; m2c often writes them the other way.

- `if (C) { ...; return X; } return Y;` where the original tests the other way:
  write `if (!C) return Y; ...; return X;` (`invert_ifs`). Negate by the operator
  (`a >= b`, not `!(a < b)`: they compile differently). Nested ifs show once the
  outer one is inverted (func_08816060, func_08813158).
- Void functions: `if (C) { A; return; } B;` -> `if (!C) { B; return; } A;`
  (func_0889A09C).
- `if (C) {A} else {B}` with the branch-likely sense reversed (`bnel` vs `beql`, the
  `else` value in the delay slot): swap the blocks, `if (!C) {B} else {A}`
  (func_0881CA34, func_08841520) (`swap_else`).
- `return E != 0;` where the original has `sltu` after a shared tail: it was
  `if (!(E)) return 0; return 1;` (func_08854D88, C++ and C) (`bool_returns`).
- m2c's `goto block_N` of a merged tail: write the tail out in each branch, `else if`
  chained (`inline_gotos`).
- Loop heads `beqz` vs `beqzl`: not solved (func_088C33E8).

## Booleans (C++ only)

- `andi` + `sltu` + branch on 0/1: `(bool) (x & K) == 0` / `!= 0`; C folds the
  `sltu` away (`bool_tests`). A plain `if (A & K)` in C++ needs the explicit
  `(bool) (A & K) != 0`.

## Types and signedness

- `seb`/`seh` or `lb`/`lbu` differences: m2c types counters and parameters `s8`/`s16`
  that the original kept in an `int`, truncated at the store or call
  (`widen_narrow`); flip the signedness of each typed load (`sign_loads`).
- An argument register masked at every use (`arg & 0xFF`): the parameter is `u8` /
  `u16` (func_0881C240, func_088493A4) (`narrow_params`).
- A callee whose result the caller masks with `andi 0xFF` may return `u8`; but keep
  the prototype the callee's own unit defines (one count and type per function,
  `tools/psp/prototypes.py`).
- `if (x >= 2.1474836e9f)` around a conversion is mwccpsp's own `(u32) x`
  (`unsigned_casts`).

## Addresses, arrays and structures

- A large offset (`lui` + `addu` then a small one) is `(char *) p + off`, not an
  integer sum (`pointer_offsets`).
- Array access gives `addu index, base`; the pointer sum `p + i * k` gives
  `addu base, index`. With an `s32` base the offset must go on a `char *`.
  Operand order of `+` / `&` in the source does not matter.
- Structure arrays: `*(T *) &((E<K> *) (p + off))[i]` with the index in a local
  (func_08830728) (`stride_arrays`).
- A symbol read word by word with one `lui` each: type it as a structure of floats
  (`F<n>`) (`float_structs`). Stack structure copies through `lwc1`/`swc1`: up to 16
  bytes one copy, larger in a loop, so one copy per member (`stack_copies`).
- A 4-byte structure passed in a register (stored to its home slot, bytes read back
  with `lbu`): a `struct { u8 b0, b1, b2, b3; }` parameter (`byte_structs`).
- A global pointer m2c types `s32 *` but steps in bytes: make it `char *`
  (`pointer_steps`, `byte_pointers`).
- A stack local passed by address: an array up to the next such local / the frame
  top, so the frame size matches (`stack_arrays`); a `ScePspDateTime` filled by
  `sceRtcGetCurrentClockLocalTime` is the pspsdk structure.
- A constant 12-byte object split by splat (`D_089B9228` + 8 vs `D_089B9230`) must be
  one symbol before a structure copy can match (func_0890682C).

## Calls and allocation

- PSP EABI: arguments 5-8 in `$t0-$t3`, float arguments in `$f12-$f19` counted apart
  from the integer ones (the float parameter may come before the 4th integer one,
  func_088C6234).
- Allocation + inlined constructor: `p = func_08859B44(heap, size, 16); if (p) {...}
  else p = 0;` with the result in a temporary (keeps the dead `p = 0` after a `b`),
  the heap sum passed uncast to a `void *` parameter, `*(s32 *) argN` for a `char *`
  read with `lw` (`alloc_temps`, `word_derefs`, `pointer_args`).
- Virtual calls (`jalr $t9`): C++ with a class of virtual functions,
  `((Vxx *) X)->vfunc_xx(X, ...)` (`virtual_calls`). Pointer-to-member calls go
  through `__ptmf_test` / `__ptmf_scall` (notes/COMPILER.md).
- A pass-through argument count is a reading aid: counts only go up
  (`tools/psp/prototypes.py`).

## Open symptoms

- Register-only differences (two registers swapped, result kept in `$v0` then copied
  to a saved register: func_088C3948, func_0884FDC4).
- Scheduling: a load placed before / after an index computation (func_088307BC,
  func_0884424C `trunc.w.s`).
- Extra `nop`s in a wait loop (func_088597BC), unfilled `jal` delay slot
  (func_08813CF8).
