/* unit_088D6B00: 0x088D6B00-0x088D71F0 (ULES01213)
 *
 * Bounds (hypothesis): 3 functions between unit_088D6AC8 and unit_088D71F0.
 *
 * func_088D6B00 turns the 16-bit heading at +0x1F4 towards the one at +0x320
 * by a step that depends on the object's state, and leans the 16-bit value
 * at +0x41A with the turn. func_088D6D10 looks for the nearest object within
 * 1500 units and turns the 16-bit value at +0x68C towards it (arc tangent of
 * the normalized offset), or back to 0 when there is none. func_088D71B8
 * adds the step at +0x660 to the position at +0x200 while the count at
 * +0x670 lasts (the move started by func_088D64E0).
 *
 * C++: bool conversions. The vector code is VFPU `asm` blocks
 * (notes/COMPILER.md, "VFPU in asm blocks").
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

extern "C" {

extern char *D_089CC438;
extern s32 D_09B23A98;
extern char *D_09C121B0;

extern s32 func_08865CB8(char *, s32, s32);
extern char *func_09ADC408(s32, s32);

static inline float vec_dist(Vec &ra, Vec &rb) {
    float r;
    float *pr = &r;
    Vec *a = &ra;
    Vec *b = &rb;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        nop
        vdot.t S010, C000, C000
        vsqrt.s S010, S010
        sv.s S010, 0(pr)
    }
    return r;
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

static inline void vec_add(Vec &rd, Vec &rs) {
    Vec *dst = &rd;
    Vec *src = &rs;
    asm {
        lv.q C000, 0(dst)
        lv.q C010, 0(src)
        vadd.t C000, C000, C010
        sv.q C000, 0(dst)
    }
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

static inline char *slot_get(char *base, s32 i) {
    if (i < 0 || i >= 0x14) {
        return 0;
    }
    return *(char **)(base + 0x1220 + i * 4);
}

void func_088D6B00(char *arg0) {
    u32 step;
    s32 lean;
    u32 diff;

    if (*(u8 *)(arg0 + 0x2A4) != 0) {
        return;
    }
    if ((bool) (*(s32 *)(arg0 + 0x410) & 8) != 0 && *(u8 *)(arg0 + 0x298) == 0 && *(u8 *)(arg0 + 0x299) == 1) {
        step = 0x71C;
    } else if ((u8) func_08865CB8(arg0, 0, 1) != 0 || (u8) func_08865CB8(arg0, 0, 0x24) != 0) {
        step = 0x71C;
    } else if ((u8) func_08865CB8(arg0, 0, 0x1F) != 0) {
        step = 0x5B0;
    } else if ((u8) func_08865CB8(arg0, 0, 0x3F) != 0) {
        step = 0;
    } else if (*(u8 *)(arg0 + 0x1E8) == 0 && *(u8 *)(arg0 + 0x298) == 1
               && (u32) (*(u8 *)(arg0 + 0x299) - 0x1A) < 4) {
        step = 0x5B0;
    } else {
        step = 0xFA4;
    }
    if (*(u16 *)(arg0 + 0x324) != 3) {
        lean = 0;
    } else {
        lean = 0x80;
    }
    diff = (u16) (*(u16 *)(arg0 + 0x320) - (u16) *(s32 *)(arg0 + 0x1F4));
    if ((u16) (diff + step) < step * 2) {
        *(s32 *)(arg0 + 0x1F4) = *(u16 *)(arg0 + 0x320);
        if (*(u16 *)(arg0 + 0x41A) + 0x300 <= 0x600) {
            *(u16 *)(arg0 + 0x41A) = 0;
        } else if (*(u16 *)(arg0 + 0x41A) < 0x8000) {
            *(u16 *)(arg0 + 0x41A) = *(u16 *)(arg0 + 0x41A) - 0x300;
        } else {
            *(u16 *)(arg0 + 0x41A) = *(u16 *)(arg0 + 0x41A) + 0x300;
        }
    } else if (diff < 0x8000) {
        *(s32 *)(arg0 + 0x1F4) = (u16) (*(s32 *)(arg0 + 0x1F4) + step);
        *(u16 *)(arg0 + 0x41A) = *(u16 *)(arg0 + 0x41A) - lean;
    } else {
        *(s32 *)(arg0 + 0x1F4) = (u16) (*(s32 *)(arg0 + 0x1F4) - step);
        *(u16 *)(arg0 + 0x41A) = *(u16 *)(arg0 + 0x41A) + lean;
    }
    if (*(u16 *)(arg0 + 0x41A) <= 0xF600 && *(u16 *)(arg0 + 0x41A) >= 0xA00) {
        if (*(u16 *)(arg0 + 0x41A) >= 0x8000) {
            *(u16 *)(arg0 + 0x41A) = 0xF600;
        } else {
            *(u16 *)(arg0 + 0x41A) = 0xA00;
        }
    }
}

void func_088D6D10(char *arg0) {
    float best = 1500.0f;
    char *target;
    char *obj;
    u32 i;
    float d;
    Vec v;
    float ang;
    u16 goal;
    u16 dir;
    u16 cur;

    *(u8 *)(arg0 + 0x68B) = 0;
    if (*(u16 *)(arg0 + 0x324) == 0x26) {
        if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) {
            for (i = 0; i < 0x14; i++) {
                obj = func_09ADC408(D_09B23A98, i);
                if (obj != 0) {
                    d = vec_dist(*(Vec *)(arg0 + 0x200), *(Vec *)(obj + 0x200));
                    if (d <= best) {
                        *(u8 *)(arg0 + 0x68B) = 1;
                        best = d;
                        target = obj;
                    }
                }
            }
        } else {
            for (i = 0; i < 0x14; i++) {
                obj = slot_get(D_09C121B0, i);
                if (obj != 0) {
                    if ((bool) (*(s32 *)(obj + 0x638) & 4) != 0) {
                        d = vec_dist(*(Vec *)(arg0 + 0x200), *(Vec *)(obj + 0x200));
                        if (d <= best) {
                            best = d;
                            target = obj;
                            *(u8 *)(arg0 + 0x68B) = 1;
                        }
                    }
                }
            }
        }
    }
    if (*(u8 *)(arg0 + 0x68B) == 0) {
        cur = *(u16 *)(arg0 + 0x68C);
        if (cur != 0) {
            if (cur + 0x400 <= 0x800 && cur + 0x400 >= 0) {
                *(u16 *)(arg0 + 0x68C) = 0;
            } else if ((s16) cur >= 0) {
                *(u16 *)(arg0 + 0x68C) -= 0x400;
            } else {
                *(u16 *)(arg0 + 0x68C) += 0x400;
            }
        }
    } else {
        v.x = *(float *)(target + 0x200) - *(float *)(arg0 + 0x200);
        v.y = 0.0f;
        v.w = 0.0f;
        v.z = *(float *)(target + 0x208) - *(float *)(arg0 + 0x208);
        vec_normalize(&v, &v);
        ang = atan2_vfpu(-v.z, v.x);
        dir = (u16) (s32) (0.5f + 65536.0f * ang / 6.2831855f) + 0x4000;
        goal = dir + 0x10000 - *(s32 *)(arg0 + 0x1F4);
        if (goal >= 0x8000) {
            if (goal < 0xD556) {
                goal = 0xD556;
            }
            if (*(u16 *)(arg0 + 0x68C) >= 0x8000) {
                if (*(u16 *)(arg0 + 0x68C) - 0x800 <= goal) {
                    *(u16 *)(arg0 + 0x68C) = goal;
                } else {
                    *(u16 *)(arg0 + 0x68C) = *(u16 *)(arg0 + 0x68C) - 0x800;
                }
            } else {
                *(u16 *)(arg0 + 0x68C) = *(u16 *)(arg0 + 0x68C) - 0x800;
            }
        } else {
            if (goal > 0x2AAB) {
                goal = 0x2AAB;
            }
            if (*(u16 *)(arg0 + 0x68C) < 0x8000) {
                if (!(*(u16 *)(arg0 + 0x68C) + 0x800 < goal)) {
                    *(u16 *)(arg0 + 0x68C) = goal;
                } else {
                    *(u16 *)(arg0 + 0x68C) = *(u16 *)(arg0 + 0x68C) + 0x800;
                }
            } else {
                *(u16 *)(arg0 + 0x68C) = *(u16 *)(arg0 + 0x68C) + 0x800;
            }
        }
    }
}

void func_088D71B8(char *arg0) {
    if (*(s16 *)(arg0 + 0x670) > 0) {
        if ((*(s16 *)(arg0 + 0x670))-- > 0) {
            vec_add(*(Vec *)(arg0 + 0x200), *(Vec *)(arg0 + 0x660));
        }
    }
}

}
