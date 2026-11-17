/* unit_08835098: 0x08835098-0x088351F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x08930FA8-0x08930FDC) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern s32 func_0881CB2C(char *arg0, s32 arg1);
extern s32 func_0881DB5C(char *arg0, s32 arg1);
extern s32 func_0881E92C(char *arg0, s32 arg1);
extern s32 func_0881EAF8(char *arg0, s32 arg1);
extern s32 func_0881EB60(char *arg0, s32 arg1);
extern s32 func_0881EC2C(char *arg0, s32 arg1);
extern s32 func_08839688(char *arg0, s32 arg1);
extern s32 func_08839B30(char *arg0, s32 arg1);
extern s32 func_0883A8A4(char *arg0, s32 arg1);
extern s32 func_0883B190(char *arg0, s32 arg1);
extern s32 func_0883BB10(char *arg0, s32 arg1);
extern s32 func_0883BA38(s32, s32);
extern s32 func_088DCEBC(s32, u8);
extern void func_088D8900(s32);

u16 func_08835098(char *arg0, u8 arg1, s32 arg2) {
    u16 ret = arg2;

    switch (arg1) {
    case 0:
        ret = func_0881CB2C(arg0, arg2);
        func_088D8900(func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)));
        break;
    case 1:
        ret = func_0881DB5C(arg0, arg2);
        func_088D8900(func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)));
        break;
    case 9:
        ret = func_0881E92C(arg0, arg2);
        break;
    case 2:
        ret = func_0881EAF8(arg0, arg2);
        break;
    case 7:
        ret = func_0881EB60(arg0, arg2);
        break;
    case 8:
        ret = func_0881EC2C(arg0, arg2);
        break;
    case 5:
        ret = func_08839688(arg0, arg2);
        break;
    case 10:
        ret = func_08839B30(arg0, arg2);
        break;
    case 12:
        ret = func_0883B190(arg0, arg2);
        break;
    case 4:
        ret = func_0883A8A4(arg0, arg2);
        break;
    case 3:
        ret = func_0883BA38((s32) arg0, arg2);
        break;
    case 11:
        ret = arg2;
        break;
    case 6:
        ret = func_0883BB10(arg0, arg2);
        break;
    }
    return ret;
}
