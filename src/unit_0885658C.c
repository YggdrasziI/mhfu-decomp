/* unit_0885658C: 0x0885658C-0x088567B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
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

extern s32 func_088567B4(char *);
extern u32 *func_088597FC(List *);
extern void func_088596C8(List *, s32 *, s32, s32);
extern int func_0885980C(List *, u32 *);

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
        if ((u32) ((list->cur - list->buf[list->index]) + (pkt->nVtx + pkt->nCmd)) < 0x10000) {
            cur = list->cur;
            if (nv > 0) {
                pkt->w[9] = (((u32) cur & 0xFF000000) >> 8) | 0x10000000;
                pkt->w[10] = ((u32) cur & 0xFFFFFF) | 0x01000000;
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

void func_0885658C(char *arg0) {
    Packet pkt;
    u32 *p;

    if ((func_088567B4(arg0) & 0xFF) == 1) {
        p = func_088597FC(D_08A62C40);
        p[0] = 0x23000000;
        p[1] = 0xDE000000;
        p[2] = 0x21000001;
        p[3] = 0xDF000032;
        p[4] = 0x22000000;
        p[5] = 0xDBFF0003;
        p[6] = 0x10000000;
        p[7] = 0x08000000;
        func_088596C8(D_08A62C40, (s32 *) p, 8, 9);
        func_0885980C(D_08A62C40, p + 8);
        pkt.nVtx = 6;
        pkt.nCmd = 8;
        pkt.w[6] = 0x1E000000;
        pkt.w[7] = 0x50000001;
        pkt.w[8] = 0x1280011C;
        pkt.w[11] = 0x04060002;
        pkt.w[12] = 0x10000000;
        pkt.w[13] = 0x08000000;
        pkt.w[0] = 0xA0000000;
        pkt.w[3] = 0xA0000000;
        pkt.w[4] = 0x011001E0;
        pkt.w[1] = 0;
        pkt.w[2] = 0;
        pkt.w[5] = 0;
        submit(D_08A62C40, &pkt, 9);
    }
}
