/* unit_088A84B4: 0x088A84B4-0x088A8570 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088A812C (still in assembly) and
 * unit_088A8570.
 */

#include "unk_peer.h"

extern int func_088AAE10(char *);

void func_088A84B4(Session *arg0, s32 idx, u8 st) {
    u8 old;

    old = arg0->unk68[(u8) idx];
    arg0->unk68[(u8) idx] = st;
    if (old != 5 && st == 5) {
        if ((u8) idx != arg0->self) {
            arg0->unk148(idx, arg0->unk14C);
        }
    } else if (old != 6 && st == 6 && (u8) idx != arg0->self) {
        func_088AAE10((char *) &arg0->unk8[(u8) idx]);
        arg0->unk150(idx, arg0->unk154);
    }
}
