/* unit_08813B3C: 0x08813B3C-0x08813C8C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern s32 func_08813C8C(char *arg0);
extern void func_08813DAC(char *arg0);
extern void func_08813560(char *arg0, s8 arg1, char *arg2, s8 arg3);

void func_08813B3C(char *arg0, char *arg1) {
    s8 k;

    if ((u8)func_08813C8C(arg0) == 1) {
        func_08813DAC(arg0);
    }
    switch (*(u8 *)(arg1 + 0x1E8)) {
    case 0x07:
    case 0x32:
        k = 0xB;
        break;
    case 0x02:
    case 0x24:
    case 0x47:
        if (*(u8 *)(arg1 + 0x280) != 2) {
            k = 0xC;
        } else {
            k = 0xD;
        }
        break;
    case 0x37:
        k = 0xE;
        break;
    case 0x36:
    case 0x3C:
        k = 0xF;
        break;
    case 0x40:
    case 0x41:
        k = 0x11;
        break;
    case 0x3B:
        k = 0x10;
        break;
    case 0x4C:
    case 0x58:
        k = 0x12;
        break;
    default:
        return;
    }
    func_08813560(arg0, k, arg1, 0);
}
