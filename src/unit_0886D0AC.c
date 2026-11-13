/* unit_0886D0AC: 0x0886D0AC-0x0886D114 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_08A62C9C;

void func_0886D0AC(char *arg0, s8 arg1) {
    s32 var_a2;
    char *var_a1;

    var_a2 = arg1;
    if (var_a2 < (*(s8 *)(arg0 + 0x21) - 1)) {
        var_a1 = &D_08A62C9C + var_a2;
        do {
            var_a2 += 1;
            *(s8 *)var_a1 = (s8) *(s8 *)(var_a1 + 1);
            var_a1 += 1;
        } while (var_a2 < (*(s8 *)(arg0 + 0x21) - 1));
    }
    *(&D_08A62C9C + var_a2) = -1;
    *(s8 *)(arg0 + 0x21) = (s8) (*(s8 *)(arg0 + 0x21) - 1);
}
