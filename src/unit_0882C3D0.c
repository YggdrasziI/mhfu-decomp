/* unit_0882C3D0: 0x0882C3D0-0x0882C7B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws part of sprite idx of the table D_089391A8 into the rectangle
 * (x, y, w, h) with a 5:5:5:1 vertex colour from (r, g, b); mode 0..3
 * selects the texture u range (right half, left half, right quarter, left
 * quarter); other modes leave the texture words unset. Two vertices and
 * nine display-list commands are copied to the display list of D_08A62C40.
 * - The colour expression is written at each use, no local: with a local
 *   the `or` operands of the second vertex word are swapped.
 * - Store order w[1], w[2], w[4], w[5] sets the registers.
 * submit is the helper matched in func_088F4210 (unit_088F4210.c).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
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


void func_0882C3D0(char *arg0, u16 x, u16 y, u16 w, u16 h, u8 r, u8 g, u8 b, s32 mode, s32 idx) {
    Packet pkt;
    Sprite *spr;

    spr = &D_089391A8[idx];
    func_088314A0(arg0, spr->u, spr->v);
    pkt.nVtx = 6;
    pkt.nCmd = 9;
    pkt.w[6] = 0x1E000001;
    pkt.w[8] = 0x50000001;
    pkt.w[9] = 0x12800116;
    pkt.w[12] = 0x04060002;
    pkt.w[13] = 0x10000000;
    pkt.w[14] = 0x08000000;
    pkt.w[7] = 0xC9000100;
    switch (mode) {
    case 0:
        pkt.w[0] = (spr->y << 16) | (spr->x + spr->w / 2);
        pkt.w[3] = ((spr->y + spr->h) << 16) | (spr->x + spr->w);
        break;
    case 1:
        pkt.w[0] = (spr->y << 16) | spr->x;
        pkt.w[3] = ((spr->y + spr->h) << 16) | (spr->x + spr->w / 2);
        break;
    case 2:
        pkt.w[0] = (spr->y << 16) | (spr->x + spr->w - spr->w / 4);
        pkt.w[3] = ((spr->y + spr->h) << 16) | (spr->x + spr->w);
        break;
    case 3:
        pkt.w[0] = (spr->y << 16) | spr->x;
        pkt.w[3] = ((spr->y + spr->h) << 16) | (spr->x + spr->w / 4);
        break;
    }
    pkt.w[1] = (x << 16) | (((u32)(r * 32) >> 8) | (((u32)(g * 32) >> 8) << 5) | (((u32)(b * 32) >> 8) << 10) | 0x8000);
    pkt.w[2] = y;
    pkt.w[4] = ((x + w) << 16) | (((u32)(r * 32) >> 8) | (((u32)(g * 32) >> 8) << 5) | (((u32)(b * 32) >> 8) << 10) | 0x8000);
    pkt.w[5] = (y + h) & 0xFFFF;
    submit(D_08A62C40, &pkt, *(u8 *)(arg0 + 0x534));
}
