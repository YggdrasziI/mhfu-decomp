/* unit_0882B624: 0x0882B624-0x0882B94C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws sprite idx of the table D_089391A8 at (x, y) with a 5:5:5:1 vertex
 * colour from (r, g, b), mirrored in u (flip 1 or 3) and in v (flip 2 or
 * 3): two vertices and nine display-list commands copied to the display
 * list of D_08A62C40.
 * - The colour is computed after the coordinates; the vertex fields are
 *   masked again at the stores (`& 0xFFFF`), except the parameter x.
 * - Declaration order u0, v0, u1, v1 sets the t1/t2 registers.
 * submit is the helper matched in func_088F4210 (unit_088F4210.c).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    /* 0x0 */ u16 x;
    /* 0x2 */ u16 y;
    /* 0x4 */ s16 w;
    /* 0x6 */ s16 h;
    /* 0x8 */ u16 u;
    /* 0xA */ u16 v;
} Sprite;

/* Vertex words then commands, with their counts. */
typedef struct {
    /* 0x00 */ s32 nVtx;
    /* 0x04 */ s32 nCmd;
    /* 0x08 */ u32 w[15];
} Packet;

typedef struct {
    /* 0x00000 */ s32 unk0;
    /* 0x00004 */ s32 index;
    char pad8[0x190];
    /* 0x00198 */ s32 buf[2][0x10000];
    /* 0x80198 */ s32 *cur;
} List;

extern Sprite D_089391A8[];
extern List *D_08A62C40;

extern void func_088314A0(char *, s32, s32);
extern void func_088596C8(List *, s32 *, s32, s32);

static inline void submit(List *list, Packet *pkt, s32 layer) {
    s32 i;
    s32 nv;
    s32 skip;
    s32 n;
    s32 *src;
    s32 *cur;
    s32 count;

    if (layer >= 0 && layer < 0x14) {
        nv = *(s32 *) pkt;
        cur = list->cur;
        if ((u32) ((cur - list->buf[list->index]) + (pkt->nVtx + pkt->nCmd)) < 0x10000) {
            if (nv > 0) {
                pkt->w[10] = (((u32) cur & 0xFF000000) >> 8) | 0x10000000;
                pkt->w[11] = ((u32) list->cur & 0xFFFFFF) | 0x01000000;
            }
            src = &pkt->nCmd;
            count = *src++;
            skip = src[-2];
            n = pkt->nVtx + count;
            i = 0;
            if (n > 0) {
                do {
                    *list->cur = *src;
                    list->cur++;
                    i++;
                    src++;
                } while (i < n);
            }
            func_088596C8(list, cur + skip, count, layer);
        }
    }
}

void func_0882B624(char *arg0, u16 x, u16 y, u8 r, u8 g, u8 b, s32 idx, s32 flip) {
    Packet pkt;
    Sprite *spr;
    u16 col;
    u16 u0;
    u16 v0;
    u16 u1;
    u16 v1;
    u16 x2;
    u16 y2;

    spr = &D_089391A8[idx];
    func_088314A0(arg0, spr->u, spr->v);
    u0 = spr->x;
    x2 = x + spr->w;
    u1 = u0 + spr->w;
    v0 = spr->y;
    y2 = y + spr->h;
    v1 = v0 + spr->h;
    col = ((u32)(r * 32) >> 8) | (((u32)(g * 32) >> 8) << 5) | (((u32)(b * 32) >> 8) << 10) | 0x8000;
    if (flip == 3 || flip == 1) {
        u0 ^= u1;
        u1 ^= u0;
        u0 ^= u1;
    }
    if (flip == 2 || flip == 3) {
        v0 ^= v1;
        v1 ^= v0;
        v0 ^= v1;
    }
    pkt.w[0] = ((v0 & 0xFFFF) << 16) | (u0 & 0xFFFF);
    pkt.w[1] = (x << 16) | (col & 0xFFFF);
    pkt.w[2] = y & 0xFFFF;
    pkt.w[3] = ((v1 & 0xFFFF) << 16) | (u1 & 0xFFFF);
    pkt.w[4] = ((x2 & 0xFFFF) << 16) | (col & 0xFFFF);
    pkt.w[5] = y2 & 0xFFFF;
    pkt.nVtx = 6;
    pkt.nCmd = 9;
    pkt.w[6] = 0x1E000001;
    pkt.w[8] = 0x50000001;
    pkt.w[9] = 0x12800116;
    pkt.w[12] = 0x04060002;
    pkt.w[13] = 0x10000000;
    pkt.w[14] = 0x08000000;
    pkt.w[7] = 0xC9000100;
    submit(D_08A62C40, &pkt, *(u8 *)(arg0 + 0x534));
}
