/* unit_08857C98: 0x08857C98-0x08857CF0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08857C98: tests a bit of the bit set at +0x6A7B4 (0xFFFF and
 * indices >= 0x4ED give 0). */

typedef int s32;
typedef unsigned short u16;
typedef unsigned int u32;

s32 func_08857C98(char *o, u16 bit) {
    s32 b = bit;
    s32 w;

    if (b == 0xFFFF || b >= 0x4ED) {
        return 0;
    }
    w = *((int *)(o + 0x6A7B4) + ((u32)b >> 5));
    return (w & (1 << (b & 0x1F))) != 0;
}
