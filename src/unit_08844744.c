/* unit_08844744: 0x08844744-0x08844A78 (ULES01213)
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

typedef struct {
    u8 r, g, b, a;
} B4;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

extern u8 D_0893914C[];
extern s32 D_0893B614[];
extern s16 D_0893B620[];

extern s32 func_08844A78(char *, char *);
extern void func_0884424C(char *, s32, f32, f32, f32);
extern s32 func_08844EA0(char *, char *);
extern void func_0882CC9C(char *, s16 *, s32, s32, s32, s32);

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
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

void func_08844744(char *arg0, char *arg1, f32 x, f32 y, f32 z) {
    s16 pts[8];
    B4 c;
    Mtx m;
    Vec v;
    u8 k;
    u32 ang;
    s16 h;
    s16 i;
    f32 s;
    f32 w;

    k = D_0893914C[*(u8 *)(arg1 + 0x1E8)];
    if (k == 0xFF) {
        return;
    }
    if (k & 0x80) {
        if (k & 0x40) {
            w = 4.0f * z;
            *(s32 *)&c = func_08844A78(arg0, arg1);
        } else {
            w = 2.0f;
            *(s32 *)&c = D_0893B614[k & 0xF];
        }
        func_0884424C(arg0, *(s32 *)&c, x, y, w);
        return;
    }
    if ((u8)func_08844EA0(arg0, arg1) == 1) {
        return;
    }
    if (*(u8 *)(arg0 + 0x5E7) < 2) {
        z *= 0.8f;
        k = 7;
        ang = 0;
    } else {
        if (*(u8 *)(arg1 + 0x280) != 2) {
            k |= 8;
        }
        ang = (u16)(0x18000 - *(s32 *)(arg1 + 0x1F4));
    }
    h = D_0893B620[k];
    mtx_identity(&m);
    rot_z(&m, 6.2831855f * (360.0f * (f32)ang / 65536.0f / 360.0f));
    s = 6.0f * z;
    v.z = 0.0f;
    for (i = 0; i < 4; i++) {
        v.x = -s + 2.0f * s * (f32)(i / 2);
        v.y = -s + 2.0f * s * (f32)(i & 1);
        vec_tfm3(&v, &m, &v);
        pts[i * 2] = (s32)(0.5f + (v.x + x));
        pts[i * 2 + 1] = (s32)(0.5f + (v.y + y));
    }
    *(s32 *)&c = func_08844A78(arg0, arg1);
    func_0882CC9C(arg0, pts, c.b, c.g, c.r, h);
}
