/* unit_0889560C: 0x0889560C-0x08895644 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_0889560C(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg1 & 0xFF;
    if ((temp_v0 < 4) && (*(s32 *)((arg0 + (temp_v0 * 4))) != 0)) {
        return 1;
    }
    return 0;
}
