/* unit_0886E0D8: 0x0886E0D8-0x0886E130 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_0886A30C(s32, s32);
extern int func_0886E130(s32, s32, s32);

void func_0886E0D8(s32 arg0, s32 arg1, s32 arg2) {
    if (func_0886A30C(arg0, 1) == 0) {
        func_0886E130(arg0, arg1 & 0xFFFF, arg2);
    }
}
