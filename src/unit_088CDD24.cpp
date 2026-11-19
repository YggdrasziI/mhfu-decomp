/* unit_088CDD24: 0x088CDD24-0x088CE05C (ULES01213)
 *
 * Bounds (hypothesis): 5 functions between unit_088CDCF4 and unit_088CE05C.
 * Helpers of the entry queue of unit_088CC828: timed actions of a record
 * (12-byte items at +0x28, ended by -1).
 *
 * C++: virtual calls.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Act {
    s32 time;
    s32 kind;
    u32 arg;
} Act;

typedef struct Rec {
    u16 unk0;
    u16 unk2;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u16 unk8;
    u8 unkA;
    char pad[0x1D];
    Act *unk28;
} Rec;

typedef struct V18 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(u16); } V18;

extern "C" {

extern char *D_089CC438;
extern char *D_089CC01C;
extern V18 *D_089CC434;
extern char *D_089CBBE4;
extern char *D_08A62D8C;
extern char *D_08A62D90;
extern s32 D_08A62D94;
extern s32 D_09A4F0D0;

extern s32 func_08813E70(char *);
extern void func_0884D790(char *, s32, s32);
extern void func_088817E8(char *, s32, s32);
extern void func_0888291C(char *, s32);
extern void func_08886638(s32, s32, u16, s32);
extern void func_0888664C(s32, s32);
extern s32 func_08886664(s32, s32);
extern s32 func_088CD2D4(char *, char *);
extern void func_088DDD9C(s32, s32, s32, s32);
extern void func_088DDF50(s32, s32);

void func_088CDFF8(char *arg0, Act *arg1);

s32 func_088CDD24(char *arg0) {
    char *e;
    s32 i;

    e = arg0 + 4;
    i = 0;
    do {
        if (*(u8 *)e != 0) {
            if (((*(Rec **)(e + 0x1C))->unkA & 1) && func_088CD2D4(arg0, e) > 0) {
                return 1;
            }
        }
        i++;
        e += 0x20;
    } while (i < 4);
    return 0;
}

void func_088CDDAC(char *arg0) {
    s32 id;
    s32 i;

    id = *(u16 *)(D_08A62D90 + 0x28);
    func_088817E8(D_08A62D8C, 0x12, D_089CC434->vfunc_18(id));
    func_088817E8(D_08A62D8C, 0x13, 0);
    func_088817E8(D_08A62D8C, 0x14, 0);
    i = 0;
    do {
        func_0888664C(D_08A62D94, i + 0x12);
        i++;
    } while (i < 3);
    func_0888291C(D_08A62D8C, 2);
    func_08886638(D_08A62D94, 0x12, id, D_089CC434->vfunc_18(id));
    func_088DDD9C(D_09A4F0D0, func_08886664(D_08A62D94, 0x12), 0x2A, -1);
    func_088DDF50(D_09A4F0D0, 0x2A);
    *(u8 *)(arg0 + 0x9B) = 0;
}

s32 func_088CDEDC(char *arg0, u32 arg1, s32 arg2) {
    if (*(s32 *)(arg0 + 0x88) != 0) {
        if (arg1 >= 0x78) {
            return 1;
        }
        if (arg2 == 0) {
            switch (*(u16 *)(D_089CC438 + 0x6AF0E)) {
            case 0x75:
            case 1:
            case 0x6E:
                return 1;
            }
        }
    }
    return 0;
}

void func_088CDF5C(char *arg0, Rec *arg1) {
    s32 t;
    Act *p;

    t = func_08813E70(D_089CBBE4);
    if (t < 0) {
        return;
    }
    p = arg1->unk28;
    if (p != 0) {
        if (p->time != -1) {
            do {
                if (p->time > t) {
                    break;
                }
                if (p->time == t) {
                    func_088CDFF8(arg0, p);
                }
                p++;
            } while (p->time != -1);
        }
    }
}

void func_088CDFF8(char *arg0, Act *arg1) {
    switch (arg1->kind) {
    case 0:
        break;
    case 1:
        func_0884D790(D_089CC01C, arg1->arg, 1);
        break;
    case 2:
        func_0884D790(D_089CC01C, arg1->arg, 0);
        break;
    }
}

}
