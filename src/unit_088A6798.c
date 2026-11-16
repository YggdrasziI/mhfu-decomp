/* unit_088A6798: 0x088A6798-0x088A6A78 (ULES01213)
 *
 * Bounds (hypothesis): 8 functions filling a record of include/unk_msg.h and
 * passing it to func_088A6E44 or its two forwarders, between unit_088A6780 and
 * unit_088A6A78.
 */

#include "unk_msg.h"

extern s32 func_088A6E44(R *, s32);
extern void func_088A6780(R *);
extern void func_088A678C(R *);

void func_088A6798(void) {
    R r;

    clear((char *) &r, sizeof(R));
    func_088A6E44(&r, 0x10000002);
}

void func_088A67D8(void) {
    R r;

    clear((char *) &r, sizeof(R));
    func_088A6E44(&r, 0x10000001);
}

void func_088A6818(s32 a) {
    R r;

    clear((char *) &r, sizeof(R));
    r.h.f.flags = 4;
    r.h.f.a = a & 0xF;
    func_088A6E44(&r, 0x10000002);
}

void func_088A6868(s32 a) {
    R r;

    clear((char *) &r, sizeof(R));
    r.h.f.flags = 4;
    r.h.f.a = a & 0xF;
    func_088A6E44(&r, 0x10000001);
}

void func_088A68B8(s32 arg0) {
    R r;

    clear((char *) &r, sizeof(R));
    r.t.w[2] = arg0;
    r.h.f.flags = 0x80;
    func_088A6780(&r);
}

void func_088A68FC(s32 arg0) {
    R r;

    clear((char *) &r, sizeof(R));
    r.t.w[2] = arg0;
    r.h.f.flags = 0x80;
    func_088A678C(&r);
}

void func_088A6940(s32 a, s32 b, s32 c) {
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
    func_088A6780(&r);
}

void func_088A69DC(s32 a, s32 b, s32 c) {
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
    func_088A678C(&r);
}
