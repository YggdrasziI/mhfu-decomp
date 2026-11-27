/* unit_088BD75C: 0x088BD75C-0x088BE550 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088BD75C asm piece, 1 function.
 *
 * C++: virtual calls through D_089CC434.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct V38_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(u16); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(u16, s32, s32, s32, s32, s32); virtual s32 vfunc_38(); } V38_0;

extern "C" {

extern s32 D_08A62C6C;
extern s32 D_08A62D8C;
extern V38_0 *D_089CC434;
extern char *D_089CC438;
extern char *D_089CC01C;
extern char *D_09A1FDDC;

extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void memset(void *, s32, s32);
extern void memcpy(void *, void *, s32);
extern void func_088BF858(char *, s32);
extern void func_088BA5BC(s16, s16, s16, s16);
extern void func_088BA494(s32, s32, s32);
extern void func_088BA2E0(s32, s32, u8, s32);
extern void func_088C30B8(char *, s32, s32);
extern void func_088C3054(char *);
extern void func_088BFE54(char *, s32);
extern void func_088BFEF8(char *, char *);
extern char *func_08851680(char *, u16);
extern void func_0884D790(char *, s16, s32);

}

static inline s32 yesno(char *p) {
    s32 pad = D_08A62C6C;

    if (pad & 0x80) {
        if (*(u8 *)(p + 4) == 0) {
            *(u8 *)(p + 4) = 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if (pad & 0x20) {
        if (*(u8 *)(p + 4) != 0) {
            *(u8 *)(p + 4) = 0;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else {
        if ((pad & 0x4000) && *(u8 *)(p + 4) != 0) {
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            return 2;
        }
        if ((pad & 0x2000) || ((pad & 0x4000) && *(u8 *)(p + 4) == 0)) {
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            return 1;
        }
    }
    return 0;
}

extern "C" {

s32 func_088BD75C(char *arg0) {
    s32 ret = 0;
    s32 r;
    s32 e;

    switch (*(s32 *)(arg0 + 0xC)) {
    case 0:
        *(u8 *)(arg0 + 4) = 1;
        *(s32 *)(arg0 + 0xC) = 1;
    case 1:
        r = yesno(arg0);
        if (r == 2) {
            *(s32 *)(arg0 + 0xC) = 4;
            D_089CC434->vfunc_34(0xC, *(s32 *)(arg0 + 0x10), -1, 0, 0, 1);
            D_089CC434->vfunc_34(0xD, *(s32 *)(arg0 + 0x14), -1, 0, 0, 1);
            memset(*(char **)(arg0 + 0x94C), 0, 0x16A100);
            func_088BF858(arg0, 0);
        } else if (r == 1) {
            ret = 2;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        if (!(*(s32 *)(arg0 + 0x990) & 4)) {
            func_088BA494(0xF0, 0x70, 0x17);
        } else {
            func_088BA494(0xF0, 0x70, 0x24);
        }
        func_088BA2E0(0xB8, 0xA0, *(u8 *)(arg0 + 4), 1);
        break;
    case 4:
        if (D_089CC434->vfunc_38() == 0) {
            *(s32 *)(arg0 + 0xC) = 2;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 2:
        if (*(u8 *)(arg0 + 0x970) == 0) {
            e = *(s32 *)(arg0 + 0x34);
            if (e == 0 || (e == 2 && *(s32 *)(arg0 + 0x5E4) == 0)) {
                func_088C30B8(arg0, 1, 0);
                *(s32 *)(arg0 + 0xC) = 3;
            } else if (e == (s32)0x80110307) {
                memcpy(*(char **)(arg0 + 0x94C), D_089CC438 + 0x6ADD8, 0xE);
                memcpy(*(char **)(arg0 + 0x94C) + 0x10, D_089CC438 + 0x6ADE8, 0x14);
                func_088C3054(arg0);
                *(s32 *)(arg0 + 0xC) = 7;
            } else if (e == 2 && *(s32 *)(arg0 + 0x5E4) == 1) {
                memset(*(char **)(arg0 + 0x94C), 0, 0x16A100);
                func_088BF858(arg0, 0);
            } else {
                func_088BFE54(arg0, e);
                *(s32 *)(arg0 + 0xC) = 9;
                *(u8 *)(arg0 + 0x995) = 0;
                if (*(s32 *)(arg0 + 0x34) == (s32)0x80110306 || *(s32 *)(arg0 + 0x34) == (s32)0x80110309) {
                    *(u8 *)(arg0 + 0x995) = 1;
                }
                *(s32 *)(arg0 + 0x9A8) = *(s32 *)(arg0 + 0x34);
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 3:
        if (*(u8 *)(arg0 + 0x4A88) == 0) {
            if (*(u8 *)(arg0 + 0x4A89) == 0) {
                func_088BFEF8(arg0, func_08851680(D_089CC438, 2));
                *(s32 *)(arg0 + 0xC) = 9;
                *(u8 *)(arg0 + 0x995) = 1;
                *(s32 *)(arg0 + 0x9A8) = *(s32 *)(arg0 + 0x34);
                break;
            }
            *(s32 *)(arg0 + 0xC) = 5;
            *(u8 *)(arg0 + 0x9AC) = 1;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 5:
        r = yesno(arg0);
        if (*(u8 *)(arg0 + 0x978) == 0) {
            *(s32 *)(arg0 + 0xC) = 8;
            *(s32 *)(arg0 + 0) = 0x1E;
        } else if (*(u8 *)(D_09A1FDDC + 0xD) != 0) {
            *(u8 *)(arg0 + 0x9AC) = 0;
            *(s32 *)(arg0 + 0xC) = 0;
        } else if (r == 2) {
            memcpy(*(char **)(arg0 + 0x94C), D_089CC438 + 0x6ADD8, 0xE);
            *(s32 *)(D_089CC438 + 0x6ADE8) |= *(s32 *)(*(char **)(arg0 + 0x94C) + 0x10);
            *(s32 *)(D_089CC438 + 0x6ADEC) |= *(s32 *)(*(char **)(arg0 + 0x94C) + 0x14);
            *(s32 *)(D_089CC438 + 0x6ADF0) |= *(s32 *)(*(char **)(arg0 + 0x94C) + 0x18);
            *(s32 *)(D_089CC438 + 0x6ADF4) |= *(s32 *)(*(char **)(arg0 + 0x94C) + 0x1C);
            *(s32 *)(D_089CC438 + 0x6ADF8) |= *(s32 *)(*(char **)(arg0 + 0x94C) + 0x20);
            memcpy(*(char **)(arg0 + 0x94C) + 0x10, D_089CC438 + 0x6ADE8, 0x14);
            func_088C3054(arg0);
            *(s32 *)(arg0 + 0xC) = 7;
            *(u8 *)(arg0 + 0x9AC) = 0;
        } else if (r == 1) {
            *(s32 *)(arg0 + 0xC) = 0;
            *(u8 *)(arg0 + 0x9AC) = 0;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0x18);
        func_088BA2E0(0xB8, 0xA0, *(u8 *)(arg0 + 4), 1);
        break;
    case 8:
        (*(s32 *)(arg0 + 0))--;
        if (*(u8 *)(arg0 + 0x978) != 0) {
            *(s32 *)(arg0 + 0xC) = 5;
        } else if (*(s32 *)(arg0 + 0) == 0) {
            *(u8 *)(arg0 + 0x9AC) = 0;
            func_088BFEF8(arg0, func_08851680(D_089CC438, 0x3D));
            *(u8 *)(arg0 + 0x995) = 0;
            *(s32 *)(arg0 + 0xC) = 9;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0x18);
        func_088BA2E0(0xB8, 0xA0, *(u8 *)(arg0 + 4), 1);
        break;
    case 7:
        if (*(u8 *)(arg0 + 0x4A88) == 0) {
            func_088BF858(arg0, 1);
            *(s32 *)(arg0 + 0xC) = 6;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x14);
        break;
    case 6:
        if (*(u8 *)(arg0 + 0x970) == 0) {
            e = *(s32 *)(arg0 + 0x34);
            if (e == 0 || (e == 2 && *(s32 *)(arg0 + 0x5E4) == 0)) {
                ret = 1;
                func_08883988(D_08A62D8C, 0, 0x24, 0, 0, 0, 0, 0, 0);
            } else if (e == 2 && *(s32 *)(arg0 + 0x5E4) == 1) {
                func_088BF858(arg0, 1);
            } else {
                func_088BFE54(arg0, e);
                *(s32 *)(arg0 + 0xC) = 9;
                *(s32 *)(arg0 + 0x9A8) = *(s32 *)(arg0 + 0x34);
                *(u8 *)(arg0 + 0x995) = 0;
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x14);
        break;
    case 9:
        if (*(u8 *)(arg0 + 0x971) == 0) {
            if (*(u8 *)(arg0 + 0x995) != 0) {
                *(s32 *)(arg0 + 0xC) = 0xD;
                *(u8 *)(arg0 + 4) = 1;
            } else if (*(s32 *)(arg0 + 0x9A8) == (s32)0x80110383) {
                *(s32 *)(arg0 + 0xC) = 0xA;
                *(u8 *)(arg0 + 4) = 1;
            } else {
                *(s32 *)(arg0 + 0xC) = 0;
            }
        }
        break;
    case 10:
        r = yesno(arg0);
        if (r == 2) {
            *(s32 *)(arg0 + 0xC) = 0xB;
            func_088BF858(arg0, 7);
            func_0884D790(D_089CC01C, 4, 1);
            *(u8 *)(D_089CC01C + 0x29) = 0xC0;
        } else if (r == 1) {
            *(s32 *)(arg0 + 0xC) = 0;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 5);
        func_088BA2E0(0xB8, 0xA0, *(u8 *)(arg0 + 4), 1);
        break;
    case 11:
        if (*(u8 *)(arg0 + 0x970) == 0) {
            *(s32 *)(arg0 + 0xC) = 0;
            func_0884D790(D_089CC01C, 4, 0);
        }
        break;
    case 13:
        r = yesno(arg0);
        if (r == 2) {
            *(s32 *)(arg0 + 0xC) = 0xB;
            func_088BF858(arg0, 7);
            func_0884D790(D_089CC01C, 4, 1);
            *(u8 *)(D_089CC01C + 0x29) = 0xC0;
        } else if (r == 1) {
            *(s32 *)(arg0 + 0xC) = 0;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x23);
        func_088BA2E0(0xB8, 0xA0, *(u8 *)(arg0 + 4), 1);
        break;
    }
    return ret;
}

}
