/* unit_0889EAE8: 0x0889EAE8-0x0889EB84 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_0889EA4C and func_0889EB84 (NonMatching).
 */

#include "unk_msg.h"

extern s32 func_0889EC50(R *);

s32 func_0889EAE8(s32 a, s32 b, s32 c) {
    R r;

    clear((char *) &r, sizeof(R));
    if (a == -1) {
        r.h.f.flags |= 2;
    } else {
        r.h.f.a = a;
        r.h.f.flags |= 4;
    }
    if (b != -1) {
        r.h.f.b = b;
        r.h.f.flags |= 0x20;
    }
    if (c != -1) {
        r.h.f.c = c;
        r.h.f.flags |= 0x40;
    }
    return func_0889EC50(&r);
}
