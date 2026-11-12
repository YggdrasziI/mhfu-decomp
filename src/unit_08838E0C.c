/* unit_08838E0C: 0x08838E0C-0x08838E30 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_0882A9DC(s32, s32, s32, s32);

void func_08838E0C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if (arg4 >= arg5) {
        func_0882A9DC(arg0, arg1, arg2, arg3 & 0xFFFF);
    }
}
