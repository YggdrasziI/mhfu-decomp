/* unit_08892004: 0x08892004-0x088920A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 variadic function between code still in assembly.
 */

#include "libc/stdarg.h"

extern void *memset(void *, int, unsigned int);
extern void func_08893C6C(char *, char *, int, char *, va_list, int);
extern void func_088921FC(char *, int, char *);

void func_08892004(char *arg0, char *arg1, ...) {
    char buf[0x300];
    va_list ap;

    memset(buf, 0, 0x300);
    va_start(ap, arg1);
    func_08893C6C(arg0, buf, 0x300, arg1, ap, 1);
    va_end(ap);
    func_088921FC(arg0, -1, buf);
}
