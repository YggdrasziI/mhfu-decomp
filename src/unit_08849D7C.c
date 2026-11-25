/* unit_08849D7C: 0x08849D7C-0x0884A66C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * NonMatching: 98.68 %. Saved registers are a permutation of the original's
 * (arg0 in s2 instead of s4, loop locals rotated); in case 0 one byte read goes
 * to a3 instead of a2. Owns jtbl_08931220 and the initialised locals
 * D_0893B760 and D_0893B770 once it matches.
 */

/* func_08849D7C (ULES01213), piece text_08849D7C, 0x08849D7C-0x0884A66C.
 *
 * NonMatching: 98.68 %. Only saved-register colouring differs (arg0 in s2
 * instead of s4, the case-1/case-2 loop locals rotated) plus one argument
 * temporary (a3 for a2) in case 0.
 *
 * Optimized for speed (loop guards, loop shapes).
 * Data owned: two initialised s16[7] locals (D_0893B760, D_0893B770, 0x10
 * bytes each with padding) and the switch table jtbl_08931220 (6 words).
 */

#pragma optimize_for_size off
typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_08A631A0;
extern char *D_08A631A8;
extern char *D_08A62C7C;
extern char *D_089CC438;
extern s32 D_09A44C5C;
extern u16 D_089B558C;
extern u16 D_089B5592;
extern u16 D_089B5590;
extern u16 D_089B558E;
extern u16 D_089B5588;
extern u16 D_089B558A;
extern u16 D_089B5578[];
extern u16 D_089AC710[];
extern char D_0893B650[];
extern char D_0893B64C[];
extern char D_0893B780[];

extern char *func_09A63198(s32, u16);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);
extern u8 func_0884FA5C(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_0881A8F8(char *, s16, s16, u8);
extern char *func_0885151C(char *, u16);
extern char *func_08851528(char *, s32);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_08890DFC(char *, s16, s16);
extern void func_0884A66C(char *, s32, s32);
extern s32 func_08872D74(char *, s32);
extern s32 func_08872DC4(char *, s32);
extern s16 func_08872DD4(char *, s32);
extern s32 func_08872DE4(char *, s32);
extern s16 func_0886C768(char *, s32, s32);
extern s16 func_0886E578(char *, s32, u16);
extern int func_0880E8F0(char *, char *, ...);
extern s32 func_0886F78C(char *);
extern char *func_088298E4(char *);
extern void func_0881A8E0(char *, s16, s16, s32);

void func_08849D7C(char *arg0) {
    s32 idx = *(s32 *)(D_08A631A0 + 0xF7A574);
    s16 xs[7] = {0, 0, 0, 0, 0, 15, 0};
    char buf[16];
    s32 v0;
    s16 y3;
    s32 n3;
    s32 n2;
    char *g0;
    s32 i1;
    s32 x3;
    char *g2;
    s32 y1;
    s32 y2;
    u8 b1;
    s32 i2;
    s32 v;
    u8 a2;
    u8 a1;
    u16 k1;
    u8 a0;
    s32 v2;
    s16 y;
    u16 k2;
    char *str2;
    char *g1;
    s32 i3;
    s32 row;
    u16 k0;
    s32 x;

    func_088915B0(D_08A631A8, 0xFC, 0xE0, 5, D_0893B650, func_09A63198(D_09A44C5C, D_089B558C));
    func_08890E38(D_08A631A8, func_0884FA5C(D_089CC438, 0) == 1 ? 10 : 0);
    func_0881A8F8(arg0, xs[idx] + 0x142, 0xE0, 0);
    func_088915B0(D_08A631A8, 0xFC, 0x60, 5, D_0893B650,
                  func_09A63198(D_09A44C5C, D_089B5578[*(u8 *)(arg0 + 0x584)]));
    func_08890E38(D_08A631A8, 0);
    row = 7;
    switch (*(u8 *)(arg0 + 0x584)) {
    case 0:
        if (*(u8 *)(arg0 + 0x5E6) & 1) {
            k0 = *(s8 *)(D_08A62C7C + 0x77C);
            func_08891474(D_08A631A8, 0xFC, 0x70, func_09A63198(D_09A44C5C, D_089B5592), func_0885151C(D_089CC438, D_089AC710[k0]));
            g0 = D_08A62C7C;
            if (*(s8 *)(g0 + 0x7B2) == 0) {
                func_08890DFC(D_08A631A8, 0x188, 0x70);
                g0 = D_08A62C7C;
                func_0884A66C(arg0, (u16)(*(u16 *)((char *)(*(u8 *)(*(char **)(g0 + 0x720) + 0x1E8) * 2) + (s32)g0 + 0x29C) +
                                          *(u16 *)((char *)(*(u8 *)(*(char **)(g0 + 0x720) + 0x1E8) * 2) + (s32)g0 + 0x350)), 0);
            } else {
                v0 = *(s8 *)(g0 + 0x7A8);
                if (k0 == v0) {
                    func_08890DFC(D_08A631A8, 0x188, 0x70);
                    g0 = D_08A62C7C;
                    func_0884A66C(arg0, (u16)(*(u16 *)((char *)(*(u8 *)(*(char **)(g0 + 0x720) + 0x1E8) * 2) + (s32)g0 + 0x29C) +
                                              *(u16 *)((char *)(*(u8 *)(*(char **)(g0 + 0x720) + 0x1E8) * 2) + (s32)g0 + 0x350)), 0);
                } else {
                    a0 = *(u8 *)(g0 + 0x781);
                    a0 = (s32)a0 - *(s8 *)(*(char **)(g0 + 0x768) + 4);
                    func_08890DFC(D_08A631A8, 0x188, 0x70);
                    func_0884A66C(arg0, a0, 0);
                    func_08891474(D_08A631A8, 0xFC, 0x80, func_09A63198(D_09A44C5C, D_089B5592), func_0885151C(D_089CC438, D_089AC710[v0]));
                    g0 = D_08A62C7C;
                    a0 = *(u8 *)(g0 + 0x7AD);
                    a0 = (s32)a0 - *(s8 *)(*(char **)(g0 + 0x794) + 4);
                    func_08890DFC(D_08A631A8, 0x188, 0x80);
                    func_0884A66C(arg0, a0, 0);
                }
            }
            break;
        }
    case 1:
        y = 0x70;
        if (!(*(u8 *)(arg0 + 0x5E6) & 4)) {
            for (i1 = 0; i1 < 2; i1++) {
                if (*(u8 *)(arg0 + 0x5E6) & 2) {
                    if (func_08872D74(D_08A62C7C, i1) != 3) {
                        continue;
                    }
                    g1 = D_08A62C7C;
                    a1 = 1;
                    b1 = *(u8 *)(g1 + func_08872DC4(g1, i1) * 2 + 0x29C);
                } else {
                    if (func_08872D74(D_08A62C7C, i1) != 2) {
                        continue;
                    }
                    a1 = func_08872DD4(D_08A62C7C, i1);
                    b1 = a1 - func_08872DE4(D_08A62C7C, i1);
                }
                k1 = func_08872DC4(D_08A62C7C, i1);
                func_08891474(D_08A631A8, 0xFC, y, func_09A63198(D_09A44C5C, D_089B5592), func_0885151C(D_089CC438, D_089AC710[k1]));
                func_08890DFC(D_08A631A8, 0x188, y);
                func_0884A66C(arg0, b1, a1);
                y += 0x10;
            }
        } else {
            n2 = *(s8 *)(D_08A62C7C + 0x786);
            for (i2 = 0; i2 < n2; i2++) {
                g2 = D_08A62C7C;
                v2 = *(u8 *)(g2 + i2 + 0x781);
                if (v2 == 0) {
                    continue;
                }
                a2 = v2 - *(s8 *)(*(char **)(g2 + i2 * 4 + 0x768) + 4);
                k2 = *(s8 *)(g2 + i2 + 0x77C);
                str2 = func_09A63198(D_09A44C5C, D_089B5592);
                func_08891474(D_08A631A8, 0xFC, y, str2, func_0885151C(D_089CC438, D_089AC710[k2]));
                func_08890DFC(D_08A631A8, 0x188, y);
                func_0884A66C(arg0, a2, (u8)v2);
                y += 0x10;
            }
            if (n2 >= 4) {
                row = 8;
            }
        }
        break;
    case 2:
        y3 = 0x70;
        for (i3 = 0; i3 < 2; i3++) {
            if (func_08872D74(D_08A62C7C, i3) == 1) {
                n3 = (u16)func_08872DC4(D_08A62C7C, i3);
                func_08891474(D_08A631A8, 0xFC, y3, func_09A63198(D_09A44C5C, D_089B5592), func_08851528(D_089CC438, n3));
                func_08890DFC(D_08A631A8, 0x181, y3);
                x3 = (u16)func_0886C768(D_08A62C7C, n3, 0);
                func_0884A66C(arg0, x3, (u16)func_0886E578(D_08A62C7C, n3, i3));
                y3 += 0x10;
            }
        }
        break;
    case 3:
    case 4:
        func_0880E8F0(buf, D_0893B64C, (10 - *(s8 *)(D_089CC438 + 0x38F)) * 10);
        func_08891474(D_08A631A8, 0x150, 0x60, func_09A63198(D_09A44C5C, D_089B5590), buf);
        func_08891474(D_08A631A8, 0xFC, 0x70, D_0893B650, func_09A63198(D_09A44C5C, D_089B558E));
        break;
    case 5:
        v = func_0886F78C(D_08A62C7C);
        if (v > 999999) {
            v = 999999;
        }
        func_08891474(D_08A631A8, 0x15E, 0x70, D_0893B780, v, 2000);
        break;
    }
    {
        s16 xs2[7] = {0, 0, 0, 0, 0, 15, 0};

        func_08890E38(D_08A631A8, 5);
        y1 = row * 16 + 0x40;
        func_08891474(D_08A631A8, 0xFC, y1, D_0893B650, func_09A63198(D_09A44C5C, D_089B5588));
        y2 = (row + 1) * 16 + 0x40;
        func_08891474(D_08A631A8, 0xFC, y2, D_0893B650, func_09A63198(D_09A44C5C, D_089B558A));
        func_08890E38(D_08A631A8, 0);
        x = xs2[idx] + 0x142;
        func_0881A8E0(arg0, x, y1, *(s32 *)(func_088298E4(arg0) + 8));
        func_0881A8E0(arg0, x, y2, *(s32 *)(D_08A62C7C + 0x14));
    }
}
