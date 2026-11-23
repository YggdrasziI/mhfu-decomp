/* unit_0886B0E0: 0x0886B0E0-0x0886B7C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;

typedef struct {
    u8 type;
    u8 pad1;
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 pad;
} Msg;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern s32 D_09A1DAEC;
extern char *D_089CBBEC;
extern u16 D_089AC5A0[];
extern u16 D_089AC5A2;
extern u16 D_089AC5A4;
extern u16 D_089AC5B4;

extern s32 func_088DCEBC(s32, u8);
extern void func_0886CADC(char *);
extern void func_088AB514(s32, s32, Msg *);
extern void func_0886E36C(char *);
extern void func_0886E828(char *, s32);
extern void func_08872B7C(char *);
extern s16 func_0886E9F4(char *, s32, s16);
extern void func_0886B918(char *);
extern void func_0886BCD0(char *);
extern void func_0886A648(char *);
extern char *func_0885151C(char *, u16);
extern void func_088307BC(char *, char *);
extern s32 func_08872B40(char *);
extern s32 func_0884FCB0(char *);
extern u8 func_08830728(char *, s8, s16, s16);
extern void func_08873554(char *, char *);

static inline u8 isFlag4(void) {
    return (*(u32 *)(D_089CC438 + 0x6AF14) & 4) != 0;
}

static inline u8 isActive(u8 i) {
    return *(u8 *)(D_089CC438 + i * 0x8C + 0x30) != 0;
}

s32 func_0886B0E0(char *arg0) {
    s32 r;
    s32 i;
    Msg m;

    r = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    for (i = 0; i < 4; i++) {
        if (!isActive(i)) {
            *(u32 *)(arg0 + 0x110) |= 1 << (i + 8);
        }
    }
    func_0886CADC(arg0);
    if (*(u16 *)(D_089CC438 + 0x6AF12) == 0) {
        return 0;
    }
    if (*(s8 *)(arg0 + 6) == 7) {
        return -2;
    }
    if (*(s8 *)(arg0 + 6) == 8) {
        return -2;
    }
    if (*(s8 *)(arg0 + 0x5AC) != 0) {
        u32 v;
        s64 w;
        m.type = 0xF;
        m.a = 0;
        v = ((u32 *)(arg0 + 0x5AC))[*(s8 *)(arg0 + 0x5AC)];
        m.c = v;
        m.b = v >> 16;
        func_088AB514(D_09A1DAEC, 6, &m);
        *(s8 *)(arg0 + 0x5AC) = 0;
        m.type = 0x10;
        m.a = 0;
        w = *(s64 *)(arg0 + 0x5B8);
        m.b = w;
        m.c = w >> 16;
        m.d = w >> 32;
        func_088AB514(D_09A1DAEC, 6, &m);
    }
    switch (*(s8 *)(arg0 + 0)) {
    case 0:
        if (*(s8 *)(arg0 + 6) == 4) {
            return 1;
        }
        if (*(s8 *)(arg0 + 6) == 6) {
            return -1;
        }
        if (*(s16 *)(arg0 + 0x1C) == -1) {
            return 1;
        }
        func_0886E36C(arg0);
        func_0886E828(arg0, 1);
        func_08872B7C(arg0);
        *(s16 *)(arg0 + 0x1C) = func_0886E9F4(arg0, r, *(s16 *)(arg0 + 0x1C));
        func_0886B918(arg0);
        func_0886BCD0(arg0);
        func_0886A648(arg0);
        return 0;
    case 1:
        switch (*(s8 *)(arg0 + 1)) {
        case 0:
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438,
                D_089AC5A0[(*(s32 *)(arg0 + 0x28) & 0x10) ? 0x1A : 0xC]));
            *(s8 *)(arg0 + 1) += 1;
            *(s32 *)(arg0 + 0x710) = 0x96;
            break;
        case 1:
            if (--*(s32 *)(arg0 + 0x710) > 0) {
                break;
            }
            *(s8 *)(arg0 + 1) += 1;
            if (*(s32 *)(arg0 + 0x28) & 0x80000) {
                if ((*(s32 *)(arg0 + 0x28) & 0x200000) && func_08872B40(arg0) == 0) {
                    *(s32 *)(arg0 + 0x710) = 0x708;
                    func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5A2));
                } else {
                    *(s32 *)(arg0 + 0x710) = 0x258;
                    func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5A0[0]));
                    if (*(s32 *)(arg0 + 0x28) & 0x10) {
                        func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5B4));
                    }
                }
            } else {
                *(s32 *)(arg0 + 0x710) = 0x708;
                func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5A2));
            }
            break;
        case 2:
            if (--*(s32 *)(arg0 + 0x710) > 0) {
                break;
            }
            *(s8 *)(arg0 + 0) += 1;
            *(s8 *)(arg0 + 1) = 0;
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5A4));
            if (isFlag4() != 1) {
                func_08830728(D_089CBBEC, 0, 0xF, 0);
            }
            *(s8 *)(arg0 + 0x767) = 0;
            break;
        }
        break;
    case 2:
        switch (*(s8 *)(arg0 + 1)) {
        case 0:
            *(s8 *)(arg0 + 1) += 1;
            *(s8 *)(arg0 + 6) = 4;
            ((u8 *)(arg0 + 0x84))[*(u8 *)(D_089CC438 + 0x28) * 2] = func_0884FCB0(D_089CC438);
            m.type = 0xC;
            m.a = 0;
            m.b = ((u8 *)(arg0 + 0x84))[*(u8 *)(D_089CC438 + 0x28) * 2];
            m.c = 0;
            func_088AB514(D_09A1DAEC, 6, &m);
            *(u32 *)(arg0 + 0x110) |= 1 << *(u8 *)(D_089CC438 + 0x28);
            *(s32 *)(arg0 + 0x118) = 0x1518;
            break;
        case 1:
            if (*(s32 *)(arg0 + 0x118) > 0) {
                *(s32 *)(arg0 + 0x118) -= 1;
            }
            for (i = 0; i < 4; i++) {
                if (!isActive(i)) {
                    *(u32 *)(arg0 + 0x110) |= 1 << i;
                }
            }
            if ((*(u32 *)(arg0 + 0x110) & 0xF) == 0xF || *(s32 *)(arg0 + 0x118) <= 0) {
                *(s8 *)(arg0 + 1) += 1;
                m.type = 0xD;
                m.a = 0;
                m.c = *(u32 *)(arg0 + 0x10C);
                m.b = *(u32 *)(arg0 + 0x10C) >> 16;
                func_088AB514(D_09A1DAEC, 6, &m);
                *(u32 *)(arg0 + 0x110) |= 1 << (*(u8 *)(D_089CC438 + 0x28) + 4);
                *(s32 *)(arg0 + 0x118) = 0x708;
            }
            break;
        case 2:
            if (*(s32 *)(arg0 + 0x118) > 0) {
                *(s32 *)(arg0 + 0x118) -= 1;
            }
            for (i = 0; i < 4; i++) {
                if (!isActive(i)) {
                    *(u32 *)(arg0 + 0x110) |= 1 << (i + 4);
                }
            }
            if (*(u8 *)(arg0 + 0x110) == 0xFF || *(s32 *)(arg0 + 0x118) <= 0) {
                *(s8 *)(arg0 + 1) += 1;
                *(u8 *)(D_089CC438 + 0x2E) = 4;
                *(s32 *)(arg0 + 0x14) /= *(u8 *)(arg0 + 0x70C);
                func_08873554(arg0, arg0 + 0x4B8);
            }
            break;
        case 3:
            break;
        }
        break;
    case 3:
        break;
    }
    return 0;
}
