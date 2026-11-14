/* unit_088BA0BC: 0x088BA0BC-0x088BA148 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_089B2B78;
extern f32 D_089B2B80;
extern f32 D_089B2B84;
extern char D_089BAB98;
extern char D_089BACA8;
extern s32 __ptmf_test(f32 *);

char *func_088BA0BC(char *arg0) {
    F3 sp14;

    *(char **)arg0 = &D_089BAB98;
    sp14.a = D_089B2B78.b;
    sp14.b = D_089B2B80;
    sp14.c = D_089B2B84;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x4) = sp14;
    }
    *(char **)arg0 = &D_089BACA8;
    *(s32 *)(arg0 + 0x1C) = 0;
    return arg0;
}
