/* unit_0887FFE8: 0x0887FFE8-0x088800C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

typedef struct {
    s32 w[15];
} T3C;

extern s32 func_0887FF24(s32, s32);
extern s32 func_0889EADC(s32, s32, T3C *);

s32 func_0887FFE8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                  s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    T3C t;

    if (func_0887FF24(arg0, arg1) != 0) {
        t.w[10] = arg8;
        t.w[1] = arg3;
        t.w[12] = arg6;
        t.w[9] = arg7;
        t.w[14] = arg9;
        t.w[0] = 0x2B01;
        if (arg4 != -1) {
            t.w[0] |= 4;
            t.w[3] = arg4;
        }
        if (arg5 != -1) {
            t.w[0] |= 8;
            t.w[4] = arg5;
        }
        return func_0889EADC(arg1, arg2, &t);
    }
    return 0;
}
