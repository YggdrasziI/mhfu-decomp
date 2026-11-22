/* unit_088800C0: 0x088800C0-0x088801A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

typedef struct {
    s32 w[15];
} T3C;

extern s32 func_0887FF24(s32, s32);
extern s32 func_088B826C(float, s32, s32, T3C *);

s32 func_088800C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                  float f, s32 arg6, s32 arg7, s32 arg8) {
    T3C t;

    if (func_0887FF24(arg0, arg1) != 0) {
        t.w[1] = arg3;
        t.w[14] = arg8;
        t.w[0] = 0x2A01;
        t.w[12] = arg6;
        t.w[10] = arg7;
        if (arg4 != -1) {
            t.w[3] = arg4;
            t.w[0] |= 4;
        }
        if (arg5 != -1) {
            t.w[4] = arg5;
            t.w[0] |= 8;
        }
        return func_088B826C(f, arg1, arg2, &t);
    }
    return 0;
}
