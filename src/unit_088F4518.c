/* unit_088F4518: 0x088F4518-0x088F4A7C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws the sprite of D_08939F58 as three stacked bands, arg3 lines taller
 * than the sprite: its top half, arg3 lines taken below the middle, then the
 * bottom half moved down by arg3. Each band is two vertices and nine
 * display-list commands, copied to the display list of D_08A62C40.
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

extern Sprite D_08939F58;
extern char *D_089CBBEC;
extern List *D_08A62C40;

extern void func_088314A0(char *, u16, u16);
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

void func_088F4518(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Packet pkt;
    /* x, y, w, h, u, v read as words through a cast: a Sprite pointer, or an
     * s16 array, folds the address into each load of the first block. */
    s16 *spr = (s16 *) &D_08939F58;
    s16 half;

    func_088314A0(D_089CBBEC, (u16) spr[4], (u16) spr[5]);
    pkt.nVtx = 6;
    pkt.nCmd = 9;
    pkt.w[6] = 0x1E000001;
    pkt.w[8] = 0x50000001;
    pkt.w[9] = 0x12800116;
    pkt.w[12] = 0x04060002;
    pkt.w[13] = 0x10000000;
    pkt.w[14] = 0x08000000;
    pkt.w[7] = 0xC9000100;
    half = spr[3] / 2;

    pkt.w[0] = (spr[1] << 16) | spr[0];
    pkt.w[1] = (arg1 << 16) | 0xFFFF;
    pkt.w[2] = arg2 & 0xFFFF;
    pkt.w[3] = ((spr[1] + half) << 16) | (spr[0] + spr[2]);
    pkt.w[4] = ((arg1 + spr[2]) << 16) | 0xFFFF;
    pkt.w[5] = (arg2 + half) & 0xFFFF;
    submit(D_08A62C40, &pkt, *(u8 *)(D_089CBBEC + 0x534));

    pkt.w[0] = spr[0] | ((spr[1] + half) << 16);
    pkt.w[1] = (arg1 << 16) | 0xFFFF;
    pkt.w[2] = (arg2 + half) & 0xFFFF;
    pkt.w[3] = ((spr[1] + (half + arg3)) << 16) | (spr[0] + spr[2]);
    pkt.w[4] = ((arg1 + spr[2]) << 16) | 0xFFFF;
    pkt.w[5] = (arg2 + (half + arg3)) & 0xFFFF;
    submit(D_08A62C40, &pkt, *(u8 *)(D_089CBBEC + 0x534));

    pkt.w[0] = spr[0] | ((spr[1] + half) << 16);
    pkt.w[1] = (arg1 << 16) | 0xFFFF;
    pkt.w[2] = (arg2 + (half + arg3)) & 0xFFFF;
    pkt.w[3] = ((spr[1] + spr[3]) << 16) | (spr[0] + spr[2]);
    pkt.w[4] = ((arg1 + spr[2]) << 16) | 0xFFFF;
    pkt.w[5] = (arg2 + (spr[3] + arg3)) & 0xFFFF;
    submit(D_08A62C40, &pkt, *(u8 *)(D_089CBBEC + 0x534));
}
