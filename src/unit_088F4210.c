/* unit_088F4210: 0x088F4210-0x088F4518 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws the sprite of D_089B8410 shrunk around its centre by the square root
 * of arg3 / 99: two vertices and nine display-list commands, copied to the
 * display list of D_08A62C40.
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

/* A Sprite */
extern s16 D_089B8410;
extern s16 D_089B8412;
extern s16 D_089B8414;
extern s16 D_089B8416;
extern u16 D_089B8418;
extern u16 D_089B841A;
extern char *D_089CBBEC;
extern List *D_08A62C40;

extern void func_088314A0(char *, s32, s32);
extern void func_088596C8(List *, s32 *, s32, s32);

static inline float sqrt_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vsqrt.s S000, S000
        sv.s S000, 0(pr)
    }
    return r;
}

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

/* - func_088314A0 is declared with s32 parameters: with u16 ones the two
 *   loads of u and v come before the store of h, in other registers.
 * - The width is an s32 local read back as (s16) w: the original extends it
 *   (`seh t1, a3`) after the first division.
 * submit is the helper matched in func_088F4518 (unit_088F4518.c). */
void func_088F4210(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Sprite spr;
    Packet pkt;
    float scale;
    s32 w;
    s16 h;
    s32 dy;
    s32 dx;
    s32 hy;
    s32 hx;

    spr.x = D_089B8410;
    spr.y = D_089B8412;
    spr.w = D_089B8414;
    spr.h = D_089B8416;
    spr.u = D_089B8418;
    spr.v = D_089B841A;
    func_088314A0(D_089CBBEC, spr.u, spr.v);
    pkt.nVtx = 6;
    pkt.nCmd = 9;
    pkt.w[6] = 0x1E000001;
    pkt.w[8] = 0x50000001;
    pkt.w[9] = 0x12800116;
    pkt.w[12] = 0x04060002;
    pkt.w[13] = 0x10000000;
    pkt.w[14] = 0x08000000;
    pkt.w[7] = 0xC9000100;
    scale = sqrt_vfpu((float) arg3 / 99.0f);
    h = spr.h;
    w = spr.w;
    dy = (s32) (h * scale);
    dx = (s32) (w * scale);
    dy = h - dy;
    hy = dy / 2;
    dx = (s16) w - dx;
    hx = dx / 2;
    pkt.w[0] = (spr.y << 16) | spr.x;
    pkt.w[1] = ((arg1 + hx) << 16) | 0xFFFF;
    pkt.w[2] = (arg2 + hy) & 0xFFFF;
    pkt.w[3] = ((spr.y + h) << 16) | (spr.x + (s16) w);
    pkt.w[4] = ((arg1 + (s16) w - hx) << 16) | 0xFFFF;
    pkt.w[5] = (arg2 + h - hy) & 0xFFFF;
    submit(D_08A62C40, &pkt, *(u8 *)(D_089CBBEC + 0x534));
}
