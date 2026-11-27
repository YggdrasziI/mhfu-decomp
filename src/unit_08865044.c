/* unit_08865044: 0x08865044-0x08865254 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08865044: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern s32 func_08865F68(char *arg0, s32 arg1);

static inline void xform3(float *mtx, float *src, Vec *dst) {
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

static inline void rot_x(float *m, float ang) {
    float *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vidt.q C000
        vrot.q C010, S100, [0,C,S,0]
        vrot.q C020, S100, [0,-S,C,0]
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

static inline void rot_y(float *m, float ang) {
    float *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vrot.q C000, S100, [C,0,-S,0]
        vidt.q C010
        vrot.q C020, S100, [S,0,C,0]
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

static inline void rot_z(float *m, float ang) {
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

static inline void mtx_mul3(float *m, float *b) {
    asm {
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        lv.q C200, 0(b)
        lv.q C210, 0x10(b)
        lv.q C220, 0x20(b)
        vmmul.t E000, E100, E200
        sv.s S000, 0(m)
        sv.s S001, 4(m)
        sv.s S002, 8(m)
        sv.s S010, 0x10(m)
        sv.s S011, 0x14(m)
        sv.s S012, 0x18(m)
        sv.s S020, 0x20(m)
        sv.s S021, 0x24(m)
        sv.s S022, 0x28(m)
    }
}

void func_08865044(char *arg0, float *dst, s32 arg2, float *vec, float *rot, float *scale) {
    float *m;
    Vec p;
    Vec t;
    f32 sx, sy, sz;
    f32 rx, ry, rz;

    m = (float *)func_08865F68(arg0, (u8)arg2);
    p.x = m[12];
    p.y = m[13];
    p.z = m[14];
    xform3(m, vec, &t);
    p.x = p.x + t.x;
    p.y = p.y + t.y;
    p.z = p.z + t.z;
    sz = scale[2];
    sy = scale[1];
    sx = scale[0];
    mtx_identity(dst);
    dst[0] = sx;
    dst[5] = sy;
    dst[10] = sz;
    rz = rot[2];
    ry = rot[1];
    rx = rot[0];
    rot_x(dst, rx);
    rot_y(dst, ry);
    rot_z(dst, rz);
    mtx_mul3(dst, m);
    dst[12] = p.x;
    dst[13] = p.y;
    dst[14] = p.z;
}
