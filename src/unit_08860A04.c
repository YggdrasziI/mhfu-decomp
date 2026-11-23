/* unit_08860A04: 0x08860A04-0x08860A78 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08860A04 (ULES01213) */

typedef short s16;
typedef int s32;

extern int memset(char *, s32, s32);
extern void func_08860848(char *, char *, s16, s32);

void func_08860A04(char *arg0, s16 arg1) {
    s32 i;
    char *p;

    memset(arg0, 0, 0x150);
    *(s16 *)(arg0 + 0x15C) = arg1;
    p = (char *)(s32)(arg0 + 0xA0) + 0x10;
    for (i = 0; i < 3; i++) {
        func_08860848(arg0, p + 0x10, i, 0);
        p += 0x30;
    }
}
