/* unit_088A4CB0: 0x088A4CB0-0x088A53A4 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

extern char D_089B265C;
extern char D_089B265D;
extern char D_089B265E;
extern char D_089B265F;
extern char D_089B2664;
extern char D_089B2665;
extern char D_089B2666;
extern char D_089B2667;
extern char D_089B266C;
extern char D_089B266D;
extern char D_089B266E;
extern char D_089B266F;
extern char D_089B2674;
extern char D_089B2675;
extern char D_089B2676;
extern char D_089B2677;

typedef struct {
    s16 unk0[6];
    u16 unkC;
} E14;

typedef struct {
    u8 cnt;
    u8 unk1;
    s16 unk2[3];
} Hdr8;

typedef struct {
    Hdr8 hd;
    E14 e[1];
} H8;

typedef struct {
    s16 unk0[5];
    u16 unkA;
} E12;

typedef struct {
    s32 unk0;
    float unk4[4];
} E20;

typedef struct {
    char unk0[0x8];
    u32 count;
    char unkC[0x4];
    s32 tbl[1];
} Sub;

typedef struct {
    char unk0[0x8];
    u32 count;
    char unkC[0x4];
    E12 e[1];
} Sub12;

typedef struct {
    char unk0[0x8];
    u32 count;
    char unkC[0x4];
    E20 e[1];
} Sub20;

typedef struct {
    char unk0[0x10];
    s32 unk10;
    s32 off14;
    s32 off18;
    s32 off1C;
} Src;

typedef struct {
    u32 tag;
    u32 size;
    u32 count;
    s32 unkC;
    s32 tbl[1];
} Sec;

typedef struct {
    u32 tag;
    u32 size;
    u32 count;
    u32 total;
    s32 sum;
    u32 off1;
    u32 off2;
    u32 off3;
} Out;

s32 func_088A4CB0(Out *out, Src **srcs, u32 n) {
    u16 base2;
    Sec *sec2;
    u32 i;
    E20 *d20;
    Src *src2;
    Sub12 *s12;
    H8 *h;
    Sub *sub2;
    u32 max;
    Sub *sub22;
    u32 j;
    Src *src;
    u32 k;
    Sub20 *s20;
    s32 base3;
    u32 size;
    Sec *sec;
    Sub *sub;
    H8 *dst;
    u16 base;
    u32 off;
    E12 *d12;

    off = 0;
    out->tag = D_089B265C | (D_089B265D << 8) | (D_089B265E << 16) | (D_089B265F << 24);
    out->size = 0x20;
    out->count = 2;
    out->total = 0;
    out->sum = 0;
    out->off1 = 0;
    out->off2 = 0;
    out->off3 = 0;
    for (i = 0; i < n; i++) {
        out->sum += srcs[i]->unk10;
    }
    off += 0x20;
    out->off1 = off;

    base = 0;
    max = 0;
    sec = (Sec *)((char *)out + off);
    size = 0;
    sec->tag = D_089B2664 | (D_089B2665 << 8) | (D_089B2666 << 16) | (D_089B2667 << 24);
    size += 0x10;
    sec->size = 0;
    sec->count = 0;
    sec->unkC = -1;
    for (i = 0; i < n; i++) {
        src = srcs[i];
        sub = (Sub *)((char *)src + src->off14);
        if (max < sub->count) {
            max = sub->count;
        }
    }
    sec->count = max;
    for (i = 0; i < max + 1; i++) {
        sec->tbl[i] = -1;
    }
    size += (max + 1) * 4;
    for (i = 0; i < n; i++) {
        src = srcs[i];
        sub = (Sub *)((char *)src + src->off14);
        sub2 = (Sub *)((char *)src + src->off18);
        for (j = 0; j < sub->count + 1; j++) {
            if (sub->tbl[j] != -1) {
                h = (H8 *)((char *)sub + sub->tbl[j]);
                if (sec->tbl[j] != -1) {
                    return -1;
                }
                sec->tbl[j] = size;
                dst = (H8 *)((char *)sec + size);
                size += h->hd.cnt * 14 + 8;
                dst->hd = h->hd;
                for (k = 0; k < dst->hd.cnt; k++) {
                    dst->e[k] = h->e[k];
                    dst->e[k].unkC += base;
                }
            }
        }
        base += (u16)(sub2->count + 1);
    }
    while (size & 0xF) {
        ((u8 *)sec)[size++] = 0xFF;
    }
    sec->size = size;
    off += size;
    out->off2 = off;

    sec2 = (Sec *)((char *)out + off);
    size = 0;
    base2 = 0;
    sec2->tag = D_089B266C | (D_089B266D << 8) | (D_089B266E << 16) | (D_089B266F << 24);
    size += 0x10;
    sec2->size = 0;
    sec2->count = 0;
    sec2->unkC = -1;
    for (i = 0; i < n; i++) {
        src2 = srcs[i];
        s12 = (Sub12 *)((char *)src2 + src2->off18);
        sub22 = (Sub *)((char *)src2 + src2->off1C);
        d12 = (E12 *)((char *)sec2 + size);
        sec2->count += s12->count + 1;
        for (j = 0; j < s12->count + 1; j++) {
            d12[j] = s12->e[j];
            d12[j].unkA += base2;
        }
        size += (s12->count + 1) * 12;
        base2 += (u16)(sub22->count + 1);
    }
    sec2->count -= 1;
    while (size & 0xF) {
        ((u8 *)sec2)[size++] = 0xFF;
    }
    sec2->size = size;
    off += size;
    out->off3 = off;

    sec = (Sec *)((char *)out + off);
    size = 0;
    base3 = 0;
    sec->tag = D_089B2674 | (D_089B2675 << 8) | (D_089B2676 << 16) | (D_089B2677 << 24);
    size += 0x10;
    sec->size = 0;
    sec->count = 0;
    sec->unkC = -1;
    for (i = 0; i < n; i++) {
        src = srcs[i];
        s20 = (Sub20 *)((char *)src + src->off1C);
        d20 = (E20 *)((char *)sec + size);
        sec->count += s20->count + 1;
        for (j = 0; j < s20->count + 1; j++) {
            d20[j] = s20->e[j];
            d20[j].unk0 += base3;
        }
        size += (s20->count + 1) * 20;
        base3 += src->unk10;
    }
    sec->count -= 1;
    while (size & 0xF) {
        ((u8 *)sec)[size++] = 0xFF;
    }
    sec->size = size;
    out->total = off + size;
    return off + size;
}
