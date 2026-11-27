/* unit_08862FE0: 0x08862FE0-0x088630D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef float f32;

f32 func_08862FE0(void *arg0, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g) {
    f32 r;
    f32 *pr = &r;
    f32 *pa = &a;
    f32 *pb = &b;
    f32 *pc = &c;
    f32 *pd = &d;
    f32 *pe = &e;
    f32 *pf = &f;
    f32 *pg = &g;
    asm {
        lv.s S100, 0(pa)
        lv.s S101, 0(pb)
        lv.s S102, 0(pc)
        lv.s S103, 0(pd)
        lv.s S110, 0(pe)
        lv.s S111, 0(pf)
        lv.s S112, 0(pg)
        vsub.s S200, S100, S102
        vsub.s S201, S111, S102
        vrcp.s S201, S201
        vmul.s S202, S201, S201
        vmul.s S203, S200, S200
        vmul.s S210, S203, S201
        vmul.s S211, S203, S200
        vmul.s S211, S211, S202
        vfim.s S212, 2.0
        vmul.s S212, S212, S211
        vmul.s S212, S212, S201
        vfim.s S213, 3.0
        vmul.s S213, S213, S203
        vmul.s S213, S213, S202
        vfim.s S220, 1.0
        vadd.s S220, S220, S212
        vsub.s S220, S220, S213
        vmul.s S220, S101, S220
        vsub.s S221, S213, S212
        vmul.s S221, S110, S221
        vsub.s S222, S211, S210
        vsub.s S222, S222, S210
        vadd.s S222, S222, S200
        vmul.s S222, S103, S222
        vsub.s S223, S211, S210
        vmul.s S223, S112, S223
        vfad.q S000, C220
        sv.s S000, 0(pr)
    }
    return r;
}
