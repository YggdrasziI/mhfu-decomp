/* unit_08872CC0: 0x08872CC0-0x08872D74 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

s8 func_08872CC0(s32 arg0, s8 arg1, s8 arg2) {
    s8 lo;
    s8 hi;

    if (arg1 >= 0 && arg1 < 8) {
        lo = 0;
        hi = 7;
    } else if (arg1 >= 8 && arg1 < 16) {
        lo = 8;
        hi = 15;
    } else if (arg1 >= 16 && arg1 < 24) {
        lo = 16;
        hi = 23;
    } else {
        lo = 24;
        hi = 31;
    }
    arg1 += arg2;
    if (arg1 < lo) {
        arg1 = lo;
    }
    if (arg1 > hi) {
        arg1 = hi;
    }
    return arg1;
}
