/* unit_08860328: 0x08860328-0x0886053C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef float f32;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

struct Node {
    virtual void vfunc_08();
    virtual void vfunc_0C(Mtx *a, Mtx *b, f32 x, f32 y, f32 z);
};

extern "C" {

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

void func_08860328(char *arg0, Mtx *arg1, Mtx *arg2, f32 x, f32 y, f32 z) {
    Mtx tmp;
    Mtx *m;
    Mtx *r;
    Mtx *o;
    Node *n;
    f32 sx;
    f32 sy;
    f32 sz;


    sx = *(f32 *)(arg0 + 0x190) * x;
    sy = *(f32 *)(arg0 + 0x194) * y;
    sz = *(f32 *)(arg0 + 0x198) * z;
    m = (Mtx *)(arg0 + 0x90);
    mtx_identity(m);
    m->m[0] = sx;
    m->m[5] = sy;
    m->m[10] = sz;
    mtx_identity(&tmp);
    tmp.m[0] = 1.0f / x;
    tmp.m[5] = 1.0f / y;
    tmp.m[10] = 1.0f / z;
    tmp.m[12] = *(f32 *)(arg0 + 0x180);
    tmp.m[13] = *(f32 *)(arg0 + 0x184);
    tmp.m[14] = *(f32 *)(arg0 + 0x188);
    r = (Mtx *)(arg0 + 0x150);
    asm {
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        lv.q C200, 0(r)
        lv.q C210, 0x10(r)
        lv.q C220, 0x20(r)
        vmmul.t E000, E100, E200
        sv.s S000, 0(m)
        sv.s S001, 4(m)
        sv.s S002, 8(m)
        sv.s S010, 0x10(m)
        sv.s S011, 0x14(m)
        sv.s S012, 0x18(m)
        sv.s S020, 0x20(m)
        sv.s S021, 0x24(m)
        sv.s S022, 0x28(m)
    }
    r = &tmp;
    asm {
        lv.q C100, 0(r)
        lv.q C110, 0x10(r)
        lv.q C120, 0x20(r)
        lv.q C130, 0x30(r)
        lv.q C200, 0(m)
        lv.q C210, 0x10(m)
        lv.q C220, 0x20(m)
        lv.q C230, 0x30(m)
        vmmul.q E000, E200, E100
        sv.q C000, 0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
    o = (Mtx *)(arg0 + 0xD0);
    asm {
        lv.q C100, 0(arg1)
        lv.q C110, 0x10(arg1)
        lv.q C120, 0x20(arg1)
        lv.q C130, 0x30(arg1)
        lv.q C200, 0(m)
        lv.q C210, 0x10(m)
        lv.q C220, 0x20(m)
        lv.q C230, 0x30(m)
        vmmul.q E000, E200, E100
        sv.q C000, 0(o)
        sv.q C010, 0x10(o)
        sv.q C020, 0x20(o)
        sv.q C030, 0x30(o)
    }
    asm {
        lv.q C100, 0(arg2)
        lv.q C110, 0x10(arg2)
        lv.q C120, 0x20(arg2)
        lv.q C130, 0x30(arg2)
        lv.q C200, 0(m)
        lv.q C210, 0x10(m)
        lv.q C220, 0x20(m)
        lv.q C230, 0x30(m)
        vmmul.q E000, E200, E100
        sv.q C000, 0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
    n = *(Node **)(arg0 + 0x14C);
    if (n != 0) {
        n->vfunc_0C(o, m, sx, sy, sz);
    }
    n = *(Node **)(arg0 + 0x148);
    if (n != 0) {
        n->vfunc_0C(arg1, arg2, x, y, z);
    }
}

}
