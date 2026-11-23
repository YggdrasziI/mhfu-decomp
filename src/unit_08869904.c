/* unit_08869904: 0x08869904-0x0886A054 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08869904 (0x08869904-0x0886A054): clears and sets up many fields of arg0 (role unknown). */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Four 90-entry s16 tables at 0x134; indexing them through a typed local
 * (not raw byte sums) gives the `i * 2 + obj` order of the unrolled tail. */
typedef struct {
    char pad0[0x134];
    s16 a[90];
    s16 b[90];
    s16 c[90];
    s16 d[90];
} S134;

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_089CBBEC;
extern char *D_08A62CB4;
extern char *D_08A62C7C;
extern char *D_09C121B0;
extern u8 D_08A62C8C[];
extern char D_08A5C440[];
extern u8 D_089A7EA4, D_089A7EA5, D_089A7EA6, D_089A7EA7, D_089A7EA8;
extern u8 D_089A7EA9, D_089A7EAA, D_089A7EAB, D_089A7EAC, D_089A7EAD;
extern u8 D_08A62C80, D_08A62C81, D_08A62C82, D_08A62C83, D_08A62C84;
extern u8 D_08A62C85, D_08A62C86, D_08A62C87, D_08A62C88, D_08A62C89;

extern void func_0886CA74(char *);
extern void func_0886E23C(char *);
extern void func_0886BE34(char *);
extern s32 func_088900C4(char *, s32);
extern void func_0886B7C0(char *);
extern s32 func_0886B8DC(char *);
extern s32 func_0884FCB0(char *);
extern void func_0886A0B4(char *, s32);
extern s32 func_0886A35C(char *, s32);
extern s32 func_08872BFC(char *, char *);
extern u8 func_088698EC(char *);
extern void func_0886E27C(char *);
extern void func_0886BE50(char *);
extern void func_0886A444(char *);
extern void func_0886D4D8(char *);
extern void func_08895EA0(char *);
extern s32 func_08855410(char *);
extern void memcpy(void *, void *, unsigned int);
extern void func_08872E48(char *, s32);
extern void func_08873554(char *, char *);
extern s32 func_08873488(char *);
extern void func_08873838(char *);

static inline u8 test_F7A57C(void) {
    return (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0;
}

void func_08869904(char *arg0) {
    S134 *s = (S134 *)arg0;
    s32 i;
    char *base;
    char *p;
    char *q;

    D_089CC438[0x2E] = 2;
    func_0886CA74(arg0);
    func_0886E23C(arg0);
    func_0886BE34(arg0);
    if (!test_F7A57C()) {
        for (i = 0; i < 15; i++) {
            arg0[0x11D + i] = func_088900C4(D_08A631A0, 0);
        }
    } else {
        for (i = 0; i < 15; i++) {
            arg0[0x11D + i] = D_08A62C8C[i];
        }
    }
    D_08A62C80 = D_089A7EA4;
    D_08A62C81 = D_089A7EA5;
    D_08A62C82 = D_089A7EA6;
    D_08A62C83 = D_089A7EA7;
    D_08A62C84 = D_089A7EA8;
    D_08A62C85 = D_089A7EA9;
    D_08A62C86 = D_089A7EAA;
    D_08A62C87 = D_089A7EAB;
    D_08A62C88 = D_089A7EAC;
    D_08A62C89 = D_089A7EAD;
    func_0886B7C0(arg0);
    func_0886B8DC(arg0);
    for (i = 0; i < 32; i++) {
        *(s16 *)(arg0 + 0x8C + i * 4) = 0;
        *(s8 *)(arg0 + 0x8E + i * 4) = 0;
    }
    for (i = 0; i < 90; i++) {
        s->b[i] = 0;
        s->a[i] = 0;
        s->c[i] = 0;
        s->d[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        arg0[0x11D + i] = func_0886B8DC(arg0);
    }
    *(s32 *)(arg0 + 0x110) = 0;
    *(s32 *)(arg0 + 0x10C) = 0;
    arg0[0x11C] = 0;
    arg0[0x117] = 0;
    arg0[0x9] = 0;
    arg0[0x84] = 0;
    arg0[0x85] = 0;
    arg0[0x86] = 0;
    arg0[0x87] = 0;
    arg0[0x88] = 0;
    arg0[0x89] = 0;
    arg0[0x8A] = 0;
    arg0[0x8B] = 0;
    *(s32 *)(arg0 + 0x5B0) = 0;
    *(s32 *)(arg0 + 0x5B4) = 0;
    arg0[0x5AC] = 0;
    *(s32 *)(arg0 + 0x5B8) = 0;
    *(s32 *)(arg0 + 0x5BC) = 0;
    arg0[0x85 + *(u8 *)(D_089CC438 + 0x28) * 2] = func_0884FCB0(D_089CC438);
    D_089CC438[0x24] = 0;
    D_089CC438[0x25] = 0;
    D_089CC438[0x26] = 0;
    D_089CC438[0x27] = 0;
    for (i = 0; i < 5; i++) {
        *(s16 *)(arg0 + 0x6C + i * 4) = 0;
        *(s8 *)(arg0 + 0x6E + i * 4) = 0;
    }
    arg0[0x80] = 0;
    arg0[0x81] = 0;
    arg0[0x3] = 0;
    arg0[0x0] = 0;
    arg0[0x1] = 0;
    arg0[0x20] = 0;
    arg0[0x82] = 0;
    *(s32 *)(arg0 + 0x24) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    arg0[0x4] = 0;
    *(s16 *)(arg0 + 0x5C0) = 0;
    base = D_08A5C440;
    *(char **)(arg0 + 0x50) = base;
    *(char **)(arg0 + 0x4C) = base;
    *(s32 *)(arg0 + 0x68) = **(s32 **)(arg0 + 0x4C) + *(s32 *)(arg0 + 0x50);
    D_089CC438[0x6AF10] = *(s8 *)(*(char **)(arg0 + 0x68) + 0x1C);
    func_0886A0B4(arg0, 0xFF);
    *(s32 *)(arg0 + 0x10) = func_0886A35C(arg0, 1);
    arg0[0x83] = (*(s32 *)(arg0 + 0x10) - 1) / 9000;
    if ((s8)arg0[0x83] > 2) {
        arg0[0x83] = 2;
    }
    *(s32 *)(arg0 + 0x54) = *(s32 *)(base + 0x10) + *(s32 *)(arg0 + 0x50);
    *(s16 *)(arg0 + 0x1C) = 0;
    *(s16 *)(arg0 + 0x1E) = 0;
    *(s32 *)(arg0 + 0x58) = *(s32 *)(*(char **)(arg0 + 0x68) + 0x14) + *(s32 *)(arg0 + 0x50);
    *(s32 *)(arg0 + 0x718) = *(s32 *)(base + 0x18) + *(s32 *)(arg0 + 0x50);
    *(s32 *)(arg0 + 0x71C) = *(s32 *)(base + 0x14) + *(s32 *)(arg0 + 0x50);
    *(s32 *)(arg0 + 0x60) = *(s32 *)(base + 0x1C) + *(s32 *)(arg0 + 0x50);
    *(s32 *)(arg0 + 0x5C) = *(s32 *)(base + 0xC) + *(s32 *)(arg0 + 0x50);
    *(s32 *)(arg0 + 0x14) = *(s32 *)(*(char **)(arg0 + 0x68) + 0x8);
    *(s32 *)(arg0 + 0x18) = *(s32 *)(*(char **)(arg0 + 0x68) + 0xC);
    *(s32 *)(arg0 + 0x28) = *(s32 *)(*(char **)(arg0 + 0x68) + 0x0);
    arg0[0x7C0] = *(s8 *)(base + 0x4B);
    arg0[0x116] = *(s8 *)(base + 0x49);
    func_08872BFC(arg0, arg0 + 0x7C0);
    if (func_088698EC(arg0) == 1) {
        D_089CC438[0x41A] = 1;
    } else {
        D_089CC438[0x41A] = 0;
    }
    arg0[0x12D] = *(s8 *)(base + 0x46);
    arg0[0x12E] = *(s8 *)(base + 0x47);
    arg0[0x12F] = *(s8 *)(base + 0x48);
    arg0[0x130] = 0;
    arg0[0x131] = *(s32 *)(arg0 + 0x10) / 9000;
    func_0886E27C(arg0);
    func_0886BE50(arg0);
    for (i = 0; i < 90; i++) {
        arg0[0x5C2 + i] = 0;
        arg0[0x61C + i] = 0;
    }
    func_0886A444(arg0);
    func_0886D4D8(arg0);
    func_08895EA0(D_089CBBEC);
    if (func_08855410(D_089CC438) != 0) {
        p = D_089CC438 + 0x4A0;
        memcpy(D_089CC438 + 0x6ADFC, p + 0x3F28, 0x60);
        for (i = 0; i < 24; i++) {
            *(s16 *)(p + 0x3F2A + i * 4) = 0;
            *(s16 *)(p + 0x3F28 + i * 4) = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        func_08872E48(arg0, i);
    }
    q = D_08A62CB4;
    *(s32 *)(q + 0x104) = *(s32 *)(D_089CC438 + 0x696F0);
    *(s32 *)(q + 0x108) = *(s32 *)(D_089CC438 + 0x696E8);
    func_08873554(arg0, arg0 + 0x404);
    arg0[0x767] = 1;
    if (func_08873488(D_08A62C7C) != 0) {
        func_08873838(D_08A62C7C);
    }
    arg0[0x67D] = 0;
    arg0[0x67E] = 0;
    arg0[0x67F] = 0;
    arg0[0x680] = 0;
    arg0[0x681] = 0;
    *(s16 *)(arg0 + 0x682) = 0;
    arg0[0x8A4] = 0;
    D_09C121B0[0x1278] = 0;
}
