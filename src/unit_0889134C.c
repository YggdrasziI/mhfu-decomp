/* unit_0889134C: 0x0889134C-0x08891474 (ULES01213)
 *
 * Bounds (hypothesis): 1 variadic function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#include "libc/stdarg.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 unk4;
    u8 unk5;
    s8 unk6;
    u8 unk7;
    u16 *unk8;
} Entry;

extern void memset(void *, s32, s32);
extern void func_08893C6C(u8 *, char *, s32, char *, va_list, s32);
extern void func_08894754(u8 *, char *, s32);

void func_0889134C(u8 *arg0, char *arg1, ...) {
    s8 idx = *(s8 *) (arg0 + 0x12F);
    u8 *countp = (u8 *) (idx + (s32) arg0) + 0x134;
    u8 count = *countp;
    Entry *e;
    char buf[0x300];
    va_list ap;

    if (count < 0x80) {
        e = ((Entry **) (arg0 + 0x140))[idx] + count;
        *countp = count + 1;
        e->unk0 = *(s16 *) (arg0 + 0x120);
        e->unk2 = *(s16 *) (arg0 + 0x122);
        e->unk4 = arg0[0x12C];
        e->unk5 = arg0[0x12D];
        e->unk7 = arg0[0x15F];
        e->unk6 = *(s8 *) (arg0 + 0x12E);
        e->unk8 = (u16 *) (arg0 + *(u16 *) (arg0 + 0x160) + 0x22CF8);
        memset(buf, 0, 0x300);
        va_start(ap, arg1);
        func_08893C6C(arg0, buf, 0x300, arg1, ap, 1);
        func_08894754(arg0, buf, 1);
    }
}
