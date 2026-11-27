/* unit_08815E28: 0x08815E28-0x08815E9C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

static inline void vec_sub(Vec *dst, Vec *a, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.q C000, C000, C010
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

void func_08815E28(s32 arg0, Vec *out, Vec *a, Vec *b, Vec *c) {
    Vec d1;
    Vec d2;
    Vec n;
    vec_sub(&d1, b, a);
    vec_sub(&d2, c, a);
    vec_cross(&n, &d1, &d2);
    vec_normalize(out, &n);
}
