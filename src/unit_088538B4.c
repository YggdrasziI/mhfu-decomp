/* unit_088538B4: 0x088538B4-0x08853ABC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off
/* func_088538B4 */

typedef int s32;
typedef unsigned short u16;

extern s32 D_089CBBE8;
extern s32 func_08816900(s32, s32);

void func_088538B4(s32 arg0, u16 *dst, u16 *src, s32 n) {
    s32 i;

    for (i = 0; i <= n; i++) {
        *dst = *src;
        if (func_08816900(D_089CBBE8, *src) != 0) {
            *dst -= 0x20;
        }
        if (*src >= 0xE0 && *src < 0xF0) {
            *dst -= 0x20;
        }
        if (*src >= 0xF0 && *src < 0xF7) {
            *dst -= 0x20;
        }
        if (*src >= 0xF8 && *src < 0xFF) {
            *dst -= 0x20;
        }
        switch (*src) {
        case 0x101:
        case 0x113:
        case 0x11B:
        case 0x129:
        case 0x12B:
        case 0x142:
        case 0x14D:
        case 0x153:
        case 0x161:
        case 0x169:
        case 0x16B:
        case 0x16F:
        case 0x17E:
        case 0x1CE:
        case 0x1D0:
        case 0x1D2:
        case 0x1D4:
            dst--;
            break;
        case 0xFF:
            *dst = 0x178;
            break;
        case 0x131:
            *dst = 0x1C0;
            break;
        }
        dst++;
        src++;
    }
}
