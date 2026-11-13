/* unit_088862A8: 0x088862A8-0x0888637C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern int func_08882C24(s32, s32, s32, s32);

void func_088862A8(char *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 var_v1;
    u16 temp_a1;

    temp_a0 = *(s32 *)(arg0 + 4);
    if (temp_a0 >= 0xF) {
        func_08882C24(D_08A62D8C, 0, arg1, 0x46);
        temp_a0_2 = *(s32 *)(arg0 + 0x14) | 0x400;
        var_v1 = temp_a0_2 & ~2;
        *(s32 *)(arg0 + 0x14) = temp_a0_2;
        *(s32 *)(arg0 + 0x14) = var_v1;
    } else if ((temp_a0 >= 4) || (temp_a1 = *(u16 *)(D_089CC438 + 0x6AF0E), (temp_a1 == 0x5B)) || ((temp_a1 == 0x59) && (*(u16 *)(arg0 + 8) == 0x19D4))) {
        func_08882C24(D_08A62D8C, 0, arg1, 0x32);
        temp_a0_3 = *(s32 *)(arg0 + 0x14) | 0x400;
        var_v1 = temp_a0_3 & ~2;
        *(s32 *)(arg0 + 0x14) = temp_a0_3;
        *(s32 *)(arg0 + 0x14) = var_v1;
    }
}
