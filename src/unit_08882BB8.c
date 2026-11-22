/* unit_08882BB8: 0x08882BB8-0x08882C24 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D94;

extern s32 func_08880884(char *, s32, s32);
extern void func_08886870(s32, s32, s32, s32);

void func_08882BB8(char *arg0, s32 arg1, s32 arg2) {
    s32 var;

    if (arg1 == 0) {
        var = *(s32 *)(arg0 + 0x5623D4);
    } else {
        var = *(s32 *)(arg0 + 0x5623D0);
    }
    func_08886870(D_08A62D94, arg1, arg2, func_08880884(arg0, 0x7F, var));
}
