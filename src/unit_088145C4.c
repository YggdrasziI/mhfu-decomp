/* unit_088145C4: 0x088145C4-0x08814674 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

extern void func_088144B4(char *arg0, char *arg1, float, float, float, float);
extern void func_08815E9C(char *arg0);

void func_088145C4(char *arg0, float arg1, float arg2, float arg3, float arg4) {
    float *q;
    float *p;

    func_088144B4(arg0, arg0 + 0xC00, arg1, arg2, arg3, arg4);
    q = (float *)(arg0 + 0xD00);
    p = (float *)(arg0 + 0xC00);
    asm {
        lv.q C100, 0x0(p)
        lv.q C110, 0x10(p)
        lv.q C120, 0x20(p)
        lv.q C130, 0x30(p)
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
        sv.q C000, 0x0(q)
        sv.q C010, 0x10(q)
        sv.q C020, 0x20(q)
        sv.q C030, 0x30(q)
    }
    func_08815E9C(arg0);
}
