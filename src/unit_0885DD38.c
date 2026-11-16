/* unit_0885DD38: 0x0885DD38-0x0885DD9C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x08931584-0x089315A0) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;

extern s32 func_0885EBC8(s32, u8 *);
extern s32 func_0885ECF4(s32, u8 *);

s32 func_0885DD38(s32 arg0, u8 *arg1) {
    s32 ret;

    switch (arg1[1]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        ret = func_0885EBC8(arg0, arg1);
        break;
    case 5:
    case 6:
        ret = func_0885ECF4(arg0, arg1);
        break;
    default:
        return 0;
    }
    return ret;
}
