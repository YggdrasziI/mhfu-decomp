/* unit_08852F1C: 0x08852F1C-0x08852F58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed int s32;

s32 func_08852F1C(char *a0, u8 a1)
{
    u8 b;

    if (a1 >= 0x3E) {
        return 0;
    }
    b = ((u8 *)(a0 + 0x44AC))[a1 >> 3];
    return (b & (1 << (a1 & 7))) != 0;
}
