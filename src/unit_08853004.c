/* unit_08853004: 0x08853004-0x088530C4 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef short s16;
typedef int s32;

s32 func_08890F70(s32);
extern s32 D_08A631A8;

s16 func_08853004(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    s32 temp_lo;
    s32 var_v1;

    temp_lo = arg3 * func_08890F70(D_08A631A8);
    var_v1 = temp_lo >> 2;
    if (temp_lo < 0) {
        var_v1 = (s32) (temp_lo + 3) >> 2;
    }
    return (s16) (arg2 - var_v1);
}

s32 func_08890F70(s32);
extern s32 D_08A631A8;

s16 func_08853064(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    s32 temp_lo;
    s32 var_v1;

    temp_lo = arg3 * func_08890F70(D_08A631A8);
    var_v1 = temp_lo >> 1;
    if (temp_lo < 0) {
        var_v1 = (s32) (temp_lo + 1) >> 1;
    }
    return (s16) (arg2 - var_v1);
}
