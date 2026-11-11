/* unit_0885205C: 0x0885205C-0x088520A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 byte table lookup, between unrelated code.
 */

typedef unsigned char u8;

extern u8 func_08851A68(void *p, int a);
extern u8 *D_089B65DC[];

u8 func_0885205C(char *p) {
    u8 r = func_08851A68(p, 1);

    return D_089B65DC[*(u8 *)(p + 0x4B3)][r];
}
