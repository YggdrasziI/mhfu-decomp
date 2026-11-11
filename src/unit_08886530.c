/* unit_08886530: 0x08886530-0x08886568 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

void func_08886530(s32 arg0, s32 arg1) {
    char *temp_a0;

    temp_a0 = (char *) (arg0 + (arg1 * 0x18));
    *(s32 *)(temp_a0 + 4) = -1;
    *(s32 *)(temp_a0 + 8) = -1;
    *(s16 *)(temp_a0 + 0xC) = 0;
    *(s16 *)(temp_a0 + 0xE) = 0;
    *(s16 *)(temp_a0 + 0x10) = 0;
    *(s16 *)(temp_a0 + 0x12) = 0;
    *(s16 *)(temp_a0 + 0x14) = 0;
    *(s16 *)(temp_a0 + 0x16) = 0;
}
