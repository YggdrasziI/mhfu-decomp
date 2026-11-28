/* unit_088C83F0: 0x088C83F0-0x088C859C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

/* func_088C83F0: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

typedef unsigned short u16;
typedef int s32;
typedef float f32;

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

typedef struct {
    u16 flags;
    u16 pad;
    f32 angle;
    s32 pad2[2];
    f32 x, y, z;
} Rot;

extern void func_08862354(float *, char *);
extern void func_0886171C(char *, s32, char *, s32);

void func_088C83F0(char *a, char *b, Rot *r, s32 d) {
    struct {
        float m[12] __attribute__((aligned(16)));
        struct { f32 x, y, z; } t;
    } s;
    f32 z = r->z;
    f32 y = r->y;
    f32 x = r->x;

    mtx_identity(s.m);
    s.t.x = x;
    s.t.y = y;
    s.t.z = z;
    if (r->flags & 1) {
        rot_x(s.m, r->angle);
    } else if (r->flags & 2) {
        rot_y(s.m, r->angle);
    } else if (r->flags & 4) {
        rot_z(s.m, r->angle);
    }
    func_08862354(s.m, b + 0x10);
    func_0886171C(b, 0, a + 0x70, d);
    func_08862354((float *)(a + 0x10), b + 0x10);
}
