/* unit_08886568: 0x08886568-0x088865B0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_08886530(s32, s32);

void func_08886568(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_08886530(arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 < 2);
}
