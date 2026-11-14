/* unit_0887F464: 0x0887F464-0x0887F4F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_089A8A10;
extern f32 D_089A8A18;
extern char D_089BAB84;
extern char D_089BAB98;
extern s32 __ptmf_test(f32 *);

char *func_0887F464(char *arg0) {
    F3 sp14;

    *(char **)arg0 = &D_089BAB98;
    sp14.a = D_089A8A10.a;
    sp14.b = D_089A8A10.b;
    sp14.c = D_089A8A18;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x4) = sp14;
    }
    *(char **)arg0 = &D_089BAB84;
    *(s32 *)(arg0 + 0x1C) = 0;
    return arg0;
}
