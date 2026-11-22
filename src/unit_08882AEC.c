/* unit_08882AEC: 0x08882AEC-0x08882B4C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D94;

extern s32 func_08880884(char *, s32, s32);
extern void func_08886850(s32, s32, s32);

void func_08882AEC(char *arg0, s32 arg1, s32 arg2) {
    s32 v;

    if (arg1 == 0) {
        v = *(s32 *)(arg0 + 0x5623D4);
    } else {
        v = *(s32 *)(arg0 + 0x5623D0);
    }
    arg2 = func_08880884(arg0, arg2, v);
    func_08886850(D_08A62D94, arg1, arg2);
}
