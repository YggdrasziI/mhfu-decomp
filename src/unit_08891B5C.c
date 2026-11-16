/* unit_08891B5C: 0x08891B5C-0x08891BC8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 D_089CBBE8;
extern s32 func_08816460(s32, s32);
extern s32 func_08894874(s32, s32);

s32 func_08891B5C(s32 arg0, u8 *arg1) {
    u8 *sp1C;

    if (arg1 == 0) {
        return 0;
    }
    if (*arg1 == 0) {
        return 0;
    }
    sp1C = arg1;
    if (func_08894874(arg0, func_08816460(D_089CBBE8, (s32) &sp1C) & 0xFFFF) != 0) {
        return 1;
    }
    return 2;
}
