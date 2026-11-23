/* unit_0886D2E4: 0x0886D2E4-0x0886D374 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;

extern char *func_088697D4(char *, u16, s32, s8);

void func_0886D2E4(char *arg0, u16 arg1) {
    char *p;

    if (func_088697D4(arg0, arg1, 0, *(s8 *)(arg0 + 0x20)) != 0) {
        p = func_088697D4(arg0, arg1, 1, *(s8 *)(arg0 + 0x20));
        for (;;) {
            if (*(s16 *)p < 0) {
                break;
            }
            if (*(s16 *)(p + 0x2E) & 4) {
                *(s16 *)(p + 0x2E) = 2;
                *(s16 *)(p + 0x32) = -1;
            }
            p += 0x3C;
        }
    }
}
