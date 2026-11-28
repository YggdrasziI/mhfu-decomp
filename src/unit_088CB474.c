#pragma optimize_for_size off

/* func_088CB474: builds a 4-vertex GE strip whose vertex colours are
 * interpolated from the angle difference of two atan2 results
 * (hypothesis from the arithmetic). */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef union Color {
    u32 w;
    u8 c[4];
} Color;

extern char *D_089CBBE4;
extern u32 *D_089CC000;
extern Color func_088CBBAC(char *arg1, u8 *a, u8 *b, float t);

#define VPFXS_ABS .word 0xDC000FE4
#define VPFXS_TWO .word 0xDC00F0AA
#define VPFXS_NEG_Y .word 0xDC0200E4
#define VPFXT_ABS .word 0xDD000FE4
#define VPFXT_HALF .word 0xDD00F0FF
#define VPFXD_SAT_Y .word 0xDE000004
#define VFIM_S010_M1 .word 0xDF81BC00

static inline float atan2_vfpu(float y, float x) {
    float r;
    float *pr = &r;
    float *py = &y;
    float *px = &x;
    asm {
        .set noreorder
        lv.s S000, 0(py)
        lv.s S001, 0(px)
        vcmp.p es, C000, C000
        bvt 4, special
        vzero.s S002
        vcmp.s ge, S001, S002
        vcst.s S010, VFPU_PI
        vcmovt.s S010, S002, 0
        vcmp.s ez, S000, S000
        bvt 0, done
        vcst.s S002, VFPU_PI_2
        vrcp.s S003, S001
        vmul.s S003, S000, S003
        vcmp.s en, S003, S003
        bvt 0, done
        vmov.s S010, S003
        vcmp.s es, S003, S003
        bvtl 0, quadrant
        vsgn.s S010, S000
        vmul.s S011, S003, S003
        vcmp.s es, S011, S011
        bvt 0, overflow
        vone.s S003
        VPFXS_ABS
        vcmp.s lt, S010, S003
        vadd.s S003, S011, S003
        bvfl 0, steep
        vrcp.s S003, S003
        vrsq.s S003, S003
        vmul.s S010, S010, S003
        b quadrant
        vasin.s S010, S010
    special:
        vcmp.p en, C000, C000
        VFIM_S010_M1
        bvt 4, done
        vrsq.s S010, S010
        vcmp.p ei, C000, C000
        bvt 5, both_inf
        nop
        vi2f.s S000, S000, 0
        VPFXT_HALF
        vadd.s S000, S000, S000
        vsgn.s S000, S000
        vcst.s S002, VFPU_PI_2
        bvt 0, finish
        vone.s S010
        vzero.s S003
        vcmp.s ge, S001, S003
        vcmovt.s S010, S003, 0
        b finish
        vcst.s S002, VFPU_PI
    both_inf:
        vsgn.p C000, C000
        VPFXS_TWO
        vsub.s S010, S010, S001
        b finish
        vcst.s S002, VFPU_PI_4
    overflow:
        vsgn.s S000, S000
        vcst.s S002, VFPU_PI_2
        bvt 0, finish
        vone.s S010
        vsgn.s S011, S001
        b finish
        vsub.s S010, S010, S011
    steep:
        vmul.s S003, S011, S003
        vpfxd [0:1],[0:1],[0:1],[0:1]
        vocp.s S003, S003
        vsqrt.s S003, S003
        vasin.s S003, S003
        vocp.s S010, S003
    quadrant:
        VPFXD_SAT_Y
        VPFXS_NEG_Y
        vsgn.p C000, C000
        vcmp.s ez, S001, S001
        bvt 0, finish
        nop
        VPFXS_TWO
        VPFXT_ABS
        vsub.s S010, S010, S010
    finish:
        VPFXS_ABS
        vmul.s S010, S010, S000
        vmul.s S010, S010, S002
    done:
        sv.s S010, 0(pr)
    }
    return r;
}

void func_088CB474(char *arg0) {
    f32 t;
    u16 a;
    u16 b;
    u16 d;

    a = (u16)(s32)(0.5f + 65536.0f * atan2_vfpu(-*(f32 *)(D_089CBBE4 + 0xCA0), -*(f32 *)(D_089CBBE4 + 0xCA8)) / 6.2831855f);
    b = (u16)(s32)(0.5f + 65536.0f * atan2_vfpu(*(f32 *)(arg0 + 0x3A4), *(f32 *)(arg0 + 0x3AC)) / 6.2831855f);
    *(s16 *)(arg0 + 0x3EA) = *(s16 *)(arg0 + 0x3F6) = *(s16 *)(arg0 + 0x3B0);
    d = b - a;
    *(u16 *)(arg0 + 0x402) = *(u16 *)(arg0 + 0x40E) = (u32)(272.0f * ((f32)*(s16 *)(arg0 + 0x3B2) / 448.0f));
    if (d < 0x4000) {
        t = (f32)d / 16384.0f;
        ((Color *)(arg0 + 0x3E4))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3B4), (u8 *)(arg0 + 0x3BC), t).w;
        ((Color *)(arg0 + 0x3F0))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3B4), (u8 *)(arg0 + 0x3C0), t).w;
        ((Color *)(arg0 + 0x3FC))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3C4), (u8 *)(arg0 + 0x3CC), t).w;
        ((Color *)(arg0 + 0x408))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3C4), (u8 *)(arg0 + 0x3D0), t).w;
    } else if (d < 0x8000) {
        t = (f32)(d - 0x4000) / 16384.0f;
        ((Color *)(arg0 + 0x3E4))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3BC), (u8 *)(arg0 + 0x3B8), t).w;
        ((Color *)(arg0 + 0x3F0))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3C0), (u8 *)(arg0 + 0x3B8), t).w;
        ((Color *)(arg0 + 0x3FC))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3CC), (u8 *)(arg0 + 0x3C8), t).w;
        ((Color *)(arg0 + 0x408))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3D0), (u8 *)(arg0 + 0x3C8), t).w;
    } else if (d < 0xC000) {
        t = (f32)(d - 0x8000) / 16384.0f;
        ((Color *)(arg0 + 0x3E4))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3B8), (u8 *)(arg0 + 0x3C0), t).w;
        ((Color *)(arg0 + 0x3F0))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3B8), (u8 *)(arg0 + 0x3BC), t).w;
        ((Color *)(arg0 + 0x3FC))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3C8), (u8 *)(arg0 + 0x3D0), t).w;
        ((Color *)(arg0 + 0x408))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3C8), (u8 *)(arg0 + 0x3CC), t).w;
    } else {
        t = (f32)(d - 0xC000) / 16384.0f;
        ((Color *)(arg0 + 0x3E4))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3C0), (u8 *)(arg0 + 0x3B4), t).w;
        ((Color *)(arg0 + 0x3F0))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3BC), (u8 *)(arg0 + 0x3B4), t).w;
        ((Color *)(arg0 + 0x3FC))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3D0), (u8 *)(arg0 + 0x3C4), t).w;
        ((Color *)(arg0 + 0x408))->w = func_088CBBAC(arg0, (u8 *)(arg0 + 0x3CC), (u8 *)(arg0 + 0x3C4), t).w;
    }
    *D_089CC000 = 0x1280011C;
    D_089CC000++;
    *D_089CC000 = (((u32)(arg0 + 0x3E4) & 0xFF000000) >> 8) | 0x10000000;
    D_089CC000++;
    *D_089CC000 = (((u32)(arg0 + 0x3E4) << 8) >> 8) | 0x01000000;
    D_089CC000++;
    *D_089CC000 = 0x04040004;
    D_089CC000++;
}
