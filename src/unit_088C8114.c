/* unit_088C8114: 0x088C8114-0x088C8360 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

/* func_088C8114 (ULES01213), piece text_088C8114, size 0x24C.
 *
 * Builds a matrix from the translation at +0x10 of `p` and a rotation about
 * X, Y or Z (bits 1/2/4 of p->flags) by the angle (self+0x1C0, inverted with
 * bit 8) mod p->period, then calls func_08862354 / func_0886171C.
 *
 * Optimized for speed. VFPU `asm` blocks as in unit_08815964. The
 * translation is read into locals before the identity (z, y, x order).
 */
#pragma optimize_for_size off
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

typedef struct Param {
    u16 flags;
    u16 pad2;
    u32 period;
    char pad8[8];
    float x, y, z;
} Param;

extern void func_08862354(char *, char *);
extern void func_0886171C(char *, s32, char *, s32);

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}
static inline void rot_x(Mtx *m, float ang) {
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

static inline void rot_y(Mtx *m, float ang) {
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

void func_088C8114(char *self, char *a1, Param *p, s32 a3) {
    Mtx m;
    u16 v;
    float ang;
    float x, y, z;

    if (p->flags & 8) {
        v = ~*(u16 *)(self + 0x1C0);
    } else {
        v = *(u16 *)(self + 0x1C0);
    }
    ang = 6.2831855f * (360.0f * (float)(v % p->period) / (float)p->period / 360.0f);
    z = p->z;
    y = p->y;
    x = p->x;
    mtx_identity(&m);
    m.m[12] = x;
    m.m[13] = y;
    m.m[14] = z;
    if (p->flags & 1) {
        rot_x(&m, ang);
    } else if (p->flags & 2) {
        rot_y(&m, ang);
    } else if (p->flags & 4) {
        rot_z(&m, ang);
    }
    func_08862354((char *)&m, a1 + 0x10);
    func_0886171C(a1, 0, self + 0x70, a3);
    func_08862354(self + 0x10, a1 + 0x10);
}
