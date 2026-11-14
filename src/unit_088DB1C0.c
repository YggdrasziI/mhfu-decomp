/* unit_088DB1C0: 0x088DB1C0-0x088DB250 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_089B6570;
extern f32 D_089B6578;
extern char *D_09A4F06C;
extern s32 __ptmf_test(f32 *);
extern s32 func_088DB0B0(s32, s32);
extern s32 func_088DB250(s32);

void func_088DB1C0(s32 arg0) {
    F3 sp14;

    func_088DB0B0(arg0, 0);
    if (*(s32 *)(D_09A4F06C + 0x88) == 0) {
        func_088DB250(arg0);
    }
    sp14.a = D_089B6570.a;
    sp14.b = D_089B6570.b;
    sp14.c = D_089B6578;
    if (__ptmf_test((float *) (&sp14)) != 0) {
        *(F3 *)(arg0 + 0x0) = sp14;
    }
}
