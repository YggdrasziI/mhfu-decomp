/* unit_088BE550: 0x088BE550-0x088BEEC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088BE550 (ULES01213), piece text_088BE550, size 0x970.
 *
 * Optimized for speed: the slot loop of state 9 is strength reduced (offset
 * stepped by 0x15000) and tested at the bottom without a guard.
 * The input handling of state 3 is a static inline helper: its "return 0"
 * paths share one block. func_088BFE54 takes the status word as its second
 * argument (left in a1). The jump table jtbl_089322B8 (0x089322B8, 0x30
 * bytes, 12 entries) is emitted by the switch.
 */
#pragma optimize_for_size off
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    char pad[0x1000];
    u8 f;
    char pad2[0x15000 - 0x1001];
} Slot;

extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_08A62C6C;
extern s32 D_08A62D8C;
extern char *D_09A1FDDC;

extern void memset(void *, s32, s32);
extern void memcpy(void *, void *, s32);
extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern int func_08832548(char *, s32);
extern void func_088BF858(void *, s32);
extern void func_088C30B8(char *, u8, s32);
extern void func_088BFE54(char *, s32);
extern void func_088BA5BC(s16, s16, s16, s16);
extern void func_088BA494(s32, s32, u16);
extern void func_088BA664(s32, s32);
extern void func_088BA2E0(s32, s32, u8, s32);
extern char *func_08851680(char *, u16);
extern void func_088BFEF8(char *, char *);
extern void func_08880760(s32, s32);
extern void func_08880864(s32, s32);
extern void func_08880874(s32, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088C14C8(char *, s32);
extern int func_088C0420(char *);
extern void func_088BFA68(char *);

static inline s32 read_choice(char *arg0) {
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

s32 func_088BE550(char *arg0) {
    char *g;
    s32 ret;
    s32 r;
    s32 st;
    char *p;
    s8 i;
    u8 found;
    Slot *sl;

    ret = 0;
    g = D_089CBBEC;
    *(u8 *)(g + 0x534) = 9;
    func_08890E08(D_08A631A8, 0);
    func_08825DA8(g);
    func_08832548(D_089CBBEC, 9);
    switch (*(u32 *)(arg0 + 0xC)) {
    case 0:
        *(u8 *)(arg0 + 0x9A2) = 0;
        *(u8 *)(arg0 + 4) = 1;
        *(s32 *)(arg0 + 0xC) = 1;
        memset(*(char **)(arg0 + 0x94C), 0, 0x16A100);
        func_088BF858(arg0, 0);
    case 1:
        if (*(u8 *)(arg0 + 0x970) == 0) {
            st = *(s32 *)(arg0 + 0x34);
            if (st == 0 || (st == 2 && *(s32 *)(arg0 + 0x5E4) == 0)) {
                func_088C30B8(arg0, 0, 0);
                *(s32 *)(arg0 + 0xC) = 2;
            } else if (st == 2 && *(s32 *)(arg0 + 0x5E4) == 1) {
                memset(*(char **)(arg0 + 0x94C), 0, 0x16A100);
                func_088BF858(arg0, 0);
                *(u8 *)(D_089CC438 + 0x6ADD8) = *(s32 *)(D_08A631A0 + 0xF7A574);
            } else {
                if (st == 0x80110309 || st == 0x80110307) {
                    *(s32 *)(arg0 + 0xC) = 8;
                } else {
                    func_088BFE54(arg0, st);
                    *(s32 *)(arg0 + 0xC) = 4;
                }
                *(u8 *)(D_089CC438 + 0x6ADD8) = *(s32 *)(D_08A631A0 + 0xF7A574);
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 2:
        if (*(u8 *)(arg0 + 0x4A88) == 0) {
            if (*(u8 *)(arg0 + 0x4A89) == 0) {
                func_088BFEF8(arg0, func_08851680(D_089CC438, 2));
                *(s32 *)(arg0 + 0xC) = 4;
            } else {
                memcpy(D_089CC438 + 0x6ADD8, *(char **)(arg0 + 0x94C), 0xE);
                memcpy(D_089CC438 + 0x6ADE8, *(char **)(arg0 + 0x94C) + 0x10, 0x14);
                func_08880760(D_08A62D8C, *(s8 *)(D_089CC438 + 0x6ADD9));
                func_08880864(D_08A62D8C, *(s8 *)(D_089CC438 + 0x6ADDB));
                func_08880874(D_08A62D8C, *(s8 *)(D_089CC438 + 0x6ADDA));
                p = *(char **)(arg0 + 0x94C);
                if (*(u8 *)(p + 0x1012) != 0 || *(u8 *)(p + 0x6C112) != 0 || *(u8 *)(p + 0xD7212) != 0) {
                    *(u8 *)(arg0 + 0x9A2) = 1;
                }
                *(s32 *)arg0 = 0x5A;
                *(s32 *)(arg0 + 0xC) = 5;
                func_08883988(D_08A62D8C, 0, 0x24, 0, 0, 0, 0, 0, 0);
            }
            *(u8 *)(D_089CC438 + 0x6ADD8) = *(s32 *)(D_08A631A0 + 0xF7A574);
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 5:
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x80, 0x15);
        func_088BA664(0x9C, 0xA0);
        if (--*(s32 *)arg0 <= 0 || (D_08A62C6C & 0x4000)) {
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            ret = 1;
        }
        break;
    case 4:
        if (*(u8 *)(arg0 + 0x971) == 0) {
            *(s32 *)(arg0 + 0xC) = 3;
        }
        break;
    case 6:
        if (*(u8 *)(arg0 + 0x970) == 0) {
            if (*(s32 *)(arg0 + 0x34) == 0x801103C7 && *(u32 *)(*(char **)(arg0 + 0x5E8) + 8) < 0x720) {
                *(s32 *)(arg0 + 0xC) = 7;
            } else {
                ret = 2;
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 7:
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 3);
        func_088BA664(0x9C, 0xA0);
        if (D_08A62C6C & 0x4000) {
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            *(s32 *)(arg0 + 0xC) = 3;
        }
        break;
    case 3:
        r = read_choice(arg0);
        if (r == 2) {
            ret = 2;
        } else if (r == 1) {
            *(s32 *)(arg0 + 0xC) = 0;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0x16);
        func_088BA2E0(0xB8, 0xA0, *(u8 *)(arg0 + 4), 1);
        break;
    case 8:
        *(s32 *)(arg0 + 0x97C) = -1;
        memset(arg0 + 0x980, 0, 8);
        *(s32 *)(arg0 + 0xC) = 9;
        memset(*(char **)(arg0 + 0x950), 0, 0x16A100);
        func_088C14C8(arg0, 1);
    case 9:
        if (*(u8 *)(arg0 + 0x970) == 0) {
            st = *(s32 *)(arg0 + 0x34);
            if (st == 0 || (st == 2 && *(s32 *)(arg0 + 0x5E4) == 0)) {
                if (func_088C0420(arg0) != 0) {
                    sl = *(Slot **)(arg0 + 0x950);
                    for (i = 0; i < 3; i++) {
                        if (sl[i].f == 1) {
                            found = 1;
                            goto done;
                        }
                    }
                    found = 0;
                done:
                    if (found) {
                        *(s32 *)(arg0 + 0xC) = 0xA;
                        *(u8 *)(arg0 + 0x9AC) = 1;
                        func_08883988(D_08A62D8C, 0, 0x24, 0, 0, 0, 0, 0, 0);
                        goto draw9;
                    }
                }
            }
            if (*(s32 *)(arg0 + 0x34) == 2 && *(s32 *)(arg0 + 0x5E4) == 1) {
                *(s32 *)(arg0 + 0xC) = 8;
            } else {
                func_088BFA68(arg0);
                *(s32 *)(arg0 + 0xC) = 6;
            }
        }
    draw9:
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 10:
        if (*(u8 *)(arg0 + 0x9AC) != 0 && *(u8 *)(arg0 + 0x978) == 0) {
            func_088BFEF8(arg0, func_08851680(D_089CC438, 0x3D));
            *(u8 *)(arg0 + 0x9AC) = 0;
            *(s32 *)(arg0 + 0xC) = 0xB;
        } else if (*(u8 *)(arg0 + 0x9AC) != 0 && *(u8 *)(D_09A1FDDC + 0xD) != 0) {
            *(u8 *)(arg0 + 0x9AC) = 0;
            *(s32 *)(arg0 + 0xC) = 0;
        } else if (D_08A62C6C & 0x4000) {
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            *(u8 *)(arg0 + 0x9AC) = 0;
            func_088BFA68(arg0);
            *(s32 *)(arg0 + 0xC) = 6;
        }
        func_088BA5BC(0x10, 0x1D, 0x1C0, 0xD6);
        func_088BA494(0xF0, 0x46, 0x3C);
        break;
    case 11:
        if (*(u8 *)(arg0 + 0x971) == 0) {
            *(s32 *)(arg0 + 0xC) = 3;
        }
        break;
    }
    return ret;
}
