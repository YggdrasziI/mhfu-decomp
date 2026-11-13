/* unit_08816930: 0x08816930-0x088169FC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_08816930(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_v1;

    temp_a0 = arg1 & 0xFF;
    if (temp_a0 == 0) {
        return 0;
    }
    temp_v1 = temp_a0 & 0x80;
    if (temp_v1 == 0) {
        return 1;
    }
    if ((temp_v1 != 0) && (temp_a0 & 0x40) && !(temp_a0 & 0x20)) {
        return 2;
    }
    if ((temp_v1 != 0) && (temp_a0 & 0x40) && (temp_a0 & 0x20) && !(temp_a0 & 0x10)) {
        return 3;
    }
    if ((temp_v1 != 0) && (temp_a0 & 0x40) && (temp_a0 & 0x20) && (temp_a0 & 0x10) && !(temp_a0 & 8)) {
        return 4;
    }
    return 0;
}
