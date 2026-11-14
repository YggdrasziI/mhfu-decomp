/* unit_0886E92C: 0x0886E92C-0x0886E978 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern char *D_089CC438;

void func_0886E92C(char *arg0, s32 arg1) {
    char *var_a3;
    s16 var_a2;
    s16 var_v1;

    var_a3 = (char *) (*(s16 **)(arg0 + 0x54));
    var_a2 = 0;
    if (arg1 == 0) {
        var_v1 = -2;
    } else {
        var_v1 = 0x25;
    }
loop_4:
    if (*(s16 *)var_a3 != var_v1) {
        var_a3 += 8;
        var_a2 += 1;
        goto loop_4;
    }
    *(s16 *)(arg0 + 0x1C) = var_a2;
    *(s8 *)(D_089CC438 + 0x2E) = 5;
}
