/* unit_0884853C: 0x0884853C-0x0884860C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32; typedef short s16; typedef unsigned char u8; typedef unsigned int u32; typedef float f32;

static inline float sqrt_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vsqrt.s S000, S000
        sv.s S000, 0(pr)
    }
    return r;
}

void func_0884853C(char *arg0, s16 arg1, u8 arg2) {
    s32 x;
    s32 y;
    u8 v;

    *(s16 *)(arg0 + 0x5A4) = arg1;
    *(u8 *)(arg0 + 0x5A3) = arg2;
    x = (*(u8 *)(arg0 + 0x5A3) & 7) * 28;
    y = (*(u8 *)(arg0 + 0x5A3) >> 3) * 24 - 94;
    { f32 d = sqrt_vfpu((f32)x * (f32)x + (f32)y * (f32)y); d = d * 1.7f; v = (u32)(0.1f * d); }
    *(u8 *)(arg0 + 0x5A1) = v;
    *(u8 *)(arg0 + 0x5A2) = v;
}
