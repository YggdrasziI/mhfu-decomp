/* unit_08891B14: 0x08891B14-0x08891B5C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 func_08891A28(s32, s32);

void func_08891B14(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_08891A28(arg0, (s8) var_s0);
        var_s0 += 1;
    } while (var_s0 < 6);
}
