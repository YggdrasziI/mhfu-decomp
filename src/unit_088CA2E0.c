/* unit_088CA2E0: 0x088CA2E0-0x088CA39C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_089B5368;
extern f32 D_089B5370;
extern s32 __ptmf_test(f32 *);
extern int func_0880C464(void *, s32, s32);
extern s32 func_088626E4(s32);
extern s32 func_088CB364(s32);

void func_088CA2E0(s32 arg0) {
    F3 sp14;

    func_0880C464((void *) (arg0 + 0x1D0), 0, 0x20);
    func_0880C464((void *) (arg0 + 0x1F0), 0, 0x140);
    func_088626E4(arg0);
    *(s8 *)(arg0 + 0x330) = 0;
    *(s8 *)(arg0 + 0x3D4) = 0;
    *(s32 *)(arg0 + 4) = (s32) (*(s32 *)(arg0 + 4) & ~2);
    *(s16 *)(arg0 + 0x1C0) = 0;
    *(s16 *)(arg0 + 0x1C2) = 0;
    func_088CB364(arg0);
    sp14.a = D_089B5368.a;
    sp14.b = D_089B5368.b;
    sp14.c = D_089B5370;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x3D8) = sp14;
    }
}
