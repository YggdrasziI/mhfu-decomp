/* unit_08890CE0: 0x08890CE0-0x08890D90 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08931B3C;
extern void func_08890C94(s32, s32, s32, s32);

void func_08890CE0(s32 arg0) {
    char *var_s2;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;

    var_s2 = (char *) (&D_08931B3C);
    var_s1 = 0;
    do {
        func_08890C94(arg0, var_s1, 0, *(s32 *)var_s2);
        var_s1 += 1;
        var_s2 += 4;
    } while (var_s1 < 0x1E);
    var_s1_2 = 0x1E;
    do {
        func_08890C94(arg0, var_s1_2, -0x01000000, *(s32 *)var_s2);
        var_s1_2 += 1;
        var_s2 += 4;
    } while (var_s1_2 < 0x20);
    var_s1_3 = 0x20;
    do {
        func_08890C94(arg0, var_s1_3, 0, 0);
        var_s1_3 += 1;
    } while (var_s1_3 < 0x30);
}
