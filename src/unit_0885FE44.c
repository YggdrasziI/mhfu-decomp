/* unit_0885FE44: 0x0885FE44-0x0885FF5C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

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

static inline void vec_cross(Vec *dst, Vec *a, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vzero.s S023
        vcrsp.t C020, C000, C010
        sv.q C020, 0(dst)
    }
}

void func_0885FE44(float *arg0, Vec *arg1, Vec *arg2) {
    Vec a;
    Vec d;
    Vec c;
    Vec b;

    vec_normalize(&a, arg1);
    vec_normalize(&b, arg2);
    vec_cross(&c, &a, &b);
    vec_normalize(&c, &c);
    vec_cross(&d, &c, &a);
    arg0[3] = 0.0f;
    arg0[7] = 0.0f;
    arg0[11] = 0.0f;
    arg0[15] = 1.0f;
    arg0[0] = a.x;
    arg0[1] = a.y;
    arg0[2] = a.z;
    arg0[4] = d.x;
    arg0[5] = d.y;
    arg0[6] = d.z;
    arg0[8] = c.x;
    arg0[9] = c.y;
    arg0[10] = c.z;
}
