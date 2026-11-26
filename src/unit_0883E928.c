/* unit_0883E928: 0x0883E928-0x0883F0CC (ULES01213)
 *
 * State machine on the byte at 0x52F of p, driven by the pad word: one
 * case per state (jump table, 0x08931124-0x08931144, in .data), then a
 * shared tail that counts down the byte at 0x592.
 *
 * func_08823AE4 takes (p, p[0x58D]): its second argument stays in a1
 * from the compare (the callee masks a1 with 0xFF).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CC438;
extern char *D_08A62C50;
extern s32 D_08A62D8C;
extern s32 D_09B22D70;

extern u8 func_08830728(char *, s8, s16, s16);
extern u8 func_08823AE4(char *, u8);
extern s32 func_0885C3DC(char *, u16);
extern s32 func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0881C098(char *, char *, u16, s32);
extern s16 func_08826734(char *, u8);
extern void func_0881C520(char *, u16, s32);
extern void func_088D839C(char *, s32);
extern s32 func_088D72A4(char *, u16, s16, s32);
extern void func_088D8900(char *);
extern void func_09A7B178(s32, s32);
extern u16 func_08853ABC(char *, u16, u16, u16);

s32 func_0883E928(u8 *p, u16 pad) {
    s8 t;

    switch (p[0x52F]) {
    case 0:
        if (*(s16 *)(p + 0x119E) != 0) {
            (*(s16 *)(p + 0x119E))--;
        }
        return 0;
    case 1:
        if (*(u8 *)(p + 0x58D) == 0xFF) {
            p[0x58D] = func_08830728((char *)p, 1, 0, *(s16 *)(p + 0x590));
            *(s8 *)(p + 0x592) = -1;
        } else {
            if (*(u8 *)(p + 0x58D) == *(u8 *)(D_089CC438 + 0x381)) {
                p[0x52F] = p[0x52F] + 1;
                p[0x592] = 4;
                *(u32 *)(p + 0x528) |= 0x100;
                return 1;
            }
            if (func_08823AE4((char *)p, p[0x58D]) == 0) {
                p[0x52F]++;
                p[0x592] = 0;
                *(u32 *)(p + 0x528) |= 0x100;
                return 1;
            }
            return 1;
        }
        return 0;
    case 2:
        p[0x594] = 0;
        if ((s32)(func_0885C3DC(D_08A62C50, *(u16 *)(p + 0x590)) < *(s8 *)(p + 0x593)) == 0) {
            p[0x58C] = 0;
        } else {
            p[0x58C] = 1;
        }
        *(u32 *)(p + 0x528) &= ~0x800;
        p[0x52F]++;
    case 3:
        p[0x594] = (*(s8 *)(p + 0x594) + 1) & 0x7F;
        if (*(s8 *)(p + 0x594) < 0x40) {
            *(s16 *)(p + 0x58E) = 0x14;
        } else {
            *(s16 *)(p + 0x58E) = *(u16 *)(p + 0x590) + 0x18;
        }
        func_0881C098((char *)p, (char *)p + 0x586, pad & 0xA0, 0x18);
        if (pad & 0x4000) {
            switch (*(u8 *)(p + 0x58C)) {
            case 0:
                if ((s32)(func_0885C3DC(D_08A62C50, *(u16 *)(p + 0x590)) < *(s8 *)(p + 0x593)) == 0) {
                    p[0x52F] = 7;
                    func_08883988(D_08A62D8C, 1, 0x88, 0, 0, 0, 0, 0, 0);
                    p[0x580] = 6;
                } else {
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                }
                break;
            case 1:
                *(s16 *)(p + 0x58E) = 0x15;
                p[0x5DA] = 0;
                p[0x52F]++;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                break;
            case 2:
                p[0x52F] = 6;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                break;
            }
        } else if (pad & 0x50) {
            if (pad & 0x10) {
                if (*(u8 *)(p + 0x58C) == 0) {
                    p[0x58C] = 2;
                } else {
                    p[0x58C]--;
                }
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            } else if (pad & 0x40) {
                p[0x58C]++;
                if (*(u8 *)(p + 0x58C) > 2) {
                    p[0x58C] = 0;
                }
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
        }
        break;
    case 4:
        if (p[0x5DA] != 0) {
            if (pad & 0xA000) {
                p[0x5DA] = 0;
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            }
            pad &= 0xDFFF;
        } else if (pad & 0x8000) {
            p[0x5DA] = 1;
            func_08883988(D_08A62D8C, 0, 9, 0, 0, 0, 0, 0, 0);
        }
        func_0881C098((char *)p, (char *)p + 0x586, pad, 0x18);
        if (pad & 0x4000) {
            *(s16 *)(p + 0x58E) = 0x16;
            p[0x5DA] = 0;
            p[0x537] = 1;
            p[0x52F]++;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        } else if (pad & 0x2000) {
            *(s16 *)(p + 0x58E) = 0x14;
            p[0x594] = 0;
            p[0x52F] = 3;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else if (p[0x5DA] == 0) {
            *(s16 *)(p + 0x58E) = 0x15;
        } else {
            *(s16 *)(p + 0x58E) = func_08826734((char *)p, p[0x586]) + 0x18;
        }
        break;
    case 5:
        *(s16 *)(p + 0x58E) = 0x16;
        func_0881C520((char *)p, pad, 0x50);
        if (pad & 0x4000) {
            if (p[0x537] == 0) {
                func_088D839C(*(char **)(p + 0x530), p[0x586]);
                func_088D72A4(*(char **)(p + 0x530), *(u16 *)(p + 0x590), *(s8 *)(p + 0x593), 0);
                if ((s32)((*(u32 *)(D_089CC438 + 0x6AF14) & 1) != 0) == 1) {
                    func_088D8900(*(char **)(p + 0x530));
                }
                p[0x52F] = 6;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            } else {
                p[0x52F] = 4;
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            }
        } else if (pad & 0x2000) {
            p[0x52F] = 4;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 6:
        p[0x52F] = 0;
        *(s16 *)(p + 0x590) = 0;
        if (p[0x52D] != 0 && p[0x57D] == 0) {
            *(u32 *)(p + 0x5E8) |= 4;
        } else {
            *(u32 *)(p + 0x528) &= ~0x100;
            *(u32 *)(p + 0x5E8) &= ~4;
        }
        return 0;
    case 7:
        p[0x580]--;
        if (p[0x580] == 0) {
            func_09A7B178(D_09B22D70, 0x14);
            func_08853ABC(D_089CC438, *(u16 *)(p + 0x590), *(s8 *)(p + 0x593), 0xFFFF);
            p[0x52F] = 0;
            *(s16 *)(p + 0x590) = 0;
            if (p[0x52D] != 0 && p[0x57D] == 0) {
                *(u32 *)(p + 0x5E8) |= 4;
            } else {
                *(u32 *)(p + 0x528) &= ~0x100;
                *(u32 *)(p + 0x5E8) &= ~4;
            }
            return 0;
        }
        break;
    }
    t = *(s8 *)(p + 0x592);
    if (t >= 0) {
        if (t > 0) {
            p[0x592] = t - 1;
        }
        if (*(u8 *)(p + 0x58D) != *(u8 *)(D_089CC438 + 0x381)) {
            *(s8 *)(p + 0x592) = -1;
        }
    }
    return 1;
}
