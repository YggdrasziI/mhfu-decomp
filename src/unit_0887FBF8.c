/* unit_0887FBF8: 0x0887FBF8-0x0887FC40 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_0887FBC4(s32, s32);

void func_0887FBF8(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_0887FBC4(arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 < 0x10);
}
