/* unit_08852834: 0x08852834-0x08852954 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08852834: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern void func_08852740(s32, Vec *, Vec *);

static inline void vec_len_o(Vec *v, float *pr) {
    asm {
        lv.q C000, 0(v)
        vdot.t S010, C000, C000
        vsqrt.s S010, S010
        sv.s S010, 0(pr)
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

void func_08852834(s32 arg0, Vec *m, Vec *arg2) {
    float t0, t1, t2;
    Vec s;
    vec_len_o(&m[0], &t0);
    s.x = t0;
    vec_len_o(&m[1], &t1);
    s.y = t1;
    vec_len_o(&m[2], &t2);
    s.z = t2;
    vec_normalize(&m[2], &m[2]);
    func_08852740(arg0, m, arg2);
    m[0].x *= s.x;
    m[0].y *= s.x;
    m[0].z *= s.x;
    m[1].x *= s.y;
    m[1].y *= s.y;
    m[1].z *= s.y;
    m[2].x *= s.z;
    m[2].y *= s.z;
    m[2].z *= s.z;
}
