/* unit_088C2168: 0x088C2168-0x088C2B54 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

/* func_088C2168 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern s32 D_08A62C6C;
extern s32 D_08A62D8C;
extern int memset(void *, s32, s32);
extern void func_08852A50(char *);
extern void func_088C12BC(char *, s16);
extern void func_088C1694(char *, s32);
extern char *func_08851680(char *, u16);
extern void func_088BFEF8(char *, char *);
extern void func_088C30B8(char *, u8, s32);
extern void func_088BF858(char *, s32);
extern void func_088BFE54(char *, s32);
extern void func_088BA5BC(s32, s32, s32, s32);
extern void func_088BA494(s32, s32, u16);
extern void func_088BA54C(s32, s32, u16);
extern void func_088BA2E0(s32, s32, s32, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_08883A80(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088C0940(char *, char *);

#define F32(o) (*(s32 *)(arg0 + (o)))
#define F8(o) (*(u8 *)(arg0 + (o)))

static inline u8 any_slot(char *p) {
    s8 i;
    for (i = 0; i < 3; i++) {
        if (*(u8 *)((s32)(i * 0x6B100) + (char *)p + 0x1012) == 1) {
            return 1;
        }
    }
    return 0;
}

static inline s32 yes_no(char *arg0) {
    s32 pad = D_08A62C6C;
    s32 ok;

    if (pad & 0x80) {
        if (F8(4) == 0) {
            F8(4) = 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if (pad & 0x20) {
        if (F8(4) != 0) {
            F8(4) = 0;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else {
        ok = pad & 0x4000;
        if (ok && F8(4) != 0) {
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            return 2;
        }
        if ((pad & 0x2000) || (ok && F8(4) == 0)) {
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            return 1;
        }
    }
    return 0;
}

s32 func_088C2168(char *arg0) {
    s32 ret;
    s32 prev;
    s32 st;
    s32 pad;
    s32 r;

    ret = 0;
    switch (F32(0xC)) {
    case 0:
        func_08852A50(D_089CC438);
        func_088C12BC(arg0, 0);
        F8(4) = 1;
        F32(0x97C) = -1;
        memset(arg0 + 0x980, 0, 8);
        F32(0xC) = 1;
        memset(*(char **)(arg0 + 0x950), 0, 0x16A100);
        func_088C1694(arg0, 1);
    case 1:
        if (F8(0x970) == 0) {
            st = F32(0x34);
            if (st == 0 || (st == 2 && F32(0x5E4) == 0) || st == (s32)0x80110307 ||
                st == (s32)0x80110309 || st == (s32)0x80110306) {
                if (st == (s32)0x80110307) {
                    func_088BFEF8(arg0, func_08851680(D_089CC438, 0x62));
                    F32(0xC) = 7;
                } else if (st == (s32)0x80110309 || st == (s32)0x80110306) {
                    func_088BFEF8(arg0, func_08851680(D_089CC438, 0x63));
                    F32(0xC) = 7;
                } else {
                    func_088C30B8(arg0, 0, 1);
                    F32(0xC) = 2;
                }
            } else if (st == 2 && F32(0x5E4) == 1) {
                memset(*(char **)(arg0 + 0x94C), 0, 0x16A100);
                func_088BF858(arg0, 0);
            } else {
                func_088BFE54(arg0, st);
                F32(0xC) = 7;
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 2:
        if (F8(0x4A88) == 0) {
            if (F8(0x4A89) == 0) {
                func_088BFEF8(arg0, func_08851680(D_089CC438, 0x63));
                F32(0xC) = 7;
            } else if (!any_slot(*(char **)(arg0 + 0x950))) {
                func_088BFEF8(arg0, func_08851680(D_089CC438, 0x64));
                F32(0xC) = 7;
            } else {
                st = *(s32 *)(*(char **)(arg0 + 0x950) + 0x24);
                if (st != 0) {
                    F32(8) = st - 1;
                } else {
                    for (F32(8) = 0; F32(8) < 3; F32(8)++) {
                        if (*(u8 *)(*(char **)(arg0 + 0x950) + (s8)F32(8) * 0x6B100 + 0x1012) == 1) {
                            break;
                        }
                    }
                }
                F32(0xC) = 3;
                func_08883988(D_08A62D8C, 0, 0x24, 0, 0, 0, 0, 0, 0);
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 3:
        pad = D_08A62C6C;
        prev = F32(8);
        if (pad & 0x10) {
            do {
                if (--F32(8) < 0) {
                    F32(8) = 2;
                }
            } while (*(u8 *)(*(char **)(arg0 + 0x950) + *(s8 *)(arg0 + 8) * 0x6B100 + 0x1012) != 1);
        } else if (pad & 0x40) {
            do {
                if (++F32(8) > 2) {
                    F32(8) = 0;
                }
            } while (*(u8 *)(*(char **)(arg0 + 0x950) + *(s8 *)(arg0 + 8) * 0x6B100 + 0x1012) != 1);
        } else if (pad & 0x2000) {
            F32(0xC) = 8;
            F8(4) = 0;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else if (pad & 0x4000) {
            *(char **)(arg0 + 0x958) = *(char **)(arg0 + 0x950) + prev * 0x6B100 + 0x1000;
            *(char **)(arg0 + 0x960) = *(char **)(arg0 + 0x950) + 0x10;
            F8(4) = 1;
            F32(0xC) = 4;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        }
        if (prev != F32(8)) {
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
        func_088C0940(arg0, *(char **)(arg0 + 0x950));
        func_088BA5BC(0xA8, 0xD0, 0x130, 0x30);
        func_088BA54C(0xB0, 0xD8, 0x2D);
        break;
    case 4:
        func_088C0940(arg0, *(char **)(arg0 + 0x950));
        func_088BA5BC(0xA8, 0xD0, 0x130, 0x30);
        func_088BA54C(0xB0, 0xD8, 0x2E);
        func_088BA2E0(0x158, 0xE8, F8(4), 1);
        r = yes_no(arg0);
        if (r == 2) {
            F32(0xC) = 5;
        } else if (r == 1) {
            F32(0xC) = 3;
        }
        break;
    case 5:
        if (D_08A62C6C & 0x4000) {
            F32(0xC) = 5;
            func_08883A80(D_08A62D8C, 1, 2, 0, 0, 0, 0, 0);
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            F32(0xC) = 6;
            ret = 1;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0x2F);
        break;
    case 6:
        break;
    case 7:
        if (F8(0x971) == 0) {
            F32(0xC) = 8;
            F8(4) = 0;
        }
        break;
    case 8:
        r = yes_no(arg0);
        if (r == 2) {
            F32(0xC) = 6;
            ret = 4;
        } else if (r == 1) {
            F32(0xC) = 6;
            ret = 2;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x2C);
        func_088BA2E0(0xB8, 0xA0, F8(4), 1);
        break;
    }
    return ret;
}
