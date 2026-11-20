/* unit_088D852C: 0x088D852C-0x088D88F0 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088D852C asm piece, 2 functions
 * between unit_088D81FC and unit_088D88F0.
 *
 * Both rotate an offset about the Y axis by a 16-bit angle (65536 units per
 * turn). func_088D852C puts `arg2` in front of the object (angle at
 * +0x1F4), asks func_09C3F640 for a height there and compares it with the
 * object's height (+0x204) plus `arg3`: below when `arg1` is 0, above
 * otherwise. func_088D8740 adds the rotated per-object offset of
 * D_089B64D0 to `arg1`.
 *
 * C++: the helpers are inline functions. Optimized for speed (float
 * constant as `lui` / `ori`). The matrix and vector operations are VFPU
 * `asm` blocks (notes/COMPILER.md, "VFPU in asm blocks").
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct IVec {
    s32 x, y, z, w;
} __attribute__((aligned(16))) IVec;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

/* The two floats of a record are reached through two symbols. */
typedef struct Ofs {
    float unk0;
    float unk4;
} Ofs;

extern "C" {

extern char *D_09D1A060;
extern Ofs D_089B64D0[];
extern Ofs D_089B64D4[];

extern s32 func_09C3F640(char *, char *, Vec *, float *);

#define ANG_TO_RAD(a) (9.58738e-05f * ((a) & 0xFFFF))

/* Rotates and scales `src` by the upper 3x3 part of `mtx`. */
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

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

/* Rotation matrix from three angles (radians), written over `m`. */
static inline void mtx_euler(Mtx *m, float x, float y, float z) {
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

static inline void vec3_add(float *dst, float *a, Vec *b) {
    float x = b->x;
    float y = b->y;
    float z = b->z;
    dst[0] = a[0] + x;
    dst[1] = a[1] + y;
    dst[2] = a[2] + z;
}

static inline void vec_set4(Vec *dst, float x, float y, float z, float w) {
    dst->x = x;
    dst->y = y;
    dst->z = z;
    dst->w = w;
}

s32 func_088D852C(char *arg0, u16 arg1, float arg2, float arg3) {
    Vec v;
    Vec out;
    IVec ang;
    Mtx m;
    Vec rot;
    float res;
    float lim;
    s32 r;

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = arg2;
    v.w = 0.0f;
    ang.x = 0;
    ang.y = *(s32 *)(arg0 + 0x1F4);
    ang.z = 0;
    ang.w = 0;
    vec_set4(&rot, ANG_TO_RAD(ang.x), ANG_TO_RAD(ang.y), ANG_TO_RAD(ang.z), 0.0f);
    mtx_identity(&m);
    mtx_euler(&m, rot.x, rot.y, rot.z);
    vec_tfm3(&out, &m, &v);
    vec3_add(&v.x, (float *)(arg0 + 0x200), &out);
    lim = *(float *)(arg0 + 0x204) + arg3;
    r = func_09C3F640(D_09D1A060, arg0, &v, &res);
    if (r != 1) {
        return 0;
    }
    if (arg1 == 0) {
        if (res < lim) {
            return 1;
        }
    } else if (res > lim) {
        return 1;
    }
    return 0;
}

void func_088D8740(char *arg0, float *arg1, u16 arg2) {
    IVec ang;
    Mtx m;
    Vec v;
    Vec out;
    Vec rot;
    Vec *po;

    ang.x = 0;
    ang.y = arg2;
    ang.z = 0;
    ang.w = 0;
    vec_set4(&rot, ANG_TO_RAD(ang.x), ANG_TO_RAD(ang.y), ANG_TO_RAD(ang.z), 0.0f);
    mtx_identity(&m);
    mtx_euler(&m, rot.x, rot.y, rot.z);
    v.x = D_089B64D0[*(u16 *)(arg0 + 0x1E6)].unk0;
    v.y = 0.0f;
    v.z = D_089B64D4[*(u16 *)(arg0 + 0x1E6)].unk0;
    v.w = 0.0f;
    /* Taken here: the pointer registers depend on it. */
    po = &out;
    vec_tfm3(po, &m, &v);
    arg1[0] += out.x;
    arg1[1] += out.y;
    arg1[2] += out.z;
}

}
