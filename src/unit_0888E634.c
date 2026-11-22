/* unit_0888E634: 0x0888E634-0x0888E788 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
typedef float f32;

s32 func_0888E634(s32 arg0, u32 t, f32 lo, f32 hi, f32 amp) {
    f32 f;
    f32 a;
    f32 b;
    if ((f32)t <= lo) {
        return 0;
    }
    if (!((f32)t < hi)) {
        if ((f32)t <= 65536.0f - hi) {
            return 0;
        }
        if ((f32)t < 65536.0f - lo) {
            t = 0x10000 - t;
            amp = -amp;
        } else {
            return 0;
        }
    }
    f = (f32)(s32)t;
    a = f - lo;
    b = hi - f;
    return (s32)(amp * (((1.0f / 65536.0f) * (a * a)) * ((1.0f / 65536.0f) * (b * b))));
}
