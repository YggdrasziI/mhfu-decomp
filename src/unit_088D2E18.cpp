/* unit_088D2E18: 0x088D2E18-0x088D3A84 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088D2E18 asm piece, 1 function between
 * unit_088D2E04 and unit_088D3A84.
 *
 * Moves the bone chains listed at +0x6D4 (count at +0x6D0, records of
 * D_089B73DC filled by func_088D2C14): each bone of a chain gets a velocity
 * (two per chain at +0x700) pulled along a fixed direction, an optional
 * push-out from an axis (func_088D3ADC), optional angle limits, and its local
 * rotation rebuilt from the two angles of the resulting direction.
 *
 * C++: the vector sum, difference and matrix product take their operands by
 * reference. Optimized for speed. The vector and matrix operations are VFPU
 * `asm` blocks (notes/COMPILER.md, "VFPU in asm blocks"); the arc tangent
 * has branches, so its block is `.set noreorder`.
 *
 * `flag` is cleared for each chain and never set: the test stays in the
 * code.
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
    char pad0[0xD0];
    Mtx unkD0;
    char pad110[0x34];
    struct Bone *unk144;
    char pad148[8];
    Mtx unk150;
    char pad190[0xC0];
} Bone;

typedef struct Mdl {
    char pad0[0x110];
    Bone *unk110;
    char pad114[0x10];
    u32 unk124;
} Mdl;

typedef struct Rec {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
} Rec;

typedef struct Slot {
    u8 unk0;
    char pad1[0xF];
    Vec unk10[2];
    char pad30[0x10];
} Slot;

typedef struct Obj {
    char pad0[0x6D0];
    s32 unk6D0;
    Rec *unk6D4[4];
    char pad6E4[0xC];
    Slot unk6F0[4];
} Obj;

extern "C" {

extern u16 D_089B70BC[][2];
extern u16 D_089B70BE[][2];
extern float D_089B70DC[];
extern Vec D_089B70F0[];
extern float D_089B71D0[];
extern Vec D_089B7200[];
extern float D_089B7240[][6];
extern float D_089B7244[][6];
extern float D_089B7248[][6];
extern float D_089B724C[][6];
extern float D_089B7250[][6];
extern float D_089B7254[][6];
extern float D_089B73C0[];
extern float D_089B73CC[];

extern s32 func_088D3ADC(Vec *, float *, Vec *, Vec *, float);

static inline void vec_copy(Vec *dst, Vec *src) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void vec_set(Vec *dst, float x, float y, float z, float w) {
    float *px = &x;
    float *py = &y;
    float *pz = &z;
    float *pw = &w;
    asm {
        lv.s S000, 0(px)
        lv.s S001, 0(py)
        lv.s S002, 0(pz)
        lv.s S003, 0(pw)
        sv.q C000, 0(dst)
    }
}

static inline void vec3_copy(Vec *dst, float *src) {
    float x = src[0];
    float y = src[1];
    float z = src[2];
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

static inline void vec3_neg(Vec *dst, Vec *src) {
    float x = -src->x;
    float y = -src->y;
    float z = -src->z;
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

static inline void vec_add(Vec *dst, Vec &ra, Vec &rb) {
    Vec *a = &ra;
    Vec *b = &rb;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vadd.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_sub(Vec *dst, Vec &ra, Vec &rb) {
    Vec *a = &ra;
    Vec *b = &rb;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_scale(Vec *dst, Vec *src, float f) {
    float *pf = &f;
    asm {
        lv.q C000, 0(src)
        lv.s S010, 0(pf)
        vscl.t C000, C000, S010
        sv.q C000, 0(dst)
    }
}

static inline void vec_cross(Vec *dst, Vec *a, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vzero.s S023
        vcrsp.t C020, C000, C010
        sv.q C020, 0(dst)
    }
}

static inline void vec_normalize(Vec *dst, Vec *src) {
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

/* Rotates and scales `src` by the upper 3x3 part of `mtx`. */
static inline void vec_tfm3(Vec *dst, Mtx *mtx, Vec *src) {
    asm {
        lv.q C100, 0(src)
        lv.q C200, 0(mtx)
        lv.q C210, 0x10(mtx)
        lv.q C220, 0x20(mtx)
        vmov.s S003, S103
        vtfm3.t C000, E200, C100
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

static inline void mtx_mul(Mtx *dst, Mtx *a, Mtx &rb) {
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

/* Inverse of a rotation, scale and translation matrix. */
static inline void mtx_inverse(Mtx *dst, Mtx *src) {
    asm {
        lv.q C100, 0(src)
        lv.q C110, 0x10(src)
        lv.q C120, 0x20(src)
        lv.q C130, 0x30(src)
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
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void row3_copy(float *src, float *dst) {
    asm {
        lv.s S000, 0(src)
        lv.s S001, 4(src)
        lv.s S002, 8(src)
        sv.s S000, 0(dst)
        sv.s S001, 4(dst)
        sv.s S002, 8(dst)
    }
}

static inline float sqrt_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vsqrt.s S000, S000
        sv.s S000, 0(pr)
    }
    return r;
}

/* The compiler's assembler has no syntax for these prefixes and constant. */
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

void func_088D2E18(Obj *arg0, Mdl *arg1, Mtx *arg2, Mtx *arg3) {
    Vec dir;
    Vec pos;
    Vec tip;
    Vec pull;
    Vec loc;
    Vec axis;
    Vec push;
    Vec side;
    Vec force;
    Vec ofs;
    Vec tmp;
    Vec base;
    Mtx world;
    Mtx mtx;
    Bone *bones;
    s16 i;
    s16 j;
    s16 k;
    u16 end;
    u16 start;
    u8 flag;
    Rec *rec;
    Bone *bone;
    float ang1;
    float ang2;
    s32 c;
    float *dst;

    bones = arg1->unk110;
    for (i = 0; i < arg0->unk6D0; i++) {
        rec = arg0->unk6D4[i];
        vec_copy(&ofs, &D_089B70F0[rec->unk6]);
        vec_tfm3(&ofs, arg2, &ofs);
        if (arg0->unk6F0[i].unk0 < 2) {
            arg0->unk6F0[i].unk0++;
            continue;
        }
        flag = 0;
        if (rec->unkA != -1) {
            vec_copy(&axis, &D_089B7200[rec->unkA]);
            vec_tfm3(&axis, arg3, &axis);
        }
        vec_set(&pull, 0.0f, D_089B70DC[arg0->unk6D4[i]->unk4], 0.0f, 0.0f);
        vec_add(&pull, pull, ofs);
        start = D_089B70BC[arg0->unk6D4[i]->unk0][0];
        end = D_089B70BE[arg0->unk6D4[i]->unk0][0];
        if (end >= arg1->unk124) {
            continue;
        }
        for (j = start, k = 0; j < end; j++, k++) {
            if (flag != 1) {
                bone = &bones[j];
                vec3_copy(&pos, &bone->unkD0.m[12]);
                vec3_copy(&tmp, &bone->unk150.m[12]);
                if (k == 0) {
                    mtx_copy(&world, arg2);
                } else {
                    mtx_mul(&mtx, &bone->unk144->unk150, world);
                    mtx_copy(&world, &mtx);
                }
                vec_tfm3(&tmp, &world, &tmp);
                vec_add(&base, *(Vec *) &world.m[12], tmp);
                bone = &bones[j + 1];
                vec3_copy(&tmp, &bone->unk150.m[12]);
                vec_tfm3(&dir, &bones[j].unkD0, &tmp);
                vec_sub(&loc, pos, base);
                vec_scale(&loc, &loc, D_089B73CC[arg0->unk6D4[i]->unk10]);
                vec_add(&dir, dir, loc);
                vec_cross(&side, &dir, &pull);
                vec_cross(&force, &side, &dir);
                vec_normalize(&force, &force);
                vec_scale(&force, &force, vec_dot(&force, &pull));
                vec_add(&arg0->unk6F0[i].unk10[k], arg0->unk6F0[i].unk10[k], force);
                vec_add(&dir, dir, arg0->unk6F0[i].unk10[k]);
                vec_add(&tip, base, dir);
                mtx_inverse(&mtx, &world);
                if (arg0->unk6D4[i]->unkA == -1) {
                    vec3_neg(&loc, &dir);
                    vec_tfm3(&loc, &mtx, &loc);
                    vec_normalize(&loc, &loc);
                } else {
                    if (func_088D3ADC(&tip, &arg3->m[12], &axis, &push, D_089B71D0[arg0->unk6D4[i]->unk8 * 2 + k]) != 0) {
                        vec_add(&tip, tip, push);
                    }
                    vec_sub(&loc, base, tip);
                    vec_tfm3(&loc, &mtx, &loc);
                    vec_normalize(&loc, &loc);
                }
                if (k == 0 || (arg0->unk6D4[i]->unk2 & 1)) {
                    c = arg0->unk6D4[i]->unkC;
                    if (c != -1) {
                        if (loc.x < D_089B7240[(s16) c][0]) {
                            loc.x = D_089B7240[(s16) c][0];
                        } else if (loc.x > D_089B7244[(s16) c][0]) {
                            loc.x = D_089B7244[(s16) c][0];
                        }
                        if (loc.y < D_089B7248[(s16) c][0]) {
                            loc.y = D_089B7248[(s16) c][0];
                        } else if (loc.y > D_089B724C[(s16) c][0]) {
                            loc.y = D_089B724C[(s16) c][0];
                        }
                        if (loc.z < D_089B7250[(s16) c][0]) {
                            loc.z = D_089B7250[(s16) c][0];
                        } else if (loc.z > D_089B7254[(s16) c][0]) {
                            loc.z = D_089B7254[(s16) c][0];
                        }
                    }
                }
            }
            ang1 = atan2_vfpu(loc.z, loc.y);
            ang2 = atan2_vfpu(-loc.x, sqrt_vfpu(loc.y * loc.y + loc.z * loc.z));
            mtx_identity(&mtx);
            rot_z(&mtx, ang2);
            rot_x(&mtx, ang1);
            dst = bones[j].unk150.m;
            row3_copy(&mtx.m[0], dst);
            row3_copy(&mtx.m[4], dst + 4);
            row3_copy(&mtx.m[8], dst + 8);
            vec_scale(&arg0->unk6F0[i].unk10[k], &arg0->unk6F0[i].unk10[k], D_089B73C0[arg0->unk6D4[i]->unkE]);
        }
    }
}

}
