/* unit_08865530: 0x08865530-0x088655E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef float f32;

static inline void mtx_identity(f32 *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void rot_y(f32 *m, f32 ang) {
    f32 *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vrot.q C000, S100, [C,0,-S,0]
        vidt.q C010
        vrot.q C020, S100, [S,0,C,0]
        vidt.q C030
        vmmov.q E200, E000
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        lv.q C130, 0x30(m)
        vmmul.q E200, E100, E000
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
    }
}

static inline void mtx_mul3(f32 *dst, f32 *a, f32 *b) {
    asm {
        lv.q C100, 0(a)
        lv.q C110, 0x10(a)
        lv.q C120, 0x20(a)
        lv.q C200, 0(b)
        lv.q C210, 0x10(b)
        lv.q C220, 0x20(b)
        vmmul.t E000, E100, E200
        sv.s S000, 0(dst)
        sv.s S001, 4(dst)
        sv.s S002, 8(dst)
        sv.s S010, 0x10(dst)
        sv.s S011, 0x14(dst)
        sv.s S012, 0x18(dst)
        sv.s S020, 0x20(dst)
        sv.s S021, 0x24(dst)
        sv.s S022, 0x28(dst)
    }
}

/* func_08865530: rotates the 3x3 part of src about Y by ang (in turns)
 * and stores it to dst. */
void func_08865530(f32 *dst, f32 *src, f32 ang) {
    f32 m[16] __attribute__((aligned(16)));

    mtx_identity(m);
    rot_y(m, ang);
    mtx_mul3(dst, m, src);
}
