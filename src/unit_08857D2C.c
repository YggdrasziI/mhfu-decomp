/* unit_08857D2C: 0x08857D2C-0x08857D6C (ULES01213)
 *
 * Bounds (hypothesis): one function (clears a bit of a bit set) between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void func_08857D2C(char *o, u16 bit) {
    u32 b = bit;
    int *w = (int *)(o + 0x6A7B4) + (b >> 5);

    *w &= ~(1 << (b & 0x1F));
}
