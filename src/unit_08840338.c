/* unit_08840338: 0x08840338-0x0884054C (ULES01213)
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
extern char *D_08A62C7C;

extern s32 func_0886A35C(char *, s32);
extern void func_0882B624(char *, s32, s32, s32, s32, s32, s32, s32);
extern void func_0884054C(char *, s32, s32);

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

void func_08840338(char *arg0) {
    s32 a;
    s32 b;
    s32 alpha;
    s32 d;

    if (*(s32 *)(arg0 + 0x1194) & 1) {
        return;
    }
    *(s32 *)(arg0 + 0x558) = func_0886A35C(D_08A62C7C, 0);
    *(s32 *)(arg0 + 0x55C) = b = func_0886A35C(D_08A62C7C, 1);
    a = *(s32 *)(arg0 + 0x558);
    if (a > 9000) {
        alpha = 0xFF;
    } else if (a > 1800) {
        u32 phase;
        float ang;

        phase = (u16) ((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x1F) << 11);
        ang = phase;
        ang = 9.58737992e-05f * (float) ang;
        alpha = (u8) ((s8) (60.0f * sin_vfpu(ang)) + 0xC0);
    } else {
        u32 phase;
        float ang;

        phase = (u16) ((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x1F) << 12);
        ang = phase;
        ang = 9.58737992e-05f * (float) ang;
        alpha = (u8) ((s8) (120.0f * sin_vfpu(ang)) + 0x80);
    }
    func_0882B624(arg0, 8, 8, 0xFF, alpha, alpha, 0, 0);
    func_0884054C(arg0, b, 1);
    d = b - a;
    if (d < 0) {
        d = 0;
    }
    func_0884054C(arg0, d, 0);
}
