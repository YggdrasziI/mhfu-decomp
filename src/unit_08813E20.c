/* unit_08813E20: 0x08813E20-0x08813E70 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_08813E10 and unit_08813E70.
 * Its jump table (0x089108C0-0x08910928) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;

s32 func_08813E20(u8 *arg0) {
    if (arg0[0x961] != 0) {
        switch (arg0[0x9BE]) {
        case 0x50:
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
        case 0x59:
        case 0x5A:
        case 0x5B:
        case 0x5C:
        case 0x5D:
        case 0x5E:
        case 0x5F:
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
        case 0x68:
        case 0x69:
            return 1;
        }
    }
    return 0;
}
