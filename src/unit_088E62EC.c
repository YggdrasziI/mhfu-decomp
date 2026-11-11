/* unit_088E62EC: 0x088E62EC-0x088E6310 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

void func_088E62EC(char *arg0) {
    char *temp_v1;

    temp_v1 = *(char **)(arg0 + 0x194);
    *(s32 *)(arg0 + 0xC4) = 0;
    *(s32 *)(arg0 + 0x7C) = 0;
    *(s32 *)(arg0 + 0x17C) = 0;
    *(s8 *)(temp_v1 + 0xC) = 0;
    *(s8 *)(temp_v1 + 0xD) = 0;
    *(s32 *)(temp_v1 + 0x14) = 0;
    *(s32 *)(temp_v1 + 0xA0) = 0;
}
