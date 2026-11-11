/* unit_088EF1F4: 0x088EF1F4-0x088EF224 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

s32 func_088EF1F4(s32 arg0, s32 arg1) {
    return (s32) ((arg0 + arg1) - 1) / arg1;
}

s32 func_088EF20C(s32 arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg0 + (arg1 - 1);
    return temp_v1 - (temp_v1 % arg1);
}
