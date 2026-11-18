/* unit_088A920C: 0x088A920C-0x088A9334 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088A91F4 and unit_088A9334.
 *
 * Drops each other peer whose timers have run past the session clock.
 */

/* Speed mode: the loop walks arg0 with a strength-reduced pointer. */
#pragma optimize_for_size off

#include "unk_peer.h"

extern void func_088A84B4(Session *, s32, u8);

s32 func_088A920C(Session *arg0) {
    s32 i;

    for (i = 0; i < arg0->count; i++) {
        if (i == arg0->self) {
            continue;
        }
        switch (arg0->unk68[i]) {
        case 4:
            if (arg0->unkF0[i] + (u32) arg0->unk138[i] <= arg0->unk78) {
                func_088A84B4(arg0, (u8) i, 6);
            }
        case 1:
        case 2:
        case 3:
            if (arg0->unkE0[i] + arg0->unk130 <= arg0->unk78) {
                func_088A84B4(arg0, (u8) i, 6);
            }
            break;
        }
    }
    return 0;
}
