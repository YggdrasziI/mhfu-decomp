/* unit_088630D0: 0x088630D0-0x08863198 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef float f32;

extern s16 func_08863668(void *arg0, f32 arg1, void *arg2, s16 **arg3, s16 **arg4, s16 arg5);
extern f32 func_08862FE0(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);

f32 func_088630D0(void *arg0, f32 arg1, void *arg2, s16 *arg3) {
    s16 *a = 0;
    s16 *b = 0;

    *arg3 = func_08863668(arg0, arg1, arg2, &a, &b, *arg3);
    if (b == 0) {
        return a[0];
    }
    return func_08862FE0(arg0, arg1, a[0], a[1], a[3], b[0], b[1], b[2]);
}
