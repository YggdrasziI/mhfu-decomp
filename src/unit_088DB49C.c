/* unit_088DB49C: 0x088DB49C-0x088DB4C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

void func_088DB49C(char *arg0, s32 arg1) {
    s32 var_a2;
    char *var_a0;

    var_a0 = arg0;
    var_a2 = 0;
    do {
        if (*(s32 *)(var_a0 + 0xC) == arg1) {
            *(s32 *)(var_a0 + 0xC) = 0;
        }
        var_a2 += 1;
        var_a0 += 4;
    } while (var_a2 < 6);
}
