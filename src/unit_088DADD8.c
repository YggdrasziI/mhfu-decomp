/* unit_088DADD8: 0x088DADD8-0x088DAE98 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088DAD58, still in assembly
 * (text_088DAD58), and unit_088DAE98.
 *
 * Returns the 16-bit value at +0x420, times 1.05 when func_088D6A54 holds
 * for 0x24 and the byte at +0x5F3 is 1.
 *
 * Optimized for speed (float constant as an immediate).
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern s32 func_088D6A54(char *, u8);

s32 func_088DADD8(char *arg0) {
    u32 v = *(u16 *)(arg0 + 0x420);

    if (func_088D6A54(arg0, 0x24) != 0) {
        if (*(u8 *)(arg0 + 0x5F3) == 1) {
            v = (u16) (u32) (1.05f * (float) v);
        }
    }
    return v;
}
