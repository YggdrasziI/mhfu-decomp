/* unit_08893444: 0x08893444-0x0889377C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws one character through the PSP font library (sceFontGetCharInfo,
 * sceFontGetCharGlyphImage); the info and glyph structures are assumed to
 * follow the libfont SceFontCharInfo / SceFontGlyphImage layouts (hypothesis).
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u32 bitmapWidth;
    u32 bitmapHeight;
    u32 bitmapLeft;
    u32 bitmapTop;
    u32 unk10[8];
    u32 unk30[3];
} CharInfo;

typedef struct {
    s32 pixelFormat;
    s32 xPos64;
    s32 yPos64;
    u16 bufWidth;
    u16 bufHeight;
    u16 bytesPerLine;
    u16 pad;
    s32 buffer;
} GlyphImage;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC[3];
} Surface;

extern s32 D_089CBBE0;
extern void func_088125A4(s32, s32, Surface *);
extern s32 func_08894874(s32, s32);
extern s32 sceFontGetCharInfo(s32, s32, CharInfo *);
extern s32 sceFontGetCharGlyphImage(s32, s32, GlyphImage *);

void func_08893444(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    GlyphImage glyph;
    CharInfo info;
    Surface surf;
    u8 *p;
    s32 j;
    s32 i;
    s32 sy;
    s32 sx;
    s32 yb;
    s32 dy;
    s32 xb;

    func_088125A4(D_089CBBE0, (arg2 + 3) & 0xFF, &surf);
    glyph.bufWidth = 0x100;
    glyph.bufHeight = 0x100;
    glyph.pixelFormat = 0;
    glyph.pad = 0;
    glyph.bytesPerLine = 0x80;
    glyph.buffer = surf.unk8;
    p = (u8 *) (surf.unk8 + (arg3 / 2 + arg4 * 128));
    for (i = 0; i < arg0[0x119]; i++) {
        for (j = 0; j < (s32) ((u32) arg0[0x118] >> 1); j++) {
            *p = 0;
            p++;
        }
        p += (0x100 - arg0[0x118]) / 2;
    }
    if ((u16) arg1 == 0x20 || (u16) arg1 == 0xA0 || (u16) arg1 == 0x2002 || (u16) arg1 == 0x2003 ||
        (u16) arg1 == 0x3000) {
        return;
    }
    if ((u16) arg1 == 0x5C) {
        arg1 = 0x3035;
    }
    if (sceFontGetCharInfo(*(s32 *) (arg0 + 8), arg1, &info) != 0) {
        return;
    }
    yb = (((u32) arg0[0x117] >> 1) << 6) + *(s32 *) (arg0 + 0x14);
    sy = *(s32 *) (arg0 + 0x14) + ((arg4 + ((u32) arg0[0x117] >> 1)) << 6);
    xb = (arg3 + ((u32) arg0[0x116] >> 1)) << 6;
    sx = info.bitmapLeft << 6;
    dy = -(info.bitmapTop << 6);
    if (func_08894874((s32) arg0, arg1) == 1 && arg0[0x130] == 0) {
        sx = ((arg0[0x114] - info.bitmapWidth) >> 1) << 6;
    }
    if (*(s32 *) (arg0 + 4) == 0 && yb + dy < 0) {
        sy = (arg4 + ((u32) arg0[0x117] >> 1)) << 6;
        dy = (arg0[0x115] - info.bitmapHeight) << 6;
    }
    if ((u16) arg1 == 0x2A || (u16) arg1 == 0xD7) {
        sy = (arg4 + ((u32) arg0[0x117] >> 1)) << 6;
        dy = ((arg0[0x115] - info.bitmapHeight) >> 1) << 6;
    }
    if ((u16) arg1 == 0xC6 || (u16) arg1 == 0xD0 || (u16) arg1 == 0xD8) {
        sy = (arg4 + ((u32) arg0[0x117] >> 1)) << 6;
        dy = (arg0[0x115] - info.bitmapHeight) << 6;
    }
    glyph.xPos64 = xb + sx;
    glyph.yPos64 = sy + dy;
    if (sceFontGetCharGlyphImage(*(s32 *) (arg0 + 8), arg1, &glyph) != 0) {
        return;
    }
    if (*(s32 *) (arg0 + 4) != 0) {
        return;
    }
    if (func_08894874((s32) arg0, arg1) != 1) {
        return;
    }
    glyph.xPos64 -= 0x1F;
    sceFontGetCharGlyphImage(*(s32 *) (arg0 + 8), arg1, &glyph);
}
