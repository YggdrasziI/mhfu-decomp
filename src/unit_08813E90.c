/* unit_08813E90: 0x08813E90-0x08813F04 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_08813E70 and unit_08813F04.
 * Its jump table (0x08910928-0x08910968) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;

extern u8 *D_089CC438;

s32 func_08813E90(u8 *arg0) {
    u8 *p;

    if (D_089CC438[0x422] == 1) {
        return 1;
    }
    p = arg0 + 0x970;
    if (arg0[0xA0A] != 0) {
        return 1;
    }
    switch (p[0x4E]) {
    case 3:
    case 4:
    case 5:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
        return 1;
    case 6:
    case 7:
    case 8:
    case 9:
    default:
        return 0;
    }
}
