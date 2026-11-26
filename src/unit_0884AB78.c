/* unit_0884AB78: 0x0884AB78-0x0884AC20 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884AB78: 0x0884AB78-0x0884AC20 (ULES01213) */

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef float f32;

extern s16 D_0893A36C[];

extern void func_0882D220(s32, u16, u16, u32, u32, s32, s32, s32);

void func_0884AB78(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 scale) {
    s16 *p = (s16 *)(s32)D_0893A36C;
    func_0882D220(arg0, arg1, arg2, (u32)(p[2] * scale),
                  (u32)(p[3] * scale), arg3, arg4, 0x17B);
}
