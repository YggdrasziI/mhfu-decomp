/* unit_089038C4: 0x089038C4-0x08903950 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_089B9170;
extern f32 D_089B9178;
extern f32 D_089B917C;
extern char D_089BAB98;
extern char D_089BAEB4;
extern s32 __ptmf_test(f32 *);

char *func_089038C4(char *arg0) {
    F3 sp14;

    *(char **)arg0 = &D_089BAB98;
    sp14.a = D_089B9170.b;
    sp14.b = D_089B9178;
    sp14.c = D_089B917C;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x4) = sp14;
    }
    *(char **)arg0 = &D_089BAEB4;
    *(s32 *)(arg0 + 0x1C) = 0;
    return arg0;
}
