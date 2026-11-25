/* unit_0885F8E8: 0x0885F8E8-0x0885F928 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885F8E8: when f0 is negative, calls func_0885FFBC with (0, f1 - f0),
 * otherwise with (f0, f1); arg0-arg2 are passed on unchanged (func_0885FFBC
 * reads $a0-$a2).
 */

typedef int s32;
typedef float f32;

extern void func_0885FFBC(s32 arg0, s32 arg1, s32 arg2, f32 f0, f32 f1);

void func_0885F8E8(s32 arg0, s32 arg1, s32 arg2, f32 f0, f32 f1) {
    if (f0 < 0.0f) {
        func_0885FFBC(arg0, arg1, arg2, 0.0f, f1 - f0);
    } else {
        func_0885FFBC(arg0, arg1, arg2, f0, f1);
    }
}
