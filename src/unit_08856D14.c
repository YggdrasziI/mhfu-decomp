/* unit_08856D14: 0x08856D14-0x08856D60 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

s32 func_08856D14(s32 arg0, u8 arg1) {
    s32 r;

    switch (arg1) {
    case 0:
        r = 0;
        break;
    case 2:
        r = 1;
        break;
    case 3:
        r = 2;
        break;
    case 4:
        r = 3;
        break;
    case 5:
        r = 4;
        break;
    default:
        r = 5;
        break;
    }
    return r;
}
