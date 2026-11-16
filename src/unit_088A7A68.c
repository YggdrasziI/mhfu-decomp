/* unit_088A7A68: 0x088A7A68-0x088A7BDC (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between func_088A7860 and func_088A7BDC (both
 * still in assembly).
 */

#include "unk_peer.h"

extern int func_0880C084(void *, void *, s32);
extern s32 func_088A8018(char *, s32, s32);
extern s32 D_09A11EE8;
extern s32 func_088AD0F0(s32);

s32 func_088A7A68(char *arg0, u8 *arg1) {
    SendBuf *g;
    s32 n;

    g = &D_09A11EE4;
    if (D_09A11EE8 < D_09A11EE4.pos + arg1[0]) {
        return func_088A8018(arg0, 2, g->pos + arg1[0]);
    }
    func_0880C084(g->buf + g->pos, arg1, arg1[0]);
    n = arg1[0];
    g->pos += n;
    return n;
}

s32 func_088A7AF0(Session *arg0, u8 *arg1) {
    u8 idx;
    u16 v;

    idx = arg1[2];
    if (arg0->count <= idx) {
        return 0;
    }
    if (arg0->self == idx) {
        return 0;
    }
    if (arg1[3] != arg0->unk114[idx]) {
        return -1;
    }
    v = func_088AD0F0(*(u16 *) (arg1 + 4));
    if (v <= arg0->unk118[idx]) {
        return -1;
    }
    if (arg0->unkBC[idx] < 0xFFFEFFFFU) {
        arg0->unkAC[idx] += 1;
    }
    arg0->unk118[arg1[2]] = func_088AD0F0(*(u16 *) (arg1 + 4));
    return 0;
}
