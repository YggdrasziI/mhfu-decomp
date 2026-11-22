/* unit_088920A8: 0x088920A8-0x08892148 (ULES01213)
 *
 * Bounds (hypothesis): 1 variadic function between code still in assembly.
 */

typedef int s32;
typedef short s16;

#include "libc/stdarg.h"

extern void func_08890DFC(char *, s16, s16);
extern void memset(void *, s32, s32);
extern void func_08893C6C(char *, char *, s32, s32, va_list, s32);
extern void func_088921FC(char *, s32, char *);

void func_088920A8(char *arg0, s16 arg1, s16 arg2, s32 arg3, ...) {
    char buf[0x300];
    va_list ap;

    func_08890DFC(arg0, arg1, arg2);
    memset(buf, 0, 0x300);
    va_start(ap, arg3);
    func_08893C6C(arg0, buf, 0x300, arg3, ap, 1);
    func_088921FC(arg0, -1, buf);
}
