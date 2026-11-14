/* unit_0885A994: 0x0885A994-0x0885AA20 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_0899D170;
extern f32 D_0899D178;
extern f32 D_0899D17C;
extern char D_089BAAF4;
extern char D_089BAB98;
extern s32 __ptmf_test(f32 *);

char *func_0885A994(char *arg0) {
    F3 sp14;

    *(char **)arg0 = &D_089BAB98;
    sp14.a = D_0899D170.b;
    sp14.b = D_0899D178;
    sp14.c = D_0899D17C;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x4) = sp14;
    }
    *(char **)arg0 = &D_089BAAF4;
    *(s32 *)(arg0 + 0x1C) = 0;
    return arg0;
}
