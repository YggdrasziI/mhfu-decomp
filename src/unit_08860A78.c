/* unit_08860A78: 0x08860A78-0x08860B24 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern void func_08860848(char *, char *, s16, s32);

void func_08860A78(char *arg0, char *arg1) {
    s32 i;
    char *p;
    s32 off;

    p = arg0 + 0xB0;
    i = 0;
    off = 0;
    do {
        char *src = *(char **)(arg1 + 0x1DC);
        char *dst = p + 0x10;
        if (src == 0 || i == 2) {
            func_08860848(arg0, dst, i, 1);
        } else {
            src += off;
            *(float *)(dst + 0) = *(float *)(src + 0);
            *(float *)(dst + 4) = *(float *)(src + 4);
            *(float *)(dst + 8) = *(float *)(src + 8);
        }
        i++;
        p += 0x30;
        off += 0x10;
    } while (i < 3);
}
