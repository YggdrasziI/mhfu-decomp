/* unit_088952E4: 0x088952E4-0x08895538 (ULES01213)
 *
 * Bounds (hypothesis): 1 function, a membership test on an id.
 */

typedef int s32;
typedef unsigned short u16;

s32 func_088952E4(s32 arg0, u16 arg1) {
    s32 id = arg1;
    s32 ret;

    if (id >= 0xA0) {
        if (id < 0x200) {
            switch (id) {
            case 0xC0: case 0xC1: case 0xC2: case 0xC3: case 0xC4: case 0xC5:
            case 0xC6: case 0xC8: case 0xC9: case 0xCA: case 0xCB: case 0xCC:
            case 0xCD: case 0xCE: case 0xCF: case 0xD0: case 0xD1: case 0xD2:
            case 0xD3: case 0xD4: case 0xD5: case 0xD6: case 0xD8: case 0xD9:
            case 0xDA: case 0xDB: case 0xDC: case 0xDD: case 0x100: case 0x112:
            case 0x11A: case 0x128: case 0x12A: case 0x14C: case 0x160: case 0x168:
            case 0x16A: case 0x16E: case 0x178: case 0x17D: case 0x1CD: case 0x1CF:
            case 0x1D1: case 0x1D3:
                return 1;
            default:
                ret = 0;
                break;
            }
            return ret;
        }
    }
    return 0;
}
