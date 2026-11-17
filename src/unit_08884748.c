/* unit_08884748: 0x08884748-0x0888491C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;

extern char *D_08A62D84;

extern s32 func_0887FBBC(char *arg0);
extern void func_088801A0(char *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088801E8(char *, s32, s32, s32, s32, s32, s32, s32, float);
extern s32 func_08880884(char *, s32, s32);
extern s32 func_088808B0(s32 arg0, s32 arg1);
extern void func_08884E44(char *, s32, s32, s32 *, s32 *);
extern void func_088851C8(char *, s32, s32, s32 *, float *);

void func_08884748(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 n;
    float f;
    s32 v;
    s32 r;

    *(s32 *)(arg0 + 0x562438) = arg8;
    if (func_0887FBBC(D_08A62D84) == 2) {
        func_088851C8(arg0, arg5, arg6, &n, &f);
        n = func_08880884(arg0, n, *(s32 *)(arg0 + 0x5623D0));
        if (n > 0) {
            r = func_088808B0((s32) arg0, n);
            func_088801E8(D_08A62D84, arg1, arg2, arg3, arg4, r, *(s32 *)(arg0 + 0x562438), arg7 * r / 100, f);
        }
    } else {
        func_08884E44(arg0, arg5, arg6, &n, &v);
        n = func_08880884(arg0, n, *(s32 *)(arg0 + 0x5623D0));
        if (n > 0) {
            r = func_088808B0((s32) arg0, n);
            func_088801A0(D_08A62D84, arg1, arg2, arg3, arg4, r, v, *(s32 *)(arg0 + 0x562438), arg7 * r / 100);
        }
    }
}