/* unit_0885B718: 0x0885B718-0x0885B7D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885B718: returns 1 when the bit selected by byte 6 of arg1 is set
 * in the bit table at 0x446C of D_089CC438; when bit 0 of arg2 is clear,
 * func_0885B160 must first return 1.
 */

typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern char *func_088DCEBC(s32, u8);
extern u8 func_0885B160(s32, char *, u8 *, s32);

s32 func_0885B718(s32 a0, u8 *a1, s32 a2, s32 a3)
{
    u8 b;

    if ((a2 & 1) == 0) {
        if (func_0885B160(a0, func_088DCEBC(D_09A4F0C4, D_089CC438[0x28]), a1, a3) != 1) {
            return 0;
        }
    }
    b = D_089CC438[(a1[6] >> 3) + 0x446C];
    if ((b & (1 << (a1[6] & 7))) == 0) {
        return 0;
    }
    return 1;
}
