# Matching techniques (mwccpsp, game code)

Lessons that made functions of `BOOT.BIN` match, each checked by a build. Read this
when a function is stuck below 100 %: look the symptom up, try the form. Most of them
are also tried automatically by `tools/psp/batch_units.py` (variant name in brackets).
Compiler facts (version, flags, C vs C++) are in `notes/COMPILER.md`.
- A switch without a jump table whose fall-out is `b end` with `v0 = 0`
  in its slot, the cases branching to a shared `addu v0, zero, zero`: no
  `default:` (or `default: break;`), `break` from the cases, one `return 0`
  after the switch. `default: return 0;` turns a `bgtz` or `bgez` into a
  likely branch with its own return block (func_0887B7E0, func_0887C724,
  func_0887CD04, func_0887DDD0).
- `beql v0, zero` to the epilogue with `v0 = 0` in its slot: `if (f() != 0)
  { ...; return g(); } return 0;` rather than an early `return 0`
  (func_0887FFE8).
- `beqzl at` with `flag = 0` in its slot before a flagged block: an
  explicit `else { flag = 0; }` (func_088795F4).
- A `u8` function returning constants with `andi v0, 0xFF` before `jr ra`:
  every result in an `s32` local and one `return ret;` at a shared label;
  `if (x >= y) ret = 1; else ret = 0;` for `slt; bnezl` rather than
  `xori`; two failing tests merged in one `||` with one `ret = 2; goto end;`
  (func_0887959C).

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
- `bltzl r` to a block placed after the code for `r == 1` and `r == 0` (each
  a `beql` with its value in the delay slot): `if (r >= 0) { switch (r) { case
  0: ...; case 1: ...; } } else { ... }` (func_088198E4).
- `return E != 0;` where the original has `sltu` after a shared tail: it was
  `if (!(E)) return 0; return 1;` (func_08854D88, C++ and C) (`bool_returns`).
- m2c's `goto block_N` of a merged tail: write the tail out in each branch, `else if`
  chained (`inline_gotos`).
- Loop heads `beqz` vs `beqzl`: not solved (func_088C33E8; func_0884F190
  97.33 %, the guard of a do-while drive wait).
- A state tested against several values that all return 0, compared as
  `beql 6` / `beq 5` / `beqz` (one `b` to the rest): `switch (st) { case 0:
  case 5: return 0; case 6: return 0; }` (func_088A8988, 74 % → 95 %; the
  separate `v0 = 0; b end` block of the original is still open).
- A loop entered by `blez n` and tested at the bottom, with the counter update
  in the delay slot of the call before it: `if (n > 0) do { ... n -= 6;
  call(...); ... } while (n > 0);` with the update written before the call
  (func_088A8C78).
- A `return C;` that branches straight to the epilogue (`b end` with the value
  in its delay slot) where ours branches to the join after the next `return
  f(x);` call, and instructions left dead after a `b` (the block a branch-likely
  delay slot was copied from, e.g. `addu $a0, $v0` before the `jal`, or `lw $v0`
  before `lw $ra`): `#pragma opt_rebuildconditionals off` at the top of the
  unit. No source form gave it (else chains, inverted tests, one result
  variable, conditional expressions, a `switch`). With it, `if (r < 0) return
  r; return 0;` becomes `return r < 0 ? r : 0;` (func_088AA520, func_088AA83C,
  func_088AAC80; notes/COMPILER.md). Found by compiling the unit once per
  `opt_*` pragma of `mwccpsp.exe` (`strings`), `off` and `on`.
- A 0/1 result kept as branches (`li v1, K; bne`, `li v0, 1` / `move v0,
  zero`, `seh v0` at the join) where ours gives `xori`/`sltiu`: the same
  pragma with `if (x == K) r = 1; else r = 0; return r;`, `r` an s32
  (func_08894F7C). With an s16 result shared through a `break`, the value
  goes through an s32 local first, `t = 1 / 0; ret = t;`, which puts the
  `seh` at the join (func_08892708). No source form keeps the branches
  without the pragma.
- The same dead instruction after a `b` (`addiu a0, zero, 2` left before the
  block its branch-likely slot was copied from) without the pragma: early
  returns instead of an `else if` chain, `if (A == 0 || B == 0) { ...;
  return; } if (C != 0) return; ...` (func_088B6B14).
- A test against two values (`== 2 || == 1`) compiled as a range check
  (`addiu -1` + `sltiu 2`) where the original compares each (`beq 2`, `beq 1`):
  `switch (x) { case 1: case 2: ...; break; }` (func_088A9EF4).
- A `switch` table whose out-of-range `beql` has `sh $zero` (the store of case
  0) in its delay slot and no `default` block: `case 0: default: x = 0;
  break;` written first (func_088AA9B4).
- A list walk `beqzl p` before the loop (no jump to the test) and `bnezl p` at
  the bottom: `p = head; if (p != 0) { do { ... p = p->next; } while (p !=
  0); } return -1;` (func_088AA9B4).
- A loop whose exit test comes first and whose found case falls through after a
  `bnel` back to the top (no jump to a bottom test): `for (;;) { if (end) { ...;
  return; } ...; if (found) { ...; return; } step; }`; a `while` rotates the test
  to the bottom and a `break` moves the found block after the loop
  (func_088AD46C).
- A slot search whose test reads through a pointer that steps by the record
  size while the stores after it recompute `base + i * size`: test `q->sock`
  with `q++` and `i++` in a `do`/`while`, store through `tbl[i]`; the pointer
  copied in the delay slot of the test is `c = q;` before the `if`
  (func_088AA370, func_088AA9B4).
- A single `== 1` test compiled as `beql` to the block placed after a `b end`
  (ours: `bne` over it): `switch (x) { case 1: ...; break; }`
  (func_088ACC60, func_088ACCE8).
- A byte stored then read back from memory after a store to a neighbour,
  where ours reuses the stored register: the two are fields of one object
  (`State.mode`, `State.unkC`), not separate `extern`s splat named
  (func_088ACC60).
- `addu v1, v1, base` (index first) for `g[cur].field` but `addu v1, base,
  v1` in the loop: index a typed array of records, not `g + i * size`
  (func_088AC04C).
- Two loops over the same table with the counter and the pointer in
  different saved registers: give the second loop its own counter and
  pointer, then search the declaration order (func_088AC0E8).
- A float constant stored as `lui` / `ori` (not read from the data) and a
  copy loop that steps two pointers: speed mode (func_088AB068).
- The same call emitted twice, behind `bnez s0` and then behind a redundant
  `beqz s0`: `if (ok == 0) err = f(); else if (ok != 0) err = f();`
  (func_088B1DB0).
- `bnezl` to the store of 1, the store of 0 first: `if (x == 0) g = 0; else
  g = 1;` (`x != 0` first gives `beqzl`; func_088B1BF8).
- A loop where one failure path skips the pointer step (`beqzl` past the
  `addiu s0, 0xC8` to the counter step): a `for` loop with the pointer
  stepped at the end of the body and `continue` on that path
  (func_088B2C20).
- A record array reached at a large offset of another symbol (`lui
  D_09A2851C`, loads at `0x116C(s1)` / `0x1231(s1)`): step a `char *` from
  the base symbol and cast `p + 0x116C` (func_088B2D74).

- States that return early (`beql K1` / `beq K2` + nop / `beqz` to a
  separate `v0 = 0; b end` block): one switch label group,
  `switch (st) { case 0: case 5: case 6: return 0; }`, lowest value first,
  not `&&` / `||` tests (func_088A8988, func_088A88E0).
- Error codes tested in reverse order (`beql FF`, `beq 202`, `beq 201` to
  a shared block): one case group written 0x80110201, 0x80110202,
  0x801102FF (func_088EFB18).
- Last test `beq a, b, end; nop; b end; addiu v0, K`: `return (a != b) ? K
  : a;` or an `if/else` on a result local (func_088AAD58).
- A list walk ending `lw s0, 0(s0); beqzl s0, <epilogue>; b <top>`: keep
  the next pointer in its own local, `n = s->next; if (n == 0) break; s =
  n;`, then `return 0;` after the loop (func_088B0724).
- A pointer search entered with no guard (`lhu; bnel id, v0, top` with the
  step in the delay slot) and the found element used after it: make the
  use inside the loop and leave with `break`, `for (;;) { if (id == p->id)
  { use(p); break; } p++; }` (func_088714F8).
- `beqzl` over the body where the original has `bnez` + `b`: `if (x != 0)
  { rest } return 0;` instead of an early `return 0` (func_088CDA74).

- `bnel` with `return 0` in its delay slot where ours gives `beql` + `b`:
  the positive test with the work inside, `if (x == K) { ...; return V; }
  return 0;` (func_088A5AFC). `bgezl v0` + `addu v0, zero, zero`: the early
  return `if (ret < 0) return ret; return 0;` (func_088A4BC4).
- `beql reg, zero` with `v0 = 0` in its slot, then `lw v0, 4(reg)`:
  `if (p != 0) return p->unk4; return 0;` (func_088A5B50). `beql x, -1` to
  a constant call: `if (x != -1) f(a, b); else f(0, 0);` (func_088A4504).
- A clamp with an inner join (`beqz at; b join; addu s0, a2`) that if/else
  tail-merges: a ternary, `x = (x < N) ? x : lim; len = x;` (func_088A4654).
  `bgezl t / slti at, t, 0x100 / bnezl at`: `if (t < 0) x = 0; else if (t >
  0xFF) x = 0xFF; else x = t;` (func_088A6100).
- Loop exit `beql` with `lw v0, ret` in its slot, then `beq` and `b loop`:
  `if (next == 0xFFFF) break; if (next == arg1) break; arg1 = next;` and one
  `return ret;` after the loop (func_088A6100).
- An error path inside a guarded do-while placed after the normal path:
  `if (ok) { ...; } else { error calls; break; } tail;` (func_088A5D38).

- `sltu v0, zero, v0; xori v0, 1; beqzl v0` after a call where ours gives
  one `bnezl`: `!(f() != 0) ? 2 : 1` (func_08890E48, func_08890ED4); the same
  pair before a `bnez` at the top of an infinite loop: `if ((x & K) == 0)
  goto sleep; ... sleep: call();` gives the plain `beqz` (func_08890494).
- A switch whose first-compared case should be `beql` to the join + 4: write
  the case equal to the default value on its own and put `default:` last
  (func_08890718).
- An early exit inside a loop as `beqzl p` with the result in its slot,
  apart from the break: `if (p == 0) goto ret; ... } ret: return total;`
  (func_08891074).

- A double guard before a speed-mode loop (`blezl` to the epilogue, then
  `blez` to the exit): an early `if (n <= 0) return;` before the same `for`
  (func_08892A88).
- `beql n, zero, end` with the final store in its slot: `if (n == 0)
  break;` and one store after the loop (func_08891BC8).
- Two tests sharing one body (duplicated `addiu` in a `bnel` slot): one `||`
  condition; `$at`/`aN` swapped between two `slti` of a byte range: both
  bounds inclusive, `c >= 0x81 && c <= 0x9F` (func_08891F88, func_08891D4C).

- A `sltu` against zero kept before a test of a masked flag (`andi 0x100;
  sltu v0, zero, v0; bnez`): `(bool) (x & 0x100) == 0` in a C++ unit
  (func_08895FFC, func_088966C0); an unroll guard copied with `andi 0xFF` in
  a speed unit: C++ too (func_08893C6C).
- A ternary on `x != 0` giving `beqzl` with swapped constants where the
  original has `bnezl` with the true value in its slot: `x == 0 ? B : A`
  (func_08894EE4); same for if/else: the `x == 0` case first (func_088952A4).
- `ext v0, v0, 1, 8` on a u8 parameter: `(u32) arg >> 1` (func_088952A4);
  `srl 1` then a signed `slt`: `(s32) ((u32) b >> 1)` (func_08893444).
- A state tested `beq st, 1, join`, then `beql st, zero, body` and `b` to
  the epilogue, the state-0 body falling into the common code: `switch (st)
  { default: return; case 0: ...; /* fall through */ case 1: break; }`
  with `default` written first; nested `if`s give `bnezl` (func_0889E508,
  func_0889E6A4).
- An error on a nonzero argument placed at the end (`beqz a0, main; b tail;
  lui v0, 0x8000`, the `ori` at `tail`): `switch (x) { case 0: ...main...;
  break; default: ret = ERR; break; }`, `case 0` first; no `if` / `goto` /
  `do { } while (0)` form gives it (func_0889F0D8, func_0889F1CC).
- An empty case tested first and branching to the epilogue: an explicit
  `case X: break;` written last (reverse compare order, func_0889E8F8).
- A case ending in `b` with the shared result store (`sw s2, 0(s0)`) in its
  delay slot: a plain `break` to the shared `*out = ret;`; an early store
  and `return`, or a `goto`, stores `zero` (func_0889F8F4, func_0889F764).
- `b default` with a `nop` in its slot where ours fills it with the first
  instruction of the default block: move the body of the case group into a
  `static inline` helper (`ret = locked(msg);`); a plain `static` is not
  inlined (func_0889F764).
- One `beqz reg; nop` among final checks where ours gives `beqzl ...; addu
  v0, zero, zero`: a single `if (a && p != 0 && b && f() == 0) return 1;
  return 0;` (func_0889DFAC).
- An if/else whose stores are duplicated into both branches: a ternary,
  `p->prev = i == 0 ? A : &arr[i - 1];` or `x = x > 16 ? x - 16 : 0;`, gives
  one store after the join (func_0889F288, func_0889FB94).
- `bnezl v0, end` with `addu v0, zero, zero` in the slot where ours gives
  `beqzl` plus `b`: no early `if (x != 0) return 0;`, write `if (x == 0) {
  ...; return 1; } return 0;` (func_08880A70, func_08881458; same for a
  call result, func_088800C0). Long path first in if/else too
  (func_088812B4).
- `beql x, v0` with the equal case's assignment in the slot and a flag set
  on the fall-through: `if (a != b) flag = 1; else x = 0xFFFF;`; the `==`
  form gives `bnel` (func_088808DC).
- A wait loop `sltu; xori 1; bnezl v0, exit` with the call at the top and
  `b` back at the bottom: `for (;;) { if (!f()) break; delay(); }`; `while
  (f() != 0)` tests at the bottom (func_088805A0).
- A single `beqz` to the epilogue in place of `bnez; nop; b`: `if (!found
  || x != 0) return call(); return r;` (func_088816AC).
- Two `beql` to the epilogue with `li v0, 1` and `move v0, zero` in their
  slots: one `if (a == 1 || b != 0) return 1; return 0;`; two early returns
  give `bnel` + `b` (func_08881970). `beql r, 1` then `beqzl w` with
  `v0 = 0` in the slot: `if (r != 1) { switch (w) { case 0: return 0; } }
  return 1;` (func_088819D0).
- Ascending `bnez` / `bnel` compares (0, 1, 2, 3, 4) with `b` to a join:
  an if/else-if chain; a `switch` compares in reverse order (func_0888291C).
  `beq state, 1` first, then `beql state, 0`, case 0 code first: a `switch`
  with `case 0` written first (func_088825FC, func_08882750).
- A `beql x, 0xFFFF` to the else call at the end of a loop body: write the
  `!= 0xFFFF` block first (func_08882750).
- A loop test at the top with the counter check at the bottom and no guard,
  where a `for` puts the test at the bottom behind a `b`: `do { if (!x)
  break; ...; i++; } while (i < N);` (func_08882FA4).
- A two-way `if` with the inverted branch-likely (`blezl` for `bgtzl`) and
  the blocks swapped: invert the test and swap the blocks, `if (ret <= 0)`
  (func_0888A1FC); `beql` for `bnel` on two constant stores: test `!=`
  first (func_0888A668).
- A test before a loop and a `bnel` back at the bottom: `if (c) do { ... }
  while (c); else ...`; `while` gives `beqzl` + `b` (func_0888A388).
- `beq x, 2` then `beql x, 1` and a separate `b` to the epilogue: a
  two-case `switch` written `case 1:` before `case 2:`; an if/else chain
  gives `bne` and the blocks in the wrong order (func_0888AF68).
- `beql x, 1, end` with a store in its slot, `beqz x, L`, then the default
  call and `b end`: `switch (v) { default: f(); break; case 0: case 1:
  store; break; }`, the group after `default` (func_0888E350).
- `beqzl v0, ret` with `addiu v0, 1` in the slot where the original
  branches to a shared `return 1`: drop the explicit `else { return 1; }`
  and fall through to the final return (func_0888B994).
- An extra `b` with `addu v0, zero, zero` in its slot before the return:
  `if (x < lim) { ... } else { return 0; }`, not `if (!(x < lim)) return
  0;` (func_0888E634).
- Two early tests with one return value, the first `beql` with the value
  in its slot, the second `bnel` + `b`: one `if (a == 1 || b == 1) return
  1;` (func_0888D888, func_0888E494). `beql v, 1` with 0 in the slot then
  `bnel v, 5` with 0xFF: `if (v == 1 || v == 5) return 0; return 0xFF;`
  (func_0888D888).
- `bltzl` with the else store in its slot: `if (r >= 0) { ... } else {
  ... }` (func_0888FBD4). A shared `return 0` after a switch: `break` from
  the cases, no `default`; returns inside the cases duplicate the epilogue
  (func_0888D734).
- A guard leaving with `bnezl` / `v0 = 0`, then `beql K1` with `v0 = 1`,
  `beq` + `nop` for the next ids and a last `bne` to a `v0 = 0` block: an
  inline helper `if (guard) { if (id == K1 || ... || id == Kn) return 1; }
  return 0;`; a switch group gives 96 % (func_088711C0).
- `beqzl v0, end` with `v0 = 0` in the slot after a call returning a
  list, then a `beq -1` to a separate `return 0`: a positive guard, `if (p
  != 0) { while (*p != -1) ... } return 0;`, with the speed setting
  (func_0887184C).
- `bnezl v1, end` with a store in the slot and the same store on the fall
  through: write the store in both arms, `if (v == 0) { *p = 0; ... } else
  { *p = 0; }` (func_08872B7C).
- A loop tested at the top with a `b` back to it: `for (;;) { if (x < 0)
  break; ... }`; `while (x >= 0)` tests at the bottom (func_08871BC4).
- A guard with `beql x, K` and `v0 = 1` in its slot, a call, `beqzl v0` with
  `v0 = 0`, then `v0 = 1; b end` with an empty slot: `if (x != K) { switch
  (f()) { case 0: return 0; } } return 1;` (func_08874124).
- Two early exits merged into one `bltzl s0, end` with `v0 = 0`: `if (idx <
  0 || f(idx)) return 0;` (func_08874278). Range blocks kept as branches
  rather than folded into `sltu`: one `if / else if` chain whose arms only
  `if (f()) return 1;`, then a single `return 0;` (func_08874278).
- A jump-table guard branching to the epilogue with `v0 = 0` in its slot:
  no `default:`, `break` from the cases, one `return 0` after the switch
  (func_08876710).
- Loops tested at the top and never rotated: `while (1) { if (!c) break;
  ... }` or `for (;; p++) { ... continue; }` with the step in the header
  (func_0887370C, func_08873614).
- An unfolded compare chain ending in `bnel last, join` with `v0 = 0`,
  the first compare `beql` with `v0 = 1`: a `static inline bool` helper
  `if (id == A || id == B || ...) return true; return false;`. A returned
  `a || b` folds near values into range tests, a switch ends in `beq; nop;
  b` (func_088795F4).

## Booleans (C++ only)

- `andi` + `sltu` + branch on 0/1: `(bool) (x & K) == 0` / `!= 0`; C folds the
  `sltu` away (`bool_tests`). A plain `if (A & K)` in C++ needs the explicit
  `(bool) (A & K) != 0`. The same `sltu` in C: `if ((u8) ((x & 1) != 0) ==
  0)`, or an inline flag helper returning `u8` (`return (x & 1) != 0;`);
  plain `== 0`, an `s32` local or `(u8) (x & 1)` drop it (func_0889D0E0,
  func_0889D6EC).
- A list walk tested on entry (`beqz head`) and then on the saved next
  pointer (`bnez next` with `o = next` in the delay slot): `if (o != 0) do {
  ...; next = o->next; ...; o = next; } while (next != 0);`; `while (o)` and
  `for` give `b` to a bottom test of `o` (func_088C33E8, func_088C349C).
- `sltu` kept before `beqz`: `(bool) (x & m) != 0`; `(bool) (x & m)`
  alone drops it, `== 1` compares against a register holding 1
  (func_0888D600). In C: a `u8` local, `u8 flag = (x & 8) != 0;`
  (func_0888E494). A test `(u8) check(p) == 1` on a `static inline bool`
  helper with an early `return false` and a switch (func_0888FBD4).
- `xor` / `sltiu 1` / `bnel` against a register holding 1 on an equality
  test: a C++ `static inline bool` returning `a == b`, tested `== 1`; C folds
  it to `bnel a, b` (func_08872AAC).
- `sltu` then `bnel` against 1: cast the comparison before testing it, `if
  ((s32) ((x & 1) != 0) == 1)` (func_088765C0). `sltu; xori 1; bnel` after
  a call: `if (!(f() != 0) == 0)` (func_08874218). A `(bool)` test kept out
  of a `||` chain in its own nested `if` (func_08873488).
- `andi v0, 0xFF` after a call tested against zero: `f(...) == 0`, not
  `!f(...)` (func_0887BB48); or the callee declared `s32` and the call cast
  to `(u8)` (func_0887CA4C, func_0887CAFC).
- `lw a0` before the `jal` and `lbu a1` in its slot swapped: declare the
  callee's second parameter `s16`, `u16` or `s32` rather than `u8`
  (func_0887CA4C, func_0887CAFC).
- `negu; seh` on an s16 where `v = -v` gives a `seh` first: `v *= -1;`. A
  clamp to 0..0xFF: `else if (t > 0xFF)`, not `t >= 0x100`. `addiu 0xFD` on
  a byte: `+= 0xFD` (func_0887F934).

## Types and signedness

- `seb`/`seh` or `lb`/`lbu` differences: m2c types counters and parameters `s8`/`s16`
  that the original kept in an `int`, truncated at the store or call
  (`widen_narrow`); flip the signedness of each typed load (`sign_loads`).
- An argument register masked at every use (`arg & 0xFF`): the parameter is `u8` /
  `u16` (func_0881C240, func_088493A4) (`narrow_params`).
- A callee whose result the caller masks with `andi 0xFF` may return `u8`; but keep
  the prototype the callee's own unit defines (one count and type per function,
  `tools/psp/prototypes.py`).
- A function that masks its argument at each use (`andi v1, s2, 0xFFFF` for
  the test and the index, the raw register stored with `sh`) and whose callers
  pass it unmasked: an `s32` parameter cast at each use, `(u16) arg0 < 0x15`,
  `tbl[(u16) arg0]`; a `u16` parameter makes the callers mask it, and a `u16`
  local keeps only the masked copy (func_088B6A80, called by func_088B6B14).
- `if (x >= 2.1474836e9f)` around a conversion is mwccpsp's own `(u32) x`
  (`unsigned_casts`).
- `mul.s` with a constant as first operand, loaded after the int-to-float
  conversion: `x = n; x = K * (float) x;`. The redundant cast stops the swap that
  `K * x` gets; `K * (float) n` loads the constant before the conversion
  (func_088429EC, func_08841100).
- A VFPU result read back (`lwc1`) after the argument loads of the next call:
  store it in a local first, `s = sin_vfpu(a); f(..., 64.0f * s ...)`
  (func_08841100).
- A small constant passed to an `s8` parameter without `seb` in the original:
  keep the value in an `s8` local, not an `s32` (func_088226F0's colours).
- A `u8` field shifted with `srl` instead of `sra`: cast it, `(u32) *(u8 *) p >> 3`
  (func_08816F24).
- A struct field read with `lhu` for `x + 0x72` and with `lh` when passed as
  an `s16`: the field is `u16` (func_088198E4).
- `subu` with its operands loaded in the other order (`b` into `$v0` before
  `a + 1` into `$v1`): `(s32) (a + 1) - b` (func_08816F24).

- `addu` operands swapped against the original: the first operand read as
  `u32`, the second as `s32` (func_088C0468).
- A loaded word added to a base with the loaded operand first (`addu v0,
  v0, a1`): load it as a pointer and add the base as an integer, `*(char
  **) (e + (s32) blk) + (s32) blk` (func_088C03CC).
- `memset` size as `unsigned int` in the prototype (func_088AD1EC).
- `(bool) (x & K)` tested `!= 0` rather than `== 1`: the id is read first
  and the large offset stays split `lui 7` / `lw -0x50EC` (func_088D168C,
  NonMatching).

- `sltiu` where ours gives `slti`: make the compared parameter unsigned
  (func_088A4654, `unsigned int` length).
- `andi 0xFFFF` followed by signed `slti` / `slt` where the original has
  `sltiu` / `sltu`: an `unsigned int` local holding a `(u16)` cast, not a
  `u16` local (func_0888FCE4).
- A compare branch with its operands swapped that `==` order does not fix:
  type both values as `char *` instead of `s32` (func_0888E218).
- An extra `andi v0, 0xFFFF` after a call whose callee already ends with
  `andi v0, 0xFFFF` in its delay slot: declare the callee returning `s32`
  (func_08870E88). An extra `andi a1, 0xFFFF` before a call: declare that
  parameter `s32`, not `u16` (func_088711C0).
- `seh v0` in the `jr ra` slot after an `s16` sum: return `s32`, keep the
  local `s16` (func_08872B40). No `seb` on an `s8` result: make the
  function return `s8` and work in the `s8` parameter, `arg1 += arg2`
  (func_08872CC0).
- `andi 0xFF` on a byte already loaded by `lbu`, before its use as an
  index: a `u8` local read in the loop condition, `while ((c = *p) != 0xFF)`
  (func_088701D8). The mask in one branch only: an `s32` local in the
  condition and `(u8) id` in that branch (func_08872444).
- Two read-modify-write sequences on one byte (`and -0x81; or 0x80`, then
  `and -0x80; or`): bitfields `u8 val : 7; u8 flag : 1;`, allocated from the
  low bit, assigned in the order of the assembly (func_08872DF4,
  func_08872E48).
- A sum loop `count * table[id].value` with shifted registers and `slt`
  before `mflo`: read the id into an `s32` local (func_08876FCC,
  func_088790F4), or declare the table field `u32` (func_08874AB0).
- `lb` for `lbu` and `addiu a0, base, off; sb 0(a0)`: make the parameter
  `u8 *`, not casts at each use (func_08873044). A flag local set twice to
  1: `u8` tested with `!flag` (func_08873044).

## Symbol names in the report

- splat names a field address it sees loaded on its own (`D_09BC8402`), and
  objdiff counts `D_09BC8400+0x2` against it. Declare that name as its own
  `extern` and index it (`D_09BC8402[id][0]`): same code, 100 % in the report
  (func_08872108).
- Not always needed: func_088A9914 writes fields of `extern Session
  D_09A1D5D0` and of four `Store` externs whose field addresses splat named
  (`D_09A1D5EC`, `D_09A1D594`...). `asm_compare.py` shows those names as
  differences (99.05 %), but the objdiff report gives 100 %. Read the report
  before splitting the externs.

- The only difference `%lo(D_X+0x4)` against `%lo(D_Y)`: read the word
  through its own `extern D_Y`, not a member of D_X (func_088ADA44).
- `jtbl_X`, `D_X` (local initialiser) against `@N`: the code matches; give
  the table or initialiser to the unit in the splat yaml (func_088A748C,
  func_0887AFB8, func_088AB980, func_088B012C, func_088714F8).
- Byte pairs copied with both loads before both stores (`D_X+0x1` against
  `D_X+1` in the diff, 100 % in the report):
  `typedef struct {u8 a, b;} AB;`, `*(AB *) &dst = *(AB *) &src;`
  (func_088B4FAC, func_088B5568, func_088B5D3C, func_088B70E8,
  func_088B7350).

- Two stores into globals 0x44 apart in an order no permutation changes:
  one struct array, `D_09A0EB80[i].unk44 = x` (splat named the field
  `D_09A0EBC4`; the diff shows `D_09A0EB80+0x44`, the report 100 %,
  func_088A5B50). Four then three `lwc1` ascending into `$f3..$f0` copying
  consecutive globals: one record written as two structure assignments
  (func_088A4504, same report behaviour).

- A u16 element at a large offset compared with a u16 argument, with
  both the index `addu` and the `xor` in the original order: a struct with
  an array field, `arg0->arr[i] == arg1`, element on the left (func_08890284).
  `sll v0, i, 1; addu v1, v0, base`: index a typed pointer,
  `((u16 *)(base + OFF))[i]` (func_088901F8, func_088900C4); a table of
  pointers: `((T **)(base + 0x140))[i]`; `addu a2, idx, base`: the integer
  sum `(u8 *)(idx + (s32)base) + 0x134` (func_088911A0).

- A scalar local and a local struct with their stack slots swapped:
  declare the scalar first (func_08892E7C).

- A `switch` whose other values return 0 through the shared `return 0;`
  after it: no `default: return 0;` (func_08896228). Two states tested
  `== 1` then `== 0`: `case 0: break;` written first (func_08895FFC); a
  mode switch with case bodies in source order (func_08896484).
- A chain of tests on one value before one call (`beql K1`, then `beq
  K2..Kn` to the same join): one `if (c != K1 && ... && c != Kn) f();`,
  not a `switch` (func_0889377C); `||` chains with `return`, then a
  separate `if`, for two groups (func_08893444).
- `slti v1, x, N; bnezl v1, end` with `v0 = 0` in its slot: the positive
  form, `if (x >= N) { ... } return 0;` (func_088952E4); a tail test
  `bltzl x, ret0`: `if (x >= 0) { ...; return 1; } return 0;`
  (func_088966C0).
- `beqz` on a switch value before the range check, table entry 0 equal to
  the default: `if (x == 0) return;` before the `switch` (func_08895644).

- A count-down loop of `lb` / `lb` / `sb` / `sb` (count 3, both pointers
  stepping by 2), then `lbu` / `lbu` / `sb` / `sb`: struct copies, a
  6-byte align-1 struct `{ s8 b[6]; }` and a 2-byte `{ u8 b[2]; }`
  (func_0889942C, func_08899E80, func_08899F30). In C++, `old[i] =
  members[i];` gives one such loop per sub-structure, by alignment (`lb`
  pairs, `lh` loop, `lbu` / `sb` for a `u8[2]`); skipped bytes are an
  unnamed bit-field `s16 : 16;` (func_08898980).
- A 0x14-byte record copied to the stack as three then two `lwc1` /
  `swc1`: a local `struct { F3 a; F2 b; }` of floats filled member by
  member from a pointer, fields read back through casts (`*(char **) ((char
  *) &m + 8)`; func_0889A138 and its neighbours, as func_088B1C34). The
  same record by value: exact size with padding, and the speed setting
  unrolls the 5-word copy (func_0889A700, func_0889BE7C, func_0889BEC0,
  func_0889C4D0). Without the speed setting a whole-struct copy gives a
  word loop. In C++, `Arg copy = *arg0;` (initialised declaration), not
  `copy = *arg0;`, keeps the copy before the other loads (func_0889BFA0).
- Members loaded in a batch before their stores (three `lbu`, then three
  `sb`; two `lh` or two `lwc1`, then the stores) in a member-by-member
  record copy: those members are a small sub-structure (`{ u8 b[3]; }`,
  `{ s16 a, b; }`, `{ float a, b; }`) assigned whole (func_0889BCB4).
- An array at a large offset of the object (`lui` plus a displacement)
  with the operands of `bnel` / `addu` reversed, or the base and `i * 12`
  kept in two saved registers: an outer struct `{ char pad[OFF]; Entry
  e[N]; }` used as `arg0->e[i].field` (func_08898898, func_088987D4,
  func_0889A3D8).
- An initialised local array copied with unrolled `lwc1`/`swc1` from the
  data: the array in the innermost block that uses it, and the speed
  pragma. mwcc puts the initialiser in `.data`, not `.rodata`: give it to
  the unit with a `.data` piece (`[off, .data, unit_X]`; func_0887BB48).
- `addu v0, v0, v1` with the scaled index first: index a typed array,
  `((u16 *) (p + 0x29C))[idx]`, not `*(u16 *) (p + idx * 2 + 0x29C)`
  (func_0887BB48). An inner loop whose offset starts after the `blez`
  guard: index a struct array with the counter, no stepped offset
  (func_088795F4).
- Two field loads before the first compare: read them in block locals
  first, declared in the order of the loads (func_0887BB48).

## Addresses, arrays and structures

- A table element whose index product is computed before the load of the base
  pointer: char arithmetic, `(Slot *) (base + k * 0x8C + 0x30)`; `(Slot *) (base +
  0x30) + k` loads the base first (func_088C0E58).
- A copy loop whose destination pointer starts inside the element (`d + 0x10`):
  the fields belong to a nested structure reached through its own pointer,
  `Info *di = &d->info;` (func_088C0E58).
- `lui at` / `ori at` / `addu` for a large offset where ours folds it into the
  load (`lui 0xF8` / `lw -0x5AAC`): the address is read twice in the function;
  declare the locals of each read in its own block (func_08841100).
- A large offset (`lui` + `addu` then a small one) is `(char *) p + off`, not an
  integer sum (`pointer_offsets`).
- Array access gives `addu index, base`; the pointer sum `p + i * k` gives
  `addu base, index`. With an `s32` base the offset must go on a `char *`.
  Operand order of `+` / `&` in the source does not matter.
- Structure arrays: `*(T *) &((E<K> *) (p + off))[i]` with the index in a local
  (func_08830728) (`stride_arrays`). Two fields of one element at large offsets
  (`lb 0x787(r)`, `lbu 0x77C(v)` from one `addu index, base`): write both as
  `((Blk *) (p + off))[i]` with their own offset (func_08872108).
- Separate pointer induction variables for the stores and the loads of the same
  arrays (some spilled): the stores use another index than the loads, e.g.
  `a[count] = ...` then `f(a[i])` with `count` and `i` both incremented
  (func_08871DCC).
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
- Constructor shapes that store `(this + 0x1C) - 0x1C` to a global unfolded
  (`addiu v0, s0, 0x1C` / `addiu v1, v0, -0x1C`): the sum goes through an
  integer cast, `D = (s32) ((char *) (s32) ((char *) d + 0x1C) - 0x1C);`.
  static_cast and inline base members fold it (func_088B97BC, func_088CC568,
  func_088A6FEC).
- A constant 12-byte object split by splat (`D_089B9228` + 8 vs `D_089B9230`) must be
  one symbol before a structure copy can match (func_0890682C).
- A structure copied member by member where small byte arrays are copied two bytes
  per pass (`lb`/`lb`/`sb`/`sb` loop) and the members one by one: a whole-structure
  assignment, or `d->arr = s->arr` on a 4-aligned member, copies a 6-byte array as
  a word and a halfword. Write each member, and each byte array as a cast copy
  `*(B6 *) d = *(B6 *) s` (`B6` = `struct { s8 b[6]; }`). Two `u8` members after a
  `u16` at a 2-aligned offset merge into an unaligned `lwl`/`lwr` copy unless
  written through `u8 *` (func_088B42C0, C, not C++).
- A copy loop moving two words per pass (`lw` / `lw` / `sw` / `sw`, count 0x19,
  step 8) is a whole-structure assignment of a 0xC8-byte `struct { s32 w[0x32]; }`;
  one word per pass (count 0x19, step 4) was a hand-written loop of 0x64 bytes,
  and an 8-byte `s8` structure gives the `lb` / `lb` / `sb` / `sb` loop of count 4.
  The registers of the outer loop follow a destination pointer local declared
  last (`Blk *dst`, func_088B3F60); a `char *` destination stepped by 0xC8 or a
  `Blk *` parameter swaps them.
- Read-modify-write of a member reached through a repeated cast,
  `--((Slot *) (p + 0x1C60))->timer`, gets its address computed once into a
  register (`addiu a0, s0, 0x1C80` / `sw v0, 0(a0)`); the original keeps
  `0x1C80(s0)`: write the member as `*(s32 *) (p + 0x1C80)` (func_088B6E8C).
- A 0x14-byte result copied as four floats then one (`lwc1` x4, `swc1` x4,
  `lwc1` / `swc1`): a structure of an `F4` (four `f32`) and an `f32`, copied
  member by member (func_088B6D10; func_088B1C34 has `F3` + `F2`).

- A large-offset byte array indexed by an argument (`addu $v0, index, base`, then
  `addiu 0x22F0` + `addiu 0x7FF8`): a structure member array, read and written
  as `arg0->flags[i]` each time; a `u8 *p = &arg0->flags[i]` local puts the
  base first (`addu base, index`), and a `char *` sum with the offset folds it
  into `lui` + `addu` (func_088C6B84, func_088C6BCC).

- A float test against zero with the value first (`c.eq.s $f1, $f0`, zero in
  `$f0`) and `bc1t` to the zero case: the implicit test `d ? d : 1.0f`;
  `d != 0.0f` or `d == 0.0f` put zero first, and an `if` gives `bc1f`
  (func_088CAB98).
- A float reinterpreted as bits through the stack (`swc1` then `lw` / `lbu`):
  `*(u32 *) &f` and `((u8 *) &f)[i]` on a float local (func_088CAB98).

- A call result compared as a byte with no `andi 0xFF`, its argument loaded
  before the other operand: declare the callee `u8 f(char *, u8)` instead of
  casting an `s32` result (func_088CD964, func_0884FC74).
- `x ? x : 0xFFFF` on a `u16` returned with no `andi`: return `s32`
  (func_088CDC8C).
- A loop with a constant count and no jump to its test at entry: `i = 0; do
  { ... } while (i < 4);` (a `for` jumps to the test first).

- `addu` operands swapped on `base + i * size + off`: `(T *)(base + i *
  sizeof(T) + 0x10)`, not `&((T *)(base + 0x10))[i]` (func_088A5548);
  `lw 0x10(idx)` after `addu idx, base`: an array member, `p->unk10[i]`
  (func_088A5454, func_088A4CB0).
- Global array base set up before the counters in ours: declare the global
  as an array and index it, no pointer local (func_088A489C).

- `addu v1, s0, v1` on `base + idx + off` with an `andi 0xFF` lost: struct
  array fields (`arg0->count[arg0->cur]`, `&arg0->list[cur][n]`) or array
  indexing on a cast base (func_088915B0, func_08891474, func_08891A28,
  func_088930A8).

- A u16 table inside a large record scanned through a pointer stepped from
  the base with the offset in the load: a struct field array reached
  through a separate `Obj *obj = (Obj *) arg0;` local, the parameter kept
  `u8 *` (func_088932A8); `arr[j] == x` gives `bnel load, x`, `x ==
  arr[j]` the reverse.
- A u8 index recomputed (`andi 0xFF`) after each call: an s32 parameter
  with `(u8) arg1` at every use (func_08895644); a byte flag kept unmasked
  in a saved register and masked only at the compare: an s32 parameter
  compared as `(u8) arg4 == 1` (func_08894B0C).
- A byte field address kept in a saved register (`addiu s0, obj, 0x11`):
  a struct field, not a cast offset (func_08895538).

- Index and row pointer in swapped argument registers for `tbl[row][col *
  2]` before a tail call: `q = tbl[row]; q += col * 2;` in separate
  statements (func_08896C58, func_08896CA0); a byte read at `tbl[i] + j * 2 +
  1` with the operands of the `addu` reversed: `(s32) tbl[i] + (u32) (j * 2)
  + 1` (func_08896CF8).
- A template copied field by field into a pointer target, with each load
  moved above the previous store (`lui` before every load, two value
  registers): declare the template externs `const` (func_08896EB8).
- `addiu vX, zero, -0x81; and` on a byte, then `andi 0x80` tests: plain
  masks on a u8 field, not a 7/1-bit bitfield (func_088971F0).

- Counter cleared before the pointer copy: both in the `for` header,
  `for (i = 0, p = arg0; ...)` (func_08898748); a speed loop guarded by
  `blez n` with the pointer copy after the guard: `if (n > 0) { p = arg0;
  do { ... } while (++i < n); }` (func_08899D00).
- A field of a stack copy kept in `$s0`: read it once into a named local
  right after the copy (func_0889AACC, func_0889A918); a value stored to a
  member and then compared from a register shifted by one: drop the local,
  compare the member (func_0889A828).
- Mode tests as `xori` / `sltiu` / `or` chains: `return (s == 2) | (s == 3)
  | ...;` (func_088994AC); `addiu -1; sltiu at, 4` with no `andi`: `(u32)
  (*(u8 *) p - 1) < 4` (func_08898980).

- Stack slots of a record copy and a byte buffer swapped: swap their
  declarations; the first local declared gets the higher offset
  (func_0889AF48, func_0889AFAC, func_0889C214; two arrays: func_0889C7B4,
  func_0889C81C).
- Inline 6-byte compare loops (speed setting):
  - one operand stepped by its own pointer where the original recomputes
    `addu base, i` at each pass: copy the parameters into locals of a
    struct type `{ u8 b[6]; }` and compare `a->b[i]` (func_0889AC14);
  - one side indexed with the offset folded into the load (`lbu
    0x5CE(v0)`): a struct pointer with a pad, `q->id[(u32) i]`, the other
    side plain `b[i]` (func_0889B1A4);
  - the outer guard emitted twice: a `static inline` helper with early
    returns, not inline code with `goto`; the table row pointer computed
    into a local before the call (func_0889ADE8);
  - the byte loads in the wrong order: load both into locals first, `a =
    buf[i]; b = p[0x12C8 + i];`, then the two `<` tests (func_0889BFA0,
    func_0889C2F0);
  - `i = 0` in the guard's delay slot and the record pointer set after it:
    index `base + i * stride` directly, no stepped pointer local
    (func_0889C214);
  - a lookup over 8-byte entries with table pointer and counter swapped:
    index the table in the call, `cmp(id, tbl + i * 8 + 0x50)`
    (func_0889B1A4).
- Loop start registers filled in the wrong order after a declaration-order
  search: write the start assignments in the order the original sets the
  registers, counter included (func_0889C524).
- `i * 200` kept in a saved register with `base + off` recomputed with
  swapped operands: write the sum in the same order at each use so it is
  shared (func_0889C2F0).
- More forms of the inline 6-byte compare (speed setting):
  - the record row pointer computed at each outer pass (`addiu a3, t1,
    0x57C`) and the inner loads at offset 0, where ours folds the offset
    into the load: a row local at the top of the outer loop, `p = base + i
    * 200 + 0x57C;`, indexed `p[j]` (func_0889CF34, func_0889D0E0);
  - the opposite, `lbu 0x57C(s0)` with the offset in the load and an
    extra `addiu` in ours: index the field, `p->ent[j].id.b[i]`, compare
    written in place with `goto done` (func_0889D6EC, func_0889C914);
  - the base copy set before the `blez` guard in ours: `p = arg0 + i *
    0xC8;` as the first statement of the body, not `p += 0xC8` in the
    `for` (func_0889CC34); or an explicit `i = 0; if (n > 0) { p = base;
    do { ... } while (++i < n); }` (func_0889C81C);
  - the two byte loads in reverse order with the `slt` operands swapped:
    `if (key[k] < p[0xBC0 + k]) ... if (p[0xBC0 + k] < key[k])`, offset
    inside the index (func_0889C81C);
  - a `static` compare helper is not inlined here (real `jal`): keep the
    loop in the caller (func_0889CEB0, func_0889D0E0). The `find` / `cmp6`
    `static inline` pair of func_0889A3D8 / func_0889AC14 still fits the
    lookups by the current id (func_0889CF34 to func_0889D608).
- A record found, then fields written at small offsets from a derived
  pointer (`addiu s0, v1, 0x20`) where ours folds them (`+0xAD`): put the
  member in its own local inside the `if`, `q = e + 0x20;` (`e += 0x20`
  is folded) (func_0889D504, func_0889D608).
- Member-by-member record copies: separate count-down loops per member
  (`lb` x2 for 8 bytes, `lh` for 22 or 70 bytes) are members that are small
  structs wrapping an array, each assigned whole; a hole in the copy is a
  pad member (func_0889C914, func_0889CA88). Two `lbu` then two `sb`: load
  both into locals first, or copy them as a 2-byte struct.
- Whole-loop register colouring different around a record row `base +
  (u8) i * 200 + off`, declaration order without effect: a `static inline`
  getter taking a `u8` index; a field read with the record offset folded
  (`lbu 0x63B(row)`): call the getter again in each condition and assign
  the row local only inside the `if` (func_0889E1E0).
- An 8-byte align-1 struct returned by value (hidden `a0`, a count-4 `lb`
  pair loop into the local): `u8 id[8]; *(Id8 *) id = f(x);` with `Id8 =
  { s8 a[8]; }`; a struct temporary gives `lwc1` / `swc1` (func_0889E368).
- A global's full address built (`lui` + `addiu`) before a branch and read
  with an offset after it: a local pointer to it before the `if`, `p =
  D_x;`, then `*(T *) (p + 8)`; a neighbour symbol still tested by its own
  name (func_0889F444, func_0889F544).
- `&local` in a saved register for the memcpy destinations while the
  scalar stores stay sp-relative: `mp = &m;` after the early returns, `mp->`
  only where an address is taken, `m.x = ...` for the stores; a store
  emitted twice, or a field reloaded after a store: write through a pointer
  to the local member (func_0889D8A8).
- A table row with the global loaded before the multiply: `&((Row *) (D +
  0x67758))[a]` with the row size in the struct (func_0889D8A8).
- A lookup loop that leaves with `b` past the next load (copied into the
  slot) and loops with `bnezl`: a `static inline` helper that returns
  inside the loop and returns 0 after it; its input computed in the helper,
  not passed, into the local declared last (func_0889DFAC).
- `addiu base, 0xB34` + `addiu 0x7FF8`, then small store offsets: a pointer
  to a small struct at the large offset, `p = (S *) (arg0 + 0x8B2C);
  p->unk2 = ...`; raw `*(u16 *) (arg0 + 0x8B2E)` stores rebuild `lui` /
  `addu` each time (func_088812B4, func_088808DC). An index added before
  that split (46 %): add the constant to the base in its own step, then
  index at each store (func_08881438).
- `addu v1, v1, base` (offset first) for an entry of a table at a constant
  offset: index an array based at the offset, `((Entry *)(base +
  0x10C))[i].f` or `((s16 *)(base + 0x18))[i]`; raw `base + i * 16 + 0x10C`
  gives the operands the other way round, an array member at 0x10C of a
  struct changes the saved registers (func_0888A49C, func_088855D0,
  func_0888A538).
- A float constant stored by `lui` / `ori` + `sw`: store the bit pattern,
  `*(s32 *)(p + 0x88) = 0x3F75BE0B;` (func_0888A668). With the speed
  setting the compiler builds 0.3f / 0.8f by `lui` / `ori` itself; with the
  size setting it loads them from `@N` (func_088858EC).
- A local struct 4 bytes off in the frame: give it its real size with
  trailing padding (func_0888A538).
- A 12-byte member set by three loads from `__ptmf_null` then three stores:
  `*(PMF *)(p + 0x180) = 0;` with `typedef void (C::*PMF)();` in a C++
  unit; a member pointer built on the stack and tested by `__ptmf_test`,
  then three `lwc1` / `swc1`: `*(PMF *)(p + 0x180) = *(PMF *)&t;`
  (func_088868AC).
- Stores at stride 8 with the same index: parallel arrays, a struct with
  `u16 a[4]; u16 b[4]; ...` indexed `s->a[i]` (func_08880CF8, func_08881114).
- `ori rX, zero, 0xFFFF` where ours gives `addiu rX, zero, -1`: store
  0xFFFF through a `u16` (func_08880CF8).
- A stack struct filled from arguments with the constant stored first and
  the stack argument loaded into the wrong register: write the constant
  store last (func_088801A0); otherwise try the permutations of the field
  stores (func_088800C0).
- `a0` / `a1` loads swapped in every `f(D, arr[i])`: the array is `u32 *`
  and the callee parameter `s32` (func_08880E50).
- `lui 0x31` + `lw -0x743C(v1)` where ours gives `lui; ori; lw 0`: the
  base is a pointer, `*(char **)(arg0 + 0x308BC4)`, not an `s32`
  (func_0888334C). A large constant added through `$at` (`lui at; ori at;
  addu s0, at`): `(s32)(arg0 + 0x549BD0)` with `char *arg0` (func_0888307C).
- An address `base + i * 2` recomputed after each call: a struct of short
  arrays, `base->a[i]`, not `((u16 *) base)[i + 8]` (func_088823B0). With
  the speed setting, raw offsets fold array offsets into stepped pointers
  (`addiu s0, s5, 0x18` then `sw 0(s0)`): a struct keeps `sw 0x18(s0)`
  (func_08881CE0). A fixed byte read through the unstepped base while the
  loop steps a copy: `s->id[i]`, `s->flag` of a struct (func_08882750).
- `addu v0, idx, base` with the scaled index first: index a struct member
  array, `s->f[i]` or `s->e[i].f`, not a raw `*(float *) (p + i * 4)`
  (func_0888C318, func_0888B7FC).
- `sw 0xC(sp)` then `lh` / `sh 0xE(sp)`: a local `union { s32 w; struct {
  s16 lo, hi; } h; }` (func_0888C344).
- Several stack arrays reached through one pointer with fixed offsets
  (0x40, 0x80): one local struct of arrays; separate locals get one stepped
  pointer each, in reverse address order (func_0888C3AC).
- One field load in the wrong register in the first of two unrolled
  blocks: declare the object as a struct instead of raw offsets, same form
  in both blocks (func_0888E28C).
- A local struct passed by address 4 bytes too high in the frame (`sp +
  0x18` for `sp + 0x14`): the struct is larger than the fields written; add
  unused trailing fields (8 to 12 bytes; func_088709D4, func_08870A2C,
  func_08870A80, func_08872AAC, func_08872B7C).
- `lui 7; lhu -0x50EE(v1)` where ours gives `lui 6; ori 0xAF12`, and a
  table base added last through `$at`: a struct for the pointed object, with
  padding and a 2D array member, `&g->tbl[i][j]` (func_08872980).
- `addu` operands swapped in `base + i * K + (s8) b`: index a struct array
  of size K twice in the expression, `e[i].b[off + (s8) e[i].b[off2]]`, with
  no pointer local (func_088714CC). A 2D element `addu x, idx * 44, base`
  then `addu x, col, x`: `((u8 (*)[44]) (p + off))[row][col]` (func_088702F0).
- A 32-bit value from two halfwords with the mask in the wrong register:
  load the high half into the result local first, `v = *(s16 *) (p + 4); v
  = *(u16 *) (p + 6) | ((v << 16) & 0xFFFF0000);` (func_088702F0).
- An unrolled clear on `obj + 0xCC` with offsets 4, 5, 6: an inline helper
  taking the embedded struct and a local `e = &l->e[k];` (func_08874454).
  Two arrays of one record stepped as two pointers: explicit pointers set
  before the loop and stepped in the `for`, declared before the counter
  (func_08874454, func_08873A0C).
- An output pointer stepped next to the counter: `buf[count] = x;
  count++;`, the compiler reduces it (func_08873CC0); a stepped output in an
  unrolled copy: `out->x = ...; out++;` (func_08873A0C).
- The counter set between the `lui` and `addiu` of the table pointer:
  `i = 0; e = TABLE; for (; i < N; i++, e++)` (func_0887CA4C). A
  `do { } while` with the steps at the end of the body for a loop with no
  entry branch (func_0887CAFC).
- Stack parameters loaded into swapped registers: swap the source order of
  the two stores that use them (func_0887FFE8).

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
- Unsigned bounds: `x >= 1000000000` puts the constant in a register, the
  original's `sltu $at` comes from `x > 999999999`; a loop bottom test
  `sltiu $at, i, 0x1EA` (instead of `$v0`) from `i <= 0x1E9` (func_0887EBFC).
- A sum of seven halfwords started from a zero register: seven `sum +=`
  statements, not a loop (func_0887EBFC).
- An initialized local array copied after the first calls: a C++ unit with the
  declaration placed after those calls (func_08877EF0).
- Argument loads in the wrong order around a global first argument: give the
  callee `s32` parameters instead of `s16`/`u16`, or type the global as the
  original loads it (`lhu`: `u16`); a `seh` after `andi 0xFFFF` on a `u16`
  value passed on is an explicit `(s16)` cast (func_08877EF0).
- `sltu $v0, $zero, $v0; xori $v0, 1; bnel` on a call result in C: `if (!!f())`;
  a counted loop entered without a jump to its test: a `do { } while` loop
  (func_08878B60).

- A constant loop unrolled by 8 (eight stores per pass, counter += 8), or a double
  constant loaded as two `lui`/`ori` pairs instead of from the data: the function
  is optimized for speed; put `#pragma optimize_for_size off` at the top of the
  unit (func_0889EB84, func_088A7E44; notes/COMPILER.md, "Speed and space").
- The opposite in a speed unit (our loop unrolled by 8, the original one pass per
  iteration, e.g. a variable-count `v /= 12` loop): add `#pragma opt_unroll_loops
  off` after `optimize_for_size off` (func_088FB2B0, 90 % → 97.7 %).
- A word loop that steps four byte pointers (`buf`, `buf + 1`, `buf + 2`,
  `buf + 3`, each `+= 4`): speed mode and the four pointers written out
  (`*p1 = sbox[*p1]`); `buf[i + 1]` or an inner `j` loop keep one pointer
  (func_088C2D74).
- A two-way unsigned test through `$at` guarding the rest of the function
  (`sltiu $at` + `beql $at, zero` to `return 0`): the rest goes inside
  `if (len < K) { ... }` followed by `return 0`; the early `return 0` form
  uses `$v0` (func_088C2BE0).

- A compare through `$at` (`slt $at, a, b` + `bnez $at`) where ours uses `$v0`:
  the source says `b <= a` / `a > b`; `a >= b` and `!(a < b)` go through `$v0`
  (func_088A7AF0).
- A float test whose `c.ngt.s` is followed by `bc1fl` over the guarded block
  (ours `bc1tl`): the source negates the comparison, `if (!(a > K))`; `a <= K`
  and `K < a` keep ours (func_088B8164).
- Two `else` branches storing the same `u16` field, the original keeping both
  stores (`b` + `sw` each) and re-masking the loaded value (`andi 0xFFFF` in a
  `bnezl` slot): read it into an `s32` local and store `(u16) v` in one branch,
  the field again in the other (func_088C1178).
- An indexed record whose offset is `n * 0x50` computed around the load of the
  base (`sll`, `addu`, `lw base`, `sll`): index a typed array,
  `(*(Ent **) (p + 0xB08))[n].size`; the `char *` sum `base + n * 0x50 + 8`
  swaps the registers (func_088BFCF0).
- A C++ unit in the splat yaml is a `cpp` subsegment (`[0x<offset>, cpp,
  unit_<addr>]`); with `c`, splat writes a `.c` stub beside the `.cpp`.
- `mul.s` with the operands swapped and the difference computed into `$f1`
  in a delay slot: cast the difference, `127.0f * (float) (a - K) / K`, or
  assign it to the variable first (func_088B81F8).
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
- A global record address built once (`lui a0` / `addiu a0`) and read at
  small offsets from it (`lbu 0x20(a0)`), where ours folds each member into
  its own `lui` / `lbu %lo(D+0x20)`: declare the symbol `extern char D[];`
  and cast, `Rec *r = (Rec *) D;`. A structure symbol, a structure array,
  an inline helper and an early return all fold (func_088ADF58,
  func_088AE0D4, func_088AE380). The same for member addresses passed as
  arguments (`addiu a0, s0, 0x62`): a structure pointer local on the
  `char[]` symbol, `m = (Msg *) D;`, passing `m->tail`; a `char *` local
  still folds. Where the original rebuilds the address after a call
  (`lui s0` again), assign the local after that call (func_088AE514,
  func_088AE814).
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
- A null test of a call result on `$v0` (`bnez $v0` with the copy to a saved
  register in its delay slot, then `b` to a `return 0` block): the assignment
  inside the test, `if ((a = f(x)) == 0) { return 0; }`; testing the local
  afterwards gives `bnezl $s1` (func_088C72B0).
- A speed-mode loop that reads its bound from a table entry again at every
  pass (`lw $v0, 0($a0)` in the `bnel` delay slot): index the table in the
  loop, `i < D[k].count` and `D[k].keys[i]`; a `Table *t = &D[k]` local
  hoists the load (func_088C722C).
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
- One argument load scheduled before another where the original has it after
  (`lb a3` before `lh a1`): the type of a callee parameter moves it; an `s16`
  member passed to an `s32` parameter (func_0883488C calling func_088915B0).
- A quotient / remainder masked once when computed (`andi s1, 0xFF`) and again
  at each use: `s32` locals assigned `(u8) (n / 7)` and passed or tested as
  `(u8) q`; `u8` locals drop the second mask. A parameter tested with `seb` but
  passed on unmasked: an `int` parameter tested as `(s8) arg1` (func_0883488C).
- Stack arrays placed in the reverse of their declaration order: declare the
  highest one first (func_0883488C: `box`, `marks`, `text` for `text` at 0x20).
- A stack argument computed before the one stored below it (`arg8 + base`
  ready before `*(p + K) + 0x2000`): the sum is its own statement before the
  call, `arg8 += base; f(..., x + 0x2000, arg8);` (func_08883B54).
- A `seh` of a variable into its own register just before one use (`seh s0,
  s0` then `subu a3, v0, s0`), the variable already extended when set: an
  `s32` local set with `(s16) (q * 6)` and the statement `first = (s16)
  first;` before the call; an `s16` local extends into a temporary at each use
  (func_08818C94).
- A `for` loop whose second variable is updated after the pointer steps
  (`addiu s1` / `addiu s0` before the `seh` of `y` in the delay slot): the
  update goes last in the increment list, `i++, ids++, m++, y += box.h`
  (func_08818C94).
- A guard that leaves with `bnezl` + `addu v0, zero, zero` and a `switch`
  whose out-of-range `beqz` keeps its `nop`: the `switch` sits inside `if
  (f() == 0) { ... } return 0;`; `if (f() != 0) return 0;` gives `beqzl`
  (func_088785CC).
- `slti at, v0, 0xB` + `bnez at` (instead of `slti v0` + `bnez v0`): write the
  test as `x > 10`, not `x >= 0xB` (func_088775F0).
- `(bool) (x & 1)` tested with `sltu` then `beqz`: `if ((bool) (x & 1) != 0)` in
  C++; without `!= 0` the `sltu` disappears, `== 1` gives a `bne` (func_0887A950).
- Test-and-clear of a flag bit where the original computes both `and`s before the
  store and keeps the `sltu`: an inline C++ helper that takes the bool first,
  `bool set = (*f & (1 << n)) != 0; *f &= (u8) ~(1 << n); return set;`, called in
  the `if`; the same statements written in the loop drop the `sltu` or move the
  store up (func_088ABE58).
- Argument loads scheduled in the wrong order around a global pointer
  (D_089CC438 loaded too early or too late): change the callee's parameter
  types (`char *` vs `s32` first parameter, `s32` vs `u16` for halfwords
  passed through) before touching the statements (func_08877100,
  func_088775F0).
- A data piece that follows a unit's `.data` aligns only to what it
  contains: once a split leaves it with `.short` only, it is linked right
  after the unit's last table and the 2 bytes of padding are lost. Give the
  padding its own `pad` entry (func_08876AA8, pad_089A8806).
- A 6-byte global copied to a stack member two bytes per pass (`lb` / `sb`
  loop, count 3): `rec.unk0 = *(B6 *) &D_X;`. With `D_X` declared `B6` the
  plain `rec.unk0 = D_X;` is copied as a word and a halfword (func_088B3778).
- Several fields of one global record that splat named one by one
  (`D_09A2887C`, `D_09A28882`, ...): declare each symbol with its type, so the
  relocations name the same symbols (func_088B3778).
- An initialised `u16 r[4]` local stays on the stack and is read back with
  `lhu`; a structure with the same initializer is kept in registers
  (func_08837D54, NonMatching).
- In a speed unit, `*(s32 *)((char *) p + 0x90) += r` inside a loop: the address
  is hoisted into a saved register (`addiu s7, s5, 0x90`); a structure field
  keeps the `lw`/`sw 0x90(s5)` of the original (func_088A8E3C).
- A per-iteration pointer into a global array written `st = &T[i];` at the top
  of the body (not `st++` in the `for`): the induction pointers are then
  updated in the original order (func_088A8E3C, 97 % → 99 %).
- Parallel global tables searched with one pointer per table stepped in the
  loop (`addiu t1, t1, 1` ...) and no jump to the test: a `for` loop in a
  speed unit. A 16-bit key built from two of them with `(u16) (hi << 8) |
  lo` swapped the two pointers or the `or` operands; `c = hi[i] << 8; c |=
  lo[i];` matched (func_088AEB80).
- A pointer local set before a guarded loop (`lui s0` in the delay slot of
  the guard): assign it before the `if`, not at the head of the loop
  (func_088AEC3C).
- A linked-list walk guarded once (`beqz` to the end, then `bnez` back at
  the bottom): `if (e != 0) { do { ...; e = e->next; } while (e != 0); }`;
  a `while (e)` loop jumps to its test first (func_088B059C, func_088B05B8).
- A stack buffer at an 8-byte boundary where ours is 4 bytes higher: the
  buffer holds 64-bit members, declare it as a `u64` array
  (func_088B0604, ad hoc peer list).
- A minimum computed as `v1 = len; if (max < len) v1 = max;` (`slt`,
  `beqz` with the copy in its delay slot): write it that way, not with
  `?:`; the address after the field is `p + (len + 2)` (func_088B040C).
- A test that leads only to `b end` after a call (`beqz v0, end; nop; b
  end`): the body is `return;`; an empty body drops the test
  (func_088AE988, NonMatching).

- Three values that all return 1, compared `beql 0x6E` (the `1` in its delay
  slot), then `beq 1` and `beq 0x75` to one `v0 = 1; b end` block: one case
  group in the reverse of the test order, `case 0x75: case 1: case 0x6E:
  return 1;`; two groups or three `return 1;` fill another branch
  (func_088CDEDC).
- A small `switch` whose case branches are `beql` with the first instruction
  of the case in the delay slot (ours `beq` + `nop`): the empty case is
  `case 0: break;`, not `case 0: return;` (func_088CDFF8).
- The loads of a global first argument and of a member second argument in
  swapped order (`lw a0, g` / `lw a1, 8(a1)`), unchanged by the callee's
  parameter types: the member is `u32`, passed to an `s32` parameter
  (func_088CDFF8).
- A float argument copied from a saved register (`mov.s fa0, fs0`) before
  the integer arguments where ours puts it in the delay slot of the `jal`:
  the float parameter comes earlier in the callee's prototype
  (`func_088D2674(char *, float, s32, s32)`, `func_08864348(float, char *,
  s32)`); the calls with constant floats did not depend on it
  (func_088D1E40).
- A halfword kept in a saved register, passed unmasked right after its load
  and with `andi 0xFFFF` at each later use: an `s32` local set from the
  `u16` member, passed to `u16` parameters; a `u16` local is never masked
  (func_088CDDAC).
- A call result copied with `addu` where ours has `seh`: the callee returns
  `s32` (its own unit matches either way when it returns an `lh` load,
  func_08813E70 called from func_088CDF5C).
- `beql x, 0xFFFF` to the next instruction with `x = id` in its delay slot:
  `v = (v != 0xFFFF) ? v : id;` on an `s32`, the `(u16)` cast at the use; an
  `if` gives `bnel` (func_088CD044). The same inside nested inline lookups
  that each test `id == 0xFFFF` again (`is_plain`, `map_id`, `base_id`,
  `cur_id` of func_088CD2D4): the repeated tests are kept by the compiler.
- A pointer argument loaded into `$v1` before a test of another global, the
  member read after it: an inline accessor taking the pointer,
  `get(D_08A62C7C)` with `if (g->busy) return 0; return p->a->b;`; a
  conditional expression loads the pointer after the test (func_088CD044).
- Final tests of a function that all branch to the shared `return 0` (`beqz`
  + `nop`, only the first one `bnezl` with the `addu v0` copied): one `&&`
  chain around the block; an early `return 0;` per test gives `beqzl` + `b`
  (func_088CD3FC).
- An index read before the store that precedes the call (`lbu v1, 1(s0)`,
  then `sb` of the state): the index goes to a local first, `idx = p->cur;
  p->state = 1; f(p, &p->e[idx]);` (func_088CD230).

- Eight byte stores per pass at consecutive offsets of `base + i`, the sum
  recomputed at the top of each pass (`addu v0, s1, v1` in the `bnezl` delay
  slot): speed mode and a plain loop storing through the `char *` sum,
  `(arg0 + i)[0x2FF] = 0;`. A `u8 *` cast or an array member is turned into
  a stepped pointer (func_088CE298).
- A copy loop whose destination register starts at the object itself and
  stores at the member offsets (`addu t0, s1, zero`, `sb 0x4F4(t0)`, step
  0xC): the destination is an array member of a structure of the object,
  `((Obj *) arg0)->unk4F4[i] = p->unk3C[i];`; `(Item *)(arg0 + 0x4F4)` starts
  the register at the array (func_088CE298).
- A global first argument loaded in the delay slot of the `jal`, after the
  member passed second (`lhu a1` / `jal` / `lw a0`): the callee's second
  parameter has the width of the member (`u16` for `lhu`, `u8` for `lbu`),
  not `s32` (func_0885CCD0, func_0885CE00, func_0885CE1C called from
  func_088CE298).
- A VFPU quad copy `lv.q C000, 0(v0)` / `sv.q C000, 0(v1)`: an inline helper
  with an `asm` block; the order of its pointer parameters (source first)
  sets which address is computed first (func_088CE5D4).
- A stack matrix written with `sv.q` at a 16-byte boundary, a gap between it
  and the next local: the array is declared `float mtx[16]
  __attribute__((aligned(16)));` (func_088CEE68).
- Two addresses `mdl + K` kept in saved registers from before a speed-mode
  loop (`addiu s7` / `addiu fp` after the counter is cleared): pointer
  locals assigned between `i = 0;` and `for (; i < 6; i++)` (func_088CEE68).
- One byte stored to two members with a single load, the higher offset
  first: `m->unk0[0] = m->unk0[4] = col[0];` (func_088CEE68).
- `lbu` of an id, `lw` of the table, `sll`, `addu table, table, id` for one
  store: a pointer local, `m = &part->unk8[ids[0]]; m->unk0[3] = 0;`. The
  direct `part->unk8[ids[0]].unk0[3] = 0;` puts the sum in the register of
  the id. In the remainder loop of an unrolled loop the same local decides
  which register holds the stored constant (func_088CE75C).
- A `u8` parameter passed on with a plain `addu` and masked at its other
  uses: the callee's parameter is `u8` too (func_08856D14 called from
  func_088CF094); an `s32` loop counter passed to that `u8` parameter gets
  the `andi 0xFF` at the call (func_088CEE68).
- `sll 24` / `srl 28` of a byte and `andi 0xF` of the same byte: two 4-bit
  bit-fields, `u8 kind : 4; u8 mode : 4;` (low bits first) (func_088CF094).
- A byte converted to float through the unsigned sequence (`bltz`, `srl 1`
  / `or` / `add.s`), the product stored to a byte through the 2^31 test:
  `m->unk0[0] = 0.65f * (float) (u32) byte;` (func_088CEAB8).

- Two branches that end in the same conversion, the taken one jumping to a
  copy of it placed after the other (`b` / `ori v0, v1, 2`, then `ori v0,
  v1, 1` / `b` / `andi`, then `andi`): a `switch` with `case 0:` and
  `default:`, not an `if` / `else` nor a conditional expression
  (func_088CF210).
- A compare chain where the last case of a group is a `beql` and the others
  plain `beq` to a shared block: all of them are one group of labels.
  Separate cases with the same body each get their own `beql`
  (func_088D1CA8).
- The jump of the missing default filled with the first instruction of the
  epilogue (`b` / `lw ra`), where the original fills the jump of a case
  instead: an explicit `default: return;` after the last case
  (func_088D168C).
- `bnel` with a load of the old value in its delay slot, then a store of the
  register, the function returning it: `if (cond) { p->m = r; } else { r =
  p->m; } return r;` with a `u8` return. The conditional expression stored
  to the member needs one more move (func_088D1BA8).
- Four floats stored to the stack and loaded with `lv.s S000`..`S003`, then
  `sv.q C000`: an inline helper with float parameters, pointer locals to
  them and an `asm` block. When the temporaries have to sit above the
  vectors in the frame, the helper is a member function of the vector
  structure (`rot.set(x, y, z)`), the structure being declared
  `__attribute__((aligned(16)))`; a plain inline function puts them below
  (func_088D1398, func_088D168C).
- Aligned stack vectors are placed in reverse declaration order (the last
  declared at the lowest address) (func_088D1978).

- `addiu a2, a2, 0x14D0` / `addiu a2, a2, 0x150` (two constants not folded
  into one): the first comes from an inline accessor, `get_bone(mdl, 9)`
  returning `(Bone *)(mdl + i * 0x250)`, the second is the member taken from
  its result. `mdl[9].mtx` on a typed pointer folds them (func_088D28DC).
- A float expression repeated with the same constants, each result computed
  straight into its final register while the constants stay in theirs: a
  macro. As an inline function with a float parameter the first use goes
  through one more register (func_088D28DC, `TO_RAD`).
- `lhu` followed by the unsigned conversion (`bltzl`, `srl 1`): the `u16`
  member is copied to a `u32` local first. `(u32) *(u16 *) p` inside the
  expression emits a second, useless `bltz` (func_088D28DC).
- A pointer computed before a call and kept in a saved register although it
  is only used after it (`addiu s0, a0, 0x10` in the delay slot of the
  `jal`): a local assigned before the call (func_088D2B90).
- Four stack slots written with the same float register in the order x, w,
  z, y before `lv.s` x4: the helper takes `w` as a fourth parameter. With
  `w` as a local of the helper the order is x, z, y, w (func_088D2C14).
- An inner counter cleared before the address of the outer element
  (`addu t1, zero, zero` / `addu t0, s2, v1`): no local for the element,
  `arg0 + i * 0x40` written at each use (func_088D2C14).
- A later loop whose counter and scaled index take each other's registers:
  the loop reuses the counter variable of an earlier loop instead of a third
  local (func_088D2C14).
- `lh v1` / compare / `seh a0, v1`: the element is read into an `s32` local
  and cast back at its use, `v = *p; ... (s16) v * 0x12` (func_088D2C14).
- Floats after the pointers in a call (`addiu a0` / `addiu a1` / `mov.s` /
  `jal` / `mov.s`): the pointer parameters come first in the prototype
  (func_088640F8 called from func_088D2894).

- Addresses of the operands of a VFPU helper computed in the order left
  operand, right operand, destination (`addiu a0` / `v1` / `a1`), where
  pointer parameters give right, left, destination: the helper takes its
  operands by reference, `vec_sub(Vec *dst, Vec &ra, Vec &rb)` with
  `Vec *a = &ra; Vec *b = &rb;` in that order before the `asm` block
  (func_088D2E18). For a matrix product only the right operand is a
  reference when it is a stack matrix (func_088D3B94, func_088D3DBC,
  func_088D2E18); the same product on two members keeps pointers.
- A fifth argument register left untouched before a recursive call
  (`t0` still holds the address of a stack matrix used just before): the
  call passes that stack matrix, not the parameter (func_088D3DBC).
- Three floats loaded, then stored (`lwc1` x3, `swc1` x3, x first): an
  inline helper with three float locals, `float x = src[0]; ...;
  dst->x = x; ...`. A helper taking the three floats as parameters loads z
  first (func_088D2E18).
- The stack slot of a helper's result lower than the slots of every later
  helper: the call is written as the argument of the next helper,
  `vec_scale(&v, &v, vec_dot(&v, &w))`; with a local in between the slot is
  allocated in source order (func_088D2E18).
- In a helper with a result, the result's address in the first register
  (`addiu a1` before the operand stores): declare `float *pr = &r;` before
  the pointers to the operands (atan2 and sqrt helpers of func_088D2E18).
- A source row and a destination row copied with `lv.s` x3 / `sv.s` x3,
  source address in `v1`, destination in `a0`: the helper takes
  `(src, dst)`; a pointer local for the destination matrix gives the
  `addiu a0, a1, 0x10` rows (func_088D2E18).
- Two tables read with the same index, the second one's value needed first
  (`lhu s7` from the +2 table, the +0 value read in the delay slot of the
  test): read the +0 table into its local first, then the +2 one
  (func_088D2E18).
- (0, pi, pi, 0) stored y, z, then w, then x: the `w` of the vector helper is
  a fourth parameter here too, not a local of the helper (func_088D168C).

- A flag built with branches (`addu v1, zero, zero` in the delay slot of the
  first test, `addiu v1, zero, 1` after the second, `andi v1, v1, 0xFF`,
  `bnezl`): an `s32` local cleared before the statements that compute the
  operands, set to 1 under `if (a && b)`, and read as `(u8) in`. Cleared
  right before the `if`, or written as a bool expression or an inline
  function, each comparison is turned into a 0 / 1 value first (`bc1t` /
  `li 1` / `move zero`, then `beqz`); `in++` keeps the branches but gives
  `addiu v1, v1, 1` (func_088D08D4).
- The order of the `beq` chain of a small `switch` is the reverse of the
  source order of the cases, so the bodies' order in the code gives the
  source order; a case value that cannot occur (0xFFFF for a `u8`) is an
  empty `case` at the end (func_088D08D4).
- `beql` to the `else` store (`swc1` in the delay slot) where ours has
  `bnezl` and a jump: swap the branches of the `if`, `if (val != 0) {...}
  else {state->f = 0.0f;}` (func_088D08D4).
- A product whose left operand is converted first, added as the right
  operand of a sum whose left operand is converted after it
  (`mul.s f1, f0, f1` in the delay slot of the second `bltz`): the
  conversion goes to a float local, then `prod = prod * f;`, then the sum
  (func_088D08D4).
- Saved registers s0, s1, s2 for three pointer locals follow the reverse of
  their declaration order (declared `p`, `item`, `state`: `state` in s0)
  (func_088D08D4).
- Inline helpers left as calls (`jal rot_x`) two levels below a large
  function: `#pragma inline_depth(2)` (notes/COMPILER.md, "Inlining depth")
  (func_088CF2C8).
- A flag word read once and kept (`lhu a1`), its mask `andi a0, a1, 0xF00`
  computed again for the table index where ours keeps the masked value: read
  the word into a `u16` local for the tests and index with the field itself,
  `w = item->unk2; if (w & 4) ...; if ((w & 0xF00) != 0 ...) ... D[(item->unk2
  & 0xF00) >> 8]` (func_088CF2C8).
- Stores to a local that nothing reads, kept by the original (three floats
  at +0x30 of a matrix local): they are the fourth row of that matrix, which
  a VFPU block reads later, not a separate vector (func_088CF2C8).
- Three floats loaded, then stored together, the first store placed before
  the third load in ours when the copy is an inline helper with a cast
  destination: write the three assignments directly, `mtx.m[12] = pos.x;
  ...` (func_088CF2C8).
- `mul.s` operands swapped for `table[i] * s` with `s` the result of an
  inline VFPU helper: read the table entry into a float local first, `amp =
  D[i]; f = amp * s2;`; the local also serves the second product
  (func_088CF2C8).
- `beql` to the reset store (`sh zero` in the delay slot) where ours has
  `bnel` and a jump: `if (v != 0xFFFF) v++; else v = 0;` (func_088CF2C8).
- A `u16` field converted to float takes the unsigned path (`bltz`, `srl`,
  `or`, `add.s`) without a cast (func_088CF2C8).
- Three floats read from a vector and stored to a matrix row with x in f0,
  y in f1, z in f2, loaded in that order (ours: x in f2, z in f0, for a copy
  helper with float locals or for three assignments): a helper that takes
  the three values as arguments, `vec3_set(float *dst, float x, float y,
  float z)` called with `v.x, v.y, v.z` (func_088D3F68).
- A float constant loaded once at the top (`mtc1 v0, f4` with 1.0f), stored
  from that register in later blocks and copied (`mov.s f3, f4`) where
  another local gets the same value: a local of its own, `one = 1.0f;`, used
  by name at those places (`scale = one;`, `mtx_scale(m, one, 0.0f, 3.0f)`);
  the other 1.0f stay literals (func_088D3F68).
- `addiu` of a member address (`s3 + 0x5F0`) placed between the loads and
  the stores of a copy that precedes its first use, and the copy's loads
  placed before an earlier VFPU block's stack stores: a pointer local taken
  first, `m2 = &bones[2].unk150; vec3_copy(&pos, &m2->m[12]);`, and the
  copies written before the vector sets (func_088D3F68).
- A chain `beql 3` / `beq 9` / `beq 4` / `beq 6` / `bne 10` over a block
  (ours with a `switch` of empty cases: `beq 10` and a `b`): `if (k == 3 ||
  k == 9 || k == 4 || k == 6 || k == 10) { ... }` (func_088D3F68).
- A call result moved twice before the next call (`addu a2, v0, zero` /
  `addu a1, a2, zero`): the result is assigned to the parameter that lives
  in that register, `arg2 = o->f(...); g(p, arg2, i, 0.0f);`
  (func_088D5F30, func_088D5FE4).
- A loop offset kept apart from its base (`addu a1, s1, s3` with `s3 += 100`,
  cleared after the entry test) where ours folds the base into the stepped
  register: cast the product, `arg1 + (s32) (i * 100)` with `i` unsigned
  (func_088D5F30).
- `seb` of a byte before the add (ours) where the original adds the raw
  `lb` value, stores it and sign-extends after: `p->b = p->b + n;`, not
  `p->b += n;` (func_088D5EF0).
- `bnel v1, v0` (ours) for `bnel v0, v1` in a byte search, the loaded byte
  first: the constant before the index in the address, `*(u8 *)(p + 0x676 +
  i) == c`, not `p + i + 0x676` (func_088D6A1C).
- A short counted search entered without a jump to its test: `i = 0; do {
  if (...) return 1; i++; } while (i < 6);` (func_088D6A1C, func_088D6A54).
- The three address registers of a VFPU helper in another order (original:
  first operand a2, second v1, result pointer a3; ours a3, a2, v1): the
  registers descend in the declaration order of the helper's pointer
  locals, so declare the result pointer first, `float *pr = &r; Vec *a =
  &ra; Vec *b = &rb;` with reference parameters (func_088D64E0).
- `xor` / `sltiu` / `bnez` for an equality test (ours: `beq`): the test is
  an inline function returning `bool`, compared with 0, `if (is_own(o) ==
  0) return 0;`; `== 1` adds the `addiu 1` / `bnel` form (func_088D6594,
  func_088D6924).
- A result returned through `addu v0, s0, zero` where ours folds the
  constant (`addu v0, zero, zero`) and keeps the variable in two registers:
  leave the loops with `break` to a single `return ret;` instead of
  returning inside them (func_088D72A4).
- `seh` of a saved register before each comparison but none at the return:
  the variable is `s16` and so is the function's return type; a `s32`
  variable with casts hoists the extension (func_088D72A4).
- A narrow parameter masked again at each use, into a scratch register,
  and passed on in its incoming register without a move (ours: one masked
  copy in a saved register): the parameter is an `int`, masked where it is
  used (`arg1 & 0xFFFF`), and the table lookup goes through an inline
  helper with a `u16` parameter (func_088D777C).
- A search loop that steps a pointer next to the index (`lhu 0x568(a0)`,
  `addiu a0, a0, 4`): write the pointer, `p = arg0; do { if (*(u16 *)(p +
  0x568) == id) ...; i++; p += 4; } while (i < 0x18);`; the body then
  indexes the array again (func_088D777C, func_088D7904).
- `i * 4 + base` computed twice for two fields of one element (ours: one
  sum, or a pointer to the element): index two arrays, one per field,
  `((Pair *)(o + 0x542))[i].unk0 = id; ... *(s16 *) &((Pair *)(o +
  0x544))[i] = n;` (func_088D7904, func_088D777C).
- Index and pointer of the first of two search loops in swapped scratch
  registers: give that loop its own index, declared before the other one,
  and keep the pointer shared (func_088D7904).
- A `for` whose bound is a variable has a guard and a bottom test
  (`blez n, end`; ours jumps to the test): `i = 0; if (n > 0) { do { ...
  i++; } while (i < n); }` (func_088D7AD8).
- A 16-bit angle converted with a plain `mtc1` / `cvt.s.w` (ours: the
  unsigned sequence with `bltz`, or reloads from the stack): mask an `int`,
  `K * (a & 0xFFFF)`, and pass the three products as arguments of an inline
  setter (`vec_set4(&rot, K * (ang.x & 0xFFFF), ...)`); a helper taking
  pointers reloads the fields (func_088D852C, func_088D8740).
- `addu v0, v1, zero` to return 1 from the register of an earlier `== 1`
  test, `addu v0, zero, zero` elsewhere (ours: `andi v0, v1, 0xff` bool
  merging, or the call result kept in v0): `if (a) { if (x) return 1; }
  else if (y) return 1; return 0;` with literal returns (func_088D852C).
- Destination and source pointers of a VFPU helper in swapped registers:
  take the destination in a local after the source is filled, `po = &out;
  vec_tfm3(po, &m, &v);` (func_088D8740).
- Two stepped pointers in swapped saved registers in a counted loop: declare
  them in the reverse order (`char *rec; char *own;` gives `rec` the higher
  register) (func_088D6924).
- `bnel` to the join with the assignment in its delay slot, then the same
  assignment again in a block of its own (ours: `beqzl` / `b` per test): the
  tests share one assignment, `if (a || b) v = K;` or `if (a && b && c) v =
  K1; else v = K2;`; the compiler duplicates it (func_088D6B00).
- Comparison with a constant in `$at` or in `$v1`: `x < K`, `x > K` and
  `a <= b` put the `slt` result in `$at` and branch on false; `x >= K` and
  `!(a < b)` use `$v1` and branch on true. `if (x != K) v = A; else v = B;`
  gives `beql` where the `==` form and the ternary give `bnel`
  (func_088D6B00, func_088D6D10).
- A `b` to the epilogue with a `nop` and a second epilogue label where the
  original has one: an early `return` inside the first branch; write the
  rest of the function as the `else` (func_088D6D10).
- `addiu v1, v1, -K` / `sltiu at, v1, N` for a range test: `(u32) (x - K) <
  N` (two `slti` for `x >= K && x < K + N`) (func_088D6B00).
- Addresses of array elements kept in saved registers and stack slots from
  an unrolled loop to a later one (`addiu v1, s5, 0x636` / `sw v1,
  0x5c(sp)`; ours: folded offsets, small frame): the arrays are members of a
  typed structure, `obj->id[i]`; `*(u8 *)(obj + 0x676 + i)` and inline
  accessors over `char *` do not give it (func_088D897C).
- A table pointer built with `lui` / `addiu` before the first test (ours:
  the first test reads the symbol directly): assign the pointer at the top
  of the function, before the code that precedes the loop, `rec = D_X; ...
  for (; rec->key != 0xFF; rec++)` (func_088D897C).
- A later argument loaded before an earlier one (`lbu a3` then `lbu a1`):
  parameter types of the callee, here `u8` second and `s32` fourth
  (func_088D897C calling func_088D8DA4).
- Loop counters in swapped temporaries in a sort: counters of their own
  for the nested loops, not the `i` of the other loops; two byte swaps
  loaded together (`lbu` x4 then `sb` x4) are two plain three-statement
  exchanges in a row (func_088D897C).
- `lhu` / `sra 1` / `sh` to halve a `u16` (ours: `srl` with `>>= 1` or
  `/= 2`): the plain form `x = x >> 1`; `x += x / 2` gives the `ext` / `addu`
  pair (func_088D92F8).
- Five float fields updated with one constant kept in `$f1` (`lwc1` / `add.s`
  / `swc1` five times): a counted loop over the fields as an array, unrolled
  in speed mode; single updates keep `x += K` (func_088D9880,
  func_088D9F3C).
- A caller that passes an `s16` value without `seh` to a function whose
  definition narrows it: the caller sees an `s32` parameter, so the two are
  in different units (func_088D96BC calling func_088D9EB8).
- Byte locals filled from one of two record tables, in other registers and
  loaded in another order than the original: here the declaration order
  does change the registers (kind, type, elem, power, elem value, base,
  flag, then the 16-bit results) and the loads must be written in one
  order in both branches (type, elem, power, elem value, base; `= 0` at the
  same place in the branch without the field). Found by permuting the
  declarations, then the statements of each branch (func_088DA398).
- A jump table for a `switch` whose first cases do nothing (ours: a compare
  chain): write the empty cases, `case 0: case 1: case 2: case 3: break;`
  (func_088DA398).
- `seh v0, a2` / `blezl` before a call that takes the value, the value kept
  in the argument register and moved to `$v0` at the end: one `return` at
  the end, `if (val > 0) { if (flag != 0) val = f(obj, flag, val); } return
  val;` (func_088DA398).
- `bnel` to a shared `return 0` for the first test and `beql` to `return 1`
  for the second: one condition, `if (a == 0 && (x == K1 || x == K2 || ...))
  return 1; return 0;` (func_088DA324).
- A `u8` counter masked at each step next to a stepped pointer (ours: the
  index masked and scaled in the loop): step both, `for (i = 0; i < 7; i++,
  p++)` (func_088DAB94).
- A 16-bit value converted to float through the unsigned sequence, scaled
  and kept unmasked in a saved register (`andi` only after the conversion
  back, `addu v0, s0, zero` to return): a `u32` local and an `s32` result,
  `v = (u16) (u32) (K * (float) v);` (func_088DADD8).
- `addu` operands of an indexed member: the value `p->slot[i]` adds the
  scaled index first (`addu v0, v0, a0`), the address `&p->slot[i]` (or
  `p->slot + i`, a reference, a member function returning the address) the
  base first. A slot read then written through one saved address (`lw s0,
  0xC(v0)`; `addiu s1, v0, 0xC`): index it twice, `obj = p->slot[i]; ...;
  p->slot[i] = 0;` (func_088DBA0C, func_088DBBBC). The same holds for
  arrays far into a large structure (`g->head[k]` at +0x80028): type the
  structure instead of adding offsets to a `char *`.
- An `if` / `else` that both branch to a lone `b` to the end instead of
  going there directly: the value is assigned after the `if` / `else`,
  `if (...) { ...; r = v; } else { r = 0; } var = r;` (func_088DB608).
- `bne v0, v1, ...` on a call result with the copy to the saved register in
  the delay slot (ours: copy, then compare the saved register): keep the
  result in its own local, `r = f(); arg1 = r; if (r == -1)`
  (func_088DB608).
- A global pointer loaded again for the first call of a case although a
  local copy made at the top of the function is still live (ours passes the
  copy; after a call both reload): only a volatile read gives it,
  `f(*(char *volatile *) &D_x, ...)`; an inline getter, another local type,
  a pointer to the global, `const` and a later assignment do not
  (func_088DBBBC). A device, not a claim about the original source.
- `addu v0, zero, zero`; `b end`; `nop` after a store (delay slot left
  empty, the other branch setting `$v0` too): a result variable set in both
  branches, `if (...) { ...; r = 0; } else { ...; r = 1; } return r;`
  (func_088DBEE0).
- `li v0, 1` both before a lone `b end` and in the delay slot of the jump
  to it: a case falling through to `default: return 1;`; the waiting branch
  of that case leaves with `break` to the `return 0` after the `switch`
  (`bnel` with the value in the delay slot), func_088DBF3C.
- Speed mode, a loop that multiplies its counter by the element size at
  each pass (`sll` / `addu` chain, not a stepped pointer) next to loops
  that are strength reduced: the multiply is unsigned, `(Node *)((char *)
  base + i * sizeof(Node))`; the signed `&base[i]` is stepped
  (func_088DC40C).
- A stepped pointer set after the counter, behind the loop guard (`blez`;
  `addu s2, zero, zero` in the delay slot; `addu s1, s4, zero`): the
  compiler's own, write `&base[k]` at each use; a pointer in the `for`
  header is set before the guard (func_088DC40C).
- Counter and stepped pointer of a loop in each other's register, or the
  counter of a loop and the base pointer / temporaries around it in other
  registers, although every declaration order was tried: each loop has its
  own counter, not the one of an earlier loop (func_088DC40C,
  func_088DCFCC: three loops, three counters).
- `seh a0, v0` right after a call, the value shifted later from `$a0`
  (ours: `seh v0, v0` and the shift into `$a0`): an `int` local holding the
  narrowed result, `s32 id = (s16) f();`, not an `s16` local
  (func_088DCA10).
- Independent set-up statements (a load, float constants, table addresses)
  with one instruction scheduled elsewhere (`mtc1` before or after a
  `lhu`): the order of the statements decides; assign the locals in
  separate statements and permute those (func_088DCB00: index and first
  pointer before the two factors, second pointer last).
- Four bytes built on the stack and returned in `$v0` (`lw v0, 0xC(sp)`):
  a union of `u8 c[4]` and `u32`, returned through the `u32`
  (func_088DCB00).
- Unrolled loop (speed mode) with its test in `$at` (`slti at, a0, 0x24`
  in the middle of the body) and every register one step lower than ours
  (test in `$v0`): the bound is written `i <= 42`, not `i < 43`
  (func_088DD91C, func_088DDA44).
- `sltu v1, a0, a2`; `bnel v1, ...` with the zero result in the delay slot,
  for an inline function returning 0 when there is not enough left: the
  positive test first, `if (left >= size) { ...; return x; } return 0;`
  (func_088DDBD8).
- `andi` + `sltu` + `xori v1, v1, 1` + `beqz`: the bool exclusive-ored with
  1, `if ((bool) (f & 2) ^ 1) r = 1;`, with a result variable preset to 0
  (func_088DDF10).
- A direct tail call (`j func`) in C++ needs `#pragma exceptions off`, as
  the virtual ones (func_088DDE20).
- `li v0, 2`; `beq a1, v0, body`; `li v0, 1`; `beq a1, v0, body`; `b end`
  where ours makes a range test (`addiu v0, a1, -1`; `sltiu at, v0, 2`) for
  `arg1 == 2 || arg1 == 1` or a `switch`: nested negative tests,
  `if (arg1 != 2) { if (arg1 != 1) return 0; }` (func_088DE560).
- Signed byte tested with `!= 0` in C++ before a `(bool) x ^ 1` test gives
  an extra `sltu`: test it bare, `if (*(s8 *) p) { ... }` (func_088DE7C8).
- Counter of a search loop kept in `$v0` with `seb v0, v0` after its
  increment, and returned as it is: the counter and the return type are
  both `s8` (func_088DE060, not matched for another reason).

- Pointer to a table built after its first read (`lui; lhu %lo(D)`) where
  the original builds it first and exits with `beql`: initialise the
  pointer through an integer cast, `e = (Entry *)(s32)D_x;` (func_088DAD58;
  the same cast keeps a field pointer in one register in func_088EF9C8).
- Lookup through nested tables, each table or row pointer loaded early:
  one pointer step per level, `p = tbl[k]; p += i; q = *p; q += j; v =
  *q;` (func_08870AEC).
- An indexed table address kept in its own register: take the element's
  address as its own step, `t = &t[idx]; e = *t;`, and follow a chain of
  table offsets through one reused local (func_088C03CC).
- A loop-invariant 16-bit id kept in a saved register and masked at each
  comparison (`andi 0xFFFF`): compute it inside the loop in a `u32` local
  and narrow it with a separate `id &= 0xFFFF;`, on an `s32` parameter
  masked `& 0xFF` (func_088DDE20, func_088DDF94, func_088DE060,
  func_088DE3D4).
- A constant index multiplied but only half folded (`li a0, 8; li v0,
  0x10; addu v0, v0, a0; sll s1, v0, 2`, offset kept for a second lookup):
  `#pragma opt_propagation off`, one `s32 idx = 8;` shared by both lookups
  and an inline helper that indexes `tbl[i]` with no copy of the index
  (func_088DC1F0, NonMatching for two saved registers).
- Table pointer and computed index swapped in an inline lookup (`addu v1,
  a0, v0` for `addu v1, v1, v0`): put the index in an earlier
  function-level local not used again, not in a fresh local, with a helper
  that indexes `tbl[i]` with no copy (func_088DB608; `opt_propagation off`
  hurts the rest of that function).
- A parameter copied unextended into a saved register and extended at each
  use: an `s32` local assigned in its own statement (`kk = k;`) passed to
  `s16` parameters; the `s16` call result stored back into the same local
  (`kk = v;`) (func_088C1344).
- A narrow parameter kept raw in one saved register and extended in
  another: declare it `s32`, copy it once into an `s16` local, and write a
  fresh `(s16) param` at the use that extends it again (func_088ADA44); or
  `(s16)` casts at each use and `x = (s16) x;` in place in the other
  branch (func_088AAD58).
- An `lh` value extended again (`seh`) after a branch, the float conversion
  using the raw register: an `s32` local set from the field, used as is in
  the float expression and as `(s16) w` elsewhere (func_088F4210).
- An invariant `seh` placed after the loop guard: a second `s16` local
  copied inside a hand-written guard, `i = 0; if (n > 0) { x2 = x; do {
  ... } while (i < n); }` (func_0882232C); a `blezl` guard with `v0 = 0` in
  its slot: the speed setting and `if (pos < n) { value; do { } while (pos
  < n); }` (func_088A8988).
- A constant register reused by `seb rD, rC`: chained assignment `w = c =
  K;` (func_0882232C).
- A `u16` step whose `andi` comes after `i++`: put the step after `i++`
  (func_0882232C).
- Two 16-bit keys built from byte pairs, `bnel` on the wrong test: build
  each key in two statements on a `u16` local, `x = p[hi] << 8; x |=
  p[lo];`; the operand order of the second test sets the `bnel` registers
  (func_088B6E14).
- Loop offset, block and size in the wrong saved registers: `for (i = 0, p
  = 0; ...; i++, p += K)` with a `u32` offset and the constant grouped with
  the base, then a declaration-order search (func_088C022C).
- Saved registers only right when pointers and integers share locals:
  every local `s32` and a scripted search of role-to-local assignments and
  declaration orders (func_088C6DF8, func_088DC1F0, func_088FB2B0).
- A pointer parameter whose saved register is swapped with a later local:
  take it as `void *` and read it through a typed local declared after
  that local (func_088AE988).
- One block-scoped counter per loop (`s32 i = 0;` in each branch)
  (func_088D72A4).
- A copy of a 16-bit number before it is scaled (`addu v0, s0, zero`; `sll
  s0, v0, 2`): pass `(u16) arg` to an inline helper with a `u32`
  parameter (func_088DE6EC).
- Three `s16` copied with x, y, z loaded into descending registers: a C++
  structure assignment of a nested member (func_088D66F4).
- Speed setting for frame and text widths that take each other's saved
  registers (func_088BA2E0); a narrow parameter spilled instead of a table
  base: hold the table in a local and compile for speed, neither works
  alone (func_088AD87C).
- Struct words stored in a scheduler order: try the plain index order
  first (func_088F4210).
- Stack offsets of locals off by 8 with the right frame size: the local
  array is larger than the bytes used (`u8 from[16]` for 6 bytes,
  func_088AD87C).

- Saturating `s16` sum re-sign-extended into a new register: compound
  `v += (s16)(x - 64);` on an `s16` local (func_088A5774).
- A running offset the compiler folds to a constant: one variable assigned
  several times (`off = 0; ... off += 0x20; ... off += size;`); one extra
  register everywhere: the function returns a value (func_088A4CB0).
- Swapped temporaries in one of several same-shaped sections: try splitting
  each loop variable per section (func_088A4CB0).
- A length passed to memcpy with `andi 0xFF` while its `lbu` feeds other
  uses: an `s32` local passed as `(u8) sz` (func_088A812C).

- Loads grouped ahead of stores in an unrolled copy (3 `lhu`, 3 `sh`):
  declare the source `extern const` and walk it with a `const` pointer
  (func_088908FC).
- A pointer parameter and the first call result swapped in their saved
  registers whatever the declaration order: read the parameter through a
  local declared after the result local (`void *arg1`, `char *str =
  arg1`, func_08890F70; `p = arg1;` before the flags, func_08891074).
- A virtual call with an argument register passed through untouched: the
  method takes that parameter (`vfunc_18(arg1)`, func_088901F8).
- A function with no `jr $ra` (infinite loop) followed by another one that
  splat left as an `alabel`: give both sizes in symbol_addrs.txt; the
  second one is a `static` (callback) or plain function after it in the
  same file (func_08890020, func_08890494).
- A call that sets only `$a0` to a function reading three arguments: an
  unprototyped declaration `extern void f();` (func_088908FC calling
  func_08894B00).

- A byte clear that must stay a loop in a speed unit whose other loop is
  unrolled: `do { *q++ = 0; } while (--n != 0);` with `u32 n` (the
  include/unk_msg.h form is unrolled; func_088921FC).
- A guard of an unrolled loop masking its value with `andi 0xFF` where C
  gives a move: compile the unit as C++ (`bool` is one byte;
  func_08891BC8).

- `andi vX, v0, 0xFFFF` after each call and one shared `sh` after an
  if/else of calls: the callees return s32 and a `u16 c` local takes each
  result, then one `*dst = c;` (func_08894754).
- The `lw a0` of a global and the `lui t0` of the format string swapped
  before a call of func_088915B0 / func_08892148: declare their second and
  third parameters s32 (func_08896484, func_088965D8). The definitions
  match with s16; the original parameters are probably ints.
- A literal 1 left in `$a1` before a virtual call with no visible argument:
  the method takes it, `obj->vfunc_08(1)` (func_08895538).
- A va_list parameter: read arguments as `*(*(T **) &ap)++` (taking the
  address of `ap` gives the frame slot and the register order;
  func_08893C6C).
- Statements in the wrong order with the right registers once declaration
  permutations stall: permute the order of independent assignments
  (func_08893444).
- Two-digit parse with the pointer step before the `seh`: a separate s16
  digit local, `d = *p++ - '0'; n = d + n * 10;` (func_08894B0C).
- The end-of-buffer address hoisted and spilled: `pos = size - 1; buf[pos]
  = 0;`; two copies of one loop with different multiplier registers: one
  multiplier local per copy, the second declared last (func_08893C6C).
- A `static` helper written for a repeated store is not inlined and is
  emitted even when unused: drop it (it shifts the link; func_08895644).

- Early exits of switch cases as `beq` + `nop` to a shared `v0 = 0` block,
  the out-of-range path `b end` with `v0 = 0` in its slot: `if (f() == 1)
  break;` in the cases, no `default:`, one `return 0;` after the switch
  (func_08896AD4). In a loop, `beq` + `nop` to the `return 0` after it: one
  `if (a == b && f(x) != 1) { ...; return 1; } break;` (func_0889695C).
- The two operand loads before a `subu` from a call result times 7: put the
  product in the local at the call, `w = f() * 7;` (func_08896D24).

- Three equality tests ending in `bne` to the exit, falling through to one
  store: `if (v == A || v == B || v == C)` in that order, not a `switch`
  (func_0889AA08, func_0889AACC, func_0889A918).
- A callee defined `(void)` but given `$a0` by its callers (`move a0` in
  the delay slot, or the register already holding a value): it takes an
  unused argument; func_0889C518 takes one, and its older callers pass
  what is in `$a0` there (func_0889D7E8, func_088FC62C).
- A value left in `$a1` (or `$a0`) with no visible use before a later
  `jal`: the callee reads it; check the callee's asm (func_088994AC,
  func_08899F30).

- `xori` / `sltiu` tests joined with `or` and one `beqz`: `if ((k == 3) |
  (k == 4) | (k == 5))`; `||` gives a range check (func_0889C0D4).
- `addu v1, off, base` (offset first) for stores into a record array of a
  global: a typed array, `((Rec *) (G + OFF))[idx].field` (func_0889B1A4).
- A `negu` + `seh` argument with the `seh` before the `jal` and a constant
  in the slot: declare that parameter s16 and the one before it u16
  (func_0889B1A4, func_088D72A4).
- `$t3` set before a call to a function that never reads it: the callee
  takes an unused eighth argument; func_088FC810 now declares it.
- A ring-buffer push or pop with the count loaded before the `divu` and
  stored before the `mfhi`: the new index in a local first, `h = (q[0] + 1)
  % q[3]; ret = q[2] + 1; q[2] = ret; q[0] = h;` (func_0889F0D8,
  func_0889F1CC).
- A constant-count loop with the table pointer set before the counter:
  `i = 0; p = arr; for (; i < N; i++, p++)` or `for (i = 0, p = arr; ...)`,
  counter declared first (func_0889F288, func_0889EEA0).
- A virtual call through `$t9` (`lw t9, off(v0); jalr t9`) where C gives
  `jalr v0`: the unit is C++ with a real virtual method (func_088805A0,
  func_08880E50, func_088816AC, func_08881840). `andi 0xFF` after it: the
  method returns `s32`, tested `(u8) obj->vf() == 0`; a `bool` return
  drops the `andi` (func_08881840).
- `mov.s fs0, fa0` at an odd place among the prologue's `addu sN, aN`
  copies: the prologue copies parameters in declaration order, floats
  included; move the float parameter to that place (func_088800C0).
- A float in `$f12` never touched before a call to a function that takes a
  float: the function takes it as a parameter and passes it on
  (func_088801E8 to func_088B8320).
- `a1` copied to its saved register after the other parameters: the first
  callee takes it as an extra argument still in `$a1` (func_08881114); a
  value loaded into `$a2` just before a `jal`: the callee reads a third
  argument (func_08881458). An argument register never set before a call
  to a function that does not read it: drop the unused parameter
  (func_088802C4 now takes three).
- `addu v0, zero, zero` before a `beq` chain and the table pointer kept in
  `a0` / `a1`: `s32 ret = 0;` declared first, set in a `switch` with
  `break`s, one `return ret;` (func_0888080C).
- An inner loop starting at a counter that steps with the outer one: a
  separate counter, `for (i = 0, k = 1; i < 4; k++, i++) for (j = k; ...)`;
  a result flag that copies a counter's register: declare it `u8`
  (func_08880D94).
- One saved register too many around `arg1 + i`: write `arg1 + i` at each
  use, not in a local (func_08881458).
- With the speed setting, the stepped pointer of a guarded loop starting at
  a non-zero `i` built before the guard: index in the body, `for (; i < n;
  i++) { e = (u16 *)(blk + i * 2); ... }`, not `e++` in the header
  (func_08882014).
- Two adjacent loop set-up instructions swapped: swap the set-up statements,
  `i = 0;` before the pointer (func_08882FA4).
- `(s0 + a) + b` where ours gives `s0 + (a + b)`: two `+=` statements;
  `sum = sum + a + b` is reassociated (func_0888307C).
- Two loaded values with t1 and t2 swapped in one store of a speed unit,
  where regroupings, casts and temporaries changed nothing: read the value
  used twice through its own pointer local, `y = (s16 *)(arg0 + 0x128);
  ... *y ...` (func_08893894; found by decomp-permuter).
- With the speed setting, `addu a1, s0` in the slot of the bottom branch
  and the first pass using the incoming `a1`: pass the parameter itself,
  `for (i = arg1; i <= arg2; arg1 = i) { f(D, arg1, x); i++; }`
  (func_088854D0).
- `slt at` / `bnezl at` where ours computes the test into `v1`: write the
  comparison the other way round, `s->idx > n` for `n < s->idx`
  (func_0888A388); `i <= 10` for `i < 11` (func_08885644, func_0888571C).
- A search loop `do { if (p[0] == key) { v = p[1]; break; } p += 2; }
  while (--i != 0);`; `for (i = 16; i != 0; i--)` rotates it behind a `b`
  (func_0888E350).
- Two pointer increments swapped at the loop bottom: put one in the `for`
  header, `for (j = 0; j < n - 1; j++, m += 4)`; a table address kept in its
  own saved register: a local pointer `m = D_x[0]` declared before the
  counter (func_0888C3AC).
- With the speed setting, a `beqz` guard and the pointer stepped in the
  `bnel` slot: `for (n--; n != 0; n--) { arr++; ... }` (func_0888BB40).
- `c.ngt.s best, v` with `bc1t` where ours has `c.lt.s v, best`: write
  `best > v` (func_0888BB40).
- A float constant built by `lui` / `ori` + `mtc1` in a function without a
  loop: the speed setting too; the size setting loads it from `@N`
  (func_0888C344).
- A bounds-checked 20-slot table read in a loop with the base and the
  scaled offset in two registers: an inline accessor taking the base as a
  parameter, `get(D_x, i)` (func_088707D4), or `i * 4 + base + 0x1220`
  written in that order (func_088718F4).
- A loop unrolled by 7 testing `slti at, i, 0x24`: `i <= 0x2A`, not `i <
  0x2B` (func_088702F0). The second walk of an array reloading its element:
  reuse the first loop's pointer local, `for (p = arg0; ...)`, rather than
  stepping the parameter (func_0887265C).
- A pointer start set before the guard of a speed-setting search loop:
  index form `seen[n]`, the compiler strength-reduces it after the guard
  (func_08870D40). Two counters stepped together: set the call-argument one
  before the guard, `j = 0; if (...) return; for (i = 0; ...; i++, j++)`
  (func_08871B34).
- A clear loop that steps the parameter itself and keeps a saved copy:
  `s16 *p = arg1;` first, `*arg1++ = 0`, then `p` to the calls
  (func_08873554). Counter and pointer swapped in an unrolled clear: declare
  the pointer before the counter, `p++` in the body (func_088739A4).
- The count of an unrolled loop: the `slti` limit is the count minus the
  unroll factor (0x52 with a step of 8 and two tail stores: 90;
  func_08873554, func_08873838).
- A `bnel` delay slot runs only when the branch is taken: on the fall
  through the register keeps its earlier value (func_08873CC0).
- Many locals: a hill climb on the declaration lines (swaps and moves)
  found the order of func_08873CC0 in about 15 tries.
- `mult v0, s3` with the call result first: put the result in its own
  local and write `w * scale` (func_0887D02C).
- A field load placed before the call where the original loads it after:
  the call result in a local before the compare (func_0887CAFC). A
  comparison operand loaded before the other's address: put it first and
  flip the operator, `a > b` for `b < a` (func_0887A838).
- The same unsigned division done twice with one constant register: read
  the second operand again in the source rather than reusing the first
  quotient (func_088795F4).
- A callee given an argument that it does not read (`a0` set for the
  call): the callee takes an unused parameter (func_0887CA4C, func_0887CAFC,
  func_0887CBAC and func_0887CC28, called by func_0887BB48).

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
- A function ending with a jump through a vtable (`lw $t9, 0xA8($t9)`; `jr $t9`,
  no frame) where ours calls with `jalr` and returns: C++ makes no tail call at
  all (virtual or through a function pointer) unless `#pragma exceptions off`;
  C makes it, but through `$v0` (func_088C6ADC).
- A parameter still in its argument register is passed on without a move
  (no `addu $a1, $s4, $zero` before the `jal`): the callee does take it,
  `func_08851F20(g, arg1)` (func_088DBBBC, `tools/psp/prototypes.py` counts
  the arguments the callee reads).
- A pass-through argument count is a reading aid: counts only go up
  (`tools/psp/prototypes.py`).

- A global read again after it was just tested or stored (`lw` after the `sw`
  of the same symbol, and once more for the return value after a call):
  declare it `volatile` (the decoder's error code D_09A52180: func_088EF460,
  func_088EF75C, func_088EF894).
- An `else if` chain whose branches all meet at a `b` over the block that
  follows (`b end` / `nop` after the chain, then `v0 = a0`), where ours sends
  each branch straight to the end: the chain sets a local and the `if` block
  ends with `return size;`, the other value is returned after it
  (func_088EF55C; an `else` with one `return` at the end does not give it).
- The address of a global kept in one register as the base of a run of stores
  (`lui v1` / `addiu v1` once, then `sw x, off(v1)`), where a pointer local set
  to `&D_x` is folded into every store (`lui` + `sw %lo` each): set the
  pointer through an integer cast, `p = (T *) (s32) &D_x;` (func_088EF9C8;
  func_08837D54, a saved register kept for two calls: 84.6 % -> 100 %).
- `seb v0, v1` of a constant register in one case of a `switch` that returns
  small constants: the result goes through an `s8` local (`ret = 1; break;`
  ... `return ret;`) in a function that returns `s8` (func_088EFB18).

- Arguments of a call loaded in another order (the `s16` global of the second
  argument read last in ours, first in the original): the callee's parameter
  is `s32` there, `f(char *, s32, s16, char *)`; the next one keeps its `seh`
  (func_088912BC called from func_088F61B4).

- `u8` locals kept on the stack as bytes (`sb` right after the load, `lbu` at
  each call) where ours keeps masked words (`andi 0xFF` / `sw`, `lw`): the
  callee's parameters are `u8`, not `s32` (func_0882B94C called from
  func_088FA6D8).
- A table row address built from the row counter at each pass (`sll v1, row,
  4`) where ours steps a second counter kept on the stack: index the rows as
  one array, `D[row + page * 3][col]` with `s16 D[][8]`, not
  `D[page][row][col]` (func_088FA6D8).
- `1 << n` in 64 bits calls `__ashldi3` (func_08904350) with the count in
  $a2/$a3; `sra a3, n, 31` needs a signed 64-bit count, `(u64) 1 << (s64) n`
  (a plain `int` count clears $a3) (func_088FA6D8).

- `lw` + `srl 15` and `lhu` + `andi 0x7FFF` on the same word: bit-fields,
  `struct { u32 a : 15; u32 b : 17; }`. `a % 12` divides signed (`div`, the
  field is promoted to `int`); the original's `divu` is `a % 12U`
  (func_088FAE30).

- Display-list packet helper (`0x80198`, func_088596C8), matched in
  func_088F4518 (`submit` in unit_088F4518.c):
  - count read twice with no store in between: once through a cast
    (`nv = *(s32 *) pkt;`, before `cur = list->cur;`) for the `> 0` test, once
    as `pkt->nVtx + pkt->nCmd` in the room test;
  - source built as `&nCmd` then `+4`: walk a word pointer, `src = &pkt->nCmd;
    count = *src++; skip = src[-2]; n = pkt->nVtx + count;`;
  - copy loop as a guarded `do { *list->cur = *src; list->cur++; i++; src++; }
    while (i < n);`; locals declared `i, nv, skip, n, src, cur, count`;
  - the packet words are written in natural order with the full expression
    repeated in each block (no shared locals): the compiler shares them
    across the inlined copies and orders the stores itself.
- A global structure read through one saved base register from its first use:
  `s16 *spr = (s16 *) &D_x;` with the extern kept as the structure, indexed
  `spr[n]` (func_088F4518); a structure pointer local folds.
- Argument loads in the wrong order around the global in `$a0`: read the
  fields as `u16` and let the callee's parameter type convert (`s16` -> `lh`,
  `u16` -> `lhu`, `u8` -> `lbu`) (func_088F69B4, func_088F7108).
- A loop pointer's `lui` far before its loop: initialise the pointer at its
  declaration and leave it out of the `for` (func_088F69B4).
- Several loops in one function, saved registers swapped: one counter per
  loop, then permute the declarations (func_088F69B4, func_088F5C88).
- Speed setting: one loop may need explicit stepped variables in the `for`
  header and the next the indexed form (func_088F69B4).
- A template copied member by member with one symbol per member: one
  assignment per member from separate externs, in C (func_088F5C88).
- Stack order of local arrays: reverse of the declaration order
  (func_088F5C88).
- A byte re-read through a saved pointer after a call: a structure member
  array read both times, the inner call's result stored in a local first
  (func_088F5C88).
- `lb; beqz; seb; beqz` before a speed loop: bare guard `if (x) { for (...; i
  < x; ...) }` with a `u32` counter; `!= 0` drops the `seb` (func_088F7108).
- A constant of more than 16 bytes copied to the stack word by word through
  `lwc1` / `swc1`: locals with a float view (`union { float f; u8 b[4]; }`),
  one assignment per word from externs (func_088F7108).
- `sltu v0` + `bnel` with the constant branch second:
  `if (!(max < *val)) { computed } else { constants }` (func_088F7108).

- Two compiler copy loops (`lh` / `sh`, counting down), one at entry and one
  later: the first is an initialised array at function scope, the second an
  initialised array declared in a nested block at the place of the copy. A
  small buffer that must sit below it on the stack is declared inside the loop
  body that uses it (func_088F56B8).
- `addiu 8` before `addu base`: `y + ((j / 24) * 16 + 8)` (func_088F56B8).

- Wrap clamp of a signed byte field (`bgezl` / `slti at` / `b` with the
  constant in the delay slot, result kept in `$v0`): a nested ternary,
  `f = f < 0 ? max : (f > max ? 0 : f);`, not `if / else if` on a local
  (func_088F2224, func_088F383C).
- Two-way block emitted in the opposite order: write the positive condition
  first, `if (*q != 0 && *q != 3) { ok } else { error }` (func_088F2224).
- `sltu` / `xori` / `bnezl` where the original has `beqzl` on a shifted test
  in a loop with `break` (speed): explicit `if ((x >> 15) != 0)`
  (func_088F383C, func_088F6450).
- Operand load order of a comparison: `b - 13 > a` loads `a` first, unlike
  `a < b - 13` (func_088F383C).
- Search loop stepping a second register: step it explicitly,
  `cur = f + 1; for (k = 1; k < 20; k++, cur++) idx = cur % 20;`
  (func_088F383C).
- First call of a series hoisted before its loop, guard in `$at`:
  `i = 0; f(first); for (i++; i <= 6; i++) f(...);` (func_088F6450,
  func_088F9EF4).
- Counter per loop is not a rule: func_088F6450 needs ONE counter for all
  its loops, func_088F9EF4 one per loop; try both.
- A counting loop that reads `lhu 0x198(a0)` from a stepped pointer: an
  explicit pointer declared first and initialised at its declaration, before
  the count and the index (`char *slot = arg0 + 0x188; s32 n = 0; s32 i;`);
  repeated, it is a `static inline` helper (func_088F2B0C).
- A `jal` emitted before an inlined loop whose result is a later argument of
  the next call: store the call's result in a local first (func_088F2B0C).
- Row offsets and table pointers in lower registers than the loop variables:
  not variables; index (`D[row][col]`, `k * 7 + 0x2F + i * 0x1D`) and let
  strength reduction create them (func_088F9EF4).
- Bytes loaded once per pass into saved registers for `s32` parameters: `s32`
  locals, not `u8` (func_088F9EF4).
- Spill slots: named locals take descending slots in declaration order,
  compiler temporaries ascending slots below them (func_088F9EF4).
- `__ashldi3` with `sra a3` in the delay slot of the `jal`: a `u64` local,
  `mask = 1; mask <<= (s64) n;` (func_088F9EF4).

- A large structure copied member by member (one count-down loop per array
  member, scalars one by one): a C++ structure assignment `dst = *src;` in a
  `.cpp` unit; in C it is a single word-copy loop. The copy shows the layout:
  arrays with an even count go two elements per pass, an 8-aligned `lw` / `lw`
  pair is an `s64`, `lwc1` runs through one base register are a nested
  structure of floats (func_088F012C).
- Speed unit whose byte-wise `clear()` comes out unrolled: add
  `#pragma opt_unroll_loops off` next to the speed pragma (func_088F7620).
- A record base stepped at offset 0 with large displacements: no pointer
  variable, `((Big *) arg1)->recs[i]` with a `u32 i` (func_088F7620).
- Tail `beqzl v0; or s0, s0, s2` then `move v0, s0`: early return,
  `if (flag != 0) { return ret; } return ret | pad;` (func_088F1664).
- `arg1 & 8` kept in a saved register: its own `s32` local; reassigning the
  `u16` parameter masks it again at each use (func_088F1664).
- `addu index, base` for a raw sum: index a typed array,
  `((u16 *)(arg2 + 0x9A))[cursor]`; one-off reads as a cast pointer array and
  loop accesses as structure members give the two orders (func_088F1664,
  func_088F4A7C).
- A saved old byte used unextended in `old - 1` but compared through `seb`:
  `s32 old = *(s8 *) p;` and `!= (s8) old` (func_088F1664, func_088F9058).
- Unlisted switch values reaching the last case through their own label:
  `default:` written just before that `case` (func_088F1664).
- A flag set in the delay slot of a `jal`: assign it before the call
  (func_088F012C).
- Descending `sb` of one constant into a local array: chained assignment
  `a[0] = a[1] = ... = 5;` (func_088F4A7C).
- Copy loop, load of a global, second copy loop: a nested block declaring
  `s16 a[7] = {...}; s32 lang = ...; s16 b[7][5] = {...};` in that order
  (func_088F4A7C).
- A table index constant folded into the relocation where the original keeps
  the `addiu`: cast the whole index, `(&D)[(u32) (sel + 0x3C)]`
  (func_088F9058).
- A sub-expression computed again in an `else` where ours reuses it: write
  the second one with an unsigned constant, `(row + 1U) * 0x10 + 0x64`
  (func_088F9058).

- Coordinates truncated (`andi 0xFFFF` / `seh`) before every call while x and
  y stay in saved registers: `s32` parameters, the truncation from the
  callee's `u16` / `s16` parameters; `u16` parameters keep pre-truncated
  copies in one more register (func_088FBE4C).
- The arguments of one call computed in the wrong order: let the callee's
  `u16` parameters truncate plain `x + 8` instead of explicit `(u16)` casts
  (func_088FBE4C).
- An entry reached through `lbu 0x150(s0)` with pointer registers to its
  fields: write `base->ents[idx].field` at each access, no entry pointer
  local (func_088FC088).
- An early-out block placed at the end of the function: `if (used || n > 0)
  { main } else { placeholder }` rather than an early return (func_088FC088).
- `beql a0, v0` with the constants of a two-way choice the other way round:
  `id = (k != 2) ? 0x1A4 : 0x1A5;` (func_088FC088).
- Pointer set before the loop counter: `for (p = base, i = 0; ...)`
  (func_088FC7A8); in a function with several loops, a pointer local of its
  own declared first and assigned before `n = 0` (func_088FC810).
- `default: return 1;` when the default path leaves the constant in `$v0`;
  `if (call() == 0) { ...; break; } return 0;` inside a case for a `bnezl`
  to the shared `return 0` (func_088FC4F4).
- A global pointer loaded again at the top of each pass of a speed loop
  (bottom test `bnez` + `nop`): declare it `volatile` and copy it to a local
  first, `g = D; e = &g->entries[(u8) i];` (func_088FC62C).
- `addiu v0, v0, 4` after the `addu` of a call result: parenthesize the call
  term, `extra + (func(...) + 4)` (func_088FCF84).
- A pointer set up in the delay slot of the call before a loop: assign it
  before that call in the source (func_088FCF84).
- `sll x, 29; srl x, 30` on a loaded byte: a two-bit `u8` bit-field at bit 1
  (func_089015F8).
- A loop pointer advanced only on some passes: `continue;` before the
  `p++` at the end of the body (func_089015F8).
- The same pointer step in the delay slots of several branches: `p += 0xC;`
  at the end of each arm of the `if` / `else` (func_08901664).
- A flag cleared in the delay slot of the `beqz` on a pointer: initialise it
  before the `if (list != 0)` (func_08901664).
- A call argument register holding the value of an earlier compare load:
  pass that value again (`func(D, p[1], ...)`); check the callee's argument
  count in src/ (func_08901664).
- `beql e, zero` with `addu r, zero, zero` in the delay slot, then the
  fall-through `addiu r, e, 0x20`: `if (e != 0) return e + 0x20; return 0;`
  (func_08901814).
- `bltzl` straight to a shared store of 0: both failure tests in one `if`
  joined by `||` (func_08901814).
- `sltu aX, zero, aX` before a `bnez` on a halfword test: the test through an
  inline helper `return *(u16 *) r != 0;` (func_08901A60).
- Arrays of structures shifted down with one source / destination pair per
  parallel array: separate `dst` and `src = dst + 1` pointers, stepped
  together (func_08901A60).
- A one-float member of a copied structure stored to the stack instead of
  kept in an FP register: make it a nested structure `struct { f32 a; }`
  (func_08901FDC).
- Element addresses as base + index or index + base in one function: mix raw
  byte sums `*(T *)(D + i * size + off)` and typed indexes
  `((s32 *)(D + off))[i]` (func_08901FDC).
- The second test of a "less / greater" pair kept in a saved register instead
  of `$at` in a `beql` delay slot: the same operand order with the operator
  flipped, `if (x[b] < x[a]) {...} if (x[b] > x[a]) break;` (func_089030D8).
- `beql v0, zero` to the epilogue with the result move in the delay slot:
  `if (cond) break;` in the loop and one `return n;` after it
  (func_0890383C).
- Registers of a sum and a count swapped across distant loops: one local for
  every sum and count (func_088FD170, NonMatching).
- An entry copied as `lhu/sh` (id read again) then `lbu, lbu, sb, sb`: C++
  structure assignment of `{u16 id; struct {u8 a, b;} ab;}` (func_088FD170).
- Two adjacent words, high one first, `bne hi, K1` then `bne lo, -1`: a `u64`
  compare; `sll 8; bnez zero; srl 8` against 0xFFFFFF is a `u32 lo:24`
  bit-field compared with a 64-bit constant (func_088FD170).
- Inline helpers nested three levels deep left as a call: the build flag
  `-inline bottomup` (notes/COMPILER.md, "Inlining depth"; func_08901814).

- Callee parameter types change the argument load order: a global first
  argument loaded before the others until the callee's last parameter is
  `u16` instead of `u8` (func_088B012C); two `u16` stack fields loaded
  before an earlier store until the callee takes `s32` (func_088F4210); an
  `lh` loaded after a `lw` until the narrow callee parameter is `s32`
  (func_088AD87C). Argument counts never change.
- A constructor result tested in `$v0` and copied to the object's saved
  register, the free path ending with a `b` over the else: keep the result
  in a `u32` or pointer local, `p = (s32) v;`, test `p`, then `obj = p;`
  after the free (func_088C3948).

- An argument register live across a call without being saved or reloaded
  (`addu a1, a0` in the `jal` delay slot, read again after the call; no
  saved register for it): the callee is a `static` function defined earlier
  in the same file; a global definition or an extern prototype is not
  enough. Put the callee and all its callers in one unit
  (func_088A13AC/140C/146C/14B8/072C/0820 calling func_088A014C,
  func_088A6BA0, func_088AD378, func_088AD4EC; notes/COMPILER.md).
- A parameter copy placed before a `jal` instead of in its delay slot, with
  a `count = 0` there: assign the call result before the zero
  initialisation; the zero then fills the next call's slot (func_088A0820).
- Dead instructions left after a `b` (first instructions of blocks copied
  into branch-likely slots) that `opt_rebuildconditionals off` does not
  change: the body is a `static inline` helper with early returns, called
  as `ret = body(arg); tail(); return ret;` (func_088A1268).
- A pointer and a counter initialised for a loop in the wrong order: both
  in the `for` header, counter first, `for (i = 0, p = base; ...)`
  (func_088A08E4, func_088A0958).
- A global sum loaded after a pointer chain in a comparison: compute the
  sum in a local first (func_088A0DB8).
- Upper bound tests that should use `slti at`: `v > 0x1FFF` rather than
  `v >= 0x2000` (func_088A0360, func_088A0DB8, func_088A061C); a "big
  enough" test with the bound on the left, `if (s <= x)` (func_088AD378).
- `beql x==1 / bne x!=2` where ours gives a range check: `if (t != 1 && t !=
  2) continue;` (func_088A072C); the range check itself is `(unsigned) (x -
  1) < 2` (func_088A0820).
- A list walk ending `bnel next, tail, top` with `n = next` in the slot: the
  exit inside the loop with its own cleanup and return, `if (next == tail)
  { unlock(); return 0; } n = next; } while (1);` (func_088AD378).
- A third parameter copied to its saved register first and tested there:
  copy it into a local at the top and loop on the local (func_088A01D8).
- A field loaded in a guard's delay slot ahead of a `cond ? e : 0`: read it
  into an `int` local before the comparison (func_088A0C74).

- `beql v0, zero, end` with the return 0 in its slot where ours gives
  `bnezl` + `b end`: put the body inside `if (x != 0) { ...; return 1; }
  return 0;` rather than an early `return 0` (func_088A243C).
- A float kept when the input holds a marker (`c.eq.s` + `bc1tl` to the
  next instruction, the old value loaded in the slot, one shared `swc1`):
  `g = (a != K) ? a : g;`, the new value first (func_088A2F88,
  func_088A3AB0).
- `lui` + `lwc1` per float from consecutive data words: one assignment per
  member from named globals declared `float D_X[2]`, the same source
  written twice for a value stored twice (func_088A198C).
- A global incremented, stored and read again before its test, each access
  with its own `lui`: declare it `extern volatile` (func_088A3480,
  func_088A356C); a callback and its argument loaded again before `jalr`:
  the whole struct pointer `volatile T *` (func_088A4004).
- A switch compare chain where only the first compare of a group is `beql`:
  all its values are labels of one case group; values are compared in
  reverse source order; a default body right after the chain: `default:`
  first (func_088A1E70).
- `x = !(a == -1 && b == -1);` for a `not; sltiu; beql; xori 1` chain
  (func_088A1E70); `if (x < 0 || x > 2)` for `bltzl` then `slti at`
  (func_088A32A0).
- A flag-bit loop with `beqz` to the exit and a plain `bnez` back edge: a
  guard and a do-while, `if (f != 0) do { ... } while (f != 0);`
  (func_088A4408).
- Two stores in a row to one field: two compound statements, `x |= A; x &=
  ~B;` (func_088A4280, func_088A42F0).
- A byte-clear loop unrolled by 8 under the speed setting with `addiu
  %lo(base)` after the counter's zeroing: index the global array with a
  `u32` counter, not a pointer (func_088A412C).
- 4-lane s16 to float blocks (registers or `lh` order differ): one statement
  per stage, all four lanes at each stage: convert, `*= k`, `+= st * g`,
  clamp, divide, store; float locals take registers in reverse declaration
  order (func_088A356C, func_088A2498). An inline `clear()` that would be
  unrolled: `#pragma opt_unroll_loops off` (ended by `reset`).
- After an inlined helper, an early error return reaches `b <return move>`
  + nop instead of `b <epilogue>` with the move in the slot: make the helper
  `void`, writing the result through a pointer to the caller's local
  (`if ((*out = f(...)) < 0) { ...; return; }`), one `return ret;` in the
  caller (func_088A2A78).
- A loop count loaded into the wrong argument register before a copy loop:
  read it into its local before the pointer set-up (func_088A2A78); `if
  ((ret = f()) < 0)` puts the copy in the `bgez` slot (func_088A2A78).
- A static leaf callee whose result-free call keeps $a0 (`sceKernel...` state
  passed through): same static-callee rule as above (func_088A4344 calling
  func_088A4178, func_088A2A78 calling func_088A243C).

- A store before a call goes into the `jal` delay slot in the original,
  after the `a0` move: the callee is `static`, defined earlier in the same
  file (func_088A9660 calling func_088A91F4). Parameters spilled to their
  stack homes and case constants in saved registers: speed setting, plus
  `#pragma opt_unroll_loops off` if an inline clear must stay rolled
  (func_088A6100).

- Unnamed argument registers stored at the top of the frame, then
  `li vX, N; slti; bnezl ...; subu; sll 2` from `sp + frame`: a variadic
  function with `va_start` of `include/libc/stdarg.h` (notes/COMPILER.md,
  "Variable arguments"; func_08891474). A callee given that pointer and a
  flag: `char *` va_list, not a struct.
- `andi a1, v0, 0xFFFF` after a call where ours passes the result through:
  two statements on one u16 local, `c = f(); c = g(D, c);`, not nested
  calls; a value kept in an argument register for no visible reason: the
  next callee takes it as an extra argument (func_08891E0C).
- A call result copied to an argument register right after the `jal`, the
  next global then loaded through `v0`: assign the result to the parameter
  that already lives in that register, `arg3 = f(..., arg3, ...); g(D, arg1,
  arg2, arg3);`; a fresh local or a nested call give `lui v1` (func_08882C24,
  func_08882AEC).
- A result stored to a stack slot just before the epilogue and never read:
  a dead `val = f(..., val, ...)` on an address-taken local of a `void`
  function (func_08883FF0, func_088846F4).
- `lhu a1` before the `jal` with `lw a0, %lo(D)` in the slot: the callee
  parameter is `u16` (func_088DE014 in func_08881A30, func_08881CE0); `lw a3`
  before the global `lw a0`: a `u32` last parameter (func_0887FF74 in
  func_08881CE0). A raw `lhu` passed with no `seh`: `u16`, not `s16`
  (func_0887FCBC in func_088823B0).
- Parameters only passed on to calls, saved in reverse parameter order where
  the original uses first-use order: declare the parameter `u32` while the
  callees take `s32`, so every use converts (func_08882D9C).
- `addu a3, s0, x` into a fresh register before `addu a2, s0, zero`: the
  callee takes a fourth argument, the intermediate sum, `old = sum; mid =
  sum + e.a; sum = mid + e.b; f(D, n, old, mid);` (func_0888307C).
- A function of two instructions, `j f; move a0, a1`, whose result its
  callers use: `s32 g(s32 a, s32 b) { return f(b); }`; func_0887FFE0 and
  func_0889EA74 had been written with four unused parameters.
- `p->f = p->f + 0.5f` with the `add.s` operands swapped: `p->f += 0.5f;`
  (func_0888A538).
- A value loaded into `a3` before a branch and one arm calling a function
  without setting it: the callee takes it as an argument; check the
  callee's reads of `a3` / `$f12` (func_0888A538 to func_0888A388).
- The prologue copying `a1` before `a0`: the first callee takes fewer
  arguments than assumed (func_0888D708 takes one, unused; func_0888A668).
- Base and table registers swapped (`a2` / `a3`): compute the base pointer
  before the table load (func_088855D0).
- A `seb` before a later compare of a byte loaded by `lb`: an `s32` local
  from `*(signed char *) p`, then `(signed char) local` in the tests
  (func_088858EC).
- Saved registers swapped and the declaration order does not help: change
  the order of the assignment statements (`b = arg0 + 0xA0;` before `p =
  *(...)`, func_0888D734), or keep the initialisers in the declarations in
  register order (func_0888C9F8, func_0888FBD4, func_0888FCE4).
- Float registers swapped around a call result in a compare: put the
  result in a float local first, `r = f(); if (x > 300.0f + r)`
  (func_0888D734).
- A dead `addu v0, zero, zero` in the slot of the first early return: a
  pointer local initialised at its declaration, `Entry *e = 0;`, set later
  in a loop (func_0888C9F8). An address `base + 4` hoisted out of a loop
  where the original loads `lw 4(base)` inside: read the global into a
  struct pointer local in the loop (func_0888C9F8).
- `add.s` operands swapped on a final sum: the shared operand in a local
  and the quotient in a temporary, `t = ...; return t + y0;`
  (func_0888C294); `mul.s` order of a product of squares: `a = f - lo; b =
  hi - f; ... k * (a * a) * (k * (b * b))` (func_0888E634).
- `a[i + 1]` loaded before `a[i]`, and `a[i]` reused: `x * (a[i + 1] -
  (base = a[i]))` (func_0888C344). Two divisions of the same loads: compute
  both before the first store (func_0888C3AC).
- A constant loaded into `$f13` before a call that seems to take one float:
  the callee takes two floats (func_08897D4C, func_0888E3DC). A branch slot
  setting `a0` whose target is a `jal`: the callee takes it
  (func_0888D888).
- `addu v1, v0, zero` after a call, then `seb`: an `s32 t` set by both arms
  (`t = f(...)` or `t = -1`), then `s8 r = t;` (func_0888FBD4).
- One reload too many through `*slot` after `*slot = p`: reload once into
  the local, `p = *slot; p[0x11] = 2; p[0x12] = 0;` (func_0888FDFC).
- func_08812A08 takes one argument (it sets `a1` itself): the second
  argument of the call in func_0885100C was the register that happened to
  hold a temporary, and the call matches without it.
- func_08859174 takes an unused argument: its callers load `a0` before the
  call (func_0888FDFC) and the definition matches with `s32 arg0`.
- `slt at, tbl, x` with the table in another register and a store moved:
  write the field on the left, `x > tbl[i]` (func_08871BC4, func_088707D4).
- `and v1, load, mask` with the operands swapped: read the byte into a `u8`
  local first, `f = p[x]; if (!(f & mask))` (func_08872444). A byte loaded
  before a call and compared with its result: an `s32` local, not `s8`
  (func_08872444).
- The argument load before the `jal` instead of in its slot: declare that
  callee parameter `u32` (func_088718F4); a global first argument loaded
  before a `u8` one: declare the byte parameter `s32` (func_08870D40).
- A splat function whose first part is a vtable tail call (`jr $t9`, no
  frame) followed by code without a label: two functions; add the second
  to symbol_addrs.txt with both sizes (func_0887142C, func_08871444).
- `bnel a1, v1` for `bnel v1, a1` in a search loop: the masked load in its
  own local, `v = b & 0x7F; if (v == arg1)` (func_08872ED4).
- func_08870AC4 and func_0886D26C return the value of their tail call to
  func_0887265C (func_08873A0C and func_08873CC0 read it): they had been
  written `void`; the callee is declared returning `s32`.
- `beqz arg` to a shared `return 0` after the body, ours `bnez` with the
  return inline: wrap the body, `if (arg != 0) { ...; return 1; } return 0;`
  (func_08862518); two early `return 1` merged the same way into one
  `if (a != 0 && b != 0) { ... } return 1;` (func_08863198).
- A loop-invariant `ptr + K` call argument recomputed in the loop in the
  original but hoisted into a saved register in ours: drop the `(s32)` cast
  on the argument, pass the `char *` (func_0886025C).
- A loop pointer built in two `addiu` steps (`base + 0xA0`, then `+ 0x10`)
  folded into one in ours: integer cast on the sub-object,
  `p = (char *)(s32)(arg0 + 0xA0) + 0x10;` (func_08860A04).
- A constant loaded in the delay slot of the last call before a loop, into
  the saved register of an argument that dies at that call: assign the
  variable just before that call, not after (func_0886171C, `prev = -1`).
  The original compares a `u8` load with -1 (`addiu -1` each pass, never
  true): write `u8 != -1`, not `!= 0xFF`.
- A stack-passed (`$t0`) argument loaded through the saved copy of the
  pointer, `&local` arguments set in parameter order: the callee's last
  parameter is `s16`, not `s32` (func_088630D0).
- An extra `addiu s0, 0x10` per pass where ours has an `sll`: a separate
  offset counter stepped by 0x10, not `i * 0x10` (func_08860A78).
- A `char *` stepped by 0x30 whose register swaps with another pointer
  under every declaration order: step a typed `Entry *e; e++` instead, then
  search the declaration order (func_08860B24).
- `addu` with base and scaled index swapped: index a struct array
  (`p->ent[idx].f`, `((Vec *)(arg1 + 0xC0))[idx].f`) rather than raw byte
  sums (func_08860848, func_08860CB0).
- A 4-byte colour copied as one word (`lw`/`sw`, `lwc1`/`swc1` to the
  result pointer): a union `{ u32 w; u8 c[4]; }` and whole assignments; a
  `u8[4]` struct copies byte by byte (func_08860CB0).
- try_unit.py below 100 % only on `%hi`/`%lo` of D_089CC000 at spilled
  `lui` (the split piece has no relocation there): link it and check the
  BOOT.BIN checksum (func_0886171C, as func_089030D8).
- `addu` with base and scaled index swapped and the address kept in a
  pointer local: drop the local, write `arg0[arg1].f` at each use
  (func_08864348). With a stride of 0x40 to one `s32` field, a typed pointer
  to the field indexed in elements, `((s32 *)(arg0 + 0x38))[i * 16]`, where
  struct indexing failed (func_08863DF4).
- Two range checks ending in one shared `return 0`: `if (!w) { if (a && b)
  return 1; } else { if (a && c) return 1; } return 0;` (func_08864348).
- Speed setting, a byte array read with a fresh `addu base, i` each pass:
  `*(u8 *)(base + i + off)`, not `((u8 *)(base + off))[i]`; a stepped
  pointer that starts at the base with the offset in the load:
  `*(u16 *)(base + i * 2 + 0x130)` (func_088637C4).
- `mtc1` of a decremented field with the store in the delay slot (ours
  stores then reloads with `lwc1`): `(f32)--e->field` (func_088637C4).
- The pointer step before the branch and the s16 counter's `seh` in the
  delay slot: write `p++; i++;`, pointer first (func_08863668).
- An argument zero-extended to 16 bits early (`andi 0xffff` in a delay slot)
  and tested later with `andi 0x8000`: a local `s32 flags = (u16)arg1;` at
  the top; a `u16` local adds a second `andi` (func_08865ADC).
- `if (x & bit) {A} else {B}` giving `beqzl` where the original has `bnel`:
  invert, `if (!(x & bit)) {B} else {A}` (func_08865A64).
- Stores to large offsets each recomputing `lui; addu base; sw %lo`: fields
  of a typed struct (`char buf[0x80000]` first), `p->arr[i]`; raw casts hoist
  separate base pointers (func_088664F8).
- Counter set before the pointer in the original loop setup:
  `for (i = 0, p = arg0; ...)` (func_088665A8). A list walk guarded once by
  `beqz` and tested at the bottom on the saved next pointer:
  `if (n) do { o = n->next; ...; n = o; } while (o != 0);` (func_088665A8).
- Float registers swapped: declaration order works for float locals too
  (func_08865DD4, func_08860CB0). Spill slots follow the declaration order:
  declare a local later for a lower slot (func_0886477C).
- A sentinel test with `beql` to a block placed later: `if (t != 0xFF) {
  nested test } else { sentinel block }` (func_0886477C, func_0886171C).
- A 3-word `lwc1`/`swc1` copy from `__ptmf_null`: a C++ pointer to member set
  to 0 (func_08865D84, as func_088868AC).
- `addu a1, v0, v1` with a call result and a loaded value swapped, the sum
  order in the source changing nothing: put the call result in a local first
  (`t = f(p) << 4; ... t + h * 8`, func_08867D10, func_08868234), or make the
  call term a pointer, `(s32)((char *)(f(p) << 4) + h * 8)` (func_088676D8,
  func_08867B34).
- memcpy argument loads in the wrong order (size loaded first in the
  original): declare the size `unsigned int` (func_08867260, func_08867058,
  as func_088AD1EC).
- A load / add / store-back on one field where the original computes the
  store address before the load: read the field inside the result
  expression, then `field += n;` (func_08866B5C, func_08866BD4).
- A test on 1 then on 0 that both reach the loop increment: `switch` with
  an empty `case 0: break;` written first (func_0886678C, func_088669F4).
- One stepped pointer per stride (+4, +8 from the same base) when the
  original steps several bases, then the declaration-order search
  (func_088669F4, func_0886691C); reads through a typed `e++`, writes
  through raw `arg0 + off + i * 8` (func_08866864).
- A selector (`i == 0 ? base0 : base1 + (i - 1) * stride`) repeated at each
  use with no saved register: a `static inline` helper, not a macro (the
  macro shares the field address) nor a plain `static` (called)
  (func_08868498, func_08868778).
- A constant loaded for a switch compare into `a0` and left for the next
  `jal`: the call takes that constant as its argument (func_08868B6C).
- A halfword table element passed as an argument, loaded early into a
  temporary then moved: declare that callee parameter `u16` (func_08866DC8).
  Conversely the masked copy passed where the original passes the raw
  register: declare the callee parameter `s32` (func_088673CC).
- A table load hoisted into a saved register before a call it is added to:
  declare the callee returning `s32` and cast inline, `D[i][j] +
  (u16)f()` (func_08866E10). `if ((u8)f() == 1) return 1; return 0;` for
  `bnel` + `addu v0, zero, zero` rather than `xori`/`sltiu` (func_08866E10).
- An extra `b epilogue` block for `default: return 0;`: drop the default and
  let unmatched values reach the `return 0` after the switch
  (func_088673CC).
- Saved registers of narrowed arguments permuted in a large call-heavy
  function with no loop, declaration order no help: try the speed setting
  (func_08867F34, 97.89 -> 100 %).
- The last `andi 0xff` of a u8 counter after `addiu i, 1`: increments in the
  `for` header, `i++, a++, b++` (func_08867058).
- `addu` base and index swapped on a table read: give the pointer side the
  `char *` type and add the integer offset to it, `(char *)tbl[i] + off`
  (func_08869750, func_088697D4); index a typed struct array at its real
  offset in the owner struct, `p->ent[i].field`, with no local pointer to
  the element (func_0886A77C, func_0886A87C, func_0886A4CC);
  `((u8 *)(base + K))[idx]` for a byte at a constant offset (func_0886A0B4,
  func_0886A7D8).
- Leftover stores after an unrolled loop with base and index swapped on
  `s16` arrays at constant offsets: a typed local pointer to a struct that
  holds the arrays, `S *s = (S *)arg0; s->b[i] = 0;` (func_08869904).
- A loop with a stepped pointer and a strength-reduced offset counter that
  swap registers under every declaration order: no pointer local, write each
  access `base + i * STRIDE + off` (func_0886A648). A loop stepping the bare
  base with full offsets while the code after it indexes the entry: step a
  pointer to the owner struct and read `slot[0]` through it (func_0886A524).
- A loaded `u16` masked again before a compare with a call result: put the
  call result in an `s32` local first (func_08869504).
- A guarded bounded copy loop (`while (n) { *d = *s; if (!*s) break; ... }`)
  tested at the bottom: speed setting; the load order follows the order of
  the assignments, permute those as well as the declarations
  (func_08868E54, func_0886A7D8). A loop-invariant address placed after the
  counter init: `i = 0;` as its own statement before the pointer local
  (func_0886A7D8).
- A clamp `if (v < 0) v = 0` leaving branch leftovers in each switch case: a
  `static inline` helper with an early return, `if (v < 0) return 0; return
  v;` (func_0886A35C).
- A test on a call result with the copy in the delay slot (`beqz v0`) where
  ours tests the saved pointer (`beqzl s0`): assign in the condition, `if
  ((e = f(a, b)) != 0)` (func_0886AB7C).
- A 0/1 flag as `bnel x, K` with a hoisted 1 in the slot, every form folding
  to `xori`/`sltu` or giving `beql`: `#pragma opt_rebuildconditionals off`
  and `if (x == K) return 0; return 1;` in an inline helper (func_0886AA28,
  still 99.12 %, flag register permuted).
- A missing `sltu` before `bnel` on a bit test: a `static inline u8` helper
  returning `(x & 1) != 0` (func_08869904); a C++ `static inline bool`
  tested `!= 0` (func_0886A7D8). A loop constant 1 for `1 << i` kept apart
  from a returned 1: return `bool` (func_0886A7D8).
- Loops tested at the top, with an unconditional `b` back and the exit
  branch to a shared epilogue: `for (;;) { if (stop) break; ... }`; `while
  (cond)` rotates the test to the bottom (func_0886BF28, func_0886D2E4,
  func_0886D450, func_0886DC68).
- `beql x, K, body` with the body's first load in the slot and `b` to the
  increment, where `if (x != K) continue;` gives `bnel`: `switch (x) { case
  K: break; default: continue; }` (func_0886BD84).
- A dead `ori v0, 0xFFFE; b` tail with `beql`/`blezl` to the epilogue:
  nested `if` with an explicit `else` for each early return
  (func_0886CFA0).
- `sltiu at, v, 2` for "neither 0 nor -1": `(u32)(x + 1) > 1`
  (func_0886D450).
- Unrolled byte-pair sums with hi/lo registers swapped in some repetitions
  only: a `u16 t = lo; t += (u16)(hi << 8);` temporary for those, one
  expression for the others (func_0886B7C0).
- A `u16` parameter masked twice (before a loop and again for an index):
  declare it `s32`, write `(u16)arg` in one place and `arg & 0xFFFF` in the
  other so they are not merged (func_0886C008).
- `bnezl flag` to an add block with the loop's first load copied into the
  other path's slot: reload the pointer in both branches, `if (f == 0) e =
  *p; else e = (T *)((char *)*p + off);` (func_0886DC68).
- In an unrolled loop, a stepped pointer and the counter swapped: step a
  typed `e++` AND declare it before the counter; either alone is not enough
  (func_0886CA74). A loop bound `i <= 0x2A`, not `i < 0x2B`, for `slti at`
  (func_0886BBE4).
- C++ `if ((bool)(x & 1) != false)` for `sltu` + `beqzl`; the plain `(bool)`
  test loses the `sltu` and `== 1` gives `bnel` (func_0886BEA4, still
  99.33 %: two loads from one pointer swap registers because the twice-read
  field is merged into one early load).
- Speed mode: one loop rotated (test at the bottom) and another of the same
  function kept at the top: plain `while (cond)` for the first, `while (1) {
  if (!cond) break; ... }` for the second (func_0886DD3C, func_0886DE78,
  func_0886D374).
- An argument computed as a pointer sum (`addiu a3, s0, K`) scheduled after
  a register-copy argument in the original, before it in ours: declare that
  callee parameter `s32` and pass `(s32)(p + K)` (func_0886D374).
- `default:` of a switch branching to a shared `return 0` with an empty
  slot, while one case returns 0 inline: write that case `case K: break;`
  with no `default` and one `return 0;` after the switch (func_0886B0E0).
  The same for a case that computes a value: `break;` and one shared
  `return sum;`, else the fall-through return becomes a constant 0
  (func_0886C768).
- An empty case tested in the original: write it after the real one,
  `switch (x) { case 1: ...; break; case 0: break; }` (func_0886B918). A
  single-value early return as `beql x, K, body` + `b` to the epilogue: a
  one-case `switch` (func_0886BA50). `default:` laid out first: put it
  first in the source too (func_0886C218).
- A switch on an `s8` table value sign-extended again before the compares:
  declare the switch variable `s32` (func_0886C218).
- A last test kept as `beqz; nop` with its own `move v0, zero` block before
  the epilogue: `if (x) return 1;` falling through to the function's single
  `return 0;`, no inner `return 0;` (func_0886E08C).
- `sh`, `seh`, then `bgtzl` with the field reloaded in the slot: the
  decrement inside the test, `if (--e->timer <= 0)` (func_0886AF2C).
- `seh` of a parameter kept in a saved register while the raw value goes to
  an earlier call: `id = arg1; id = (s16)id;` with `s16 id` (func_0886C8AC).
- Halfwords at +0x18/+0x1A/+0x1C built from two words with `srl`/`sll`/`or`:
  read an `s64` and store `w`, `w >> 16`, `w >> 32` (func_0886B0E0); `srl`
  rather than `sra` for the high half: a `u32` source.
- A local structure or float array 4 bytes too high in the frame: declare
  it larger than the fields used (12-byte message, `f32 v[4]`;
  func_0886B918, func_0886C8AC, func_0886CADC).
- A small structure copied field by field with `lw`/`lhu`/`lh`: assign each
  field, a whole-structure assignment becomes `lwc1`/`swc1` (func_0886E2EC).
- The prologue copies `a2` into its saved register before `a0`/`a1`: the
  first callee takes fewer arguments than declared; count the registers
  its assembly reads (func_0886E130 -> func_0886E08C).
- A parameter in a saved register and the outer loop counter swapped,
  unchanged by every declaration order: the speed setting (func_0886C914).
- Speed setting also needed for float constants built with `lui`/`ori`
  instead of loaded (func_0886CADC).
- A `switch` whose failing cases `bne` to a shared `return 0` while the
  default is an inline `b end; v0 = 0`: no `default:` label, `return 0;`
  after the switch (func_0886E828). Two body-less cases that exit are
  compared in their own place: keep each where the compare chain has it
  (func_0886E9F4).
- A search loop tested at the top with `beql` to the exit (store in its
  slot) and a `b` back that `for (;;) { if (hit) { store; break; } }` still
  rotates: write it with labels, `loop: if (hit) goto done; ...; goto loop;`
  (func_0886E978). The order of the two increments places the `seh` of an
  `s16` counter in the `b` slot (`p += 4; i++;`).
- Ternary order: `x == 0 ? -1 : K` for `bnezl` with K in the slot
  (func_0886E978).
- `and` operands swapped on a `u8` byte array masked with `1 << n`: read it
  through a structure member array, `((T *)p)->bits[i]` (func_0886E36C).
  `slt v1` where the original has `slt at`: put the call on the left,
  `f() > h` (func_0886E36C).
- An initialised local `s16[35]` gives an `lh`/`sh` copy loop from its
  `D_` symbol (an extern structure copy gives `lw`/`sw`); the 64-bit shift
  `(u64) 1 << i` calls `__ashldi3` with `a3 = 0` for an `s32` count, an
  `(s64)` cast gives `sra a3` (func_0886F7FC).
- A skip-forward loop whose walker is in `v0`: step the existing cursor
  variable, not a new pointer local (func_0886E9F4). A `g[i * K + off]`
  byte read with `addu` operands swapped: a block-local `u8 *` copy of the
  global (func_0886E9F4). A bounded table getter as a `static inline`
  taking the global at each call keeps base and offset apart
  (func_0886E9F4).
- A compare-and-swap whose swap reads both fields again after the compare:
  `volatile` element pointers and the compared field read once into a
  local (func_0886F894; a device for the reloads, not a claim about the
  source). A counter zeroed in the delay slot of a loop guard: `cnt = 0;
  if (e->id != END) { off = 0; do { ... } while (...); }` (func_0886F894).
  A byte flag on the stack loaded too early: test it alone, `if (flag) goto
  next;`, not inside `||` (func_0886F894).
- Only a temporary and a result swap saved registers after the
  declaration and assignment order search: the speed setting
  (func_0886E5BC). `s32` return for an `s16` sum when the original ends
  with `seh v0` (func_0886E6F4).
- A large compare constant built in `$at` (`lui at; ori at; sltu`) and built
  again for the store: compare a local holding the new value with `> K-1`,
  not the field again with `>= K` (func_08850FB8, func_0885058C); a clamp
  keeps its two stores in `if`/`else` (func_0885058C).
- An argument masked (`andi 0xFF`) for one use and passed raw to a callee:
  `s32` parameter, `(u8)arg` only at the masked uses (func_08850078,
  func_08850158). No `andi 0xFFFF` before a call on a `u16` counter: the
  callee parameter is `u16` (func_08850E58, func_088507F4). A call result
  masked `andi 0xFFFF` in the caller: the callee returns `s32`, assigned
  to a `u16` local (func_08850158).
- Table address computed before the int-to-float conversion: call result in
  a `u32` local, then a pointer to the table element, then `(float)v * *p`
  (func_08850078).
- Accumulator and argument copy swapping saved registers in a loop over a
  0xFF-terminated list: speed setting, `for (c = *p; c != 0xFF; c = *++p)`
  and the accumulator set to 0 before the pointer load (func_088503F8,
  func_0885048C).
- Field copies whose last fields are all loaded then all stored: those
  fields are one sub-structure copied by one assignment (func_08850910).
- `beq` + `nop` to a `v0 = 1` block placed after a shared `return 0` whose
  `b` slot is empty: `if (g) { if (a == x || a == y) goto found; } return 0;
  found: return 1;` (func_08850C34).
- A loop tested at the bottom on a value read from memory with its counter
  checked in the middle (`slti at`, `beqz` to the exit): `while (c) { ...;
  p++; i++; if (i >= N) break; }`; the order of the step statements sets
  the registers of the stepped pointers (func_08851078). An inner loop with
  a constant bound and a `break` rotated with a duplicated first load:
  `j = 0; do { ... } while (j < N);` (func_0885128C). A top test with a
  `beqzl` bottom test: `if (c) do { ... } while (c);` (func_088511B4).
- Constants of a ternary built in `v0` then `andi s1, v0, 0xFFFF`: cast
  each one, `t = c ? (u16)A : (u16)B;` (func_088511B4).
- `addu v0, v0, s0` (scaled index first) on a table read where every sum
  order gives the base first: cast the index term to a pointer and the base
  to an integer, `*(s16 *)((char *)(i * 12) + (s32)p + K)` (func_08851DBC).
- The same argument masked again at each call: `s32` parameter, `u8`
  callee parameters, no explicit cast (an explicit `(u8)` is shared once)
  (func_08851E54). A call result passed to another call with `andi a1, v0,
  0xFF`: the inner callee returns `s32` (func_08851E54).
- A shared `sltu` after two branches that each load a halfword: assign an
  `s32` local in both and `return v != 0;` once (func_08851D3C).
- `and` operands swapped on a bit test where both written orders give the
  same code: load the byte into its own local first, `b = p[(i >> 3) + K];
  if (b & (1 << (i & 7)))` (func_08852F58, func_08852FA0).
- `addiu a3, a0, K` then a field through `lui` + negative offset: a local
  base pointer `q = arg0 + K` and one offset from it (func_08852E38). A
  global pointer reused as a call argument instead of reloaded: read it
  once into a local (func_08852C20).
- Key tables ended by a marker, the copy of the last entry placed after the
  loop: `while (1) { if (k->t == -1.0f) break; ... k++; }` (func_08852114,
  func_08852618, func_088522CC). Float temporaries of an interpolation
  swapped: the ratio in its own local first (func_08852618). A constant
  stored at the top of every pass but hoisted by ours, even with
  `opt_loop_invariants off`: a `volatile` field, said in the header
  (func_08852200).
- A redundant `ext` after an `and` mask: the shifted value in a `u8` local
  (func_088522CC). A clean register rotation in a long function: drop the
  locals holding loaded words and read the field at each use
  (func_088522CC).
- Index `sel + a * 68 + b * 4` shifted once: a flat array with the explicit
  sum, not a 3-D array (func_08852954).
- A final `andi v0, v0, 0xFFFF` in the `jr ra` slot covering constant
  return paths too: assign every path to a `u16` local and `return r;` once
  from an `s32` function (func_088564F8).
- Only the second-to-last check of a 0/1 chain inverted: write the last
  check as `if (!(...)) return 0;` too, then `return 1;` (func_08855038).
- A `switch` over consecutive cases that must stay a compare chain: an
  `if (x != A && x != B && ...)` chain (func_088552E0). In a long compare
  chain, a `beql K` with the body's first instruction in its slot marks the
  first-compared (last in source) label of a group; its target may be the
  join + 4 of another group (func_088534E8). A `default:` block with an
  empty `jal` slot: add a case label to it, `case 0: default:`
  (func_0885320C).
- A destination `p2 + (p - p1)` emitting `sra`: use the byte difference
  masked, `(u16 *)((char *)p2 + (((char *)p - (char *)p1) & ~1))`
  (func_0885320C).
- The same parameter masked once for the loop compare and again at each
  later use: write the masks differently (`(u16)a` for one, `a & 0xFFFF`
  for the other) (func_08856920), or index a typed struct array
  (`((Info *)D)[a].f`) (func_088569F8), or an `s32` parameter with the mask
  at each use and an `s32` callee parameter (func_08853ABC). An `seh` copy
  of the counter at the loop top passed to a call: an `s16 j = i;` local
  with an `s32` callee parameter (func_088569F8).
- A field pointer kept in a register right after a read: assign the
  pointer local after the read, not before (func_08853ABC).
- An array element base recomputed with `lui` + `addu` at each access while
  the offset is kept: index an array member of a large wrapper structure,
  `((Big *)p)->rec[i].f` (func_08853E20). Each branch of an if/else chain
  doing its own bit-field store: write the store in every branch, `= 0` in
  the last one too (func_08853E20). A table byte loaded before a bit-field
  store in the original but after it in ours: declare the table `const`
  (func_08853E20).
- A large record copy member by member (count-down loops per array,
  unrolled by 2): one C++ structure assignment; two-word loads after a gap at
  an 8-aligned offset are an `s64` member (func_088542EC).
- A list cursor read after the bounds test and kept in one register for
  both address words: assign the cursor local after the test
  (func_0885658C; a second version of the packet helper of
  func_088F4210).
- A compare chain branching to the shared `jr` with no value set: that
  case returns the constant still in `v0` from an earlier compare, so
  write the value it holds (func_08856CA0). A `b end; nop` fall-through
  with `v0` already holding the first compare constant: `default: r = K;
  break;` written after the cases, one `return r;` (func_08856D14).
- Nested loops tested at the bottom with no guard: `do { } while`, and
  `j = 0;` as the first statement of the outer body to get the `bnezl`
  slot reset (func_08856E8C).
- A call result turned into a flag (`sltu; xori; bnezl`) leaving a loop to
  `return 1`: `if (!(f() != 0) == 0) return 1;` (func_088570D8). A chain of
  `andi; sltu; beql` against a register holding 1: one `if (A == 1 || B ==
  1 || C == 1)` with each test `(s32)((x & K) != 0) == 1` (func_08857A34).
- A range guard with `bnezl v0 = 0`, then `beqz at`, and a separate
  `return 0` block after a `b end`: `if (x >= A && x < B) { ...; return e;
  } return 0;` (func_08857058). Two guards sharing one `return 0` block
  placed before the body: `if (x == K || y >= N) return 0;`; `slti v0`
  needs `y >= N`, not `y > N-1`; an `s32` local for a `u16` parameter,
  cast `(u32)` only at the shift, gives `slti` with `srl` (func_08857C98).
- A base built then `+1` added (`addiu t0, v0, 1`) instead of folded into
  the constant: assign the base, then `a++;` before the loop, and step the
  pointers in the `for` header (func_088574A4).
- A 64-bit flag word whose low half is copied (`addu v1, v0, zero`): build
  it with a 64-bit add, `lo + ((u64)hi << 32)` (func_08857D88).

- Threshold chains whose last compare is a `beql` with the default value in
  its slot: `if / else if / else` assigning one result local, one `return`;
  separate `return K;` add a `b` (func_088581C0, func_08858184). An early
  value that must land in the saved result register: assign the local and
  join the shared return (`if (...) r = ...; else {...} return r;`, or
  `goto end;`) (func_08857E74, func_08858010).
- Count-down `lb`/`sb` copy loops (2 bytes or 1 byte per pass) in speed or
  size mode: structure assignment of a struct wrapping the `s8` array
  (`struct { s8 b[27][2]; }`, `struct { s8 b[43]; }`); a float field copied
  through a full `lui`/`ori` + `addu` address: one-member struct (or a union
  `{ s32 i; f32 f; }` when it is also compared as an integer) assigned whole
  (func_08858904, func_08858BD8).
- Unrolled stores to a table at a large offset with the base stepped: array
  member of a struct (`p->tbl[i]`), next addresses written from the stepped
  pointer (`p + 2`), no chained local (func_088592E4). One loop left rolled
  in a speed function: `s32` counter against a `u32` bound
  (func_08859848).
- `slt at` instead of `slt a0`/`v0` on an early return: try both operand
  orders of the compare (`if (min > n) return;`, func_088585E8) and `x > 4`
  for `x >= 5` (func_08858BD8, func_0885981C). A 0/1 flag stored with
  `bnezl` and `sb zero` on the fall-through: zero case first, `if (!(x &
  1)) f = 0; else f = 1;`; an explicit `andi 0xFF` before `addiu -1`:
  `(u8)((p->f & 0xFF) - 1)` (func_08858238).
- A `sync` and nop run: one `__asm__ volatile("sync
 nop ...")` string
  (func_08859768); `asm { nop; nop }` also works (func_088597BC).
- C++ flag test keeping `andi 1; sltu; beqz`: `(bool)(x & 1) != 0`; `== 1`
  gives `li 1; bne` (func_088590B0).

- A table at a large offset of a global block, `addu` base/offset and the
  `bnel` compare both swapped in a speed loop, no sum order helping: the
  block as a struct with the table as an array member after a pad
  (`struct { char pad[0x3F28]; Pair e[24]; } *p`, `p->e[i].id`)
  (func_0885AED0, func_0885AF28); loaded field on the left of `==`
  (func_0885AF28).
- A down-counting loop `addiu t1, -1; bnez t1` in speed mode: `unsigned int`
  counter, `for (i = K; i != 0; i--, e++)`; an `s32` counter gives `bgtz`
  (func_0885B048). The order of comma-separated `for` steps sets the order
  of the `addiu`s (func_0885BD0C).
- A `u8` parameter tested with a plain `bnez`: `if (!mode)`; `mode == 0`
  adds an `andi` (func_0885B048). A `u8` result chosen by a byte compare,
  `beql` with the other value in its slot: `switch (x) { case 1: m = 2;
  break; default: m = 1; break; }` (func_0885B048).
- An `s16` parameter extended at entry but subtracted raw: keep it `s16`,
  `s16` locals, compound `-=` subtractions; `f -= x` also stores through
  the computed field pointer (func_0885BB00). Two guards sharing one
  `return 0` placed as `beql ... v0 = 0`: one `if (a == 0 || b == K)`
  (func_0885B9E0).
- A flag computed into the saved register of a later value: assign it to
  that later value's local as a ternary `v = (a == 1) ? 1 : 0;`
  (func_0885BE08). A search fallback computed into the argument register:
  store it back into the parameter (`arg0 += 8; ... arg0 = (char *)n;`)
  (func_08859C40). A pointer offset that must not fold:
  `(char *)((s32)(p + 0x1C) - 0x1C)` (func_0885AAEC).
- A guarded loop tested at the top and the bottom with invariants after the
  guard: early return, then `if (n != 0) do { ... } while (n != 0);` with
  `goto next` for skipped entries (func_0885B5B8). A struct copy from
  separate `D_` symbols: one extern per field, assigned in the original
  load order (func_0885A23C).

- A `beql x, K` to a shared `return 0`, then a plain `bne` + `nop` on the
  inner test where every `if` form gives `bnel`: a one-case `switch (x) {
  case K: if (c) return v; break; } return 0;`; a `return 0` inside the
  case gives `bnel` again (func_0885DB70, func_0885DBD0). A redundant `b`
  to the next instruction after the last branch, the 0 in a `bnel` slot:
  `if / else if / else` with a `return` in each branch (func_0885DF38).
- A clamp `slti v1; bnezl` with `+1` in its slot, then `b` with the cap:
  `if (n >= 4) n = 4; else n++;`; `n < 4 ? n + 1 : 4` gives `slti at;
  beqzl`. The counter one `u16` local reused in the result, else the
  final `andi`s swap (func_0885E348).
- A `seh` right after an `lbu` that `(s16)*p` folds away: `(s16)(u16)*p`,
  or `x = *p; x = (s16)x;`. Parameter saved registers in reverse order,
  deaf to declaration order and copies: the speed setting fixed it
  (func_0885C13C).
- An output pointer copied to its saved register before the `blez` guard:
  write `out[n].f = ...; n++;` and let the compiler step it (speed,
  func_0885C75C). A constant built in `v0` then copied: chained
  assignment `r = max = 99;` (func_0885C498).
- An `s8` call result kept in a saved register with `move v0, s0` at the
  return: the function returns `s32` (callers may declare `s8`), result
  in an `s32` local, `(s8)r * n` for the redundant `seb` before `mult`
  (func_0885D1D4). A missing `seh v0, v0` after a call added to an `s16`:
  the callee returns `s32`, cast `(s16)` at each use; `xor; sltiu; beqz`
  inside an `||`: `(s32)(a == b) == 0` (func_0885D300).
- A loop pointer from a record base stepping by 4, fields at +4/+6:
  `e = (Rec *)((char *)e + 4)`, `e->e[0].id`; `i = 0; e = r;` as separate
  statements; a sum used after a flags test computed into a local before
  the `if`; `beqzl` to 0/1 at the end: `if (r->f) return 1; return 0;`
  (func_0885DFA0, speed).

- Argument moves in the wrong order around a `mov.s $f12`: the float's
  place in the callee's parameter list sets the order of the moves (it
  goes to `$f12` wherever it is): `(s32, f32, s32, s32)` (func_0885FB54,
  func_0885FA0C), floats before the last integer (func_0885FF5C). A
  function that only sets `$f12`/`$f13` before its call passes its
  integer arguments on: declare and forward them (func_0885F8E8).
- A two-level table read (`tbl[kind]`, then a 40-byte record) with the
  row word and the `idx * 40` term in swapped registers: two statements,
  `rec = tbl[kind]; rec += idx;` (func_0885EAA4, func_0885F068,
  func_0885F194, func_0885EBC8); for a single expression, `(T *)((s32)
  tbl[k] + (s32)(i * K))` (func_0885EB34). `(u32)(k - 5) < 2` gives
  `addiu -5; sltiu 2` (func_0885EB34).
- `beqzl` on a raw `u8` register then `addiu -1`, no `andi`: `if (v) v--;`
  (func_0885EF20). `slti at` for a bound: `x > 3`, not `x >= 4`
  (func_0885E748, func_0885E878, func_0885EF20). `srl` of a `u16`
  parameter: `(u32)x >> 1` (func_0885F290, func_0885F354). A large
  constant added to a local pointer through `$at`: `p = (u8 *)(s32)(p + K)`
  (func_0885F290).
- A value shifted in the slot of the last `jal` and added after it:
  `v >>= 1; v += f(); return v;` (func_0885ECF4, func_0885EBC8). Two
  values tested with `beql 1 / bnel 5`: `if (t == 1 || t == 5) ... else
  switch ...` (func_0885ECF4).
- An unrolled clear loop (speed) building a large offset once in `$at`:
  the arrays are struct members at that offset, `p->arr[i]`; loops whose
  ranges join end to end are consecutive members (func_0885F434). An
  unrolled copy keeping the base offsets in the loads: index the raw base,
  `((f32 *)s)[i + 0x10] = ((f32 *)n)[i + 0x48]` (func_0885FA0C).
- A tree walk using the argument register: walk with the parameter and
  copy it into a `root` local; an inner loop tested at the top with
  `beqzl`: `if (s != 0) do { ... } while (s != 0);` (func_0885F848). An
  indexed struct array member (`p->ids[i]`) instead of a stepped pointer
  keeps the fixed offset in the load (func_0885EA08). `i = 0;` as its own
  statement before the pointer set-up of a speed loop guard
  (func_0885F7D4).

- A 64-bit flag test (`lw` at N+4, `andi 1`, `negu`, `subu`, `or`,
  `sltu`): C++ `(bool)(*(u64 *)(p + N) & 0x100000000LL) != 0`; `& 1LL` on
  N+4 swaps v0/v1 (func_08841AB4). An `sltu` flag on the first operand of
  an `||` with `bnel`: C++ `(bool)x != 0`; `== true` drops it
  (func_08841908).
- A global's address kept in a saved register (`lui`/`addiu` in the
  prologue) where ours folds `%lo(D+off)` at each use: `T *s = (T *)(s32)
  &D_x;` (func_088423E0, func_08842504, func_0884558C). A byte argument
  stored to a later stack argument slot in the wrong order: type that
  callee parameter `u8` (func_088423E0, func_08842504).
- `andi sX, zero, 0xFF` for a byte cleared with a sibling: `g = (u8)(b =
  0);`; three locals copied from one constant: `r = g = b = 0xFF;`
  (func_08842BE4). `seh` before `sra 1` on an `s16` parameter: `u = (s16)u
  >> 1;` (func_0884558C).
- A dead copy of the default block's first instruction after a `b`: a
  `switch` whose case group ends in `return;` and whose `default:` holds
  the rest as early returns (func_088428EC). One case-label group for all
  values of a result (`case A: case B: case C: return 1;`): the compiler
  gives the first its own `beql` (func_088446CC). `if (x != 0) return 1;
  return 0;` for `beqzl` with the 0 in the slot (func_08844578). Several
  tests leaving with `return 1`, only the first as `bnezl`: one `||` chain
  (func_088443EC).
- `sltu; xori 1; bnezl` to skip a loop body: `if ((c != 0) ^ 1) continue;`
  (func_088421C4). A float -> `u16` conversion repeated per sum: `a1 +=
  (u16)off;` on `u16` parameters (func_08842F70). A constant float product
  used in many places: write it at each use, not in a local; the float
  registers then land right (func_08843A7C).
- Guards that branch with `bnel`/`beql` to a shared epilogue, the return
  value in the slot: nested positive `if` blocks, each returning, the
  fallback after the block (func_08849BCC). Several final tests sharing one
  -1/0 block, the last one `bne` + `nop`: one `&&` chain, a void call
  between two tests written as a comma expression `a == 0 && (f(x), g(x)
  == 1)` (func_08849300). An early-out kept as `sltu` + `bnel`: `if
  ((s32)((x & 0x200) != 0) == 0)` (func_088487B8).
- `srl 5` on a byte index where ours gives `sra`: an `s32` local and
  `bits[(u32)(u8)i >> 5] |= 1 << (i % 32);` (func_08847B74). `a + (u16 >>
  1)` with `srl` and the `u16` loaded first: `h = (u32)g >> 1;` in its own
  statement into an `s32` local (func_08849CAC).
- Argument load order set by callee parameter types: a `u16` parameter
  puts the first argument's global load before an `lhu` table read
  (func_0884A72C); `s32` parameters for `u16` globals put the plain
  global first argument last (func_088487B8); a `char *` parameter
  without cast (func_088495AC).
- A missing `andi 0xFFFF` before `seh` on a computed argument:
  `(s16)(u16)(expr)`; one shared `seb` at a join for a 0/5 value passed as
  `s8`: keep the local `s32` and write nested `if`/`else` (func_088474DC).
  An `s8` local tested against zero: `if (x)` gives a plain `beqz`, `if (x
  != 0)` adds `seb` and `beqzl` (func_088495AC).
- C++ `static inline bool` helpers: `is_own(o) != 0` for `xor; sltiu;
  beqzl`, `used(x) == 0` inside an `||` for `lbu; sltu; bnez`; `if (c >=
  K)` rather than `if (c < K)` for `slti v1` with the value kept; a
  variable holding the scaled offset `c = b * 4;` then `(char *)c + (s32)g
  + off` for swapped saved registers (func_088476F4).
- A colour word stored to the stack and read back byte by byte: a `u32`
  local read as `((u8 *)&c)[0..2]` (func_088471D8). Loop and register order
  of two zero-initialised locals follows the order of the assignments
  (func_0884706C).
- A float -> unsigned conversion (`0x4F000000` compare, `sub.s`, `or
  0x8000`): an explicit `(u32)` cast of the float expression (func_0884AC20,
  func_0884AAD0, func_0884AB78). An `sltu` kept before a plain `beqz` on a
  byte flag: `if ((s32)(x != 0) != 0)` (func_0884C89C). `andi; sltu; xori
  1; bnez` for a bit-clear loop test: `while (((x & K) != 0) ^ 1)`
  (func_0884D878).
- Retry loops not rotated (test at the top, `b` back): `while (1) { if
  (f() >= 0) break; delay(); }` (func_0884D878). A comparison emitted twice,
  `bnel` then a `bne` that is never taken: `if (r != x) goto fail;` then `if
  (r == x) { ... }` (func_0884DE3C).
- Dead copies of each case's first instruction after `beql` into a switch:
  nest the later switch and the code after it inside the case group of the
  earlier guard switch, ending the cases with `break;` (func_0884A958).
- `c.eq.s d, zero; bc1tl; mov.s d, one`: `d = d ? d : 1.0f;` (func_0884B284).
  A stack temporary 4 bytes too high: make it an 8-byte struct; the source
  position of a struct copy sets its float register (func_0884B284).
  Stack offsets too low for a buffer a callee reads whole: declare it larger
  than used (`cmd[16]` for 12 words) (func_0884C128).
- A global byte table reloaded after stores through a kept address: take a
  pointer local `np = &D_x[i];` and read `*np` at each use; a product by
  `-1.0f` in the wrong float register: `t = sum; d = t; d *= -1.0f;`
  (func_0884CBD8). A ratio converted before the divisor load: `t =
  ++e->timer; t /= e->duration;`, a `u8` difference assigned between the
  two statements (func_0884D2F8).
- A global reloaded with `lui`/`lw` for one argument while a copy sits in a
  saved register: read it there as `*(char * volatile *)&D_x`
  (func_0884DBB8). `x / K - 1` subtracted from a field: fold the `- 1` into
  the local (`n = x / K - 1; f -= n;`) (func_0884E478).
- Two values computed in a call's arguments and kept for later, in swapped
  saved registers whatever the declaration order: pass plain expressions to
  the call, then assign the locals from the same expressions after it, in
  the order of the registers wanted (common subexpressions; func_08843A7C
  99.12 % -> 100 %).
- A `trunc.w.s` placed after two unsigned conversions while the `add.s` it
  reads stays early: `f32 w = expr;`, then the `u32` locals, then `s32 i =
  w;` under `#pragma opt_propagation off` (func_0884424C 82.91 % -> 100 %).
- One prologue `sw sN` scheduled before the first `lui` of a global in
  ours, after it in the original (`lui; sw s0; lhu`): declare that global
  (or its group) `const`; declaring every global `const` adds a saved
  register (func_08845C68 98.61 % -> 100 %).
- A value loaded once and used in two blocks, in the wrong temporary: drop
  its local and write the load at each use (still loaded once). Saved
  registers swapped between two loops: a separate counter for the second
  loop (func_088415D0, with `opt_rebuildconditionals off`, 89.85 % -> 100 %).
- Saved registers rotated in a large call-heavy function: pass call results
  inline instead of through a local that lives across the next call, drop
  no-op casts on arguments, reuse locals across cases, block-scoped
  declarations, then a scripted search (func_08849D7C 98.68 % -> 99.21 %).
- A near-identical matched sibling is the best draft: func_088307BC and
  func_08830850 (left in earlier sessions with a scheduling gap and two
  swapped prologue copies) matched at once in the style of func_08830728
  (`E36` struct-array casts for 36-byte entries, the global reloaded at
  each use).
- `negu; sll 1; addu` with the operands swapped: subtract the value twice,
  `w - k - k` (`w - k * 2` gives `sll; subu`) (func_08832228).
- `beql x, A` with the body in its slot, then `bne x, B` with the body
  copied: one `||` condition, `if (c == A || c == B) ... else if (c == C)`
  (func_0883095C). A ternary whose constants come out swapped: write the
  `== 0` compare, `x == 0 ? K1 : K2` (func_0883029C).
- A compare computed in the prologue into a saved register and passed to a
  later call: a local initialised at its declaration under `#pragma
  opt_propagation off` (func_08831338). A stack record passed by address 8
  bytes too high: make it 12 bytes (func_08831338, func_08831418).
- A `u16` parameter masked once before the first `jal` and again later:
  copy it into an `s32` local as the first statement, `(u16)x` at the uses
  that re-mask (func_08831CB0). A call result masked `andi 0xFFFF` at each
  use: an `s32` local and `(u16)r & K` per use (func_088303E8).
- A byte local spilled to the stack (`sb`, then `lb; addu a1`) with every
  saved register in use: speed mode, a `u8` local passed to an `s8`
  parameter (func_08830078). `x -= 15;` on an `s16` local avoids the `seh`
  of `x = x - 15;` (func_08830078).
- A field read several times in one block where ours shares one load: a
  local for the first use, `*(volatile s32 *)&field` for a read that must
  stay separate; a copy pointer kept as `addiu v0, sp, K; addiu t3, v0, 4`:
  `src = &hdr->n1; src++;` as two statements (func_088314A0).
- A field loaded once before a branch but reloaded after a call in the
  other branch: read it there through a bit-field member of a union
  (func_0883185C). `bne` with the else value in its slot: `n = 0x100; if
  (fmt == 4) n = 0x10;` (func_0883185C, func_088314A0).
- A doubly negated bit test kept as `andi; sltu; xori 1; sltiu 1`, two of
  them joined by `bnez` before one `beql` that picks a constant: materialise
  the flag in an `s32` local with an unsigned compare, `c = (u32)(((x & K)
  != 0) ^ 1) < 1; if (!c) c = (u32)(((x & L) != 0) ^ 1) < 1; idx = c ? 2 :
  1;`. `!(...)` folds back to `sltu; xori`, `== 0` adds an `xor`, a direct
  `||` becomes branches (func_08832884).
- A loop whose accumulator add sits between the counter test and the branch
  (`lh; i++; slti; addu; pointer steps; bnez` with `seh` in the slot): put
  the accumulation in the `for` step, and order the step statements with the
  counter last and the accumulator just before it, `ids++, m++, y += box.h,
  i++` (func_08838E30; `i++, y += box.h` in func_08838F58). The loop form
  (for / do / while) does not matter, the step order does.
- A loop that steps a pointer into a stack buffer, bottom-tested with no
  guard: `i = 0; p = buf; do { ...; i++; p++; } while (i < 6);` (a `for`
  rotates it; `buf[i]` recomputes `sp + i` and shrinks the frame). Six `sb
  zero` in descending order: six explicit statements, `buf[5] = 0;` first
  (func_08838894).
- A shared subexpression written as a local or inline changes where its
  saved-register computation is scheduled against the argument loads of the
  two calls that use it: try both forms per block (func_08832F20: inline in
  the first block, locals assigned first in the second).
- The bytes of a 32-bit argument reloaded from the caller's argument slot
  before every call: a `u32` parameter read as `((u8 *)&c)[n]` at each use (a
  by-value structure of four bytes gets cached in saved registers)
  (func_08832940).
- A call result converted and used in one expression, scheduled too early:
  give it its own `s16` local as a separate statement, `w = f(...); x = box.x
  + K - (w * 7 >> 1);` (func_08839824).
- A byte argument loaded before the `jal` instead of in its slot: declare
  that callee parameter `s32` rather than `u8` (func_08839688, as for `u16`).
- A record copied to the stack in the middle of a function with unrolled
  `lwc1` / `swc1` (speed mode), from data that sits among the unit's strings:
  an initialised local declared in a nested block opened at that point,
  `{ Box box = { ... }; Layout lay; ... }`; declared at function level the
  copy moves to the prologue. The record is the unit's own `.data`
  (func_088378A8). A whole-structure assignment from a global whose field
  addresses splat named separately scores 99 % in `try_unit.py` and 100 % in
  the report (func_08838640).
- A call result compared with a value in a saved register, operands
  swapped (`beql s3, v0` for `beql v0, s3`): assign the result to a local
  in its own statement, `r = f(); if (r == x) break;`; swapping the `==`
  operands or assigning inside the condition does not move it
  (func_0884F0D8, func_0884F244, func_0884EDC8). Same form for `bgezl sX`
  with the move in its slot (func_0884F2E0).
- A virtual call through `$t9` (`lw t9, 0(sX); lw t9, K(t9); jalr t9`):
  only a C++ virtual method gives it, a C function pointer uses `$v0`
  (func_0884EDC8, func_0884EF0C). In C++, `if (u8param)` avoids an extra
  `addu v0, v0, zero` that `if (u8param != 0)` gives (func_0884EF0C).
- One saved register per byte offset of a stepped buffer (`addiu s3, a1,
  1` / `s2, a1, 2` / `s1, a1, 3`): one pointer local per offset, the
  counter declared after them (func_0884EA1C, speed). A speed loop that
  steps the plain base and keeps the table offset in the load: index an
  array member of a struct placed after a pad, not `(T *)(p + K)`
  (func_0884ED24).
- A table word loaded before the branches of a signed `% 32`: read it
  through a `volatile` pointer into a local (func_0884FE80). `andi 0xFFFF;
  ext v1, 5, 16` for a word index: `(u16)((u32)idx >> 5)` (func_0884FE10).
- Two `bnel` on the same flag (`li v0, 1` in the first slot) and an empty
  `b` slot after the `return 1` block: `if (X != 0 || (X == 0 && f() ==
  0)) return 1; return 0;` (func_0884E7FC).
- The counter's `addu v0, zero, zero` before a loop guard `beq`, the
  pointer's `addiu %lo` in its slot: `i = 0;` as its own statement before
  a `for` that sets the pointer (func_0884FDC4, speed). A retry loop whose
  `b` back edge carries the field reload: load it before the loop and
  again as the last statement of the body (func_0884F190).
- A switch whose other values return what the shared return returns: no
  `default:` at all (`default: return x;` adds `b` / `nop` blocks)
  (func_0883A8A4). In an if-chain where `x == A || x == B` with consecutive
  constants becomes a range test (`addiu; sltiu 2`) but the original has
  `beql x, A` into the next body: `else if (x == A) { goto L; } else if (x
  == B) { L: body; }` (func_08839B30).
- `bgtzl` where ours has `blezl`, the `> 0` block after the other one:
  `if (x <= 0) { other } else { then }` (func_0883B190).
- A halfword field loaded after a `mult` where the original loads it after
  a global and before the product's use: type the field `s16`, cast `(u16)`
  at the use (`lhu` and the order both right) (func_0883D290).
- A guard pair where the second `return 0` is `addu v0, zero, zero; b end;
  nop` with the slot left empty: one `||` guard, `if (p == 0 || f() == -1)
  return 0;` (func_0883D40C, func_0883D4F0; func_0883BB10 with a shared
  `ok = 0` block).
- Prologue saves interleaved with the loads of a group of globals passed to
  one call: declare ALL of them `const` (half of them is not enough); the
  callee parameter types then set the argument load order (func_0883B870).
- An invariant `x + K` hoisted into a saved register but masked inside the
  loop: a `u32` local, `xx = xb + K; xx &= 0xFFFF;` in the loop body; when
  the masked value must survive a call, copy it to a `u16` and make the call
  its own statement (func_0883D6D0).
- A record copied member by member in a given load/store order: the order
  follows the struct grouping (`u8 x[3]` for three `lbu` then three `sb`,
  separate members for a delayed last store, plain `f32` members rather than
  a sub-struct); in C++ `a = *p;` copies by members where `Rec a = *p;`
  copies by words (func_0883BB10). A 6-byte tail copied as `lh`x3 / `sh`x3:
  that tail as a sub-structure, the rest field by field (func_0883A07C).
- Saved registers of parameters and locals permuted in a call-heavy function
  with two loops, no declaration order helping in size mode: speed mode,
  then the declaration-order search (func_0883AE3C: 5040 orders, several at
  100 % only in speed mode).
- A parameter copied to a saved register, used once, and that register
  later holds an `s16` coordinate (`lh`, `seh` after each add): the
  coordinate IS the reused `s32` parameter, `b = box.y; ... b = (s16)(b +
  box.h);` (func_0883A758).
- Dead copies of branch-likely slot instructions left after each `b`,
  unfilled `b` slots and plain `beqz` + `nop` all over a function, where ours
  removes them: the original has a nested `if` inside a block ending in
  `return;` that ours splits into early returns. Join consecutive early
  returns into one guard, `if (f(a) == 0 && f(b) == 0 && f(c) == 0) { ... }
  return;` (func_0883F270: 95.5 -> 100 %), `if (x <= 2 || x == 7) return;`
  (func_0883E4B8). No pragma, flag or compiler build gives it.
- A final call result tested with plain `beqz` + `nop`, then `b end` with
  `v0 = 1` in its slot: one `&&` chain, `if (f() == 1 && g() != 0) return 1;
  return 0;` (func_0883F988).
- A byte compared first with 1, then with 0 (`beql`, then `beqzl`): `switch
  (x) { case 0: ...; break; case 1: ...; break; }` with no `default`
  (reverse comparison order) (func_0883FAD4).
- A compare result kept in `v0` (`slt v0; bnel v0`) rather than `at`:
  `if ((s32)(f() < x) == 0) { else-part } else { then-part }`
  (func_0883E928). A value loaded into an argument register before a call
  whose slot stays empty: the callee takes it as an argument (read its asm)
  (func_0883E928).
- A clamp `slti at; beqzl` with the constant in the slot: `n = x < K ? x :
  K;` (`if (x > K - 1) x = K;` gives `bnez` + `nop`). A local struct store
  scheduled before a parameter update in the same branch: assign the result
  to a new local, not to the parameter (func_0883DF88).
- A record read member by member from a global whose fields splat named
  separately (`D_..F4`, `D_..F6`...): an extern `const` structure copied
  whole in C++, `Frame f = D_X;`; the name-only differences resolve in the
  report (func_0883E4B8).
- An early-return block inside a loop joined through an extra `negu; b end;
  nop` block where the original has `b end` with the computation in its
  slot: one result local set by `if / else` in the loop and in the tail,
  `goto end;`, one `end: return r;` (func_08821828).
- `k == 6 || k == 5` folded to a range test (`addiu -5; sltiu 2`) where the
  original has two `beq`: `switch (k) { case 5: case 6: ... }`; the case
  bodies follow source order while the compares are reversed
  (func_08820DBC). `return r == 0 ? B : A;` for `bnezl` with A in the slot.
- An `s8` local passed with a plain `addu aN, sX, zero` where ours adds
  `seb`: the callee parameter is `s8` (func_08822594); a spilled `s8` loaded
  `lb v0` then moved where ours loads `lb a1`: the callee parameter is
  `s32` (func_08821D48, func_0882148C).
- A byte parameter masked again in each block with the masks in the wrong
  argument registers: `s32` parameter written `(flag & 0xFF)` at each use,
  not `(u8)flag` (func_08821D48). Several locals set to one constant: one
  assignment chain `a = b = c = 10;`; its order with the declaration order
  sets which locals are spilled (func_08821D48).
- A field address computed into a saved register in a delay slot and
  stored through `0(sX)` later: a pointer local to that field (func_08821CA8).
- Stepped pointers that start at the bare arguments with the full offsets in
  the loads: step raw `char *` copies by `sizeof(Rec)` and cast `(Rec *)(s +
  off)` in the body (func_08821924). `addu` base/index swapped on an element
  address that no sum form fixes: type the parameter as a wrapper struct
  (pad, array member) and take `&p->ent[idx]` once (func_08821ADC).
- Loop set-up instructions out of order (the scale of a two-level table
  index scheduled late): split the pointer, `p = tbl[k]; p += idx * K;`,
  then search the ASSIGNMENT order of the set-up statements, `i = 7;` out of
  the `for` header (func_08821080: 95.0 -> 100 %). A float constant built
  with `lui`/`ori` instead of read from `@N` data: speed mode (func_08821080).
- `s16` increments: `yy += 16;` (no extra `seh`), and an `s16` reset from an
  `s32` (`yy = top;`) to keep the `seh` in the loop (func_0882148C).
- Batch 40 (0x08822C58-0x0882693C). Two halfword out-parameters passed by
  address at the wrong stack slots (2 or 4 bytes off), no declaration order
  helping: one local `u16 ab[2]` or `struct { u16 w; u16 h; }`, pass the
  member addresses (func_088262B0, func_088264F4). A sub-record address kept
  in a saved register across a call (`addiu sX, base, K` in the `jal` slot)
  that every form folds into the load: `#pragma opt_propagation off`, the
  pointer assigned in the block that uses it (func_0882619C). Loop
  invariants spilled to the stack before a loop (`(s16)x`, `x + 14`, `(s8)c`)
  are the compiler's: write the expressions in the calls, no locals
  (func_08822C58). Saved registers of a counter and a strength-reduced index
  swapped in the second of two grid loops: the two nests share the column
  counter and coordinate locals (func_0882545C; sharing beat one counter per
  loop there). `D_089CC438 + 0x6AF14` built with `ori`: declare the global
  `char *` so that it splits as `lui 0x7` / `-0x50EC` (func_08823B58,
  func_088239FC). A byte tested then used with an extra `andi 0xFF`: read the
  field twice, no `u8` local (func_08823174). A store of zero pulled into a
  `b` slot (the original has a dead copy of the likely slot there): `u16`
  store instead of `s16` (func_08825D38). A value minus a constant
  recomputed at each use: its own new `s32` local (func_08825ADC). Ring
  index `(start + i) % N` with `start` loaded after the guard: the whole
  expression inside the loop, no second counter (func_08823AE4). `bgez`
  with the zero return inline: wrap the body, `if (x >= 0) { ... } return
  0;` (func_08823960). `beq` + `b` to a shared `return 0` after a
  `bnezl`: `if (!(A != 0) && B != 1) return 0; return 1;` (func_088239FC).
  If/else arms inverted (`beqzl` for `bnel`): flip the test and swap the
  arms; `cur > 1` for `slti at` (func_0882675C). A two-halfword record copied
  out with `lh`/`lh`, back by members, then one field reloaded: C++ `Pair
  tmp = *src; *dst = tmp; f(tmp.a);` (func_08823E18).
- Batch 41 (0x088269C0-0x088292AC). A clamped field written and read again
  through `0(reg)` with `beqz` for `beqzl`: a real `s16` member of a struct,
  `p->f62E`, not a raw offset (func_088277DC). `mult` operands swapped with
  a call result: the result in its own local as a separate statement
  (func_08827AD4). `sll 3` where the original has `addu v0, a0, a0; sll 2`:
  `k = k + k;` as its own statement (func_088290A4). A constant inner count
  in the wrong register, no declaration order helping: `for (j = 5; j > 0;
  j--)` or `j = 5;` right before the `do` (func_0882774C). Chained stores
  run from the last name to the first: write the chain in reverse field
  order (func_08827194). `lh`/`lh`/`lh` then three `sh`: one three-member
  struct copy (func_08826FCC). An unrolled clear loop counting down by 8:
  stepped pointer, `for (k = N; k > 0; k--)` (func_08826FCC). A `u8` flag as
  a ternary gives `beqzl` + `andi`: `if (x == 0) f = 1; else f = 2;`
  (func_08826EF4). `y += step;` before the exit test for an `addu` in a plain
  `beqz` slot (func_08827918). A `beql` with the value in its slot then a
  plain `beq` to the same body: a group of case labels (func_0882822C); a
  `bool` return keeps a compared 1 apart from the returned 1 (C++). Only one
  branch into a shared `return 1` becomes branch-likely: route the other
  cases through it too (`if (f() >= 0) break; return 0;`, func_088269C0). An
  `lh` value kept for an `s32` argument with an extra `seh`: `s32` local
  (func_08828784). A returned `s8` with an extra `seb`: `s8` return type
  (func_088291B4). Callers passing a register the callee never reads
  (func_0882747C, func_088275B0): the callee definition takes the extra
  unused argument (same code), the callers need it.
- Batch 42 (0x088292AC-0x0882B94C). Global loads kept below byte stores to a
  struct: declare the globals read in that block `const`, only those
  (func_0882A43C, func_0882A660). Two global loads and a field load out of
  order, no order or type helping: read the first global and the field
  through `volatile` into locals (func_0882A28C). A shift or packed colour
  repeated at several uses: the full expression at each use, no local
  (func_0882A43C, func_0882B1CC). Stack slots of uninitialised 4-byte
  structure locals loaded in the prologue: they are structure locals not set
  on every path (func_088292AC). A call with no visible argument set-up: the
  register still holds a constant from an earlier store (func_08829F04). A
  stored word that looks like an earlier value: check for a `lui` reloading
  the register (func_0882AC18). A `u16` local re-masked at a packed store:
  explicit `& 0xFFFF` at the store (func_0882B624). A store order searched by
  a hill-climb over statement swaps (func_0882AF70). A byte parameter of a
  callee loaded after a global: the parameter `s32` (func_0882AD70). An
  if/else ending in `return 1` / `return 0`: only the `return 0` paths in
  the arms, one shared `return 1` (func_08829928). A call result compared
  with a masked halfword: `r = f();` alone, `if (r != (u16)id)`
  (func_08829A48). Draw-loop step `i++, y += h` with the counter first
  (func_08829B58), the reverse of batch 36.
- Batch 43 (0x0882B94C-0x0882FB38). A neighbour of the same shape: start
  from its matched file, inline helper and pragma included (func_0882B94C,
  func_0882BBE8, func_0882BE60). Table bytes loaded once before an if/else
  between two calls: read them into locals before the `if` (func_0882E0D0).
  Sums kept in saved registers across a run of calls: `s32` locals assigned
  where the original first computes them, the reloaded field written again
  at each use (func_0882DCB0). A constant count propagated into an inline
  helper test lands in the wrong register: its store first among the
  stores (func_0882CF58, func_0882DAC0, func_0882CC9C). A packed colour
  scheduled too early: chained into its first use, `pkt.w[0] = col = ...`
  (func_0882D8DC). Operands of an `or` swapped: the other operand in its own
  `u32` local defined before the colour (func_0882BE60). A flag `p != 0` in
  the wrong register: computed later, after the plain copies
  (func_0882FA24). A byte parameter masked into another register: `s32`
  parameter, `arg1 = (u8)arg1;` alone (func_0882E53C). A stack halfword
  parameter used as `lh` and `lhu`: `u16` parameter, `(s16)` at the signed
  uses (func_0882E2C0). A range test recomputed in a speed-mode loop:
  `#pragma opt_loop_invariants off` (func_0882F580). Several packet types
  through one inline: one struct and one inline per type (func_0882E86C).
  Colour bytes that splat names one by one (`D_0893AA5C`, `D_0893AA5D`,
  `D_0893AA5E`): three `u8` externs.
- Region 0x08820000, last three (0x0882FB38-0x08830078). A `u16` parameter
  masked in place with no visible use: it is an extra variadic argument,
  read the format string (`"%d/%d"`, func_0882FB38); `#pragma
  opt_dead_assignments off` jumping up is a probe for such a hidden use. A
  global loaded as first argument too early: the call inside the
  expression, not in a local (func_0882FB38). Parameter saved registers
  rotated with declaration order of no effect: move the statements that
  use them (func_0882FE34).
- Batch 44 (0x08811C84-0x08814D84, lower edge of the Metrowerks region). A
  call result tested as a flag with an `andi 0xFF`: callee returns `s32`,
  test `(u8)f()` (func_08812BD0). A guarded call with a `nop` in its `jal`
  slot and a `beql` to the epilogue: `switch (x) { case K: break; default:
  f(); }` (func_08813CF8). A returned 1 kept apart from a compared 1: C++
  `bool` return (func_08813498) or `#pragma opt_common_subs off` with a
  result local (func_088134C0). A field reloaded in every case arm before a
  shared use: assign it to a local inside each case (func_0881263C). An
  `andi 0xFF` after `lbu`: `s32` local, `(u8)x & 2` at the test
  (func_08812264). A pointer to a struct field in a saved register: a
  separate pointer local, `p[1] = ...` (func_08812144). Dead copies of
  branch-likely slots kept after every `b`: one guard joined with `||`
  before a `return;` (func_08813594, as func_0883F270). Pointer advance
  `base + K + idx * S` with the constant in its own register: integer sum
  `(T *)((s32)p->arr + idx * S)` (func_08814A14). Count-down loop unrolled
  by 8 in speed mode: `for (i = n; i > 0; i--)` with its own counter
  (func_08814A14). A float field set by `lui`/`ori` into an integer
  register: an `s32` store of the bit pattern (func_08814BE0).
- Batch 45 (0x08814D84-0x08818950). `bltzl x` to the next instruction with
  the replacement in its slot: `x = (x >= 0) ? x : K;`; a base offset kept
  as its own `addiu`: pointer local assigned first, `p = arg0 + 0xB0;`
  (func_08815004). A `beql x, K` with the equal value in the slot:
  `(x != K) ? A : B` (func_08818028). A byte loaded twice (loop test and
  call argument): speed setting + `#pragma opt_common_subs off`, or
  `volatile` reads (func_088169FC); a string pointer reloaded for guard,
  body and bottom test: `volatile` pointer parameter (func_08816818). Loop
  tested at the top on a count and at the bottom on a call result: `if (c
  != 0) do { if (n <= 0) break; ... } while (c != 0);` (func_08816730,
  func_08816638). `*--q = v;` scheduled too early: `q--; *q = v;`
  (func_08816508). `or` operands swapped on `((c & m) << 6) | b`: `c &= m;
  c = (c << 6) | b;` (func_08816460). Range chains sharing one return
  block: inclusive bounds, `c <= 0x7F || (c >= 0xA0 && c <= 0xDF) || c >=
  0xFD` (func_0881629C); `0xF4 < c` for the `sltiu at` order
  (func_08816460). Float side tests with permuted registers: difference
  locals reassigned before each test in one order (func_08815260). `k = k
  + k;` before the store it must precede (func_08816BE4). A byte kept in
  two saved registers: `s32` local, a `u8` copy for the tests, `(n &
  0xFF)` at the other use (func_08818264). `beql x, 2` then `b`: one-case
  `switch` with `default:`; guardless bottom-tested search loop: `do {
  ... } while (i < N);` (func_088172D8). A call result masked into `a2`
  and only tested after: an extra argument of the next call
  (func_08816638).
- Batch 46 (0x08818F74-0x0881C398). `if (A || B) v = K1; else if (C || D)
  v = K2;` for `beql x, K, end` with the body in the slot on the first term
  and a copied body + `b` on the second (func_0881908C). A field tested then
  read again (`lhu` twice) in a copy loop: `volatile` on the test only;
  count-down loop ending in `bnez`: `u32` counter (func_088197A0). `sltiu`
  on a `u16` field: `unsigned int` local; `slti at` vs `v0` set per bound
  (`n >= 9`, `v > 11999`) (func_0881A9D8). A `u8` 0/1 flag: if/else on the
  negated condition; `v <= r->hi ? A : B` keeps the original `bnezl`
  (func_0881A7A4). Raw parameter register in a sum after a masked compare:
  `u8` parameter, not `s32` with casts; flags `s32` with `(u16)` at each
  use (func_0881C098). Only the tested table `const` for a prologue `sw`
  after its load (func_08819CF8); only the table whose load must cross the
  `sw zero, 0(sp)` `const` (func_0881B408). Two call results kept on the
  stack: a local array `char *ss[2]` (func_0881A30C). `mult` operands
  swapped on a table element times a call result: the table read inline,
  no pointer local (func_0881AAA4). Inner search loop with every register
  shifted after an `andi` copy: `static inline` helper with an `s32` byte
  parameter cast at the compare (func_0881B7F0). A masked loop index left
  in `a2` before a call that sets `a0`/`a1`: the callee takes it as a third
  argument (func_0881B5F8). `seh` copies of an s16 pair after a call: a
  local `struct { s16 x, y; }` (func_08819128, NonMatching). A caller
  passing no second argument to func_08852F58: its definition takes one
  (the second was a pass-through of whatever `a1` held).
- Batch 47 (0x0881C398-0x08820B74). A local reset in a `jal` slot: `x = 0;`
  before the call, as the first statement of its block (func_0881E92C,
  func_0881CB2C); a flag set in the slot: assign it before the call
  (func_0881C5D8). A `u16` copy of an `s32` parameter whose mask must not
  be shared with later `(u16)pad & K` tests: initialise it at its
  declaration after a call (func_0881DB5C). A switch on `-1..5` needs its
  empty cases listed (`case -1: case 4: break;`) to get a jump table
  (func_0881DB5C). One shared assignment for two failing tests, `if (e == 0
  || e[0xBF] == 5) ok = 0; else ok = f() == 0;`, for a `b` with an empty
  slot; outer switch without `default:`; an 8-byte record copy as one
  assignment of `struct { struct { s8 c[6]; } n; struct { u8 a, b; } m; }`;
  a two-element swap: read the first element's fields before taking the
  second's address (func_0881CB2C). `x--;` rather than `x = x - 1;` for a
  stray `seh` on an `s16` local (func_0881C68C). `u8 *` for `lbu` on a
  pointer parameter (func_0881EB60). A large function where declaration
  order changes nothing: `#pragma opt_propagation off` (func_0881EE84,
  +5 points, NonMatching).
- Retry of 2026-11-27 (7 of 15 NonMatching units above 98 % matched). An
  unfilled `jal` slot inside a guarded block: the guard as a `switch` with
  the excluded values in an empty `case A: case B: break;` group and the
  body in `default:` (func_088A812C). A field address `p + K` in the wrong
  register and its store out of order: a pointer local initialised at its
  declaration at the top, used for the member stores too (`q[i]`)
  (func_08814BE0). An `s8` value kept in its parameter register with `seb`
  only at the tests: `s32` parameter reused as the variable, `(s8)` at each
  use with a `seb`, `s32` return when the return has none (func_088291B4).
  Saved registers swapped in older units: rerun a hill-climb over
  declarations under the current flags, one adjacent swap was enough
  (func_088DC1F0). An `s16` position copied after a call swapped with an
  index: plain `s16` locals and explicit `s32` copies right after the call,
  in register order (func_08819128). Index and count swapped with no
  declaration order helping: reuse the index local for an earlier test of
  the parameter, speed setting, guarded `do/while` written as a `for`
  (func_088D7AD8). A global-address pointer local swapped with a later
  local: the first use after the branch as the cast `(T *)(s32)&D_x`, and
  the branch that sets the other local as a `switch` (func_088EF9C8).
  Found while failing: the saved register a value gets follows the
  instruction count before scheduling, not declaration order (toy tests on
  func_08825148); with `#pragma schedule off` the loop head of
  func_088FD170 gets the original registers (a common-subexpression pass
  runs after colouring).
- Batch 48 (2026-11-27, 17 of 17, 0x08855428-0x088CBBAC). Menu state
  switches: several arms jumping to one shared `r = 0` block (`beqz` + `nop`,
  no `beqzl` slot copies): the choice code as a `static inline` helper with
  `return 2;` / `return 1;` inside and one final `return 0;`
  (func_088BF26C, func_088BEEC0, func_088BBE58, func_088BE550, ...); a case
  ending with `b` to the shared tail: `break;`, not `return r;`; a result
  constant in a `jal` slot: assign it before the call; `ret = 0;` as the
  first statement when it sits in the first `jal` slot (func_088BE550). A
  value left in `a1` and only compared: the last callee takes it as a second
  argument (func_088BFE54). Slot records 0x6B100 apart: `(s32)(i * K) +
  (char *)p + off` when `(char *)(i * K) + (s32)p` leaves the `addu`
  operands swapped, or a slot struct of that size (func_088C2168,
  func_088BC7F0). A `u8` inline predicate tested `== 0` adds `andi 0xFF`:
  `!pred(...)`. A `for` whose bound is a call under the speed setting
  hoists `self + K` into an extra saved register: `#pragma
  opt_loop_invariants off` (func_088C7914, func_088C7CDC). `/ 100` as a
  `div` where the original multiplies: speed setting (func_08874C58). Two
  word ORs (`lw` x4, `or`, `sw`, `or`, `sw`): one `u64` compound `|=`
  (func_08874C58).

- Retry of the leftovers (2026-11-27, 12 of 19 to 100 %). A bit test
  `(w & (1 << n)) != 0` with the `and` operands swapped: the loaded word or
  byte in its own local first (func_08850618, func_08852F1C); a byte at
  `base + K + idx` with swapped `addu` operands: `((u8 *)(base + K))[idx]`
  (func_08852F1C). A loop value rotating through the wrong registers when
  no declaration order helps: reuse an earlier local whose live range is
  over (func_0886C59C), or pass the counter to a later callee whose
  definition takes it (func_0885ACA8). A field load hoisted to the top of
  a block: `#pragma opt_propagation off`, the field in a local assigned
  where it is used (func_0886BEA4). A pointer chosen by a flag with the
  index in the wrong argument register: plain if/else under `#pragma
  opt_rebuildconditionals off` and the index computation in a `static
  inline` helper with early returns (func_088727CC). A stack argument store
  (`sw zero, 0(sp)`) scheduled before table loads: the table `const`, read
  through pointers inside the loop, plus a non-const view of the same
  memory for later reloads (func_088C05FC). Speed mode that unrolls clear
  or copy loops: add `#pragma opt_unroll_loops off` (func_08855F98,
  func_088B8A58). Two halfword globals copied to the stack as one pair: a
  whole `{u16, u16}` struct copy, with the pair sized in symbol_addrs.txt
  (func_088B8A58). A word table copied to the stack with `lwc1`/`swc1`
  from symbols splat names one by one: a union of `extern float` members
  assigned one by one before the loop (func_08855F98). An `s16` parameter
  re-extended after a loop: an `s32` parameter with `(s16)` at each use
  (func_0885B3A0, NonMatching). Narrow parameters (`u16`, `s16`, `u8`) take
  the lowest saved registers before pointers and ints; a `void *` parameter
  copied into a `char *` local moves that one ahead (func_0881EE84).
- C++ runtime, first batch (2026-11-27, 0x0890BE54-0x0890CD14, 15 linked).
  A function that only calls a function pointer and keeps its frame
  (`jalr`, no tail `jr`): C++, which makes no tail call (func_0890C200,
  func_0890C224, func_0890C248). An `or` chain with swapped operands: one
  accumulator, `x = A; x |= B; x |= C;` (`__ptmf_cmpr`, `__ptmf_test`).
  Bytes loaded in the `bnel` slots of a chain of length tests: each byte
  in a `u32` local just before its test (func_0890C3F4, func_0890C490). A
  stack structure copy whose loads and stores interleave: make it a member
  of the structure whose address is passed to a callee (func_0890CBC0,
  func_0890C6C8). A stack slot or frame 4 to 16 bytes short: the structure
  passed by address is larger than the callee uses, or a case's first
  output is a two-word array (func_0890C564, func_0890CD14). `p + 4` kept
  in a saved register: `#pragma opt_propagation off` (func_0890CD14).
  Not linked: a C++ class with an inline destructor matches the function
  but also emits an out-of-line destructor calling `operator delete`, so
  the unit does not link (func_0890BEC0); functions using `throw()` or
  `try`/`catch` (func_0890BFA4, func_0890C9A0) need the runtime names
  `__unexpected`, `__end__catch`, `__throw` and their exception tables.

## Open symptoms

- One inlined copy of a helper coloured differently from its identical
  copies (the last `submitL` of func_0882E86C, 99.66 %); func_088F4518
  shows the compiler does it, no source lever found.
- `$ra` saved at 0x0 (or under the other saved registers) and a call block
  after `jr $ra` reached by `j`: not mwccpsp code, leave it in assembly
  (0x088972A0-0x08897E1C, notes/SPLITS.md).
- Scheduling: a load placed before / after an index computation (func_088307BC).
- One block of a large speed function: a byte load in `a3` instead of `a2`
  and a constant argument set before a `subu` instead of in the `jal` slot
  (func_08849D7C, 99.21 %, case 0).
- A test against the constant 1 (`addiu v1, zero, 1` after the `andi`,
  `bnel a0, v1`): ours branches with `beqzl` for every `== 1` form
  (func_088D168C, 98.79 %).
- `t->tbl[t->idx]` address computed in $v0 where the original uses the
  register of the result (a1), and the following clear() counter in a2
  instead of v0 (func_088A2498, 99.87 %).
