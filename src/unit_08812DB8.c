/* unit_08812DB8: 0x08812DB8-0x08812F18 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;

extern char D_08933A98;
extern char D_08933AA8;

typedef struct {
    f32 v[4];
    u8 unk10;
    u8 unk11;
    s16 unk12;
    u8 unk14;
} Src;

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

static inline f32 vec_dist(Src *a, char *base) {
    f32 r;
    f32 *pr = &r;
    f32 *b = (f32 *)(base + 0xB40);
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

void func_08812DB8(char *arg0, Src *arg1) {
    f32 amp;
    f32 k;
    f32 a;
    s32 idx;

    if (arg1->unk10 != 0) {
        idx = arg1->unk11 & 0x7F;
        a = 90.0f * ((f32)arg1->unk12 / (f32)((s16 *)&D_08933A98)[idx]);
        if (idx < 2) {
            amp = 10.0f;
        } else {
            amp = 12.0f;
        }
        amp = amp * sin_vfpu(6.2831855f * (a / 360.0f));
        if (arg1->unk11 & 0x80) {
            k = 1.0f;
        } else {
            f32 dist = vec_dist(arg1, arg0);
            f32 t = ((f32 *)&D_08933AA8)[arg1->unk14];
            if (dist >= t) {
                k = 0.0f;
            } else {
                k = 1.0f - dist / t;
            }
        }
        amp = amp * k;
        if ((arg1->unk12 >> 1) & 1) {
            amp = -amp;
        }
        *(f32 *)(arg0 + 0xB44) += amp;
        *(f32 *)(arg0 + 0xB54) += amp;
    }
}
