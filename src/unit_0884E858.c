/* unit_0884E858: 0x0884E858-0x0884E884 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

s32 func_0884E858(s32 arg0, u32 arg1, s32 arg2) {
    s32 var_v0;

    var_v0 = arg1 >= 0x08400000U;
    if (var_v0 != 0) {
        var_v0 = (u32) (arg1 + arg2) < 0x08800001U;
    }
    return var_v0;
}
