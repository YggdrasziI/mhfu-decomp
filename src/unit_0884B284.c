/* unit_0884B284: 0x0884B284-0x0884BB00 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Appends a fixed list of display-list words through D_089CC000: six words
 * built from the floats at D_089CBBE4 + 0xDA0..0xDB4, constant state words,
 * then a colour word and two float words (65000 * *D_08A62C40 and the
 * inverse of a difference that is replaced by 1 when zero).
 * Speed setting: the float constants are built with lui/ori.
 * The colour temporary is 8 bytes (Col8) so the stack slots match.
 */
#pragma optimize_for_size off
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef union {
    u32 w;
    u8 c[4];
} Col;
typedef struct { Col c; u32 pad; } Col8;

typedef union {
    f32 f;
    u32 w;
} FBits;

extern char *D_089CBBE4;
extern u32 *D_089CC000;
extern f32 *D_08A62C40;
extern void func_0884BB00(s32);
extern s32 func_0884C89C(s32, s32);
extern void func_0884C7C0(s32, s32);
extern void func_0884C914(s32);

void func_0884B284(s32 arg0) {
    Col8 t;
    Col col;
    FBits far;
    FBits inv;
    FBits one;
    f32 d;
    char *g;

    func_0884BB00(arg0);
    if (func_0884C89C(arg0, 1) != 0) {
        g = D_089CBBE4;
        *D_089CC000++ = (*(u32 *)(g + 0xDA0) >> 8) | 0x42000000;
        *D_089CC000++ = (*(u32 *)(g + 0xDA4) >> 8) | 0x43000000;
        *D_089CC000++ = (*(u32 *)(g + 0xDA8) >> 8) | 0x44000000;
        *D_089CC000++ = (*(u32 *)(g + 0xDAC) >> 8) | 0x45000000;
        *D_089CC000++ = (*(u32 *)(g + 0xDB0) >> 8) | 0x46000000;
        *D_089CC000++ = (*(u32 *)(g + 0xDB4) >> 8) | 0x47000000;
        *D_089CC000++ = 0xD6000000;
        *D_089CC000++ = 0xD700FFFF;
        *D_089CC000++ = 0xD4000000;
        *D_089CC000++ = 0xD50441E0;
        *D_089CC000++ = 0x4C007100;
        *D_089CC000++ = 0x4D007780;
        *D_089CC000++ = 0x22000001;
        *D_089CC000++ = 0xDBFFC007;
        *D_089CC000++ = 0x21000001;
        *D_089CC000++ = 0xDF000032;
        *D_089CC000++ = 0x27000000;
        *D_089CC000++ = 0xD8000000;
        *D_089CC000++ = 0xDAFFFFFF;
        *D_089CC000++ = 0x24000000;
        *D_089CC000++ = 0x23000001;
        *D_089CC000++ = 0xDE000005;
        *D_089CC000++ = 0x20000000;
        func_0884C7C0(arg0, 0);
        *D_089CC000++ = 0x25000000;
        *D_089CC000++ = 0x28000000;
        *D_089CC000++ = 0x1D000000;
        *D_089CC000++ = 0x1C000001;
        *D_089CC000++ = 0x50000001;
        *D_089CC000++ = 0x5C000000;
        *D_089CC000++ = 0x5D0000FF;
        *D_089CC000++ = 0x54000000;
        *D_089CC000++ = 0x57000000;
        *D_089CC000++ = 0x5B000000;
        *D_089CC000++ = 0xC0000000;
        *D_089CC000++ = 0xC6000101;
        *D_089CC000++ = 0xC9000100;
        *D_089CC000++ = 0xC7000000;
        *D_089CC000++ = 0x4A000000;
        *D_089CC000++ = 0x4B000000;
        one.f = 1.0f;
        *D_089CC000++ = (one.w >> 8) | 0x48000000;
        *D_089CC000++ = (one.w >> 8) | 0x49000000;
        *D_089CC000++ = 0x5E000000;
        *D_089CC000++ = 0x17000000;
        *D_089CC000++ = 0x18000001;
        *D_089CC000++ = 0x90000000;
        *D_089CC000++ = 0x8F000000;
        *D_089CC000++ = 0x91000000;
        *D_089CC000++ = 0x19000001;
        *D_089CC000++ = 0x93000000;
        *D_089CC000++ = 0x92000000;
        *D_089CC000++ = 0x94000000;
        *D_089CC000++ = 0x1A000001;
        *D_089CC000++ = 0x96000000;
        *D_089CC000++ = 0x95000000;
        *D_089CC000++ = 0x97000000;
        *D_089CC000++ = 0x1B000000;
        *D_089CC000++ = 0x99000000;
        *D_089CC000++ = 0x98000000;
        *D_089CC000++ = 0x9A000000;
        *D_089CC000++ = 0x1F000000;
        t.c.w = 0;
        col = t.c;
        far.f = 65000.0f * *D_08A62C40;
        d = far.f - far.f;
        d = d ? d : 1.0f;
        inv.f = 1.0f / d;
        *D_089CC000++ = 0xCF000000 | (col.c[2] << 16) | (col.c[1] << 8) | col.c[0];
        *D_089CC000++ = (far.w >> 8) | 0xCD000000;
        *D_089CC000++ = (inv.w >> 8) | 0xCE000000;
        func_0884C914(arg0);
    }
}
