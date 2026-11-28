/* unit_088C8AE0: 0x088C8AE0-0x088C8E5C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

/* func_088C8AE0: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

#pragma optimize_for_size off

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Anim {
    u16 flags;
    u16 u;
    u16 v;
    s16 shift;
    char pad8[8];
    f32 x;
    f32 y;
    f32 z;
} Anim;

extern s32 *D_089CC000;
extern void func_0886171C(char *, s32, char *, s32);
extern void func_08862354(float *, char *);

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

void func_088C8AE0(char *arg0, char *arg1, Anim *arg2, s32 arg3) {
    float m[16] __attribute__((aligned(16)));
    f32 su;
    f32 sv;
    u16 t;
    f32 ang;
    f32 x, y, z;

    if (arg2->u != 0) {
        su = (f32)(*(u16 *)(arg0 + 0x1C0) % arg2->u) / (f32)(u32)arg2->u;
        if (arg2->flags & 8) {
            su = 1.0f - su;
        }
        *D_089CC000 = (*(u32 *)&su >> 8) | 0x4A000000;
        D_089CC000++;
    }
    if (arg2->v != 0) {
        sv = (f32)(*(u16 *)(arg0 + 0x1C0) % arg2->v) / (f32)(u32)arg2->v;
        if (arg2->flags & 8) {
            sv = 1.0f - sv;
        }
        *D_089CC000 = (*(u32 *)&sv >> 8) | 0x4B000000;
        D_089CC000++;
    }
    t = (arg2->flags & 8) ? (u16)~*(u16 *)(arg0 + 0x1C0) : *(u16 *)(arg0 + 0x1C0);
    ang = 6.2831855f * ((360.0f * (f32)(s32)((t & (0xFFFF >> arg2->shift)) << arg2->shift) / 65536.0f) / 360.0f);
    z = arg2->z;
    y = arg2->y;
    x = arg2->x;
    mtx_identity(m);
    m[12] = x;
    m[13] = y;
    m[14] = z;
    if (arg2->flags & 1) {
        rot_x(m, ang);
    } else if (arg2->flags & 2) {
        rot_y(m, ang);
    } else if (arg2->flags & 4) {
        rot_z(m, ang);
    }
    func_08862354(m, arg1 + 0x10);
    func_0886171C(arg1, 0, arg0 + 0x70, arg3);
    *D_089CC000 = 0x4A000000;
    D_089CC000++;
    *D_089CC000 = 0x4B000000;
    D_089CC000++;
    func_08862354((float *)(arg0 + 0x10), arg1 + 0x10);
}
