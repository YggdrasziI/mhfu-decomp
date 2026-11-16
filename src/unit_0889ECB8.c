/* unit_0889ECB8: 0x0889ECB8-0x0889EE40 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_0889EC78 and unit_0889EE40.
 */

#include "unk_msg.h"

extern void func_088A6100(s32, s32, s32 *);

void func_0889ECB8(s32 arg0, s32 arg1, s32 *src) {
    s32 out[15];
    u32 flags;
    u32 bit;

    clear((char *) out, sizeof(out));
    flags = src[0];
    out[12] = 100;
    out[0] = flags;
    if (src != 0) {
        bit = 1;
        if (flags != 0) {
            do {
            switch (flags & bit) {
            case 1:
                out[1] = src[1];
                break;
            case 2:
                out[2] = src[2];
                break;
            case 4:
                out[3] = src[3];
                break;
            case 8:
                out[4] = src[4];
                break;
            case 0x40:
                out[7] = src[7];
                break;
            case 0x80:
                out[8] = src[8];
                break;
            case 0x100:
                out[9] = src[9];
                break;
            case 0x200:
                out[10] = src[10];
                break;
            case 0x10:
                out[5] = src[5];
                break;
            case 0x20:
                out[6] = src[6];
                break;
            case 0x800:
                out[12] = src[12];
                break;
            case 0x1000:
                out[13] = src[13];
                break;
            case 0x2000:
                out[14] = src[14];
                break;
            }
            flags &= ~bit;
            bit <<= 1;
            } while (flags != 0);
        }
    }
    func_088A6100(arg0, arg1, out);
}
