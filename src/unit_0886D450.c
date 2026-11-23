/* unit_0886D450: 0x0886D450-0x0886D4D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CC438;

void func_0886D450(char *arg0, char **arg1, u16 arg2, char *arg3, s32 arg4) {
    char *t;
    char *base;
    s32 *e;
    s32 *p;

    t = arg1[*(s8 *)(arg0 + 0x20)];
    if (t != 0 && *(u16 *)(D_089CC438 + 0x6AF12) != 0) {
        base = *(char **)(arg0 + 0x50);
        e = (s32 *)(t + (s32)base);
        for (;;) {
            if (e[0] == 0) return;
            if (e[0] == arg2) break;
            e += 4;
        }
        p = &e[arg4 + 2];
        if ((u32)(*p + 1) > 1) {
            *p = arg3 - base;
        }
    }
}
