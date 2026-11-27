/* unit_088A812C: 0x088A812C-0x088A84B4 (ULES01213)
 *
 * Builds a packet from the queued entries of a store and sends it to every
 * other peer (same scheme as func_088A7860).
 *
 * The peer state test is a `switch` whose cases 0 and 6 `break`: the
 * `if (st != 6 && st != 0)` form fills the empty `jal` slot of the
 * func_088AAD58 call with the `addu a1`.
 */

#pragma optimize_for_size off

#include "unk_peer.h"

extern int memcpy(void *, void *, s32);
extern int func_0880C1A8(void *, void *, s32);
extern s32 func_088A7860(Session *);
extern void func_088A7F6C(Session *);
extern s32 func_088AA9B4(s32, char *);
extern s32 func_088AD0D4(s32);
extern s32 func_088AAD58(s32, u8 *, s16);
extern void func_088A84B4(Session *, s32, u8);
extern s32 func_088A8048(Session *, char *, s32, s32);
extern char D_09A11F76[];


/* `len = 6; dst = ...; pkt[2] = ...` in this order schedules the setup; the
 * entry length goes through an `s32` local cast `(u8)` at the copy (`andi`). */
s32 func_088A812C(Session *arg0, Store *g, s32 arg2) {
    s32 rest;
    s32 ret;
    s32 sz;
    s32 off;
    s32 room;
    s32 flag;
    s32 i;
    s32 len;
    u8 *pkt;
    u8 t[4];
    u8 type;
    char *dst;

    func_088A7860(arg0);
    func_088A7F6C(arg0);
    arg0->unkDA = 0;
    flag = 0;
    for (i = 0; i < arg0->count; i++) {
        if (arg0->unk8[i] >= 0 && func_088AA9B4(arg0->unk8[i], arg0->unkD8) >= 0 &&
            *(s16 *) arg0->unkD8 == 4 && *(u16 *) arg0->unkDC < 0x2000) {
            flag = 1;
            break;
        }
    }
    room = 0xFF;
    room -= 6;
    type = arg2;
    pkt = (u8 *) &D_09A11F70;
    pkt[1] = type & 0xF;
    len = 6;
    dst = D_09A11F76;
    pkt[2] = arg0->self;
    if ((1.0f + *(float *) arg0->unk6C < arg0->unk78 && g->pos > 0) ||
        2.0f + *(float *) arg0->unk6C < arg0->unk78) {
        if (room < 4) {
            return 0;
        }
        room -= 4;
        for (i = 0; i < arg0->count; i++) {
            dst[i] = arg0->unk68[i];
        }
        len += 4;
        dst += 4;
        pkt[1] |= 0x10;
    }
    off = 0;
    while (room > 0 && off < g->pos) {
        memcpy(t, g->buf + off, 4);
        sz = t[0];
        if (room < sz) {
            break;
        }
        if (flag != 0 && t[1] == 1) {
            off += sz;
        } else {
            memcpy(dst, g->buf + off, (u8) sz);
            room -= t[0];
            len += t[0];
            dst += t[0];
            off += t[0];
        }
    }
    if (len == 6) {
        return 0;
    }
    pkt[3] = ++arg0->unk114[arg0->self];
    *(u16 *) (pkt + 4) = func_088AD0D4(0);
    arg0->unk118[arg0->self] = 0;
    pkt[0] = len;
    len = pkt[0];
    for (i = 0; i < arg0->count; i++) {
        if (i != arg0->self) {
            switch (arg0->unk68[i]) {
            case 0:
            case 6:
                break;
            default:
                ret = func_088AAD58(arg0->unk8[i], pkt, (s16) len);
                if (ret != len) {
                    func_088A84B4(arg0, (u8) i, 6);
                }
            }
        }
    }
    arg0->unk8C += len;
    arg0->unkD0 = arg0->unk78;
    if (pkt[1] & 0x10) {
        *(float *) arg0->unk6C = arg0->unk78;
    }
    if (off != 0) {
        if (type == 2) {
            func_088A8048(arg0, g->buf, off, arg2);
        }
        rest = g->pos - off;
        if (rest > 0) {
            func_0880C1A8(g->buf, g->buf + off, rest);
        }
        g->pos = rest;
    }
    return off;
}
