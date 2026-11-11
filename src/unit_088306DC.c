/* unit_088306DC: 0x088306DC-0x08830728 (ULES01213)
 *
 * Bounds (hypothesis): 1 reset (bytes, clear, copy), between unrelated code.
 */

typedef unsigned char u8;

extern void func_0880C464(void *p, int v, int n);
extern void func_08859AE4(void *a, void *b, int n);

void func_088306DC(char *p) {
    *(u8 *)(p + 0x10F8) = 0;
    *(u8 *)(p + 0x10F9) = 0;
    *(u8 *)(p + 0x10FA) = 0;
    func_0880C464(p + 0xE28, 0, 0x2D0);
    func_08859AE4(p + 0x500, p, 0x500);
}
