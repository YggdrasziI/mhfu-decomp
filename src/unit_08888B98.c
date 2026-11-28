/* unit_08888B98: 0x08888B98-0x08889C90 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08888B98: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks").
 * The yaw goes through vec_yaw (atan2 two inline levels deep) and the pitch
 * calls atan2 directly: this sets the stack slot order of the inlined
 * locals. s16 rot[3] (not [2]) places the local angles at sp+0x118. */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct {
    Vec pos;
    Vec tgt;
    Vec pos2;
    Vec tgt2;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4C;
    s16 s50;
    s16 s52;
    s16 pad54[2];
    s16 rot[2];
} Cam;

typedef struct {
    Vec pos;
    Vec tgt;
    Vec pad20;
    Vec dir;
    char pad40[0x40];
    f32 f80;
    f32 pad84;
    f32 f88;
    char pad8C[5];
    u8 b91;
    char pad92[6];
    union {
        s32 w;
        u8 b;
    } u98;
    u8 b9C;
    char pad9D[3];
    Cam cam;
} Obj;

extern char *D_089CBBE4;
extern char D_08A62DA0[];

extern void func_0888D0A8(Obj *, Vec *, char *);
extern s32 func_0888A330(Obj *, char *, u8);
extern void func_0888B600(Obj *, Vec *, char *, float);
extern void func_0888B6AC(Obj *, Vec *, char *, Vec *);
extern void func_0888B7FC(Obj *, Cam *, char *);
extern float func_0888C318(Obj *, char *, s32, float);
extern float func_0888C344(float, Obj *, char *, s32);
extern void func_08897BD8(Vec *, Vec *, Vec *);
extern float func_0888C294(Obj *, float, char *);
extern void func_0888E350(Obj *, char *);
extern float func_0888E3DC(Obj *);

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

static inline void vec_sub(Vec *a, Vec *b, Vec *dst) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.q C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_copy(Vec *src, Vec *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void vec_dist_o(Vec *a, Vec *b, float *pr) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        nop
        vdot.t S010, C000, C000
        vsqrt.s S010, S010
        sv.s S010, 0(pr)
    }
}

static inline float vec_dist(Vec *a, Vec *b) {
    float r;
    vec_dist_o(a, b, &r);
    return r;
}

static inline void vec_len_o(Vec *a, float *pr) {
    asm {
        lv.q C000, 0(a)
        vdot.t S010, C000, C000
        vsqrt.s S010, S010
        sv.s S010, 0(pr)
    }
}

static inline float vec_len(Vec *a) {
    float r;
    vec_len_o(a, &r);
    return r;
}

static inline void rot_x(Vec *v, float ang) {
    float *pa = &ang;
    asm {
        lv.q C000, 0(v)
        lv.q C100, 0(v)
        lv.s S110, 0(pa)
        vcst.s S111, VFPU_2_PI
        vmul.s S122, S110, S111
        vsin.s S120, S122
        vcos.s S121, S122
        vmul.s S001, S121, S101
        vmul.s S130, S120, S102
        vsub.s S001, S001, S130
        vmul.s S002, S120, S101
        vmul.s S130, S121, S102
        vadd.s S002, S002, S130
        sv.q C000, 0(v)
    }
}

static inline void rot_y(Vec *v, float ang) {
    float *pa = &ang;
    asm {
        lv.q C000, 0(v)
        lv.q C100, 0(v)
        lv.s S110, 0(pa)
        vcst.s S111, VFPU_2_PI
        vmul.s S122, S110, S111
        vsin.s S120, S122
        vcos.s S121, S122
        vmul.s S000, S121, S100
        vmul.s S130, S120, S102
        vadd.s S000, S000, S130
        vmul.s S002, S120, S100
        vmul.s S130, S121, S102
        vsub.s S002, S130, S002
        sv.q C000, 0(v)
    }
}

/* dst = a * t + b * u */
static inline void vec_lerp(Vec *b, Vec *a, Vec *dst, float t, float u) {
    float *pt = &t;
    float *pu = &u;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        lv.s S020, 0(pt)
        lv.s S021, 0(pu)
        vscl.t C100, C000, S020
        vscl.t C110, C010, S021
        vadd.t C000, C100, C110
        sv.q C000, 0(dst)
    }
}

static inline s16 vec_yaw(Vec *d) {
    return (s16)(10430.378f * atan2_vfpu(d->x, d->z));
}

void func_08888B98(Obj *arg0) {
    char *g = D_089CBBE4;
    char *w = *(char **)(g + 0xA84);
    Cam *c;
    char *s2;
    char *s1;
    f32 scale;
    Vec v;
    float t;
    float u;

    arg0->b91 = 0;
    c = &arg0->cam;
    if (*(u8 *)(g + 0xA8D) != 2) {
        arg0->u98.w = 0;
        return;
    }
    s2 = *(char **)(g + 0xA90);
    if (*(u8 *)(s2 + 2) == 0) {
        arg0->u98.w = 0;
        *(u8 *)(g + 0xA8D) = 0;
        return;
    }
    switch (arg0->u98.b) {
    case 0:
        arg0->u98.b++;
        arg0->b91 = 1;
        arg0->b9C = 0;
        switch (*(u8 *)(s2 + 2)) {
        case 1:
            c->pos.x = *(f32 *)(s2 + 0x20);
            c->pos.y = *(f32 *)(s2 + 0x24);
            c->pos.z = *(f32 *)(s2 + 0x28);
            c->pos.w = 1.0f;
            func_0888D0A8(arg0, &c->tgt, s2);
            c->f40 = *(f32 *)(g + 0xC);
            break;
        case 3:
            c->pos.x = *(f32 *)(w + 0x200) + *(f32 *)(s2 + 0x20);
            c->pos.y = *(f32 *)(w + 0x204) + *(f32 *)(s2 + 0x24);
            c->pos.z = *(f32 *)(w + 0x208) + *(f32 *)(s2 + 0x28);
            c->pos.w = 1.0f;
            func_0888D0A8(arg0, &c->tgt, s2);
            c->f40 = *(f32 *)(g + 0xC);
            break;
        case 2:
            func_0888A330(arg0, w + 0x200, 0);
            func_0888B600(arg0, &v, D_08A62DA0 + *(u8 *)(g + 0xAA0) * 0x40, *(f32 *)(g + 0xA98));
            func_0888B6AC(arg0, &c->tgt, s2, &v);
            func_0888B7FC(arg0, c, s2);
            c->f40 = *(f32 *)(g + 0xC);
            break;
        }
        vec_sub(&c->tgt, &c->pos, &arg0->dir);
        {
            Vec a;
            Vec b;
            float d;

            c->rot[1] = vec_yaw(&arg0->dir);
            vec_copy(&c->tgt, &a);
            vec_copy(&c->pos, &b);
            a.y = 0.0f;
            b.y = 0.0f;
            d = vec_dist(&a, &b);
            c->rot[0] = (s16)(10430.378f * atan2_vfpu(-arg0->dir.y, d));
        }
        c->s52 = 0;
        c->s50 = 0;
        break;
    case 1:
        arg0->b91 = 1;
        switch (*(u8 *)(s2 + 2)) {
        case 1:
            c->pos.x = *(f32 *)(s2 + 0x20);
            c->pos.y = *(f32 *)(s2 + 0x24);
            c->pos.z = *(f32 *)(s2 + 0x28);
            func_0888D0A8(arg0, &c->tgt, s2);
            scale = *(f32 *)(s2 + 0x50);
            c->f44 = *(f32 *)(s2 + 0x54);
            break;
        case 3:
            c->pos.x = *(f32 *)(w + 0x200) + *(f32 *)(s2 + 0x20);
            c->pos.y = *(f32 *)(w + 0x204) + *(f32 *)(s2 + 0x24);
            c->pos.z = *(f32 *)(w + 0x208) + *(f32 *)(s2 + 0x28);
            func_0888D0A8(arg0, &c->tgt, s2);
            scale = *(f32 *)(s2 + 0x50);
            c->f44 = *(f32 *)(s2 + 0x54);
            break;
        case 2:
            s1 = s2 + 0x20;
            if (*(u8 *)(g + 0xA8B) == 0) {
                func_0888A330(arg0, w + 0x200, 1);
            } else {
                func_0888A330(arg0, w + 0x200, 0);
            }
            func_0888B600(arg0, &v, D_08A62DA0 + *(u8 *)(g + 0xAA0) * 0x40, *(f32 *)(g + 0xA98));
            scale = func_0888C318(arg0, s1, *(u8 *)(g + 0xAA0), *(f32 *)(g + 0xA9C));
            c->f44 = func_0888C344(*(f32 *)(g + 0xA9C), arg0, s1, *(u8 *)(g + 0xAA0));
            func_0888B6AC(arg0, &c->tgt, s2, &v);
            func_0888B7FC(arg0, c, s2);
            break;
        }
        vec_sub(&c->tgt, &c->pos, &arg0->dir);
        if (*(u8 *)(g + 0xA8B) != 0) {
            Vec a;
            Vec b;
            float d;

            c->rot[1] = vec_yaw(&arg0->dir);
            vec_copy(&c->tgt, &a);
            vec_copy(&c->pos, &b);
            a.y = 0.0f;
            b.y = 0.0f;
            d = vec_dist(&a, &b);
            c->rot[0] = (s16)(10430.378f * atan2_vfpu(-arg0->dir.y, d));
            c->s52 = 0;
            c->s50 = 0;
        } else {
            s16 rot[3];
            s16 diff;
            s16 lim;
            s16 roll;
            s16 pitch;

            {
                Vec a;
                Vec b;
                float d;

                rot[1] = vec_yaw(&arg0->dir);
                vec_copy(&c->tgt, &a);
                vec_copy(&c->pos, &b);
                a.y = 0.0f;
                b.y = 0.0f;
                d = vec_dist(&a, &b);
                pitch = (s16)(10430.378f * atan2_vfpu(-arg0->dir.y, d));
            }
            rot[0] = pitch;
            lim = (s16)(521.51892f * c->f40);
            roll = (s16)(52.15189f * c->f40);
            diff = pitch - c->rot[0];
            if (lim < diff) {
                c->rot[0] = pitch - lim;
                c->s50 = roll;
            } else if (diff < -lim) {
                c->rot[0] = pitch + lim;
                c->s50 = -roll / 2;
            }
            {
                f32 f = 651.89862f * c->f40;

                lim = (s16)(1.7647059f * f);
            }
            diff = rot[1] - c->rot[1];
            if (lim < diff) {
                c->s52 = c->rot[1];
                c->rot[1] = rot[1] - lim;
                c->s52 = c->rot[1] - c->s52;
                c->s52 = c->s52 - (s16)(c->s52 >> 2);
            } else if (diff < -lim) {
                c->s52 = c->rot[1];
                c->rot[1] = rot[1] + lim;
                c->s52 = c->rot[1] - c->s52;
                c->s52 = c->s52 - (s16)(c->s52 >> 2);
            }
        }
        v.x = v.y = 0.0f;
        v.z = vec_len(&arg0->dir);
        rot_x(&v, 9.58738019e-05f * (float)c->rot[0]);
        rot_y(&v, 9.58738019e-05f * (float)c->rot[1]);
        func_08897BD8(&c->tgt, &c->pos, &v);
        c->f40 = scale * func_0888C294(arg0, vec_dist(&c->tgt, &c->pos), s2);
        break;
    }
    func_0888E350(arg0, s2);
    switch (arg0->b9C) {
    case 0:
        vec_copy(&c->pos, &arg0->pos);
        vec_copy(&c->tgt, &arg0->tgt);
        arg0->f80 = c->f44;
        arg0->f88 = c->f40;
        return;
    case 1:
        vec_copy((Vec *)(g + 0x20), &c->pos2);
        vec_copy((Vec *)(g + 0x30), &c->tgt2);
        c->f4C = *(f32 *)(g + 0xA0);
        c->f48 = *(f32 *)(g + 0xA8);
        arg0->b9C++;
    case 2:
        t = func_0888E3DC(arg0);
        u = 1.0f - t;
        vec_lerp(&c->pos, &c->pos2, &arg0->pos, t, u);
        vec_lerp(&c->tgt, &c->tgt2, &arg0->tgt, t, u);
        arg0->f80 = c->f4C * t + c->f44 * u;
        arg0->f88 = c->f48 * t + c->f40 * u;
        break;
    }
}
