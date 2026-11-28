/* unit_088949EC: 0x088949EC-0x08894B00 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern void func_08890C94(u8 *, s32, s32, s32);

static inline f32 sin_vfpu(f32 x) {
    f32 r;
    f32 a = x;
    f32 *pr = &r;
    f32 *px = &a;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S000, S000
        sv.s S000, 0(pr)
    }
    return r;
}

void func_088949EC(u8 *arg0) {
    f32 s = sin_vfpu(3.1415927f * (f32)(u16)((arg0[0x15E] & 0x1F) << 11) / 32768.0f);
    func_08890C94(arg0, -1, 0,
                  (u8)((s8)(s32)(7.0f * s) + 0xF7) |
                  (0xFF000000 | ((u8)((s8)(s32)(64.0f * s) + 0x50) << 16) |
                   ((u8)((s8)(s32)(20.0f * s) + 0xE4) << 8)));
}
