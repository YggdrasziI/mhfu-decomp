/* unit_088DCD94: 0x088DCD94-0x088DCDEC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

char *func_088DCEBC(s32, s32);

void func_088DCD94(s32 arg0) {
    s32 var_s0;
    char *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_088DCEBC(arg0, var_s0);
        if (temp_v0 != 0) {
            *(s8 *)(temp_v0 + 0x276) = 0xA;
        }
        var_s0 += 1;
    } while (var_s0 < 6);
}
