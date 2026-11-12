/* unit_08880254: 0x08880254-0x08880294 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_0889EAC4(s32, s32, s32);
extern void func_0889EE80(s32, s32, s32);

void func_08880254(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg4 != 0) {
        func_0889EE80(arg1, arg2, arg3);
        return;
    }
    func_0889EAC4(arg1, arg2, arg3);
}
