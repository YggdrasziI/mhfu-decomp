/* unit_088405E4: 0x088405E4-0x08840BC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088405E4 (ULES01213)
 *
 * C++: virtual call through D_09A4F060. Optimized for speed: the float
 * constants are built as immediates. The sines are VFPU code in an `asm { }`
 * block (notes/COMPILER.md, "VFPU in asm blocks").
 *
 * The switch selector is passed to func_08840C24 as its second argument,
 * which is why the `seh` lands in a1. `default:` written first keeps its
 * stores before the case bodies. The gauge widths go through an inline
 * helper taking the maximum as a float (converted before the value).
 * func_0882D6F0 takes its colour bytes as u8.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef union { u32 w; u8 b[4]; } Col;

struct Obj { u8 pad[0x3C]; u8 f3C; };
typedef struct V28 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual Obj *vfunc_28(); } V28;

extern "C" {

extern char *D_08A631A0;
extern char *D_09A4F060;
extern u16 D_0893B57C;
extern u16 D_0893B57E;
extern u16 D_0893B580;
extern u16 D_0893B582;
extern u16 D_0893B586;
extern u16 D_0893B588;
extern u16 D_0893B58A;
extern u16 D_0893B58C;
extern u16 D_0893B58E;
extern u16 D_0893B592;

extern u32 func_08840C24(char *, s16);
extern u32 func_08840E30(char *);
extern u32 func_08840F30(char *, s16);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882AC18(char *, u16, u16, u16, u16, s32);
extern void func_0882D6F0(char *, u16, u16, u16, u16, u8, u8, u8);
extern s32 func_09A6A708(char *);

static inline s32 scale(float max, s16 v, float k) {
    float m = max;
    return m * (k * v);
}

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

void func_088405E4(char *arg0) {
    Col c1;
    Col c0;
    char *p;
    char *q;
    s32 w;
    s16 h;
    s16 k;

    if (*(s32 *)(arg0 + 0x1194) & 2) {
        return;
    }
    c0.w = 0xFF10C010;
    c1.w = 0xFFF0F000;
    p = *(char **)(arg0 + 0x530);
    k = (**(V28 **)D_09A4F060).vfunc_28()->f3C;
    switch (k) {
    default:
        *(s16 *)(arg0 + 0x11A2) = 0;
        *(s16 *)(arg0 + 0x11A0) = 0;
        break;
    case 0:
    case 1:
    case 2:
        c0.w = func_08840C24(arg0, k);
        break;
    case 3:
    case 4:
        c1.w = func_08840F30(arg0, k);
        c0.w = func_08840E30(arg0);
        break;
    }
    q = *(char **)(arg0 + 0x530);
    w = scale(D_0893B580, *(s16 *)(q + 0x41E), 0.01f);
    func_0882AC18(arg0, D_0893B57C, D_0893B57E, w, D_0893B582, 3);
    func_0882A9DC(arg0, D_0893B57C + w, D_0893B586, 5);
    q = *(char **)(arg0 + 0x530);
    if (*(s16 *)(q + 0x2E4) > 0) {
        if (*(s16 *)(arg0 + 0x560) < *(s16 *)(q + 0x41C)) {
            func_0882D6F0(arg0, D_0893B57C, D_0893B57E + 5,
                          scale(D_0893B580, *(s16 *)(q + 0x41C), 0.01f), 2, 0xC0, 0x10, 0x10);
        }
        func_0882D6F0(arg0, D_0893B57C, D_0893B57E + 5,
                      (s32)(0.01f * *(s16 *)(arg0 + 0x560) * D_0893B580), 2, c0.b[2], c0.b[1], c0.b[0]);
    }
    q = *(char **)(arg0 + 0x530);
    w = scale(D_0893B58C, *(s16 *)(q + 0x62E), 0.0033333334f);
    func_0882AC18(arg0, D_0893B588, D_0893B58A, w, D_0893B58E, 4);
    func_0882A9DC(arg0, D_0893B588 + w, D_0893B592, 6);
    q = *(char **)(arg0 + 0x530);
    h = *(s16 *)(q + 0x55A);
    w = scale(D_0893B58C, h, 0.0033333334f);
    if (h < 0x4C) {
        s32 a;
        s32 ph;
        float ang;

        ph = *(s32 *)(D_08A631A0 + 0xF7A554) % 45 * 8;
        ang = ph;
        ang = 6.2831855f * (ang / 360.0f);
        a = (u8)((s16)(64.0f * sin_vfpu(ang)) + 0x40);
        func_0882D6F0(arg0, D_0893B588, D_0893B58A + 1, w, 2, 0xFF, a, a);
        return;
    }
    if ((u8)func_09A6A708(p) == 0) {
        func_0882D6F0(arg0, D_0893B588, D_0893B58A + 1, w, 2, c1.b[2], c1.b[1], c1.b[0]);
    } else {
        u32 phase;
        float ang;
        float s;
        s32 g;

        phase = (u16)((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x3F) << 10);
        ang = phase;
        ang = 9.58737992e-05f * (float)ang;
        s = sin_vfpu(ang);
        g = (u8)((s8)(18.0f * s) + 0xE7);
        func_0882D6F0(arg0, D_0893B588, D_0893B58A + 1, w, 2, g, g, (u8)((s8)(40.0f * s) + 0x9F));
    }
}

}
