/* unit_088C75D4: 0x088C75D4-0x088C7764 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

#pragma optimize_for_size off
typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern void func_08897BD8(Vec *, Vec *, Vec *);
extern f32 func_09C35790(Vec *, Vec *, Vec *, f32 *);

static inline void vec_sub(Vec *a, Vec *b, Vec *dst) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.q C000, C000, C010
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

static inline void vec_scale(Vec *dst, Vec *src, f32 s) {
    f32 *ps = &s;
    asm {
        lv.q C000, 0(src)
        lv.s S010, 0(ps)
        vscl.q C000, C000, S010
        sv.q C000, 0(dst)
    }
}

f32 func_088C75D4(void *self, f32 *arg1, Vec *a, Vec *b, f32 scale) {
    f32 d[4];
    Vec out;
    Vec dir;
    Vec n;
    Vec v40;
    Vec v30;
    Vec v20;
    Vec v10;
    s32 i;

    vec_sub(a, b, &dir);
    vec_normalize(&dir, &dir);
    n.x = -dir.z;
    n.y = dir.y;
    n.z = dir.x;
    n.w = 0.0f;
    vec_scale(&n, &n, scale);
    func_08897BD8(&v10, a, &n);
    vec_sub(a, &n, &v20);
    func_08897BD8(&v30, b, &n);
    vec_sub(b, &n, &v40);
    d[0] = func_09C35790(&out, &v10, &v20, arg1);
    d[1] = func_09C35790(&out, &v30, &v40, arg1);
    d[2] = func_09C35790(&out, &v10, &v30, arg1);
    d[3] = func_09C35790(&out, &v20, &v40, arg1);
    for (i = 1; i <= 3; i++) {
        if (d[0] > d[i]) {
            d[0] = d[i];
        }
    }
    return d[0];
}
