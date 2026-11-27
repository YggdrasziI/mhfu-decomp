/* unit_0882CF58: 0x0882CF58-0x0882D220 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Sets up the texture of sprite idx of D_089391A8 (func_088314A0), then
 * submits a four-vertex packet (uv, colour, xy from pts[0..7]) and eight
 * display-list commands to the display list of D_08A62C40.
 * submit is the helper of unit_0882B624.c with a larger packet.
 * - nVtx must be stored before the vertex words (register of the 0x10).
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
    /* 0x08 */ u32 w[24];
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
                pkt->w[19] = (((u32) cur & 0xFF000000) >> 8) | 0x10000000;
                pkt->w[20] = ((u32) list->cur & 0xFFFFFF) | 0x01000000;
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

void func_0882CF58(char *arg0, s16 *pts, u8 r, u8 g, u8 b, u8 a, s32 idx) {
    Packet pkt;
    Sprite *spr;
    u32 col;

    spr = &D_089391A8[idx];
    func_088314A0(arg0, spr->u, spr->v);
    col = (a << 24) | ((b << 16) | (r | (g << 8)));
    pkt.w[1] = col;
    pkt.w[5] = col;
    pkt.w[9] = col;
    pkt.w[13] = col;
    pkt.nVtx = 0x10;
    pkt.nCmd = 8;
    pkt.w[16] = 0x1E000001;
    pkt.w[17] = 0x50000001;
    pkt.w[18] = 0x1280011E;
    pkt.w[21] = 0x04040004;
    pkt.w[22] = 0x10000000;
    pkt.w[23] = 0x08000000;
    pkt.w[0] = (spr->y << 16) | spr->x;
    pkt.w[2] = (pts[1] << 16) | (u16)pts[0];
    pkt.w[4] = ((spr->y + spr->h) << 16) | spr->x;
    pkt.w[6] = (pts[3] << 16) | (u16)pts[2];
    pkt.w[8] = (spr->y << 16) | (spr->x + spr->w);
    pkt.w[10] = (pts[5] << 16) | (u16)pts[4];
    pkt.w[12] = ((spr->y + spr->h) << 16) | (spr->x + spr->w);
    pkt.w[14] = (pts[7] << 16) | (u16)pts[6];
    pkt.w[3] = 0;
    pkt.w[7] = 0;
    pkt.w[11] = 0;
    pkt.w[15] = 0;
    submit(D_08A62C40, &pkt, *(u8 *)(arg0 + 0x534));
}
