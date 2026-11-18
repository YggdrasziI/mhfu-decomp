/* unit_088A8D74: 0x088A8D74-0x088A8E3C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088A8C78 and func_088A8E3C
 * (still in assembly).
 *
 * Hands every complete packet of a buffer to func_088A8988, then moves what
 * is left to the start of the buffer.
 */

#include "unk_peer.h"

extern int func_0880C1A8(void *, void *, s32);
extern s32 func_088A8C78(Session *, char *, s32, Header *);
extern s32 func_088A8988(Session *, s32, u8, char *, u8);

s32 func_088A8D74(Session *arg0, Store *b) {
    Header hdr;
    s32 pos;
    s32 r;
    s32 n;

    pos = 0;
    for (;;) {
        r = func_088A8C78(arg0, b->buf + pos, b->pos - pos, &hdr);
        if (r < 0) {
            pos -= r;
            continue;
        }
        if (r == 0) {
            break;
        }
        if (func_088A8988(arg0, hdr.from, hdr.type, b->buf + (pos + 6), r - 6) < 0) {
            return -1;
        }
        pos += r;
    }
    n = b->pos - pos;
    b->pos = n;
    if (n > 0) {
        func_0880C1A8(b->buf, b->buf + pos, n);
    }
    return 0;
}
