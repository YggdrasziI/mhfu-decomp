/* unit_08815E9C: 0x08815E9C-0x08816060 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern void func_08815E28(float *arg0, float *arg1, float *arg2, float *arg3, float *arg4);

void func_08815E9C(float *arg0) {
    float cx;
    float cr;
    float sx;
    float sr;
    float z[4];
    float a[4];
    float b[4];
    float *pz;
    float *px;
    float *pr;
    float h;
    float c;
    float s;
    float r;
    float t;

    pz = z;
    asm {
        vzero.q C000
        sv.q C000, 0(pz)
    }
    a[2] = b[2] = 1.5f * -arg0[1];
    h = 0.5f * arg0[3];
    cx = h;
    pr = &cr;
    px = &cx;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vcos.s S010, S000
        sv.s S010, 0(pr)
    }
    c = cr;
    sx = h;
    pr = &sr;
    px = &sx;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    s = sr;
    r = c / s;
    a[0] = -arg0[1] * r;
    a[1] = arg0[1] * r / arg0[2];
    b[0] = a[0];
    b[1] = -a[1];
    func_08815E28(arg0, arg0 + 0x354, z, a, b);
    r = c / s;
    t = arg0[1];
    a[0] = t * r;
    a[1] = -t * r / arg0[2];
    b[0] = a[0];
    b[1] = -a[1];
    func_08815E28(arg0, arg0 + 0x358, z, a, b);
    a[0] = arg0[1] * r;
    a[1] = a[0] / arg0[2];
    b[0] = -a[0];
    b[1] = a[1];
    func_08815E28(arg0, arg0 + 0x35C, z, a, b);
    a[0] = -arg0[1] * r;
    a[1] = a[0] / arg0[2];
    b[0] = -a[0];
    b[1] = a[1];
    func_08815E28(arg0, arg0 + 0x360, z, a, b);
    arg0[0x365] = -arg0[1];
    arg0[0x364] = -arg0[0];
}
