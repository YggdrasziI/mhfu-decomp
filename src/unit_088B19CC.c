/* unit_088B19CC: 0x088B19CC-0x088B1A04 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s8 D_09A1FDE0;
extern s32 D_09A299AC;

s32 func_088B19CC(s32 *arg0) {
    char *var_a0;
    char *var_a1;
    s32 var_v1;

    var_a0 = (char *) (arg0);
    var_a1 = (char *) (&D_09A299AC);
    var_v1 = 0xC9;
    do {
        var_v1 -= 1;
        *(s32 *)var_a0 = *(s32 *)var_a1;
        var_a1 += 4;
        var_a0 += 4;
    } while (var_v1 > 0);
    D_09A1FDE0 = 2;
    return 0;
}
