/* unit_08815700: 0x08815700-0x088158D8 (ULES01213)
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

static inline void vec_sub4(Vec *dst, Vec *a, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.q C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_copy(float *dst, Vec *src) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
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

static inline void vec_cross(Vec *dst, Vec *a, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vzero.s S023
        vcrsp.t C020, C000, C010
        sv.q C020, 0(dst)
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

static inline void vec_set(float *dst, float x, float y, float z, float w) {
    float *px = &x;
    float *py = &y;
    float *pz = &z;
    float *pw = &w;
    asm {
        lv.s S000, 0(px)
        lv.s S001, 0(py)
        lv.s S002, 0(pz)
        lv.s S003, 0(pw)
        sv.q C000, 0(dst)
    }
}

static inline void mtx_transpose(Mtx *m) {
    asm {
        lv.q C000, 0(m)
        lv.q C010, 0x10(m)
        lv.q C020, 0x20(m)
        lv.q C030, 0x30(m)
        sv.q R000, 0(m)
        sv.q R001, 0x10(m)
        sv.q R002, 0x20(m)
        sv.q R003, 0x30(m)
    }
}

void func_08815700(Mtx *arg0, Vec *arg1, Vec *arg2, Vec *arg3) {
    Vec side;
    Vec newup;
    Vec fwd;
    Vec up;

    vec_sub4(&fwd, arg1, arg2);
    vec_copy((float *)&up, arg3);
    vec_normalize(&fwd, &fwd);
    vec_normalize(&up, &up);
    vec_cross(&side, &up, &fwd);
    vec_normalize(&side, &side);
    vec_cross(&newup, &fwd, &side);
    vec_copy(arg0->m, &side);
    vec_copy(arg0->m + 4, &newup);
    vec_copy(arg0->m + 8, &fwd);
    vec_set(arg0->m + 12, 0.0f, 0.0f, 0.0f, 0.0f);
    mtx_transpose(arg0);
    vec_set(arg0->m + 12, -vec_dot(arg1, &side), -vec_dot(arg1, &newup),
            -vec_dot(arg1, &fwd), 1.0f);
}
