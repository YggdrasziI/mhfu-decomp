/* unit_08865F8C: 0x08865F8C-0x08866050 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D8C;
extern s32 func_08865BAC(void *);
extern s32 func_08883B54(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_08865F8C(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0) {
    s32 var_s6;

    var_s6 = 0;
    if ((func_08865BAC(arg0) & 0xFF) == 1) {
        var_s6 = func_08883B54(D_08A62D8C, 1, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg_sp0, 0);
    }
    return var_s6;
}
