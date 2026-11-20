/* unit_088A8048: 0x088A8048-0x088A812C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088A8028 and func_088A812C (still
 * in assembly).
 */

#include "unk_peer.h"

extern int memcpy(void *, void *, s32);
extern s32 func_088A8018(Session *, s32, s32);
extern s32 D_09A1D594;

s32 func_088A8048(Session *arg0, char *data, s32 n, s32 type) {
    Header h;
    Store *g;

    g = &D_09A1D590;
    if (D_09A1D594 < D_09A1D590.pos + 6 + n) {
        return func_088A8018(arg0, 4, g->pos + 6 + n);
    }
    h.len = n + 6;
    h.type = type;
    h.from = arg0->self;
    h.seq = 0xFF;
    h.n = 0xFFFF;
    memcpy(g->buf + g->pos, &h, 6);
    memcpy(g->buf + (g->pos + 6), data, n);
    g->pos += h.len;
    return 0;
}
