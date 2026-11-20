/* unit_088A85F4: 0x088A85F4-0x088A874C (ULES01213)
 *
 * Bounds (hypothesis): 5 functions between unit_088A8570 and func_088A874C (still
 * in assembly): an append to a store and four packet builders that end in it.
 */

#include "unk_peer.h"

extern int memcpy(void *, void *, s32);
extern s32 func_088A7A68(Session *, u8 *);
extern s32 func_088A8018(Session *, s32, s32);
extern Store D_09A1D56C;

s32 func_088A85F4(Session *arg0, Store *g, u8 *pkt) {
    s32 n;

    if (pkt[1] == 1) {
        return func_088A7A68(arg0, pkt);
    }
    if (g->cap < g->pos + pkt[0]) {
        return func_088A8018(arg0, 2, g->pos + pkt[0]);
    }
    memcpy(g->buf + g->pos, pkt, pkt[0]);
    g->pos += pkt[0];
    n = pkt[0];
    return n;
}

s32 func_088A868C(Session *arg0) {
    u8 *pkt;

    pkt = (u8 *) &D_09A11F70;
    pkt[0] = 4;
    pkt[2] = 1;
    pkt[1] = 0;
    pkt[3] = 0xFF;
    return func_088A85F4(arg0, &D_09A1D56C, pkt);
}

s32 func_088A86BC(Session *arg0, s32 arg1) {
    u8 *pkt;

    pkt = (u8 *) &D_09A11F70;
    pkt[0] = 5;
    pkt[4] = arg1;
    pkt[2] = 2;
    pkt[1] = 0;
    pkt[3] = 0xFF;
    return func_088A85F4(arg0, &D_09A1D56C, pkt);
}

s32 func_088A86F0(Session *arg0) {
    u8 *pkt;

    pkt = (u8 *) &D_09A11F70;
    pkt[0] = 4;
    pkt[2] = 3;
    pkt[1] = 0;
    pkt[3] = 0xFF;
    return func_088A85F4(arg0, &D_09A1D56C, pkt);
}

s32 func_088A8720(Session *arg0) {
    u8 *pkt;

    pkt = (u8 *) &D_09A11F70;
    pkt[0] = 4;
    pkt[2] = 4;
    pkt[1] = 0;
    pkt[3] = 0xFF;
    return func_088A85F4(arg0, &D_09A1D56C, pkt);
}
