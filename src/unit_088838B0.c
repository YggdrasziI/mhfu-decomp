/* unit_088838B0: 0x088838B0-0x08883988 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_08883988.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;

extern s32 D_08A62D84;

extern s32 func_0887FFE8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_088808B0(s32 arg0, s32 arg1);

s32 func_088838B0(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    s32 n;

    if (arg2 == -1) {
        return 0;
    }
    n = func_088808B0((s32) arg0, arg6);
    arg9 = arg9 * n / 100;
    return func_0887FFE8(D_08A62D84, arg1, arg2, arg3, arg4, arg5, n, arg7 - 0x40, arg8 - 0x2000, arg9);
}