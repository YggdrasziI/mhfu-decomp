/* unit_0882CC9C: 0x0882CC9C-0x0882CF58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Draws sprite idx of the table D_089391A8 as a four-vertex strip with the
 * screen positions and depths of quad and a 5:5:5:1 vertex colour from
 * (r, g, b); twelve vertex words and eight display-list commands copied to
 * the display list of D_08A62C40.
 * NonMatching (97.46 %): the scheduler places the w[2] store, the w[6]/w[9]
 * stores and the pt[1].x/pt[2].x loads differently; statement order searched.
 * submit is the helper of func_0882B624 with the address words at w[15]/w[16].
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

typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ u16 z;
} Point;

/* Vertex words then commands, with their counts. */
typedef struct {
    /* 0x00 */ s32 nVtx;
    /* 0x04 */ s32 nCmd;
    /* 0x08 */ u32 w[20];
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
                pkt->w[15] = (((u32) cur & 0xFF000000) >> 8) | 0x10000000;
                pkt->w[16] = ((u32) list->cur & 0xFFFFFF) | 0x01000000;
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

void func_0882CC9C(char *arg0, Point *pt, u8 r, u8 g, u8 b, s32 idx) {
    Packet pkt;
    Sprite *spr;
    u32 col;

    spr = &D_089391A8[idx];
    func_088314A0(arg0, spr->u, spr->v);
    col = ((u32)(r * 32) >> 8) | (((u32)(g * 32) >> 8) << 5) | (((u32)(b * 32) >> 8) << 10) | 0x8000;
    pkt.nVtx = 12;
    pkt.nCmd = 8;
    pkt.w[12] = 0x1E000001;
    pkt.w[13] = 0x50000001;
    pkt.w[14] = 0x12800116;
    pkt.w[17] = 0x04040004;
    pkt.w[18] = 0x10000000;
    pkt.w[19] = 0x08000000;
    pkt.w[0] = (spr->y << 16) | spr->x;
    pkt.w[1] = (pt[0].x << 16) | col;
    pkt.w[2] = pt[0].z;
    pkt.w[3] = ((spr->y + spr->h) << 16) | spr->x;
    pkt.w[6] = (spr->y << 16) | (spr->x + spr->w);
    pkt.w[9] = ((spr->y + spr->h) << 16) | (spr->x + spr->w);
    pkt.w[4] = (pt[1].x << 16) | col;
    pkt.w[7] = (pt[2].x << 16) | col;
    pkt.w[5] = pt[1].z;
    pkt.w[8] = pt[2].z;
    pkt.w[10] = (pt[3].x << 16) | col;
    pkt.w[11] = pt[3].z;
    submit(D_08A62C40, &pkt, *(u8 *)(arg0 + 0x534));
}
