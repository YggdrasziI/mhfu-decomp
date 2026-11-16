/* unit_088A6C48: 0x088A6C48-0x088A6FEC (ULES01213)
 *
 * Bounds (hypothesis): 5 functions building and sending the messages of
 * include/unk_msg.h, between func_088A6BA0 and func_088A6FEC (both NonMatching,
 * same family).
 */

#include "unk_msg.h"

extern s32 func_088A5B50(s32, void *, s32);
extern void *func_088A5EF8(s32, void *, s32);
extern int func_0880D9EC(void *);
extern char D_089B2788;
extern char D_089B2790;
extern char D_089B2798;
extern char D_089B27D4;
extern char D_089B27E8;

s32 func_088A6D64(R *r);

void func_088A6C48(s32 *arg0) {
    M20 m;

    clear((char *) &m, sizeof(M20));
    m.type = 0x10000007;
    m.v[0] = arg0[0];
    m.v[1] = arg0[1];
    m.v[2] = arg0[2];
    m.v[3] = arg0[3];
    m.v[4] = arg0[4];
    m.v[5] = arg0[5];
    func_088A5B50(1, &m, sizeof(M20));
}

s32 func_088A6CC4(R *r) {
    M24 m;
    s32 ret;

    clear((char *) &m, sizeof(M24));
    m.type = 0x20000002;
    m.r.h = r->h;
    m.r.t = r->t;
    ret = func_088A6D64(&m.r);
    if (ret < 0) {
        return ret;
    }
    return *(u8 *)((char *) func_088A5EF8(100, &m, sizeof(M24)) + 0x12);
}

s32 func_088A6D64(R *r) {
    u16 f;

    if (r->h.f.flags & 1) {
        r->h.f.unk3 &= 0x7F;
    } else {
        r->h.f.flags |= 1;
        r->h.f.unk3 = 0x7F;
    }
    f = r->h.f.flags;
    if (f & 0x20) {
        if ((f & 0xE) == 0) {
            func_0880D9EC(&D_089B2788);
            func_0880D9EC(&D_089B2790);
            func_0880D9EC(&D_089B2798);
            return 0x80000012;
        }
    } else if (f & 0x40) {
        func_0880D9EC(&D_089B2788);
        func_0880D9EC(&D_089B2790);
        func_0880D9EC(&D_089B27D4);
        return 0x80000013;
    }
    if (f & 0x10) {
        r->h.f.unk5 &= 0x7F;
    }
    return 0;
}

s32 func_088A6E44(R *r, s32 type) {
    M24 m;
    s32 ret;

    clear((char *) &m, sizeof(M24));
    switch (type) {
    case 0x10000003:
    case 0x10000002:
    case 0x10000001:
        break;
    default:
        func_0880D9EC(&D_089B2788);
        func_0880D9EC(&D_089B2790);
        func_0880D9EC(&D_089B27E8);
        return 0;
    }
    m.type = type;
    m.r.h = r->h;
    m.r.t = r->t;
    ret = func_088A6D64(&m.r);
    if (ret < 0) {
        return 0;
    }
    return func_088A5B50(1, &m, sizeof(M24));
}

void func_088A6F30(R *a, R *b) {
    M40 m;

    clear((char *) &m, sizeof(M40));
    m.unk4 = 0;
    m.type = 0x10000000;
    m.b.h = a->h;
    m.b.t = a->t;
    m.a.h = b->h;
    m.a.t = b->t;
    func_088A5B50(1, &m, sizeof(M40));
}
