#pragma optimize_for_size off
/* unit_088840A8: 0x088840A8-0x088846F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed (saved registers). C++: virtual call 0x28 on
 * *D_09A4F060. Owns its jump table (6 words, jtbl_08931954 at 0x08931954).
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

typedef struct Vec4 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct Entry {
    s32 type;
    char pad4[0xC];
    Vec4 a;
    Vec4 b;
    s32 unk30;
    char pad34[0xC];
} Entry;

typedef struct Table {
    char pad0[0x38];
    Entry *ent;
    char pad3C[4];
    u8 count;
} Table;

struct Store {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual Table *vfunc_28();
};

extern "C" {

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern Store **D_09A4F060;

extern char *func_088DCEBC(s32, u8);
extern f32 func_09C35790(Vec4 *, Vec4 *, Vec4 *, f32 *);
extern s32 func_088846F4(char *, f32 *, Vec4 *, s32, s32, f32);

static inline f32 sqrt_vfpu(f32 x) {
    f32 r;
    f32 *pr = &r;
    f32 *px = &x;
    asm {
        lv.s S000, 0(px)
        vsqrt.s S000, S000
        sv.s S000, 0(pr)
    }
    return r;
}

static inline void vec_copy(Vec4 *src, Vec4 *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline f32 vec_dist(Vec4 *a, f32 *b) {
    f32 r;
    f32 *pr = &r;
    Vec4 *pa = a;
    f32 *pb = b;
    asm {
        lv.q C000, 0(pa)
        lv.q C010, 0(pb)
        vsub.t C000, C000, C010
        nop
        vdot.t S010, C000, C000
        vsqrt.s S010, S010
        sv.s S010, 0(pr)
    }
    return r;
}

s32 func_088840A8(char *arg0, u32 arg1, s32 arg2, f32 *arg3, s32 *arg4, f32 *arg5) {
    char *p;
    Entry *e;
    s32 result;
    f32 best;
    f32 dist2;
    s32 type2;
    s32 v48;
    s32 type1;
    s32 v44;
    s32 i;
    s32 count;
    s32 flags;
    Vec4 vec;
    Vec4 v90;
    Vec4 v80;
    Vec4 out70;
    Vec4 out60;
    f32 dx;
    f32 dz;
    f32 d;
    f32 d2;
    f32 y;

    p = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    dist2 = 0.0f;
    result = 0;
    e = (*D_09A4F060)->vfunc_28()->ent;
    if (e != 0) {
        best = -1.0f;
        type2 = 0;
        v44 = 0;
        type1 = 0;
        v48 = 0;
        flags = 0;
        count = (*D_09A4F060)->vfunc_28()->count;
        if (count != 0) {
        for (i = 0; i < count; i++, e++) {
            vec.w = 0.0f;
            switch (e->type) {
            case 0:
            case 3:
            case 4:
            case 5:
                if (e->type == 0) {
                    dx = arg3[0] - e->a.x;
                    dz = arg3[2] - e->a.z;
                } else {
                    dx = *(f32 *)(p + 0x200) - e->a.x;
                    dz = *(f32 *)(p + 0x208) - e->a.z;
                }
                d = sqrt_vfpu(dx * dx + dz * dz);
                if (best < 0.0f || best > d) {
                    best = d;
                    vec.x = e->a.x;
                    vec.y = e->a.y;
                    vec.z = e->a.z;
                    v48 = e->unk30;
                    type1 = e->type;
                }
                flags |= 1;
                break;
            case 1:
            case 2:
                dist2 = func_09C35790(&out70, &e->a, &e->b, arg3);
                if (e->type == 2) {
                    vec_copy(&e->a, &v80);
                    vec_copy(&e->b, &v90);
                    *arg4 = e->unk30;
                }
                v44 = e->unk30;
                type2 = e->type;
                flags |= 2;
                break;
            }
        }
        if (flags == 3) {
            if (dist2 < vec_dist(&vec, arg3)) {
                v48 = v44;
                vec.w = 0.0f;
                vec.z = 0.0f;
                vec.y = 0.0f;
                vec.x = 0.0f;
                type1 = type2;
            }
        } else if (flags == 2) {
            v48 = v44;
            type1 = type2;
        }
        if (type2 == 2 || type1 >= 3) {
            if ((arg1 >= 7 && arg1 <= 10) || (arg1 == 1 && arg2 == 0x60)) {
                *(s32 *)(arg0 + 0x562460) = 0;
                if (type2 == 2) {
                    *(f32 *)(arg0 + 0x562460) = dist2;
                    if (dist2 >= 3000.0f) {
                        d = func_09C35790(&out60, &v80, &v90, (f32 *)(p + 0x200));
                        if (d >= 1800.0f && d <= 3000.0f) {
                            *(s32 *)(arg0 + 0x56246C) = 0x41F00000;
                            *arg5 = 0.6f;
                            *arg4 = -1;
                        } else if (d < 1800.0f) {
                            *arg4 = 0x1F;
                        } else {
                            *arg4 = -1;
                        }
                    } else {
                        *arg4 = -1;
                    }
                }
                if (type1 == 3) {
                    y = *(f32 *)(p + 0x204);
                    if (y >= 1800.0f && y < 2400.0f) {
                        vec.y = y;
                    } else if (y >= 2400.0f) {
                        *arg5 = 0.5f;
                    }
                    if (vec_dist(&vec, (f32 *)(p + 0x200)) < 1800.0f) {
                        *arg5 = 0.3f;
                    } else {
                        *arg4 = -1;
                    }
                } else if (type1 == 4) {
                    d = vec_dist(&vec, (f32 *)(p + 0x200));
                    d2 = vec_dist(&vec, arg3);
                    if (d < 500.0f && d2 >= 500.0f) {
                        *arg5 = 0.3f;
                    } else {
                        *arg4 = -1;
                    }
                } else if (type1 == 5) {
                    d = vec_dist(&vec, (f32 *)(p + 0x200));
                    d2 = vec_dist(&vec, arg3);
                    if (d < 500.0f && d2 >= 500.0f) {
                        *arg5 = 0.5f;
                    } else {
                        *arg4 = -1;
                    }
                }
            } else {
                *arg4 = -1;
            }
        } else {
            result = func_088846F4(arg0, arg3, &vec, v48, type1, dist2);
        }
        }
    }
    return result;
}

}
