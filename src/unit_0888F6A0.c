/* unit_0888F6A0: 0x0888F6A0-0x0888FACC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0888F6A0: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks").
 * Speed setting. The scale is written `k = 136.0f; k *= c;` so that the
 * constant is built once in v1 after the calls (also stored to a.z) with
 * the original mul.s operand order; the negation sits at each use. */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef struct Vec {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Mtx {
    f32 m[16];
} __attribute__((aligned(16))) Mtx;

typedef struct {
    Vec pos;
    Vec tgt;
    Vec up;
    Vec dir;
    char pad40[0x40];
    f32 f80;
    f32 f84;
    f32 f88;
} Obj;

extern s32 func_0888FACC(Obj *, Vec *);
extern void func_08815D84(Vec *, Vec *, Vec *, float);
extern void func_08815700(Mtx *, Vec *, Vec *, Vec *);
extern float func_08897C50(float);
extern float func_08897BF4(float);
extern void func_08897DE0(Vec *out, Vec *v, float);
extern void func_08897D7C(Mtx *out, Vec *q);

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

static inline void vec_sub3(Vec *a, Vec *b, Vec *dst) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_add3(Vec *a, Vec *b, Vec *dst) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vadd.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_copy(Vec *src, Vec *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void mtx_inverse(Mtx *src, Mtx *dst) {
    asm {
        lv.q C100, 0x0(src)
        lv.q C110, 0x10(src)
        lv.q C120, 0x20(src)
        lv.q C130, 0x30(src)
        vmidt.q E000
        vmidt.q E200
        vdot.t S300, C100, C100
        vsqrt.s S300, S300
        vdot.t S301, C110, C110
        vsqrt.s S301, S301
        vdot.t S302, C120, C120
        vsqrt.s S302, S302
        vdiv.t C200, R100, C300
        vdiv.t C210, R101, C300
        vdiv.t C220, R102, C300
        vneg.t C310, C130
        vmul.t C320, R200, C310
        vfad.t S230, C320
        vmul.t C320, R201, C310
        vfad.t S231, C320
        vmul.t C320, R202, C310
        vfad.t S232, C320
        vdiv.t C000, C200, C300
        vdiv.t C010, C210, C300
        vdiv.t C020, C220, C300
        vdiv.t C030, C230, C300
        sv.q C000, 0x0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void mtx_apply3(Mtx *m, Vec *v, Vec *dst) {
    asm {
        lv.q C100, 0(v)
        lv.q C200, 0x0(m)
        lv.q C210, 0x10(m)
        lv.q C220, 0x20(m)
        vmov.s S003, S103
        vtfm3.t C000, E200, C100
        sv.q C000, 0(dst)
    }
}

static inline void vec_normalize(Vec *v) {
    asm {
        lv.q C000, 0(v)
        vdot.q S010, C000, C000
        vzero.s S011
        vcmp.s ez, S010, S010
        nop
        vrsq.s S010, S010
        vcmovt.s S010, S011, 0
        vpfxd [-1:1],[-1:1],[-1:1],[-1:1]
        vscl.q C000, C000, S010
        sv.q C000, 0(v)
    }
}

static inline void vec_dot3_o(Vec *a, Vec *b, float *pr) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vdot.t S100, C000, C010
        sv.s S100, 0(pr)
    }
}

static inline float vec_dot3(Vec *a, Vec *b) {
    float r;
    vec_dot3_o(a, b, &r);
    return r;
}

static inline void vec_cross(Vec *a, Vec *b, Vec *dst) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vzero.s S023
        vcrsp.t C020, C000, C010
        sv.q C020, 0(dst)
    }
}

void func_0888F6A0(Obj *arg0) {
    Mtx m;
    Mtx inv;
    Vec tgt;
    Vec pos;
    Vec a;
    Vec b;
    Vec axis;
    Vec d;
    Vec q;
    float s;
    float k;
    float c;
    float da;
    float db;

    vec_sub3(&arg0->tgt, &arg0->pos, &arg0->dir);
    if ((u8)func_0888FACC(arg0, &tgt) != 1) {
        return;
    }
    func_08815D84(&arg0->up, &arg0->pos, &arg0->tgt, arg0->f80);
    func_08815700(&m, &arg0->pos, &arg0->tgt, &arg0->up);
    mtx_inverse(&m, &inv);
    s = func_08897C50(0.5f * arg0->f88);
    c = func_08897BF4(0.5f * arg0->f88) / s;
    k = 136.0f;
    k *= c;
    vec_copy(&arg0->pos, &pos);
    a.z = 136.0f;
    a.x = 0.0f;
    a.y = -k;
    a.w = 0.0f;
    mtx_apply3(&inv, &a, &a);
    vec_normalize(&a);
    b.z = -k;
    b.x = 0.0f;
    b.w = 0.0f;
    b.y = -136.0f;
    mtx_apply3(&inv, &b, &b);
    vec_normalize(&b);
    vec_sub3(&tgt, &pos, &d);
    da = vec_dot3(&d, &a);
    if (!(da > 0.0f)) {
        return;
    }
    db = vec_dot3(&d, &b);
    vec_cross(&b, &a, &axis);
    func_08897DE0(&q, &axis, atan2_vfpu(da, db));
    func_08897D7C(&m, &q);
    mtx_apply3(&m, &arg0->dir, &axis);
    vec_add3(&arg0->pos, &axis, &arg0->tgt);
}
