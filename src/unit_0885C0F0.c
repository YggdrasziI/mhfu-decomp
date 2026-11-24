/* unit_0885C0F0: 0x0885C0F0-0x0885C124 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885C0F0: set bit arg1[6] in the flag array at D_089CC438 + 0x446C. */
typedef unsigned char u8;

extern char *D_089CC438;

void func_0885C0F0(void *arg0, u8 *arg1) {
    u8 n = arg1[6];
    ((u8 *)(D_089CC438 + 0x446C))[n >> 3] |= (u8)(1 << (n & 7));
}
