/* unit_088314A0: 0x088314A0-0x0883185C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088314A0: builds a block of texture-setup display-list words (from a
 * texture when arg1 & 0x8000, else from a surface) in a stack buffer and
 * pushes it to the list at D_08A62C40 through an inlined helper (same copy
 * loop as func_08859480). Speed setting needed.
 * The two `volatile` reads of c->n0 keep the separate loads of the original
 * (no common subexpression with the neighbouring reads); the command words are
 * stored through raw byte offsets of the buffer, which sets the scheduling
 * order of the surface branch. */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 unk0;
    u32 unk4;
    u16 unk8;
    u16 unkA;
    u32 unkC;
    u32 unk10;
    u32 unk14;
} Tex;

typedef struct {
    s32 unk0;
    u16 unk4;
    u16 unk6;
    u32 unk8;
    u16 unkC;
    u16 unkE;
    u32 unk10;
    u16 unk14;
    u16 unk16;
} Surface;

typedef struct {
    s32 n0;
    s32 n1;
    u32 w[12];
    u32 tail[2];
} Cmd;

extern s32 D_09A0B540;
extern s32 D_08A62C40;
extern s32 D_089CBBE0;
extern s32 func_08898898(s32, s32);
extern int func_08859848(s32, s32, s32, s32, s32, Tex *);
extern s32 func_0885981C(s32, u32);
extern void func_088125A4(s32, s32, Surface *);
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

void func_088314A0(char *arg0, s32 arg1, s32 arg2) {
    Cmd c;
    Tex tex;
    Surface surf;
    u32 hi;
    u32 n;
    u32 w8;
    u32 t;

    c.n0 = 0;
    c.n1 = 12;
    *(u32 *)((char *)&c + 0x2C) = 0xCB000000;
    *(u32 *)((char *)&c + 0x30) = 0x10000000;
    *(u32 *)((char *)&c + 0x34) = 0x08000000;
    if (arg1 & 0x8000) {
        func_08859848(D_08A62C40, func_08898898(D_09A0B540, arg2), arg1 & 0xFFF, 0, 0, &tex);
        *(u32 *)((char *)&c + 0x8) = 0xC2000001;
        *(u32 *)((char *)&c + 0xC) = tex.unk4 | 0xC3000000;
        t = tex.unk0;
        *(u32 *)((char *)&c + 0x10) = (t & 0xFFFFFF) | 0xA0000000;
        w8 = tex.unk8;
        *(u32 *)((char *)&c + 0x14) = ((t & 0xFF000000) >> 8) | 0xA8000000 | w8;
        hi = (func_0885981C(D_08A62C40, tex.unkA) << 8) | 0xB8000000;
        *(u32 *)((char *)&c + 0x18) = hi | func_0885981C(D_08A62C40, w8);
        *(u32 *)((char *)&c + 0x1C) = tex.unk10 | 0xC500FF00;
        *(u32 *)((char *)&c + 0x20) = (tex.unkC & 0xFFFFFF) | 0xB0000000;
        *(u32 *)((char *)&c + 0x24) = ((tex.unkC & 0xFF000000) >> 8) | 0xB1000000;
        n = 0x100;
        if (tex.unk4 == 4) {
            n = 0x10;
        }
        *(u32 *)((char *)&c + 0x28) = ((n + 7) >> 3) | 0xC4000000;
    } else {
        func_088125A4(D_089CBBE0, arg1 & 0xFF, &surf);
        *(u32 *)((char *)&c + 0x8) = 0xC2000001;
        *(u32 *)((char *)&c + 0xC) = surf.unkC | 0xC3000000;
        *(u32 *)((char *)&c + 0x10) = (surf.unk8 & 0xFFFFFF) | 0xA0000000;
        *(u32 *)((char *)&c + 0x14) = ((surf.unk8 & 0xFF000000) >> 8) | 0xA8000000 | surf.unk4;
        hi = (func_0885981C(D_08A62C40, surf.unk6) << 8) | 0xB8000000;
        *(u32 *)((char *)&c + 0x18) = hi | func_0885981C(D_08A62C40, surf.unk4);
        *(u32 *)((char *)&c + 0x1C) = surf.unk14 | 0xC500FF00;
        *(u32 *)((char *)&c + 0x20) = (surf.unk10 & 0xFFFFFF) | 0xB0000000;
        *(u32 *)((char *)&c + 0x24) = ((surf.unk10 & 0xFF000000) >> 8) | 0xB1000000;
        n = 0x100;
        if (surf.unkC == 4) {
            n = 0x10;
        }
        *(u32 *)((char *)&c + 0x28) = ((n + 7) >> 3) | 0xC4000000;
    }
    push((char *)D_08A62C40, &c, *(u8 *)(arg0 + 0x534));
}
