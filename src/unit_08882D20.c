/* unit_08882D20: 0x08882D20-0x08882D9C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_08880884(char *, s32, s32);
extern s32 func_08882D9C(s32, s32, s32, s32, s32);

void func_08882D20(char *arg0, s32 arg1, s32 arg2) {
    s32 var_a2;

    if (arg1 == 0) {
        var_a2 = *(s32 *)((char *)arg0 + 0x5623D4);
    } else {
        var_a2 = *(s32 *)((char *)arg0 + 0x5623D0);
    }
    func_08882D9C((s32) arg0, arg1, arg2, func_08880884(arg0, 0x7F, var_a2), 0);
}
