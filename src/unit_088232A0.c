/* unit_088232A0: 0x088232A0-0x08823960 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_08A631A8;
extern char *D_08A62C54;
extern char *D_089CC438;
extern s8 D_08938608[];
extern u16 D_089AC954[];
extern u16 D_089AC966;
extern u16 D_089AC968;
extern u16 D_089AC9BC[];

extern void func_08890DE8(char *, s8, u8);
extern void func_08821890(char *, s32);
extern void func_08821A10(char *, s32, s32);
extern void func_08823174(char *, s32, s32, s16 *, s16 *, s16 *);
extern s32 func_0885F7D4(char *, s32);
extern char *func_0885F82C(char *, s32);
extern s16 func_088DA740(s32, u16, s32);
extern void func_08821924(char *, s32);
extern u8 func_08823960(char *, s32, s16);
extern char *func_0885151C(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_08890DFC(char *, s32, s16);
extern void func_08892004(char *, char *, ...);

static inline s16 lowbit(u16 x) {
    u32 i;

    for (i = 0; i < 16; i++) {
        if ((((x & (1 << i)) != 0) ^ 1) == 0) {
            return i;
        }
    }
    return -1;
}

void func_088232A0(char *arg0, s32 arg1, s16 arg2, u16 arg3, s32 arg4) {
    s32 s3;
    char *e;
    s32 idx;
    s16 a9E;
    s16 a9C;
    s16 a9A;
    s16 b98;
    s16 b96;
    s16 b94;
    s16 a3C;
    s16 b38;
    s16 b34;
    s16 k2;
    s8 c2b;
    s8 c1b;
    s8 c2;
    s8 c1;
    s8 c0;
    s8 c0b;
    char buf0[0x28];
    char buf1[0x28];
    char *s;

    s3 = *(s32 *)(arg0 + 0x530);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08821890(arg0, s3);
    func_08821A10(arg0, s3, arg1);
    func_08823174(arg0, s3, arg1, &a9C, &a9E, &a9A);
    idx = func_0885F7D4(D_08A62C54, arg1);
    if (idx != -1) {
        e = func_0885F82C(D_08A62C54, idx);
        a9E = D_08938608[lowbit(*(u16 *)(e + 2))];
        k2 = D_08938608[lowbit(*(u16 *)(e + 6))];
        a9C = func_088DA740(s3, *(u16 *)(e + 2), *(s16 *)(e + 4));
        a3C = func_088DA740(s3, *(u16 *)(e + 6), *(s16 *)(e + 8));
    } else {
        k2 = -1;
    }
    func_08821924(arg0, s3);
    c0b = c0 = c2b = c2 = c1b = c1 = 0;
    if (func_08823960(arg0, s3, a9E) == 1) {
        c0 = 3;
        c0b = c0;
    }
    if (func_08823960(arg0, s3, k2) == 1) {
        c1 = 3;
        c1b = c1;
    }
    if (arg4 != 0) {
        func_08821A10(arg0, s3, arg4);
        func_08823174(arg0, s3, arg4, &b96, &b98, &b94);
        idx = func_0885F7D4(D_08A62C54, arg4);
        if (idx != -1) {
            e = func_0885F82C(D_08A62C54, idx);
            b98 = D_08938608[lowbit(*(u16 *)(e + 2))];
            b38 = D_08938608[lowbit(*(u16 *)(e + 6))];
            b96 = func_088DA740(s3, *(u16 *)(e + 2), *(s16 *)(e + 4));
            b34 = func_088DA740(s3, *(u16 *)(e + 6), *(s16 *)(e + 8));
        } else {
            b38 = -1;
        }
        func_08821924(arg0, s3);
        if (a9E >= 0) {
            if (a9E == b98) {
                if (a9C > b96) {
                    c0 = 4;
                } else if (b96 > a9C) {
                    c0 = 2;
                }
            } else if (a9E == b38) {
                if (a9C > b34) {
                    c0 = 4;
                } else if (b34 > a9C) {
                    c0 = 2;
                }
            } else {
                c0 = 4;
                c0b = c0;
            }
        }
        if (k2 >= 0) {
            if (k2 == b98) {
                if (a3C > b96) {
                    c1 = 4;
                } else if (b96 > a3C) {
                    c1 = 2;
                }
            } else if (k2 == b38) {
                if (a3C > b34) {
                    c1 = 4;
                } else if (b34 > a3C) {
                    c1 = 2;
                }
            } else {
                c1 = 4;
                c1b = c1;
            }
        }
        if (a9A > 0) {
            if (b94 > 0) {
                if (b94 < a9A) {
                    c2 = 4;
                } else if (a9A < b94) {
                    c2 = 2;
                }
            } else {
                c2 = 4;
                c2b = c2;
            }
        }
    }
    if (a9E >= 0) {
        s = func_0885151C(D_089CC438, D_089AC954[(s16)(a9E < 5 ? 11 : 12)]);
        func_0880E8F0(buf0, s, c0, a9C);
        func_08890DFC(D_08A631A8, arg2, arg3);
        s = func_0885151C(D_089CC438, D_089AC966);
        func_08892004(D_08A631A8, s, c0b, func_0885151C(D_089CC438, D_089AC9BC[a9E]), buf0);
        arg3 += 15;
    }
    if (k2 >= 0) {
        s = func_0885151C(D_089CC438, D_089AC954[(s16)(k2 < 5 ? 11 : 12)]);
        func_0880E8F0(buf1, s, c1, a3C);
        func_08890DFC(D_08A631A8, arg2, arg3);
        s = func_0885151C(D_089CC438, D_089AC966);
        func_08892004(D_08A631A8, s, c1b, func_0885151C(D_089CC438, D_089AC9BC[k2]), buf1);
        arg3 += 15;
    }
    if (a9A != 0) {
        func_08890DFC(D_08A631A8, arg2, arg3);
        s = func_0885151C(D_089CC438, D_089AC968);
        func_08892004(D_08A631A8, s, c2b, c2, a9A);
    }
}
