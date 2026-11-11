/* unit_08865A9C: 0x08865A9C-0x08865ADC (ULES01213)
 *
 * Bounds (hypothesis): one function (clears flags in one of two words, chosen by bit 31) between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void func_08865A9C(char *o, u32 v) {
    if (!(v & 0x80000000)) {
        *(u32 *)(o + 0x288) &= ~v;
    } else {
        *(u32 *)(o + 0x28C) &= ~((v << 1) >> 1);
    }
}
