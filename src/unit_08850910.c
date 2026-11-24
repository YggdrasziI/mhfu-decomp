/* unit_08850910: 0x08850910-0x08850C34 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08850910 (ULES01213): Vec3s is a hypothesis from the grouped lh/lh/lh sh/sh/sh copy. */
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

typedef struct { s16 x, y, z; } Vec3s;

typedef struct {
    u8 a;
    u8 b;
    u16 c;
    u16 d;
    Vec3s v;
} Entry;

typedef struct {
    char pad0[0x20];
    Entry slot[6];
    char pad68[0xA8 - 0x68];
    Entry tbl[(0x4020 - 0xA8) / 12];
    u16 idx[6];
} Block;

extern u8 func_08850C34(char *, s32, s32, s32);
extern void func_08850D04(char *);
extern void memset(void *, s32, s32);


void func_08850910(char *arg0) {
    Block *b = (Block *)(arg0 + 0x4A0);
    Entry *e;

    if (func_08850C34(arg0, b->idx[0], 5, 6) == 1) {
        e = &b->tbl[b->idx[0]];
        b->slot[0].a = e->a;
        b->slot[0].b = e->b;
        b->slot[0].c = e->c;
        b->slot[0].d = e->d;
        b->slot[0].v = e->v;
    }
    func_08850D04(arg0);
    if (func_08850C34(arg0, b->idx[1], 0, 0) == 1) {
        e = &b->tbl[b->idx[1]];
        b->slot[1].a = e->a;
        b->slot[1].b = e->b;
        b->slot[1].c = e->c;
        b->slot[1].d = e->d;
        b->slot[1].v = e->v;
    } else {
        memset(&b->slot[1], 0, 12);
    }
    if (func_08850C34(arg0, b->idx[2], 1, 1) == 1) {
        e = &b->tbl[b->idx[2]];
        b->slot[2].a = e->a;
        b->slot[2].b = e->b;
        b->slot[2].c = e->c;
        b->slot[2].d = e->d;
        b->slot[2].v = e->v;
    } else {
        memset(&b->slot[2], 0, 12);
    }
    if (func_08850C34(arg0, b->idx[3], 2, 2) == 1) {
        e = &b->tbl[b->idx[3]];
        b->slot[3].a = e->a;
        b->slot[3].b = e->b;
        b->slot[3].c = e->c;
        b->slot[3].d = e->d;
        b->slot[3].v = e->v;
    } else {
        memset(&b->slot[3], 0, 12);
    }
    if (func_08850C34(arg0, b->idx[4], 3, 3) == 1) {
        e = &b->tbl[b->idx[4]];
        b->slot[4].a = e->a;
        b->slot[4].b = e->b;
        b->slot[4].c = e->c;
        b->slot[4].d = e->d;
        b->slot[4].v = e->v;
    } else {
        memset(&b->slot[4], 0, 12);
    }
    if (func_08850C34(arg0, b->idx[5], 4, 4) == 1) {
        e = &b->tbl[b->idx[5]];
        b->slot[5].a = e->a;
        b->slot[5].b = e->b;
        b->slot[5].c = e->c;
        b->slot[5].d = e->d;
        b->slot[5].v = e->v;
    } else {
        memset(&b->slot[5], 0, 12);
    }
}
