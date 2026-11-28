/* func_0888DD14: real roots of a cubic p[0] x^3 + p[1] x^2 + p[2] x + p[3]
 * (hypothesis from the arithmetic); VFPU asm blocks for fabs, sqrt, atan2,
 * sin and cos (notes/COMPILER.md, "VFPU in asm blocks"). */

#pragma optimize_for_size off

typedef int s32;
typedef float f32;

extern float func_08897D4C(float, float);

#define VPFXS_ABS .word 0xDC000FE4
#define VPFXS_TWO .word 0xDC00F0AA
#define VPFXS_NEG_Y .word 0xDC0200E4
#define VPFXT_ABS .word 0xDD000FE4
#define VPFXT_HALF .word 0xDD00F0FF
#define VPFXD_SAT_Y .word 0xDE000004
#define VFIM_S010_M1 .word 0xDF81BC00

static inline float fabs_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vabs.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

static inline float sqrt_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vsqrt.s S000, S000
        sv.s S000, 0(pr)
    }
    return r;
}

static inline float cos_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vcos.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
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

s32 func_0888DD14(void *arg0, f32 *out, f32 *p) {
    f32 inv;
    f32 b;
    f32 c;
    f32 d;
    f32 a3;
    f32 q;
    f32 q2;
    f32 r;
    f32 disc;
    f32 t;
    f32 u;
    f32 s;
    f32 th;

    inv = 1.0f / p[0];
    b = p[1] * inv;
    c = p[2] * inv;
    d = p[3] * inv;
    a3 = (1.0f / 3.0f) * b;
    q = (1.0f / 3.0f) * c - a3 * a3;
    r = 0.5f * (d + a3 * (a3 * a3 + a3 * a3 - c));
    if (fabs_vfpu(q) < 1e-6f && fabs_vfpu(r) < 1e-6f) {
        out[0] = -a3;
        return 1;
    }
    q2 = q * q;
    disc = q2 * q + r * r;
    if (disc > 0.0f) {
        if (r >= 0.0f) {
            t = func_08897D4C(r + sqrt_vfpu(disc), 1.0f / 3.0f);
        } else {
            t = -func_08897D4C(-r + sqrt_vfpu(disc), 1.0f / 3.0f);
        }
        u = q / t;
        if (q < 0.0f) {
            out[0] = u - t;
        } else {
            u = t * t;
            out[0] = -2.0f * r * u / (q2 + u * (u + q));
        }
        out[0] = out[0] - a3;
        return 1;
    }
    if (r < 0.0f) {
        s = sqrt_vfpu(-q);
    } else {
        s = -sqrt_vfpu(-q);
    }
    if (fabs_vfpu(disc) < 1e-6f) {
        out[0] = s + s - a3;
        out[1] = -s - a3;
        return 2;
    }
    th = (1.0f / 3.0f) * atan2_vfpu(sqrt_vfpu(-disc), -r);
    {
        f32 x = s * cos_vfpu(th);
        f32 y = 1.7320508f * (s * sin_vfpu(th));
        out[0] = x + x - a3;
        out[1] = -x - y - a3;
        out[2] = -x + y - a3;
    }
    return 3;
}
