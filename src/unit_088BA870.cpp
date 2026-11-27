/* unit_088BA870: 0x088BA870-0x088BBE58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: virtual call (D_089CC434->vfunc_38 through $t9).
 * .rodata jtbl_089321DC (0x089321DC, 0x50 bytes): the switch's jump table.
 * A save/load menu state machine (+0xC); the yes/no question block is a
 * static inline helper used five times.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct V38_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual s32 vfunc_38(); } V38_0;

extern "C" {

typedef struct Pair { u16 a; u16 b; } Pair;

extern V38_0 *D_089CC434;
extern char *D_089CC438;
extern char *D_089CC01C;
extern char *D_09A1FDDC;
extern char *D_09A4F060;
extern char D_09CE4848[];
extern s32 D_08A62C6C;
extern s32 D_08A62D8C;

extern int memset(void *, s32, s32);
extern int memcpy(void *, void *, unsigned int);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern char *func_08851680(char *, u16);
extern void func_088BFEF8(char *, char *);
extern void func_088C1430(char *);
extern void func_088BA5BC(s32, s32, s32, s32);
extern void func_088BA494(s32, s32, u16);
extern void func_088BA54C(s32, s32, u16);
extern void func_088BA2E0(s32, s32, s32, s32);
extern void func_088BA664(s32, s32);
extern void func_088C30B8(char *, u8, s32);
extern void func_088BF858(char *, s32);
extern void func_088BFE54(char *, s32);
extern void func_088C0940(char *, char *);
extern void func_088C0594(char *, char *);
extern s32 func_0884FB38(char *, s32);
extern s32 func_0884FC0C(char *, s32);
extern void func_0884FAC4(char *, s32);
extern void func_088C3054(char *);
extern void func_08882B58(s32, s32, s32);
extern s32 func_08882C90(s32, s32);
extern s32 func_088855C4(s32, s32, s32, s32);
extern void func_08885494(s32, s32, s32, s32, s32);
extern int func_08882C24(s32, s32, s32, s32);
extern void func_0884D790(char *, s16, s32);

static inline s32 read_choice(char *p) {
    s32 btn = D_08A62C6C;

    if (btn & 0x80) {
        if (*(u8 *)(p + 0x4) == 0) {
            *(u8 *)(p + 0x4) = 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if (btn & 0x20) {
        if (*(u8 *)(p + 0x4) != 0) {
            *(u8 *)(p + 0x4) = 0;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if ((btn & 0x4000) && *(u8 *)(p + 0x4) != 0) {
        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        return 2;
    } else if ((btn & 0x2000) || ((btn & 0x4000) && *(u8 *)(p + 0x4) == 0)) {
        func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}

static inline void show_pair(void) {
    func_08882C24(D_08A62D8C, 0, 0x10, ((Pair *) D_09CE4848)[*(u16 *)(D_09A4F060 + 0x288)].b);
}

s32 func_088BA870(char *p) {
    s32 ret;
    s32 st;
    s32 btn;
    s32 r;
    s32 i;
    char *q;

    ret = 0;
    if (*(u8 *)(p + 0x9AC) != 0) {
        st = *(s32 *)(p + 0xC);
        if (st != 0 && st != 0x10 && st != 0x11 && *(u8 *)(p + 0x971) == 0 && *(u8 *)(p + 0x970) == 0) {
            if (*(u8 *)(p + 0x978) == 0) {
                func_088BFEF8(p, func_08851680(D_089CC438, 0x3D));
                *(u8 *)(p + 0x9AC) = 0;
                *(s32 *)(p + 0xC) = 0x10;
            } else if (*(u8 *)(D_09A1FDDC + 0xD) != 0) {
                *(u8 *)(p + 0x9AC) = 0;
                *(s32 *)(p + 0xC) = 0;
            }
        }
    }

    switch (*(s32 *)(p + 0xC)) {
    case 0:
        *(u8 *)(p + 0x4) = 1;
        *(s32 *)(p + 0x8) = 0;
        *(s32 *)(p + 0x97C) = -1;
        memset(p + 0x980, 0, 8);
        *(u8 *)(p + 0x9AC) = 0;
        if (*(u8 *)(p + 0x9A3) == 0) {
            *(s32 *)(p + 0xC) = 1;
        } else {
            func_088C1430(p);
            *(s32 *)(p + 0xC) = 4;
            *(u8 *)(p + 0x9A3) = 0;
            break;
        }
    case 1:
        r = read_choice(p);
        if (r == 2) {
            if (!(*(s32 *)(p + 0x990) & 0x40)) {
                *(s32 *)(p + 0xC) = 4;
                func_088C1430(p);
            } else {
                *(s32 *)(p + 0xC) = 2;
            }
        } else if (r == 1) {
            ret = 2;
        }
        if (!(*(s32 *)(p + 0x990) & 1)) {
            func_088BA5BC(0x10, 0xC0, 0x1C0, 0x48);
            func_088BA494(0xF0, 0xCC, 6);
            func_088BA2E0(0xB8, 0xEC, *(u8 *)(p + 0x4), 1);
        } else {
            func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
            func_088BA494(0xF0, 0x70, 4);
            func_088BA2E0(0xB8, 0xA0, *(u8 *)(p + 0x4), 1);
        }
        break;
    case 2:
        btn = D_08A62C6C;
        if (btn & 0x4000) {
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            *(s32 *)(p + 0xC) = 4;
            func_088C1430(p);
        } else if (btn & 0x2000) {
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            *(s32 *)(p + 0xC) = 1;
        }
        func_088BA5BC(0x10, 0x34, 0x1C0, 0xD6);
        func_088BA494(0xF0, 0x50, 0x5A);
        break;
    case 4:
        if (D_089CC434->vfunc_38() == 0) {
            *(s32 *)(p + 0xC) = 3;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 3:
        if (*(u8 *)(p + 0x970) == 0) {
            st = *(s32 *)(p + 0x34);
            if (st == 0 || (st == 2 && *(s32 *)(p + 0x5E4) == 0)) {
                func_088C30B8(p, 1, 0);
                *(s32 *)(p + 0xC) = 0x13;
                *(u8 *)(p + 0x9AC) = 1;
            } else if (st == (s32)0x80110307) {
                *(u8 *)(p + 0x9AC) = 1;
                *(s32 *)(p + 0xC) = 6;
            } else if (st == 2 && *(s32 *)(p + 0x5E4) == 1) {
                memset(*(char **)(p + 0x94C), 0, 0x16A100);
                func_088BF858(p, 0);
            } else {
                *(u8 *)(p + 0x995) = 0;
                if (*(s32 *)(p + 0x34) == (s32)0x80110306 || *(s32 *)(p + 0x34) == (s32)0x80110309) {
                    *(u8 *)(p + 0x995) = 1;
                }
                func_088BFE54(p, *(s32 *)(p + 0x34));
                *(s32 *)(p + 0xC) = 5;
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 0x13:
        if (*(u8 *)(p + 0x4A88) == 0) {
            if (*(u8 *)(p + 0x4A89) == 0) {
                func_088BFEF8(p, func_08851680(D_089CC438, 2));
                *(u8 *)(p + 0x995) = 1;
                *(s32 *)(p + 0xC) = 5;
                break;
            }
            *(s32 *)(p + 0xC) = 6;
            *(u8 *)(p + 0x9AC) = 1;
            q = *(char **)(p + 0x94C);
            i = 0;
            do {
                if (*(u8 *)(q + 0x1012) == 0) {
                    *(s32 *)(p + 0x8) = i;
                    break;
                }
                i++;
                q += 0x6B100;
            } while (i < 3);
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 6:
        btn = D_08A62C6C;
        if (btn & 0x10) {
            if (--*(s32 *)(p + 0x8) < 0) {
                *(s32 *)(p + 0x8) = 2;
            }
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        } else if (btn & 0x40) {
            if (++*(s32 *)(p + 0x8) > 2) {
                *(s32 *)(p + 0x8) = 0;
            }
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        } else if (btn & 0x2000) {
            *(s32 *)(p + 0xC) = 0;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else if (btn & 0x4000) {
            *(u8 *)(p + 0x4) = 0;
            *(s32 *)(p + 0xC) = 7;
            if ((*(u8 **)(p + 0x94C) + *(s32 *)(p + 0x8) * 0x6B100)[0x1012] == 1) {
                *(u8 *)(p + 0x994) = 1;
            } else {
                *(u8 *)(p + 0x994) = 0;
            }
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        }
        func_088C0940(p, *(char **)(p + 0x94C));
        func_088BA5BC(0xA8, 0xD0, 0x130, 0x30);
        func_088BA54C(0xB0, 0xD8, 7);
        break;
    case 7:
        r = read_choice(p);
        if (r == 2) {
            *(u8 *)(p + 0x9AC) = 0;
            func_088C0594(p, *(char **)(p + 0x94C) + 0x16A0E0);
            memcpy(p + 0x988, *(char **)(p + 0x94C) + 0x16A0E0, 8);
            memcpy(*(char **)(p + 0x94C), D_089CC438 + 0x6ADD8, 0xE);
            *(s32 *)(D_089CC438 + 0x6ADE8) |= *(s32 *)(*(char **)(p + 0x94C) + 0x10);
            *(s32 *)(D_089CC438 + 0x6ADEC) |= *(s32 *)(*(char **)(p + 0x94C) + 0x14);
            *(s32 *)(D_089CC438 + 0x6ADF0) |= *(s32 *)(*(char **)(p + 0x94C) + 0x18);
            *(s32 *)(D_089CC438 + 0x6ADF4) |= *(s32 *)(*(char **)(p + 0x94C) + 0x1C);
            *(s32 *)(D_089CC438 + 0x6ADF8) |= *(s32 *)(*(char **)(p + 0x94C) + 0x20);
            q = D_089CC438;
            if (func_0884FB38(q, 0xCA) == 0 && (*(s32 *)(q + 0x6ADF8) & 0x1000000)) {
                func_0884FC0C(q, 0xBB8);
                func_0884FAC4(q, 0xCA);
            }
            memcpy(*(char **)(p + 0x94C) + 0x10, D_089CC438 + 0x6ADE8, 0x14);
            memcpy(*(char **)(p + 0x94C) + *(s32 *)(p + 0x8) * 0x6B100 + 0x1000, D_089CC438 + 0x4A0, 0x6A938);
            (*(u8 **)(p + 0x94C) + *(s32 *)(p + 0x8) * 0x6B100)[0x1012] = 1;
            *(s32 *)(*(char **)(p + 0x94C) + 0x24) = *(s32 *)(p + 0x8) + 1;
            *(u8 *)(p + 0x9A2) = 1;
            func_088C3054(p);
            *(s32 *)(p + 0xC) = 0x12;
        } else if (r == 1) {
            *(s32 *)(p + 0xC) = 6;
        }
        if (*(u8 *)(p + 0x994) != 0) {
            func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
            func_088BA494(0xF0, 0x60, 9);
            func_088BA2E0(0xB8, 0xA0, *(u8 *)(p + 0x4), 1);
        } else if (*(s32 *)(p + 0xC) == 6 || *(s32 *)(p + 0xC) == 7) {
            func_088C0940(p, *(char **)(p + 0x94C));
            func_088BA5BC(0xA8, 0xD0, 0x130, 0x30);
            func_088BA54C(0xB0, 0xD8, 0xA);
            func_088BA2E0(0x158, 0xE8, *(u8 *)(p + 0x4), 1);
        }
        break;
    case 0x12:
        if (*(u8 *)(p + 0x4A88) == 0) {
            func_088BF858(p, 1);
            if (*(s32 *)(p + 0x990) & 8) {
                func_08882B58(D_08A62D8C, 0, 0x10);
                *(s32 *)(p + 0xC) = 0xF;
            } else {
                *(s32 *)(p + 0xC) = 8;
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x14);
        break;
    case 0xF:
        if (func_08882C90(D_08A62D8C, 0) == 0) {
            *(s32 *)(p + 0xC) = 8;
            func_08883988(D_08A62D8C, 7, 0x71, 0, 0, 0, 0, 0, 0);
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x14);
        break;
    case 8:
        if (*(u8 *)(p + 0x970) == 0) {
            st = *(s32 *)(p + 0x34);
            if (st == 0 || (st == 2 && *(s32 *)(p + 0x5E4) == 0)) {
                if (!(*(s32 *)(p + 0x990) & 8) || ((*(s32 *)(p + 0x990) & 8) && func_088855C4(D_08A62D8C, 7, 0, 0) == 0)) {
                    *(s32 *)(p + 0x97C) = *(s32 *)(p + 0x8);
                    memcpy(p + 0x980, p + 0x988, 8);
                    if (!(*(s32 *)(p + 0x990) & 0x20)) {
                        *(s32 *)(p + 0xC) = 0xE;
                    } else {
                        *(s32 *)(p + 0xC) = 0x11;
                        *(s32 *)(p + 0x0) = 0x3C;
                        *(u8 *)(p + 0x4) = 1;
                    }
                    func_08883988(D_08A62D8C, 0, 0x24, 0, 0, 0, 0, 0, 0);
                    show_pair();
                }
            } else if (st == 2 && *(s32 *)(p + 0x5E4) == 1) {
                func_088BF858(p, 1);
            } else {
                *(u8 *)(p + 0x995) = 0;
                func_088BFE54(p, *(s32 *)(p + 0x34));
                *(s32 *)(p + 0xC) = 5;
                if (*(s32 *)(p + 0x990) & 8) {
                    func_08885494(D_08A62D8C, 7, 0, 0, 0);
                    show_pair();
                }
                show_pair();
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x14);
        break;
    case 5:
        if (*(u8 *)(p + 0x971) == 0) {
            if (*(u8 *)(p + 0x995) != 0) {
                *(s32 *)(p + 0xC) = 0xC;
                *(u8 *)(p + 0x4) = 1;
            } else if (*(s32 *)(p + 0x34) == (s32)0x80110383) {
                *(s32 *)(p + 0xC) = 0xA;
                *(u8 *)(p + 0x4) = 1;
            } else {
                *(s32 *)(p + 0xC) = 0;
            }
        }
        break;
    case 0xA:
        r = read_choice(p);
        if (r == 2) {
            *(s32 *)(p + 0xC) = 0xB;
            func_088BF858(p, 7);
            func_0884D790(D_089CC01C, 4, 1);
            *(u8 *)(D_089CC01C + 0x29) = 0xC0;
        } else if (r == 1) {
            *(s32 *)(p + 0xC) = 0;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 5);
        func_088BA2E0(0xB8, 0xA0, *(u8 *)(p + 0x4), 1);
        break;
    case 0xB:
        if (*(u8 *)(p + 0x970) == 0) {
            *(s32 *)(p + 0xC) = 0;
            func_0884D790(D_089CC01C, 4, 0);
        }
        break;
    case 0xC:
        r = read_choice(p);
        if (r == 2) {
            *(s32 *)(p + 0xC) = 0xB;
            func_088BF858(p, 7);
            func_0884D790(D_089CC01C, 4, 1);
            *(u8 *)(D_089CC01C + 0x29) = 0xC0;
        } else if (r == 1) {
            *(s32 *)(p + 0xC) = 0;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x23);
        func_088BA2E0(0xB8, 0xA0, *(u8 *)(p + 0x4), 1);
        break;
    case 0xE:
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 8);
        func_088BA664(0x9C, 0xA0);
        if (D_08A62C6C & 0x4000) {
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            ret = 1;
        }
        break;
    case 0x10:
        if (*(u8 *)(p + 0x971) == 0) {
            *(s32 *)(p + 0xC) = 0;
        }
        break;
    case 0x11:
        if (*(s32 *)(p + 0x0) > 0) {
            (*(s32 *)(p + 0x0))--;
        } else {
            r = read_choice(p);
            if (r == 2) {
                *(s32 *)(p + 0xC) = 0xE;
            } else if (r == 1) {
                ret = 4;
            }
        }
        func_088BA5BC(0x10, 0x34, 0x1C0, 0xD6);
        func_088BA494(0xF0, 0x60, 0x3F);
        st = *(s32 *)(p + 0x0);
        func_088BA2E0(0xB8, 0x80, *(u8 *)(p + 0x4), st <= 0);
        break;
    }
    return ret;
}

}
