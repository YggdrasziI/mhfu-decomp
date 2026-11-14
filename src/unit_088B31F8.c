/* unit_088B31F8: 0x088B31F8-0x088B3234 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern u8 D_09A28876;

void func_088B31F8(char *arg0) {
    if (D_09A28876 != 0) {
        *(u8 *)(arg0 + 0x21) = (u8) (*(u8 *)(arg0 + 0x21) + 1);
        *(u8 *)(arg0 + 0x22) = 0U;
        return;
    }
    *(u8 *)(arg0 + 0x22) = (u8) (*(u8 *)(arg0 + 0x22) + 1);
    *(s32 *)(arg0 + 0xC) = 0x96;
}
