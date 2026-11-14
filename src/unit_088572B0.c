/* unit_088572B0: 0x088572B0-0x088572E8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

extern s32 D_0899CC08;

u32 func_088572B0(s32 arg0, s32 arg1) {
    char *var_a0;
    u32 var_v0;

    var_v0 = 0;
    var_a0 = (char *) (&D_0899CC08);
loop_1:
    if (arg1 == *(s32 *)var_a0) {
        return var_v0;
    }
    var_v0 += 1;
    var_a0 += 4;
    if (var_v0 >= 0x3DU) {
        return 0U;
    }
    goto loop_1;
}
