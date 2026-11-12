/* unit_08812308: 0x08812308-0x08812338 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

s32 func_08812308(char *arg0) {
    s32 var_v1;
    char *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
loop_1:
    if (*(u8 *)(var_a0 + 1) == 0) {
        return var_v1 & 0xFF;
    }
    var_v1 += 1;
    var_a0 += 0x18;
    if (var_v1 >= 0x2E) {
        return 0xFF;
    }
    goto loop_1;
}
