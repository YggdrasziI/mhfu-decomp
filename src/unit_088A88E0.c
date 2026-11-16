/* unit_088A88E0: 0x088A88E0-0x088A8988 (ULES01213)
 *
 * NonMatching: compiled for the report only, the code is linked from assembly.
 * Bounds (hypothesis): 1 function between unit_088A88C4 and func_088A8988 (still
 * in assembly).
 */

#include "unk_peer.h"

extern void func_088A8570(Session *, s32);

/* 87.5 %: the original tests the state as `beql st, 6, end` / `beqz st, zero` /
 * `b test` with `flags & 0xFF` in the delay slot, and a separate block
 * `v0 = 0; b end` for the zero state; ours folds the zero state into the flag
 * test. Tried: `||` and `&&` in both orders, early returns, switch shapes, a
 * ternary or an if/else for the mask, an inline helper returning the flags. */
s32 func_088A88E0(Session *arg0, s32 idx, u8 flags, s32 arg3) {
    u8 i;
    u8 st;

    i = idx;
    if (arg0->count <= i) {
        return 0;
    }
    st = arg0->unk68[i];
    if (st != 6 && st != 0) {
        if (flags & 0x10) {
            if (st == 3 || st == 4) {
                func_088A8570(arg0, arg3);
            }
            arg0->unkE0[i] = arg0->unk78;
        }
    }
    return 0;
}
