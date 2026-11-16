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
- A `switch` whose cases compare in reverse source order (3, 2, 1, 0): write the
  cases 0..3 in order, with fall-through where a case ends in the next one's code
  (state machines func_088B996C, func_088B9BF8). A branch with the long block
  first in the source: `if ((x & 0xFF) == 0) { A } else { B }` (no `bool`).
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
- A ring or table indexed by a field (`sll` + `addu idx, base`): a real structure
  with an array member, `q->entries[q->head]`, rather than m2c's shifted sum
  (func_088B85F8, include/unk_queue.h).
- A structure assignment is copied member by member (`lhu`/`sh`, `lw`/`sw`,
  `lbu`/`sb`) in C++ only; C copies it by words (func_088B88F8).
- Float constants read from a symbol splat typed `char` (`((float *) &D_X)[1]`)
  load in another order than from a `float D_X[2]` declaration: declare the symbol
  with its real element type (func_088B996C).
- A member-pointer constant copied to a member when `__ptmf_test` accepts it: a
  local `struct { float v[3]; }` copied as a whole (`*(T *)(p + 4) = t`); with three
  float fields the copy interleaves loads and stores (func_088B97BC, func_088B996C).
- A local cleared byte by byte (`beqz p` guard, `sb $zero` loop, `bnez` on an
  unsigned count) is an inline helper `clear(char *q, u32 n)` with a `do while`;
  `void *` for the pointer or a signed count gives other registers or `bgtz`
  (include/unk_msg.h).
- A 0x1C-byte record copied as four then three float registers: two members of 16
  and 12 bytes copied one after the other (a C copy of the whole record is a word
  loop; C++ copies member by member) (func_088A6CC4).
- A `bnel` to the next instruction with the operation in its delay slot
  (`bnel a, K` / `andi a, a, 0xF`): `x = (a == K) ? a : (a & 0xF);`; the `if` forms
  and the ternary of the other sense give a `beql` over the next statement
  (func_088A6628).
- A mask repeated at each call inside a loop (`andi $a2, $s1, 0xFF`) instead of
  once before it: the callee's parameter is `u8` and the caller passes its `int`
  unmasked; an explicit `& 0xFF` or `(u8)` is hoisted out of the loop
  (func_088A6690).
- A `char **this` (destructor shapes) used with a member address `this + 0x1C`:
  m2c scales it by 4; it is `(char *) this + 0x1C` (`byte_offsets`).
- Constructor shapes that store `(this + 0x1C) - 0x1C` to a global (a base at
  +0x1C cast back): not solved; every form tried folds it (func_088B97BC,
  func_088CC568, func_088A6FEC).
- A constant 12-byte object split by splat (`D_089B9228` + 8 vs `D_089B9230`) must be
  one symbol before a structure copy can match (func_0890682C).

## Registers and loops

- Two locals in swapped registers: the declaration order of the locals sets them
  (func_088B871C: the entry pointer declared before the counter).
- `for` loops compile with a jump to the test at the bottom; a loop the original
  enters without that `b` is a `do { } while` (with `break` for the early exits,
  func_088B87B0), or `if (c) do { } while (c)` (func_088B88F8).

- A loop whose first test branches (`beqz`) with the counter's initial value in
  the delay slot: the initialisation comes before the test,
  `bit = 1; if (flags != 0) { do { } while (flags != 0); }` (func_0889ECB8).

- A counter and a pointer stepped together in swapped registers:
  `for (i = 0, p = table; i < n; i++, p++)` with `i` declared before `p`
  (func_0889F6A0).

- A constant loop unrolled by 8 (eight stores per pass, counter += 8), or a double
  constant loaded as two `lui`/`ori` pairs instead of from the data: the function
  is optimized for speed; put `#pragma optimize_for_size off` at the top of the
  unit (func_0889EB84, func_088A7E44; notes/COMPILER.md, "Speed and space").

- A compare through `$at` (`slt $at, a, b` + `bnez $at`) where ours uses `$v0`:
  the source says `b <= a` / `a > b`; `a >= b` and `!(a < b)` go through `$v0`
  (func_088A7AF0).
- The last load in `$v0` instead of an argument register although nothing is
  returned after it: the function returns that value
  (`n = p[0]; g->pos += n; return n;`, func_088A7A68).

- `addiu $v0, $zero, 0xFF` + `addiu $s3, $v0, -6` (a constant not folded): two
  statements, `room = 0xFF; room -= 6;` (func_088A7860).
- A global structure reached through one saved register from its first store on:
  a `u8 *` to it; a structure pointer sends the stores before the first call
  straight to the symbol (func_088A7860).
- Stack locals in another order than ours: the declaration order sets the
  offsets, try the permutations (func_088A7BDC: `hdr`, `addr`, `port`).
- A search loop leaving by `beqz` to the exit then `b` to the next pass:
  `if (cmp(...) != 0) { break; } goto found;` inside the `switch` case, not
  `if (cmp(...) == 0) goto found; break;` (func_088A7BDC).

- A jump-table bound one above ours (`sltiu $at, $v0, 9` against 8): the source
  has the last case, even empty (`case 8: break;`); the table then has its entry
  (func_088A748C).

- `andi x, 0xFF` repeated at each compare of an argument (not factored): the
  parameter itself is `u8`; `(u8) arg` casts of an `int` parameter are computed
  once (func_088A84B4).

- A `switch` with a jump table: the table moves into the unit with a `.data`
  subsegment at its address in the splat yaml (notes/COMPILER.md, "A unit's own
  data"). An out-of-range value that runs the same code as the last cases
  (`beql` with the statement in the delay slot) is `case 5: default:` on one
  block, not two blocks with the same statement (func_088ADDF4).

- Reading a jump-table `switch` back from its table and blocks:
  - the blocks are in source order: the `case` whose block comes first in the
    code is written first, whatever its value (func_0884FA5C: `case 4: case 6:
    case 7: case 8:` before `case 3:` and `case 5:`);
  - a block reached both from the table and from the out-of-range `beql` (the
    statement copied in its delay slot) is `case N: default:` together, also for
    a `return` (func_08838AB4, func_08813E90, func_08894988 with `case 0:
    default: return 9;`);
  - an out-of-range `beqz` to a `return 0` shared with the code after the
    `switch` has no `default`: the cases `break` or the `switch` sits inside the
    `if` (func_08813E20, func_0884FA5C);
  - 26 cases that all return 1 are still a table: every `case` is written out.
  - table entries that point at the end of the `switch` are cases with an empty
    `break` (`case 0: case 1: case 4: case 5: break;`, func_088AE1EC,
    func_088D5B54); they can be written after the others;
  - a `return 0` block that no table entry reaches, placed last, is a `default:
    return 0;` at the end of the `switch` (func_08850868).
  - after a call in a case, `b end` with the `lw ra` of the epilogue in its delay
    slot is `return f();`; `b end; nop` to the `lw ra` itself is `ret = f();
    break;` with `return ret;` after the `switch` and `default: return 0;`
    inside it (func_0885DD38). With `return f();` in every case only the first
    case gets the `lw ra` copy, the others keep `b; nop` (func_0885C968);
  - cases that only leave (`b end; nop` block of their own, last) together with
    the out-of-range values: `case 0: ... case 25: default: return;`
    (func_08869424);
  - a store followed by the store of the next case is kept when it falls
    through: `x = 5;` then `case 0: x = 0;` (func_088A2244).
- `addu v1, a0, v1` (index first) for a byte in a table of a global object:
  the member is used directly twice (`if (g->t[i] < 0xFF) { g->t[i]++; }`), not
  through a pointer local (func_08869424).

## Calls and allocation

- PSP EABI: arguments 5-8 in `$t0-$t3`, float arguments in `$f12-$f19` counted apart
  from the integer ones (the float parameter may come before the 4th integer one,
  func_088C6234).
- The copy of a float argument to `$f20` placed before the copies of the integer
  arguments: the float parameter is declared first; passing it explicitly to a
  callee that has it still in `$f12` costs no instruction (func_088B826C,
  func_088B8320).
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

- $a0 not reloaded after a call to a function that leaves it alone
  (func_088A6BA0, notes/COMPILER.md).
- Register-only differences (two registers swapped, result kept in `$v0` then copied
  to a saved register: func_088C3948, func_0884FDC4).
- Scheduling: a load placed before / after an index computation (func_088307BC,
  func_0884424C `trunc.w.s`).
- Extra `nop`s in a wait loop (func_088597BC), unfilled `jal` delay slot
  (func_08813CF8).
