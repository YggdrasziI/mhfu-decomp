/* unit_0882F4A4: 0x0882F4A4-0x0882F580 (ULES01213)
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

extern void func_0882D8DC(char *, u16, u16, u16, u16, s32, s32, s32, s32);

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

void func_0882F4A4(char *arg0, u16 x, u16 y, u16 w, u16 h, u32 col) {
    u32 c;
    u16 ang;
    float s;

    ang = (*(u32 *)(D_08A631A0 + 0xF7A554) & 0x3F) << 10;
    s = sin_vfpu(9.58738e-05f * (float)(u32)ang);
    c = (col & 0xFFFFFF) | ((u32)((s8)(s32)(48.0f * s) + 0xBF) << 24);
    func_0882D8DC(arg0, x, y, w, h, ((u8 *)&c)[2], ((u8 *)&c)[1], ((u8 *)&c)[0], ((u8 *)&c)[3]);
}
