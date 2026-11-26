/* unit_08821D48: 0x08821D48-0x0882217C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * The two formatting steps are static inline helpers (their u8 parameters
 * give the andi copies of the colours). The colours are initialised in one
 * assignment chain; with the declaration order below, c0 and c3 are the two
 * colours the compiler keeps on the stack. `flag & 0xFF` (not `(u8)flag`)
 * gives the original temporary registers. func_08890E38 takes an s32 here
 * (lb into v0, then a move to a1).
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 b[4];
    u32 m[4];
} Ent;

extern char *D_089CC438;
extern char *D_08A631A8;
extern Ent D_0893AD00[];
extern u8 D_089786F8[][0x20];
extern u16 D_089AC96E;
extern u16 D_089AC970;
extern u16 D_089AC972;
extern u16 D_089AC974;
extern u16 D_089AC976;
extern u16 D_089AC998[];
extern char D_0893855C;
extern char D_089385E4;

extern void func_08890DFC(char *, s16, s16);
extern void func_08890E38(char *, s32);
extern char *func_0885151C(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_08892004(char *, char *, ...);

static inline void stepA(char *dst, char *src, u8 prev, u8 cur) {
    if (prev != cur) {
        func_0880E8F0(dst, func_0885151C(D_089CC438, D_089AC974), src, cur);
    } else {
        func_0880E8F0(dst, func_0885151C(D_089CC438, D_089AC976), src);
    }
}

static inline void stepB(char *dst, char *src, u8 prev, u8 cur, u8 *v) {
    if (prev != cur) {
        func_0880E8F0(dst, func_0885151C(D_089CC438, D_089AC972), src, cur, *v);
    } else {
        func_0880E8F0(dst, &D_089385E4, src, *v);
    }
}

void func_08821D48(char *arg0, s16 x, s16 y, u8 *p, u32 mask, u32 mask2, s32 arg6, s32 flag) {
    union { u8 v[4]; s32 w; } u;
    char b[0x20];
    char a[0x20];
    u8 idx;
    Ent *e;
    u8 z2;
    u8 z1;
    u8 c3;
    u8 c2;
    u8 c1;
    u8 z0;
    s8 c0;
    char *t;

    func_08890DFC(D_08A631A8, x, y);
    idx = arg6;
    e = &D_0893AD00[idx];
    u.w = 0;
    c1 = c2 = c3 = z1 = z2 = c0 = z0 = 10;
    if (mask & e->m[3]) {
        c0 = (mask2 & e->m[3]) ? 3 : 0;
        z0 = 0;
    }
    if (mask & e->m[0]) {
        u.v[0] = (flag & 0xFF) + D_089786F8[p[0x10]][e->b[1]];
        c1 = ((flag & 0xFF) || (mask2 & e->m[0])) ? 3 : 0;
    }
    if (mask & e->m[1]) {
        u.v[1] = (flag & 0xFF) + D_089786F8[p[0x10]][e->b[2]];
        c2 = ((flag & 0xFF) || (mask2 & e->m[1])) ? 3 : 0;
        z1 = 0;
    }
    if (mask & e->m[2]) {
        u.v[2] = (flag & 0xFF) + D_089786F8[p[0x10]][e->b[3]];
        c3 = ((flag & 0xFF) || (mask2 & e->m[2])) ? 3 : 0;
        z2 = 0;
    }
    if (z0 != c1) {
        func_0880E8F0(b, func_0885151C(D_089CC438, D_089AC970), c1, u.v[0]);
    } else {
        func_0880E8F0(b, &D_0893855C, u.v[0]);
    }
    if (e->b[0] > 1) {
        stepA(a, b, c1, z1);
        stepB(b, a, z1, c2, &u.v[1]);
        if (e->b[0] > 2) {
            stepA(a, b, c2, z2);
            stepB(b, a, z2, c3, &u.v[2]);
        }
    }
    func_08890E38(D_08A631A8, c0);
    t = func_0885151C(D_089CC438, D_089AC96E);
    func_08892004(D_08A631A8, t, func_0885151C(D_089CC438, D_089AC998[idx]), z0, b);
}
