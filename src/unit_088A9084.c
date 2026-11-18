/* unit_088A9084: 0x088A9084-0x088A91F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088A8E3C (NonMatching) and
 * unit_088A91F4.
 *
 * Polls each peer's link state, counts how often its counter lags behind,
 * drops the peer past a threshold, then rolls the per-frame byte counters.
 */

/* Speed mode: the loop walks arg0 with two strength-reduced pointers. */
#pragma optimize_for_size off

#include "unk_peer.h"

extern s32 func_088A7F6C(Session *);
extern s32 func_088AA9B4(s32, char *);
extern void func_088A84B4(Session *, s32, u8);

s32 func_088A9084(Session *arg0) {
    s32 i;
    u16 v;
    u16 cnt;
    u16 old;

    if (func_088A7F6C(arg0) <= 0) {
        return 0;
    }
    arg0->unkDA = 0;
    for (i = 0; i < arg0->count; i++) {
        if (arg0->unk8[i] < 0) {
            continue;
        }
        if (func_088AA9B4(arg0->unk8[i], arg0->unkD8) < 0) {
            continue;
        }
        if (*(s16 *) arg0->unkD8 != 4) {
            continue;
        }
        v = *(u16 *) arg0->unkDC;
        old = arg0->unk100[i];
        cnt = arg0->unk108[i];
        if (v >= 0x1FFA) {
            cnt = 0;
        } else if (old - arg0->unk8C < v) {
            if (cnt > 0) {
                cnt--;
            }
        } else if (cnt < 0xFFFF) {
            cnt++;
        }
        arg0->unk100[i] = v;
        arg0->unk108[i] = cnt;
        if (arg0->unk13C <= cnt) {
            func_088A84B4(arg0, (u8) i, 6);
        }
    }
    arg0->unk9C += arg0->unk8C;
    arg0->unkA0 += arg0->unk90;
    arg0->unk94 = arg0->unk8C;
    arg0->unk98 = arg0->unk90;
    arg0->unk8C = 0;
    arg0->unk90 = 0;
    return 0;
}
