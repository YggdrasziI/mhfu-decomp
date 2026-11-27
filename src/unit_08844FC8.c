/* unit_08844FC8: 0x08844FC8-0x08845270 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off


typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

extern char *D_089CC438;
extern u8 D_0893ABAC[];
extern u8 D_0893ABAD[];
extern u8 D_0893ABAE[];

extern void func_0882CC9C(char *, s16 *, s32, s32, s32, s32);
extern void func_08845270(char *, s32, s32, s16, s32);

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
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

static inline void rot_z(Mtx *m, float ang) {
    float *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vrot.q C000, S100, [C,S,0,0]
        vrot.q C010, S100, [-S,C,0,0]
        vidt.q C020
        vidt.q C030
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        vmmul.t E200, E100, E000
        lv.q C230, 0x30(m)
        vcst.t R203, 0
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
    }
}

static inline void vec_tfm3(Vec *dst, Mtx *mtx, Vec *src) {
    asm {
        lv.q C100, 0(src)
        lv.q C200, 0(mtx)
        lv.q C210, 0x10(mtx)
        lv.q C220, 0x20(mtx)
        vmov.s S003, S103
        vtfm3.t C000, E200, C100
        sv.q C000, 0(dst)
    }
}

void func_08844FC8(char *arg0, u16 a, f32 x, f32 y, f32 z, s32 idx) {
    s16 pts[8];
    Mtx m;
    Vec v;
    s32 i;
    s32 h;
    s32 k;
    f32 s;
    f32 t;
    f32 r;

    r = 6.2831855f * (360.0f * (f32)(u16)(0x18000 - a) / 65536.0f / 360.0f);
    s = 5.0f * z;
    t = 6.0f * z;
    mtx_identity(&m);
    vec_set(&v.x, 0.0f, 0.0f, 0.0f, 0.0f);
    rot_z(&m, r);
    for (i = 0; i < 4; i++) {
        v.x = -s + 2.0f * s * (f32)(i / 2);
        v.y = -t + 2.0f * t * (f32)(i & 1);
        vec_tfm3(&v, &m, &v);
        pts[i * 2] = (s32)(x + v.x);
        pts[i * 2 + 1] = (s32)(y + v.y);
    }
    h = (idx == *(u8 *)(D_089CC438 + 0x28)) ? 0x92 : 0x97;
    k = (idx & 3) * 4;
    func_0882CC9C(arg0, pts, D_0893ABAC[k], D_0893ABAD[k], D_0893ABAE[k], h);
    if (*(s16 *)((char *)(idx * 2) + (s32)arg0 + 0x56C) >= 0) {
        func_08845270(arg0, (s32)x, (s32)y, *(s16 *)((char *)(idx * 2) + (s32)arg0 + 0x56C), *(s32 *)&D_0893ABAC[k]);
    }
}
