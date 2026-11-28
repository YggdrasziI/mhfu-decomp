/* unit_08883384: 0x08883384-0x088838B0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08883384: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern s32 D_089CBBE4;
extern char *D_089CC438;
extern s32 D_09A4F06C;
extern s32 D_09A4F0C4;
extern s32 D_08A62D84;

extern void func_088140C4(s32, Vec *);
extern void func_088140E4(s32, Vec *);
extern s32 func_088CDCF4(s32);
extern s32 func_08813F04(s32);
extern s32 func_08813E90(s32);
extern s32 func_08813E20(s32);
extern s32 func_0887FBBC(s32);
extern char *func_088DCEBC(s32, u8);
extern s32 func_08865C88(char *, s32);

static inline void vec_normalize(Vec *src, Vec *dst) {
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

static inline void vec_scale(Vec *dst, Vec *src, float k) {
    float *pk = &k;
    asm {
        lv.q C000, 0(src)
        lv.s S010, 0(pk)
        vscl.t C000, C000, S010
        sv.q C000, 0(dst)
    }
}

static inline void vec_add(Vec *a, Vec *b, Vec *dst) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vadd.t C000, C000, C010
        sv.q C000, 0(dst)
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

void func_08883384(char *arg0) {
    char *e;
    Vec d;
    Vec b;
    Vec a;

    if (*(u8 *)(arg0 + 0x5623E0) == 0) {
        *(u8 *)(arg0 + 0x5623E0) = 1;
        func_088140C4(D_089CBBE4, &b);
        func_088140E4(D_089CBBE4, &a);
        d.x = a.x - b.x;
        d.y = a.y - b.y;
        d.z = a.z - b.z;
        *(s32 *)&d.w = 0;
        vec_normalize(&d, (Vec *)(arg0 + 0x562400));
        *(f32 *)(arg0 + 0x562410) = atan2_vfpu(*(f32 *)(arg0 + 0x562400), *(f32 *)(arg0 + 0x562408));
        if ((s32)((*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) == 0) {
            if ((u8)func_088CDCF4(D_09A4F06C) != 0 && (u8)func_08813F04(D_089CBBE4) == 1) {
                vec_scale(&d, (Vec *)(arg0 + 0x562400), 0.0f);
                vec_add(&b, &d, (Vec *)(arg0 + 0x5623F0));
                return;
            }
            if ((u8)func_08813E90(D_089CBBE4) == 0 && func_0887FBBC(D_08A62D84) == 2 &&
                (e = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28))) != 0) {
                vec_scale(&d, (Vec *)(arg0 + 0x562400), -150.0f);
                vec_add((Vec *)(e + 0x200), &d, (Vec *)(arg0 + 0x5623F0));
                return;
            }
        }
        if ((s32)((*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) == 1) {
            if (func_0887FBBC(D_08A62D84) == 2) {
                e = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
                if (e != 0 && func_08865C88(e, 0x80000) != 0) {
                    vec_scale(&d, (Vec *)(arg0 + 0x562400), -150.0f);
                    vec_add((Vec *)(e + 0x200), &d, (Vec *)(arg0 + 0x5623F0));
                    return;
                }
            }
            if ((u8)func_08813E20(D_089CBBE4) == 1 || *(s8 *)(arg0 + 0x562465) == 1) {
                vec_scale(&d, (Vec *)(arg0 + 0x562400), 0.0f);
                vec_add(&b, &d, (Vec *)(arg0 + 0x5623F0));
                return;
            }
        }
        vec_scale(&d, (Vec *)(arg0 + 0x562400), 250.0f);
        vec_add(&b, &d, (Vec *)(arg0 + 0x5623F0));
    }
}
