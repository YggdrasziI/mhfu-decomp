/* unit_08825EE8: 0x08825EE8-0x088260D4 (ULES01213)
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
extern u16 D_08938690[];

extern s32 func_08830078(char *, char *, s16, s16, s32, char *, s32);
extern void func_0882B624(char *, u16, u16, u8, u8, s32, s32, s32);

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

void func_08825EE8(char *arg0, char *arg1, char *arg2, s16 arg3, s16 arg4, s32 arg5, s32 arg6) {
    s32 mode;
    u32 phase;
    float ang;
    float s;

    if (arg6 == 0) {
        mode = 1;
    } else {
        mode = 2;
    }
    func_08830078(arg0, arg1, arg3, arg4, (arg5 | 0x20) & ~8, arg2, mode);
    func_08830078(arg0, arg2, arg3, (s16)(arg4 + 0x78 + D_08938690[arg6]), arg5, arg1, mode);
    phase = (u16)((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x1F) << 11);
    ang = phase;
    ang = 9.58737992e-05f * (float)ang;
    s = sin_vfpu(ang);
    func_0882B624(arg0, arg3 + 0x68, arg4 + 0x70 + D_08938690[arg6], (s8)(95.0f * s) + 0x9F, (s8)(63.0f * s) + 0xBF, 0xFF, 0x9C, 0);
}
