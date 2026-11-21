/* unit_088A88E0: 0x088A88E0-0x088A8988 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088A88C4 and func_088A8988.
 */

#include "unk_peer.h"

extern void func_088A8570(Session *, s32);

s32 func_088A88E0(Session *arg0, s32 idx, u8 flags, s32 arg3) {
    u8 i;
    u8 st;

    i = idx;
    if (arg0->count <= i) {
        return 0;
    }
    st = arg0->unk68[i];
    switch (st) {
    case 0:
    case 6:
        return 0;
    }
    if (flags & 0x10) {
        if (st == 3 || st == 4) {
            func_088A8570(arg0, arg3);
        }
        arg0->unkE0[i] = arg0->unk78;
    }
    return 0;
}
