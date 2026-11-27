/* unit_08816460: 0x08816460-0x08816508 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08816460 (ULES01213): reads one UTF-8 character from *arg1 and
 * advances the pointer; invalid lead bytes and characters rejected by
 * func_088167E0 become '?' (0x3F).
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern s32 func_088167E0(s32 arg0, u32 arg1);

u16 func_08816460(s32 arg0, u8 **arg1) {
    u8 *p;
    u32 c;
    u32 mask;

    p = *arg1;
    c = *p++;
    if (c < 0x80) {
        *arg1 = p;
    } else {
        if (c < 0xC2 || 0xF4 < c) {
            c = 0x3F;
        } else {
            mask = 0x40;
            c &= 0x7F;
            do {
                c &= mask - 1;
                c = (c << 6) | (*p & 0x3F);
                mask <<= 5;
                p++;
            } while (c >= mask);
        }
        *arg1 = p;
    }
    if ((u8)func_088167E0(arg0, c) == 0) {
        c = 0x3F;
    }
    return c;
}
