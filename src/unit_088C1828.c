/* unit_088C1828: 0x088C1828-0x088C2168 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088C0BBC's neighbours and
 * unit_088C2B54. State machine on the state word at +0xC (jump table
 * jtbl_089322E8, 9 words at 0x089322E8, owned by this function).
 *
 * Optimized for speed (the slot search loop keeps an offset counter). The
 * records at +0x950 are 0x15000 bytes apart, as in func_088C0BBC.
 * func_088BFE54 takes the error code as a second argument (a1 still holds it
 * at the call).
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern s32 D_08A62C6C;
extern s32 D_08A62D8C;

extern int memset(void *, s32, s32);
extern int func_08852A50(s32);
extern void func_088C12BC(char *, s32);
extern void func_088C14C8(char *, s32);
extern char *func_08851680(char *, u16);
extern void func_088BFEF8(char *, char *);
extern s32 func_088C0420(char *);
extern void func_088BFE54(char *, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_08883A80(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088BA5BC(s16, s16, s16, s16);
extern void func_088BA494(s32, s32, u16);
extern void func_088BA54C(s32, s32, u16);
extern void func_088BA2E0(s32, s32, s32, s32);
extern void func_088C0BBC(char *);

static inline u8 has_save(char *p) {
    s8 i;

    for (i = 0; i < 3; i++) {
        if (*(u8 *)((s32)(i * 0x15000) + p + 0x1000) == 1) {
            return 1;
        }
    }
    return 0;
}

static inline s32 yes_no(char *arg0) {
    s32 pad = D_08A62C6C;

    if (pad & 0x80) {
        if (*(u8 *)(arg0 + 4) == 0) {
            *(u8 *)(arg0 + 4) = 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if (pad & 0x20) {
        if (*(u8 *)(arg0 + 4) != 0) {
            *(u8 *)(arg0 + 4) = 0;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if ((pad & 0x4000) && *(u8 *)(arg0 + 4) != 0) {
        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        return 2;
    } else if ((pad & 0x2000) || ((pad & 0x4000) && *(u8 *)(arg0 + 4) == 0)) {
        func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}

s32 func_088C1828(char *arg0) {
    s32 old;
    s32 ret;
    s32 err;
    s32 r;
    s32 pad;

    ret = 0;
    switch (*(s32 *)(arg0 + 0xC)) {
    case 0:
        func_08852A50((s32)D_089CC438);
        func_088C12BC(arg0, 0);
        *(u8 *)(arg0 + 4) = 1;
        *(s32 *)(arg0 + 0x97C) = -1;
        memset(arg0 + 0x980, 0, 8);
        *(s32 *)(arg0 + 0xC) = 1;
        memset(*(char **)(arg0 + 0x950), 0, 0x16A100);
        func_088C14C8(arg0, 1);
    case 1:
        if (*(u8 *)(arg0 + 0x970) == 0) {
            err = *(s32 *)(arg0 + 0x34);
            if (err == 0 || (err == 2 && *(s32 *)(arg0 + 0x5E4) == 0) || err == 0x80110307 ||
                err == 0x80110309 || err == 0x80110306) {
                if (err == 0x80110307) {
                    func_088BFEF8(arg0, func_08851680(D_089CC438, 0x5F));
                    *(s32 *)(arg0 + 0xC) = 7;
                } else if (err == 0x80110309 || err == 0x80110306 || func_088C0420(arg0) == 0) {
                    func_088BFEF8(arg0, func_08851680(D_089CC438, 0x60));
                    *(s32 *)(arg0 + 0xC) = 7;
                } else if (!has_save(*(char **)(arg0 + 0x950))) {
                    func_088BFEF8(arg0, func_08851680(D_089CC438, 0x61));
                    *(s32 *)(arg0 + 0xC) = 7;
                } else {
                    if (*(s32 *)(*(char **)(arg0 + 0x950) + 0x20) != 0) {
                        *(s32 *)(arg0 + 8) = *(s32 *)(*(char **)(arg0 + 0x950) + 0x20) - 1;
                    } else {
                        for (*(s32 *)(arg0 + 8) = 0; *(s32 *)(arg0 + 8) < 3; (*(s32 *)(arg0 + 8))++) {
                            if (*(u8 *)(*(char **)(arg0 + 0x950) + (s8)*(s32 *)(arg0 + 8) * 0x15000 + 0x1000) == 1) {
                                break;
                            }
                        }
                    }
                    *(s32 *)(arg0 + 0xC) = 3;
                    func_08883988(D_08A62D8C, 0, 0x24, 0, 0, 0, 0, 0, 0);
                }
            } else if (err == 2 && *(s32 *)(arg0 + 0x5E4) == 1) {
                memset(*(char **)(arg0 + 0x950), 0, 0x16A100);
                func_088C14C8(arg0, 1);
            } else {
                func_088BFE54(arg0, err);
                *(s32 *)(arg0 + 0xC) = 7;
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 3:
        old = *(s32 *)(arg0 + 8);
        pad = D_08A62C6C;
        if (pad & 0x10) {
            do {
                if (--*(s32 *)(arg0 + 8) < 0) {
                    *(s32 *)(arg0 + 8) = 2;
                }
            } while (*(u8 *)(*(char **)(arg0 + 0x950) + *(s8 *)(arg0 + 8) * 0x15000 + 0x1000) != 1);
        } else if (pad & 0x40) {
            do {
                if (++*(s32 *)(arg0 + 8) > 2) {
                    *(s32 *)(arg0 + 8) = 0;
                }
            } while (*(u8 *)(*(char **)(arg0 + 0x950) + *(s8 *)(arg0 + 8) * 0x15000 + 0x1000) != 1);
        } else if (pad & 0x2000) {
            *(s32 *)(arg0 + 0xC) = 8;
            *(u8 *)(arg0 + 4) = 0;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else if (pad & 0x4000) {
            *(char **)(arg0 + 0x954) = *(char **)(arg0 + 0x950) + old * 0x15000 + 0x1000;
            *(char **)(arg0 + 0x95C) = *(char **)(arg0 + 0x950) + 0xC;
            *(u8 *)(arg0 + 4) = 1;
            *(s32 *)(arg0 + 0xC) = 4;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        }
        if (old != *(s32 *)(arg0 + 8)) {
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
        func_088C0BBC(arg0);
        func_088BA5BC(0xA8, 0xD0, 0x130, 0x30);
        func_088BA54C(0xB0, 0xD8, 0x2D);
        break;
    case 4:
        func_088C0BBC(arg0);
        func_088BA5BC(0xA8, 0xD0, 0x130, 0x30);
        func_088BA54C(0xB0, 0xD8, 0x2E);
        func_088BA2E0(0x158, 0xE8, *(u8 *)(arg0 + 4), 1);
        r = yes_no(arg0);
        if (r == 2) {
            *(s32 *)(arg0 + 0xC) = 5;
        } else if (r == 1) {
            *(s32 *)(arg0 + 0xC) = 3;
        }
        break;
    case 5:
        if (D_08A62C6C & 0x4000) {
            *(s32 *)(arg0 + 0xC) = 5;
            func_08883A80(D_08A62D8C, 1, 2, 0, 0, 0, 0, 0);
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            *(s32 *)(arg0 + 0xC) = 6;
            ret = 1;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0x2F);
        break;
    case 7:
        if (*(u8 *)(arg0 + 0x971) == 0) {
            *(s32 *)(arg0 + 0xC) = 8;
            *(u8 *)(arg0 + 4) = 0;
        }
        break;
    case 8:
        r = yes_no(arg0);
        if (r == 2) {
            *(s32 *)(arg0 + 0xC) = 6;
            ret = 4;
        } else if (r == 1) {
            *(s32 *)(arg0 + 0xC) = 6;
            ret = 2;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x2C);
        func_088BA2E0(0xB8, 0xA0, *(u8 *)(arg0 + 4), 1);
        break;
    }
    return ret;
}
