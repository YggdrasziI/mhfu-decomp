/* unit_088865D0: 0x088865D0-0x08886618 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_088865B0(s32, s32);

void func_088865D0(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_088865B0(arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 < 0x15);
}
