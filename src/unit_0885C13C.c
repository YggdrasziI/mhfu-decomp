/* unit_0885C13C: 0x0885C13C-0x0885C290 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Compiled for speed (pragma below); the (s16)(u16) cast keeps the `seh`
 * of the loaded byte.
 */

#pragma optimize_for_size off
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    u16 a;
    u16 b;
} Pair;

extern Pair D_089A5864[];

extern s32 func_0885B5B8(s32, s32, s32, s32, s32, s32);

s32 func_0885C13C(s32 arg0, u8 *arg1, s32 step, u16 *out0, u16 *out1, s32 arg5) {
    s32 s;
    s32 r;
    s32 n;
    s32 idx;
    Pair *p;

    idx = (s16)(u16)*arg1;
    if ((s8)step == 0) {
        p = &D_089A5864[(s16)idx];
        r = func_0885B5B8(arg0, (s16)p->a, (s16)p->b, arg5, 0, 0);
        if (r != 0) {
            *out0 = p->a;
            *out1 = p->b;
            return r;
        }
        step = 1;
    }
    s = (s8)step;
    n = 0xAC;
    do {
        idx = (s16)(idx + s);
        if (idx > 0xAB) {
            idx = 0;
        } else if (idx < 0) {
            idx = 0xAB;
        }
        p = &D_089A5864[(s16)idx];
        r = func_0885B5B8(arg0, (s16)p->a, (s16)p->b, arg5, 0, 0);
        if (r != 0) {
            *arg1 = idx;
            *out0 = p->a;
            *out1 = p->b;
            return r;
        }
    } while (--n != 0);
    return 0;
}
