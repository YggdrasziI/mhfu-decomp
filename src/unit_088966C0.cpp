/* unit_088966C0: 0x088966C0-0x0889695C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly. Its jump
 * table (0x08931E00-0x08931E4C) is linked from this unit.
 *
 * C++: the two flag tests are bool comparisons (`sltu` kept).
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {

extern char *D_08A631A0;
extern char *D_089CC438;
extern char D_089B12A0[];
extern char D_089B1338[];
extern char D_089B1358[];
extern char D_089B1390[];
extern char D_089B13A8[];
extern char D_089B13C0[];
extern char D_089B13E8[];

extern u8 func_0884FA5C(char *, s32);
extern void func_0889695C(char *, char *);
extern void func_08896A50(char *, s32, s32, s32);
extern void func_08896AD4(char *);

s32 func_088966C0(char *arg0, u16 arg1) {
    if ((bool) (*(s32 *) (D_08A631A0 + 0xF7A57C) & 1) == 1) {
        return 0;
    }
    if ((bool) (*(s32 *) (D_089CC438 + 0x6AF14) & 0x100) == 0) {
        return 0;
    }
    if (func_0884FA5C(D_089CC438, 0) == 1) {
        return 0;
    }
    *(s8 *) (arg0 + 0x1113) = -1;
    switch (arg1) {
    case 0:
        func_0889695C(arg0, D_089B12A0);
        break;
    case 1:
        func_0889695C(arg0, D_089B1338);
        break;
    case 2:
        func_08896AD4(arg0);
        break;
    case 3:
        func_08896A50(arg0, 0x67, 1, 3);
        break;
    case 4:
        func_08896A50(arg0, 0x68, 1, 4);
        break;
    case 5:
        func_0889695C(arg0, D_089B13C0);
        break;
    case 6:
        func_08896A50(arg0, 0x77, 3, 3);
        break;
    case 7:
        func_0889695C(arg0, D_089B13E8);
        break;
    case 8:
        func_08896A50(arg0, 0x79, 3, 5);
        break;
    case 9:
        func_08896A50(arg0, 0x7A, 3, 6);
        break;
    case 12:
        func_0889695C(arg0, D_089B1390);
        break;
    case 13:
        func_08896A50(arg0, 0x6B, 1, 7);
        break;
    case 14:
        func_0889695C(arg0, D_089B13A8);
        break;
    case 15:
        func_0889695C(arg0, D_089B1358);
        break;
    case 16:
        func_08896A50(arg0, 0x84, 6, 2);
        break;
    case 17:
        func_08896A50(arg0, 0x90, 7, 10);
        break;
    case 18:
        func_08896A50(arg0, 0x91, 7, 11);
        break;
    default:
        return 0;
    }
    if (*(s8 *) (arg0 + 0x1113) >= 0) {
        *(s8 *) (arg0 + 0x1115) = 1;
        *(s8 *) (arg0 + 0x1112) = *(s8 *) (arg0 + 0x1113);
        return 1;
    }
    return 0;
}

}
