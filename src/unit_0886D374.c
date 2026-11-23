/* unit_0886D374: 0x0886D374-0x0886D450 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern char *func_088697D4(char *, u16, s32, s8);
extern void func_0886D450(char *, char **, u16, s32, s32);

void func_0886D374(char *arg0, u16 arg1) {
    char *e;
    char *p;
    s32 found;
    s16 v;

    e = func_088697D4(arg0, arg1, 0, *(s8 *)(arg0 + 0x20));
    if (e != 0) {
        p = func_088697D4(arg0, arg1, 1, *(s8 *)(arg0 + 0x20));
        found = 0;
        while (1) {
            v = *(s16 *)p;
            if (v < 0) {
                break;
            }
            if ((*(s16 *)(p + 0x2E) & 5) == 0) {
                found = 1;
            }
            p += 0x3C;
        }
        if (found == 0 && v == -2) {
            func_0886D450(arg0, *(char ***)(arg0 + 0x718), arg1, (s32)(p + 0x3C), 1);
            func_0886D450(arg0, *(char ***)(arg0 + 0x718), arg1, (s32)(e + 0x10), 0);
        }
    }
}
