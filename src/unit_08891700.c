/* unit_08891700: 0x08891700-0x0889183C (ULES01213)
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
    s16 x;
    s16 y;
    u8 unk4;
    u8 unk5;
    s8 unk6;
    u8 unk7;
    char *unk8;
} Entry;

extern void func_08890DFC(char *, s16, s16);
extern void memset(void *, s32, s32);
extern void func_08893C6C(char *, char *, s32, char *, char *, s32);
extern void func_08894754(char *, char *, s32);

void func_08891700(char *arg0, s16 arg1, s16 arg2, char *fmt, ...) {
    char buf[0x300];
    char *ap;
    u8 idx;
    Entry *e;

    idx = (arg0 + 0x134)[*(s8 *) (arg0 + 0x12F)];
    if (idx < 0x80) {
        func_08890DFC(arg0, arg1, arg2);
        e = &((Entry **) (arg0 + 0x140))[*(s8 *) (arg0 + 0x12F)][idx];
        ((u8 *) (arg0 + 0x134))[*(s8 *) (arg0 + 0x12F)]++;
        e->x = *(s16 *) (arg0 + 0x120);
        e->y = *(s16 *) (arg0 + 0x122);
        e->unk4 = *(u8 *) (arg0 + 0x12C);
        e->unk5 = *(u8 *) (arg0 + 0x12D);
        e->unk7 = *(u8 *) (arg0 + 0x15F);
        e->unk6 = *(s8 *) (arg0 + 0x12E);
        e->unk8 = arg0 + *(u16 *) (arg0 + 0x160) + 0x22CF8;
        memset(buf, 0, 0x300);
        va_start(ap, fmt);
        func_08893C6C(arg0, buf, 0x300, fmt, ap, 0);
        func_08894754(arg0, buf, 0);
    }
}
