/* unit_08856884: 0x08856884-0x088568AC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_08856884(char *arg0, char *arg1) {
    s32 var_a1;

    var_a1 = (int) (arg1);
    if (var_a1 >= 0x19) {
        var_a1 = 0;
    }
    return (int) (arg0 + (var_a1 * 4) + 0x6AEA6);
}
