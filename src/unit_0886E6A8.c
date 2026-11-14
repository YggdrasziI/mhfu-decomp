/* unit_0886E6A8: 0x0886E6A8-0x0886E6F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_0886E6A8(s32 arg0) {
    char *var_a2;
    s32 temp_a0;
    s32 var_a1;

    var_a2 = (char *) (arg0 + 0x728);
    var_a1 = 0;
loop_1:
    temp_a0 = *(s32 *)var_a2;
    if ((temp_a0 & 0x100) && ((temp_a0 & 0x31) == 0x31)) {
        return 1;
    }
    var_a1 += 1;
    var_a2 += 8;
    if (var_a1 >= 2) {
        return 0;
    }
    goto loop_1;
}
