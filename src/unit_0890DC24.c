/* unit_0890DC24: 0x0890DC24-0x0890DD9C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890DC24 (derived from the assembly only).
 *
 * Reads the byte at it->unk4 (bit 0x40 = flag), locates a word block in
 * ctx->unk18 + ctx->unkA4 (after an optional 16-byte aligned block of
 * ctx->unkB4 words when the flag is set), returns its last word, copies the
 * previous word to ctx->unk98 (when ctx->unkB0 is set, or when the count
 * ctx->unkA8 is 9), then copies the count words to ctx->unk60[] and, with the
 * flag, the ctx->unkB4 words before the block to ctx->unk108[].
 *
 * Optimized for speed with loop unrolling off (single-pass bottom-tested
 * copy loops behind a guard).
 */

#pragma optimize_for_size off
#pragma opt_unroll_loops off

typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    s8 *unk4;
} Iter;

typedef struct {
    char pad0[0x14];
    char *unk14;
    char *unk18;
    char pad1C[0x60 - 0x1C];
    u32 unk60[14];
    u32 unk98;
    u32 unk9C;
    u32 unkA0;
    u32 unkA4;
    u32 unkA8;
    u32 unkAC;
    u32 unkB0;
    u32 unkB4;
    char padB8[0x108 - 0xB8];
    u32 unk108[16];
} Ctx;

u32 func_0890DC24(Ctx *ctx, Iter *it) {
    s32 flag;
    u32 n;
    u32 m;
    u32 a;
    u32 b;
    u32 *p;
    u32 *q;
    u32 c;
    u32 r;
    u32 i;

    a = ctx->unkA0;
    b = ctx->unkA4;
    n = ctx->unkA8;
    flag = *it->unk4 & 0x40;
    if (flag) {
        m = ctx->unkB4;
        p = (u32 *) (ctx->unk18 + b + ((m * 4 + 15) & ~15));
        c = ctx->unkB0;
        if (c) {
            q = (u32 *) ((char *) p + (((n + 2) * 4 + 15) & ~15)) - 1;
        } else {
            q = (u32 *) ((char *) p + (((n + 1) * 4 + 15) & ~15)) - 1;
        }
    } else {
        c = ctx->unkB0;
        if (c) {
            q = (u32 *) (ctx->unk18 + b + (((n + 2) * 4 + 15) & ~15)) - 1;
        } else {
            q = (u32 *) (ctx->unk18 + b + (((n + 1) * 4 + 15) & ~15)) - 1;
        }
    }
    r = *q;
    if (c) {
        q--;
        ctx->unk98 = *q;
    } else if (n == 9) {
        q--;
        ctx->unk98 = *q;
        n--;
    }
    q -= n;
    for (i = 0; i < n; i++) {
        ctx->unk60[i] = *q++;
    }
    ctx->unk14 = ctx->unk18 + a;
    if (flag) {
        p -= m;
        for (i = 0; i < m; i++) {
            ctx->unk108[i] = *p++;
        }
    }
    return r;
}
