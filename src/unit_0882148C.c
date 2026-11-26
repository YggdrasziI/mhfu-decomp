/* unit_0882148C: 0x0882148C-0x08821774 (ULES01213) */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct {
    u8 id;
    s8 val;
} Pair;

extern char *D_089CC438;
extern char *D_08A631A8;
extern char D_08938478[];
extern char D_089385DC[];
extern u16 D_089AC9CC;
extern u16 D_089AC9D2;
extern u16 D_089AC8AA;
extern u16 D_089ACC70[];

extern char *func_0885151C(char *, u16);
extern int func_088915B0(char *, s16, s16, s8, char *, ...);
extern void func_08821774(s32, s32, Pair *);
extern s32 func_08821828(s32, Pair *, Pair *);
extern void func_08890E38(char *, s32);
extern void func_08890DFC(char *, s32, s16);
extern int func_0889134C(char *, char *, ...);
extern void func_08891474(char *, s16, s16, char *, ...);

void func_0882148C(s32 arg0, s32 arg1, s16 x, s16 y, s32 arg4, u8 flags) {
    Pair cur[10];
    s8 col[9];
    Pair other[10];
    Pair *p;
    s32 i;
    s32 xx;
    s8 c;
    s16 yy;
    s8 *w;
    s32 j;
    Pair *o;
    s16 x0;
    s8 *q;
    s32 top;
    s16 r;
    s32 n;

    if (!(flags & 8)) {
        c = 0;
        n = 5;
    } else {
        c = 10;
        n = 10;
        arg4 = 0;
    }
    func_088915B0(D_08A631A8, x, y, n, D_08938478, func_0885151C(D_089CC438, D_089AC9CC));
    col[8] = c;
    col[7] = c;
    col[6] = c;
    col[5] = c;
    col[4] = c;
    col[3] = c;
    col[2] = c;
    col[1] = c;
    col[0] = c;
    p = cur;
    func_08821774(arg0, arg1, p);
    if (arg4 != 0) {
        if (arg1 != arg4) {
            o = other;
            func_08821774(arg0, arg4, o);
            i = 0;
            q = col;
            for (; i < 9; i++, q++, p++) {
                r = func_08821828(arg0, p, o);
                if (r > 0) {
                    *q = 4;
                } else if (r < 0) {
                    *q = 2;
                }
            }
        }
        p = cur;
    }
    xx = x;
    top = y + 16;
    yy = top;
    j = 0;
    w = col;
    for (; j < 9; j++, w++, p++) {
        func_08890E38(D_08A631A8, c);
        func_08890DFC(D_08A631A8, xx, yy);
        if (p->id == 0) {
            if (j != 0) {
                return;
            }
            func_0889134C(D_08A631A8, D_08938478, func_0885151C(D_089CC438, D_089AC9D2));
            return;
        }
        func_0889134C(D_08A631A8, D_08938478, func_0885151C(D_089CC438, D_089ACC70[p->id]));
        if (p->id != 1) {
            x0 = xx;
            func_08891474(D_08A631A8, x0 + 0x46, yy, D_08938478, func_0885151C(D_089CC438, D_089AC8AA));
            func_08890E38(D_08A631A8, *w);
            func_08891474(D_08A631A8, x0 + 0x54, yy, D_089385DC, p->val);
        }
        yy += 16;
        if (j == 4) {
            xx = (s16)(xx + 0x78);
            yy = top;
        }
    }
}
