/* unit_0881ECDC: 0x0881ECDC-0x0881ED64 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern "C" {
extern char *D_089CC438;
extern s32 D_09B22D70;
s32 func_09A7BFA8(s32);

s32 func_0881ECDC(char *arg0)
{
    if ((bool)(*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 1 && (u8)func_09A7BFA8(D_09B22D70) == 0) {
        *(s32 *)(arg0 + 0x528) &= ~0x40;
        return 0;
    }
    *(s32 *)(arg0 + 0x528) |= 0x40;
    return 1;
}
}
