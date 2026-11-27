/* unit_08845EA8: 0x08845EA8-0x08846FAC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Needs the speed setting (saved registers of the last block). The table at
 * sp+0x4C is an initialised local array: its data (D_0893B6D0, 0x14 bytes)
 * and the switch jump table (jtbl_08931188, 0x18 bytes) belong to this unit.
 * func_0884706C is defined `(void)` but is called with arg0 in a0.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} Slot;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Box;

extern u16 D_0893B684, D_0893B686, D_0893B688, D_0893B68A;
extern u16 D_0893B690, D_0893B692, D_0893B694, D_0893B696;
extern u16 D_0893B698, D_0893B69C, D_0893B69E;
extern s16 D_0893B6A0;
extern u16 D_0893B6A2, D_0893B6A4, D_0893B6A6, D_0893B6A8, D_0893B6AA, D_0893B6AC;
extern u16 D_0893B6AE, D_0893B6B0, D_0893B6B2, D_0893B6B4, D_0893B6B6, D_0893B6BA;
extern u16 D_0893B6BC, D_0893B6BE, D_0893B6C0, D_0893B6C2;
extern u16 D_0893B6C4, D_0893B6C6, D_0893B6C8, D_0893B6CA, D_0893B6CC, D_0893B6CE;
extern Box D_089398EC;
extern u16 D_089CBFF0[2];
extern u16 D_089CBFF4[2];
extern s8 D_089CBFF8;
extern char *D_089CC438;
extern char *D_08A631A8;

extern void func_08832B98(char *, s32);
extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern s16 func_0884706C(char *);
extern u8 func_0882693C(char *, u16);
extern s32 func_088D81FC(char *, u16, s32);
extern void func_0882C3D0(char *, u16, u16, u16, u16, u8, u8, u8, s32, s32);
extern Slot *func_08856884(char *, s32);
extern void func_0882E0D0(char *, u16, u16, u16, u16, u16, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);
extern void func_0884711C(char *, u16, u16, u16, u16);
extern u16 func_088D7AD8(char *, u16, u8);
extern void func_08890DE8(char *, s8, u8);
extern s32 func_088474DC(char *, u8, s16);
extern void func_088471D8(char *, u16, u16, u16, u16, u8);

void func_08845EA8(char *arg0) {
    char *p;
    s32 cond;
    u8 flag;
    s16 y;

    p = *(char **)(arg0 + 0x530);
    cond = *(u8 *)(p + 0x5F3) != 1;
    func_08832B98(arg0, 1);
    flag = cond;
    if (!flag) {
        func_0882DCA0(arg0, D_0893B6BC, D_0893B6BE, D_0893B6C0, D_0893B6C2, 0xFF);
    } else {
        func_0882DCA0(arg0, D_0893B684, D_0893B686, D_0893B688, D_0893B68A, 0xFF);
    }
    if (*(s8 *)(arg0 + 0x598) != 0) {
        s32 n;
        u16 t[9] = {0x144, 0x14E, 0x16A, 0x186, 0x1A2, 0x1BC, 0xC, 0xC, 0};
        Box *box;
        u16 b;
        u16 c;
        u16 a;
        u16 e;
        u16 f;
        u16 d;

        n = func_0884706C(arg0);
        f = e = d = c = b = a = 0xFF;
        if (*(s8 *)(arg0 + 0x599) < 0) {
            if (func_0882693C(arg0, *(u16 *)(p + 0x648)) == 0) {
                n++;
            } else {
                e = *(u16 *)(p + 0x648);
            }
            if (n >= 2) {
                f = func_088D81FC(p, *(u16 *)(p + 0x648), 0);
            }
        } else {
            if (func_0882693C(arg0, *(u16 *)(p + 0x648)) == 0) {
                n++;
            } else {
                f = *(u16 *)(p + 0x648);
            }
            if (n >= 2) {
                e = func_088D81FC(p, *(u16 *)(p + 0x648), 1);
            }
        }
        switch (n) {
        case 0:
        case 1:
        case 2:
            break;
        case 4:
            c = func_088D81FC(p, e, 1);
        case 3:
            d = func_088D81FC(p, f, 0);
            break;
        case 5:
            d = func_088D81FC(p, f, 0);
            c = func_088D81FC(p, e, 1);
            b = func_088D81FC(p, d, 0);
            break;
        default:
            d = func_088D81FC(p, f, 0);
            c = func_088D81FC(p, e, 1);
            b = func_088D81FC(p, d, 0);
            a = func_088D81FC(p, c, 1);
            break;
        }
        box = (Box *)(s32)&D_089398EC;
        func_0882C3D0(arg0, t[0], D_0893B698, box->unk4 / 2, box->unk6, 0xFF, 0xFF, 0xFF, 0, 0x9B);
        if (a != 0xFF) {
            func_0882E0D0(arg0, func_08856884(D_089CC438, a)->unk0, t[0],
                          D_0893B698 + D_0893B6BA, t[6], 0x18, 1);
        }
        func_0882C3D0(arg0, t[5], D_0893B698, box->unk4 / 2, box->unk6, 0xFF, 0xFF, 0xFF, 1, 0x9B);
        if (b != 0xFF) {
            func_0882E0D0(arg0, func_08856884(D_089CC438, b)->unk0, t[8] + (t[5] + D_0893B6B6),
                          D_0893B698 + D_0893B6BA, t[7], 0x18, -1);
        }
        func_0882A9DC(arg0, t[1], D_0893B698, 0x9B);
        if (c != 0xFF) {
            func_0882E0D0(arg0, func_08856884(D_089CC438, c)->unk0, t[1] + D_0893B6B6,
                          D_0893B698 + D_0893B6BA, 0x18, 0x18, 0);
        }
        func_0882A9DC(arg0, t[2], D_0893B698, 0x9B);
        if (e != 0xFF) {
            func_0882E0D0(arg0, func_08856884(D_089CC438, e)->unk0, t[2] + D_0893B6B6,
                          D_0893B698 + D_0893B6BA, 0x18, 0x18, 0);
        }
        func_0882A9DC(arg0, t[3], D_0893B698, 0x9B);
        if (f != 0xFF) {
            func_0882E0D0(arg0, func_08856884(D_089CC438, f)->unk0, t[3] + D_0893B6B6,
                          D_0893B698 + D_0893B6BA, 0x18, 0x18, 0);
        }
        func_0882A9DC(arg0, t[4], D_0893B698, 0x9B);
        if (d != 0xFF) {
            func_0882E0D0(arg0, func_08856884(D_089CC438, d)->unk0, t[4] + D_0893B6B6,
                          D_0893B698 + D_0893B6BA, 0x18, 0x18, 0);
        }
    } else {
        u16 g;
        u16 h;
        u16 i;
        u16 j;
        u16 k;
        s32 n;

        g = *(u16 *)(p + 0x648);
        k = j = i = h = 0xFF;
        n = func_0884706C(arg0);
        if (func_0882693C(arg0, *(u16 *)(p + 0x648)) == 0) {
            g = 0xFF;
            n++;
        }
        switch (n) {
        case 0:
        case 1:
            break;
        case 3:
            j = func_088D81FC(p, *(u16 *)(p + 0x648), 0);
        case 2:
            k = func_088D81FC(p, *(u16 *)(p + 0x648), 1);
            break;
        case 4:
            k = func_088D81FC(p, *(u16 *)(p + 0x648), 1);
            j = func_088D81FC(p, *(u16 *)(p + 0x648), 0);
            i = func_088D81FC(p, k, 1);
            break;
        default:
            k = func_088D81FC(p, *(u16 *)(p + 0x648), 1);
            j = func_088D81FC(p, *(u16 *)(p + 0x648), 0);
            i = func_088D81FC(p, k, 1);
            h = func_088D81FC(p, j, 0);
            break;
        }
        func_0882A9DC(arg0, D_0893B690, D_0893B698, 0x9B);
        if (i != 0xFF) {
            func_0882E0D0(arg0, func_08856884(D_089CC438, i)->unk0, D_0893B690 + D_0893B6B6,
                          D_0893B698 + D_0893B6BA, 0x18, 0x18, 0);
        }
        func_0882A9DC(arg0, D_0893B696, D_0893B698, 0x9B);
        if (h != 0xFF) {
            func_0882E0D0(arg0, func_08856884(D_089CC438, h)->unk0, D_0893B696 + D_0893B6B6,
                          D_0893B698 + D_0893B6BA, 0x18, 0x18, 0);
        }
        func_0882A9DC(arg0, D_0893B692, D_0893B698, 0x9B);
        if (k != 0xFF) {
            func_0882E0D0(arg0, func_08856884(D_089CC438, k)->unk0, D_0893B692 + D_0893B6B6,
                          D_0893B698 + D_0893B6BA, 0x18, 0x18, 0);
        }
        func_0882A9DC(arg0, D_0893B694, D_0893B698, 0x9B);
        if (j != 0xFF) {
            func_0882E0D0(arg0, func_08856884(D_089CC438, j)->unk0, D_0893B694 + D_0893B6B6,
                          D_0893B698 + D_0893B6BA, 0x18, 0x18, 0);
        }
        func_08832B98(arg0, 0);
        func_0882A9DC(arg0, D_0893B6A2, D_0893B6A4, 0x24);
        func_08832B98(arg0, 1);
        if (g != 0xFF) {
            func_0882E0D0(arg0, func_08856884(D_089CC438, g)->unk0, D_0893B6AE, D_0893B6B0,
                          D_0893B6B2, D_0893B6B4, 0);
        }
    }
    func_0882A9DC(arg0, 0x192, 0xE0, 0x1A1);
    func_0882C7B4(arg0, 0x166, 0xE0, 0x18, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0x1A1, 1);
    y = D_0893B6A0;
    if (*(u8 *)(p + 0x674) & 4) {
        y += 2;
    }
    func_0882A9DC(arg0, D_0893B69C, y, 0x35);
    y = D_0893B6A0;
    if (*(u8 *)(p + 0x674) & 2) {
        y += 2;
    }
    func_0882A9DC(arg0, D_0893B69E, y, 0x32);
    func_0884711C(arg0, D_0893B6A6, D_0893B6A8, D_0893B6AA, D_0893B6AC);
    if (flag) {
        return;
    }
    {
        Slot *s;
        u8 r0;
        u8 r1;
        u8 r2;
        u8 r3;
        u8 m;
        u16 id;

        s = func_08856884(D_089CC438, 0);
        if (*(s8 *)(arg0 + 0x59A) != 0) {
            if (D_089CBFF8 == 0) {
                s32 half;
                D_089CBFF0[0] = D_0893B6C6;
                half = (u32)D_0893B6CA >> 1;
                D_089CBFF0[1] = D_0893B6CC - half;
                D_089CBFF4[0] = D_0893B6CE - half;
                D_089CBFF4[1] = D_0893B6CE + half;
                D_089CBFF8 = 1;
            }
            if (*(s8 *)(arg0 + 0x59B) < 0) {
                r0 = func_088D7AD8(p, *(u8 *)(p + 0x686), 1);
                r3 = r2 = r1 = 0xFF;
                if (r0 != 0xFF) {
                    if (s[r0].unk0 == s[*(u8 *)(p + 0x686)].unk0) {
                        r0 = 0xFF;
                        goto L1C;
                    }
                    func_08890DE8(D_08A631A8, 0xE, 0xE);
                    if (!(u8)func_088474DC(arg0, r0, D_089CBFF4[0] + 2)) {
                        r0 = 0xFF;
                        goto L1C;
                    }
                    m = func_088D7AD8(p, r0, 1);
                    id = s[m].unk0;
                    if (id == s[r0].unk0) goto L1C;
                    if (id == s[*(u8 *)(p + 0x686)].unk0) goto L1C;
                    func_08890DE8(D_08A631A8, 0xE, 7);
                    if ((u8)func_088474DC(arg0, m, D_089CBFF4[1] + 2) != 1) goto L1C;
                    r3 = m;
                    m = func_088D7AD8(p, *(u8 *)(p + 0x686), 0);
                    if (s[m].unk0 == s[r3].unk0) goto L1C;
                    if ((u8)func_088474DC(arg0, m, D_089CBFF0[0] + 2) == 1) {
                        r1 = m;
                    }
                L1C:
                    func_08890DE8(D_08A631A8, 0xE, 0xE);
                    if ((u8)func_088474DC(arg0, *(u8 *)(p + 0x686), D_089CBFF0[1] + 2) == 1) {
                        r2 = *(u8 *)(p + 0x686);
                    }
                }
            } else {
                r3 = func_088D7AD8(p, *(u8 *)(p + 0x686), 1);
                r0 = r2 = r1 = 0xFF;
                if (r3 != 0xFF) {
                    if (s[r3].unk0 == s[*(u8 *)(p + 0x686)].unk0) {
                        r3 = 0xFF;
                        goto LD0;
                    }
                    func_08890DE8(D_08A631A8, 0xE, 7);
                    if (!(u8)func_088474DC(arg0, r3, D_089CBFF4[1] + 2)) {
                        r3 = 0xFF;
                        goto LD0;
                    }
                    m = func_088D7AD8(p, *(u8 *)(p + 0x686), 0);
                    if (s[m].unk0 == s[r3].unk0) goto LD0;
                    func_08890DE8(D_08A631A8, 0xE, 0xE);
                    if ((u8)func_088474DC(arg0, m, D_089CBFF0[1] + 2) != 1) goto LD0;
                    r2 = m;
                    m = func_088D7AD8(p, r2, 0);
                    if (s[m].unk0 == s[r3].unk0) goto LD0;
                    func_08890DE8(D_08A631A8, 0xE, 7);
                    if ((u8)func_088474DC(arg0, m, D_089CBFF0[0] + 2) == 1) {
                        r1 = m;
                    }
                LD0:
                    func_08890DE8(D_08A631A8, 0xE, 0xE);
                    if ((u8)func_088474DC(arg0, *(u8 *)(p + 0x686), D_089CBFF4[0] + 2) == 1) {
                        r0 = *(u8 *)(p + 0x686);
                    }
                }
            }
            func_088471D8(arg0, D_0893B6C4, D_089CBFF0[0], D_0893B6C8, D_0893B6CA >> 1, r1);
            func_088471D8(arg0, D_0893B6C4, D_089CBFF0[1], D_0893B6C8, D_0893B6CA, r2);
            func_088471D8(arg0, D_0893B6C4, D_089CBFF4[0], D_0893B6C8, D_0893B6CA, r0);
            func_088471D8(arg0, D_0893B6C4, D_089CBFF4[1], D_0893B6C8, D_0893B6CA >> 1, r3);
        } else {
            r0 = func_088D7AD8(p, *(u8 *)(p + 0x686), 1);
            r2 = r1 = 0xFF;
            if (r0 != 0xFF) {
                func_08890DE8(D_08A631A8, 0xE, 0xE);
                m = func_088D7AD8(p, *(u8 *)(p + 0x686), 0);
                if (s[m].unk0 != s[r0].unk0) {
                    if ((u8)func_088474DC(arg0, m, D_0893B6C6 + 2) == 1) {
                        r1 = m;
                    }
                }
                if (s[r0].unk0 == s[*(u8 *)(p + 0x686)].unk0) {
                    r0 = 0xFF;
                } else if (!(u8)func_088474DC(arg0, r0, D_0893B6CE + 2)) {
                    r0 = 0xFF;
                }
                if ((u8)func_088474DC(arg0, *(u8 *)(p + 0x686), D_0893B6CC + 2) == 1) {
                    r2 = *(u8 *)(p + 0x686);
                }
            }
            func_088471D8(arg0, D_0893B6C4, D_0893B6C6, D_0893B6C8, D_0893B6CA, r1);
            func_088471D8(arg0, D_0893B6C4, D_0893B6CC, D_0893B6C8, D_0893B6CA, r2);
            func_088471D8(arg0, D_0893B6C4, D_0893B6CE, D_0893B6C8, D_0893B6CA, r0);
        }
        *(s32 *)(arg0 + 0x528) |= 2;
    }
}
