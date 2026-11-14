/* unit_0884D06C: 0x0884D06C-0x0884D0FC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_0893B800;
extern f32 D_0893B808;
extern char D_089BAA80;
extern char D_089BAB98;
extern s32 __ptmf_test(f32 *);

char *func_0884D06C(char *arg0) {
    F3 sp14;

    *(char **)arg0 = &D_089BAB98;
    sp14.a = D_0893B800.a;
    sp14.b = D_0893B800.b;
    sp14.c = D_0893B808;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x4) = sp14;
    }
    *(char **)arg0 = &D_089BAA80;
    *(s32 *)(arg0 + 0x1C) = 0;
    *(s32 *)(arg0 + 0x20) = 0;
    return arg0;
}
