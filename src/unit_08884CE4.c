/* unit_08884CE4: 0x08884CE4-0x08884E44 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08884CE4 (ULES01213)
 *
 * Speed setting (0x469AB000 built with lui/ori). The distance is VFPU code in
 * an `asm { }` block. `d` is declared before the table values to get $f21;
 * the 19800.0f test is written `if (max == K) d = max; else return 0;`.
 * With a mode other than 1 or 2, `d` is read uninitialised, as in the
 * original.
 */

#pragma optimize_for_size off

typedef int s32;
typedef float f32;

extern f32 D_089AB884[];
extern f32 D_089AB888[];
extern s32 *D_089ABCE0[];

extern f32 func_08897D28(f32);

static inline f32 vec_dist(f32 *a, f32 *b) {
    f32 r;
    f32 *pr = &r;
    asm {
        lv.q C000, 0(b)
        lv.q C010, 0(a)
        vsub.t C000, C000, C010
        nop
        vdot.t S010, C000, C000
        vsqrt.s S010, S010
        sv.s S010, 0(pr)
    }
    return r;
}

s32 func_08884CE4(char *arg0, f32 *arg1, f32 *arg2, s32 idx, s32 mode) {
    f32 d;
    f32 step;
    f32 max;
    f32 t;
    s32 *tbl;
    s32 v;

    step = D_089AB884[idx * 3];
    max = D_089AB888[idx * 3];
    tbl = D_089ABCE0[idx];
    if (mode == 1) {
        d = vec_dist(arg1, arg2);
        if (d >= max) {
            if (max == 19800.0f) {
                d = max;
            } else {
                return 0;
            }
        }
    } else if (mode == 2) {
        d = *(f32 *)(arg0 + 0x562460);
        if (d >= max) {
            if (max == 19800.0f) {
                d = max;
            } else {
                return 0;
            }
        }
    }
    t = func_08897D28(d / step);
    v = tbl[(s32)t];
    return v - (s32)(((d - step * t) / step) * (f32)(v - tbl[(s32)t + 1]));
}
