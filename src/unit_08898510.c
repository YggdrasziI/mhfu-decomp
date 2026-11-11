/* unit_08898510: 0x08898510-0x08898540 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62C40;
extern s32 D_08A631A0;
extern s32 D_09A0B540;

s32 func_08898510(s32 arg0) {
    D_08A62C40 = arg0;
    return arg0;
}

s32 func_08898520(s32 arg0) {
    D_08A631A0 = arg0;
    return arg0;
}

s32 func_08898530(s32 arg0) {
    D_09A0B540 = arg0;
    return arg0;
}
