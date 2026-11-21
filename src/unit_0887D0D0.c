/* unit_0887D0D0: 0x0887D0D0-0x0887D65C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_0887D0B4 and unit_0887D65C.
 *
 * Optimized for speed: loops unrolled by 8, divisions by a constant are
 * multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 id;
    s16 count;
} Slot;

typedef struct {
    char pad0[0x10];
    s32 unk10;
    char pad14[4];
} Item18;

typedef struct {
    char pad0[0x404];
    u16 x[2][90];
} Glob;

extern char *D_08A62C7C;
extern char *D_089CC438;
extern u16 D_089A872C[];
extern u8 D_089A8708[10][3];
extern u8 D_089A8709[10][3];
extern u8 D_089A870A[10][3];
extern u8 D_089A8728;
extern u8 D_089A8729;
extern u8 D_089A872A;
extern Item18 D_0899D198[];

extern Slot *func_08856884(char *, s32);
extern s32 func_0886A35C(char *, s32);
extern s32 func_0886A30C(char *, s32);
extern s32 func_0887E320(char *);

/* The first loop covers 90 halfword pairs; its bound is written `i <= 0x59`
 * (test in $at). The structure pointer is reloaded inside the loop body so
 * the unrolled remainder adds index + base. splat names the field addresses
 * D_089A8709, D_089A870A, D_089A8729 and D_089A872A: they are their own
 * externs. */
void func_0887D0D0(char *arg0) {
    u8 i;
    s32 j;
    s32 lvl;
    s32 v;
    s32 r;
    char *g;
    Slot *p;

    *(s32 *) (arg0 + 0x10C) = *(s32 *) (*(char **) (D_08A62C7C + 0x4C) + 0x3C) * 10;
    *(s32 *) (arg0 + 0x110) = 0;
    for (i = 0; i <= 0x59; i++) {
        Glob *q = (Glob *) D_08A62C7C;
        *(s32 *) (arg0 + 0x110) += D_089A872C[i] * (u16) (q->x[0][i] - q->x[1][i]);
    }
    g = D_08A62C7C;
    v = *(s32 *) (*(char **) (g + 0x68) + 0x10) / 9000;
    lvl = 0;
    if (v > 0 && v < 11) {
        lvl = v - 1;
    }
    v = (func_0886A35C(D_08A62C7C, 1) - func_0886A35C(g, 0) - 1) / 1800;
    if (v < D_089A8708[lvl][0]) {
        r = D_089A8728;
    } else if (v < D_089A8709[lvl][0]) {
        r = D_089A8729;
    } else if (v < D_089A870A[lvl][0]) {
        r = D_089A872A;
    } else {
        r = 0;
    }
    *(u32 *) (arg0 + 0x114) = (u32) (*(s32 *) (arg0 + 0x10C) * r) / 100;
    *(s32 *) (arg0 + 0x118) = 0;
    p = func_08856884(D_089CC438, 0);
    for (j = 0; j < 0x18; j++) {
        *(s32 *) (arg0 + 0x118) += p[j].count * D_0899D198[p[j].id].unk10;
    }
    *(u32 *) (arg0 + 0x120) = (u32) (*(s32 *) (arg0 + 0x11C) *
        (*(s32 *) (arg0 + 0x10C) + *(s32 *) (arg0 + 0x110) + *(s32 *) (arg0 + 0x114) + *(s32 *) (arg0 + 0x118))) / 100;
    if (func_0886A30C(D_08A62C7C, 1) == 1) {
        *(s32 *) (arg0 + 0x124) = func_0887E320(arg0);
    }
}
