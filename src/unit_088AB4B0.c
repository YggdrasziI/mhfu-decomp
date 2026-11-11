/* unit_088AB4B0: 0x088AB4B0-0x088AB4DC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

void func_088AB4B0(s32 arg0, char *arg1) {
    s32 temp_a0;

    temp_a0 = (1 << (arg0 & 0xFF)) & 0xFF;
    *(u8 *)(arg1 + 0x171) = (u8) (*(u8 *)(arg1 + 0x171) | temp_a0);
    *(u8 *)(arg1 + 0x172) = (u8) (*(u8 *)(arg1 + 0x172) | temp_a0);
}
