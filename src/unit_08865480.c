/* unit_08865480: 0x08865480-0x08865530 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

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

static inline void mtx_mul3(float *out, float *a, float *b) {
    asm {
        lv.q C100, 0(a)
        lv.q C110, 0x10(a)
        lv.q C120, 0x20(a)
        lv.q C200, 0(b)
        lv.q C210, 0x10(b)
        lv.q C220, 0x20(b)
        vmmul.t E000, E100, E200
        sv.s S000, 0(out)
        sv.s S001, 4(out)
        sv.s S002, 8(out)
        sv.s S010, 0x10(out)
        sv.s S011, 0x14(out)
        sv.s S012, 0x18(out)
        sv.s S020, 0x20(out)
        sv.s S021, 0x24(out)
        sv.s S022, 0x28(out)
    }
}

void func_08865480(float *out, float *in, float ang) {
    Mtx tmp;

    mtx_identity(tmp.m);
    rot_x(tmp.m, ang);
    mtx_mul3(out, tmp.m, in);
}
