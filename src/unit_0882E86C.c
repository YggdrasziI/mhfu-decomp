/* unit_0882E86C: 0x0882E86C-0x0882F4A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * NonMatching (99.66 %): only the registers of the last inlined submit differ
 * (the original keeps the list pointer in t0 and colours the loop temporaries
 * from v0; ours keeps it in v0).
 *
 * Draws a rectangle outline of colour `color` (0x00RRGGBB, packed to 5:5:5:1)
 * twice, at (x, y)-(x + w, y + h) and one pixel outside, as eight two-vertex
 * line packets pushed to the display list of D_08A62C40, after two 4-command
 * packets. The packets are pushed through the inline helper of
 * func_0885658C (no layer check in the code: layer 10 is a constant).
 * - The packets are local structures of their own types (a cast to a common
 *   type hoists the &nCmd address into the check).
 * - x2 + 1 and y2 + 1 are written again in lines 6 and 7 although x3 / y3
 *   hold them: the original recomputes them there.
 * - b.w[0] is stored twice in the original (once more before its submit).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    /* 0x0 */ u16 c;
    /* 0x2 */ u16 x;
    /* 0x4 */ u16 y;
    /* 0x6 */ u16 z;
} Vtx;

/* Four commands, two unused tail words. */
typedef struct {
    /* 0x00 */ s32 nVtx;
    /* 0x04 */ s32 nCmd;
    /* 0x08 */ u32 w[6];
} Packet4;

/* Two vertices then eight commands. */
typedef struct {
    /* 0x00 */ s32 nVtx;
    /* 0x04 */ s32 nCmd;
    /* 0x08 */ Vtx v[2];
    /* 0x18 */ u32 w[8];
} LinePacket;

typedef struct {
    /* 0x00000 */ s32 unk0;
    /* 0x00004 */ s32 index;
    char pad8[0x190];
    /* 0x00198 */ s32 buf[2][0x10000];
    /* 0x80198 */ s32 *cur;
} List;

extern List *D_08A62C40;

extern void func_088596C8(List *, s32 *, s32, s32);

static inline void submit4(List *list, Packet4 *pkt, s32 t, s32 layer) {
    s32 i;
    s32 nv;
    s32 skip;
    s32 n;
    s32 *src;
    s32 *cur;
    s32 count;

    if (layer >= 0 && layer < 0x14) {
        nv = *(s32 *) pkt;
        if ((u32) ((list->cur - list->buf[list->index]) + (pkt->nVtx + pkt->nCmd)) < 0x10000) {
            cur = list->cur;
            if (nv > 0) {
                pkt->w[t] = (((u32) cur & 0xFF000000) >> 8) | 0x10000000;
                pkt->w[t + 1] = ((u32) cur & 0xFFFFFF) | 0x01000000;
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

static inline void submitL(List *list, LinePacket *pkt, s32 t, s32 layer) {
    s32 i;
    s32 nv;
    s32 skip;
    s32 n;
    s32 *src;
    s32 *cur;
    s32 count;

    if (layer >= 0 && layer < 0x14) {
        nv = *(s32 *) pkt;
        if ((u32) ((list->cur - list->buf[list->index]) + (pkt->nVtx + pkt->nCmd)) < 0x10000) {
            cur = list->cur;
            if (nv > 0) {
                pkt->w[t] = (((u32) cur & 0xFF000000) >> 8) | 0x10000000;
                pkt->w[t + 1] = ((u32) cur & 0xFFFFFF) | 0x01000000;
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

void func_0882E86C(s32 arg0, u16 x, u16 y, u16 w, u16 h, u32 color) {
    Packet4 a;
    Packet4 b;
    LinePacket l;
    u16 col;
    s32 x2;
    s32 y2;
    s32 xm;
    s32 ym;
    s32 x3;
    s32 y3;

    a.nCmd = 4;
    b.nCmd = 4;
    l.nVtx = 4;
    a.w[2] = 0x10000000;
    b.w[2] = 0x10000000;
    l.w[6] = 0x10000000;
    a.w[3] = 0x08000000;
    b.w[3] = 0x08000000;
    l.w[7] = 0x08000000;
    a.w[0] = 0x21000001;
    a.w[1] = 0xDF000000;
    b.w[0] = 0x23000000;
    b.w[1] = 0xDE000000;
    l.nCmd = 8;
    l.w[0] = 0x1E000000;
    l.w[1] = 0x50000001;
    l.w[2] = 0x12800114;
    l.w[5] = 0x04010002;
    a.nVtx = 0;
    b.nVtx = 0;
    submit4(D_08A62C40, &a, 4, 10);
    b.w[0] = 0x23000000;
    submit4(D_08A62C40, &b, 4, 10);
    col = ((u32)(((color >> 16) & 0xFF) * 32) >> 8) | (((u32)(((color >> 8) & 0xFF) * 32) >> 8) << 5)
        | (((u32)((color & 0xFF) * 32) >> 8) << 10) | 0x8000;
    x2 = x + w;
    l.v[0].c = col;
    l.v[1].c = col;
    l.v[0].x = x;
    l.v[0].y = y;
    l.v[0].z = 0;
    l.v[1].x = x2;
    l.v[1].y = y;
    l.v[1].z = 0;
    submitL(D_08A62C40, &l, 3, 10);
    y2 = y + h;
    l.v[0].x = x2;
    l.v[0].y = y;
    l.v[1].x = x2;
    l.v[1].y = y2;
    submitL(D_08A62C40, &l, 3, 10);
    l.v[0].x = x2;
    l.v[0].y = y2;
    l.v[1].x = x;
    l.v[1].y = y2;
    submitL(D_08A62C40, &l, 3, 10);
    l.v[0].x = x;
    l.v[0].y = y2;
    l.v[1].x = x;
    l.v[1].y = y;
    submitL(D_08A62C40, &l, 3, 10);
    xm = x - 1;
    ym = y - 1;
    x3 = x2 + 1;
    l.v[0].x = xm;
    l.v[0].y = ym;
    l.v[1].x = x3;
    l.v[1].y = ym;
    submitL(D_08A62C40, &l, 3, 10);
    l.v[0].x = x2 + 1;
    l.v[1].x = x2 + 1;
    y3 = y2 + 1;
    l.v[0].y = ym;
    l.v[1].y = y3;
    submitL(D_08A62C40, &l, 3, 10);
    l.v[0].y = y2 + 1;
    l.v[1].y = y2 + 1;
    l.v[0].x = x3;
    l.v[1].x = xm;
    submitL(D_08A62C40, &l, 3, 10);
    l.v[0].x = xm;
    l.v[0].y = y3;
    l.v[1].x = xm;
    l.v[1].y = ym;
    submitL(D_08A62C40, &l, 3, 10);
}
