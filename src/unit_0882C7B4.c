/* unit_0882C7B4: 0x0882C7B4-0x0882CC9C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws sprite idx of D_089391A8 into the rectangle (x, y)-(x + w, y + h)
 * with the colour r, g, b, a (one byte each), mirrored according to mode
 * (0..5; other values leave the four coordinate words unset): two vertices
 * and nine display-list commands copied to the display list of D_08A62C40.
 * submitC is the helper matched in func_08825148 (unit_08825148.c).
 */

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
    /* 0x00 */ s32 nVtx;
    /* 0x04 */ s32 nCmd;
    /* 0x08 */ u32 w[17];
} PacketC;

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

static inline void submitC(List *list, PacketC *pkt, s32 layer) {
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
                pkt->w[12] = (((u32) cur & 0xFF000000) >> 8) | 0x10000000;
                pkt->w[13] = ((u32) list->cur & 0xFFFFFF) | 0x01000000;
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

void func_0882C7B4(char *arg0, s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b, s32 a, s32 idx, s32 mode) {
    PacketC pkt;
    Sprite *spr;

    spr = &D_089391A8[idx];
    func_088314A0(arg0, spr->u, spr->v);
    pkt.nVtx = 8;
    pkt.nCmd = 9;
    pkt.w[8] = 0x1E000001;
    pkt.w[10] = 0x50000001;
    pkt.w[11] = 0x1280011E;
    pkt.w[14] = 0x04060002;
    pkt.w[15] = 0x10000000;
    pkt.w[16] = 0x08000000;
    pkt.w[9] = 0xC9000100;
    pkt.w[3] = 0;
    pkt.w[7] = 0;
    pkt.w[1] = (r & 0xFF) | ((g & 0xFF) << 8) | ((b & 0xFF) << 16) | ((a & 0xFF) << 24);
    pkt.w[5] = (r & 0xFF) | ((g & 0xFF) << 8) | ((b & 0xFF) << 16) | ((a & 0xFF) << 24);
    switch (mode & 0xFF) {
    case 0:
        pkt.w[2] = ((y & 0xFFFF) << 16) | (x & 0xFFFF);
        pkt.w[6] = (((y & 0xFFFF) + (s16)h) << 16) | (((x & 0xFFFF) + (s16)w) & 0xFFFF);
        pkt.w[0] = (spr->y << 16) | spr->x;
        pkt.w[4] = ((spr->y + spr->h) << 16) | (spr->x + spr->w);
        break;
    case 1:
        pkt.w[2] = ((y & 0xFFFF) << 16) | (x & 0xFFFF);
        pkt.w[6] = (((y & 0xFFFF) + (s16)h) << 16) | (((x & 0xFFFF) + (s16)w) & 0xFFFF);
        pkt.w[0] = (spr->y << 16) | (spr->x + spr->w);
        pkt.w[4] = ((spr->y + spr->h) << 16) | spr->x;
        break;
    case 2:
        pkt.w[2] = (((y & 0xFFFF) + (s16)h) << 16) | (x & 0xFFFF);
        pkt.w[6] = ((y & 0xFFFF) << 16) | (((x & 0xFFFF) + (s16)w) & 0xFFFF);
        pkt.w[0] = (spr->y << 16) | spr->x;
        pkt.w[4] = ((spr->y + spr->h) << 16) | (spr->x + spr->w);
        break;
    case 3:
        pkt.w[2] = (((y & 0xFFFF) + (s16)h) << 16) | (x & 0xFFFF);
        pkt.w[6] = ((y & 0xFFFF) << 16) | (((x & 0xFFFF) + (s16)w) & 0xFFFF);
        pkt.w[0] = (spr->y << 16) | (spr->x + spr->w);
        pkt.w[4] = ((spr->y + spr->h) << 16) | spr->x;
        break;
    case 4:
        pkt.w[2] = ((y & 0xFFFF) << 16) | (x & 0xFFFF);
        pkt.w[6] = (((y & 0xFFFF) + (s16)h) << 16) | (((x & 0xFFFF) + (s16)w) & 0xFFFF);
        pkt.w[0] = ((spr->y + spr->h) << 16) | spr->x;
        pkt.w[4] = (spr->y << 16) | (spr->x + spr->w);
        break;
    case 5:
        pkt.w[2] = ((y & 0xFFFF) << 16) | (x & 0xFFFF);
        pkt.w[6] = (((y & 0xFFFF) + (s16)h) << 16) | (((x & 0xFFFF) + (s16)w) & 0xFFFF);
        pkt.w[0] = ((spr->y + spr->h) << 16) | (spr->x + spr->w);
        pkt.w[4] = (spr->y << 16) | spr->x;
        break;
    }
    submitC(D_08A62C40, &pkt, *(u8 *)(arg0 + 0x534));
}
