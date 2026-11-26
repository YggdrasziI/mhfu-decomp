/* unit_088291B4: 0x088291B4-0x088292AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * NonMatching: func_088291B4 99.60 %. Left: arg1 in s1 instead of s2 and
 * the order of the two parameter moves. With func_08852F58 declared with
 * one argument the moves come out in the original order (99.84 %), but
 * unit_088260D4 passes it two; every declaration order, loop form and
 * opt pragma was tried for the s1/s2 swap.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern char *D_089CC438;
extern s32 func_08852F58(char *, s32);
extern s32 func_08852F1C(char *, u8);

s8 func_088291B4(s32 arg0, s32 arg1, s32 arg2) {
    s8 idx;
    s32 i;
    s8 dir;

    if (func_08852F58(D_089CC438, arg1) != 0) {
        if ((s8)arg1 < 0) {
            idx = 0;
        } else {
            idx = arg1 + arg2;
            if (idx > 61) {
                idx = 0;
            }
            if (idx < 0) {
                idx = 61;
            }
        }
        dir = arg2;
        i = 62;
        do {
            if (!(func_08852F1C(D_089CC438, idx) != 0) == 0) {
                return idx;
            }
            if (dir >= 0) {
                idx++;
                if (idx > 61) {
                    idx = 0;
                }
            } else if (idx <= 0) {
                idx = 61;
            } else {
                idx--;
            }
            i--;
        } while (i > 0);
    }
    return -1;
}
