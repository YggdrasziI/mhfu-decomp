/* unit_08851FEC: 0x08851FEC-0x0885205C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern s32 func_0885187C(char *, s32, s32);
extern u8 *D_089B65DC[];

u8 func_08851FEC(char *arg0, s32 arg1) {
    u8 r = func_0885187C(arg0, arg1, 1);

    return D_089B65DC[*(u8 *)(arg0 + arg1 * 140 + 0x40)][r];
}
