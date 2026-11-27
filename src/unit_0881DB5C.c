/* unit_0881DB5C: 0x0881DB5C-0x0881E8F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881DB5C: 0x0881DB5C-0x0881E8F8 (ULES01213)
 *
 * State machine on the byte at 0x5B8 (7 states, jump table jtbl_089309A0)
 * returning the pad mask with the consumed bits cleared. Default (size)
 * setting, C.
 *
 * Owns two jump tables: jtbl_089309A0 (0x089309A0, 0x1C bytes, outer
 * switch) and jtbl_08930984 (0x08930984, 0x1C bytes, switch on the s16
 * result of func_08831FF8, cases -1..5).
 *
 * The pad is an s32 parameter masked at each use; the returned copy is a
 * u16 initialised at its declaration, after the table call, so that its
 * mask is not shared with the later tests.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Pair {
    u16 a;
    u16 b;
} Pair;

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern char *D_08A62C50;
extern s32 D_08A62C74;
extern char *D_08A62D90;

extern Pair *func_08856884(char *, s32);
extern void func_0881C520(char *, s32, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088292AC(char *, s32);
extern void func_0881C098(char *, u8 *, s32, s32);
extern s32 func_088286E4(char *, u8, u16);
extern s32 func_08828784(char *, u8, u8);
extern s32 func_0881C2E4(char *, u8 *, s32, u8);
extern u8 func_08857558(char *, u16);
extern s32 func_0885B7D0(char *, s32, s32);
extern s32 func_088569F8(char *, s32);
extern void func_08829EEC(char *, s32);
extern s16 func_0885B82C(char *, char *, char *, s16, s16, s32);
extern void func_08826688(char *);
extern void func_0885C0F0(char *, s32);
extern s32 func_08831FF8(char *, char *, u16, s32, s32, u8);
extern void func_088860A0(char *, u16);
extern void func_08885E3C(char *, s16);
extern u8 func_08830728(char *, s8, s16, s16);
extern s32 func_0885B5B8(char *, s32, s32, s32, s32, s32);

u16 func_0881DB5C(char *arg0, s32 pad)
{
    char *work = *(char **)(arg0 + 0x530);
    Pair *tbl = func_08856884(D_089CC438, 0);
    u16 ret = pad;
    u16 p;
    u32 i;
    s16 r;

    if (*(u8 *)(arg0 + 0x586) >= 0x18) {
        *(u8 *)(arg0 + 0x586) = 0;
    }
    switch (*(u8 *)(arg0 + 0x5B8)) {
    case 0:
        *(s32 *)(arg0 + 0x5E8) &= ~4;
        if (*(s32 *)(arg0 + 0x528) & 0x10) {
            ret &= ~0x2000;
            func_0881C520(arg0, pad, 0xA0);
            if ((u16)pad & 0x2000) {
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            } else if (!((u16)pad & 0x4000)) {
                *(s32 *)(arg0 + 0x5E8) |= 4;
                *(s16 *)(arg0 + 0x5FC) = 6;
                break;
            } else if (*(u8 *)(arg0 + 0x537) == 0) {
                func_088292AC(arg0, 0);
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                *(u8 *)(arg0 + 0x586) = 0;
            } else {
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            }
            *(s32 *)(arg0 + 0x528) &= ~0x10;
        } else {
            p = (u16)pad;
            if (p & 1) {
                *(s32 *)(arg0 + 0x528) |= 0x10;
                *(u8 *)(arg0 + 0x537) = 0;
                *(s32 *)(arg0 + 0x5E8) |= 4;
                *(s16 *)(arg0 + 0x5FC) = 6;
                func_08883988(D_08A62D8C, 0, 0xF, 0, 0, 0, 0, 0, 0);
            } else if (!(p & 0x2000)) {
                func_0881C098(arg0, (u8 *)(arg0 + 0x586), pad, 0x18);
                if (p & 0x4000) {
                    if ((u8)func_088286E4(arg0, *(u8 *)(arg0 + 0x586), tbl[*(u8 *)(arg0 + 0x586)].a) == 1) {
                        *(u8 *)(arg0 + 0x5B0) = *(u8 *)(arg0 + 0x586);
                        *(u16 *)(arg0 + 0x5AC) = tbl[*(u8 *)(arg0 + 0x5B0)].a;
                        *(u16 *)(arg0 + 0x5AE) = 0xFFFF;
                        *(u8 *)(arg0 + 0x5B8) += 1;
                        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                    } else {
                        func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                    }
                }
            }
        }
        break;
    case 1:
        *(s32 *)(arg0 + 0x5E8) &= ~4;
        ret &= ~0x2000;
        if (*(s32 *)(arg0 + 0x528) & 0x10) {
            func_0881C520(arg0, pad, 0xA0);
            if ((u16)pad & 0x2000) {
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            } else if (!((u16)pad & 0x4000)) {
                *(s32 *)(arg0 + 0x5E8) |= 4;
                *(s16 *)(arg0 + 0x5FC) = 6;
                break;
            } else if (*(u8 *)(arg0 + 0x537) == 0) {
                func_088292AC(arg0, 0);
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                *(u8 *)(arg0 + 0x586) = 0;
                i = 0;
                do {
                    if (*(u16 *)(arg0 + 0x5AC) == func_08856884(D_089CC438, i)->a) {
                        *(u8 *)(arg0 + 0x5B0) = i;
                        break;
                    }
                    if (i == 0x17) {
                        *(u8 *)(arg0 + 0x5B0) = 0xFF;
                        *(u16 *)(arg0 + 0x5AC) = 0xFFFF;
                        *(u8 *)(arg0 + 0x5B8) = 0;
                    }
                    i++;
                } while (i < 0x18);
            } else {
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            }
            *(s32 *)(arg0 + 0x528) &= ~0x10;
        } else {
            p = (u16)pad;
            if (p & 1) {
                *(s32 *)(arg0 + 0x528) |= 0x10;
                *(u8 *)(arg0 + 0x537) = 0;
                *(s32 *)(arg0 + 0x5E8) |= 4;
                *(s16 *)(arg0 + 0x5FC) = 6;
                func_08883988(D_08A62D8C, 0, 0xF, 0, 0, 0, 0, 0, 0);
            } else if ((u8)func_088286E4(arg0, *(u8 *)(arg0 + 0x5B0), *(u16 *)(arg0 + 0x5AC)) == 1) {
                func_0881C098(arg0, (u8 *)(arg0 + 0x586), pad, 0x18);
                if (p & 0x2000) {
                    func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
                    goto reset;
                } else if (p & 0x4000) {
                    if ((u8)func_08828784(arg0, *(u8 *)(arg0 + 0x586), *(u8 *)(arg0 + 0x5B0)) == 1) {
                        *(u8 *)(arg0 + 0x5B1) = *(u8 *)(arg0 + 0x586);
                        *(u16 *)(arg0 + 0x5AE) = tbl[*(u8 *)(arg0 + 0x5B1)].a;
                        *(u8 *)(arg0 + 0x5B9) = 0;
                        *(u8 *)(arg0 + 0x5B8) += 1;
                        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                    } else {
                        func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                    }
                }
            } else {
            reset:
                *(u8 *)(arg0 + 0x5B0) = 0xFF;
                *(u16 *)(arg0 + 0x5AC) = 0xFFFF;
                *(u8 *)(arg0 + 0x5B8) = 0;
            }
        }
        break;
    case 2:
        *(s32 *)(arg0 + 0x5E8) |= 4;
        func_0881C2E4(arg0, (u8 *)(arg0 + 0x5B9), pad, 2);
        pad = (u16)pad;
        func_0881C098(arg0, (u8 *)(arg0 + 0x586), (u16)(pad & 0xA0), 0x18);
        *(s8 *)(arg0 + 0x5BA) = 0;
        *(s32 *)(arg0 + 0x528) &= ~0x80;
        if ((u8)func_088286E4(arg0, *(u8 *)(arg0 + 0x5B0), *(u16 *)(arg0 + 0x5AC)) == 0) {
            *(u8 *)(arg0 + 0x5B0) = func_08857558(D_089CC438, *(u16 *)(arg0 + 0x5AC));
            if (*(u8 *)(arg0 + 0x5B0) == 0xFF) {
                *(s8 *)(arg0 + 0x5BA) |= 4;
            }
        }
        if ((u8)func_088286E4(arg0, *(u8 *)(arg0 + 0x5B1), *(u16 *)(arg0 + 0x5AE)) == 0) {
            *(u8 *)(arg0 + 0x5B1) = func_08857558(D_089CC438, *(u16 *)(arg0 + 0x5AE));
            if (*(u8 *)(arg0 + 0x5B1) == 0xFF) {
                *(s8 *)(arg0 + 0x5BA) |= 4;
            }
        }
        if (*(s8 *)(arg0 + 0x5BA) == 0) {
            if (func_0885B7D0(D_08A62C50, *(s16 *)(arg0 + 0x5AC), *(s16 *)(arg0 + 0x5AE)) != 0) {
                r = func_088569F8(D_089CC438, *(u16 *)(arg0 + 0x5B4));
                if (r == 0) {
                    *(s8 *)(arg0 + 0x5BA) |= 1;
                    *(s16 *)(arg0 + 0x5FC) = 0xC;
                } else if (r < 0 && (s16)tbl[*(u8 *)(arg0 + 0x5B0)].b > 1 &&
                           (s16)tbl[*(u8 *)(arg0 + 0x5B1)].b > 1) {
                    *(s8 *)(arg0 + 0x5BA) |= 2;
                    *(s16 *)(arg0 + 0x5FC) = 0xD;
                }
                *(s32 *)(arg0 + 0x528) |= 0x80;
            }
            if (*(s8 *)(arg0 + 0x5BA) == 0) {
                if (*(s16 *)(arg0 + 0x5B4) == -1) {
                    *(s16 *)(arg0 + 0x5FC) = 9;
                } else {
                    *(s16 *)(arg0 + 0x5FC) = *(s16 *)(arg0 + 0x5B4) + 0x18;
                }
            }
        } else {
            *(s16 *)(arg0 + 0x5FC) = 0xB;
        }
        if ((pad & 0x4000) || (*(u8 *)(arg0 + 0x5B9) == 0 && (D_08A62C74 & 0x4000))) {
            ret &= ~0x2008;
            switch (*(u8 *)(arg0 + 0x5B9)) {
            case 0:
                if (*(s8 *)(arg0 + 0x5BA) == 0) {
                    if (*(s32 *)(arg0 + 0x528) & 0x80) {
                        *(s16 *)(arg0 + 0x5B2) = 1;
                    } else {
                        *(s16 *)(arg0 + 0x5B2) = 0x1E;
                        func_08829EEC(arg0, 0);
                    }
                    *(u8 *)(arg0 + 0x5B8) += 1;
                    *(s16 *)(arg0 + 0x5B6) = func_0885B82C(D_08A62C50, arg0 + 0x5E5, work,
                                                           (s16)tbl[*(u8 *)(arg0 + 0x5B0)].a,
                                                           (s16)tbl[*(u8 *)(arg0 + 0x5B1)].a, 0);
                    *(s32 *)(arg0 + 0x528) |= 8;
                } else {
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                }
                break;
            case 1:
                *(u8 *)(arg0 + 0x586) = 0;
                *(u8 *)(arg0 + 0x5B1) = 0xFF;
                *(u8 *)(arg0 + 0x5B0) = 0xFF;
                *(u16 *)(arg0 + 0x5AE) = 0xFFFF;
                *(u16 *)(arg0 + 0x5AC) = 0xFFFF;
                *(u8 *)(arg0 + 0x5B8) = 0;
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
                break;
            }
        } else if (pad & 8) {
            func_08826688(arg0);
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            return 8;
        } else if (pad & 0x2000) {
            ret &= ~0x2000;
            if (*(s8 *)(arg0 + 0x5BA) != 0) {
                *(u8 *)(arg0 + 0x5B0) = 0xFF;
                *(u16 *)(arg0 + 0x5AC) = 0xFFFF;
                *(u8 *)(arg0 + 0x5B8) = 0;
            } else {
                if (*(u8 *)(arg0 + 0x5B1) < 0x18) {
                    *(u8 *)(arg0 + 0x586) = *(u8 *)(arg0 + 0x5B1);
                } else {
                    *(u8 *)(arg0 + 0x586) = 0;
                }
                *(u8 *)(arg0 + 0x5B8) = 1;
            }
            *(u8 *)(arg0 + 0x5B1) = 0xFF;
            *(u16 *)(arg0 + 0x5AE) = 0xFFFF;
            *(s16 *)(arg0 + 0x5B4) = -1;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 3:
        ret &= ~0x2008;
        if (--*(s16 *)(arg0 + 0x5B2) > 0) {
            break;
        }
        if (*(s16 *)(arg0 + 0x5B6) > 0) {
            func_0885C0F0(D_08A62C50, *(s32 *)(arg0 + 0x5A8));
            *(s16 *)(arg0 + 0x5B4) = *(s16 *)(arg0 + 0x5B6);
            func_08829EEC(arg0, 1);
        } else {
            *(s16 *)(arg0 + 0x5B6) = 0x9B;
            *(u8 *)(arg0 + 0x5E5) = 1;
            func_08829EEC(arg0, 2);
        }
        if (tbl[*(u8 *)(arg0 + 0x5B0)].a == 0) {
            *(u8 *)(arg0 + 0x5B0) = 0xFF;
        }
        if (tbl[*(u8 *)(arg0 + 0x5B1)].a == 0) {
            *(u8 *)(arg0 + 0x5B1) = 0xFF;
        }
        *(s16 *)(arg0 + 0x5FC) = *(s16 *)(arg0 + 0x5B6) + 0x18;
        *(u8 *)(arg0 + 0x5B8) += 1;
    case 4:
        r = func_08831FF8(arg0, work, *(u16 *)(arg0 + 0x5B6), -1, 0, *(u8 *)(arg0 + 0x5E5));
        switch (r) {
        case 0:
        case 1:
            if (!(*(s32 *)(arg0 + 0x528) & 0x80)) {
                if (*(s16 *)(arg0 + 0x5B6) != 0x9B) {
                    if (*(u16 *)(work + 0x1E6) == *(u8 *)(D_089CC438 + 0x28)) {
                        func_088860A0(D_08A62D90, *(s16 *)(arg0 + 0x5B6));
                    }
                } else {
                    func_08885E3C(D_08A62D90, 0x18F9);
                }
                *(s16 *)(arg0 + 0x5B2) = 0x1E;
            } else {
                *(s16 *)(arg0 + 0x5B2) = 1;
            }
            *(u8 *)(arg0 + 0x5B8) += 1;
            *(s32 *)(arg0 + 0x528) &= ~8;
            break;
        case 2:
        case 3:
            func_08830728(arg0, 1, 3, *(s16 *)(arg0 + 0x5B6));
            if (*(s32 *)(arg0 + 0x528) & 0x80) {
                *(s16 *)(arg0 + 0x5B2) = 1;
            } else {
                *(s16 *)(arg0 + 0x5B2) = 0x1E;
            }
            *(u8 *)(arg0 + 0x5B8) += 1;
            *(s32 *)(arg0 + 0x528) &= ~8;
            break;
        case 5:
            *(u8 *)(arg0 + 0x586) = 0;
            *(u8 *)(arg0 + 0x5B8) = 6;
            *(s32 *)(arg0 + 0x528) &= ~0x200;
            break;
        case -1:
        case 4:
            break;
        }
        break;
    case 5:
        ret &= ~0x2000;
        if (*(s16 *)(arg0 + 0x5B2) != 0) {
            *(s16 *)(arg0 + 0x5B2) -= 1;
            break;
        }
        if (((u16)pad & 0xF3F0) || (D_08A62C74 & 0x4000)) {
            *(u8 *)(arg0 + 0x5B8) = 2;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 6:
        ret &= ~0x2000;
        if (*(u8 *)(arg0 + 0x52F) != 0) {
            break;
        }
        if (*(u16 *)(arg0 + 0x5AC) != tbl[*(u8 *)(arg0 + 0x5B0)].a) {
            *(u8 *)(arg0 + 0x5B0) = 0xFF;
        } else if (*(u16 *)(arg0 + 0x5AE) != tbl[*(u8 *)(arg0 + 0x5B1)].a) {
            *(u8 *)(arg0 + 0x5B1) = 0xFF;
        }
        *(s32 *)(arg0 + 0x528) |= 0x200;
        *(s32 *)(arg0 + 0x528) &= ~8;
        *(u8 *)(arg0 + 0x5B8) = 2;
        if (*(u8 *)(arg0 + 0x5B0) != 0xFF && *(u8 *)(arg0 + 0x5B1) != 0xFF &&
            func_0885B5B8(D_08A62C50, *(s16 *)(arg0 + 0x5AC), *(s16 *)(arg0 + 0x5AE), 0, 0, 0) == 0) {
            func_08826688(arg0);
            *(s32 *)(arg0 + 0x5E8) &= ~4;
        }
        break;
    }
    return ret;
}
