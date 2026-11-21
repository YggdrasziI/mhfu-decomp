/* unit_088FB2B0: 0x088FB2B0-0x088FBC3C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_088F0088 and text_088FBC3C).
 *
 * The sine is VFPU code in an `asm { }` block (notes/COMPILER.md, "VFPU in
 * asm blocks"). Optimized for speed: the divisions by 12 and 60 are
 * multiplications.
 *
 * #pragma opt_unroll_loops off (hypothesis): without it the compiler unrolls
 * the  /= 12 loop by 8, the original keeps one division per pass.
 *
 * Register allocation: the two base-12 digit loops are one inline helper,
 * the coordinates of the last loop are derived from its counter (strength
 * reduced by the compiler), the loops of the row list start their counter
 * before the y locals, and the locals are reused across loops in the
 * declaration order below (found by a scripted search).
 */

#pragma optimize_for_size off
#pragma opt_unroll_loops off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CBBEC;
extern char *D_08A631A8;
extern char *D_08A631A0;
extern char *D_089CC438;
extern s32 D_09B22D70;
extern s32 D_089B81F8[];
extern u16 D_09B055C2;
extern u16 D_09B055C4;
extern u16 D_09B055C6;
extern u16 D_09B055C8;
extern u16 D_09B056A0[];
extern u16 D_089AC8E4;
extern u16 D_0893AE68[];
extern char D_089B8674[];
extern char D_089B86C8[];
extern char D_089B86D4[];
extern char D_089B86D8[];
extern char D_089B86E0[];

extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern void func_0882DCB0(char *, s32, s32, s32, s32, s32, s32);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern char *func_09A7B790(s32, u16);
extern int func_08827918(char *, s32, s32, char *, s32, s32);
extern void func_0882B94C(char *, u16, u16, s32, s32, s32, s32, s32);
extern char *func_0885151C(char *, u16);
extern void func_08891474(char *, s32, s16, char *, ...);
extern void func_0882B624(char *, s32, s32, s32, s32, s32, s32, s32);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);
extern void func_0882DAC0(char *, s32, s32, s32, s32, s32, s32, s32);
extern void func_0887D02C(s32, s32, char *, s32);
extern int func_0880E8F0(char *, char *, ...);
extern s32 func_0882A9DC(char *, u16, u16, s32);

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

static inline void draw_digits(u32 *p, s32 x0, s32 y) {
    s32 n;
    u32 m;
    u32 v;
    for (n = 0; n < 4; n++) {
        v = *(u16 *)p & 0x7FFF;
        for (m = 0; m < n; m++) {
            v /= 12;
        }
        if (v % 12 != 11) {
            func_0882A9DC(D_089CBBEC, n * 0x12 + x0, y, D_0893AE68[v % 12]);
        }
    }
}

void func_088FB2B0(char *arg0, char *arg1, s32 arg2) {
    s32 row;
    s32 line;
    s32 *col;
    float ang;
    char *g;
    float s;
    s32 rows;
    s32 y2;
    u32 t;
    s32 i;
    u32 *a;
    u8 blink;
    s32 k;
    u32 *b;
    s32 j;
    u32 phase;
    s32 mask;
    s32 y;
    s32 n;
    s32 sel;

    g = D_089CBBEC;
    g[0x534] = 0xD;
    func_08890E08(D_08A631A8, 4);
    func_08825DA8(g);
    col = &D_089B81F8[arg2];
    func_0882DCB0(D_089CBBEC, 0x10, 0x2C, 0xC0, 0xD0, 0xFF, *col);
    func_0882DCB0(D_089CBBEC, 0xE0, 0x28, 0xF0, 0xD8, 0xFF, *col);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    func_08890E38(D_08A631A8, 5);
    func_08827918(D_089CBBEC, 0x9A, 0x11, func_09A7B790(D_09B22D70, D_09B055C6), 0xE, 0x10);
    phase = (u16) ((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x3F) << 10);
    ang = phase;
    ang = 9.58737992e-05f * (float) ang;
    s = sin_vfpu(ang);
    blink = (s8) (48.0f * s) + 0xAF;
    *(s8 *)(arg0 + 0x21) = 0;
    mask = 0;
    for (y2 = 0; y2 < 20; y2++) {
        if (*(u32 *)(arg1 + 0x2AC + y2 * 0x14) >> 15) {
            mask |= 1 << y2;
            (*(s8 *)(arg0 + 0x21))++;
        }
    }
    sel = 0;
    func_08890E38(D_08A631A8, 0);
    if (*(s8 *)(arg0 + 0x21) <= 0) {
        n = 0;
        func_0882B94C(D_089CBBEC, 0x16, 0x39, 0xFF, 0xFF, 0xFF, 0x66, 0x159);
        for (n++; n <= 9; n++) {
            func_0882B94C(D_089CBBEC, n * 16 + 0x16, 0x39, 0xFF, 0xFF, 0xFF, 0x66, 0x15A);
        }
        func_0882B94C(D_089CBBEC, n * 16 + 0x16, 0x39, 0xFF, 0xFF, 0xFF, 0x66, 0x15B);
        func_08891474(D_08A631A8, 0x1C, 0x3A, func_0885151C(D_089CC438, D_089AC8E4));
    } else {
        rows = 0;
        k = 0;
        y = 0x39;
        y2 = 0x3B;
        for (; k < 20; k++) {
            n = (*(s8 *)(arg0 + 0xA72A) + k) % 20;
            if (mask & (1 << n)) {
                j = 0;
                func_0882B94C(D_089CBBEC, 0x16, y, 0xFF, 0xFF, 0xFF, 0x66, 0x159);
                for (j++; j <= 9; j++) {
                    func_0882B94C(D_089CBBEC, j * 16 + 0x16, y, 0xFF, 0xFF, 0xFF, 0x66, 0x15A);
                }
                func_0882B94C(D_089CBBEC, j * 16 + 0x16, y, 0xFF, 0xFF, 0xFF, 0x66, 0x15B);
                func_08891474(D_08A631A8, 0x1C, y2, func_09A7B790(D_09B22D70, D_09B056A0[n]));
                if (rows == *(s8 *)(arg0 + 0x10)) {
                    sel = n;
                }
                y += 0x12;
                y2 += 0x12;
                rows++;
            }
            if (rows >= 10) {
                break;
            }
        }
        if (*(s8 *)(arg0 + 0x21) > 10) {
            func_0882B624(D_089CBBEC, 0x68, 0x28, 0, 0xC0, 0x40, 0x9D, 0);
            func_0882B624(D_089CBBEC, 0x68, 0xEE, 0, 0xC0, 0x40, 0x9D, 2);
        }
    }
    y2 = *(s8 *)(arg0 + 0x10) * 18 + 0x39;
    func_0882BE60(D_089CBBEC, 0x16, y2, 0xB0, 2, 0x20, blink, 0x20, 0x105);
    func_0882BE60(D_089CBBEC, 0x16, y2 + 0xE, 0xB0, 2, 0x20, blink, 0x20, 0x105);
    func_0882BE60(D_089CBBEC, 0x16, y2 + 2, 2, 0xC, 0x20, blink, 0x20, 0x106);
    func_0882BE60(D_089CBBEC, 0xC4, y2 + 2, 2, 0xC, 0x20, blink, 0x20, 0x106);
    func_0882DAC0(D_089CBBEC, 0xE8, 0x40, 0x1CA, 0x40, 0xFF, 0xFF, 0xFF);
    func_08891474(D_08A631A8, 0xE8, 0x30, func_09A7B790(D_09B22D70, D_09B055C8));
    func_08827918(D_089CBBEC, 0x143, 0x30, func_09A7B790(D_09B22D70, D_09B055C2), 0xE, 0x10);
    func_08827918(D_089CBBEC, 0x1A0, 0x30, func_09A7B790(D_09B22D70, D_09B055C4), 0xE, 0x10);
    func_08890DE8(D_08A631A8, 0x30, 0x18);
    func_08890E38(D_08A631A8, 6);
    for (line = 0; line < 5; line++) {
        func_08891474(D_08A631A8, 0xEA, 0x4E + line * 0x24, D_089B8674, line + 1);
        func_08890E38(D_08A631A8, 0);
    }
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    if (*(s8 *)(arg0 + 0x21) <= 0) {
        for (i = 0; i < 5; i++) {
            func_0887D02C(0x160, 0x58 + i * 0x24, D_089B86D8, 0xE);
            func_0887D02C(0x1B6, 0x58 + i * 0x24, D_089B86E0, 0xE);
        }
        return;
    }
    a = (u32 *)(arg1 + sel * 0x14 + 0x2AC);
    b = (u32 *)(arg1 + sel * 0x14 + 0x498);
    for (row = 0; row < 5; row++) {
        if (*a >> 15) {
            draw_digits(a, 0x11F, row * 0x24 + 0x46);
            t = *a >> 15;
            func_0880E8F0(arg0 + 0x88, D_089B86C8, t / 60, t % 60);
            func_0887D02C(0x160, row * 0x24 + 0x58, arg0 + 0x88, 0xE);
        } else {
            func_0887D02C(0x160, row * 0x24 + 0x58, D_089B86D8, 0xE);
        }
        if (*b >> 15) {
            draw_digits(b, 0x176, row * 0x24 + 0x46);
            func_0880E8F0(arg0 + 0x88, D_089B86D4, *b >> 15);
            func_0887D02C(0x1B6, row * 0x24 + 0x58, arg0 + 0x88, 0xE);
        } else {
            func_0887D02C(0x1B6, row * 0x24 + 0x58, D_089B86E0, 0xE);
        }
        a++;
        b++;
    }
}
