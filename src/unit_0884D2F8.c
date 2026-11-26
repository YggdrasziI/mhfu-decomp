/* unit_0884D2F8: 0x0884D2F8-0x0884D754 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Fades the alpha of a colour rectangle (states 1 and 2, timer against
 * duration), then draws it to the display list of D_08A62C40 (same packet
 * and inline submit as func_0885658C).
 * - The timer ratio is built as `t = ++timer; t /= duration;`, the byte
 *   difference is assigned to a u8 local between the two, and the product
 *   is cast `(float)(d * t)`: this sets the load order, the registers and
 *   the operand order of the mul.s.
 * - func_088596C8's last parameter is u32: the layer is loaded before the
 *   list pointer.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    char pad0[0x1C];
    /* 0x1C */ s32 state;
    /* 0x20 */ s32 layer;
    /* 0x24 */ s16 duration;
    /* 0x26 */ s16 timer;
    char pad28;
    /* 0x29 */ u8 a0;
    /* 0x2A */ u8 a1;
    char pad2B;
    /* 0x2C */ u8 r;
    /* 0x2D */ u8 g;
    /* 0x2E */ u8 b;
    /* 0x2F */ u8 a;
} Fade;

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

extern u32 *func_088597FC(List *);
extern void func_088596C8(List *, s32 *, s32, u32);
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


void func_0884D2F8(Fade *e) {
    Packet pkt;
    u32 *p;
    u32 c;
    float t;
    u8 d;

    switch (e->state) {
    case 0:
        return;
    case 1:
        t = ++e->timer;
        d = e->a1 - e->a0;
        t /= e->duration;
        e->a = e->a1 - (float)(d * t);
        break;
    case 2:
        t = ++e->timer;
        d = e->a0 - e->a1;
        t /= e->duration;
        e->a = e->a1 + (float)(d * t);
        break;
    case 3:
        break;
    }
    if (e->timer >= e->duration) {
        if (e->a == 0) {
            e->state = 0;
            return;
        }
        e->state = 3;
    }
    p = func_088597FC(D_08A62C40);
    p[0] = 0x23000000;
    p[1] = 0xDE000000;
    p[2] = 0x21000001;
    p[3] = 0xDF000032;
    p[4] = 0x22000000;
    p[5] = 0xDBFF0003;
    p[6] = 0x10000000;
    p[7] = 0x08000000;
    func_088596C8(D_08A62C40, (s32 *) p, 8, e->layer);
    func_0885980C(D_08A62C40, p + 8);
    pkt.nVtx = 6;
    pkt.nCmd = 8;
    pkt.w[6] = 0x1E000000;
    pkt.w[7] = 0x50000001;
    pkt.w[8] = 0x1280011C;
    pkt.w[11] = 0x04060002;
    pkt.w[12] = 0x10000000;
    pkt.w[13] = 0x08000000;
    c = (e->a << 24) | ((e->b << 16) | (e->r | (e->g << 8)));
    pkt.w[0] = c;
    pkt.w[3] = c;
    pkt.w[4] = 0x011001E0;
    pkt.w[1] = 0;
    pkt.w[2] = 0;
    pkt.w[5] = 0;
    submit(D_08A62C40, &pkt, e->layer);
}
