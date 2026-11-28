/* unit_088C859C: 0x088C859C-0x088C8760 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088C859C: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */



typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Xf {
    u16 flags;
    u16 pad;
    f32 ang;
    f32 pad2[2];
    f32 tx, ty, tz;
    f32 pad3;
    f32 sx, sy, sz;
} Xf;

extern s32 func_08862354(char *, char *);
extern s32 func_0886171C(char *, s32, char *, s32);

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


void func_088C859C(char *self, char *obj, Xf *xf, s32 arg) {
    float m[16] __attribute__((aligned(16)));

    f32 sx, sy, sz;
    f32 tx, ty, tz;

    sz = xf->sz;
    sy = xf->sy;
    sx = xf->sx;
    mtx_identity(m);
    m[0] = sx;
    m[5] = sy;
    m[10] = sz;
    tz = xf->tz;
    ty = xf->ty;
    tx = xf->tx;
    m[12] = tx;
    m[13] = ty;
    m[14] = tz;
    if (xf->flags & 1) {
        rot_x(m, xf->ang);
    } else if (xf->flags & 2) {
        rot_y(m, xf->ang);
    } else if (xf->flags & 4) {
        rot_z(m, xf->ang);
    }
    func_08862354((char *)m, obj + 0x10);
    func_0886171C(obj, 0, self + 0x70, arg);
    func_08862354(self + 0x10, obj + 0x10);
}
