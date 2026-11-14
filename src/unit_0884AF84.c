/* unit_0884AF84: 0x0884AF84-0x0884B010 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;
typedef struct { f32 a, b, c; } F3;

extern f32 D_0893B7A4;
extern f32 D_0893B7A8;
extern f32 D_0893B7AC;
extern char D_089BAA6C;
extern char D_089BAB98;
extern s32 __ptmf_test(f32 *);

char *func_0884AF84(char *arg0) {
    F3 sp14;

    *(char **)arg0 = &D_089BAB98;
    sp14.a = D_0893B7A4;
    sp14.b = D_0893B7A8;
    sp14.c = D_0893B7AC;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x4) = sp14;
    }
    *(char **)arg0 = &D_089BAA6C;
    *(s32 *)(arg0 + 0x1C) = 0;
    return arg0;
}
