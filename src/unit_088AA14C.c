/* unit_088AA14C: 0x088AA14C-0x088AA368 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088AA0BC and unit_088AA368.
 *
 * func_088AA14C maps a negative system error code (the 0x8001xxxx and
 * 0x804xxxxx values returned by the sceNetInet / sceNetAdhoc calls of
 * func_088AA370) to a small negative code; other values pass through.
 * The case values are copied from the code; their meaning is not checked.
 */

typedef int s32;

extern void func_0880C464(void *, s32, s32);
extern s32 D_09A1D728;
extern char D_09A1D72C[];
extern char D_09A1D8AC[];

s32 func_088AA14C(s32 err) {
    if (err >= 0) {
        return err;
    }
    switch (err) {
    case 0:
        err = 0;
        break;
    case 0x80010077:
    case 0x80010078:
    case 0x8001000B:
    case 0x80410709:
        err = -1;
        break;
    case 0x80410710:
    case 0x8041070F:
        err = -2;
        break;
    case 0x80010009:
    case 0x80410707:
    case 0x80410701:
        err = -4;
        break;
    case 0x8001006F:
    case 0x80010068:
    case 0x80410718:
    case 0x8041070B:
    case 0x8041070C:
        err = -6;
        break;
    case 0x80010074:
    case 0x80410715:
        err = -0xB;
        break;
    case 0x80010069:
    case 0x8001000C:
    case 0x80400706:
        err = -0xC;
        break;
    case 0x80010004:
    case 0x80410719:
        err = -0xE;
        break;
    case 0x80010075:
    case 0x80010076:
    case 0x80010072:
        err = -7;
        break;
    case 0x8001006D:
        err = -0xD;
        break;
    default:
        err = -0x10;
        break;
    }
    return err;
}

s32 func_088AA304(s32 arg0) {
    if (arg0 != 0) {
        D_09A1D728 = 2;
    } else {
        D_09A1D728 = 1;
    }
    func_0880C464(D_09A1D8AC, 0xFF, 0x240);
    func_0880C464(D_09A1D72C, 0xFF, 0x180);
    return D_09A1D728;
}
