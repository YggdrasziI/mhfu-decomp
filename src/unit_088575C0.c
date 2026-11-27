/* unit_088575C0: 0x088575C0-0x088576BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern char *func_088DCEBC(s32, u8);

static inline void vec_sub3(Vec *b, Vec *a, Vec *dst) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_normalize(Vec *dst, Vec *src) {
    asm {
        lv.q C000, 0(src)
        vdot.q S010, C000, C000
        vzero.s S011
        vcmp.s ez, S010, S010
        nop
        vrsq.s S010, S010
        vcmovt.s S010, S011, 0
        vpfxd [-1:1],[-1:1],[-1:1],[-1:1]
        vscl.q C000, C000, S010
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

float func_088575C0(s32 arg0, Vec *arg1, Vec *arg2) {
    Vec a;
    Vec b;
    Vec dir;
    Vec na;
    Vec diff;
    char *obj;

    a = *arg1;
    b = *arg2;
    obj = func_088DCEBC(D_09A4F0C4, D_089CC438[0x28]);
    vec_sub3(&b, (Vec *)(obj + 0x200), &diff);
    vec_normalize(&dir, &diff);
    vec_normalize(&na, &a);
    return vec_dot(&dir, &na);
}
