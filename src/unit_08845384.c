/* unit_08845384: 0x08845384-0x0884558C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);

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

void func_08845384(char *arg0, s32 x, s32 y, s32 c, float scale, float t) {
    u8 a;
    s16 s;
    s32 x0;
    s32 y0;
    u16 xx;
    u16 yy;

    a = (u32)(51.0f * sqrt_vfpu(t));
    s = (s32)(scale * (0.291667014f + 0.1180555f * sqrt_vfpu(25.0f - t)));
    y0 = (s16)y - s;
    x0 = (s16)x - s;
    func_0882C7B4(arg0, x0, y0, s, s, ((u8 *)&c)[0], ((u8 *)&c)[1], ((u8 *)&c)[2], a, 0x7E, 5);
    yy = y;
    func_0882C7B4(arg0, x0, yy, s, s, ((u8 *)&c)[0], ((u8 *)&c)[1], ((u8 *)&c)[2], a, 0x7E, 1);
    xx = x;
    func_0882C7B4(arg0, xx, y0, s, s, ((u8 *)&c)[0], ((u8 *)&c)[1], ((u8 *)&c)[2], a, 0x7E, 4);
    func_0882C7B4(arg0, xx, yy, s, s, ((u8 *)&c)[0], ((u8 *)&c)[1], ((u8 *)&c)[2], a, 0x7E, 0);
}
