/* unit_08861E9C: 0x08861E9C-0x08862354 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08861E9C: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

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

static inline void rot_xyz(float *m, float x, float y, float z) {
    rot_x(m, x);
    rot_y(m, y);
    rot_z(m, z);
}

static inline void rot_zxy(float *m, float x, float y, float z) {
    rot_z(m, z);
    rot_x(m, x);
    rot_y(m, y);
}

void func_08861E9C(f32 *scale, f32 *rot, Vec3 *trans, u16 order, f32 *m) {
    Vec t;
    f32 sx, sy, sz;

    t.x = trans->x;
    t.y = trans->y;
    t.z = trans->z;
    sz = scale[2];
    sy = scale[1];
    sx = scale[0];
    mtx_identity(m);
    m[0] = sx;
    m[5] = sy;
    m[10] = sz;
    switch (order) {
    case 6:
        rot_xyz(m, rot[0], rot[1], rot[2]);
        break;
    case 7:
        rot_zxy(m, rot[0], rot[1], rot[2]);
        break;
    case 4:
        rot_x(m, rot[0]);
        rot_y(m, rot[1]);
        break;
    case 5:
        rot_z(m, rot[2]);
        rot_y(m, rot[1]);
        break;
    case 1:
        rot_x(m, rot[0]);
        break;
    case 2:
        rot_y(m, rot[1]);
        break;
    case 3:
        rot_z(m, rot[2]);
        break;
    }
    m[12] = t.x;
    m[13] = t.y;
    m[14] = t.z;
}
