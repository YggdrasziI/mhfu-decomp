/* unit_088B9DA8: 0x088B9DA8-0x088B9E34 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_089B2B60;
extern f32 D_089B2B68;
extern f32 D_089B2B6C;
extern char D_089BAB98;
extern char D_089BAC94;
extern s32 __ptmf_test(f32 *);

char *func_088B9DA8(char *arg0) {
    F3 sp14;

    *(char **)arg0 = &D_089BAB98;
    sp14.a = D_089B2B60.b;
    sp14.b = D_089B2B68;
    sp14.c = D_089B2B6C;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x4) = sp14;
    }
    *(char **)arg0 = &D_089BAC94;
    *(s32 *)(arg0 + 0x1C) = 0;
    return arg0;
}
