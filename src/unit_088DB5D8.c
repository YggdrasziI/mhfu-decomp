/* unit_088DB5D8: 0x088DB5D8-0x088DB608 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_088DB5D8(char *arg0) {
    s32 var_v0;
    char *var_a0;

    var_a0 = arg0;
    var_v0 = 0;
loop_1:
    if (*(s32 *)(var_a0 + 0xC) == 0) {
        return var_v0;
    }
    var_v0 += 1;
    var_a0 += 4;
    if (var_v0 >= 6) {
        return -1;
    }
    goto loop_1;
}
