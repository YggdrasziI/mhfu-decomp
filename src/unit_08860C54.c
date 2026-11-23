/* unit_08860C54: 0x08860C54-0x08860CB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern void func_08860848(char *, char *, s16, s32);

void func_08860C54(char *arg0) {
    s32 i;
    char *p;

    p = arg0 + 0xB0;
    for (i = 0; i < 3; i++) {
        func_08860848(arg0, p + 0x10, i, 1);
        p += 0x30;
    }
}
