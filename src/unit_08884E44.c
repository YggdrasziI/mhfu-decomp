/* unit_08884E44: 0x08884E44-0x08885088 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08884E44: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

#pragma optimize_for_size off

typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern char *D_089CBBE4;
extern f32 D_089AA35C[];
extern f32 D_089AA364[];

extern void func_08883384(char *);
extern s32 func_088849B4(char *, f32 *, s32);
extern void func_08814674(char *, float *, float *);

static inline void vec_dist(float *a, float *b, float *out) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        nop
        vdot.t S010, C000, C000
        vsqrt.s S010, S010
        sv.s S010, 0(out)
    }
}

static inline void cos_vfpu(float *px, float *pr) {
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vcos.s S010, S000
        sv.s S010, 0(pr)
    }
}

void func_08884E44(char *arg0, f32 *arg1, s32 arg2, s32 *arg3, s32 *arg4) {
    f32 dist;
    f32 ang;
    f32 c;
    Vec v;
    f32 max;
    f32 d;

    max = D_089AA364[arg2 * 3];
    func_08883384(arg0);
    *arg3 = func_088849B4(arg0, arg1, arg2);
    vec_dist(arg1, (f32 *)(arg0 + 0x5623F0), &dist);
    d = dist;
    if (d < 0.0f) {
        d = 0.0f;
    }
    if (d >= max) {
        if (max == 19800.0f) {
            d = max;
        } else {
            *arg3 = 0;
            return;
        }
    }
    if (d < D_089AA35C[arg2 * 3]) {
        *arg4 = 0x40;
        *arg3 = 0x7F;
        return;
    }
    func_08814674(D_089CBBE4, &v.x, arg1);
    if (v.x < 0.0f) {
        v.x = 0.0f;
    }
    if (v.x > 480.0f) {
        v.x = 480.0f;
    }
    if (v.w < 0.0f) {
        v.x = 480.0f - v.x;
    }
    ang = v.x;
    ang = 6.2831855f * (1.4173229f * (ang / 3.7795277f) / 360.0f);
    cos_vfpu(&ang, &c);
    *arg4 = (s32)(63.0f - 48.0f * c);
}
