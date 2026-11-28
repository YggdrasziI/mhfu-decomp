/* unit_0888D958: 0x0888D958-0x0888DA60 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0888D958: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks").
 * Builds at arg1 a rotation matrix from two angles (65536 units per turn)
 * with the vector at arg4 as its translation row. */
#pragma optimize_for_size off

typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct {
    f32 m[16];
} __attribute__((aligned(16))) Mtx;

static inline void vec_copy(Vec *src, Vec *dst) {
    asm {
        lv.q C000, 0(src)
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

static inline void mtx_rot_xyz(Mtx *m, float x, float y, float z) {
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

void func_0888D958(char *arg0, Mtx *arg1, s32 arg2, s32 arg3, Vec *arg4) {
    f32 x;
    f32 y;
    mtx_identity(arg1);
    y = 9.58738019e-05f * (f32)arg3;
    x = 9.58738019e-05f * (f32)arg2;
    mtx_rot_xyz(arg1, x, y, 0.0f);
    vec_copy(arg4, (Vec *)&arg1->m[12]);
    arg1->m[15] = 1.0f;
}
