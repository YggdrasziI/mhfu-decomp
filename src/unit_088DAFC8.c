/* unit_088DAFC8: 0x088DAFC8-0x088DB068 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_089B6560;
extern f32 D_089B6568;
extern f32 D_089B656C;
extern s32 __ptmf_test(f32 *);

void func_088DAFC8(char *arg0) {
    F3 sp14;

    *(s32 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x24) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    *(s32 *)(arg0 + 0x28) = 0;
    *(s32 *)(arg0 + 0x14) = 0;
    *(s32 *)(arg0 + 0x2C) = 0;
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x1C) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    *(s32 *)(arg0 + 0x20) = 0;
    *(s32 *)(arg0 + 0x38) = 0;
    *(s32 *)(arg0 + 0x3C) = 0;
    sp14.a = D_089B6560.b;
    sp14.b = D_089B6568;
    sp14.c = D_089B656C;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x0) = sp14;
    }
}
