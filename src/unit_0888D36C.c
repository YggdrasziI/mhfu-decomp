/* unit_0888D36C: 0x0888D36C-0x0888D600 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0888D36C: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks");
 * same atan2 helper as func_08888B98. */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct {
    char pad0[0x80];
    s16 h80;
    char pad82[4];
    u16 h86;
    char pad88[3];
    u8 b8B;
    char pad8C;
    u8 b8D;
} Sub;

typedef struct {
    char pad0[0xA0];
    Sub sub;
} Obj;

extern char *D_089CBBE4;

extern u8 func_0888D2B4(Obj *);

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

static inline void vec_sub(Vec *b, Vec *a, Vec *dst) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

void func_0888D36C(Obj *p) {
    char *g = D_089CBBE4;
    Sub *s = &p->sub;
    char *w;
    Vec v;

    if (s->b8B == 0x3C) {
        if ((s32)(((u8 *)p)[0x133] != 0) == 1) {
            return;
        }
        if (s->h86 & 0x50) {
            s->b8B = 0;
            return;
        }
        if (func_0888D2B4(p) != 0) {
            return;
        }
        s->b8B--;
        return;
    }
    if (s->b8B != 0) {
        s->b8B--;
        if (s->h86 & 0x50) {
            s->b8B = 0;
        }
    }
    if ((s32)(((u8 *)p)[0x133] != 0) != 1) {
        return;
    }
    if (func_0888D2B4(p) != 1) {
        return;
    }
    w = *(char **)(g + 0xA84);
    s->b8B = 0x3C;
    vec_sub((Vec *)(w + 0x200), (Vec *)(w + 0x210), &v);
    if (s->b8D != 0) {
        return;
    }
    s->h80 = (s16)(10430.378f * atan2_vfpu(v.x, v.z));
}
