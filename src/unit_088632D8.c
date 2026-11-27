/* unit_088632D8: 0x088632D8-0x088633CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Builds the matrix at arg1 from the three angles at +0xC (identity, then
 * the rotation from the sines and cosines of the angles) and the
 * translation at +0x18. The first argument is unused.
 */

typedef float f32;

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

void func_088632D8(void *arg0, float *arg1, char *arg2) {
    mtx_identity(arg1);
    mtx_rot_xyz(arg1, *(f32 *)(arg2 + 0xC), *(f32 *)(arg2 + 0x10), *(f32 *)(arg2 + 0x14));
    arg1[12] = *(f32 *)(arg2 + 0x18);
    arg1[13] = *(f32 *)(arg2 + 0x1C);
    arg1[14] = *(f32 *)(arg2 + 0x20);
}
