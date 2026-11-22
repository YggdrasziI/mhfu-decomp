/* unit_08891474: 0x08891474-0x088915B0 (ULES01213)
 *
 * Bounds (hypothesis): 1 variadic function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#include "libc/stdarg.h"

extern void func_08890DFC(char *, s16, s16);
extern void memset(void *, s32, s32);
extern void func_08893C6C(char *, char *, s32, char *, va_list, s32);
extern void func_08894754(char *, char *, s32);

void func_08891474(char *arg0, s16 arg1, s16 arg2, char *fmt, ...) {
    char buf[0x300];
    va_list ap;
    char *rec;
    s32 n;

    n = ((u8 *) (arg0 + 0x134))[*(s8 *) (arg0 + 0x12F)];
    if (n < 0x80) {
        func_08890DFC(arg0, arg1, arg2);
        rec = ((char **) (arg0 + 0x140))[*(s8 *) (arg0 + 0x12F)] + (u8) n * 0xC;
        (((u8 *) (arg0 + 0x134))[*(s8 *) (arg0 + 0x12F)])++;
        *(s16 *) (rec + 0x0) = *(s16 *) (arg0 + 0x120);
        *(s16 *) (rec + 0x2) = *(s16 *) (arg0 + 0x122);
        *(u8 *) (rec + 0x4) = *(u8 *) (arg0 + 0x12C);
        *(u8 *) (rec + 0x5) = *(u8 *) (arg0 + 0x12D);
        *(u8 *) (rec + 0x7) = *(u8 *) (arg0 + 0x15F);
        *(s8 *) (rec + 0x6) = *(s8 *) (arg0 + 0x12E);
        *(char **) (rec + 0x8) = arg0 + *(u16 *) (arg0 + 0x160) + 0x22CF8;
        memset(buf, 0, 0x300);
        va_start(ap, fmt);
        func_08893C6C(arg0, buf, 0x300, fmt, ap, 1);
        func_08894754(arg0, buf, 1);
    }
}
