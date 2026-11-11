/* unit_08816900: 0x08816900-0x08816930 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_08816900(s32 arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg1 & 0xFFFF;
    if ((temp_v1 >= 0x61) && (temp_v1 < 0x7B)) {
        return 1;
    }
    return 0;
}
