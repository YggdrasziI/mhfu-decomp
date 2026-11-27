/* unit_0882E6F0: 0x0882E6F0-0x0882E7B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off


typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_08A631A0;

extern void func_0882E604(char *, u16, u16, u16, u8, u8, u8, u8);

static inline float sin_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

void func_0882E6F0(char *arg0, u16 x, u16 y, u16 dx, u8 a) {
    u32 phase;
    float ang;
    u8 g;

    phase = (u16)((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x3F) << 10);
    ang = phase;
    ang = 9.58737992e-05f * (float)ang;
    g = (s8)(48.0f * sin_vfpu(ang)) + 0xAF;
    func_0882E604(arg0, x, y, dx, 0x20, g, 0x20, a);
}
