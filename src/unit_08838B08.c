/* unit_08838B08: 0x08838B08-0x08838E0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

/* func_08838B08: a horizontal alpha-gradient quad (four vertices, colour
 * c, left alpha `left`, right alpha `right`) at (x, y, w, h). Flag bit 7
 * clear: fixed alpha 0xE5 and an extra sprite drawn by func_0882C11C
 * (flag 0) or func_0882C7B4; bit 7 set: alphas 0xE0/0x60 swapped by the low
 * bits, both raised by 16 * sin of a phase read from D_08A631A0 + 0xF7A554.
 * Colour byte names r/g/b are placeholders (packed as 0x34<<16|0x35<<8|0x36).
 *
 * Needs the speed setting (float constant built with lui/ori). Register
 * colouring of the vertex block depends on the statement order below
 * (found with a dependency-aware statement search).
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Col {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Col;

extern char *D_08A631A0;
extern s32 D_08A62C40;

extern void func_0882C11C(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32);
extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);
extern u32 *func_088597FC(s32);
extern int func_088596C8(s32, u32 *, s32, u8);
extern int func_0885980C(s32, u32 *);

static inline float sin_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

void func_08838B08(char *arg0, s16 x, s16 y, s16 w, s16 h, Col c, u8 flag) {
    u32 *p;
    u32 phase;
    float ang;
    float s;
    s32 left;
    s32 right;
    u8 d;
    u32 rgb;
    u32 c0;
    u32 c1;
    u32 a;
    u32 x0;
    u32 x1;
    u32 y0;
    u32 y1;
    s32 xs;

    phase = (u16)((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x3F) << 10);
    ang = phase;
    ang = 9.58737992e-05f * (float)ang;
    s = sin_vfpu(ang);
    if (!(flag & 0x80)) {
        left = right = 0xE5;
        if (flag == 0) {
            func_0882C11C(arg0, x + w, y, 0x20, h, 0xFF, 0xFF, 0xFF, right, 0x103);
        } else {
            func_0882C7B4(arg0, x - 0x20, y, 0x20, h, 0xFF, 0xFF, 0xFF, right, 0x103, 1);
        }
    } else {
        if ((flag & 0x7F) == 0) {
            left = 0xE0;
            right = 0x60;
        } else {
            left = 0x60;
            right = 0xE0;
        }
        d = (u8)(s32)(16.0f * s);
        left += d;
        left &= 0xFF;
        right += d;
        right &= 0xFF;
    }
    p = func_088597FC(D_08A62C40);
    c0 = (u8)left << 24;
    xs = x;
    rgb = c.b | (c.g << 8) | (c.r << 16);
    x0 = xs & 0xFFFF;
    c0 |= rgb;
    y0 = y << 16;
    p[0] = c0;
    p[1] = y0 | x0;
    p[2] = 0;
    y1 = (y + h) << 16;
    p[3] = c0;
    p[4] = x0 | y1;
    p[5] = 0;
    c1 = ((u8)right << 24) | rgb;
    x1 = (u16)(xs + w);
    p[6] = c1;
    p[7] = y0 | x1;
    p[8] = 0;
    p[9] = c1;
    p[10] = y1 | x1;
    p[11] = 0;
    a = (u32)p;
    p[12] = ((a & 0xFF000000) >> 8) | 0x10000000;
    p[13] = ((a << 8) >> 8) | 0x01000000;
    p[14] = 0x1E000000;
    p[15] = 0x50000001;
    p[16] = 0x1280011C;
    p[17] = 0x04040004;
    p[18] = 0x10000000;
    p[19] = 0x08000000;
    func_088596C8(D_08A62C40, p + 12, 8, *(u8 *)(arg0 + 0x534));
    func_0885980C(D_08A62C40, p + 20);
}
