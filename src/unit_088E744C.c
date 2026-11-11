/* unit_088E744C: 0x088E744C-0x088E7460 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

void func_088E744C(char *arg0) {
    char *temp_a1;

    temp_a1 = *(char **)(arg0 + 0x1A0);
    *(s8 *)(temp_a1 + 0x24) = 0;
    *(s32 *)(temp_a1 + 0x2C) = (s32) *(s32 *)(arg0 + 0x60);
}
