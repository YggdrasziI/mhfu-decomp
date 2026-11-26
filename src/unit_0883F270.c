/* unit_0883F270: 0x0883F270-0x0883F8B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * The 0x400 branch is one `&&` guard followed by a shared `return;`: that
 * nested-if-then-return shape keeps, for the whole function, the dead copies
 * of branch-likely slot instructions after each `b` and the unfilled `b`
 * slots of the original. func_088476F4 takes the object pointer read from
 * arg0 + 0x530 as its second argument (it reads $a1).
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_09A4F06C;
extern u8 *D_089CC438;
extern u8 *D_08A631A0;
extern u8 *D_089CBBE4;
extern s32 D_08A62D8C;

extern u8 func_0884FA5C(u8 *, s32);
extern void func_08828884(u8 *);
extern void func_08823A50(u8 *);
extern void func_0884A72C(u8 *);
extern void func_0884A958(u8 *);
extern u8 func_08865CB8(u8 *, s32, s32);
extern u16 func_0884FB6C(u8 *);
extern u8 func_0882693C(u8 *, u16);
extern u8 func_0883F988(u8 *, u8 *);
extern void func_0883F8B4(u8 *);
extern u8 func_088567B4(u8 *);
extern void func_088567C8(u8 *);
extern void func_0885683C(u8 *);
extern s32 func_08895FFC(u8 *, u16);
extern s32 func_08828938(u8 *, u16);
extern void func_08848D30(u8 *);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088476F4(u8 *, u8 *);
extern void func_08848630(u8 *);
extern void func_08848E04(u8 *, u16);
extern void func_0882A168(u8 *);
extern void func_08825D38(u8 *);
extern void func_08849404(u8 *);
extern void func_0883F9F8(u8 *);
extern void func_0883FAD4(u8 *);
extern void func_0883FD44(u8 *);
extern s32 func_08813E18(u8 *);

void func_0883F270(u8 *arg0) {
    u16 btn;
    u8 v;
    u8 *p;

    if (*(s32 *)(D_09A4F06C + 0x88) != 0) {
        return;
    }
    if (func_0884FA5C(D_089CC438, 1) == 1) {
        func_08828884(arg0);
        arg0[0x52D] = 0;
        arg0[0x52E] = 0;
        arg0[0x52F] = 0;
        arg0[0x57C] = 0;
        D_089CC438[0x10] = 0;
        arg0[0x604] = 0;
        func_08823A50(arg0);
        func_0884A72C(arg0);
        func_0884A958(arg0);
        return;
    }
    if (*(s32 *)(arg0 + 0x528) & 0x400) {
        func_08823A50(arg0);
        if (func_08865CB8(*(u8 **)(arg0 + 0x530), 0, 0x73) == 0 &&
            func_08865CB8(*(u8 **)(arg0 + 0x530), 0, 0x4E) == 0 &&
            func_08865CB8(*(u8 **)(arg0 + 0x530), 5, 0xC) == 0) {
            *(s32 *)(arg0 + 0x528) &= ~0x400;
        }
        return;
    }

    btn = func_0884FB6C(D_089CC438);
    if (*(s32 *)(arg0 + 0x528) & 0x20) {
        btn &= 0xFFFE;
    }

    switch (*(u8 *)(arg0 + 0x52C)) {
    case 0:
        arg0[0x52C]++;
        D_089CC438[0x10] = 0;
        *(s16 *)(arg0 + 0x560) = *(s16 *)(*(u8 **)(arg0 + 0x530) + 0x2E4);
        *(s16 *)(arg0 + 0x562) = *(s16 *)(*(u8 **)(arg0 + 0x530) + 0x41C);
        break;
    case 1:
        if (*(s16 *)(arg0 + 0x560) != *(s16 *)(*(u8 **)(arg0 + 0x530) + 0x2E4)) {
            if (*(s16 *)(arg0 + 0x560) < *(s16 *)(*(u8 **)(arg0 + 0x530) + 0x2E4)) {
                (*(s16 *)(arg0 + 0x560))++;
            } else {
                (*(s16 *)(arg0 + 0x560))--;
            }
        }
        *(s16 *)(arg0 + 0x562) = *(s16 *)(*(u8 **)(arg0 + 0x530) + 0x41C);
        *(s32 *)(arg0 + 0x528) &= ~2;
        if (*(u16 *)(arg0 + 0x596) != *(u16 *)(*(u8 **)(arg0 + 0x530) + 0x648)) {
            *(u16 *)(arg0 + 0x596) = *(u16 *)(*(u8 **)(arg0 + 0x530) + 0x648);
            if (func_0882693C(arg0, *(u16 *)(*(u8 **)(arg0 + 0x530) + 0x648)) == 1) {
                arg0[0x598] = 2;
                if (*(u8 *)(*(u8 **)(arg0 + 0x530) + 0x674) & 4) {
                    *(s8 *)(arg0 + 0x599) = -1;
                } else {
                    *(s8 *)(arg0 + 0x599) = 1;
                }
            }
        }
        if (*(u8 *)(*(u8 **)(arg0 + 0x530) + 0x5F3) == 1) {
            if (*(u16 *)(arg0 + 0x59C) != *(u8 *)(*(u8 **)(arg0 + 0x530) + 0x686)) {
                *(u16 *)(arg0 + 0x59C) = *(u8 *)(*(u8 **)(arg0 + 0x530) + 0x686);
                if (*(u8 *)(*(u8 **)(arg0 + 0x530) + 0x686) != 0xFF) {
                    arg0[0x59A] = 2;
                    if (*(u8 *)(*(u8 **)(arg0 + 0x530) + 0x674) & 0x10) {
                        *(s8 *)(arg0 + 0x59B) = -1;
                    } else {
                        *(s8 *)(arg0 + 0x59B) = 1;
                    }
                }
            }
        }
        *(s32 *)(arg0 + 0x528) &= ~1;
        if (func_0883F988(arg0, *(u8 **)(arg0 + 0x530)) == 1) {
            if (*(s8 *)(arg0 + 0x579) >= 4) {
                *(s32 *)(arg0 + 0x528) |= 1;
            }
            if (*(s8 *)(arg0 + 0x579) != 0) {
                (*(s8 *)(arg0 + 0x579))--;
            }
        } else {
            *(s8 *)(arg0 + 0x579) = 4;
        }
        arg0[0x5DB] = 0;
        if ((s32)((*(s32 *)(*(u8 **)(arg0 + 0x530) + 0x614) & 1) != 0) == 0) {
            arg0[0x5DB] = arg0[0x5DC];
        }
        if (*(u8 *)(arg0 + 0x577) != 0) {
            (*(u8 *)(arg0 + 0x577))--;
        }
        func_0883F8B4(arg0);
        if (*(s16 *)(arg0 + 0x59E) > 0) {
            (*(s16 *)(arg0 + 0x59E))--;
        }
        if (*(u8 *)(arg0 + 0x5A1) > 0) {
            (*(u8 *)(arg0 + 0x5A1))--;
        }

        v = D_089CC438[0x2A];
        if ((v & 0xF0) == 0) {
            if (v & 1) {
                if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0 &&
                    func_0884FA5C(D_089CC438, 0) == 0 && func_088567B4(D_089CC438) == 0) {
                    func_088567C8(D_089CC438);
                    D_089CC438[0x2A] |= 0x10;
                    arg0[0x11AB] = 1;
                    return;
                }
                if (func_088567B4(D_089CC438) == 0) {
                    D_089CC438[0x2A] = 0;
                }
            }
            if (func_08895FFC(arg0, btn) != 0) {
                break;
            }
            if (func_08828938(arg0, btn) == 0) {
                switch (*(u8 *)(arg0 + 0x52D)) {
                case 0:
                    p = *(u8 **)(arg0 + 0x530);
                    if (p[0x552] == 0 && (btn & 8)) {
                        func_08848D30(arg0);
                        func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
                        break;
                    }
                    if (arg0[0x52E] != 0) {
                        func_088476F4(arg0, p);
                    } else if (arg0[0x554] != 0) {
                        func_08848630(arg0);
                    }
                    arg0[0x52E] = (*(s32 *)(*(u8 **)(arg0 + 0x530) + 0x614) & 2) != 0;
                    arg0[0x554] = (*(s32 *)(*(u8 **)(arg0 + 0x530) + 0x614) & 0x200) != 0;
                    break;
                case 1:
                    func_08848E04(arg0, btn);
                    break;
                }
            }
            func_0882A168(arg0);
        } else {
            if ((v & 0xF) == 0 && (btn & 0x6008)) {
                func_0885683C(D_089CC438);
                D_089CC438[0x2A] = 0;
                arg0[0x11AB] = 0;
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            }
            func_0882A168(arg0);
        }
        break;
    }

    func_08825D38(arg0);
    func_08849404(arg0);
    func_0883F9F8(arg0);
    func_0883FAD4(arg0);
    func_0883FD44(arg0);
    if (func_08813E18(D_089CBBE4) != 0) {
        *(s32 *)(arg0 + 0x528) |= 0x20;
    } else {
        *(s32 *)(arg0 + 0x528) &= ~0x20;
    }
    func_08823A50(arg0);
}
