/* unit_0889EC50: 0x0889EC50-0x0889EC78 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_088A6CC4(s32);

s32 func_0889EC50(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_088A6CC4(arg0);
    if (temp_v0 < 0) {
        return 0;
    }
    return temp_v0 != 0;
}
