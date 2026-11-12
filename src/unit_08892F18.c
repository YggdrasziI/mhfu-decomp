/* unit_08892F18: 0x08892F18-0x08892F88 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_08A631B8;
extern s32 D_08A8B1E0;
extern s32 D_08A8B1E4;
extern s32 func_08859B44(s32, s32, s32);

s32 func_08892F18(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_a1;

    var_a1 = arg1;
    if (var_a1 == 0) {
        var_a1 = 4;
    }
    temp_v0 = func_08859B44((s32) &D_08A631B8, var_a1, 4);
    if (temp_v0 == 0) {
        return 0;
    }
    temp_a0 = D_08A8B1E0 + (*(s32 *)(temp_v0 + -0x10) * 0x10);
    D_08A8B1E0 = temp_a0;
    if (D_08A8B1E4 < temp_a0) {
        D_08A8B1E4 = temp_a0;
    }
    return temp_v0;
}
