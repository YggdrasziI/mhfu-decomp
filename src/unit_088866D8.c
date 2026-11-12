/* unit_088866D8: 0x088866D8-0x0888670C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

s32 func_088866D8(char *arg0, s32 arg1) {
    s32 var_v0;
    char *var_a0;

    var_a0 = arg0;
    var_v0 = 0;
loop_1:
    if (*(u16 *)(var_a0 + 0x3C) == (arg1 & 0xFFFF)) {
        return var_v0;
    }
    var_v0 += 1;
    var_a0 += 0x10;
    if (var_v0 >= 0x15) {
        return -1;
    }
    goto loop_1;
}
