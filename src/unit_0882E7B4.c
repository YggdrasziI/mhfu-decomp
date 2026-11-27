/* unit_0882E7B4: 0x0882E7B4-0x0882E86C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off


typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_08A631A0;

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

u32 func_0882E7B4(void) {
    u32 phase;
    float ang;

    phase = (u16) ((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x3F) << 10);
    ang = phase;
    ang = 9.58737992e-05f * (float) ang;
    return (((s8) (48.0f * sin_vfpu(ang)) + 0xAF) << 8) | 0xF0200020;
}
