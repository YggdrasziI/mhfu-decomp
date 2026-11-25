/* unit_0884558C: 0x0884558C-0x08845A34 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws a sprite between (x, y) and (x + w, y + h) with texture coordinates
 * (u0, v0)-(u1, v1): two vertices and nine display-list commands copied to
 * the display list of D_08A62C40, with a vertex colour when alpha != 0xFF.
 * - The sprite pointer goes through (Sprite *)(s32)&D_08939874 so that its
 *   address is built once (%lo without offset) and read at 0x8 / 0xA.
 * - The u coordinates are halved with an explicit (s16) cast: the original
 *   extends them again (seh) before the sra.
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

/* Two vertices without colour then nine commands. */
typedef struct {
    /* 0x00 */ s32 nVtx;
    /* 0x04 */ s32 nCmd;
    /* 0x08 */ u32 w[15];
} Packet;

/* Two vertices with colour then nine commands. */
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

extern Sprite D_08939874;
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

void func_0884558C(char *arg0, s16 x, s16 y, s16 w, s16 h, s16 u0, s16 v0, s16 u1, s16 v1, u8 alpha) {
    PacketC pktc;
    Packet pkt;
    s16 x2;
    s16 y2;
    u8 mode;
    Sprite *spr;

    spr = (Sprite *)(s32)&D_08939874;
    func_088314A0(arg0, spr->u, spr->v);
    x2 = x + w;
    mode = *(u8 *)(arg0 + 0x578);
    y2 = y + h;
    if (mode != 0) {
        u0 = (s16)u0 >> 1;
        u1 = (s16)u1 >> 1;
        if (mode == 2) {
            u0 += 0x4B;
            u1 += 0x4B;
        }
    }
    if (alpha != 0xFF) {
        pktc.nVtx = 8;
        pktc.nCmd = 9;
        pktc.w[8] = 0x1E000001;
        pktc.w[10] = 0x50000001;
        pktc.w[11] = 0x1280011E;
        pktc.w[14] = 0x04060002;
        pktc.w[15] = 0x10000000;
        pktc.w[16] = 0x08000000;
        pktc.w[9] = 0xC9000100;
        pktc.w[0] = (v0 << 16) | u0;
        pktc.w[1] = (alpha << 24) | 0xFFFFFF;
        pktc.w[2] = (y << 16) | (x & 0xFFFF);
        pktc.w[3] = 0;
        pktc.w[4] = (v1 << 16) | u1;
        pktc.w[5] = (alpha << 24) | 0xFFFFFF;
        pktc.w[6] = (y2 << 16) | (x2 & 0xFFFF);
        pktc.w[7] = 0;
        submitC(D_08A62C40, &pktc, *(u8 *)(arg0 + 0x534));
    } else {
        pkt.nVtx = 6;
        pkt.nCmd = 9;
        pkt.w[6] = 0x1E000001;
        pkt.w[8] = 0x50000001;
        pkt.w[9] = 0x12800116;
        pkt.w[12] = 0x04060002;
        pkt.w[13] = 0x10000000;
        pkt.w[14] = 0x08000000;
        pkt.w[7] = 0xC9000100;
        pkt.w[0] = (v0 << 16) | u0;
        pkt.w[1] = (x << 16) | 0xFFFF;
        pkt.w[2] = y & 0xFFFF;
        pkt.w[3] = (v1 << 16) | u1;
        pkt.w[4] = (x2 << 16) | 0xFFFF;
        pkt.w[5] = y2 & 0xFFFF;
        submit(D_08A62C40, &pkt, *(u8 *)(arg0 + 0x534));
    }
}
