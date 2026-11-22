/* unit_088702F0: 0x088702F0-0x088707D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

extern char *D_089CC438;
extern char *D_089CC434;
extern char *D_09A4F0D0;
extern s32 D_09A4F0C4;
extern char *D_09C121B0;
extern u16 D_089AC5B2;
extern char *D_089CBBEC;
extern s32 D_08A62D8C;

extern void func_0886E978(char *, s32);
extern void func_0886E92C(char *, s32);
extern void func_088B87B0(char *, u8);
extern void func_088707D4(char *, u8 *);
extern char *func_088DCEBC(s32, u8);
extern void func_0886C59C(char *, char *, u16, s16);
extern char *func_0885151C(char *, u16);
extern void func_088307BC(char *, char *);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern int func_0886E130(char *, u16, s32);

static inline char *get_entry(char *base, s32 i) {
    if (i < 0 || i >= 20) {
        return 0;
    }
    return *(char **)(base + 0x1220 + i * 4);
}

void func_088702F0(char *arg0, s32 arg1, u8 *arg2) {
    char *p;
    u8 k;
    char *f;
    s32 i;
    s32 w;
    char *e;
    s32 v;
    s32 j;

    switch (*arg2) {
    case 2:
        *(u32 *)(arg0 + 0x110) |= 1 << ((u8)arg1 + 8);
        func_0886E978(arg0, 0);
        break;
    case 4:
        k = *(u8 *)(D_089CC438 + 0x2E);
        if (k == 5 || k == 6 || k == 7) {
            break;
        }
        func_0886E92C(arg0, 0);
        break;
    case 5:
        v = *(s16 *)(arg2 + 4);
        v = *(u16 *)(arg2 + 6) | ((v << 16) & 0xFFFF0000);
        if (v < *(s32 *)(arg0 + 0x10)) {
            *(s32 *)(arg0 + 0x10) = v;
        }
        break;
    case 6:
        v = *(s16 *)(arg2 + 4);
        if (*(s8 *)(arg0 + 0x20) < v) {
            *(s8 *)(arg0 + 0x20) = v;
            p = D_09A4F0D0;
            *(s32 *)(p + 0x210) = *(s32 *)(p + 0x204);
            *(s32 *)(p + 0x20C) = *(s32 *)(p + 0x208);
            for (i = 0x15; i <= 0x2A; i++) {
                *(u16 *)(p + i * 12) &= ~2;
            }
            func_088B87B0(D_089CC434, 1);
        }
        break;
    case 7:
        func_088707D4(arg0, arg2);
        break;
    case 9:
        e = func_088DCEBC(D_09A4F0C4, arg1);
        if (e != 0) {
            func_0886C59C(arg0, e, *(u16 *)(arg2 + 4), *(s16 *)(arg2 + 6));
        }
        break;
    case 10:
        k = *(u8 *)(D_089CC438 + 0x2E);
        if (k == 5 || k == 6 || k == 7) {
            break;
        }
        func_0886E92C(arg0, 1);
        break;
    case 11:
        *(u32 *)(arg0 + 0x110) |= 1 << ((u8)arg1 + 8);
        func_0886E978(arg0, 1);
        break;
    case 12:
        k = arg1;
        *(u32 *)(arg0 + 0x110) |= 1 << k;
        ((s8 *)(arg0 + 0x84))[k * 2] = *(s16 *)(arg2 + 4);
        break;
    case 13:
        k = arg1;
        *(u32 *)(arg0 + 0x110) |= 1 << (k + 4);
        *(u32 *)(arg0 + 0x10C) |= *(s16 *)(arg2 + 4) << 16;
        *(u32 *)(arg0 + 0x10C) |= *(s16 *)(arg2 + 6);
        break;
    case 14:
        if (*(s8 *)(arg0 + 0x12D) != 0) {
            *(s8 *)(arg0 + 0x12D) = 0;
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5B2));
            func_08883988(D_08A62D8C, 1, 0x77, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 20:
        w = *(s16 *)(arg2 + 4);
        w = *(u16 *)(arg2 + 6) | ((w << 16) & 0xFFFF0000);
        if (*(s16 *)(arg2 + 0xA) != -1) {
            *(char **)(arg0 + 0x24) = 0;
            for (j = 0; j < 20; j++) {
                f = get_entry(D_09C121B0, j);
                if (f != 0 && *(s16 *)(f + 0x4AC) == *(s16 *)(arg2 + 0xA)) {
                    *(char **)(arg0 + 0x24) = f;
                    break;
                }
            }
        }
        func_0886E130(arg0, *(u16 *)(arg2 + 8), w);
        break;
    case 15:
        v = *(s16 *)(arg2 + 4);
        ((s32 *)(arg0 + 0x5B0))[(u8)arg1] = *(u16 *)(arg2 + 6) | ((v << 16) & 0xFFFF0000);
        break;
    case 16:
        v = *(u16 *)(arg2 + 4);
        *(u64 *)(arg0 + 0x5B8) |= (u64)(u32)v + (u32)((*(s16 *)(arg2 + 6) << 16) & 0xFFFF0000) + ((u64)*(u16 *)(arg2 + 8) << 32);
        break;
    case 18:
        v = *(s16 *)(arg2 + 4);
        if (*(s8 *)(arg0 + 0x724) < v) {
            *(s8 *)(arg0 + 0x724) = v;
            *(s32 *)(arg0 + 0x678) = -1;
        }
        break;
    case 19:
        *(s8 *)(D_089CC438 + 0x418) = 1;
        *(s32 *)(arg0 + 0x678) = 0x4650;
        break;
    case 21:
        k = arg1;
        ((u8 (*)[44])(arg0 + 0x788))[*(s16 *)(arg2 + 4)][*(s16 *)(arg2 + 6)] |= (u8)(1 << k);
        break;
    }
}
