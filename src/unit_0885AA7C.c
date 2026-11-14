/* unit_0885AA7C: 0x0885AA7C-0x0885AAEC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_0899D180;
extern f32 D_0899D188;
extern s32 __ptmf_test(f32 *);

void func_0885AA7C(char *arg0) {
    F3 sp14;

    *(s32 *)(arg0 + 0x1C) = 0;
    sp14.a = D_0899D180.a;
    sp14.b = D_0899D180.b;
    sp14.c = D_0899D188;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x4) = sp14;
    }
}
