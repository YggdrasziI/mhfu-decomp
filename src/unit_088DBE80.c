/* unit_088DBE80: 0x088DBE80-0x088DBEE0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_088DBE70(char *, s32);

void func_088DBE80(char *arg0) {
    s32 var_s1;
    char *var_s0;

    var_s1 = 0;
    var_s0 = arg0;
    do {
        if (*(s32 *)(var_s0 + 0xC) != 0) {
            func_088DBE70(arg0, var_s1);
        }
        var_s1 += 1;
        var_s0 += 4;
    } while (var_s1 < 6);
}
