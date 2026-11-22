/* unit_088795F4: 0x088795F4-0x08879FA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern "C" {
extern char *D_08A62C7C;
extern char *D_08A62CB4;
extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_09A0B544;
extern s32 D_09A4F0C4;
extern s32 D_09CFBBC8;

extern s32 func_0886A30C(char *, s32);
extern char *func_088DCEBC(s32, s32);
extern s32 func_0880BFF0(void *, void *, s32);
extern s32 func_08873488(char *);
extern char *func_08857C38(char *);
extern s32 func_088D6A1C(char *, s32);
extern void func_09C267D0(s32, char *);
}

static inline bool id_in_list(u16 id) {
    if (id == 0x3E9 || id == 0x3EA || id == 0x3EB || id == 0x44D || id == 0x44E ||
        id == 0x44F || id == 0x7D1 || id == 0x7D2 || id == 0x7D3 || id == 0x835 ||
        id == 0x836 || id == 0x837 || id == 0xBB9 || id == 0xBBA || id == 0xBBB ||
        id == 0xBBC || id == 0xBBD || id == 0xC1D || id == 0xC1E || id == 0x2775 ||
        id == 0x2776 || id == 0x2777 || id == 0x27D9 || id == 0x27DA || id == 0x283D) {
        return true;
    }
    return false;
}

static inline u8 step_of(s16 x) {
    if (x < 1000) {
        return 0;
    } else if (x < 2500) {
        return 1;
    } else if (x < 4500) {
        return 2;
    } else if (x < 6000) {
        return 3;
    } else if (x < 7000) {
        return 4;
    }
    return 5;
}

/* 0xC8-byte record of the array read at D_09A0B544 + 0xBC8 / + 0xBE0. */
typedef struct {
    u8 pad[0xC8];
} Pl;

extern "C" void func_088795F4(char *arg0) {
    char *p;
    char *rec;
    char *ent;
    u32 add;
    s32 j;
    s8 n;
    char *tot;
    char *base;
    char *sub;
    char *q;
    s32 i;
    s32 *pp;
    u32 old;
    u32 k;
    u32 a;
    u32 b;
    u32 c;
    s32 flags;
    u8 r1;
    u8 r2;
    u8 flag;
    u8 *cp;

    *(s16 *)(arg0 + 0xA4) = 0;
    *(s16 *)(arg0 + 0xA6) = 0;
    *(s16 *)(arg0 + 0xAA) = 0xE10;
    *(s16 *)(arg0 + 0xA8) = 10;
    if (func_0886A30C(D_08A62C7C, 1) == 1) {
        *(s32 *)(D_08A62CB4 + 0x14) = *(s32 *)(*(char **)(D_08A62C7C + 0x4C) + 0x3C);
    } else {
        *(s32 *)(D_08A62CB4 + 0x14) = *(s32 *)(*(char **)(D_08A62C7C + 0x4C) + 0x40);
    }
    *(s32 *)(D_08A62CB4 + 0x18) = *(s32 *)(D_08A62CB4 + 0x14);
    p = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    *(s32 *)(D_08A62CB4 + 0x14) -= *(u8 *)(p + 0x113E) * 10;
    pp = (s32 *)(D_08A62CB4 + 0x14);
    if (*pp < 0) {
        *pp = 0;
    }
    if ((bool)(*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1) {
        if (func_0886A30C(D_08A62C7C, 1) == 1) {
            n = *(s8 *)(D_09A0B544 + 0xBBD);
            rec = D_08A62C7C;
            flags = *(s32 *)(rec + 0x28);
            add = 0;
            if (flags & 0x10) {
                add = (*(s32 *)(rec + 0x5B0) + *(s32 *)(rec + 0x5B4)) / 400;
            } else if (flags & 0x1000000) {
                add = *(u32 *)(arg0 + 0x120) / 200;
            } else if (!id_in_list(*(u16 *)(D_089CC438 + 0x6AF12))) {
                add = *(u32 *)(D_08A62CB4 + 0x14) / 20;
            }
            base = D_089CC438;
            sub = base + 0x4A0;
            tot = sub + 0x672B8;
            if (n > 1) {
                ent = base + 0x4A58;
                for (i = 0; i < 0x60; i++, ent += 0x1078, sub += 4) {
                    if (*(u16 *)ent == 0) {
                        continue;
                    }
                    for (j = 0; j < n; j++) {
                        q = (char *)&((Pl *)(D_09A0B544 + 0xBE0))[j];
                        if ((bool)*(u8 *)(D_089CC438 + (u8)j * 0x8C + 0x30) == 0) {
                            continue;
                        }
                        if (func_0880BFF0(ent + 0x248, q + 0x71, 8) != 0) {
                            continue;
                        }
                        if (func_0880BFF0(ent, (char *)&((Pl *)(D_09A0B544 + 0xBC8))[j], 0x10) != 0) {
                            continue;
                        }
                        *(u32 *)(tot + 0x30) += add;
                        if (*(u32 *)(tot + 0x30) > 999999) {
                            *(u32 *)(tot + 0x30) = 999999;
                        }
                        old = *(u32 *)(sub + 0x69EE4);
                        *(u32 *)(sub + 0x69EE4) = old + add;
                        if (*(u32 *)(sub + 0x69EE4) > 999999) {
                            *(u32 *)(sub + 0x69EE4) = 999999;
                        }
                        k = *(u32 *)(sub + 0x69EE4) / 1000;
                        if (old / 1000 == k) {
                            break;
                        }
                        if (k != 0 && k < 6) {
                            *(u8 *)(D_089CC438 + 0x6AC3B) += 2;
                            cp = (u8 *)(D_089CC438 + 0x6AC3B);
                            if (*cp > 99) {
                                *cp = 99;
                            }
                        } else {
                            *(u8 *)(D_089CC438 + 0x6AC3C) += 1;
                            cp = (u8 *)(D_089CC438 + 0x6AC3C);
                            if (*cp > 99) {
                                *cp = 99;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    if (func_08873488(D_08A62C7C) == 0) {
        return;
    }
    rec = func_08857C38(D_089CC438);
    p = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    k = *(u32 *)(D_08A62CB4 + 0x18);
    if (!id_in_list(*(u16 *)(D_089CC438 + 0x6AF12))) {
        a = k / 10;
        b = *(u32 *)(D_08A62CB4 + 0x18) / 100;
        c = *(u32 *)(D_08A62CB4 + 0x18) / 10;
        if (a < 20) {
            a = 20;
        }
        if (b < 2) {
            b = 2;
        }
        if (c < 20) {
            c = 20;
        }
        if (func_088D6A1C(p, 0xBE)) {
            a = a * 15 / 10;
        } else if (func_088D6A1C(p, 0xBF)) {
            a = a * 15 / 10;
            c = c * 15 / 10;
        }
        *(u16 *)(rec + 0x26) += (u16)a;
        if (*(u16 *)(rec + 0x26) > 10000) {
            *(u16 *)(rec + 0x26) = 10000;
        }
        *(u32 *)(rec + 0x30) += (u16)b;
        if (*(u32 *)(rec + 0x30) > 9999) {
            *(u32 *)(rec + 0x30) = 9999;
        }
        r1 = step_of(*(s16 *)(rec + 0x2A));
        if (*(s16 *)(rec + 0x2A) < 7000) {
            *(s16 *)(rec + 0x2A) += (s16)(u16)c;
            if (*(s16 *)(rec + 0x2A) >= 7000) {
                *(s16 *)(rec + 0x2A) = 7000;
                cp = (u8 *)(D_089CC438 + 0x687CF);
                if (*cp < 250) {
                    *cp += 1;
                }
            }
        }
        r2 = step_of(*(s16 *)(rec + 0x2A));
        if (r1 < r2) {
            *(s8 *)rec |= 0x80;
            flag = 1;
        } else {
            flag = 0;
        }
        if (flag == 1) {
            func_09C267D0(D_09CFBBC8, rec);
        }
    }
    if (*(u8 *)(rec + 0x4A) < 0xFF) {
        *(u8 *)(rec + 0x4A) += 1;
    }
}
