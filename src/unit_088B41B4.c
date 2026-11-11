/* unit_088B41B4: 0x088B41B4-0x088B41E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

void func_088B41B4(char *arg0) {
    s32 temp_v1;

    temp_v1 = *(s32 *)(arg0 + 0xC) - 1;
    *(s32 *)(arg0 + 0xC) = temp_v1;
    if (temp_v1 < 0) {
        *(u8 *)(arg0 + 0x21) = (u8) (*(u8 *)(arg0 + 0x21) + 1);
        *(s8 *)(arg0 + 0x22) = 0;
        *(s8 *)(arg0 + 0x23) = 0;
    }
}
