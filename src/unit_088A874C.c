/* unit_088A874C: 0x088A874C-0x088A88C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

#include "unk_peer.h"

extern void func_088A84B4(Session *, s32, u8);
extern s32 func_088A868C(Session *);

s32 func_088A874C(Session *arg0, s32 arg1, u8 *pkt) {
    switch (pkt[2]) {
    case 1:
        if (arg0->unk68[arg0->self] != 1) {
            break;
        }
        if (arg0->unk68[(u8) arg1] == 1) {
            func_088A84B4(arg0, arg1, 2);
            func_088A868C(arg0);
            arg0->unk64 |= 1 << (u8) arg1;
        }
        break;
    case 2:
        if (arg0->unk68[(u8) arg1] == 3) {
            func_088A84B4(arg0, arg1, 4);
            arg0->unkF0[(u8) arg1] = arg0->unk78;
            arg0->unk138[(u8) arg1] = pkt[4];
        }
        break;
    case 3:
        if (arg0->unk68[(u8) arg1] == 4) {
            func_088A84B4(arg0, arg1, 3);
            arg0->unkF0[(u8) arg1] = 0;
            arg0->unk138[(u8) arg1] = 0;
        }
        break;
    case 4:
        if (arg0->unk68[(u8) arg1] == 3) {
            func_088A84B4(arg0, arg1, 5);
        }
        break;
    default:
        return 0;
    }
    arg0->unkE0[(u8) arg1] = arg0->unk78;
    return 0;
}
