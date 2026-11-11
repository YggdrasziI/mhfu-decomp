/* unit_088B3234: 0x088B3234-0x088B32A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern u8 D_09A28877;
extern int func_088B7A50(s32);

void func_088B3234(char *arg0) {
    s32 temp_v1;

    if (D_09A28877 != 0) {
        *(u8 *)(arg0 + 0x21) = (u8) (*(u8 *)(arg0 + 0x21) + 1);
        *(u8 *)(arg0 + 0x22) = 0;
        return;
    }
    temp_v1 = *(s32 *)(arg0 + 0xC) - 1;
    *(s32 *)(arg0 + 0xC) = temp_v1;
    if (temp_v1 < 0) {
        *(u8 *)(arg0 + 0x21) = 2U;
        *(u8 *)(arg0 + 0x22) = 0;
        func_088B7A50(6);
        *(u16 *)(arg0 + 0x26) = 0x8034;
    }
}
