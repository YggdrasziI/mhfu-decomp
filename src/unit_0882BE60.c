/* unit_0882BE60: 0x0882BE60-0x0882C11C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Same as func_0882AF70 (unit_0882AF70.c) with a 5:5:5:1 vertex colour
 * from (r, g, b) instead of 0xFFFF: one textured sprite of size (w, h)
 * from the D_089391A8 table entry idx pushed to the list at D_08A62C40
 * through the same inlined helper. Speed setting needed; the store order is
 * the one of func_0882AF70. The sum x + w in its own local, set before the
 * colour, gives the `or` operand order of the second vertex word.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    s16 u;
    s16 v;
    s16 du;
    s16 dv;
    u16 unk8;
    u16 unkA;
} Ent;

typedef struct {
    s32 n0;
    s32 n1;
    u32 w[10];
    u32 tail[2];
    u32 w2[3];
} Cmd;

extern Ent D_089391A8[];
extern s32 D_08A62C40;
extern void func_088314A0(char *, s32, s32);
extern int func_088596C8(char *, u32 *, s32, s32);

static inline s32 push(char *l, Cmd *c, s32 id) {
    s32 i;
    u32 *src;
    u32 *start;
    s32 pre;
    s32 fin;

    if (id < 0 || id >= 20) {
        return 0;
    }
    start = *(u32 **)(l + 0x80198);
    pre = c->n0;
    if ((u32)((start - (u32 *)(l + (*(s32 *)(l + 4) << 18) + 0x198)) + (*(volatile s32 *)&c->n0 + c->n1)) >= 0x10000) {
        return 0;
    }
    if (pre > 0) {
        c->tail[0] = (((u32)start & 0xFF000000) >> 8) | 0x10000000;
        c->tail[1] = (*(u32 *)(l + 0x80198) & 0xFFFFFF) | 0x01000000;
    }
    src = (u32 *)&c->n1;
    src++;
    fin = *(volatile s32 *)&c->n0;
    for (i = 0; i < c->n0 + c->n1; i++) {
        **(u32 **)(l + 0x80198) = *src;
        *(u32 **)(l + 0x80198) += 1;
        src++;
    }
    func_088596C8(l, start + fin, c->n1, id);
    return 1;
}


void func_0882BE60(char *arg0, s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b, s32 idx) {
    Cmd c;
    Ent *e;
    u32 col;
    u32 x2;

    e = &D_089391A8[idx];
    func_088314A0(arg0, e->unk8, e->unkA);
    x2 = (x & 0xFFFF) + (w & 0xFFFF);
    col = ((u32)((r & 0xFF) * 32) >> 8) | (((u32)((g & 0xFF) * 32) >> 8) << 5) | (((u32)((b & 0xFF) * 32) >> 8) << 10) | 0x8000;
    c.w[1] = ((x & 0xFFFF) << 16) | col;
    c.n1 = 9;
    c.w[2] = y & 0xFFFF;
    c.w[6] = 0x1E000001;
    c.w[8] = 0x50000001;
    c.w[9] = 0x12800116;
    c.n0 = 6;
    c.w2[0] = 0x04060002;
    c.w[4] = (x2 << 16) | col;
    c.w2[1] = 0x10000000;
    c.w[5] = ((y & 0xFFFF) + (h & 0xFFFF)) & 0xFFFF;
    c.w2[2] = 0x08000000;
    c.w[7] = 0xC9000100;
    c.w[0] = (e->v << 16) | e->u;
    c.w[3] = ((e->v + e->dv) << 16) | (e->u + e->du);
    push((char *)D_08A62C40, &c, *(u8 *)(arg0 + 0x534));
}
