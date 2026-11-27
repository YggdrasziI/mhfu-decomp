/* unit_0882FA24: 0x0882FA24-0x0882FB38 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Lays out a box from a template (hypothesis): position
 * offset by (dx, dy), size from the template counts, flag adds a line.
 * - f = (flag != 0) must be computed after the plain copies (here just
 *   before n): computed at the top, it takes v1 instead of the register
 *   freed by dy (t0).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    /* 0x00 */ u16 x;
    /* 0x02 */ u16 y;
    /* 0x04 */ u8 b4;
    /* 0x05 */ u8 b5;
    /* 0x06 */ u8 b6;
    /* 0x07 */ u8 b7;
    /* 0x08 */ u16 h8;
    /* 0x0A */ u16 hA;
    /* 0x0C */ s32 wC;
    /* 0x10 */ s32 w10;
} Src;

typedef struct {
    /* 0x00 */ u16 x;
    /* 0x02 */ u16 y;
    /* 0x04 */ u16 w;
    /* 0x06 */ u16 h;
    /* 0x08 */ u8 b8;
    /* 0x09 */ u8 b9;
    /* 0x0A */ u8 bA;
    /* 0x0B */ u8 bB;
    /* 0x0C */ u16 hC;
    /* 0x0E */ u16 hE;
    /* 0x10 */ u16 h10;
    /* 0x12 */ u16 h12;
    /* 0x14 */ s32 w14;
    /* 0x18 */ s32 w18;
    /* 0x1C */ u16 h1C;
    /* 0x1E */ u16 h1E;
    /* 0x20 */ u16 h20;
    /* 0x22 */ u16 h22;
    /* 0x24 */ u16 h24;
    /* 0x26 */ u16 h26;
} Dst;

void func_0882FA24(Dst *out, Src *in, s32 flag, s16 dx, s16 dy)
{
    s32 f;
    s16 n;

    out->x = in->x + dx;
    out->y = in->y + dy;
    out->b8 = in->b4;
    out->b9 = in->b5;
    out->bA = in->b6;
    out->bB = in->b7;
    out->h12 = in->hA;
    out->w14 = in->wC;
    out->w18 = in->w10;
    f = flag != 0;
    n = in->b5 + 2;
    out->w = (((s32)(in->b4 * in->h8) >> 1) + 0x17) & 0x7FF8;
    out->h = n * (in->hA + f) + 0x10;
    out->hC = out->x + 8;
    out->hE = out->y + (f ? 25 : 10);
    out->h10 = n;
    out->h1C = out->x + 6;
    out->h1E = out->hE - 2;
    out->h20 = out->w - 12;
    out->h22 = n + 1;
    out->h24 = out->x + 8;
    out->h26 = out->y + 7;
}
