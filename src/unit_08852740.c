/* unit_08852740: 0x08852740-0x08852834 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08852740 */
#pragma optimize_for_size off

typedef int s32;

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern char *D_089CBBE4;

static inline void vec_sub3(Vec *dst, Vec *a, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_copy(Vec *dst, Vec *src) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void vec_cross(Vec *dst, Vec *a, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vzero.s S023
        vcrsp.t C020, C000, C010
        sv.q C020, 0(dst)
    }
}

static inline void vec_normalize(Vec *dst, Vec *src) {
    asm {
        lv.q C000, 0(src)
        vdot.t S010, C000, C000
        vzero.s S011
        vcmp.s ez, S010, S010
        nop
        vrsq.s S010, S010
        vcmovt.s S010, S011, 0
        vpfxd [-1:1],[-1:1],[-1:1],[-1:1]
        vscl.t C000, C000, S010
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

void func_08852740(s32 arg0, Vec *arg1, Vec *arg2) {
    Vec diff;
    Vec up;
    Vec n;
    Vec s;

    { Vec *base = (Vec *)(D_089CBBE4 + 0xC80); vec_sub3(&diff, base + 3, arg2); }
    vec_copy(&up, arg1 + 2);
    vec_cross(&n, &diff, &up);
    vec_normalize(&n, &n);
    vec_cross(&s, &up, &n);
    if (vec_dot(&s, &s) > 0.0001f) {
        vec_cross(&n, &s, &up);
        vec_copy(arg1, &n);
        vec_copy(arg1 + 1, &s);
    }
}
