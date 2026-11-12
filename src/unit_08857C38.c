/* unit_08857C38: 0x08857C38-0x08857C98 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

char *func_08857C38(char *arg0) {
    s32 var_a1;
    char *var_v1;

    var_a1 = 0;
    var_v1 = arg0;
loop_1:
    if (*(s8 *)(var_v1 + 0x69BEC) & 2) {
        return arg0 + (var_a1 * 0x70) + 0x69BEC;
    }
    var_a1 += 1;
    var_v1 += 0x70;
    if (var_a1 >= 3) {
        return 0;
    }
    goto loop_1;
}
