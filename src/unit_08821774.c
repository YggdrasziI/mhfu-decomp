/* unit_08821774: 0x08821774-0x08821828 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 * func_08821774 lists up to 9 (value, result) byte pairs for which
 * func_0885CF9C accepts arg1, then clears the remaining pairs.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern char *D_08A62C54;
extern s8 func_0885CF9C(char *, char *, u8);

void func_08821774(s32 arg0, char *arg1, u8 *arg2) {
    s32 n;
    s32 i;
    s8 r;

    n = 0;
    if (arg1 != 0) {
        for (i = 1; i < 100; i++) {
            r = func_0885CF9C(D_08A62C54, arg1, i);
            if (r != 0) {
                arg2[0] = i;
                arg2[1] = r;
                if (n >= 8) {
                    return;
                }
                n++;
                arg2 += 2;
            }
        }
    }
    for (; n < 9; n++) {
        arg2[0] = 0;
        arg2[1] = 0;
        arg2 += 2;
    }
}
