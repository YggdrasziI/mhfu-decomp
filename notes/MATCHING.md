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
- Two floats loaded then both stored (`lwc1 f1`, `lwc1 f0`, `swc1 f1`, `swc1 f0`)
  inside a member-by-member C++ copy: they are a sub-structure of two floats;
  as two float members each is stored right after its load (func_088AB6D0).
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
- A structure copied member by member where small byte arrays are copied two bytes
  per pass (`lb`/`lb`/`sb`/`sb` loop) and the members one by one: a whole-structure
  assignment, or `d->arr = s->arr` on a 4-aligned member, copies a 6-byte array as
  a word and a halfword. Write each member, and each byte array as a cast copy
  `*(B6 *) d = *(B6 *) s` (`B6` = `struct { s8 b[6]; }`). Two `u8` members after a
  `u16` at a 2-aligned offset merge into an unaligned `lwl`/`lwr` copy unless
  written through `u8 *` (func_088B42C0, C, not C++).

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

- Several loops in one function with registers shifted from the second loop on:
  give each loop its own counter variables (func_0887E320: `i` for the first
  loop, `m`/`j` and `m2`/`j2` for the next two), then try declaration orders. A
  small script that shuffles the declaration lines, then swaps them two by two
  while the objdiff score rises, found the order in a few minutes (the stack
  locals stay first so the frame does not move).
- A local array indexed by the loop counter, `d[i] = k`: mwcc turns it into a
  pointer stepped by 4 (one more saved register, frame larger); the original
  recomputes `i * 4 + sp` each pass when the index is `d[(u32) i]`
  (func_0887E320).
- Gap between two stack locals in the original frame: the array between them is
  larger than the words used (`s32 d[6]` with 4 used, func_0887E320); a `struct`
  local takes a slot even when it lives in a register (`Rec rec2`).
- `x * 1728` added last in the other operand order: written `x * 12 * 12 * 12`
  (func_0887E320, base-12 digits).

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
  - the result register cleared in the delay slot of the out-of-range `beqz`
    and no `return 0` block: `ret = 0;` before the `switch`, `ret = f(); break;`
    in the cases, `return ret;` after it. A `u16 ret` gives the `andi 0xFFFF` in
    each `b` delay slot (func_08849120, func_08849214, func_088DED1C);
  - a size set in each case, kept in `$v0` and copied to the argument register
    after the `switch` (`addu $a2, $v0, $zero`), also on the paths that leave
    it unset: an uninitialised local assigned before the copy in each case,
    `size = 0xC; msg.a = *(A *) p; break;` (func_088AB6D0).
  - a `switch` inside a loop entered by `blezl n` (no jump to the test): `i = 0;
    if (n > 0) { p = row; do { switch (*p) {...} i++; p++; } while (i < n); }`;
    the `for` form adds the `b` to the test (func_08828524).
  - a test before the `switch` that leaves by `beq` + `nop` to the shared
    `return 0` (ours: `beql` with the `addu $v0` copied in its delay slot): the
    `switch` is the `else if` of the test before it, `if (k == 7) { f(); } else
    if (a != b) { switch (k) {...} } return 0;`; an early `return 0;` in the
    first `if` and a plain `if (a != b)` give the `beql` (func_088AB35C);
  - two `switch` statements in one function: the table of the second comes
    first in the data (func_08832548);
  - the selector re-masked before the bound test (`andi` + `sltiu`): it is an
    `int` local loaded from the byte, not a `u8` local (func_08832548).
  - a case with a `b end` + `nop` block of its own in the middle of the cases
    (an empty `case N: break;` points the table at the end instead): the case
    assigns the result its initial value again, `case 11: ret = arg2; break;`
    with `u16 ret = arg2;` before the `switch` (func_08835098);
  - a two-value test before the table (`beq x, 1` then `beql x, 0`, the block
    of 0 first): an outer `switch` with `case 0:` and `case 1:`, the inner
    `switch` in `case 1` (func_08834730);
  - the out-of-range jump filled with the shared `return 0` (`b end` with
    `addu $v0` in its delay slot) while the later branches to it keep their
    `nop`: only the first branch to a label is filled this way, so the
    `switch` has no `default: return 0;` of its own (func_0883F0CC); the same
    for a first case written like the others, `if (x >= 0) return 1; break;`
    (func_08857A80);
  - `addiu $a0, $a0, 0x4A0` kept in the delay slot of the bound test (ours
    folds the offset into every load): the sub-object is a typed pointer
    local, `Unk4A0 *p = (Unk4A0 *) (arg0 + 0x4A0);` (func_08857A80);
  - a case, or the body of an `if`, that is only `b end` + `nop` in a `void`
    function (an empty `case N: break;` points the table at the end, an empty
    `if` and a dead assignment are dropped with their test): it is a
    `return;`, `case 1: return;` and `if (a != b) { return; } break;`
    (func_088AB7D8);
  - few cases compiled as a chain of compares where the original has a table:
    the cases that do nothing are written out, `case 0: case 3: ... break;`
    (func_088AB7D8);
  - a loop around the `switch` with the test only at the bottom (`sltiu` /
    `bnez` / `nop`; the `for` form jumps to the test first and gives `bnezl`):
    `i = 0; do { ...; switch (...) {...} i++; } while (i < 0x40);`
    (func_0889F9C4);
  - a small `switch` compiled as a chain of compares tests the cases in the
    reverse of their source order: `beq 4`, `3`, `1`, `2`, `0` is `case 0:`
    ... `case 2: case 1: case 3: case 4: break;` (func_088B3BE4, func_0883F0CC).
- A constant stored and then used as an argument from the same register
  (`addiu $a2, $zero, 1` / `sw $a2`), or the argument's `addiu` before the
  store: the local is assigned before the member (`lang = 1; p->x = 1;`)
  (func_088902A8).
- A member of the records of a table addressed by its own symbol
  (`D_08973839` = `D_08973834` + 5): declare the table at its base and read
  the member; the linked bytes are the same (include/unk_tables.h).
- `addu a2, v1, a3` (scaled index first) for a record of an array at the start
  of a global object: `D_089CC438->unk0[i].m` with the object declared as a
  structure holding the array; `((Rec *) D_089CC438)[i].m` and a `rec` pointer
  local give the base first. For an array inside a `char *` parameter,
  `((s16 *) (arg0 + 0xA))[i]` gives the index first (func_088AB7D8,
  func_088AB514).
- A message filled on the stack, C++: a structure of eight `s8` members is
  copied member by member (`lb` / `sb` pairs); the same structure holding
  `s8 unk0[8]` is copied by a loop (func_088AB514).
- Scheduling of a constant and a load in one case (`size` in `$v0`): the
  order of the two statements decides it, `size = 8;` before the store that
  needs the load (func_088AB514).
- A pointer local computed in `$v1` with the result's `addiu $v0, $zero, -1`
  before its last `addiu` (ours computes it in `$v0` and copies): the result
  is declared and initialised first, `s32 ret = -1; Sub30 *p = (Sub30 *)
  (arg0 + arg1 * 0x8C + 0x30);` (func_0885187C).
- A member at +2 of the 40-byte records addressed by its own symbol
  (`D_08973836`) next to the base symbol: both are declared as tables of the
  same 40-byte type holding a `u16` (unit_088516A4).
- A table pointer loaded before the index is scaled (`lw` then `sll` / `addu`
  / `sll`; ours scales first): two statements, `rec = tbl[kind]; rec += id;`.
  `rec = tbl[kind] + id`, `&tbl[kind][id]` and a pointer local for the table
  all scale first (func_0885CF9C).
- `addu v1, a0, v1` (index first) for a byte in a table of a global object:
  the member is used directly twice (`if (g->t[i] < 0xFF) { g->t[i]++; }`), not
  through a pointer local (func_08869424).

- Saved registers of a loop's pointer and counter (wanted `$s3` / `$s4` after
  the result and the parameters; ours gave the pointer `$s0`): the order of the
  declarations changes nothing; the two are declared with initialisers in a
  block around a `do while`, `{ s32 i = 0; u16 *p = (u16 *) arg1; do { ...;
  i++; p++; } while (i < 3); }` (func_0885CF9C).
- `sum += f();` with a `s8` sum and a callee declared `s32` adds a `seb` of the
  result before the sum: the callee returns `s8` (func_0885CF9C).

- A `switch` whose out-of-range values run a block that no table entry reaches,
  placed first and falling into the cases (7, 6, ... 1 in code order, case 0 at
  the end of the `switch`): `default:` written first, then `case 7:` ... `case
  1:` without `break`, `case 0: break;` (func_0887D884).
- A division by a constant compiled as a multiplication (`lui` / `ori
  0x88888889`, `mult`, `mfhi`) where ours has `div`: the unit is optimized for
  speed (`#pragma optimize_for_size off`); `% 60` stays a `div` (func_0887D884).
- A loop copying a constant to the stack by halfwords (`lh` / `sh`, count 7 down
  to 0, `bgtz`): a local array with an initialiser, `s16 t[7] = {0, 0, 0, 0, 0,
  0x1C, 0};`, declared in a block at the place of the loop. A structure copy
  of the same bytes goes through `lwc1` / `swc1`. The constant is the unit's own
  `.data`: it needs a `.data` entry at its address in the splat yaml
  (func_0887D884, notes/COMPILER.md, "Two data streams").
- An initialised local array of up to 16 bytes (`s32 t[4] = {2, 3, 8, 15};`) is
  copied through `lwc1` / `swc1` pairs from its constant, like a structure
  copy (func_0885E664); larger ones by a loop (func_0887D884).
- `mult v0, v1` with the quotient of a call first (ours: `mult v1, v0`): the
  result goes to an unsigned local first, `n = f(); return n / 10 * t[i];`;
  casts in one expression and a local for the table entry give the other order
  (func_0885E664).
- Stack offsets of an initialised array and a buffer swapped: the array is
  declared first (func_088B01BC).
- A list walked with its first element tested before the loop (`lhu a1` /
  `beqz`) and the element kept in `` for the call: an `int` local,
  `id = *p; if (id != 0) { do { f(x, id); p++; id = *p; } while (id != 0); }`;
  `while (*p)` jumps to the test and a `u16` local is masked again
  (func_08855160).
- The constant of an initialised array whose size is not a multiple of 4 is
  followed by padding in the image: a `pad` entry in the splat yaml after the
  unit's `.data` entry when the next piece does not align itself
  (unit_0887CBAC).
- Speed setting, quotient and remainder: `m / 60` and `m % 60` of a call
  result give the multiplication and a `div` for the remainder
  (func_0887D884); a remainder computed as `m - q * 60` from the quotient
  (`sll 4` / `subu` / `sll 2` / `subu`) is written that way, `h = m / 60;
  f(h, m - h * 60);` (func_0881A8F8).
- A loop counter in `` and the stepped pointer in `` (ours swapped
  when the parameter itself is stepped): a pointer local declared after the
  counter, `s32 i = 0; char *p = arg0;` (func_0883F8B4).
- `arg ? 0xA : 0` compiled `bnezl` with the 0xA in the delay slot and the 0
  after it: written `arg == 0 ? 0 : 0xA` (func_08823CBC).
- The load of a global first argument placed before the stack loads of the
  other arguments (ours: after them): the callee's parameters are `u16`, not
  `s32` (func_0882DCA0 called from func_0883E400).
- Two searches of the same list one after the other, the searched id of the
  first loaded only after the list's first element is tested: both written out
  (`if (ids[0] != 0) { id = g->id; p = ids; do { ... } while (*p != 0); }`);
  an inline helper evaluates its argument before the test (func_08858F1C).
- A byte loop copying 6 bytes two per pass (`lb` / `lb` / `sb` / `sb`,
  count 3) then two `lbu` / `sb`: the 6 bytes are a structure holding only
  `s8 unk0[6]`, assigned through casts (`*(Addr6 *) &D_X = *(Addr6 *) &local;`),
  the two bytes after it are assigned one by one. Assigning the whole 8-byte
  structure copies a word and a halfword (func_088B27C8).
- A sort that reads a record's fields again for the move (`lhu` / `sh`,
  `lh` / `sh`) after comparing them: C++ structure assignments
  (`t = a[i]; a[j + h] = a[j];`); field by field in C the loads are shared
  (func_0885C5DC).
- A wait loop `lbu` / `sltu` / `xori 1` / `beqz` with two `nop` in its
  body: C, the negation kept in an `int`, `wait = !flag; if (wait) { do { asm
  { nop; nop } wait = !flag; } while (wait); }` on a `volatile u8`; a plain
  `while (!flag)` folds the first test into a `bnez` and C++ adds an `andi
  0xFF` (func_088597BC).
- With the speed setting, a `for` / `while (cond)` loop is rotated (test at
  the bottom). An original loop with the test at the top and a `b` back is
  `while (1) { if (!cond) { break; } ...; step; }` (func_0886DB0C).
- `addu v0, s1, zero` at the return where ours sign-extends (`seh`): the
  function returns `s16`, not `s32` (func_0885CE38). `val = val + base / 10`,
  not `val += base / 10`, for the order of the `mfhi` and shift registers.
- Two tests leading to the same store, the store shared: ``if (a() != 0 ||
  b() != 1) { x = 100; } else { x = ...; }`; the `&&` form with the branches
  swapped duplicates the store (func_0886DB0C).
- A local structure 4 bytes higher on the stack than the original: its size or
  alignment is short (func_088B0FF8: 0xC8 bytes with a 4-byte tail, not 0xC4).
- Binary search with `lo` / `hi` in swapped registers: declare `lo` first
  (`s32 lo = 0; s32 hi = n;`); `sltu at` at a loop end where ours uses a value
  register: the test operands are written the other way (`while (off > acc)`)
  (func_0890D7BC).
- Three byte arguments that are either table bytes or one constant, loaded
  straight into the argument registers with no `andi`: `s32` locals set in an
  `if` / `else` (`r = g = b = 0x80`) before a single call. A `u16` loop
  variable passed with an extra `andi 0xFFFF`: the parameter is `u16`
  (func_08842D3C).
- A stack buffer argument (`addiu a2, sp, N`) set after a constant argument
  where ours sets it before: the parameter is a pointer, not `s32` with a cast
  (func_0887941C called from func_08878F08).
- A mask in two registers shifted with `sll` / `srl 31` / `or` and tested
  against two words: a `u64` (`unsigned long long`) mask, `*(u64 *)(p + N) &
  mask`, `mask <<= 1`; initialise it before the counter (`for (mask = 1, i =
  0; ...)`) (func_0887B8D8).
- A value of a second loop held in the register of the first loop's counter,
  the second counter in a new register: the first counter variable is reused
  for the value (`i = a[j] + b[j];`) and the second loop has its own counter
  (func_08879198).
- A format string that is sometimes the result of a call: the callee's parameter
  is a `char *` and the lookup returns `char *`; with an `s32` parameter and
  `(s32) &D_X` the `addiu %lo` is scheduled before the other arguments
  (func_0887D884).
- Variadic callees (they store `$t0`-`$t3` at the top of their frame) are
  declared with `...` (func_08892004, func_088920A8, func_08891474).

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
- A parameter still in its argument register is passed on without a move
  (no `addu $a1, $s4, $zero` before the `jal`): the callee does take it,
  `func_08851F20(g, arg1)` (func_088DBBBC, `tools/psp/prototypes.py` counts
  the arguments the callee reads).
- A pass-through argument count is a reading aid: counts only go up
  (`tools/psp/prototypes.py`).

## Open symptoms

- A global pointer loaded again for the first call of a case although a local
  copy made at the top of the function is still live (ours passes the copy;
  after a call both reload): func_088DBBBC.
- $a0 not reloaded after a call to a function that leaves it alone
  (func_088A6BA0, notes/COMPILER.md).
- Register-only differences (two registers swapped, result kept in `$v0` then copied
  to a saved register: func_088C3948, func_0884FDC4).
- Scheduling: a load placed before / after an index computation (func_088307BC,
  func_0884424C `trunc.w.s`).
- Unfilled `jal` delay slot (func_08813CF8).
