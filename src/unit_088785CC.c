/* unit_088785CC: 0x088785CC-0x08878B60 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_08877EF0 and unit_08878B60.
 * Its jump table (0x0893182C-0x08931898) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;

extern int func_088571C8(char *o, int bit);
extern u16 func_08850520(char *, u8);
extern s32 func_088570D8(char *, s32);
extern s32 func_0884FE80(char *, s32);
extern u16 func_0884FF4C(char *, u8);

s32 func_088785CC(char *arg0, s32 arg1) {
    if (func_088571C8(D_089CC438, arg1) == 0) {
        switch (arg1) {
        case 0:
            if (*(u16 *)(D_089CC438 + 0x6AF12) == 0x277E) {
                return 1;
            }
            break;
        case 1:
            if (*(u16 *)(D_089CC438 + 0x6AF12) == 0x277F) {
                return 1;
            }
            break;
        case 2:
            if (*(u16 *)(D_089CC438 + 0x6AF12) == 0x27DB) {
                return 1;
            }
            break;
        case 3:
            if (*(u16 *)(D_089CC438 + 0x6AF12) == 0x27E2) {
                return 1;
            }
            break;
        case 4:
            if (*(u16 *)(D_089CC438 + 0x6AF12) == 0x283E) {
                return 1;
            }
            break;
        case 5:
            if (*(u16 *)(D_089CC438 + 0x6AF12) == 0x2840) {
                return 1;
            }
            break;
        case 6:
            if (*(u16 *)(D_089CC438 + 0x6AF12) == 0x28A1) {
                return 1;
            }
            break;
        case 7:
            if (*(u16 *)(D_089CC438 + 0x6AF12) == 0x28A6) {
                return 1;
            }
            break;
        case 8:
            if (*(u16 *)(D_089CC438 + 0x6AF12) == 0x28AB) {
                return 1;
            }
            break;
        case 9:
            if (*(u16 *)(D_089CC438 + 0x6AF12) == 0x28A2) {
                return 1;
            }
            break;
        case 10:
            if (func_08850520(D_089CC438, 0x8) > 0 && func_088570D8(D_089CC438, 0x5209) != 0 && func_088570D8(D_089CC438, 0x520A) != 0) {
                return 1;
            }
            break;
        case 11:
            if (func_08850520(D_089CC438, 0x15) > 0 && func_088570D8(D_089CC438, 0x520B) != 0 && func_088570D8(D_089CC438, 0x520C) != 0) {
                return 1;
            }
            break;
        case 12:
            if (func_08850520(D_089CC438, 0x43) > 0 && func_088570D8(D_089CC438, 0x520D) != 0 && func_088570D8(D_089CC438, 0x520E) != 0) {
                return 1;
            }
            break;
        case 13:
            if (func_08850520(D_089CC438, 0xB) > 0 && func_088570D8(D_089CC438, 0x520F) != 0 && func_088570D8(D_089CC438, 0x5210) != 0) {
                return 1;
            }
            break;
        case 14:
            if (func_08850520(D_089CC438, 0x35) > 0 && func_088570D8(D_089CC438, 0x5211) != 0 && func_088570D8(D_089CC438, 0x5212) != 0) {
                return 1;
            }
            break;
        case 15:
            if (func_0884FE80(D_089CC438, 0x3F7) != 0 && func_0884FF4C(D_089CC438, 0x8) > 4) {
                return 1;
            }
            break;
        case 16:
            if (func_0884FE80(D_089CC438, 0x4B9) != 0 && func_08850520(D_089CC438, 0x1) > 9) {
                return 1;
            }
            break;
        case 17:
            if (func_0884FE80(D_089CC438, 0x845) != 0 && func_08850520(D_089CC438, 0x43) > 4) {
                return 1;
            }
            break;
        case 18:
            if (func_0884FE80(D_089CC438, 0xC82) != 0 && func_0884FF4C(D_089CC438, 0x4B) > 9) {
                return 1;
            }
            break;
        case 19:
            if (func_0884FE80(D_089CC438, 0xBC1) != 0) {
                return 1;
            }
            break;
        case 20:
            if (func_0884FE80(D_089CC438, 0xBCC) != 0) {
                return 1;
            }
            break;
        case 21:
            if (func_0884FE80(D_089CC438, 0xBC4) != 0) {
                return 1;
            }
            break;
        case 22:
            if (func_0884FE80(D_089CC438, 0xC1F) != 0) {
                return 1;
            }
            break;
        case 23:
            if (func_0884FE80(D_089CC438, 0xC31) != 0) {
                return 1;
            }
            break;
        case 24:
            if (func_0884FE80(D_089CC438, 0xC22) != 0) {
                return 1;
            }
            break;
        case 25:
            if (func_0884FE80(D_089CC438, 0xC26) != 0) {
                return 1;
            }
            break;
        case 26:
            if (func_0884FE80(D_089CC438, 0xC8C) != 0) {
                return 1;
            }
            break;
        }
    }
    return 0;
}
