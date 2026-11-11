/* unit_08867EC8: 0x08867EC8-0x08867F34 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_08867F34(s32, s32, s32, s32);

s32 func_08867EC8(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_08867F34(arg0, arg1, arg2, var_s0 & 0xFF);
        var_s0 += 1;
    } while (var_s0 < 6);
    return 1;
}
