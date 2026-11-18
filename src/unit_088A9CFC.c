/* unit_088A9CFC: 0x088A9CFC-0x088A9DF4 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088A9CDC and unit_088A9DF4.
 *
 * Session status queries: the first pending error code, then whether the
 * local peer's state allows sending.
 */

#include "unk_peer.h"

extern Session D_09A1D5D0;

s32 func_088A9CFC(void) {
    Session *s = &D_09A1D5D0;

    if (s->unk120 != 0) {
        return s->unk120;
    }
    if (s->unk124 != 0) {
        return s->unk124;
    }
    if (s->unk128 != 0) {
        return s->unk128;
    }
    if (s->unk68[s->self] == 6) {
        return 7;
    }
    return 0;
}

s32 func_088A9D60(void) {
    u8 st = D_09A1D5D0.unk68[D_09A1D5D0.self];

    if (st != 3 && st != 4) {
        return 1;
    }
    if (D_09A1D5D0.unkD4 <= D_09A1D5D0.unk8C) {
        return 2;
    }
    if (D_09A1D5D0.unk78 < D_09A1D5D0.unkD0 + D_09A1D5D0.unkCC) {
        return 3;
    }
    return 0;
}
