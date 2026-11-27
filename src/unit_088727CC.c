/* unit_088727CC: 0x088727CC-0x08872980 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Needs opt_rebuildconditionals off (keeps the sltu of the flag) and the
 * rank choice as a static inline helper (sets the register colouring).
 */

#pragma opt_rebuildconditionals off
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    s16 a;
    u8 b;
    u8 c;
} Ent;

extern char *D_089CC438;
extern char *D_08A631A0;
extern s16 D_089A818C[][8];
extern s16 D_089A81DC[][8];
extern s32 func_0887276C(char *, s32);

static inline s32 rank(char *arg0) {
    u16 h = *(u16 *)(D_089CC438 + 0x6AF12);
    if (h >= 10000 && h < 20000) {
        if (*(s8 *)(*(char **)(arg0 + 0x68) + 0x1A) < 7) {
            return 0;
        }
        return 1;
    }
    if (*(s8 *)(*(char **)(arg0 + 0x68) + 0x1A) < 6) {
        return 2;
    }
    if (*(s8 *)(*(char **)(arg0 + 0x68) + 0x1A) < 9) {
        return 3;
    }
    return 4;
}

void func_088727CC(char *arg0, char *arg1) {
    u8 idx;
    s32 k;
    char *g;
    Ent *p;
    s16 t;
    s16 a;

    idx = func_0887276C(arg0, *(u8 *)(arg1 + 0x1E8));
    g = D_089CC438;
    k = rank(arg0);
    if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
        p = (Ent *)(g + k * 32 + idx * 4 + 0x6A54A);
    } else {
        p = (Ent *)(g + 0x388);
    }
    if (p->a == 0) {
        p->a = D_089A818C[k][idx];
    }
    *(s16 *)(arg1 + 0x41E) = D_089A818C[k][idx];
    a = p->a;
    *(s16 *)(arg1 + 0x2E4) = a;
    t = D_089A81DC[k][idx];
    if (a < t) {
        *(s16 *)(arg1 + 0x2E4) = t;
    }
    if (*(u8 *)(D_089CC438 + 0x480) == 0) {
        *(u16 *)(arg1 + 0x774) = p->b;
        (*(u8 *)(arg1 + 0x1E8) + arg0)[0x5C2] = *(u16 *)(arg1 + 0x774);
        (*(u8 *)(arg1 + 0x1E8) + arg0)[0x61C] = p->c;
        *(s16 *)(arg0 + 0x114) = *(s16 *)(arg1 + 0x2E4);
        *(u8 *)(arg0 + 0x74A) = *(u8 *)(arg1 + 0x1E8);
    }
}
