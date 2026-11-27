/* unit_0882DAC0: 0x0882DAC0-0x0882DCA0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws a line from (x0, y0) to (x1, y1) with a 5:5:5:1 vertex colour from
 * (r, g, b): two vertices and eight display-list commands copied to the
 * display list of D_08A62C40 (same submit helper as func_0882B624).
 * - col is an s32 local (a u16 one is masked again at its uses).
 * - The order of the packet stores was found by search; it sets both the
 *   register allocation (count 4 in a1, colour in t1) and the scheduling.
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

static inline u16 rgb(u8 r, u8 g, u8 b) {
    return ((u32)((u8)r * 32) >> 8) | (((u32)((u8)g * 32) >> 8) << 5) | (((u32)((u8)b * 32) >> 8) << 10) | 0x8000;
}

void func_0882DAC0(char *arg0, u16 x0, u16 y0, u16 x1, u16 y1, u8 r, u8 g, u8 b) {
    Packet pkt;
    s32 col;

    pkt.nCmd = 8;
    pkt.nVtx = 4;
    pkt.w[4] = 0x1E000000;
    pkt.w[5] = 0x50000001;
    col = ((u32)(r * 32) >> 8) | (((u32)(g * 32) >> 8) << 5) | (((u32)(b * 32) >> 8) << 10) | 0x8000;
    pkt.w[0] = (x0 << 16) | col;
    pkt.w[6] = 0x12800114;
    pkt.w[9] = 0x04010002;
    pkt.w[1] = y0;
    pkt.w[10] = 0x10000000;
    pkt.w[3] = y1;
    pkt.w[11] = 0x08000000;
    pkt.w[2] = (x1 << 16) | col;
    submit(D_08A62C40, &pkt, *(u8 *)(arg0 + 0x534));
}
