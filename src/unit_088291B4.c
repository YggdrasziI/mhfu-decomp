/* unit_088291B4: 0x088291B4-0x088292AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern char *D_089CC438;
extern s32 func_08852F58(char *);
extern s32 func_08852F1C(char *, u8);

s32 func_088291B4(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s8 dir;

    if (func_08852F58(D_089CC438) != 0) {
        if ((s8)arg1 < 0) {
            arg1 = 0;
        } else {
            arg1 = (s8)(arg1 + arg2);
            if (arg1 > 61) {
                arg1 = 0;
            }
            if ((s8)arg1 < 0) {
                arg1 = 61;
            }
        }
        dir = arg2;
        i = 62;
        do {
            if (!(func_08852F1C(D_089CC438, arg1) != 0) == 0) {
                return arg1;
            }
            if (dir >= 0) {
                arg1 = (s8)(arg1 + 1);
                if (arg1 > 61) {
                    arg1 = 0;
                }
            } else if ((s8)arg1 <= 0) {
                arg1 = 61;
            } else {
                arg1 = (s8)(arg1 - 1);
            }
            i--;
        } while (i > 0);
    }
    return -1;
}
