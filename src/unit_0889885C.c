/* unit_0889885C: 0x0889885C-0x08898898 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_0889885C(char *arg0) {
    s32 var_v0;
    char *var_a0;

    var_a0 = arg0;
    var_v0 = 0;
loop_1:
    if (*(s32 *)((char *)var_a0 + 0x83C030) == -1) {
        return var_v0;
    }
    var_v0 += 1;
    var_a0 += 0xC;
    if (var_v0 >= 0x200) {
        return -1;
    }
    goto loop_1;
}
