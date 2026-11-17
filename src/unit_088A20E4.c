/* unit_088A20E4: 0x088A20E4-0x088A2204 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two matched units.
 * Its jump table (0x08931F20-0x08931F38) is linked from this unit.
 */

typedef int s32;

extern char D_09A0D25C;
extern s32 func_088A1E70(char *, s32, s32);
extern void func_088A177C(char *);
extern void func_088A178C(char *);
extern void func_088A17D8(char *);
extern void func_088A1814(char *);
extern void func_088A2244(char *);
extern void func_088A2410(void *);

s32 func_088A20E4(char *arg0, s32 arg1, s32 arg2) {
    switch (*(s32 *)(arg0 + 0x54)) {
    case 1:
    case 3:
    case 4:
        func_088A2244(arg0);
    case 0:
    case 5:
        if (func_088A1E70(arg0, arg1, arg2) < 0) {
            *(s32 *)(arg0 + 0x5C) = *(s32 *)(arg0 + 8);
            *(s32 *)(arg0 + 0x58) = 3;
            *(s32 *)(arg0 + 0x54) = 6;
            func_088A2410(arg0);
            return -1;
        }
        break;
    default:
        *(s32 *)(arg0 + 0x5C) = *(s32 *)(arg0 + 0x54);
        *(s32 *)(arg0 + 0x58) = 1;
        *(s32 *)(arg0 + 0x54) = 6;
        func_088A2410(arg0);
        return -1;
    case 2:
        break;
    }
    func_088A177C(&D_09A0D25C);
    if (*(s32 *)(arg0 + 0x44) == 1) {
        func_088A17D8(arg0);
    } else {
        func_088A1814(arg0);
    }
    func_088A178C(&D_09A0D25C);
    *(s32 *)(arg0 + 0x84) = 0;
    *(s32 *)(arg0 + 0x8C) = 0;
    *(s32 *)(arg0 + 0x54) = 3;
    return 0;
}
