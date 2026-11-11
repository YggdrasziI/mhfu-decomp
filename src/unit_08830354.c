/* unit_08830354: 0x08830354-0x088303A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 colour lookup through two tables, between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 D_0893AF0C[];
extern u32 D_0893AECC[];

u32 func_08830354(void *unused, int a, int b, int c) {
    if ((u8)c) {
        a = (u8)(a + 10);
    }
    return ((u8)b << 24) | D_0893AECC[D_0893AF0C[(u8)a]];
}
