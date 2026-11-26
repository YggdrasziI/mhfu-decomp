/* unit_0884424C: 0x0884424C-0x08844304 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884424C (ULES01213)
 *
 * Needs #pragma opt_propagation off: with copy propagation on, the
 * trunc.w.s of the width is hoisted before both unsigned conversions.
 */

#pragma opt_propagation off

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    u8 r, g, b, a;
} B4;

extern void func_0882C11C(char *, s32, s32, s32, s32, u8, u8, u8, u8, s32);

void func_0884424C(char *arg0, B4 c, f32 x, f32 y, f32 z) {
    f32 w = z + z;
    u32 a = x - z;
    u32 b = y - z;
    s32 i = w;

    func_0882C11C(arg0, a, b, i, i, c.b, c.g, c.r, c.a, 0x93);
}
