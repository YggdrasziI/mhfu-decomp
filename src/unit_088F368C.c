/* unit_088F368C: 0x088F368C-0x088F383C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * A list of nine entries: the pad moves the cursor (+0xE) up and down, with a
 * sound for each move; the other buttons go to func_088F383C.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern s32 D_08A62D8C;
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088F383C(char *, u16, char *);
extern void func_088F6450(char *, char *, s8);

s32 func_088F368C(char *arg0, u16 arg1, char *arg2) {
    s32 ret;

    ret = 0;
    switch (*(s8 *)(arg0 + 0xD)) {
    case 0:
        *(s8 *)(arg0 + 0xE) = 0;
        *(s8 *)(arg0 + 0xA72C) = 0;
        *(s8 *)(arg0 + 0xD) = *(s8 *)(arg0 + 0xD) + 1;
    case 1:
        if (arg1 & 0x100) {
            *(s8 *)(arg0 + 0xE) = *(s8 *)(arg0 + 0xE) - 1;
            if (*(s8 *)(arg0 + 0xE) < 0) {
                *(s8 *)(arg0 + 0xE) = 8;
            }
            func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
            *(s8 *)(arg0 + 0x10) = 0;
            *(s8 *)(arg0 + 0x1E) = 0;
            *(s8 *)(arg0 + 0xF) = 0;
        } else if (arg1 & 0x200) {
            *(s8 *)(arg0 + 0xE) = *(s8 *)(arg0 + 0xE) + 1;
            if (*(s8 *)(arg0 + 0xE) > 8) {
                *(s8 *)(arg0 + 0xE) = 0;
            }
            func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
            *(s8 *)(arg0 + 0x10) = 0;
            *(s8 *)(arg0 + 0x1E) = 0;
            *(s8 *)(arg0 + 0xF) = 0;
        } else if (arg1 & 0x2000) {
            ret = 0x2000;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else {
            func_088F383C(arg0, arg1, arg2);
        }
        break;
    }
    func_088F6450(arg0, arg2, *(s8 *)(arg0 + 0xE));
    return ret | (arg1 & 8);
}
