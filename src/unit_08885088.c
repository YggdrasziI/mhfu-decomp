/* unit_08885088: 0x08885088-0x088851C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef float f32;

typedef struct {
    f32 v;
    f32 pad[2];
} Ent12;

extern Ent12 D_089AB880[];
extern Ent12 D_089AB888[];
extern s32 D_08A62D84;

extern s32 func_08884CE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_0887FBBC(s32);

void func_08885088(s32 arg0, f32 *arg1, f32 *arg2, s32 arg3, s32 *arg4, s32 arg5) {
    f32 lim = D_089AB888[arg3].v;
    f32 d;
    f32 *pd;
    f32 x;

    *arg4 = func_08884CE4(arg0, (s32)arg1, (s32)arg2, arg3, arg5);
    if (func_0887FBBC(D_08A62D84) == 2) {
        return;
    }
    if (arg5 != 1) {
        return;
    }
    pd = &d;
    asm {
        lv.q C000, 0x0(arg2)
        lv.q C010, 0x0(arg1)
        vsub.t C000, C000, C010
        nop
        vdot.t S010, C000, C000
        vsqrt.s S010, S010
        sv.s S010, 0x0(pd)
    }
    x = d;
    if (x < 0.0f) {
        x = 0.0f;
    }
    if (x >= lim) {
        if (lim == 19800.0f) {
            x = lim;
        } else {
            *arg4 = 0;
            return;
        }
    }
    if (x < D_089AB880[arg3].v) {
        *arg4 = 0;
    }
}
