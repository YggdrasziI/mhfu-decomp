/* func_088C88FC (ULES01213): texture scroll by a sine wave (hypothesis). */

#pragma optimize_for_size off

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Wave {
    u16 period;
    u16 step;
    f32 base;
    f32 amp;
} Wave;

typedef struct Anim {
    Wave u;
    Wave v;
} Anim;

extern s32 *D_089CC000;
extern void func_0886171C(char *, s32, char *, s32);

static inline f32 sin_vfpu(f32 x) {
    f32 r;
    f32 *pr = &r;
    f32 *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

void func_088C88FC(char *arg0, char *arg1, Anim *arg2, s32 arg3) {
    f32 su;
    f32 sv;

    if (arg2->u.period != 0) {
        su = arg2->u.base + arg2->u.amp * sin_vfpu(6.2831855f * (360.0f * (f32)(arg2->u.step * (*(u16 *)(arg0 + 0x1C0) % arg2->u.period)) / 65536.0f / 360.0f));
        *D_089CC000 = (*(u32 *)&su >> 8) | 0x4A000000;
        D_089CC000++;
    }
    if (arg2->v.period != 0) {
        sv = arg2->v.base + arg2->v.amp * sin_vfpu(6.2831855f * (360.0f * (f32)(arg2->v.step * (*(u16 *)(arg0 + 0x1C0) % arg2->v.period)) / 65536.0f / 360.0f));
        *D_089CC000 = (*(u32 *)&sv >> 8) | 0x4B000000;
        D_089CC000++;
    }
    func_0886171C(arg1, 0, arg0 + 0x70, arg3);
    *D_089CC000 = 0x4A000000;
    D_089CC000++;
    *D_089CC000 = 0x4B000000;
    D_089CC000++;
}
