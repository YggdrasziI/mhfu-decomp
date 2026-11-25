/* unit_08845270: 0x08845270-0x08845384 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef short s16;
typedef int s32;
typedef float f32;

extern f32 D_0893B640;
extern void func_08845384(s32, s32, s32, s32, f32, f32);

void func_08845270(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4) {
    s16 r;
    s32 d;

    if (arg3 < 20) {
        func_08845384(arg0, arg1, arg2, arg4, D_0893B640, (f32)(25 - arg3));
    } else if (arg3 < 85) {
        r = arg3 % 20;
        func_08845384(arg0, arg1, arg2, arg4, D_0893B640, (f32)(25 - r));
        d = 5 - r;
        if (d >= 0) {
            func_08845384(arg0, arg1, arg2, arg4, D_0893B640, (f32)d);
        }
    } else {
        func_08845384(arg0, arg1, arg2, arg4, D_0893B640, (f32)(105 - arg3));
    }
}
