/* unit_08825148: 0x08825148-0x0882545C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * NonMatching: func_08825148 99.70 %. Left: the saved registers of t (and
 * hi) and p are swapped (s1/s0); declaration orders, scopes, types and
 * inline helpers did not change the allocation.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

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

extern char *D_089CC438;
extern List *D_08A62C40;

extern void func_088596C8(List *, s32 *, s32, s32);
extern s32 *func_088597FC(List *);
extern int func_0885980C(List *, s32 *);
extern s32 func_0885981C(List *, u32);

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

void func_08825148(char *arg0) {
    PacketC pktc;
    s32 *p;
    u32 t;
    u32 hi;

    if (*(u8 *)(D_089CC438 + 0xD) != 0) {
        t = *(u32 *)(arg0 + 0x538);
        p = func_088597FC(D_08A62C40);
        p[0] = 0x22000000;
        p[1] = 0x21000001;
        p[2] = 0xE0FFFFFF;
        p[3] = 0xDF00003A;
        p[4] = 0xC6000107;
        p[5] = 0x23000000;
        p[6] = 0xC9000000;
        p[7] = 0x1E000001;
        p[8] = 0xC2000000;
        p[9] = 0xC3000001;
        p[10] = (t & 0xFFFFFF) | 0xA0000000;
        p[11] = ((t & 0xFF000000) >> 8) | 0xA8000200;
        hi = (func_0885981C(D_08A62C40, 0x110) << 8) | 0xB8000000;
        p[12] = hi | func_0885981C(D_08A62C40, 0x200);
        p[13] = 0xCB000000;
        p[14] = 0x10000000;
        p[15] = 0x08000000;
        func_088596C8(D_08A62C40, p, 0x10, *(u8 *)(arg0 + 0x534));
        func_0885980C(D_08A62C40, p + 0x10);
        pktc.nVtx = 8;
        pktc.nCmd = 9;
        pktc.w[8] = 0x1E000001;
        pktc.w[10] = 0x50000001;
        pktc.w[11] = 0x1280011E;
        pktc.w[14] = 0x04060002;
        pktc.w[15] = 0x10000000;
        pktc.w[16] = 0x08000000;
        pktc.w[9] = 0xC9000100;
        pktc.w[0] = 0x22003C;
        pktc.w[1] = 0x80FFFFFF;
        pktc.w[2] = 0;
        pktc.w[3] = 0;
        pktc.w[4] = 0xEE01A4;
        pktc.w[5] = 0x80FFFFFF;
        pktc.w[6] = 0x11001E0;
        pktc.w[7] = 0;
        submitC(D_08A62C40, &pktc, *(u8 *)(arg0 + 0x534));
    }
}
