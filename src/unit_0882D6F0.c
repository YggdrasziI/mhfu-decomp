/* unit_0882D6F0: 0x0882D6F0-0x0882D8DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Draws an untextured rectangle at (x, y) of size (w, h) with a 5:5:5:1
 * vertex colour from (r, g, b): two vertices and eight display-list
 * commands copied to the display list of D_08A62C40.
 * - The colour expression is written at each of its two uses and the
 *   parameters are s32 masked at each use; locals change the registers.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

/* Vertex words then commands, with their counts. */
typedef struct {
    /* 0x00 */ s32 nVtx;
    /* 0x04 */ s32 nCmd;
    /* 0x08 */ u32 w[12];
} Packet;

typedef struct {
    /* 0x00000 */ s32 unk0;
    /* 0x00004 */ s32 index;
    char pad8[0x190];
    /* 0x00198 */ s32 buf[2][0x10000];
    /* 0x80198 */ s32 *cur;
} List;

extern List *D_08A62C40;

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
                pkt->w[7] = (((u32) cur & 0xFF000000) >> 8) | 0x10000000;
                pkt->w[8] = ((u32) list->cur & 0xFFFFFF) | 0x01000000;
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

void func_0882D6F0(char *arg0, s32 x, s32 y, s32 w, s32 h, s32 r, s32 g, s32 b) {
    Packet pkt;

    pkt.nVtx = 4;
    pkt.nCmd = 8;
    pkt.w[4] = 0x1E000000;
    pkt.w[5] = 0x50000001;
    pkt.w[6] = 0x12800114;
    pkt.w[9] = 0x04060002;
    pkt.w[10] = 0x10000000;
    pkt.w[11] = 0x08000000;
    pkt.w[0] = ((x & 0xFFFF) << 16) | (((u32)((r & 0xFF) * 32) >> 8) | (((u32)((g & 0xFF) * 32) >> 8) << 5) | (((u32)((b & 0xFF) * 32) >> 8) << 10) | 0x8000);
    pkt.w[1] = y & 0xFFFF;
    pkt.w[2] = (((x & 0xFFFF) + (w & 0xFFFF)) << 16) | (((u32)((r & 0xFF) * 32) >> 8) | (((u32)((g & 0xFF) * 32) >> 8) << 5) | (((u32)((b & 0xFF) * 32) >> 8) << 10) | 0x8000);
    pkt.w[3] = ((y & 0xFFFF) + (h & 0xFFFF)) & 0xFFFF;
    submit(D_08A62C40, &pkt, *(u8 *)(arg0 + 0x534));
}
