/* unit_088351F0: 0x088351F0-0x08835470 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 *
 * C++: flag tests keep their `sltu` (bool).
 */

typedef int s32;
typedef unsigned char u8;

extern "C" {

extern char *D_08A631A0;
extern char *D_08A62C60;
extern s32 D_08A62C6C;
extern s32 D_08A62D8C;
extern s32 *D_09B22D70;

extern void func_08835470(char *, s32);
extern void func_08835F7C(char *, s32);
extern void func_088375C8(char *, s32);
extern void func_088378A8(char *, s32);
extern void func_0883D0EC(char *);
extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_088351F0(char *arg0) {
    s32 *st = D_09B22D70;

    switch (st[0]) {
    case 0xC:
        if (*(u8 *)(D_08A62C60 + 0x74) != 1) {
            func_08835470(arg0, 0);
        }
        break;
    case 0:
        *(u8 *)(st + 2) = 0;
    case 0x16:
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1 && (D_08A62C6C & 0x100)) {
            if (*(s32 *)(arg0 + 0x528) & 0x2000) {
                *(s32 *)(arg0 + 0x528) &= ~0x2000;
                func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
            } else {
                *(s32 *)(arg0 + 0x528) |= 0x2000;
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            }
        }
        func_08835470(arg0, 0);
        func_08835F7C(arg0, 1);
        func_088378A8(arg0, 2);
        break;
    case 8:
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1 && (D_08A62C6C & 0x100)) {
            if (*(s32 *)(arg0 + 0x528) & 0x2000) {
                *(s32 *)(arg0 + 0x528) &= ~0x2000;
                func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
            } else {
                *(s32 *)(arg0 + 0x528) |= 0x2000;
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            }
        }
        func_08835470(arg0, 0);
        func_088375C8(arg0, 1);
        func_088378A8(arg0, 2);
        break;
    case 0x14:
        func_08835470(arg0, 0);
        func_08835F7C(arg0, 1);
        func_088378A8(arg0, 2);
        break;
    }
    func_0883D0EC(arg0);
}

}
