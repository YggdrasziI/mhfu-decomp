/* unit_08894874: 0x08894874-0x08894988 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

s32 func_08894874(s32 arg0, s32 arg1) {
    u32 temp_v1;

    temp_v1 = arg1 & 0xFFFF;
    if (temp_v1 == 0x3035) {
        return 1;
    }
    if ((temp_v1 >= 0x250U) && (temp_v1 < 0x2000U)) {
        return 0;
    }
    if ((temp_v1 >= 0x2000U) && (temp_v1 < 0x2070U)) {
        return 1;
    }
    if ((temp_v1 >= 0x2070U) && (temp_v1 < 0x20A0U)) {
        return 0;
    }
    if ((temp_v1 >= 0x20A0U) && (temp_v1 < 0x20D0U)) {
        return 1;
    }
    if ((temp_v1 >= 0x20D0U) && (temp_v1 < 0xFF60U)) {
        return 0;
    }
    if ((temp_v1 >= 0xFF60U) && (temp_v1 < 0xFFE0U)) {
        return 2;
    }
    if ((temp_v1 >= 0xFFE0U) && (temp_v1 < 0xFFF0U)) {
        return 0;
    }
    return 1;
}
