/* unit_0882B94C: 0x0882B94C-0x0882BBE8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws sprite arg7 of D_089391A8 at (arg1, arg2) with the colour
 * arg3..arg6 (one byte each): two vertices and nine display-list commands
 * copied to the display list of D_08A62C40. Same as func_0882B1CC without
 * its second quad.
 *
 * - The colour expression is written at each of its two uses.
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

void func_0882B94C(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    PacketC pkt;
    Sprite *spr;

    spr = &D_089391A8[arg7];
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
    pkt.w[0] = (spr->y << 16) | spr->x;
    pkt.w[1] = (arg3 & 0xFF) | ((arg4 & 0xFF) << 8) | ((arg5 & 0xFF) << 16) | ((arg6 & 0xFF) << 24);
    pkt.w[2] = ((arg2 & 0xFFFF) << 16) | (arg1 & 0xFFFF);
    pkt.w[3] = 0;
    pkt.w[4] = ((spr->y + spr->h) << 16) | (spr->x + spr->w);
    pkt.w[5] = (arg3 & 0xFF) | ((arg4 & 0xFF) << 8) | ((arg5 & 0xFF) << 16) | ((arg6 & 0xFF) << 24);
    pkt.w[6] = (((arg2 & 0xFFFF) + spr->h) << 16) | (((arg1 & 0xFFFF) + spr->w) & 0xFFFF);
    pkt.w[7] = 0;
    submitC(D_08A62C40, &pkt, *(u8 *)(arg0 + 0x534));
}
