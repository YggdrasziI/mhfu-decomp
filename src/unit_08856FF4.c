/* unit_08856FF4: 0x08856FF4-0x08857058 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_0884FE80(s32, s32);

s32 func_08856FF4(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
loop_1:
    if (func_0884FE80(arg0, ((var_s0 & 0xFFFF) + 0x55F1) & 0xFFFF) == 0) {
        return 0;
    }
    var_s0 = (var_s0 + 1) & 0xFFFF;
    if (var_s0 >= 6) {
        return 1;
    }
    goto loop_1;
}
