/* unit_088B3A3C: 0x088B3A3C-0x088B3A68 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A28B98;

s32 func_088B3A3C(s32 *arg0) {
    char *var_a0;
    char *var_a1;
    s32 var_v1;

    var_a0 = (char *) (arg0);
    var_a1 = (char *) (&D_09A28B98);
    var_v1 = 0x19;
    do {
        var_v1 -= 1;
        *(s32 *)var_a0 = *(s32 *)var_a1;
        var_a1 += 4;
        var_a0 += 4;
    } while (var_v1 > 0);
    return 0;
}
