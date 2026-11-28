/* unit_088C96F8: 0x088C96F8-0x088C9834 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Vec {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Mtx {
    f32 m[16];
} __attribute__((aligned(16))) Mtx;

extern s32 func_0886171C(char *, s32, char *, s32);
extern s32 func_08862354(char *, char *);

static inline f32 sin_vfpu(f32 x) {
    f32 r;
    f32 *pr = &r;
    f32 *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

static inline void vec_scale(Vec *src, Vec *dst, f32 f) {
    f32 *pf = &f;
    asm {
        lv.q C000, 0(src)
        lv.s S010, 0(pf)
        vscl.t C000, C000, S010
        sv.q C000, 0(dst)
    }
}

static inline void vec_add(Vec *dst, Vec *a, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vadd.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void mtx_identity(Mtx *m) {
    asm {
        vmidt.q E000
        sv.q C000, 0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
}

void func_088C96F8(char *arg0, char *arg1, u16 *arg2, s32 arg3) {
    Vec v;
    Mtx m;
    f32 s;

    s = sin_vfpu(6.2830896f * ((f32)(*(u16 *)(arg0 + 0x1C0) % *arg2) / (f32)(u32)*arg2));
    vec_scale((Vec *)(arg2 + 0x10), &v, s);
    vec_add(&v, &v, (Vec *)(arg2 + 8));
    {
        f32 z = v.z;
        f32 y = v.y;
        f32 x = v.x;
        mtx_identity(&m);
        m.m[12] = x;
        m.m[13] = y;
        m.m[14] = z;
    }
    func_08862354((char *)&m, arg1 + 0x10);
    func_0886171C(arg1, 0, arg0 + 0x70, arg3);
    func_08862354(arg0 + 0x10, arg1 + 0x10);
}
