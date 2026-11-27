/* unit_088B8A58: 0x088B8A58-0x088B96D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
#pragma opt_unroll_loops off

/* func_088B8A58 (ULES01213), piece text_088B8A58, size 0xC80.
 *
 * Builds GE display-list packets on the stack (four packet layouts: two
 * 4-command packets, a 12-command texture packet from func_08859848, and a
 * 6-vertex sprite packet drawn once and then once per entry of the s16 list
 * D_089B2AD4[x] up to -1, -2 skipping a slot) and copies them to the list of
 * D_08A62C40 through an inline submit (same body as func_0882A9DC's, the
 * layer is a constant so its range test folds away). Then optional text
 * calls behind flags 1 and 2 at arg0 + 0x29308.
 * - Speed setting with loop unrolling off: the copy loops stay rolled, the
 *   `y << 16` of the list loop is strength reduced and only the copy loop
 *   nested in it gets its `list + 0x80198` address hoisted.
 * - The list loop is a plain `while` (a guarded do/while loses the hoist).
 * - The colour comes from a u16 inline helper (the double `andi 0xFFFF`).
 * - D_089B2B30 / D_089B2B32 are one {u16, u16} pair copied whole: the copy
 *   keeps it on the stack (member copies are promoted to registers); the
 *   second load is relocated against D_089B2B30+2 (name-only difference).
 * - Statement and declaration orders were searched (store scheduling and
 *   saved registers depend on them).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { u16 x; u16 y; } Pt;

typedef struct {
    u32 unk0;
    u32 unk4;
    u16 unk8;
    u16 unkA;
    u32 unkC;
    u32 unk10;
    u32 unk14;
} Tex;

typedef struct {
    /* 0x00000 */ s32 unk0;
    /* 0x00004 */ s32 index;
    char pad8[0x190];
    /* 0x00198 */ s32 buf[2][0x10000];
    /* 0x80198 */ s32 *cur;
} List;

/* Four commands, jump words at w[4], w[5]. */
typedef struct {
    s32 nVtx;
    s32 nCmd;
    u32 w[6];
} PktA;

/* Six vertex words, nine commands, jump words at w[10], w[11]. */
typedef struct {
    s32 nVtx;
    s32 nCmd;
    u32 w[15];
} PktC;

/* Twelve commands, jump words at w[12], w[13]. */
typedef struct {
    s32 nVtx;
    s32 nCmd;
    u32 w[14];
} PktD;

extern List *D_08A62C40;
extern s32 D_09A0B540;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern char *D_089CBBEC;
extern s16 *D_089B2AD4[];
extern s16 D_089B2AF0[];
extern f32 D_089B2B00[];
extern s16 D_089B2B30;

extern s32 func_08898898(s32, s32);
extern int func_08859848(List *, s32, s32, s32, s32, Tex *);
extern s32 func_0885981C(List *, u32);
extern void func_088596C8(List *, s32 *, s32, s32);
extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern void func_08832B98(char *, s32);
extern void func_08842F70(char *, u16, u16, f32, s32);
extern s32 func_08890E48(char *, char *);
extern void func_08890DE8(char *, s8, u8);
extern void func_0889198C(char *, s32, s32, s32, s32, char *, s32, s32);

#define SUBMIT_BODY(J)                                                         \
    s32 i;                                                                     \
    s32 nv;                                                                    \
    s32 skip;                                                                  \
    s32 n;                                                                     \
    s32 *src;                                                                  \
    s32 *cur;                                                                  \
    s32 count;                                                                 \
                                                                               \
    nv = *(s32 *) pkt;                                                         \
    if ((u32) ((list->cur - list->buf[list->index]) +                          \
               (pkt->nVtx + pkt->nCmd)) < 0x10000) {                           \
        cur = list->cur;                                                       \
        if (nv > 0) {                                                          \
            pkt->w[J] = (((u32) cur & 0xFF000000) >> 8) | 0x10000000;          \
            pkt->w[J + 1] = ((u32) cur & 0xFFFFFF) | 0x01000000;               \
        }                                                                      \
        src = &pkt->nCmd;                                                      \
        count = *src++;                                                        \
        skip = src[-2];                                                        \
        n = pkt->nVtx + count;                                                 \
        i = 0;                                                                 \
        if (n > 0) {                                                           \
            do {                                                               \
                *list->cur = *src;                                             \
                list->cur++;                                                   \
                i++;                                                           \
                src++;                                                         \
            } while (i < n);                                                   \
        }                                                                      \
        func_088596C8(list, cur + skip, count, layer);                         \
    }

static inline void submitA(List *list, PktA *pkt, s32 layer) { SUBMIT_BODY(4) }
static inline void submitC(List *list, PktC *pkt, s32 layer) { SUBMIT_BODY(10) }
static inline void submitD(List *list, PktD *pkt, s32 layer) { SUBMIT_BODY(12) }

static inline u16 getcol(s32 fl) {
    u16 c;

    c = 0xFFFF;
    if ((s32)((fl & 1) != 0) != 0 || (s32)((fl & 2) != 0) != 0) {
        c = 0xBDEF;
    }
    return c;
}

void func_088B8A58(char *arg0) {
    PktD d;
    PktC c;
    Tex tex;
    PktA b;
    PktA a;
    Pt pos;
    u32 hi;
    u32 tw;
    s32 fl;
    s32 k;
    s32 n;
    s16 y;
    s16 *p;
    s32 x;
    u16 col;
    s16 v;
    char *s;

    if (*(u8 *)(arg0 + 0x2930C) == 0) {
        return;
    }
    d.nVtx = 0;
    d.nCmd = 0xC;
    d.w[9] = 0xCB000000;
    d.w[10] = 0x10000000;
    d.w[11] = 0x08000000;
    c.nVtx = 6;
    c.nCmd = 9;
    c.w[6] = 0x1E000001;
    c.w[8] = 0x50000001;
    c.w[9] = 0x12800116;
    c.w[12] = 0x04060002;
    c.w[7] = 0xC9000100;
    c.w[13] = 0x10000000;
    c.w[14] = 0x08000000;
    b.nVtx = 0;
    b.nCmd = 4;
    b.w[0] = 0x23000000;
    b.w[1] = 0xDE000000;
    b.w[2] = 0x10000000;
    b.w[3] = 0x08000000;
    a.nVtx = 0;
    a.nCmd = 4;
    a.w[0] = 0x21000001;
    a.w[1] = 0xDF000032;
    a.w[2] = 0x10000000;
    a.w[3] = 0x08000000;
    submitA(D_08A62C40, &a, 2);
    b.w[0] = 0x23000000;
    b.w[1] = 0xDE000000;
    submitA(D_08A62C40, &b, 2);

    func_08859848(D_08A62C40, func_08898898(D_09A0B540, 0), 0, 0, 0, &tex);
    d.w[0] = 0xC2000001;
    d.w[1] = tex.unk4 | 0xC3000000;
    d.w[2] = (tex.unk0 & 0xFFFFFF) | 0xA0000000;
    tw = tex.unk8;
    d.w[3] = ((tex.unk0 & 0xFF000000) >> 8) | 0xA8000000 | tw;
    hi = (func_0885981C(D_08A62C40, tex.unkA) << 8) | 0xB8000000;
    d.w[4] = hi | func_0885981C(D_08A62C40, tw);
    d.w[5] = tex.unk10 | 0xC500FF00;
    d.w[6] = (tex.unkC & 0xFFFFFF) | 0xB0000000;
    d.w[7] = ((tex.unkC & 0xFF000000) >> 8) | 0xB1000000;
    d.w[8] = 0xC4000020;
    submitD(D_08A62C40, &d, 2);

    fl = *(s32 *)(arg0 + 0x29308);
    if ((s32)((fl & 4) != 0) == 0) {
        col = getcol(fl);
        c.w[0] = 0;
        c.w[1] = col;
        c.w[2] = 0;
        c.w[3] = ((tex.unkA - 0x18) << 16) | tex.unk8;
        c.w[4] = col | 0x1E00000;
        c.w[5] = 0x110;
        submitC(D_08A62C40, &c, 2);
    }

    s = D_08A631A0;
    x = *(s32 *)(s + 0xF7A574);
    if (*(s32 *)(s + 0xF7A554) & 1) {
        n = ++*(s32 *)(arg0 + 0x29310);
        if (n & 1) {
            *(s32 *)(arg0 + 0x29310) = n + 1;
        }
        if (*(s32 *)(arg0 + 0x29310) >= 0xC) {
            *(s32 *)(arg0 + 0x29310) -= 0xC;
        }
    }
    k = *(s32 *)(arg0 + 0x29310);
    p = D_089B2AD4[x];
    y = D_089B2AF0[x];
    d.w[0] = 0xC2000001;
    d.w[1] = tex.unk4 | 0xC3000000;
    d.w[2] = (tex.unk0 & 0xFFFFFF) | 0xA0000000;
    tw = tex.unk8;
    d.w[3] = ((tex.unk0 & 0xFF000000) >> 8) | 0xA8000000 | tw;
    hi = (func_0885981C(D_08A62C40, tex.unkA) << 8) | 0xB8000000;
    d.w[4] = hi | func_0885981C(D_08A62C40, tw);
    d.w[5] = tex.unk10 | 0xC500FF00;
    d.w[6] = (tex.unkC & 0xFFFFFF) | 0xB0000000;
    d.w[7] = ((tex.unkC & 0xFF000000) >> 8) | 0xB1000000;
    d.w[8] = 0xC4000020;
    submitD(D_08A62C40, &d, 9);

    while (*p != -1) {
        {
            if (*p != -2) {
                c.w[0] = *p | 0x1100000;
                c.w[1] = (y << 16) | 0xFFFF;
                v = 236.0f + 4.0f * D_089B2B00[k];
                c.w[3] = (*p + 0x18) | 0x1280000;
                c.w[4] = ((y + 0x18) << 16) | 0xFFFF;
                c.w[2] = (u16)v;
                c.w[5] = (u16)(v + 0x18);
                submitC(D_08A62C40, &c, 9);
            }
            y += 0x18;
            k++;
            if (k >= 0xC) {
                k = 0;
            }
            p++;
        }
    }

    if ((s32)((*(s32 *)(arg0 + 0x29308) & 1) != 0) != 0) {
        pos = *(Pt *)&D_089B2B30;
        s = D_089CBBEC;
        *(u8 *)(s + 0x534) = 9;
        func_08890E08(D_08A631A8, 0);
        func_08825DA8(s);
        func_08832B98(D_089CBBEC, 1);
        func_08842F70(D_089CBBEC, pos.x, pos.y, 1.5f, 1);
    }
    if ((s32)((*(s32 *)(arg0 + 0x29308) & 2) != 0) != 0) {
        x = (0x1E0 - func_08890E48(D_08A631A8, *(char **)(arg0 + 0x29314)) * 8) / 2;
        func_08890E08(D_08A631A8, 0);
        func_08890DE8(D_08A631A8, 0x10, 0x10);
        func_0889198C(D_08A631A8, (s16)x, 0x84, 1, 0, *(char **)(arg0 + 0x29314), 2, 2);
    }
}
