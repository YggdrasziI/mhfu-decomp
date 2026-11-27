/* unit_08815964: 0x08815964-0x08815D64 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08815964 (ULES01213), piece text_08815964, size 0x400.
 *
 * Eases the vectors at +0xB40 / +0xB50 and the float at +0xC towards their
 * targets (1/9 per call), calls func_08815348 and func_08814268, then turns
 * the point (0, 0, 1) by the matrix at +0xC80 and rebuilds the matrix at
 * +0xCC0 as a rotation about Y from the heading of that point.
 *
 * Optimized for speed (float constants built with lui/ori). The vector and
 * matrix operations are VFPU `asm` blocks (notes/COMPILER.md); the arc
 * tangent block is the one of unit_088D2E18.
 */
#pragma optimize_for_size off
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

extern void func_08815348(char *);
extern void func_08814268(char *, Vec *, char *, Vec *);

#define TO_RAD(a) (6.2831855f * (360.0f * (a) / 65536.0f / 360.0f))

static inline void to_world(Mtx *mtx, Vec *src, Vec *dst) {
    asm {
        lv.q C100, 0(src)
        lv.q C200, 0(mtx)
        lv.q C210, 0x10(mtx)
        lv.q C220, 0x20(mtx)
        lv.q C230, 0x30(mtx)
        vcst.s S003, 0
        vtfm3.t C000, E200, C100
        vadd.t C000, C000, C230
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

static inline void rot_x(Mtx *m, float ang) {
    float *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vidt.q C000
        vrot.q C010, S100, [0,C,S,0]
        vrot.q C020, S100, [0,-S,C,0]
        vidt.q C030
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        vmmul.t E200, E100, E000
        lv.q C230, 0x30(m)
        vcst.t R203, 0
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
    }
}

static inline void rot_y(Mtx *m, float ang) {
    float *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vrot.q C000, S100, [C,0,-S,0]
        vidt.q C010
        vrot.q C020, S100, [S,0,C,0]
        vidt.q C030
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        vmmul.t E200, E100, E000
        lv.q C230, 0x30(m)
        vcst.t R203, 0
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
    }
}

static inline void rot_z(Mtx *m, float ang) {
    float *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vrot.q C000, S100, [C,S,0,0]
        vrot.q C010, S100, [-S,C,0,0]
        vidt.q C020
        vidt.q C030
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        vmmul.t E200, E100, E000
        lv.q C230, 0x30(m)
        vcst.t R203, 0
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
    }
}

#define VPFXS_ABS .word 0xDC000FE4
#define VPFXS_TWO .word 0xDC00F0AA
#define VPFXS_NEG_Y .word 0xDC0200E4
#define VPFXT_ABS .word 0xDD000FE4
#define VPFXT_HALF .word 0xDD00F0FF
#define VPFXD_SAT_Y .word 0xDE000004
#define VFIM_S010_M1 .word 0xDF81BC00

static inline float atan2_vfpu(float y, float x) {
    float r;
    float *pr = &r;
    float *py = &y;
    float *px = &x;
    asm {
        .set noreorder
        lv.s S000, 0(py)
        lv.s S001, 0(px)
        vcmp.p es, C000, C000
        bvt 4, special
        vzero.s S002
        vcmp.s ge, S001, S002
        vcst.s S010, VFPU_PI
        vcmovt.s S010, S002, 0
        vcmp.s ez, S000, S000
        bvt 0, done
        vcst.s S002, VFPU_PI_2
        vrcp.s S003, S001
        vmul.s S003, S000, S003
        vcmp.s en, S003, S003
        bvt 0, done
        vmov.s S010, S003
        vcmp.s es, S003, S003
        bvtl 0, quadrant
        vsgn.s S010, S000
        vmul.s S011, S003, S003
        vcmp.s es, S011, S011
        bvt 0, overflow
        vone.s S003
        VPFXS_ABS
        vcmp.s lt, S010, S003
        vadd.s S003, S011, S003
        bvfl 0, steep
        vrcp.s S003, S003
        vrsq.s S003, S003
        vmul.s S010, S010, S003
        b quadrant
        vasin.s S010, S010
    special:
        vcmp.p en, C000, C000
        VFIM_S010_M1
        bvt 4, done
        vrsq.s S010, S010
        vcmp.p ei, C000, C000
        bvt 5, both_inf
        nop
        vi2f.s S000, S000, 0
        VPFXT_HALF
        vadd.s S000, S000, S000
        vsgn.s S000, S000
        vcst.s S002, VFPU_PI_2
        bvt 0, finish
        vone.s S010
        vzero.s S003
        vcmp.s ge, S001, S003
        vcmovt.s S010, S003, 0
        b finish
        vcst.s S002, VFPU_PI
    both_inf:
        vsgn.p C000, C000
        VPFXS_TWO
        vsub.s S010, S010, S001
        b finish
        vcst.s S002, VFPU_PI_4
    overflow:
        vsgn.s S000, S000
        vcst.s S002, VFPU_PI_2
        bvt 0, finish
        vone.s S010
        vsgn.s S011, S001
        b finish
        vsub.s S010, S010, S011
    steep:
        vmul.s S003, S011, S003
        vpfxd [0:1],[0:1],[0:1],[0:1]
        vocp.s S003, S003
        vsqrt.s S003, S003
        vasin.s S003, S003
        vocp.s S010, S003
    quadrant:
        VPFXD_SAT_Y
        VPFXS_NEG_Y
        vsgn.p C000, C000
        vcmp.s ez, S001, S001
        bvt 0, finish
        nop
        VPFXS_TWO
        VPFXT_ABS
        vsub.s S010, S010, S010
    finish:
        VPFXS_ABS
        vmul.s S010, S010, S000
        vmul.s S010, S010, S002
    done:
        sv.s S010, 0(pr)
    }
    return r;
}

typedef struct Obj {
    char pad0[0xC];
    float unkC;
    char pad10[0x10];
    float unk20;
    float unk24;
    float unk28;
    char pad2C[4];
    float unk30;
    float unk34;
    float unk38;
    char pad3C[0x6C];
    float unkA8;
    char padAC[0xB40 - 0xAC];
    Vec unkB40;
    Vec unkB50;
    Vec unkB60;
    char padB70[0xC80 - 0xB70];
    Mtx unkC80;
    Mtx unkCC0;
} Obj;

void func_08815964(Obj *arg0) {
    Vec v;
    Vec t;
    float ang;
    s32 dir;
    float rad;

    arg0->unkB50.x += (arg0->unk30 - arg0->unkB50.x) / 9.0f;
    arg0->unkB50.y += (arg0->unk34 - arg0->unkB50.y) / 9.0f;
    arg0->unkB50.z += (arg0->unk38 - arg0->unkB50.z) / 9.0f;
    arg0->unkB40.x += (arg0->unk20 - arg0->unkB40.x) / 9.0f;
    arg0->unkB40.y += (arg0->unk24 - arg0->unkB40.y) / 9.0f;
    arg0->unkB40.z += (arg0->unk28 - arg0->unkB40.z) / 9.0f;
    arg0->unkC += (arg0->unkA8 - arg0->unkC) / 9.0f;
    func_08815348((char *)arg0);
    func_08814268((char *)arg0, &arg0->unkB40, (char *)&arg0->unkB50, &arg0->unkB60);
    v.w = 1.0f;
    v.z = 1.0f;
    v.y = 0.0f;
    v.x = 0.0f;
    to_world(&arg0->unkC80, &v, &t);
    ang = atan2_vfpu(-(t.z - arg0->unkC80.m[14]), t.x - arg0->unkC80.m[12]);
    dir = (s32) (0.5f + 65536.0f * ang / 6.2831855f) & 0xFFFF;
    rad = TO_RAD((float) ((dir + 0x4000) & 0xFFFF));
    mtx_identity(&arg0->unkCC0);
    rot_x(&arg0->unkCC0, 0.0f);
    rot_y(&arg0->unkCC0, rad);
    rot_z(&arg0->unkCC0, 0.0f);
}
