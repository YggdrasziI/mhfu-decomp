/* unit_088C9D9C: 0x088C9D9C-0x088CA100 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088C9D9C: vtable method of D_089BACDC (also listed twice in
 * D_089BE690) (ULES01213).
 *
 * Builds a local matrix: identity with the translation at +0x10 of the
 * parameter record, a rotation (X, Y or Z by flag bits 1, 2, 4) by an angle
 * made of three sines of the 12-bit phase (+0x1C0 of the object plus the
 * record's +2), scaled by half the record's +4, then a Y rotation by +8.
 *
 * Optimized for speed. The sines and rotations are VFPU `asm` blocks
 * (notes/COMPILER.md, "VFPU in asm blocks").
 */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

typedef struct Param {
    u16 flags;
    u16 phase;
    float amp;
    float unk8;
    float pad;
    float pos[3];
} Param;

extern void func_08862354(float *, char *);
extern s32 func_0886171C(char *, s32, char *, s32);

#define TO_RAD(a) (6.2831855f * (360.0f * (a) / 65536.0f / 360.0f))

static inline float sin_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
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

void func_088C9D9C(char *arg0, char *arg1, Param *arg2, s32 arg3) {
    Mtx m;
    u32 t;
    float s1;
    float s2;
    float h;
    float ang;
    float a;

    {
        u16 q = *(u16 *)(arg0 + 0x1C0) + arg2->phase;
        t = q & 0xFFF;
    }
    s1 = sin_vfpu(TO_RAD((s32)(t * 4)));
    s2 = sin_vfpu(TO_RAD((s32)((u16)(u32)((float)t * s1) << 10)));
    h = 0.5f * arg2->amp;
    a = h * s2;
    ang = a + h * sin_vfpu(TO_RAD((s32)((u16)t << 10)));
    {
        float z = arg2->pos[2];
        float y = arg2->pos[1];
        float x = arg2->pos[0];
        mtx_identity(m.m);
        m.m[12] = x;
        m.m[13] = y;
        m.m[14] = z;
    }
    if (arg2->flags & 1) {
        rot_x(m.m, ang);
    } else if (arg2->flags & 2) {
        rot_y(m.m, ang);
    } else if (arg2->flags & 4) {
        rot_z(m.m, ang);
    }
    rot_y(m.m, arg2->unk8);
    func_08862354(m.m, arg1 + 0x10);
    func_0886171C(arg1, 0, arg0 + 0x70, arg3);
    func_08862354((float *)(arg0 + 0x10), arg1 + 0x10);
}
