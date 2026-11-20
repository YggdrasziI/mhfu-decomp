/* unit_088D3ADC: 0x088D3ADC-0x088D3F68 (ULES01213)
 *
 * Bounds (hypothesis): 3 functions between unit_088D3A84 and the asm piece
 * text_088D3F68.
 *
 * A push-out vector along a normalized axis, and two recursive walks of a
 * tree of 0x250-byte bones (children at +0x148 and +0x14C) that rebuild the
 * matrix at +0x50 from the one at +0x10 and a matrix picked by the table
 * D_089B78A0.
 *
 * Optimized for speed. The vector and matrix operations are VFPU `asm`
 * blocks (notes/COMPILER.md, "VFPU in asm blocks").
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

typedef struct Bone {
    char pad0[0x10];
    Mtx unk10;
    Mtx unk50;
    Mtx unk90;
    char padD0[0x46];
    u16 unk116;
    char pad118[0x30];
    struct Bone *unk148;
    struct Bone *unk14C;
    Mtx unk150;
    char pad190[0xC0];
} Bone;

extern "C" {

extern s16 *D_089B78A0[];

void func_088D3B94(char *arg0, Bone *arg1, Bone *arg2, s16 arg3);
void func_088D3DBC(char *arg0, Bone *arg1, Bone *arg2, s16 arg3, Mtx *arg4);

static inline void vec_sub(Vec *dst, float *a, float *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_normalize(Vec *dst, float *src) {
    asm {
        lv.q C000, 0(src)
        vdot.t S010, C000, C000
        vzero.s S011
        vcmp.s ez, S010, S010
        nop
        vrsq.s S010, S010
        vcmovt.s S010, S011, 0
        vpfxd [-1:1],[-1:1],[-1:1],[-1:1]
        vscl.t C000, C000, S010
        sv.q C000, 0(dst)
    }
}

static inline float vec_dot(Vec *a, Vec *b) {
    float r;
    float *pr = &r;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vdot.t S100, C000, C010
        sv.s S100, 0(pr)
    }
    return r;
}

static inline void vec_scale(float *dst, Vec *src, float f) {
    float *pf = &f;
    asm {
        lv.q C000, 0(src)
        lv.s S010, 0(pf)
        vscl.t C000, C000, S010
        sv.q C000, 0(dst)
    }
}

static inline void vec_copy(float *dst, float *src) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void mtx_copy(Mtx *dst, Mtx *src) {
    asm {
        lv.q C000, 0(src)
        lv.q C010, 0x10(src)
        lv.q C020, 0x20(src)
        lv.q C030, 0x30(src)
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
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

static inline void mtx_mul(Mtx *dst, Mtx *a, Mtx *b) {
    asm {
        lv.q C100, 0(a)
        lv.q C110, 0x10(a)
        lv.q C120, 0x20(a)
        lv.q C130, 0x30(a)
        lv.q C200, 0(b)
        lv.q C210, 0x10(b)
        lv.q C220, 0x20(b)
        lv.q C230, 0x30(b)
        vmmul.q E000, E100, E200
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

/* Same product with the right operand taken by reference: the address of a
 * stack matrix is then computed after the left operand's. */
static inline void mtx_mul_ref(Mtx *dst, Mtx *a, Mtx &rb) {
    Mtx *b = &rb;
    asm {
        lv.q C100, 0(a)
        lv.q C110, 0x10(a)
        lv.q C120, 0x20(a)
        lv.q C130, 0x30(a)
        lv.q C200, 0(b)
        lv.q C210, 0x10(b)
        lv.q C220, 0x20(b)
        lv.q C230, 0x30(b)
        vmmul.q E000, E100, E200
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void mtx_mul3(Mtx *dst, Mtx *a, Mtx *b) {
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

s32 func_088D3ADC(float *arg0, float *arg1, float *arg2, float *arg3, float arg4) {
    Vec d;
    Vec n;
    float dot;

    vec_sub(&d, arg1, arg0);
    vec_normalize(&n, arg2);
    dot = vec_dot(&n, &d);
    if (dot <= 0.0f && -dot > arg4) {
        return 0;
    }
    vec_scale(arg3, &n, dot + arg4);
    return 1;
}

void func_088D3B94(char *arg0, Bone *arg1, Bone *arg2, s16 arg3) {
    Mtx tmp;
    s16 *tbl;
    s16 v;
    Mtx *p;

    tbl = D_089B78A0[arg3];
    if (arg3 == 0) {
        if (arg1->unk116 >= 11) {
            return;
        }
        mtx_mul(&arg1->unk50, &arg1->unk10, &arg1->unk90);
    } else {
        v = tbl[arg1->unk116];
        if (v > 0) {
            p = &arg2[v & 0x3F].unk90;
            if (v < 0x40) {
                mtx_copy(&tmp, p);
            } else {
                mtx_copy(&tmp, &arg1->unk90);
                mtx_mul3(&tmp, &arg1->unk150, p);
            }
        } else {
            mtx_identity(&tmp);
            vec_copy(&tmp.m[12], &arg1->unk90.m[12]);
        }
        mtx_mul_ref(&arg1->unk50, &arg1->unk10, tmp);
    }
    if (arg1->unk14C != 0) {
        func_088D3B94(arg0, arg1->unk14C, arg2, arg3);
    }
    if (arg1->unk148 != 0) {
        func_088D3B94(arg0, arg1->unk148, arg2, arg3);
    }
}

void func_088D3DBC(char *arg0, Bone *arg1, Bone *arg2, s16 arg3, Mtx *arg4) {
    Mtx tmp;
    s16 *tbl;
    s16 v;

    tbl = D_089B78A0[arg3];
    v = tbl[arg1->unk116];
    if (v > 0) {
        if (v < 0x40) {
            mtx_copy(&tmp, &arg2[v].unk90);
        } else {
            mtx_mul(&tmp, &arg1->unk150, arg4);
        }
    } else {
        mtx_identity(&tmp);
        vec_copy(&tmp.m[12], &arg1->unk90.m[12]);
    }
    mtx_mul_ref(&arg1->unk50, &arg1->unk10, tmp);
    /* The first child gets the local matrix, the second one the caller's. */
    if (arg1->unk14C != 0) {
        func_088D3DBC(arg0, arg1->unk14C, arg2, arg3, &tmp);
    }
    if (arg1->unk148 != 0) {
        func_088D3DBC(arg0, arg1->unk148, arg2, arg3, arg4);
    }
}

}
