/* unit_0882D8DC: 0x0882D8DC-0x0882DAC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws a flat rectangle at (x, y) of size (w, h) with the colour
 * (r, g, b, a): two vertices and eight display-list commands copied to the
 * display list of D_08A62C40.
 * - The colour is assigned inside the first vertex store (`w[0] = col =
 *   ...`); as its own statement it is scheduled before the commands.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

/* Two vertices then eight commands. */
typedef struct {
    /* 0x00 */ s32 nVtx;
    /* 0x04 */ s32 nCmd;
    /* 0x08 */ u32 w[14];
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
                pkt->w[9] = (((u32) cur & 0xFF000000) >> 8) | 0x10000000;
                pkt->w[10] = ((u32) list->cur & 0xFFFFFF) | 0x01000000;
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

void func_0882D8DC(char *arg0, u16 x, u16 y, u16 w, u16 h, u8 r, u8 g, u8 b, u8 a) {
    Packet pkt;
    u32 col;

    pkt.nVtx = 6;
    pkt.nCmd = 8;
    pkt.w[6] = 0x1E000000;
    pkt.w[7] = 0x50000001;
    pkt.w[8] = 0x1280011C;
    pkt.w[11] = 0x04060002;
    pkt.w[12] = 0x10000000;
    pkt.w[13] = 0x08000000;
    pkt.w[0] = col = r | (g << 8) | (b << 16) | (a << 24);
    pkt.w[1] = (y << 16) | x;
    pkt.w[2] = 0;
    pkt.w[3] = col;
    pkt.w[4] = ((y + h) << 16) | ((x + w) & 0xFFFF);
    pkt.w[5] = 0;
    submit(D_08A62C40, &pkt, *(u8 *)(arg0 + 0x534));
}
