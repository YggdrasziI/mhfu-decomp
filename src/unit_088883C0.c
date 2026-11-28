/* unit_088883C0: 0x088883C0-0x08888B84 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088883C0: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks").
 * Updates the structure at arg0 + 0xA0 (two vectors and three halfword
 * angles) from the state at D_089CBBE4, rotates two offsets by the angles,
 * clips the result against func_09C3AAA8 and func_0888E5B8 and copies it to
 * arg0 (hypothesis: a camera). */
#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct {
    s32 x, y, z;
} __attribute__((aligned(16))) Ang;

extern char *D_089CBBE4;
extern char *D_09D1A060;
extern Vec D_08933AC0;
extern Vec D_08933AD0;

extern f32 func_0888E3DC(char *arg0);
extern f32 func_0888E5B8(char *arg0, char *arg1, char *arg2);
extern s32 func_09C3AAA8(char *arg0, f32 *arg1, char *arg2, Vec *arg3, s32 arg4, f32 arg5);

static inline void vec_copy(Vec *src, Vec *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void vec_copy2(Vec *dst, Vec *src) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void vec_add3(Vec *a, Vec *b, Vec *dst) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vadd.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_blend(Vec *b, Vec *dst, float s, float t) {
    float *ps = &s;
    float *pt = &t;
    asm {
        lv.q C000, 0(dst)
        lv.q C010, 0(b)
        lv.s S020, 0(ps)
        lv.s S021, 0(pt)
        vscl.t C100, C000, S020
        vscl.t C110, C010, S021
        vadd.t C000, C100, C110
        sv.q C000, 0(dst)
    }
}

static inline void xform3(float *mtx, Vec *src, Vec *dst) {
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

static inline void mtx_identity(float *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void mtx_rot_xyz(float *m, float x, float y, float z) {
    float *px = &x;
    float *py = &y;
    float *pz = &z;
    asm {
        lv.q C000, 0(m)
        lv.q C010, 0x10(m)
        lv.q C020, 0x20(m)
        lv.q C030, 0x30(m)
        lv.s S100, 0(px)
        lv.s S101, 0(py)
        lv.s S102, 0(pz)
        vcst.s S103, VFPU_2_PI
        vscl.t C130, C100, S103
        vsin.t C110, C130
        vcos.t C120, C130
        vmul.s S000, S122, S121
        vmul.s S130, S112, S120
        vmul.s S010, S111, S122
        vmul.s S010, S010, S110
        nop
        vsub.s S010, S010, S130
        vmul.s S020, S110, S112
        vmul.s S131, S111, S122
        vmul.s S131, S131, S120
        vadd.s S020, S020, S131
        vmul.s S001, S112, S121
        vmul.s S011, S122, S120
        vmul.s S131, S111, S112
        vmul.s S131, S131, S110
        vadd.s S011, S011, S131
        vmul.s S130, S110, S122
        vmul.s S021, S111, S112
        vmul.s S021, S021, S120
        nop
        vsub.s S021, S021, S130
        vneg.s S002, S111
        vmul.s S012, S110, S121
        vmul.s S022, S121, S120
        sv.q C000, 0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
}

void func_088883C0(u8 *arg0) {
    Vec pos;
    float mtx[16] __attribute__((aligned(16)));
    Vec v;
    Vec ofs0;
    Vec ofs1;
    Ang ang;
    Vec hit;
    Vec q1;
    Vec q0;
    Vec p;
    Vec n;
    Vec d;
    Vec r0;
    Vec r1;
    u8 *g;
    char *s3;
    char *s1;
    char *s0;
    char *cam;
    char *q;
    f32 h;
    f32 t;
    f32 u;
    f32 y;
    f32 num;
    f32 den;
    u32 diff;
    s16 a;

    g = (u8 *)D_089CBBE4;
    cam = (char *)arg0 + 0xA0;
    s1 = (char *)g + 0xB0;
    s3 = *(char **)(g + 0xA84);
    s0 = s1 + 0xA0;
    if (g[0x141] == 0) {
        arg0[0x91] = 0;
        *(s32 *)(arg0 + 0x98) = 0;
        return;
    }
    switch ((u8)arg0[0x98]) {
    case 0:
        if ((u8)s0[0x8F] == 0) {
            arg0[0x91] = 0;
            *(s32 *)(arg0 + 0x98) = 0;
            return;
        }
        vec_copy((Vec *)s1, (Vec *)(cam + 0x20));
        *(s16 *)(cam + 0x30) = ((s8)s3[0x67E] + 100) * 34 - 0xB00;
        *(s16 *)(cam + 0x34) = 0x800;
        *(s16 *)(cam + 0x32) = 0;
        arg0[0x98]++;
        arg0[0x9C] = 1;
        *(s16 *)(arg0 + 0x94) = 9;
        *(f32 *)(arg0 + 0x190) = 1.0f / *(s16 *)(arg0 + 0x94);
        break;
    case 1:
        *(s16 *)(cam + 0x30) += (s16)((s16)(((s8)s3[0x67E] + 100) * 34 - 0xB00 - *(s16 *)(cam + 0x30)) >> 2);
        if ((u8)s0[0x8F] == 0) {
            arg0[0x91] = 0;
            *(s32 *)(arg0 + 0x98) = 0;
            return;
        }
        break;
    }
    arg0[0x91] = 1;
    g[0xA8D] = 1;
    g[0xA88] = 0;

    diff = (u16)((*(s32 *)(s3 + 0x1F4) ^ 0x8000) - (*(s16 *)(s0 + 0x82) + *(s16 *)(cam + 0x32)));
    if (diff > 0x100 && diff < 0x7800) {
        *(s16 *)(cam + 0x34) = -0x800;
    } else if (diff > 0x8800 && diff < 0xFF00) {
        *(s16 *)(cam + 0x34) = 0x800;
    }
    if (*(s16 *)(cam + 0x34) < 0) {
        a = *(s16 *)(cam + 0x32);
        if (a > -0x800) {
            *(s16 *)(cam + 0x32) = a + (s16)(((s16)(-0x800 - a) * 6) >> 6);
        }
    } else {
        a = *(s16 *)(cam + 0x32);
        if (a < 0x800) {
            *(s16 *)(cam + 0x32) = a + (s16)(((s16)(0x800 - a) * 6) >> 6);
        }
    }

    switch ((u8)arg0[0x9C]) {
    case 0:
        vec_copy(&D_08933AC0, &ofs0);
        vec_copy(&D_08933AD0, &ofs1);
        h = 170.0f;
        break;
    case 1:
        arg0[0x9C]++;
    case 2:
        t = func_0888E3DC((char *)arg0);
        q = *(char **)(s0 + 0x70);
        u = 1.0f - t;
        ofs0.x = 0.0f;
        ofs0.y = 0.0f;
        ofs0.z = *(f32 *)(q + 8);
        vec_blend(&D_08933AC0, &ofs0, t, u);
        ofs1.z = 0.0f;
        ofs1.y = 0.0f;
        ofs1.x = 0.0f;
        vec_blend(&D_08933AD0, &ofs1, t, u);
        h = 170.0f * u + *(f32 *)(q + 0x10) * t;
        break;
    }

    *(f32 *)(cam + 0x10) = pos.x = *(f32 *)(s3 + 0x200);
    *(f32 *)(cam + 0x14) = pos.y = *(f32 *)(s3 + 0x204) + h;
    *(f32 *)(cam + 0x18) = pos.z = *(f32 *)(s3 + 0x208);

    ang.x = *(s16 *)(cam + 0x30);
    ang.y = *(s16 *)(s0 + 0x82) + *(s16 *)(cam + 0x32);
    ang.z = 0;
    r0.x = 9.58738e-05f * (f32)(ang.x & 0xFFFF);
    r0.y = 9.58738e-05f * (f32)(ang.y & 0xFFFF);
    r0.z = 9.58738e-05f * (f32)(ang.z & 0xFFFF);
    r0.w = 0.0f;
    mtx_identity(mtx);
    mtx_rot_xyz(mtx, r0.x, r0.y, r0.z);
    xform3(mtx, &ofs0, &v);
    vec_add3((Vec *)(cam + 0x10), &v, (Vec *)cam);
    if (func_09C3AAA8(D_09D1A060, &pos.x, cam, &hit, 0x8009, 28.0f) != 0) {
        vec_copy(&hit, (Vec *)cam);
    }
    y = func_0888E5B8((char *)arg0, cam, s3);
    y += *(f32 *)(*(char **)(s0 + 0x70) + 0x18);
    if (y > *(f32 *)(cam + 4)) {
        *(f32 *)(cam + 4) = y;
    }

    /* Same rotation with the angle offset removed. The temporaries set the
     * register allocation of the original. */
    {
        f32 fx;
        f32 kk;
        ang.y = *(s16 *)(s0 + 0x82);
        fx = (f32)(ang.x & 0xFFFF);
        kk = 9.58738e-05f;
        r1.w = 0.0f;
        r1.x = kk * fx;
        r1.y = kk * (f32)(ang.y & 0xFFFF);
        r1.z = kk * (f32)(ang.z & 0xFFFF);
    }
    mtx_identity(mtx);
    mtx_rot_xyz(mtx, r1.x, r1.y, r1.z);
    xform3(mtx, &ofs1, &v);

    p.x = *(f32 *)(cam + 0x10);
    p.y = 0.0f;
    p.z = *(f32 *)(cam + 0x18);
    n.x = v.x;
    n.y = 0.0f;
    n.z = v.z;
    vec_copy((Vec *)cam, &q0);
    vec_add3((Vec *)(cam + 0x10), &v, &q1);
    num = n.x * (p.x - q1.x) + n.y * (p.y - q1.y) + n.z * (p.z - q1.z);
    d.x = q1.x - q0.x;
    d.y = q1.y - q0.y;
    d.z = q1.z - q0.z;
    den = d.x * n.x + d.y * n.y + d.z * n.z;
    if (den != 0.0f) {
        t = num / den;
        q1.x = q1.x + d.x * t;
        q1.y = q1.y + d.y * t;
        q1.z = q1.z + d.z * t;
    }
    vec_copy2((Vec *)(cam + 0x10), &q1);
    *(f32 *)(arg0 + 0x80) = *(f32 *)(s1 + 0x80);
    *(f32 *)(arg0 + 0x88) = *(f32 *)(s1 + 0x88);
    vec_copy((Vec *)cam, (Vec *)arg0);
    vec_copy((Vec *)(cam + 0x10), (Vec *)(arg0 + 0x10));
}
