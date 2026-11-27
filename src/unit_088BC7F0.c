/* unit_088BC7F0: 0x088BC7F0-0x088BD75C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088BC7F0 (ULES01213), piece text_088BC7F0 (0xF6C bytes).
 *
 * Optimized for speed: the loops are guarded and tested at the bottom.
 * State machine of the save data load screen (state word at +0xC, jump
 * table of ten cases). The two name tables are copied whole from the data
 * onto the stack at entry (D_089B3604: 0x3C0 words, D_089B4B10: 0xAA
 * words). func_088BFE54 receives the status word kept in a1 as its second
 * argument.
 */

#pragma optimize_for_size off
typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char *e[0x3C0];
} Names1;

typedef struct {
    char *e[0xAA];
} Names2;

extern Names1 D_089B3604;
extern Names2 D_089B4B10;

extern char *D_089CC438;
extern char *D_089CC434;
extern char *D_089CBBEC;
extern char *D_08A62C64;
extern s32 D_08A62C6C;
extern s32 D_08A62D8C;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09A4F0C4;

extern int func_08852A50(char *);
extern void func_088C12BC(char *, s32);
extern void func_088BF858(void *, s32);
extern void func_088C30B8(char *, s32, s32);
extern char *func_08851680(char *, u16);
extern void func_088BFEF8(char *, char *);
extern void func_088BFE54(char *, s32);
extern void func_088BA5BC(s16, s16, s16, s16);
extern void func_088BA494(s32, s32, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_08883A80(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088B96D8(char *, s32, s32);
extern s32 func_088C0E58(char *);
extern void func_088B97A0(char *);
extern void func_088DB068(s32);
extern void func_088DB338(s32);
extern void func_088DB39C(s32);
extern void func_088C0940(char *, char *);
extern void func_088BA54C(s32, s32, s32);
extern void func_08890E38(char *, s8);
extern void func_088C05FC(char *, char *, s32);
extern void func_08832C60(char *, s32);
extern void func_088C1178(char *, s16);
extern void func_088C1344(char *, s16);
extern void func_088BA2E0(s32, s32, u8, s32);
extern void func_08880864(s32, s32);
extern void func_08880874(s32, s32);
extern void func_088BA664(s32, s32);
extern s32 func_088855C4(s32, s32, s32, s32);
extern void func_088900A0(char *);
extern int func_0880ED04(char *, char *);
extern int func_0880ED70(char *, char *);
extern void memcpy(void *, void *, s32);
extern void memset(void *, s32, s32);

typedef struct {
    u8 pad[0x1012];
    u8 used;
    u8 pad2[0x6B100 - 0x1013];
} Slot;

static inline u8 has_save(Slot *base) {
    s8 i;

    for (i = 0; i < 3; i++) {
        if (base[i].used == 1) {
            return 1;
        }
    }
    return 0;
}

static inline s32 confirm(char *p) {
    s32 btn = D_08A62C6C;

    if (btn & 0x80) {
        if (*(u8 *)(p + 4) == 0) {
            *(u8 *)(p + 4) = 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if (btn & 0x20) {
        if (*(u8 *)(p + 4) != 0) {
            *(u8 *)(p + 4) = 0;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if ((btn & 0x4000) && *(u8 *)(p + 4) != 0) {
        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        return 2;
    } else if ((btn & 0x2000) || ((btn & 0x4000) && *(u8 *)(p + 4) == 0)) {
        func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}

s32 func_088BC7F0(char *p) {
    Names1 n1 = D_089B3604;
    Names2 n2 = D_089B4B10;
    s32 r;
    s32 old;
    s32 kind;
    s32 err;
    s32 btn;
    s32 i;
    s32 i2;
    s32 f1;
    char **q2;
    s32 f2;
    char **q1;

    r = 0;
    switch (*(s32 *)(p + 0xC)) {
    case 0:
        func_08852A50(D_089CC438);
        func_088C12BC(p, 0);
        *(u8 *)(p + 4) = 1;
        *(s32 *)(p + 0x97C) = -1;
        memset(p + 0x980, 0, 8);
        *(s32 *)(p + 0xC) = 1;
        memset(*(char **)(p + 0x94C), 0, 0x16A100);
        func_088BF858(p, 0);
        *(u8 *)(p + 0x964) = *(s8 *)(D_089CC438 + 0x6ADDC) != 0;
    case 1:
        if (*(u8 *)(p + 0x970) == 0) {
            err = *(s32 *)(p + 0x34);
            if (err == 0 || (err == 2 && *(s32 *)(p + 0x5E4) == 0)) {
                func_088C30B8(p, 0, 0);
                *(s32 *)(p + 0xC) = 8;
            } else if (err == (s32)0x80110307) {
                func_088BFEF8(p, func_08851680(D_089CC438, 0x3E));
                *(s32 *)(p + 0xC) = 9;
            } else if (err == 2 && *(s32 *)(p + 0x5E4) == 1) {
                memset(*(char **)(p + 0x94C), 0, 0x16A100);
                func_088BF858(p, 0);
            } else {
                func_088BFE54(p, err);
                *(s32 *)(p + 0xC) = 9;
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 8:
        if (*(u8 *)(p + 0x4A88) == 0) {
            if (*(u8 *)(p + 0x4A89) == 0) {
                func_088BFEF8(p, func_08851680(D_089CC438, 2));
                *(s32 *)(p + 0xC) = 9;
            } else if (!has_save(*(Slot **)(p + 0x94C))) {
                func_088BFEF8(p, func_08851680(D_089CC438, 0xB));
                *(s32 *)(p + 0xC) = 9;
            } else {
                memcpy(p + 0x988, *(char **)(p + 0x94C) + 0x16A0E0, 8);
                if (*(s32 *)(*(char **)(p + 0x94C) + 0x24) != 0) {
                    *(s32 *)(p + 8) = *(s32 *)(*(char **)(p + 0x94C) + 0x24) - 1;
                } else {
                    for (*(s32 *)(p + 8) = 0; *(s32 *)(p + 8) < 3; (*(s32 *)(p + 8))++) {
                        if (*(u8 *)(*(char **)(p + 0x94C) + (s8)*(s32 *)(p + 8) * 0x6B100 + 0x1012) == 1) {
                            break;
                        }
                    }
                }
                if (*(u8 *)(p + 0x964) != 0) {
                    *(s32 *)(p + 0xC) = 3;
                    *(s32 *)(p + 0x99C) = 0x28;
                    func_08883988(D_08A62D8C, 0, 0x24, 0, 0, 0, 0, 0, 0);
                } else {
                    *(s32 *)(p + 0xC) = 2;
                    *(s32 *)(p + 0x99C) = 0;
                    *(s32 *)(p + 0x998) = 0;
                    func_088B96D8(D_089CC434, 3, 0);
                }
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 2:
        if ((u8)func_088C0E58(p) == 0) {
            break;
        }
        *(u16 *)(p + 0x9A0) = 0;
        func_088C12BC(p, 1);
        *(s32 *)(p + 0xC) = 3;
        func_088B97A0(D_089CC434);
        func_08883988(D_08A62D8C, 0, 0x24, 0, 0, 0, 0, 0, 0);
        func_088DB068(D_09A4F0C4);
        func_088DB338(D_09A4F0C4);
        func_088DB39C(D_09A4F0C4);
        break;
    case 3:
        old = *(s32 *)(p + 8);
        btn = D_08A62C6C;
        if (btn & 0x10) {
            do {
                if (--*(s32 *)(p + 8) < 0) {
                    *(s32 *)(p + 8) = 2;
                }
            } while (*(u8 *)(*(char **)(p + 0x94C) + (s8)*(s32 *)(p + 8) * 0x6B100 + 0x1012) != 1);
        } else if (btn & 0x40) {
            do {
                if (++*(s32 *)(p + 8) > 2) {
                    *(s32 *)(p + 8) = 0;
                }
            } while (*(u8 *)(*(char **)(p + 0x94C) + (s8)*(s32 *)(p + 8) * 0x6B100 + 0x1012) != 1);
        } else if (btn & 0x2000) {
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            r = 2;
        } else if (btn & 0x4000) {
            *(u8 *)(p + 4) = 1;
            *(s32 *)(p + 0xC) = 4;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        }
        if (old != *(s32 *)(p + 8)) {
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
        func_088C0940(p, *(char **)(p + 0x94C));
        func_088BA5BC(0xA8, 0xD0, 0x130, 0x30);
        func_088BA54C(0xB0, 0xD8, 0x19);
        if (*(u8 *)(p + 0x964) != 0) {
            func_088BA5BC(0x108, 0x38, 0xD0, 0x98);
            func_08890E38(D_08A631A8, 0);
            func_088BA494(0x170, 0x40, 0x1A);
            func_088C05FC(p, *(char **)(p + 0x94C) + *(s32 *)(p + 8) * 0x6B100 + 0x1000, 0);
        } else {
            func_08832C60(D_089CBBEC, 0);
            if (*(s8 *)(D_08A62C64 + 2) < -0x50) {
                *(u16 *)(p + 0x9A0) -= 0x400;
            } else if (*(s8 *)(D_08A62C64 + 2) > 0x50) {
                *(u16 *)(p + 0x9A0) += 0x400;
            }
            func_088C1178(p, (s16)*(s32 *)(p + 8));
        }
        break;
    case 4:
        func_088C0940(p, *(char **)(p + 0x94C));
        func_088BA5BC(0xA8, 0xD0, 0x130, 0x30);
        func_088BA54C(0xB0, 0xD8, 0xC);
        func_088BA2E0(0x158, 0xE8, *(u8 *)(p + 4), 1);
        if (*(u8 *)(p + 0x964) != 0) {
            func_088BA5BC(0x108, 0x38, 0xD0, 0x98);
            func_08890E38(D_08A631A8, 0);
            func_088BA494(0x170, 0x40, 0x1A);
            func_088C05FC(p, *(char **)(p + 0x94C) + *(s32 *)(p + 8) * 0x6B100 + 0x1000, 0);
        } else {
            func_08832C60(D_089CBBEC, 0);
            if (*(s8 *)(D_08A62C64 + 2) < -0x50) {
                *(u16 *)(p + 0x9A0) -= 0x400;
            } else if (*(s8 *)(D_08A62C64 + 2) > 0x50) {
                *(u16 *)(p + 0x9A0) += 0x400;
            }
            func_088C1178(p, (s16)*(s32 *)(p + 8));
        }
        kind = confirm(p);
        if (kind == 2) {
            if ((*(s32 *)(p + 0x990) & 2) == 0) {
                *(u16 *)(p + 0x9A0) = 0;
                *(s32 *)(p + 0xC) = 5;
                break;
            }
            r = 1;
            memcpy(D_089CC438 + 0x4A0, *(char **)(p + 0x94C) + *(s32 *)(p + 8) * 0x6B100 + 0x1000, 0x6A938);
            memcpy(D_089CC438 + 0x6ADD8, *(char **)(p + 0x94C), 0xE);
            memcpy(D_089CC438 + 0x6ADE8, *(char **)(p + 0x94C) + 0x10, 0x14);
            func_08880864(D_08A62D8C, *(s8 *)(D_089CC438 + 0x6ADDB));
            func_08880874(D_08A62D8C, *(s8 *)(D_089CC438 + 0x6ADDA));
            *(u8 *)(D_089CC438 + 0x6ADD8) = *(s32 *)(D_08A631A0 + 0xF7A574);
            *(s32 *)(p + 0x97C) = *(s32 *)(p + 8);
            memcpy(p + 0x980, p + 0x988, 8);
            *(s32 *)(p + 0xC) = 7;
        } else if (kind == 1) {
            *(s32 *)(p + 0xC) = 3;
        }
        break;
    case 5:
        if (D_08A62C6C & 0x4000) {
            if (*(u8 *)(p + 0x964) == 0) {
                func_088C1344(p, (s16)*(s32 *)(p + 8));
            }
            func_088C12BC(p, 2);
            *(s32 *)(p + 0xC) = 6;
            func_08883A80(D_08A62D8C, 1, 2, 0, 0, 0, 0, 0);
            func_08883988(D_08A62D8C, 6, 0x2E, 0, 0, 1, 0, 0, 0);
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0xD);
        func_088BA664(0x9C, 0xA0);
        if (*(u8 *)(p + 0x964) == 0) {
            func_088C1178(p, (s16)*(s32 *)(p + 8));
        }
        break;
    case 6:
        if (*(u8 *)(p + 0x964) == 0) {
            func_088C1178(p, (s16)*(s32 *)(p + 8));
        }
        if ((*(s32 *)(p + 0x99C))++ <= 0x28) {
            break;
        }
        if (func_088855C4(D_08A62D8C, 6, 0, 1) != 0) {
            break;
        }
        r = 1;
        memcpy(D_089CC438 + 0x4A0, *(char **)(p + 0x94C) + *(s32 *)(p + 8) * 0x6B100 + 0x1000, 0x6A938);
        memcpy(D_089CC438 + 0x6ADD8, *(char **)(p + 0x94C), 0xE);
        memcpy(D_089CC438 + 0x6ADE8, *(char **)(p + 0x94C) + 0x10, 0x14);
        func_08880864(D_08A62D8C, *(s8 *)(D_089CC438 + 0x6ADDB));
        func_08880874(D_08A62D8C, *(s8 *)(D_089CC438 + 0x6ADDA));
        *(u8 *)(D_089CC438 + 0x6ADD8) = *(s32 *)(D_08A631A0 + 0xF7A574);
        func_088900A0(D_08A631A0);
        *(s32 *)(p + 0x97C) = *(s32 *)(p + 8);
        memcpy(p + 0x980, p + 0x988, 8);
        f1 = 0;
        old = *(s32 *)(D_08A631A0 + 0xF7A574);
        if (*(u8 *)(D_089CC438 + 0x6A210) != 0) {
            i = 0;
            q1 = n1.e;
            do {
                if (func_0880ED04(D_089CC438 + 0x6A210, *q1) == 0) {
                    f1 = 1;
                    break;
                }
                i++;
                q1++;
            } while (i < 0x3C0);
            if (f1 == 1) {
                if (i >= 0xC0) {
                    i %= 0xC0;
                }
                memset(D_089CC438 + 0x6A210, 0, 0x13);
                func_0880ED70(D_089CC438 + 0x6A210, n1.e[i + (old - 1) * 0xC0]);
            }
            f2 = 0;
            i2 = 0;
            q2 = n2.e;
            do {
                if (func_0880ED04(D_089CC438 + 0x6A224, *q2) == 0) {
                    f2 = 1;
                    break;
                }
                i2++;
                q2++;
            } while (i2 < 0xAA);
            if (f2 == 1) {
                if (i2 >= 0x22) {
                    i2 %= 0x22;
                }
                memset(D_089CC438 + 0x6A224, 0, 0x10);
                func_0880ED70(D_089CC438 + 0x6A224, n2.e[i2 + (old - 1) * 0x22]);
            }
        }
        *(s32 *)(p + 0xC) = 7;
        break;
    case 7:
        if (*(u8 *)(p + 0x964) == 0) {
            func_088C1178(p, (s16)*(s32 *)(p + 8));
        }
        break;
    case 9:
        if (*(u8 *)(p + 0x971) == 0) {
            r = 2;
        }
        break;
    }
    return r;
}
