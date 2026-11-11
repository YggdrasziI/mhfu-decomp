/* unit_088EC6EC: 0x088EC6EC-0x088EC740 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

s32 func_088EC6EC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_v1;

    var_v1 = arg3 >> 1;
    if (arg3 < 0) {
        var_v1 = (s32) (arg3 + 1) >> 1;
    }
    return (s32) (var_v1 + (arg2 * 0xFF)) / arg3;
}

s32 func_088EC718(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return (s32) (arg3 + (((arg2 * 2) + 1) * 0xFF)) / (s32) (arg3 * 2);
}
