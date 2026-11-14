/* unit_088B8460: 0x088B8460-0x088B8548 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

extern F2 D_089B2A48;
extern f32 D_089B2A50;
extern f32 D_089B2A54;
extern char *D_089CC01C;
extern s32 D_08A631A0;
extern s32 __ptmf_test(f32 *);
extern void func_0884D754(void *, s16, s8, s32);
extern int func_08890144(s32, s32, s32);
extern s32 func_088901E0(s32, s32);
extern int func_088901F8(s32, s32, s32);

void func_088B8460(char *arg0) {
    F3 sp14;
    s32 temp_v1;

    temp_v1 = *(s32 *)(arg0 + 0x1C);
    switch (temp_v1) {                              /* irregular */
    case 0:
        func_0884D754(D_089CC01C, 1, 0, 1);
        func_08890144(D_08A631A0, 0x42, 1);
        *(s32 *)(arg0 + 0x1C) = (s32) (*(s32 *)(arg0 + 0x1C) + 1);
        return;
    case 1:
        if (func_088901E0(D_08A631A0, 1) == 0) {
            func_088901F8(D_08A631A0, 0x42, 1);
            *(s32 *)(arg0 + 0x1C) = 0;
            sp14.a = D_089B2A48.b;
            sp14.b = D_089B2A50;
            sp14.c = D_089B2A54;
            if (__ptmf_test((float *) (&sp14)) != 0) {
                *(F3 *)(arg0 + 0x4) = sp14;
            }
        }
        return;
    }
}
