/* unit_088B0D2C: 0x088B0D2C-0x088B0D58 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A29D3C;

s32 func_088B0D2C(s32 *arg0) {
    char *var_a0;
    char *var_a1;
    s32 var_v1;

    var_a0 = (char *) (arg0);
    var_a1 = (char *) (&D_09A29D3C);
    var_v1 = 0x2B;
    do {
        var_v1 -= 1;
        *(s32 *)var_a0 = *(s32 *)var_a1;
        var_a1 += 4;
        var_a0 += 4;
    } while (var_v1 > 0);
    return 0;
}
