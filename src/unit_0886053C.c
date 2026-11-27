/* unit_0886053C: 0x0886053C-0x08860648 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

void func_0886053C(char *arg0, float *arg1) {
    float *l = (float *)(arg0 + 0x150);
    float *w = (float *)(arg0 + 0x90);
    float *o;
    asm {
        lv.q C100, 0x0(l)
        lv.q C110, 0x10(l)
        lv.q C120, 0x20(l)
        lv.q C130, 0x30(l)
        lv.q C200, 0x0(arg1)
        lv.q C210, 0x10(arg1)
        lv.q C220, 0x20(arg1)
        lv.q C230, 0x30(arg1)
        vmmul.q E000, E100, E200
        sv.q C000, 0x0(w)
        sv.q C010, 0x10(w)
        sv.q C020, 0x20(w)
        sv.q C030, 0x30(w)
    }
    o = (float *)(arg0 + 0x10);
    asm {
        lv.q C100, 0x0(w)
        lv.q C110, 0x10(w)
        lv.q C120, 0x20(w)
        lv.q C130, 0x30(w)
        vmidt.q E000
        vmidt.q E200
        vdot.t S300, C100, C100
        vsqrt.s S300, S300
        vdot.t S301, C110, C110
        vsqrt.s S301, S301
        vdot.t S302, C120, C120
        vsqrt.s S302, S302
        vdiv.t C200, R100, C300
        vdiv.t C210, R101, C300
        vdiv.t C220, R102, C300
        vneg.t C310, C130
        vmul.t C320, R200, C310
        vfad.t S230, C320
        vmul.t C320, R201, C310
        vfad.t S231, C320
        vmul.t C320, R202, C310
        vfad.t S232, C320
        vdiv.t C000, C200, C300
        vdiv.t C010, C210, C300
        vdiv.t C020, C220, C300
        vdiv.t C030, C230, C300
        sv.q C000, 0x0(o)
        sv.q C010, 0x10(o)
        sv.q C020, 0x20(o)
        sv.q C030, 0x30(o)
    }
    if (*(char **)(arg0 + 0x14C) != 0) {
        func_0886053C(*(char **)(arg0 + 0x14C), w);
    }
    if (*(char **)(arg0 + 0x148) != 0) {
        func_0886053C(*(char **)(arg0 + 0x148), arg1);
    }
}
