/* unit_08886870: 0x08886870-0x08886898 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

void func_08886870(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    char *temp_a0;

    temp_a0 = (char *) (arg0 + (arg1 * 0x18));
    *(s16 *)(temp_a0 + 0x10) = (s16) *(s16 *)(temp_a0 + 0xC);
    *(s16 *)(temp_a0 + 0x12) = arg3;
    *(s16 *)(temp_a0 + 0x14) = arg2;
    *(s16 *)(temp_a0 + 0x16) = arg2;
}
