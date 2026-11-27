/* unit_08874C58: 0x08874C58-0x08876574 (ULES01213)
 *
 * Bounds (hypothesis): 1 large state-machine function (36-case switch on
 * the state word at 0xA0) between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match (the
 * division by 100 is a multiplication, the remainder stays a `div`).
 * The switch table is emitted in the object's own data (the original is
 * jtbl_08931734, 36 words).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

extern char *D_089CC438;
extern char *D_08A62C7C;
extern char *D_089CC01C;
extern char *D_089CBBEC;
extern char *D_08A62CB4;
extern char *D_08A631A0;
extern s32 D_09CFBBC8;
extern s32 D_09A4F0C4;
extern s32 D_08A62D8C;

extern char *func_088DCEBC(s32, u8);
extern void func_08885870(s32, s32, s32);
extern void func_08885530(s32, s32);
extern void func_088807CC(s32, s32);
extern void func_0888571C(s32, s32, s32);
extern void func_08874AB0(char *);
extern void func_0887D0D0(char *);
extern void func_0887EA88(char *);
extern s32 func_08855410(char *);
extern void func_0887EB20(char *);
extern void func_088553DC(char *);
extern void func_088741D4(char *);
extern void func_0884D790(char *, s16, s32);
extern void func_088588BC(char *, char *, s16, u16);
extern void func_08879198(char *);
extern s32 func_0886A30C(char *, s32);
extern void func_08869424(char *);
extern void func_088585E8(char *, char *, s32, s32, s32);
extern s32 func_088552E0(char *);
extern s32 func_08873488(char *);
extern char *func_08857C38(char *);
extern void func_09C26AE0(s32, char *);
extern s32 func_08874190(char *, s16);
extern s32 func_0887CA08(char *);
extern void func_0884FE10(char *, u16);
extern void func_08857148(char *, u16, s32);
extern void func_0886F894(char *);
extern void func_08823DB0(char *);
extern void func_088D8900(char *);
extern void func_088765C0(char *);
extern void func_08872980(char *);
extern s32 func_08823E18(char *, s32);
extern void func_08824B14(char *, s32);
extern void func_08823DEC(char *);
extern void func_088739A4(char *);
extern void func_08873A0C(char *);
extern void func_08873CC0(char *);
extern void func_0887D0B4(char *);
extern s32 func_0887D65C(char *);
extern void func_0887D884(char *);
extern void func_0887DD88(char *);
extern s32 func_0887DDD0(char *);
extern void func_0887E030(char *);
extern s32 func_08876710(char *);
extern void func_08876AA8(char *);
extern void func_08876FCC(char *);
extern s32 func_08877100(char *);
extern void func_088775F0(char *);
extern void func_088795F4(char *);
extern s32 func_08879FA4(char *);
extern void func_0887A34C(char *);
extern void func_0887A838(char *);
extern s32 func_0887A950(char *);
extern void func_0887AFB8(char *);
extern s32 func_0884FCB0(char *);
extern void func_0887CCAC(char *);
extern int func_08882C24(s32, s32, s32, s32);
extern s32 func_0887CD04(char *);
extern void func_0887CDFC(char *);
extern void func_08874A94(char *);
extern u16 func_0884FB6C(char *);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_08877EF0(char *);
extern u64 func_0887BB48(char *);
extern void func_0887B7C4(char *);
extern s32 func_0887B7E0(char *);
extern void func_0887B8D8(char *);
extern void func_0887C708(char *);
extern s32 func_0887C724(char *);
extern void func_0887C81C(char *);
extern s32 func_08878B60(char *);
extern void func_08878BC0(char *);
extern void func_08878BDC(char *);
extern s32 func_088785CC(char *, s32);
extern s32 func_08874218(char *);
extern void func_08877BE8(char *);
extern void func_08877C04(char *);
extern s32 func_0884FE80(char *, s32);
extern void func_08878EEC(char *);
extern void func_08878F08(char *);
extern s32 func_08874278(char *, s32);
extern s32 func_08857294(char *, s8);
extern void func_088505E0(char *, s32);
extern void func_08850648(char *, s32);
extern void func_0884FAC4(char *, s32);
extern void func_08882B68(s32, s32);
extern void func_0887EBFC(char *);
extern void func_08882D20(s32, s32, u16);
extern s32 func_08882F64(s32, s32);

static inline s32 busy(void) {
    s32 st = *(s32 *)(D_089CC01C + 0x1C);
    if (st == 0 || st == 3) {
        return 0;
    }
    return 1;
}

s32 func_08874C58(char *arg0) {
    char *g;
    char *s2;
    s32 id;
    u8 kind;
    s32 k;
    u16 *cnt;
    s32 i;
    s32 n;
    u16 val;

    g = D_089CC438;
    s2 = func_088DCEBC(D_09A4F0C4, *(u8 *)(g + 0x28));
    switch (*(s32 *)(arg0 + 0xA0)) {
    case 0:
        if (*(s32 *)(arg0 + 0xC4) == 0) {
            func_08885870(D_08A62D8C, 4, 0);
        } else if (*(s32 *)(arg0 + 0xC4) > 4) {
            *(s32 *)(arg0 + 0xA0) += 1;
        }
        *(s32 *)(arg0 + 0xC4) += 1;
        break;
    case 1:
        func_08885530(D_08A62D8C, 1);
        *(s32 *)(arg0 + 0xA0) += 1;
        break;
    case 2:
        func_088807CC(D_08A62D8C, 0);
        *(s32 *)(arg0 + 0xA0) += 1;
        break;
    case 3:
        func_0888571C(D_08A62D8C, 1, 1);
        *(s16 *)(g + 0xA) = 0;
        *(u8 *)(arg0 + 0x1F) = 0;
        func_08874AB0(arg0);
        if ((s32)((*(u32 *)(D_089CC438 + 0x6AF14) & 4) != 0) != 0) {
            func_0887D0D0(arg0);
            func_0887EA88(arg0);
        }
        if (func_08855410(D_089CC438) != 0) {
            func_0887EB20(arg0);
        }
        if (*(u8 *)(D_089CC438 + 0x2E) == 7) {
            char *cb = D_08A62CB4;

            *(s32 *)(D_089CC438 + 0x696F0) = *(s32 *)(cb + 0x104);
            *(s32 *)(D_089CC438 + 0x696E8) = *(s32 *)(cb + 0x108);
            func_088553DC(D_089CC438);
            if ((s32)((*(u32 *)(D_089CC438 + 0x6AF14) & 4) != 0) == 0 &&
                func_08855410(D_089CC438) == 0) {
                func_088741D4(arg0);
            }
            if (*(u8 *)(D_089CC438 + 0x6A5EA) < 0xFF) {
                *(u8 *)(D_089CC438 + 0x6A5EA) += 1;
            }
            *(s32 *)(arg0 + 0xA0) = 0x1B;
            func_0884D790(D_089CC01C, 1, 0);
            func_088588BC(D_089CC438, D_08A62C7C + 0x684, 0,
                          *(u16 *)(*(char **)(D_08A62C7C + 0x68) + 0x18));
            return 0;
        }
        func_08879198(arg0);
        if (func_0886A30C(D_08A62C7C, 1) == 1) {
            char *rec;

            func_08869424(D_08A62C7C);
            rec = *(char **)(D_08A62C7C + 0x68);
            id = *(u16 *)(rec + 0x18);
            kind = 0xFF;
            if (id >= 10000 && id < 11000) {
                kind = 0;
            } else if (id >= 11000 && id < 12000) {
                kind = 5;
            } else if (id >= 4000 && id < 5000) {
                kind = 3;
            } else if (id >= 0 && id < 2000) {
                kind = 1;
            } else if (id >= 2000 && id < 3000) {
                kind = 2;
            } else if (id >= 3000 && id < 4000) {
                kind = 6;
            } else if (id >= 61000 && id < 62000) {
                kind = 4;
            } else if (id >= 60000 && id < 61000) {
                if (*(s8 *)(rec + 0x1A) < 6) {
                    kind = 1;
                } else if (*(s8 *)(rec + 0x1A) < 9) {
                    kind = 2;
                } else {
                    kind = 6;
                }
            } else if (id >= 20000 && id < 23000) {
                kind = 4;
            }
            k = kind;
            if (k >= 0) {
                cnt = (u16 *)((char *)(k * 2) + (s32)D_089CC438 + 0x67778);
                if (*cnt < 9999) {
                    *cnt += 1;
                }
            }
            cnt = (u16 *)((char *)(*(u8 *)(s2 + 0x1E8) * 2) + (s32)D_089CC438 + 0x67D80);
            if (*cnt < 9999) {
                *cnt += 1;
                n = *(u8 *)(s2 + 0x1E8);
                val = *(u16 *)((char *)(n * 2) + (s32)D_089CC438 + 0x67D80);
                if (val % 100 == 0) {
                    func_088585E8(D_089CC438, D_08A62C7C + 0x684, 0x10, n, val / 100);
                }
            }
            *(s32 *)(arg0 + 0x100) = func_088552E0(D_089CC438);
            if (func_08873488(D_08A62C7C) != 0) {
                func_09C26AE0(D_09CFBBC8, func_08857C38(D_089CC438));
            }
            if ((s32)((*(u32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 1) {
                if ((u8)func_08874190(arg0, *(s16 *)(D_089CC438 + 0x6AF12)) != 1 ||
                    func_0887CA08(arg0) != 0) {
                    func_0884FE10(D_089CC438, *(u16 *)(D_089CC438 + 0x6AF12));
                }
            } else {
                u16 m = *(u16 *)(D_089CC438 + 0x6AF12);

                func_0884FE10(D_089CC438, m);
                if ((s32)((*(u32 *)(D_089CC438 + 0x6AF14) & 4) != 0) != 0) {
                    func_08857148(D_089CC438, m, *(s32 *)(arg0 + 0x128));
                }
            }
            if (*(s32 *)(D_08A62C7C + 0x28) & 0x10) {
                *(u64 *)(D_089CC438 + 0x677F8) |= *(u64 *)(D_08A62C7C + 0x5B8);
            }
            func_0886F894(D_08A62C7C);
            {
                char *ui = D_089CC01C;

                *(u8 *)(ui + 0x2C) = 0;
                *(u8 *)(ui + 0x2D) = 0;
                *(u8 *)(ui + 0x2E) = 0;
                *(u8 *)(ui + 0x2F) = 0xFF;
            }
            func_0884D790(D_089CC01C, 0x10, 0);
            *(u8 *)(D_089CC438 + 0xD) = 1;
            func_08823DB0(D_089CBBEC);
            *(s32 *)(arg0 + 0xA0) += 1;
            func_088588BC(D_089CC438, D_08A62C7C + 0x684, 4,
                          *(u16 *)(*(char **)(D_08A62C7C + 0x68) + 0x18));
        } else {
            *(s32 *)(arg0 + 0xA0) = 0xC;
            func_088D8900(s2);
            func_088765C0(arg0);
            func_088588BC(D_089CC438, D_08A62C7C + 0x684, 1,
                          *(u16 *)(*(char **)(D_08A62C7C + 0x68) + 0x18));
        }
        func_08872980(D_08A62C7C);
        break;
    case 4:
        if (func_08823E18(D_089CBBEC, 1) == 0) {
            *(s32 *)(arg0 + 0xA0) += 1;
            func_0884D790(D_089CC01C, 0x10, 1);
            func_088D8900(s2);
        }
        func_08824B14(D_089CBBEC, 0);
        break;
    case 5:
        if (!busy()) {
            if (func_08873488(D_08A62C7C) != 0) {
                func_0884D790(D_089CC01C, 0x10, 0);
                func_08823DEC(D_089CBBEC);
                func_088739A4(D_08A62C7C);
                func_08873A0C(D_08A62C7C);
                func_08873CC0(D_08A62C7C);
                *(s32 *)(arg0 + 0xA0) += 1;
            } else {
                *(s32 *)(arg0 + 0xA0) = 7;
            }
        } else {
            func_08824B14(D_089CBBEC, 0);
        }
        break;
    case 6:
        if (func_08823E18(D_089CBBEC, 1) == 0) {
            *(s32 *)(arg0 + 0xA0) += 1;
            func_0884D790(D_089CC01C, 0x10, 1);
            func_088D8900(s2);
        }
        func_08824B14(D_089CBBEC, 0);
        break;
    case 7:
        if (!busy()) {
            if ((*(s32 *)(D_08A62C7C + 0x28) & 0x1000000) &&
                       !(*(s32 *)(D_08A62C7C + 0x28) & 0x800000)) {
                func_0884D790(D_089CC01C, 0x10, 0);
                func_0887D0B4(arg0);
                *(s32 *)(arg0 + 0xA0) += 1;
            } else {
                *(s32 *)(arg0 + 0xA0) = 0xB;
            }
        } else {
            func_08824B14(D_089CBBEC, 0);
        }
        break;
    case 8:
        if (func_0887D65C(arg0) != 0) {
            func_0884D790(D_089CC01C, 0x10, 1);
            *(s32 *)(arg0 + 0xA0) += 1;
        }
        func_0887D884(arg0);
        break;
    case 9:
        if (!busy()) {
            func_0884D790(D_089CC01C, 0x10, 0);
            func_0887DD88(arg0);
            *(s32 *)(arg0 + 0xA0) += 1;
        } else {
            func_0887D884(arg0);
        }
        break;
    case 10:
        if (func_0887DDD0(arg0) != 0) {
            func_0884D790(D_089CC01C, 0x10, 1);
            *(s32 *)(arg0 + 0xA0) += 1;
        }
        func_0887E030(arg0);
        break;
    case 11:
        if (!busy()) {
            func_0884D790(D_089CC01C, 0x10, 0);
            *(u8 *)(D_089CC438 + 0xD) = 0;
            func_088765C0(arg0);
            *(s32 *)(arg0 + 0xA0) += 1;
        } else {
            func_0887E030(arg0);
        }
        break;
    case 12:
        if ((u8)func_08876710(arg0) == 1) {
            func_0884D790(D_089CC01C, 0x10, 1);
            *(s32 *)(arg0 + 0xA0) += 1;
        }
        func_08876AA8(arg0);
        break;
    case 13:
        if (!busy()) {
            if (*(u8 *)(arg0 + 0x1E) != 0) {
                func_0884D790(D_089CC01C, 0x10, 0);
                func_08876FCC(arg0);
                *(s32 *)(arg0 + 0xA0) += 1;
            } else {
                *(s32 *)(arg0 + 0xA0) = 0xF;
            }
        } else {
            func_08876AA8(arg0);
        }
        break;
    case 14:
        if ((u8)func_08877100(arg0) == 1) {
            func_088D8900(s2);
            *(s32 *)(arg0 + 0xA0) += 1;
            func_0884D790(D_089CC01C, 0x10, 1);
        }
        func_088775F0(arg0);
        break;
    case 15:
        if (!busy()) {
            func_088795F4(arg0);
            func_0884D790(D_089CC01C, 0x10, 0);
            *(s32 *)(arg0 + 0xA0) += 1;
        } else {
            func_088775F0(arg0);
        }
        break;
    case 16:
        if (func_08879FA4(arg0) != 0) {
            func_0884D790(D_089CC01C, 0x10, 1);
            *(s32 *)(arg0 + 0xA0) += 1;
        }
        func_0887A34C(arg0);
        break;
    case 17:
        if (!busy()) {
            if (*(s32 *)(D_08A62C7C + 0x28) & 0x10) {
                func_0887A838(arg0);
                func_0884D790(D_089CC01C, 0x10, 0);
                *(s32 *)(arg0 + 0xA0) += 1;
            } else {
                *(s32 *)(arg0 + 0xA0) = 0x13;
            }
        } else {
            func_0887A34C(arg0);
        }
        break;
    case 18:
        if (func_0887A950(arg0) != 0) {
            func_0884D790(D_089CC01C, 0x10, 1);
            *(s32 *)(arg0 + 0xA0) += 1;
        }
        func_0887AFB8(arg0);
        break;
    case 19:
        if (!busy()) {
            u8 have = *(u8 *)(D_089CC438 + 0x44BC);

            if (have < (u8)func_0884FCB0(D_089CC438)) {
                func_0887CCAC(arg0);
                func_0884D790(D_089CC01C, 0x10, 0);
                *(s32 *)(arg0 + 0xA0) += 1;
            } else {
                *(s32 *)(arg0 + 0xA0) = 0x15;
                func_08882C24(D_08A62D8C, 0, 0x10, 0x37);
            }
        } else {
            func_0887AFB8(arg0);
        }
        break;
    case 20:
        if (func_0887CD04(arg0) != 0) {
            func_0884D790(D_089CC01C, 0x10, 1);
            func_088585E8(D_089CC438, D_08A62C7C + 0x684, 0x1B,
                          (u8)func_0884FCB0(D_089CC438), 0);
            *(s32 *)(arg0 + 0xA0) += 1;
        }
        func_0887CDFC(arg0);
        break;
    case 21:
        if (!busy()) {
            if (*(s32 *)(arg0 + 0xCC) > 0) {
                func_08874A94(arg0);
                func_0884D790(D_089CC01C, 0x10, 0);
                *(s32 *)(arg0 + 0xA0) += 1;
            } else {
                *(s32 *)(arg0 + 0xA0) = 0x17;
            }
        } else {
            func_0887CDFC(arg0);
        }
        break;
    case 22:
        if (*(s16 *)(arg0 + 0xA8) > 0) {
            *(s16 *)(arg0 + 0xA8) -= 1;
        } else if (--*(s16 *)(arg0 + 0xAA) <= 0) {
            *(s16 *)(arg0 + 0xAA) = 0xF;
        }
        if ((--*(s16 *)(arg0 + 0xAC) <= 0 ||
             (*(s16 *)(arg0 + 0xA8) <= 0 && (func_0884FB6C(D_089CC438) & 0x4000))) &&
            *(s8 *)(arg0 + 0xC1) == 0) {
            *(s32 *)(arg0 + 0xA0) += 1;
            func_0884D790(D_089CC01C, 0x10, 1);
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        }
        func_08877EF0(arg0);
        break;
    case 23:
        if (!busy()) {
            *(u8 *)(arg0 + 0x1F) += 1;
            if (*(u8 *)(arg0 + 0x1F) >= *(s32 *)(arg0 + 0xCC)) {
                *(u64 *)(arg0 + 0xF8) = func_0887BB48(arg0);
                if (*(u64 *)(arg0 + 0xF8) != 0) {
                    func_0884D790(D_089CC01C, 0x10, 0);
                    *(s32 *)(arg0 + 0xA0) += 1;
                    func_0887B7C4(arg0);
                } else {
                    *(s32 *)(arg0 + 0xA0) = 0x19;
                }
            } else {
                func_08874A94(arg0);
                func_0884D790(D_089CC01C, 0x10, 0);
                *(s32 *)(arg0 + 0xA0) = 0x16;
            }
        } else {
            func_08877EF0(arg0);
        }
        break;
    case 24:
        if (func_0887B7E0(arg0) != 0) {
            func_0884D790(D_089CC01C, 0x10, 1);
            *(s32 *)(arg0 + 0xA0) += 1;
        }
        func_0887B8D8(arg0);
        break;
    case 25:
        if (!busy()) {
            s32 r = func_088552E0(D_089CC438);

            if (r != *(s32 *)(arg0 + 0x100) && func_0886A30C(D_08A62C7C, 1) == 1 &&
                (r == 0x46 || r == 0x7A || r == 0xA7 || r == 0xC0 || r == 0x10F ||
                 r == 0x164)) {
                func_0887C708(arg0);
                func_0884D790(D_089CC01C, 0x10, 0);
                *(s32 *)(arg0 + 0xA0) += 1;
            } else {
                *(s32 *)(arg0 + 0xA0) = 0x1B;
            }
        } else {
            func_0887B8D8(arg0);
        }
        break;
    case 26:
        if (func_0887C724(arg0) != 0) {
            func_0884D790(D_089CC01C, 0x10, 1);
            *(s32 *)(arg0 + 0xA0) += 1;
        }
        func_0887C81C(arg0);
        break;
    case 27:
        if (!busy()) {
            if (func_08878B60(arg0) != 0) {
                func_0884D790(D_089CC01C, 0x10, 0);
                func_08878BC0(arg0);
                *(s32 *)(arg0 + 0xA0) += 1;
            } else {
                *(s32 *)(arg0 + 0xA0) = 0x1D;
            }
        } else {
            func_0887C81C(arg0);
        }
        break;
    case 28:
        if (*(s16 *)(arg0 + 0xA8) > 0) {
            *(s16 *)(arg0 + 0xA8) -= 1;
        } else if (--*(s16 *)(arg0 + 0xAA) <= 0) {
            *(s16 *)(arg0 + 0xAA) = 0xF;
        }
        if ((--*(s16 *)(arg0 + 0xAC) <= 0 ||
             (*(s16 *)(arg0 + 0xA8) <= 0 && (func_0884FB6C(D_089CC438) & 0x4000))) &&
            *(s8 *)(arg0 + 0xC1) == 0) {
            *(s32 *)(arg0 + 0xA0) += 1;
            func_0884D790(D_089CC01C, 0x10, 1);
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        }
        func_08878BDC(arg0);
        break;
    case 29:
        if (!busy()) {
            s32 found;
            s32 bit;

            found = 0;
            bit = 0;
            do {
                if (func_088785CC(arg0, bit) != 0) {
                    *(u32 *)(D_089CC438 + 0x696E4) |= 1 << bit;
                    found++;
                }
                if (found >= 2) {
                    break;
                }
                bit++;
            } while (bit < 0x1B);
            if (func_08878B60(arg0) != 0) {
                func_0884D790(D_089CC01C, 0x10, 0);
                func_08878BC0(arg0);
                *(s32 *)(arg0 + 0xA0) = 0x1C;
            } else if (func_08874218(arg0) != 0) {
                func_08877BE8(arg0);
                *(s32 *)(arg0 + 0xA0) += 1;
                func_0884D790(D_089CC01C, 0x10, 0);
            } else {
                *(s32 *)(arg0 + 0xA0) = 0x1F;
            }
        } else {
            func_08878BDC(arg0);
        }
        break;
    case 30:
        if (*(s16 *)(arg0 + 0xA8) > 0) {
            *(s16 *)(arg0 + 0xA8) -= 1;
        } else if (--*(s16 *)(arg0 + 0xAA) <= 0) {
            *(s16 *)(arg0 + 0xAA) = 0xF;
            *(s16 *)(arg0 + 0xAC) ^= 1;
        }
        if ((--*(s16 *)(arg0 + 0xAC) <= 0 ||
             (*(s16 *)(arg0 + 0xA8) <= 0 && (func_0884FB6C(D_089CC438) & 0x4000))) &&
            *(s8 *)(arg0 + 0xC1) == 0) {
            *(s32 *)(arg0 + 0xA0) += 1;
            func_0884D790(D_089CC01C, 0x10, 1);
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        }
        func_08877C04(arg0);
        break;
    case 31:
        if (!busy()) {
            if (!(*(u8 *)(D_089CC438 + 0x6AC3D) & 2) &&
                func_0884FE80(D_089CC438, 0x290E) != 0) {
                func_08878EEC(arg0);
                *(s32 *)(arg0 + 0xA0) += 1;
                func_0884D790(D_089CC01C, 0x10, 0);
            } else {
                *(s32 *)(arg0 + 0xA0) = 0x21;
            }
        } else {
            func_08877C04(arg0);
        }
        break;
    case 32:
        if (*(s16 *)(arg0 + 0xA8) > 0) {
            *(s16 *)(arg0 + 0xA8) -= 1;
        } else if (--*(s16 *)(arg0 + 0xAA) <= 0) {
            *(s16 *)(arg0 + 0xAA) = 0xF;
        }
        if ((--*(s16 *)(arg0 + 0xAC) <= 0 ||
             (*(s16 *)(arg0 + 0xA8) <= 0 && (func_0884FB6C(D_089CC438) & 0x4000))) &&
            *(s8 *)(arg0 + 0xC1) == 0) {
            *(s32 *)(arg0 + 0xA0) += 1;
            func_0884D790(D_089CC01C, 0x10, 1);
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        }
        func_08878F08(arg0);
        break;
    case 33:
        if (!busy()) {
            if (!(*(u8 *)(D_089CC438 + 0x6AC3D) & 2) &&
                func_0884FE80(D_089CC438, 0x290E) != 0) {
                *(u8 *)(D_089CC438 + 0x6AC3D) |= 2;
            }
            *(s32 *)(arg0 + 0xA0) = 0x22;
        } else {
            func_08878F08(arg0);
        }
        break;
    case 34:
        if (!busy()) {
            for (i = 0; i < 0x3D; i++) {
                if (func_08874278(arg0, i) != 0) {
                    func_088505E0(D_089CC438, func_08857294(D_089CC438, i));
                    func_08850648(D_089CC438, func_08857294(D_089CC438, i));
                }
            }
            if (!(*(s32 *)(D_08A62C7C + 0x28) & 0x1000010)) {
                if (*(s32 *)(D_089CC438 + 0x696E8) - *(s32 *)(arg0 + 0x108) >= 5000) {
                    func_0884FAC4(D_089CC438, 0xC8);
                }
            }
            *(s32 *)(arg0 + 0xA0) += 1;
            func_08882B68(D_08A62D8C, 0x10);
            *(s16 *)(arg0 + 0xA8) = 0x10;
        }
        break;
    case 35:
        if (--*(s16 *)(arg0 + 0xA8) <= 0) {
            func_0887EBFC(arg0);
            *(s32 *)(arg0 + 0xA0) = 0;
            return 1;
        }
        break;
    }
    if (*(s8 *)(arg0 + 0xC1) != 0) {
        if (*(u8 *)(arg0 + 0xC3) > 0) {
            *(u8 *)(arg0 + 0xC3) -= 1;
        } else if (*(u8 *)(arg0 + 0xC2) == 0) {
            func_08882D20(D_08A62D8C, 1, 0x18FF);
            *(u8 *)(arg0 + 0xC2) = 1;
        } else if (func_08882F64(D_08A62D8C, 1) == 0) {
            func_08882C24(D_08A62D8C, 0, 0x10, 0x7F);
            *(s8 *)(arg0 + 0xC1) = 0;
        }
    }
    return 0;
}
