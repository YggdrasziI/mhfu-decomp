/* unit_0881CAC8: 0x0881CAC8-0x0881CB0C (ULES01213)
 *
 * Bounds (hypothesis): 1 reset (call, byte and flag clear), between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_08826FCC(void *p, int a, int b);

int func_0881CAC8(char *p) {
    func_08826FCC(p, *(int *)(p + 0x530), 0);
    *(u8 *)(p + 0x57F) = 0;
    *(u32 *)(p + 0x5E8) &= ~4;
    return 0;
}
