/* unit_088A8E3C: 0x088A8E3C-0x088A9084 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088A8D74 and func_088A9084
 * (still in assembly). NonMatching: the code stays in the asm piece
 * text_088A8E3C.
 *
 * Optimized for speed (the per-peer word at +0x8 is walked with a pointer).
 *
 * For each peer, receives what fits in its buffer, then splits it into
 * packets and copies each one into one of two queues chosen by the packet
 * type.
 */

#pragma optimize_for_size off

#include "unk_peer.h"

extern Store D_09A1D59C[];
extern Store D_09A1D578;

extern void func_088A7BDC(Session *);
extern void func_088A7F6C(Session *);
extern int memcpy(void *, void *, s32);
extern int func_0880C1A8(void *, void *, s32);
extern s32 func_088AAC80(s32, char *, s16);
extern void func_088A84B4(Session *, s32, u8);
extern s32 func_088A8C78(Session *, char *, s32, Header *);
extern s32 func_088A8B98(Session *, Header *);
extern s32 func_088A8028(Session *, s32, s32);
extern s32 func_088A88E0(Session *, s32, u8, char *);

/* NonMatching, 99.0 %: the peer's buffer and the inner position are in swapped
 * registers (original s3 / s2). Tried: declaration orders, block-scoped
 * locals, pointer or index forms for the buffer, a separate length local, two
 * forms of the final move.
 */
s32 func_088A8E3C(Session *arg0) {
    Header hdr;
    s32 i;
    Store *st;
    Store *dst;
    s32 n;
    s32 r;
    s32 pos;
    u8 s;

    func_088A7BDC(arg0);
    func_088A7F6C(arg0);
    for (i = 0; i < arg0->count; i++) {
        st = &D_09A1D59C[i];
        if (i == arg0->self) {
            continue;
        }
        s = arg0->unk68[i];
        if (s == 6 || s == 0) {
            continue;
        }
        n = 0xFF;
        if (st->cap < st->pos + 0xFF) {
            n = st->cap - st->pos;
        }
        if (n == 0) {
            continue;
        }
        r = func_088AAC80(arg0->unk8[i], st->buf + st->pos, n);
        if (r < 0) {
            func_088A84B4(arg0, (u8) i, 6);
            continue;
        }
        if (r == 0) {
            continue;
        }
        st->pos += r;
        arg0->unk90 += r;
        arg0->unkE0[arg0->self] = arg0->unk78;
        pos = 0;
        for (;;) {
            r = func_088A8C78(arg0, st->buf + pos, st->pos - pos, &hdr);
            if (r < 0) {
                pos -= r;
                continue;
            }
            if (r == 0) {
                break;
            }
            if (func_088A8B98(arg0, &hdr) < 0) {
                pos += r;
                continue;
            }
            dst = (hdr.type & 0xF) == 2 ? &D_09A1D590 : &D_09A1D578;
            if (dst->cap < dst->pos + r) {
                return func_088A8028(arg0, 4, dst->pos + r);
            }
            memcpy(dst->buf + dst->pos, st->buf + pos, r);
            func_088A88E0(arg0, hdr.from, hdr.type, dst->buf + (dst->pos + 6));
            pos += r;
            dst->pos += r;
        }
        n = st->pos - pos;
        st->pos = n;
        if (n > 0) {
            func_0880C1A8(st->buf, st->buf + pos, n);
        }
    }
    return 0;
}
