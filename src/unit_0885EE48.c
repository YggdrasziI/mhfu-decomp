/* unit_0885EE48: 0x0885EE48-0x0885EEA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char D_0899D198;

s32 func_0885EE48(s32 arg0, char *arg1) {
    s32 var_a3;
    s32 var_v0;
    u16 temp_a2;
    char *var_a1;

    var_a1 = arg1;
    if (*(u16 *)(var_a1 + 2) == 0) {
        return 0;
    }
    var_v0 = 0;
    var_a3 = 0;
    do {
        temp_a2 = *(u16 *)(var_a1 + 6);
        if (temp_a2 != 0) {
            var_v0 += *(s32 *)((char *)((&D_0899D198 + (temp_a2 * 0x18))) + 0x10);
        }
        var_a3 += 1;
        var_a1 += 2;
    } while (var_a3 < 3);
    return var_v0;
}
