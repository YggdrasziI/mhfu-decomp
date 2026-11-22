/* unit_08892148: 0x08892148-0x088921FC (ULES01213)
 *
 * Bounds (hypothesis): 1 variadic function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef signed char s8;

#include "libc/stdarg.h"

extern void func_08890DFC(char *, s16, s16);
extern void func_08890E38(char *, s8);
extern void memset(void *, s32, s32);
extern void func_08893C6C(char *, char *, s32, char *, char *, s32);
extern void func_088921FC(char *, s32, char *);

void func_08892148(char *arg0, s16 arg1, s16 arg2, s8 arg3, char *arg4, ...) {
    char buf[0x300];
    char *ap;

    func_08890DFC(arg0, arg1, arg2);
    func_08890E38(arg0, arg3);
    memset(buf, 0, 0x300);
    va_start(ap, arg4);
    func_08893C6C(arg0, buf, 0x300, arg4, ap, 1);
    func_088921FC(arg0, -1, buf);
}
