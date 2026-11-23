/* unit_0886D024: 0x0886D024-0x0886D0AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886D024 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern char *D_09A4F060;
extern s8 D_08A62C9C[];
extern char *D_08A62C7C;
extern void func_0886CE10(char *, s32);

void func_0886D024(char *arg0) {
    s32 n;
    s32 i;

    n = *(s8 *)(arg0 + 0x21);
    if (n >= 0x14) {
        n--;
        for (i = 0; i < n; i++) {
            if (!(*(u8 *)(D_09A4F060 + D_08A62C9C[i] * 32 + 0x1E) & 1)) {
                break;
            }
        }
        func_0886CE10(D_08A62C7C, D_08A62C9C[i]);
    }
}
