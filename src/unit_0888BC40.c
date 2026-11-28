/* unit_0888BC40: 0x0888BC40-0x0888C294 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

/* func_0888BC40: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct {
    f32 re, im;
} Root;

extern f32 func_0888E1F8(void *arg0, f32 *a, f32 *b);
extern f32 func_0888E1C8(void *arg0, f32 *a, f32 *b);
extern s32 func_0888DD14(void *arg0, f32 *out, f32 *coef);
extern void func_0888DA60(void *arg0, Root *roots, f32 *coef);

static inline void vcopy(Vec *dst, f32 *src) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void vsub(f32 *a, Vec *b, Vec *dst) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.q C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline f32 vfabs(f32 x) {
    f32 r;
    f32 *pr = &r;
    f32 *px = &x;
    asm {
        lv.s S000, 0(px)
        vabs.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

static inline f32 len2(f32 *v) {
    f32 r;
    r = v[2] * v[2] + (v[0] * v[0] + v[1] * v[1]);
    return r;
}

s32 func_0888BC40(void *arg0, f32 *out, f32 *m, f32 *pos, s32 flag) {
    f32 coef[6];
    Vec p;
    s32 i;
    s32 n;

    vcopy(&p, pos);
    if (flag == 0) {
        Root roots[5];
        Vec d;

        p.y = 0.0f;
        vsub(m + 12, &p, &d);
        if (!(len2(m) > 1e-9f)) {
            if (!(len2(m + 4) > 1e-9f)) {
                if (!(len2(m + 8) > 1e-9f)) {
                    return 0;
                } else {
                    f32 a = func_0888E1F8(arg0, m + 8, m + 8);
                    *out = -(func_0888E1F8(arg0, m + 8, (f32 *)&d) / a);
                    return 1;
                }
            } else {
                coef[0] = 2.0f * func_0888E1F8(arg0, m + 4, m + 4);
                coef[1] = 3.0f * func_0888E1F8(arg0, m + 4, m + 8);
                coef[2] = 2.0f * func_0888E1F8(arg0, m + 4, (f32 *)&d) + func_0888E1F8(arg0, m + 8, m + 8);
                coef[3] = func_0888E1F8(arg0, m + 8, (f32 *)&d);
                return func_0888DD14(arg0, out, coef);
            }
        } else {
            coef[0] = 3.0f * func_0888E1F8(arg0, m, m);
            coef[1] = 5.0f * func_0888E1F8(arg0, m, m + 4);
            coef[2] = 4.0f * func_0888E1F8(arg0, m, m + 8) + 2.0f * func_0888E1F8(arg0, m + 4, m + 4);
            coef[3] = 3.0f * (func_0888E1F8(arg0, m, (f32 *)&d) + func_0888E1F8(arg0, m + 4, m + 8));
            coef[4] = 2.0f * func_0888E1F8(arg0, m + 4, (f32 *)&d) + func_0888E1F8(arg0, m + 8, m + 8);
            coef[5] = func_0888E1F8(arg0, m + 8, (f32 *)&d);
            func_0888DA60(arg0, roots, coef);
            n = 0;
            for (i = 0; i < 5; i++) {
                if (vfabs(roots[i].im) < 0.001f) {
                    out[n++] = roots[i].re;
                }
            }
            return n;
        }
    } else {
        Root roots[5];
        Vec d;

        vsub(m + 12, &p, &d);
        if (!(len2(m) > 1e-9f)) {
            if (!(len2(m + 4) > 1e-9f)) {
                if (!(len2(m + 8) > 1e-9f)) {
                    return 0;
                } else {
                    f32 a = func_0888E1C8(arg0, m + 8, m + 8);
                    *out = -(func_0888E1C8(arg0, m + 8, (f32 *)&d) / a);
                    return 1;
                }
            } else {
                coef[0] = 2.0f * func_0888E1C8(arg0, m + 4, m + 4);
                coef[1] = 3.0f * func_0888E1C8(arg0, m + 4, m + 8);
                coef[2] = 2.0f * func_0888E1C8(arg0, m + 4, (f32 *)&d) + func_0888E1C8(arg0, m + 8, m + 8);
                coef[3] = func_0888E1C8(arg0, m + 8, (f32 *)&d);
                return func_0888DD14(arg0, out, coef);
            }
        } else {
            coef[0] = 3.0f * func_0888E1C8(arg0, m, m);
            coef[1] = 5.0f * func_0888E1C8(arg0, m, m + 4);
            coef[2] = 4.0f * func_0888E1C8(arg0, m, m + 8) + 2.0f * func_0888E1C8(arg0, m + 4, m + 4);
            coef[3] = 3.0f * (func_0888E1C8(arg0, m, (f32 *)&d) + func_0888E1C8(arg0, m + 4, m + 8));
            coef[4] = 2.0f * func_0888E1C8(arg0, m + 4, (f32 *)&d) + func_0888E1C8(arg0, m + 8, m + 8);
            coef[5] = func_0888E1C8(arg0, m + 8, (f32 *)&d);
            func_0888DA60(arg0, roots, coef);
            n = 0;
            for (i = 0; i < 5; i++) {
                if (vfabs(roots[i].im) < 0.001f) {
                    out[n++] = roots[i].re;
                }
            }
            return n;
        }
    }
}
