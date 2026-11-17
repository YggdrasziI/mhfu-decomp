/* unit_0887EB80: 0x0887EB80-0x0887EBFC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;

extern s32 D_08A62C7C;

extern s32 func_0886A35C(s32, s32);

s32 func_0887EB80(char *arg0) {
    s32 a = func_0886A35C(D_08A62C7C, 1);
    s32 d = a - func_0886A35C(D_08A62C7C, 0);
    s32 ret = d / 30;

    if (d % 30 != 0) {
        ret++;
    }
    return ret;
}