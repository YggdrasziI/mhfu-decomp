/* unit_08864440: 0x08864440-0x088644E8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_089A6048;
extern f32 D_089A6050;
extern char D_089BAB44;
extern s32 __ptmf_test(f32 *);
extern void *func_088614DC(void *);

char *func_08864440(char *arg0) {
    F3 sp14;

    func_088614DC(arg0);
    *(char **)arg0 = &D_089BAB44;
    *(s32 *)(arg0 + 0x1C4) = 0;
    *(s32 *)(arg0 + 0x1C8) = 0;
    *(s8 *)(arg0 + 0x1D7) = 0;
    *(s8 *)(arg0 + 0x1D6) = 0;
    *(s8 *)(arg0 + 0x1D5) = 0;
    *(s8 *)(arg0 + 0x1D4) = 0;
    *(s32 *)(arg0 + 0x414) = 0;
    *(s8 *)(arg0 + 0x1E9) = 3;
    *(s32 *)(arg0 + 0x410) = 0;
    sp14.a = D_089A6048.a;
    sp14.b = D_089A6048.b;
    sp14.c = D_089A6050;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x3FC) = sp14;
    }
    return arg0;
}
