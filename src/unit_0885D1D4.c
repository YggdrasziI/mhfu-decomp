/* unit_0885D1D4: 0x0885D1D4-0x0885D300 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885D1D4: when func_0885CF9C accepts arg1 + 0x50C, multiplies that
 * result by 1 plus the number of the six items at arg1 + 0x500, 0x50C,
 * 0x518, 0x524, 0x4F4, 0x4E8 it accepts with argument 1.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern s8 func_0885CF9C(char *, char *, s32);

s32 func_0885D1D4(char *arg0, char *arg1, s32 arg2) {
    s32 r;
    s8 n;

    r = func_0885CF9C(arg0, arg1 + 0x50C, arg2);
    if (r != 0) {
        n = 1;
        if (func_0885CF9C(arg0, arg1 + 0x500, n)) n++;
        if (func_0885CF9C(arg0, arg1 + 0x50C, 1)) n++;
        if (func_0885CF9C(arg0, arg1 + 0x518, 1)) n++;
        if (func_0885CF9C(arg0, arg1 + 0x524, 1)) n++;
        if (func_0885CF9C(arg0, arg1 + 0x4F4, 1)) n++;
        if (func_0885CF9C(arg0, arg1 + 0x4E8, 1)) n++;
        r = (s8)((s8)r * n);
    }
    return r;
}
