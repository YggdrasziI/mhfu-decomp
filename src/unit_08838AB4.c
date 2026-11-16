/* unit_08838AB4: 0x08838AB4-0x08838B08 (ULES01213)
 *
 * Bounds (hypothesis): 1 function, func_08838894 before it and func_08838B08 after it are
 * still in assembly.
 * Its jump table (0x089310F0-0x08931124) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;

s32 func_08838AB4(s32 arg0, u8 arg1, u8 arg2) {
    if (arg1 != 0) {
        return 0;
    }
    switch (arg2) {
    case 15:
    case 16:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        return 1;
    case 17:
    default:
        return 0;
    }
}
