/* unit_0881629C: 0x0881629C-0x08816460 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881629C: decode one Shift-JIS character (hypothesis). */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

u16 func_0881629C(s32 arg0, u8 **arg1) {
    u8 *p;
    u32 c;
    s32 flag;
    s32 hi;
    s32 lo;
    u16 r;

    p = *arg1;
    c = *p++;
    if (c <= 0x7F || (c >= 0xA0 && c <= 0xDF) || c >= 0xFD) {
        r = (u8)c;
    } else {
        flag = 0;
        hi = 0;
        lo = 0;
        if (c >= 0x81 && c < 0xA0) {
            hi = ((u8)c - 0x81) * 2 + 1;
        } else if (c >= 0xE0 && c < 0xF0) {
            hi = ((u8)c - 0xE0) * 2 + 0x3F;
        } else if (c >= 0xF0 && c < 0xFD) {
            flag = 1;
            hi = ((u8)c - 0xF0) * 2 + 7;
            if ((s32)c >= 0xF4) {
                hi += 0x3E;
            }
        }
        if (hi != 0) {
            c = *p++;
            if (c >= 0x40 && c < 0x7F) {
                lo = c - 0x3F;
            } else if (c >= 0x80 && c < 0x9F) {
                lo = (u8)c - 0x40;
            } else if (c >= 0x9F && c < 0xFD) {
                lo = (u8)c - 0x9E;
                hi++;
            }
            if (flag) {
                if (hi == 7) {
                    hi = 1;
                } else if (hi == 11) {
                    hi = 5;
                } else if (hi == 0x4D) {
                    hi = 0xF;
                }
            }
        }
        if (hi == 0 || lo == 0) {
            r = 0x3F;
        } else {
            r = (lo + 0x20) | ((flag << 15) | ((hi + 0x20) << 8));
        }
    }
    *arg1 = p;
    return r;
}
