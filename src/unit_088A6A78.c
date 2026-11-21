/* unit_088A6A78: 0x088A6A78-0x088A6C48 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions before unit_088A6C48. func_088A6A78 is
 * `static` and defined before its only caller func_088A6BA0: the original
 * keeps `&r` in $a0 across that call (the compiler knows a static function
 * already compiled leaves $a0 alone); with an extern callee $a0 is
 * reloaded.
 */

#include "unk_msg.h"

/* Copies the optional fields flagged in arg1 into the record arg0. */
static void func_088A6A78(char *arg0, char *arg1) {
    if (*(s32 *)arg1 & 0x80) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x100);
        *(s16 *)(arg0 + 8) = (s16) *(s32 *)(arg1 + 0x20);
    }
    if (*(s32 *)arg1 & 0x100) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x200);
        *(s16 *)(arg0 + 0xA) = (s16) *(s32 *)(arg1 + 0x24);
    }
    if (*(s32 *)arg1 & 0x200) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x400);
        *(s16 *)(arg0 + 0xC) = (s16) *(s32 *)(arg1 + 0x28);
    }
    if (*(s32 *)arg1 & 0x1000) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x200);
        *(s8 *)(arg0 + 2) = (s8) *(s32 *)(arg1 + 0x34);
    }
    if (*(s32 *)arg1 & 0x400) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x800);
        *(s16 *)(arg0 + 0xE) = (s16) *(s32 *)(arg1 + 0x2C);
    }
    if (*(s32 *)arg1 & 0x40) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x4000);
        *(s8 *)(arg0 + 3) = (s8) *(s32 *)(arg1 + 0x1C);
    }
    if (*(s32 *)arg1 & 0x800) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x1000);
        *(s8 *)(arg0 + 0x13) = (s8) *(s32 *)(arg1 + 0x30);
    }
    if (*(s32 *)arg1 & 0x2000) {
        *(u16 *)arg0 = (u16) (*(u16 *)arg0 | 0x2000);
        *(s8 *)(arg0 + 0x11) = (s8) *(s32 *)(arg1 + 0x38);
    }
}

extern s32 func_088A6E44(R *, s32);

void func_088A6BA0(s32 a, s32 b, s32 c, s32 arg3) {
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
    func_088A6A78((char *) &r, (char *) arg3);
    func_088A6E44(&r, 0x10000003);
}

