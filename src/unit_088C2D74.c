/* unit_088C2D74: 0x088C2D74-0x088C2F48 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088C2D74 asm piece, 1 function
 * between unit_088C2CE0 and unit_088C2F48.
 *
 * Encodes (enc != 0) or decodes the save image buf of len bytes: the last
 * word, passed through the byte table sbox twice, seeds the keystream
 * (func_088C2F48) before (decode) or after (encode) the substitution; each
 * other word is substituted, xored with the next keystream word
 * (func_088C2F88) and substituted again.
 *
 * Speed mode: the loop steps four byte pointers (one per byte of the word),
 * which only the speed setting keeps in registers (notes/MATCHING.md).
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern void func_088C2F48(char *, u32);
extern u32 func_088C2F88(char *);

void func_088C2D74(char *ctx, u8 *buf, u32 len, u8 *sbox, s32 enc) {
    u8 *last;
    u32 n;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u32 i;

    last = buf + len - 4;
    if (enc == 0) {
        func_088C2F48(ctx, *(u32 *) last);
    }
    last[0] = sbox[last[0]];
    last[1] = sbox[last[1]];
    last[2] = sbox[last[2]];
    last[3] = sbox[last[3]];
    last[0] = sbox[last[0]];
    last[1] = sbox[last[1]];
    last[2] = sbox[last[2]];
    last[3] = sbox[last[3]];
    if (enc != 0) {
        func_088C2F48(ctx, *(u32 *) last);
    }
    n = len - 4;
    p1 = buf + 1;
    p2 = buf + 2;
    p3 = buf + 3;
    for (i = 0; i < n; i += 4) {
        *buf = sbox[*buf];
        *p1 = sbox[*p1];
        *p2 = sbox[*p2];
        *p3 = sbox[*p3];
        *(u32 *) buf ^= func_088C2F88(ctx);
        *buf = sbox[*buf];
        *p1 = sbox[*p1];
        *p2 = sbox[*p2];
        *p3 = sbox[*p3];
        buf += 4;
        p1 += 4;
        p2 += 4;
        p3 += 4;
    }
}
