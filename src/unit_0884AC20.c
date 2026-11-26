/* unit_0884AC20: 0x0884AC20-0x0884AE14 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884AC20: 0x0884AC20-0x0884AE14 (ULES01213) */

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef float f32;

extern s16 D_0893B79C;
extern s16 D_0893B79E;
extern s16 D_0893B7A0;
extern s16 D_0893B7A2;

extern void func_0882D470(s32, s32, s32, s32, s32, s32, s32, s16, s32, s32);

void func_0884AC20(s32 arg0, u16 arg1, u16 arg2, s16 arg3, s32 arg4, f32 scale) {
    s16 v = (s16)(s32)(80.0f * scale);

    func_0882D470(arg0, arg1, arg2, v, v, (u32)(D_0893B79C * scale),
                  (u32)(D_0893B79E * scale), (s16)(arg3 + 0x4000), arg4, 0x17C);
    func_0882D470(arg0, arg1, arg2, v, v, (u32)(D_0893B7A0 * scale),
                  (u32)(D_0893B7A2 * scale), (s16)(arg3 - 0x4000), arg4, 0x17D);
}
