/* unit_08857CF0: 0x08857CF0-0x08857D2C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08857CF0: sets a bit of a bit set. */

typedef unsigned short u16;
typedef unsigned int u32;

void func_08857CF0(char *o, u16 bit) {
    u32 b = bit;
    int *w = (int *)(o + 0x6A7B4) + (b >> 5);

    *w |= 1 << (b & 0x1F);
}
