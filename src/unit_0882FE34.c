/* unit_0882FE34: 0x0882FE34-0x08830078 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Draws a textured sprite (hypothesis) at (x, y) with texture coordinates
 * (u, v), 0x24 x 0x33: two vertices and nine display-list commands copied to
 * the display list of D_08A62C40, between two func_08832B98 calls.
 * - Statement order of the packet fills sets the saved registers of the
 *   parameters (found by a hill-climb over statement moves).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

/* Two vertices then nine commands. */
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

extern List *D_08A62C40;

extern void func_088596C8(List *, s32 *, s32, s32);
extern void func_08832B98(char *, s32);
extern void func_088314A0(char *, s32, s32);

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

void func_0882FE34(char *arg0, u16 u, u16 v, u16 x, u16 y) {
    Packet pkt;

    func_08832B98(arg0, 1);
    func_088314A0(arg0, 0x8002, 0xB);
    pkt.nCmd = 9;
    pkt.w[6] = 0x1E000001;
    pkt.w[8] = 0x50000001;
    pkt.w[9] = 0x12800116;
    pkt.w[12] = 0x04060002;
    pkt.w[13] = 0x10000000;
    pkt.nVtx = 6;
    pkt.w[14] = 0x08000000;
    pkt.w[7] = 0xC9000100;
    pkt.w[0] = (y << 16) | x;
    pkt.w[2] = v;
    pkt.w[1] = (u << 16) | 0xFFFF;
    pkt.w[3] = ((y + 0x24) << 16) | (x + 0x24);
    pkt.w[5] = (u16)(v + 0x33);
    pkt.w[4] = ((u + 0x33) << 16) | 0xFFFF;
    submit(D_08A62C40, &pkt, *(u8 *)(arg0 + 0x534));
    func_08832B98(arg0, 0);
}
