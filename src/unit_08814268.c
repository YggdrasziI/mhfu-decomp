/* unit_08814268: 0x08814268-0x088144B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

extern float *D_08A62C40;
extern void func_08815700(Mtx *, Vec *, Vec *, Vec *);

static inline void vec_sub(Vec *dst, Vec *a, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.q C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline float vec_dot(Vec *a, Vec *b) {
    float r;
    float *pr = &r;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vdot.t S100, C000, C010
        sv.s S100, 0(pr)
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

static inline void vec_scale(Vec *dst, Vec *src, float f) {
    float *pf = &f;
    asm {
        lv.q C000, 0(src)
        lv.s S010, 0(pf)
        vscl.q C000, C000, S010
        sv.q C000, 0(dst)
    }
}

static inline void mtx_inverse(Mtx *src, Mtx *dst) {
    asm {
        lv.q C100, 0(src)
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
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

void func_08814268(char *arg0, Vec *arg1, Vec *arg2, Vec *arg3) {
    Vec d;
    Vec a;
    Vec b;
    float s;

    ((Vec *)(arg0 + 0xB40))->x = arg1->x;
    ((Vec *)(arg0 + 0xB40))->y = arg1->y;
    ((Vec *)(arg0 + 0xB40))->z = arg1->z;
    ((Vec *)(arg0 + 0xB40))->w = arg1->w;
    ((Vec *)(arg0 + 0xB50))->x = arg2->x;
    ((Vec *)(arg0 + 0xB50))->y = arg2->y;
    ((Vec *)(arg0 + 0xB50))->z = arg2->z;
    ((Vec *)(arg0 + 0xB50))->w = arg2->w;
    ((Vec *)(arg0 + 0xB60))->x = arg3->x;
    ((Vec *)(arg0 + 0xB60))->y = arg3->y;
    ((Vec *)(arg0 + 0xB60))->z = arg3->z;
    ((Vec *)(arg0 + 0xB60))->w = arg3->w;
    vec_sub(&d, arg2, arg1);
    *(float *)(arg0 + 0xDB8) = vec_dot(&d, &d);
    *(float *)(arg0 + 0xDB8) = sqrt_vfpu(*(float *)(arg0 + 0xDB8));
    func_08815700((Mtx *)(arg0 + 0xB80), arg1, arg2, arg3);
    s = *D_08A62C40;
    vec_scale(&a, arg1, s);
    vec_scale(&b, arg2, s);
    func_08815700((Mtx *)(arg0 + 0xBC0), &a, &b, arg3);
    mtx_inverse((Mtx *)(arg0 + 0xB80), (Mtx *)(arg0 + 0xC80));
    mtx_inverse((Mtx *)(arg0 + 0xBC0), (Mtx *)(arg0 + 0xC40));
}
