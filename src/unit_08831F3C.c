/* unit_08831F3C: 0x08831F3C-0x08831FF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

extern char *D_08A631A0;
extern void func_08831CB0(char *arg0, u16 arg1, u16 y, u16 arg3, u16 h, u8 r, u8 g, u8 b, u8 a);

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

void func_08831F3C(char *arg0, u16 arg1, u16 y, u16 arg3, u16 h, u8 r, u8 g, u8 b) {
    u16 t = (*(u32 *)(D_08A631A0 + 0xF7A554) & 0x3F) << 10;
    func_08831CB0(arg0, arg1, y, arg3, h, r, g, b,
                  (u8)((s8)(s32)(48.0f * sin_vfpu(9.58738e-5f * (u32)t)) + 0xBF));
}
