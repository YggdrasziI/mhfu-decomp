/* unit_08822C58: 0x08822C58-0x08823174 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * The spill slots of (s16)x, x + 14 and (s8)col in the second loop are
 * loop invariants hoisted by the compiler: the source uses x and col
 * directly. The order of the local declarations sets the saved registers.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Rec {
    u8 pad[6];
    u16 ids[3];
} Rec;

extern s32 D_08A62C54;
extern char *D_08A631A8;
extern char *D_089CC438;
extern u16 D_089AC8AA;
extern u16 D_089AC98C;
extern u16 D_089AC992;
extern u16 D_089AC994;
extern u16 D_089ACC70[];
extern u8 D_0893AC8C[];
extern u8 D_0899D19E[][24];
extern u8 D_0893AA88[];
extern char D_08938478[];
extern char D_08938548[];
extern char D_089385F8[];

extern s8 func_0885EB34(s32 arg0, Rec *arg1);
extern s32 func_0885E748(s32 arg0, Rec *arg1);
extern u8 *func_0885E834(s32 arg0, u16 arg1);
extern s32 func_08822BF4(s32 arg0, u16 arg1);
extern char *func_0885151C(char *, u16);
extern char *func_08851528(char *, u16);
extern int func_088915B0(char *, s16, s16, s8, char *, ...);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_08890DFC(char *, s16, s16);
extern int func_0889134C(char *, char *, ...);
extern int func_0880E8F0(char *, char *, ...);
extern int func_0880ED70(char *, char *);

void func_08822C58(s32 arg0, Rec *arg1, u16 x, u16 y, u8 arg4, s32 flags) {
    u8 *recs[2];
    u8 colors[2];
    char *names[2];
    char buf54[8];
    char buf4C[8];
    s32 n;
    s32 key;
    u8 *p;
    s32 j;
    s16 xx;
    s32 f8;
    s32 k;
    u8 col;
    s16 yy;
    s32 mul;
    s32 i;
    s32 id;

    f8 = flags & 8;
    if (f8 == 0) {
        col = 0;
    } else {
        col = 10;
    }
    if ((u8)func_0885EB34(D_08A62C54, arg1) == 0) {
        func_088915B0(D_08A631A8, (s16)x, (s16)y, (s8)col, D_08938478, func_0885151C(D_089CC438, D_089AC992));
        return;
    }
    key = 0;
    mul = 1;
    for (n = 0; n < 3; n++) {
        if (arg1->ids[n] != 0) {
            key += mul * func_08822BF4(arg0, arg1->ids[n]);
        }
        mul *= 3;
    }
    recs[1] = 0;
    recs[0] = 0;
    if (arg4 == 0) {
        switch (D_0893AC8C[key] & 3) {
        case 2:
            recs[1] = func_0885E834(D_08A62C54, arg1->ids[1]);
            names[1] = func_08851528(D_089CC438, arg1->ids[1]);
            colors[1] = D_0893AA88[D_0899D19E[arg1->ids[1]][0]];
            /* fall through */
        case 1:
            recs[0] = func_0885E834(D_08A62C54, arg1->ids[0]);
            names[0] = func_08851528(D_089CC438, arg1->ids[0]);
            colors[0] = D_0893AA88[D_0899D19E[arg1->ids[0]][0]];
            break;
        }
    } else {
        k = D_0893AC8C[key] >> 4;
        if (k != 0) {
            id = arg1->ids[k];
            recs[0] = func_0885E834(D_08A62C54, id);
            names[0] = func_08851528(D_089CC438, id);
            colors[0] = D_0893AA88[D_0899D19E[id][0]];
        }
    }
    if (f8) {
        colors[1] = 10;
        colors[0] = 10;
    }
    for (j = 0; j < 2; j++) {
        if (recs[j] == 0) {
            if (j == 0) {
                func_0880E8F0(buf54, D_08938548, func_0885E748(D_08A62C54, arg1));
                func_0880ED70(buf4C, buf54);
                func_088915B0(D_08A631A8, (s16)x, (s16)y, (s8)col, func_0885151C(D_089CC438, D_089AC994), buf4C);
            }
            break;
        }
        func_088915B0(D_08A631A8, (s16)x, (s16)y, (s8)colors[j], D_08938478, func_0885151C(D_089CC438, D_089AC98C));
        func_088915B0(D_08A631A8, (s16)(x + 14), (s16)y, (s8)col, D_08938478, names[j]);
        y += 16;
        p = recs[j] + 8;
        for (i = 0; i < 4; i++) {
            if (*p == 0) {
                break;
            }
            xx = (s16)(x + (i & 1) * 120);
            yy = (s16)(y + (i >> 1) * 16);
            func_08891474(D_08A631A8, xx, yy, D_08938478, func_0885151C(D_089CC438, D_089ACC70[*p]));
            if (*p != 1) {
                func_08890DFC(D_08A631A8, (s16)(xx + 70), yy);
                func_0889134C(D_08A631A8, D_089385F8, func_0885151C(D_089CC438, D_089AC8AA), (s8)p[1]);
            }
            p += 2;
        }
        y += (u16)(((i + 1) >> 1) * 16);
    }
}
