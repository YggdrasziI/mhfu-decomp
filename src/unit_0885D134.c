/* unit_0885D134: 0x0885D134-0x0885D1D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern u8 *func_0885E834(s32, s32);

s8 func_0885D134(s32 arg0, s32 arg1, u8 arg2) {
    s8 r = 0;
    u8 *p = func_0885E834(arg0, arg1);
    if (p != 0) {
        if (p[8] == arg2) r += (s8)p[9];
        if (p[10] == arg2) r += (s8)p[11];
        if (p[12] == arg2) r += (s8)p[13];
        if (p[14] == arg2) r += (s8)p[15];
    }
    return r;
}
