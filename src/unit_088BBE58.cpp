/* unit_088BBE58: 0x088BBE58-0x088BC7F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088BBE58: state machine over the word at +0xC (jump table). C++ for the
 * virtual call through D_089CC434. The input handling of state 1 is a static
 * inline helper (its zero results share one assignment). */

#pragma exceptions off
typedef int s32;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

typedef struct V38 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual s32 vfunc_38(); } V38;
typedef struct Pair { u16 unk0; u16 unk2; } Pair;

extern "C" {

extern V38 *D_089CC434;
extern char *D_089CC438;
extern s32 D_08A62D8C;
extern s32 D_08A62C6C;
extern char *D_09A4F060;
extern char D_09CE4848[];

extern int memset(void *, s32, s32);
extern int memcpy(void *, void *, s32);
extern void func_088C1430(char *);
extern void func_08882B58(s32, s32, s32);
extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088BA5BC(s16, s16, s16, s16);
extern void func_088BA494(s32, s32, s32);
extern void func_088BA2E0(s32, s32, u8, s32);
extern s32 func_08882C90(s32, s32);
extern void func_088C30B8(char *, s32, s32);
extern void func_088BF858(void *, s32);
extern char *func_08851680(char *, u16);
extern void func_088BFEF8(char *, char *);
extern void func_088BFE54(char *, s32);
extern void func_08885494(s32, s32, s32, s32, s32);
extern int func_08882C24(s32, s32, s32, s32);
extern s32 func_088C0554(char *);
extern void func_088C0594(char *, char *);
extern void func_088C3054(char *);
extern s32 func_088855C4(s32, s32, s32, s32);

static inline s32 read_choice(char *arg0) {
    s32 k;

    k = D_08A62C6C;
    if (k & 0x80) {
        if (*(u8 *)(arg0 + 4) == 0) {
            *(u8 *)(arg0 + 4) = 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if (k & 0x20) {
        if (*(u8 *)(arg0 + 4) != 0) {
            *(u8 *)(arg0 + 4) = 0;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if ((k & 0x4000) && *(u8 *)(arg0 + 4) != 0) {
        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        return 2;
    } else if ((k & 0x2000) || ((k & 0x4000) && *(u8 *)(arg0 + 4) == 0)) {
        func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}

s32 func_088BBE58(char *arg0) {
    s32 r;
    s32 k;
    s32 a;
    s32 st;

    r = 0;
    switch (*(s32 *)(arg0 + 0xC)) {
    case 0:
        *(u8 *)(arg0 + 4) = 1;
        *(s32 *)(arg0 + 8) = 0;
        if (*(u8 *)(arg0 + 0x9A3) == 0) {
            *(s32 *)(arg0 + 0xC) = 1;
        } else {
            func_088C1430(arg0);
            if (*(s32 *)(arg0 + 0x990) & 8) {
                func_08882B58(D_08A62D8C, 0, 0x10);
                *(s32 *)(arg0 + 0xC) = 7;
            } else {
                *(s32 *)(arg0 + 0xC) = 3;
            }
            *(u8 *)(arg0 + 0x9A3) = 0;
            break;
        }
    case 1:
        a = read_choice(arg0);
        if (a == 2) {
            func_088C1430(arg0);
            if (*(s32 *)(arg0 + 0x990) & 8) {
                func_08882B58(D_08A62D8C, 0, 0x10);
                *(s32 *)(arg0 + 0xC) = 7;
            } else {
                *(s32 *)(arg0 + 0xC) = 3;
            }
        } else if (a == 1) {
            r = 2;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 4);
        func_088BA2E0(0xB8, 0xA0, *(u8 *)(arg0 + 4), 1);
        break;
    case 7:
        if (func_08882C90(D_08A62D8C, 0) == 0) {
            *(s32 *)(arg0 + 0xC) = 3;
            func_08883988(D_08A62D8C, 7, 0x71, 0, 0, 0, 0, 0, 0);
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 3:
        if (D_089CC434->vfunc_38() == 0) {
            *(s32 *)(arg0 + 0xC) = 2;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 2:
        if (*(u8 *)(arg0 + 0x970) == 0) {
            st = *(s32 *)(arg0 + 0x34);
            if (st == 0 || (st == 2 && *(s32 *)(arg0 + 0x5E4) == 0)) {
                func_088C30B8(arg0, 1, 0);
                *(s32 *)(arg0 + 0xC) = 9;
            } else if (st == 2 && *(s32 *)(arg0 + 0x5E4) == 1) {
                memset(*(char **)(arg0 + 0x94C), 0, 0x16A100);
                func_088BF858(arg0, 0);
            } else {
                if (st == (s32)0x80110307) {
                    func_088BFEF8(arg0, func_08851680(D_089CC438, 0x1B));
                } else {
                    func_088BFE54(arg0, st);
                }
                *(s32 *)(arg0 + 0xC) = 4;
                if (*(s32 *)(arg0 + 0x990) & 8) {
                    func_08885494(D_08A62D8C, 7, 0, 0, 0);
                    func_08882C24(D_08A62D8C, 0, 0x10, ((Pair *)D_09CE4848)[*(u16 *)(D_09A4F060 + 0x288)].unk2);
                }
                func_08882C24(D_08A62D8C, 0, 0x10, ((Pair *)D_09CE4848)[*(u16 *)(D_09A4F060 + 0x288)].unk2);
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 9:
        if (*(u8 *)(arg0 + 0x4A88) == 0) {
            if (*(u8 *)(arg0 + 0x4A89) == 0) {
                func_088BFEF8(arg0, func_08851680(D_089CC438, 2));
                *(s32 *)(arg0 + 0xC) = 4;
            } else if (func_088C0554(arg0) == 0) {
                func_088BFEF8(arg0, func_08851680(D_089CC438, 0x1B));
                *(s32 *)(arg0 + 0xC) = 4;
            } else {
                func_088C0594(arg0, *(char **)(arg0 + 0x94C) + 0x16A0E0);
                memcpy(arg0 + 0x988, *(char **)(arg0 + 0x94C) + 0x16A0E0, 8);
                memcpy(*(char **)(arg0 + 0x94C), D_089CC438 + 0x6ADD8, 0xE);
                memcpy(*(char **)(arg0 + 0x94C) + 0x10, D_089CC438 + 0x6ADE8, 0x14);
                memcpy(*(char **)(arg0 + 0x94C) + *(s32 *)(arg0 + 0x97C) * 0x6B100 + 0x1000, D_089CC438 + 0x4A0, 0x6A938);
                (*(char **)(arg0 + 0x94C))[*(s32 *)(arg0 + 0x97C) * 0x6B100 + 0x1012] = 1;
                *(s32 *)(*(char **)(arg0 + 0x94C) + 0x24) = *(s32 *)(arg0 + 0x97C) + 1;
                *(u8 *)(arg0 + 0x9A2) = 1;
                func_088C3054(arg0);
                *(s32 *)(arg0 + 0xC) = 8;
            }
            if (*(s32 *)(arg0 + 0xC) == 4 && (*(s32 *)(arg0 + 0x990) & 8)) {
                func_08885494(D_08A62D8C, 7, 0, 0, 0);
                func_08882C24(D_08A62D8C, 0, 0x10, ((Pair *)D_09CE4848)[*(u16 *)(D_09A4F060 + 0x288)].unk2);
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 8:
        if (*(u8 *)(arg0 + 0x4A88) == 0) {
            func_088BF858(arg0, 1);
            *(s32 *)(arg0 + 0xC) = 5;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 5:
        if (*(u8 *)(arg0 + 0x970) == 0) {
            st = *(s32 *)(arg0 + 0x34);
            if (st == 0 || (st == 2 && *(s32 *)(arg0 + 0x5E4) == 0)) {
                k = *(s32 *)(arg0 + 0x990) & 8;
                if (k == 0 || (k != 0 && func_088855C4(D_08A62D8C, 7, 0, 0) == 0)) {
                    memcpy(arg0 + 0x980, arg0 + 0x988, 8);
                    r = 1;
                    func_08883988(D_08A62D8C, 0, 0x24, 0, 0, 0, 0, 0, 0);
                    func_08882C24(D_08A62D8C, 0, 0x10, ((Pair *)D_09CE4848)[*(u16 *)(D_09A4F060 + 0x288)].unk2);
                    *(s32 *)(arg0 + 0xC) = 0xA;
                }
            } else if (st == 2 && *(s32 *)(arg0 + 0x5E4) == 1) {
                func_088BF858(arg0, 1);
            } else {
                func_088BFE54(arg0, st);
                *(s32 *)(arg0 + 0xC) = 4;
                if (*(s32 *)(arg0 + 0x990) & 8) {
                    func_08885494(D_08A62D8C, 7, 0, 0, 0);
                    func_08882C24(D_08A62D8C, 0, 0x10, ((Pair *)D_09CE4848)[*(u16 *)(D_09A4F060 + 0x288)].unk2);
                }
                func_08882C24(D_08A62D8C, 0, 0x10, ((Pair *)D_09CE4848)[*(u16 *)(D_09A4F060 + 0x288)].unk2);
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x14);
        break;
    case 10:
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x14);
        break;
    case 4:
        if (*(u8 *)(arg0 + 0x971) == 0) {
            *(s32 *)(arg0 + 0xC) = 0;
        }
        break;
    case 6:
        break;
    }
    return r;
}

}
