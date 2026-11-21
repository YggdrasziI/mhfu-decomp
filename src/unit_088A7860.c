/* unit_088A7860: 0x088A7860-0x088A7A68 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088A7788 and unit_088A7A68.
 */

#pragma optimize_for_size off

#include "unk_peer.h"

extern int memcpy(void *, void *, s32);
extern int func_0880C1A8(void *, void *, s32);
extern s32 func_088AD0D4(s32);
extern s32 func_088AAFA4(s32, char *, s32, Packet *, s32);
extern s32 func_088A8048(Session *, char *, s32, s32);
extern char D_09A0FDC8;
extern char D_09A11F76[];

/* Speed mode puts the packet in $s6 and the length read-back in $s1; this
 * declaration order (found by search) fixes the loop registers, and `off = 0`
 * after `dst` gives its late `addu`. `room = 0xFF; room -= 6;` is needed for
 * the unfolded `addiu` pair. */
s32 func_088A7860(Session *arg0) {
    SendBuf *g;
    s32 rem;
    s32 n;
    s32 off;
    s32 room;
    s32 flag;
    s32 i;
    s32 len;
    u8 *pkt;
    u8 st;
    u8 t[4];
    u16 v;
    char *dst;

    g = &D_09A11EE4;
    flag = 0;
    i = 0;
    if (arg0->count > 0) {
        do {
            if (i != arg0->self) {
                st = arg0->unk68[i];
                if (st != 6 && st != 5 && st != 0) {
                    flag = 1;
                    break;
                }
            }
            i++;
        } while (i < arg0->count);
    }
    len = 6;
    room = 0xFF;
    room -= 6;
    pkt = (u8 *) &D_09A11F70;
    pkt[1] = 3;
    pkt[2] = arg0->self;
    dst = D_09A11F76;
    off = 0;
    while (room > 0 && off < g->pos) {
        memcpy(t, g->buf + off, 4);
        if (room < t[0]) {
            break;
        }
        memcpy(dst, g->buf + off, t[0]);
        room -= t[0];
        len += t[0];
        dst += t[0];
        off += t[0];
    }
    if (len == 6) {
        return 0;
    }
    pkt[3] = arg0->unk114[arg0->self];
    v = func_088AD0D4(++arg0->unk118[arg0->self]);
    pkt[0] = len;
    *(u16 *) (pkt + 4) = v;
    n = pkt[0];
    if (flag == 1) {
        func_088AAFA4(arg0->unk18, &D_09A0FDC8, 0x4E21, (Packet *) pkt, (s16) n);
        arg0->unkA4 += n;
    }
    if (off != 0) {
        func_088A8048(arg0, g->buf, off, 3);
        rem = g->pos - off;
        if (rem > 0) {
            func_0880C1A8(g->buf, g->buf + off, rem);
        }
        g->pos = rem;
    }
    return off;
}
