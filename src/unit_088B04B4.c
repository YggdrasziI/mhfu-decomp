/* unit_088B04B4: 0x088B04B4-0x088B04EC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_088B04B4(char *arg0) {
    s32 var_a2;
    s32 var_v0;

    var_v0 = 0;
    var_a2 = 0;
    do {
        if (*(arg0 + var_a2) != 0) {
            var_v0 = 1;
        }
        var_a2 += 1;
    } while (var_a2 < 6);
    return var_v0;
}
