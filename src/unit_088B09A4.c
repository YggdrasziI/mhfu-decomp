/* unit_088B09A4: 0x088B09A4-0x088B09D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A29E58;

void func_088B09A4(s32 *arg0) {
    char *var_a0;
    char *var_a2;
    s32 var_a1;

    var_a0 = (char *) (arg0);
    var_a2 = (char *) (&D_09A29E58);
    var_a1 = 0xC9;
    do {
        var_a1 -= 1;
        *(s32 *)var_a0 = *(s32 *)var_a2;
        var_a2 += 4;
        var_a0 += 4;
    } while (var_a1 > 0);
}
