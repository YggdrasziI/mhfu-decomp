/* unit_088E9048: 0x088E9048-0x088E9060 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

void func_088E9048(char *arg0) {
    char *temp_a1;

    temp_a1 = *(char **)(arg0 + 0x1A0);
    *(s32 *)(temp_a1 + 0x2C) = (s32) *(s32 *)(arg0 + 0x114);
    *(s32 *)(temp_a1 + 0x30) = (s32) *(s32 *)(arg0 + 0x60);
}
