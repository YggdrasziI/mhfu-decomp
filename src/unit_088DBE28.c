/* unit_088DBE28: 0x088DBE28-0x088DBE70 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_088DBD98(s32, s32);

void func_088DBE28(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_088DBD98(arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 < 6);
}
