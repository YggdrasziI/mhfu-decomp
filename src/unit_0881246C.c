/* unit_0881246C: 0x0881246C-0x088124D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Clears the bit of an offset (in 0x400-byte pages from a base returned by
 * func_08812610) in the bitmap at +0xC58.
 */

typedef int s32;
typedef unsigned int u32;

extern s32 func_08812610(char *, s32);

void func_0881246C(char *arg0, u32 arg1) {
    s32 base;
    u32 off;

    base = func_08812610(arg0, 0x2D);
    if (base != -1) {
        off = arg1 - base;
        ((u32 *)(arg0 + 0xC58))[off >> 15] &= ~(1 << ((off >> 10) & 0x1F));
    }
}
