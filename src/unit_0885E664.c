/* unit_0885E664: 0x0885E664-0x0885E718 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 * The initialised array of func_0885E664 (0x089A5B80-0x089A5B90, in .data) is
 * linked from this unit.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 func_0885CB98(s32, u8, u16);

s32 func_0885E664(s32 arg0, u8 arg1, u16 arg2, s32 arg3) {
    s32 factors[4] = {2, 3, 8, 15};
    u32 n;

    if (arg1 != 6) {
        return 0;
    }
    if (arg3 < 0 || arg3 > 3) {
        return 0;
    }
    n = func_0885CB98(arg0, arg1, arg2);
    return n / 10 * factors[arg3];
}