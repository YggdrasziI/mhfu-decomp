/* unit_088DBB5C: 0x088DBB5C-0x088DBBBC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_088DBA0C(char *, s32);

void func_088DBB5C(char *arg0) {
    s32 var_s1;
    char *var_s0;

    var_s1 = 0;
    var_s0 = arg0;
    do {
        if (*(s32 *)(var_s0 + 0xC) != 0) {
            func_088DBA0C(arg0, var_s1);
        }
        var_s1 += 1;
        var_s0 += 4;
    } while (var_s1 < 6);
}
