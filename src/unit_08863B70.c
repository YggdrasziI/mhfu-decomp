/* unit_08863B70: 0x08863B70-0x08863D58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;
typedef float f32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

extern void func_0885F8E8(s32 arg0, s32 arg1, s32 arg2, f32 f0, f32 f1);
extern f32 func_08862FE0(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);

static inline void vec_zero(Vec *dst) {
    asm {
        vzero.q C000
        sv.q C000, 0(dst)
    }
}

static inline void mtx_copy(Mtx *dst, Mtx *src) {
    asm {
        lv.q C000, 0(src)
        lv.q C010, 0x10(src)
        lv.q C020, 0x20(src)
        lv.q C030, 0x30(src)
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void vec_set(Vec *dst, float x, float y, float z, float w) {
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

static inline void vec_blend(Vec *b, Vec *a, Vec *dst, float s, float t) {
    float *ps = &s;
    float *pt = &t;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        lv.s S020, 0(ps)
        lv.s S021, 0(pt)
        vscl.q C100, C000, S020
        vscl.q C110, C010, S021
        vadd.q C000, C100, C110
        sv.q C000, 0(dst)
    }
}

static inline void vec_tfm4(Vec *dst, Vec *src, Mtx *mtx) {
    asm {
        lv.q C100, 0(src)
        lv.q C200, 0(mtx)
        lv.q C210, 0x10(mtx)
        lv.q C220, 0x20(mtx)
        lv.q C230, 0x30(mtx)
        vtfm4.q C000, E200, C100
        sv.q C000, 0(dst)
    }
}

void func_08863B70(char *arg0, Vec *out, Mtx *mtx) {
    Vec r;
    Vec a;
    Vec b;
    Mtx m;
    char *p;
    s32 h;
    f32 f;
    f32 g;

    vec_zero(out);
    mtx_copy(&m, mtx);
    vec_zero((Vec *)&m.m[12]);
    h = *(s32 *)(*(char **)(arg0 + 0x110) + 0x14C);
    p = (char *)h + 0x150;
    if (*(s8 *)(arg0 + 0x3E) != 0) {
        func_0885F8E8(h, (s32)&a, 0, *(f32 *)(arg0 + 0x10), *(f32 *)(arg0 + 0x10) + *(f32 *)(arg0 + 0x14));
        f = func_08862FE0(p, *(f32 *)(arg0 + 0x34), 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);
        g = 1.0f - f;
        func_0885F8E8(*(s32 *)(*(char **)(arg0 + 0x110) + 0x14C), (s32)&b, 1, *(f32 *)(arg0 + 0x20), *(f32 *)(arg0 + 0x20) + *(f32 *)(arg0 + 0x14));
        vec_blend(&b, &a, &r, f, g);
        if (*(s8 *)(arg0 + 0x3E) > 0) {
            vec_tfm4(out, &r, &m);
        } else {
            vec_set(out, 0.0f, 0.0f, 0.0f, 1.0f);
        }
    } else {
        func_0885F8E8(h, (s32)&r, 0, *(f32 *)(arg0 + 0x10) - *(f32 *)(arg0 + 0x14), *(f32 *)(arg0 + 0x10));
        vec_tfm4(out, &r, &m);
    }
}
