/* unit_088B30CC: 0x088B30CC-0x088B3118 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

void func_088B30CC(char *arg0) {
    s32 temp_v1;
    s32 temp_v1_2;

    temp_v1 = *(s32 *)(arg0 + 0xC) - 1;
    *(s32 *)(arg0 + 0xC) = temp_v1;
    if (temp_v1 < 0) {
        temp_v1_2 = *(s32 *)(arg0 + 0x14) - 1;
        *(s32 *)(arg0 + 0x14) = temp_v1_2;
        if (temp_v1_2 <= 0) {
            *(u8 *)(arg0 + 0x21) = (u8) (*(u8 *)(arg0 + 0x21) + 1);
            *(s8 *)(arg0 + 0x22) = 0;
            return;
        }
        *(s8 *)(arg0 + 0x22) = 4;
        *(s32 *)(arg0 + 0xC) = 5;
    }
}
