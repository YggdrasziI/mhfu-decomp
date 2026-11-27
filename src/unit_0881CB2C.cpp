/* unit_0881CB2C: 0x0881CB2C-0x0881DB5C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881CB2C: 0x0881CB2C-0x0881DB5C (ULES01213)
 *
 * C++: the flag tests keep their `sltu` (bool). Default (size) setting.
 *
 * The 8-byte record copy is one structure of a 6-byte array and a 2-byte
 * pair (loop for the array, two byte loads then two stores). The table swap
 * reads the first element before taking the second address. The two failing
 * tests of the "ok" value share one `ok = 0` (one `||` guard).
 */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Pair {
    u16 a;
    s16 b;
} Pair;

typedef struct B2 {
    u8 a;
    u8 b;
} B2;

typedef struct Name6 {
    s8 c[6];
} Name6;

typedef struct Name8 {
    Name6 n;
    B2 m;
} Name8;

extern "C" {

extern char *D_089CC438;
extern char *D_08A62D90;
extern s32 D_08A62D8C;
extern char *D_08A62C50;
extern char *D_09A0B544;
extern u8 D_0899D19B[][24];

extern Pair *func_08856884(char *, s32);
extern void func_088862A8(char *, s32);
extern void func_08885E3C(char *, s16);
extern void func_0881C520(char *, u16, s32);
extern s32 func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088292AC(char *, u8);
extern void func_0881C1C8(char *, u8 *, u16);
extern s32 func_0881C2E4(char *, u8 *, u16, u8);
extern void func_0881C240(char *, s32, u16);
extern s32 func_08829928(char *);
extern s32 func_08829A48(char *, s32);
extern s16 func_08826734(char *, u8);
extern void func_08825E78(char *);
extern void func_088D839C(char *, s32);
extern void func_0882675C(char *, u16);
extern char *func_0883B3D4(char *, s32);
extern s32 func_0882A8B8(char *, s32);
extern void func_0889D3FC(char *, void *, u16, s32);
extern void func_0889D6EC(char *);
extern void func_08829E6C(char *, s32, s32);
extern u8 *func_0885C580(char *, s32);
extern void func_0881C098(char *, u8 *, u16, u8);
extern void func_088490C8(char *);
extern void func_08834548(char *);

u16 func_0881CB2C(char *arg0, u16 pad) {
    char *w = *(char **)(arg0 + 0x530);
    Pair *tbl = func_08856884(D_089CC438, 0);
    u8 ok;

    if (*(u8 *)(arg0 + 0x1207) != 0) {
        func_088862A8(D_08A62D90, 4);
        func_08885E3C(D_08A62D90, 0x18F8);
        *(u8 *)(arg0 + 0x1207) = 0;
    }
    switch (*(u8 *)(arg0 + 0x585)) {
    case 0:
        *(s16 *)(arg0 + 0x5FC) = 6;
        if (*(s32 *)(arg0 + 0x528) & 0x10) {
            func_0881C520(arg0, pad, 0xA0);
            if (pad & 0x2000) {
                pad = 0;
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            } else if (pad & 0x4000) {
                pad = 0;
                if (*(u8 *)(arg0 + 0x537) == 0) {
                    func_088292AC(arg0, 0);
                    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                    *(u8 *)(arg0 + 0x586) = *(u8 *)(arg0 + 0x586) % 8;
                } else {
                    func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
                }
            } else {
                break;
            }
            *(s32 *)(arg0 + 0x528) &= ~0x10;
        } else if (pad & 1) {
            *(s32 *)(arg0 + 0x528) |= 0x10;
            *(u8 *)(arg0 + 0x537) = 0;
            pad = 0;
            func_08883988(D_08A62D8C, 0, 0xF, 0, 0, 0, 0, 0, 0);
            break;
        }
        if (!(pad & 0x2000)) {
            func_0881C1C8(arg0, (u8 *)(arg0 + 0x586), pad);
            if (pad & 0x4000) {
                if (tbl[*(u8 *)(arg0 + 0x586)].a != 0) {
                    *(u8 *)(arg0 + 0x585) += 1;
                    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                } else {
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                }
            }
        }
        break;
    case 1:
        if (tbl[*(u8 *)(arg0 + 0x586)].a == 0) {
            *(u8 *)(arg0 + 0x585) = 0;
            pad &= ~0x2000;
            break;
        }
        func_0881C2E4(arg0, (u8 *)(arg0 + 0x588), pad, 4);
        func_0881C240(arg0, tbl[*(u8 *)(arg0 + 0x586)].a, pad & 0x8000);
        if (pad & 0x2000) {
            *(u8 *)(arg0 + 0x585) -= 1;
            pad &= ~0x2000;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else if (pad & 0x4000) {
            if ((bool)(*(s32 *)(w + 0x614) & 4) == 0) {
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                break;
            }
            switch (*(u8 *)(arg0 + 0x588)) {
            case 0:
                *(u8 *)(arg0 + 0x537) = 1;
                *(u8 *)(arg0 + 0x585) += 1;
                *(u8 *)(arg0 + 0x589) = 0;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                break;
            case 1:
                if ((u8)func_08829928(arg0) == 1) {
                    *(u8 *)(arg0 + 0x58A) = 1;
                    *(u8 *)(arg0 + 0x585) += 1;
                    if (tbl[*(u8 *)(arg0 + 0x586)].b != 1) {
                        *(u8 *)(arg0 + 0x58B) = 0;
                        *(u8 *)(arg0 + 0x589) = 0;
                    } else {
                        *(u8 *)(arg0 + 0x589) = 1;
                    }
                    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                } else {
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                }
                break;
            case 2:
                if ((u8)func_08829A48(arg0, tbl[*(u8 *)(arg0 + 0x586)].a) == 1) {
                    *(u8 *)(arg0 + 0x58A) = 1;
                    *(u8 *)(arg0 + 0x585) += 1;
                    if (tbl[*(u8 *)(arg0 + 0x586)].b != 1) {
                        *(u8 *)(arg0 + 0x58B) = 0;
                        *(u8 *)(arg0 + 0x589) = 0;
                    } else {
                        *(u8 *)(arg0 + 0x589) = 1;
                    }
                    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                } else {
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                }
                break;
            case 3:
                *(u8 *)(arg0 + 0x585) += 1;
                *(u8 *)(arg0 + 0x595) = *(u8 *)(arg0 + 0x586);
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                break;
            }
        }
        break;
    case 2:
        if (tbl[*(u8 *)(arg0 + 0x586)].a == 0) {
            *(u8 *)(arg0 + 0x585) = 0;
            pad = 0;
            *(s16 *)(arg0 + 0x5FC) = func_08826734(arg0, *(u8 *)(arg0 + 0x586)) + 0x18;
            break;
        }
        if ((bool)(*(s32 *)(w + 0x614) & 4) == 0) {
            *(u8 *)(arg0 + 0x585) = 1;
            pad = 0;
            *(s16 *)(arg0 + 0x5FC) = func_08826734(arg0, *(u8 *)(arg0 + 0x586)) + 0x18;
            break;
        }
        switch (*(u8 *)(arg0 + 0x588)) {
        case 0:
            if (pad & 0x2000) {
                pad &= ~0x2000;
                func_08825E78(arg0);
                break;
            }
            *(s16 *)(arg0 + 0x5FC) = 0;
            func_0881C520(arg0, pad, 0x50);
            if (pad & 0x4000) {
                if (*(u8 *)(arg0 + 0x537) == 0) {
                    func_088D839C(w, *(u8 *)(arg0 + 0x586));
                    *(u8 *)(arg0 + 0x585) = 0;
                    *(u8 *)(arg0 + 0x588) = 0;
                    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                } else {
                    func_08825E78(arg0);
                }
            }
            break;
        case 1:
            if ((u8)func_08829928(arg0) == 0) {
                pad = 0;
                func_08825E78(arg0);
                break;
            }
            switch (*(u8 *)(arg0 + 0x589)) {
            case 0:
                if (pad & 0x2000) {
                    pad = 0;
                    func_08825E78(arg0);
                    break;
                }
                *(s16 *)(arg0 + 0x5FC) = 3;
                func_0882675C(arg0, pad);
                if (pad & 0x4000) {
                    *(s16 *)(arg0 + 0x5FC) = 1;
                    *(u8 *)(arg0 + 0x589) += 1;
                    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                }
                break;
            case 1:
                if (pad & 0x2000) {
                    pad &= ~0x2000;
                    if (tbl[*(u8 *)(arg0 + 0x586)].b != 1 && D_0899D19B[tbl[*(u8 *)(arg0 + 0x586)].a][0] != 0xFF) {
                        *(u8 *)(arg0 + 0x589) = 0;
                        func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
                    } else {
                        func_08825E78(arg0);
                    }
                    break;
                }
                *(s16 *)(arg0 + 0x5FC) = 1;
                if ((bool)(*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 1) {
                    func_0881C2E4(arg0, (u8 *)(arg0 + 0x587), pad, 3);
                } else if (pad & 0x10) {
                    if (--*(s8 *)(arg0 + 0x587) < 0) {
                        *(s8 *)(arg0 + 0x587) = 3;
                    }
                    if (*(s8 *)(arg0 + 0x587) == *(u8 *)(D_089CC438 + 0x28)) {
                        *(s8 *)(arg0 + 0x587) = *(s8 *)(arg0 + 0x587) - 1;
                    }
                    if (*(s8 *)(arg0 + 0x587) < 0) {
                        *(s8 *)(arg0 + 0x587) = 3;
                    }
                    func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
                } else if (pad & 0x40) {
                    if (++*(s8 *)(arg0 + 0x587) > 3) {
                        *(s8 *)(arg0 + 0x587) = 0;
                    }
                    if (*(s8 *)(arg0 + 0x587) == *(u8 *)(D_089CC438 + 0x28)) {
                        *(s8 *)(arg0 + 0x587) = *(s8 *)(arg0 + 0x587) + 1;
                    }
                    if (*(s8 *)(arg0 + 0x587) > 3) {
                        *(s8 *)(arg0 + 0x587) = 0;
                    }
                    func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
                }
                if (pad & 0x4000) {
                    if ((bool)(*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0) {
                        ok = *(u8 *)((char *)(*(u8 *)(arg0 + 0x587) * 0x8C) + (s32)D_089CC438 + 0x30) != 0;
                    } else {
                        char *e = func_0883B3D4(arg0, *(s8 *)(arg0 + 0x587));
                        if (e == 0 || *(u8 *)(e + 0xBF) == 5) {
                            ok = 0;
                        } else {
                            ok = (u8)func_0882A8B8(arg0, *(s8 *)(arg0 + 0x587)) == 0;
                        }
                    }
                    if (ok == 1) {
                        *(s8 *)(w + 0x5C9) = *(s8 *)(arg0 + 0x587);
                        *(u16 *)(w + 0x5CA) = tbl[*(u8 *)(arg0 + 0x586)].a;
                        *(s16 *)(w + 0x5CC) = *(u8 *)(arg0 + 0x58A);
                        *(s32 *)(w + 0x614) |= 0x40;
                        if ((bool)(*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) {
                            char *e = func_0883B3D4(arg0, *(s8 *)(arg0 + 0x587));
                            *(Name8 *)(w + 0x5CE) = *(Name8 *)e;
                            func_0889D3FC(D_09A0B544, e, tbl[*(u8 *)(arg0 + 0x586)].a, *(u8 *)(arg0 + 0x58A));
                            func_0889D6EC(D_09A0B544);
                        }
                        *(u8 *)(arg0 + 0x585) = 3;
                        pad = 0;
                    } else {
                        func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                    }
                }
                break;
            }
            break;
        case 2:
            if ((u8)func_08829A48(arg0, tbl[*(u8 *)(arg0 + 0x586)].a) == 0) {
                *(u8 *)(arg0 + 0x585) = 1;
                pad &= ~0x2000;
                *(s16 *)(arg0 + 0x5FC) = func_08826734(arg0, *(u8 *)(arg0 + 0x586)) + 0x18;
                break;
            }
            switch (*(u8 *)(arg0 + 0x589)) {
            case 0:
                if (pad & 0x2000) {
                    pad &= ~0x2000;
                    func_08825E78(arg0);
                    break;
                }
                *(s16 *)(arg0 + 0x5FC) = 4;
                func_0882675C(arg0, pad);
                if (pad & 0x4000) {
                    *(s16 *)(arg0 + 0x5FC) = 5;
                    *(u8 *)(arg0 + 0x589) += 1;
                    *(u8 *)(arg0 + 0x537) = 1;
                    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                }
                break;
            case 1:
                *(s16 *)(arg0 + 0x5FC) = 5;
                func_0881C520(arg0, pad, 0x50);
                if (pad & 0x4000) {
                    if (*(u8 *)(arg0 + 0x537) == 0) {
                        func_08829E6C(arg0, tbl[*(u8 *)(arg0 + 0x586)].a, *(u8 *)(arg0 + 0x58A));
                        *(u8 *)(arg0 + 0x585) = 0;
                        *(u8 *)(arg0 + 0x588) = 0;
                        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                        pad = 0;
                        break;
                    }
                    pad |= 0x2000;
                }
                if (pad & 0x2000) {
                    pad &= ~0x2000;
                    if (func_08856884(D_089CC438, *(u8 *)(arg0 + 0x586))->b != 1 &&
                        func_0885C580(D_08A62C50, *(u8 *)(arg0 + 0x586))[3] != 0xFF) {
                        *(u8 *)(arg0 + 0x589) = 0;
                        func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
                    } else {
                        func_08825E78(arg0);
                    }
                }
                break;
            }
            break;
        case 3:
            if (pad & 0x2000) {
                pad &= ~0x2000;
                func_08825E78(arg0);
                break;
            }
            *(s16 *)(arg0 + 0x5FC) = 7;
            func_0881C098(arg0, (u8 *)(arg0 + 0x595), pad, 0x18);
            if (pad & 0x4000) {
                if (*(u8 *)(arg0 + 0x586) != *(u8 *)(arg0 + 0x595)) {
                    Pair *p;
                    Pair *q;
                    Pair *r;
                    u16 ta;
                    s16 tb;

                    p = &tbl[*(u8 *)(arg0 + 0x586)];
                    ta = p->a;
                    tb = p->b;
                    q = &tbl[*(u8 *)(arg0 + 0x595)];
                    p->a = q->a;
                    p->b = q->b;
                    r = &tbl[*(u8 *)(arg0 + 0x595)];
                    r->a = ta;
                    r->b = tb;
                    if ((bool)(*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0) {
                        if (*(u8 *)(arg0 + 0x586) == *(u8 *)(w + 0x686)) {
                            *(s16 *)(w + 0x686) = *(u8 *)(arg0 + 0x595);
                        } else if (*(u8 *)(arg0 + 0x595) == *(u8 *)(w + 0x686)) {
                            *(s16 *)(w + 0x686) = *(u8 *)(arg0 + 0x586);
                        }
                        if (*(u8 *)(w + 0x5F6) == *(u8 *)(arg0 + 0x586)) {
                            *(u8 *)(w + 0x5F6) = *(u8 *)(arg0 + 0x595);
                        } else if (*(u8 *)(w + 0x5F6) == *(u8 *)(arg0 + 0x595)) {
                            *(u8 *)(w + 0x5F6) = *(u8 *)(arg0 + 0x586);
                        }
                    }
                    *(u8 *)(arg0 + 0x586) = *(u8 *)(arg0 + 0x595);
                    *(u8 *)(arg0 + 0x585) = 0;
                    *(s16 *)(arg0 + 0x5FC) = func_08826734(arg0, *(u8 *)(arg0 + 0x586)) + 0x18;
                    func_08883988(D_08A62D8C, 1, 0x8B, 0, 0, 0, 0, 0, 0);
                } else {
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                }
            }
            break;
        default:
            *(u8 *)(arg0 + 0x585) = 0;
            break;
        }
        break;
    case 3:
        if ((bool)(*(s32 *)(w + 0x614) & 8) != 0) {
            if ((bool)(*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0) {
                func_088490C8(arg0);
            } else {
                func_08834548(arg0);
            }
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            pad = 0;
        } else {
            *(u8 *)(arg0 + 0x585) = 2;
            *(u8 *)(arg0 + 0x588) = 1;
            *(u8 *)(arg0 + 0x589) = 1;
            func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
            pad = 0;
        }
        break;
    }
    return pad;
}

}
