/* unit_08850EFC: 0x08850EFC-0x08850FB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef short s16;

extern s16 func_08850E58(char *);

s16 func_08850EFC(char *arg0, s16 arg1) {
    s16 max;
    s16 hi;

    if (arg1 <= 0) {
        if (arg1 < 0) {
            do {
                arg1 += 100;
            } while (arg1 < 0);
        }
        return arg1;
    }
    max = func_08850E58(arg0) - 1;
    hi = arg1 / 100;
    if (max < hi) {
        hi = max;
    }
    return hi * 100 + arg1 % 100;
}
