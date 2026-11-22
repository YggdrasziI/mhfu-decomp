/* unit_0889183C: 0x0889183C-0x0889198C (ULES01213)
 *
 * Variadic text print: positions the cursor, sets the colour, queues a
 * record and formats the arguments into a local buffer (hypothesis).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

#include "libc/stdarg.h"

extern void func_08890DFC(u8 *, s16, s16);
extern void func_08890E38(u8 *, s8);
extern void *memset(void *, s32, s32);
extern void func_08893C6C(u8 *, char *, s32, const char *, va_list, s32);
extern void func_08894754(u8 *, char *, s32);

void func_0889183C(u8 *arg0, s16 arg1, s16 arg2, s8 arg3, const char *fmt, ...) {
    char buf[0x300];
    va_list ap;
    s32 idx;
    char *rec;
    s8 slot;

    idx = arg0[(s8) arg0[0x12F] + 0x134];
    if (idx < 0x80) {
        func_08890DFC(arg0, arg1, arg2);
        func_08890E38(arg0, arg3);
        slot = (s8) arg0[0x12F];
        rec = ((char **) (arg0 + 0x140))[slot] + (u8) idx * 12;
        arg0[slot + 0x134]++;
        *(s16 *) (rec + 0) = *(s16 *) (arg0 + 0x120);
        *(s16 *) (rec + 2) = *(s16 *) (arg0 + 0x122);
        rec[4] = arg0[0x12C];
        rec[5] = arg0[0x12D];
        rec[7] = arg0[0x15F];
        rec[6] = *(s8 *) (arg0 + 0x12E);
        *(u8 **) (rec + 8) = arg0 + *(unsigned short *) (arg0 + 0x160) + 0x22CF8;
        memset(buf, 0, 0x300);
        va_start(ap, fmt);
        func_08893C6C(arg0, buf, 0x300, fmt, ap, 0);
        func_08894754(arg0, buf, 0);
        va_end(ap);
    }
}
