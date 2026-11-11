/* unit_08862510: 0x08862510-0x08862518 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_088623DC(char *, s32, s32, s32);

void func_08862510(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_088623DC(arg0 + 0x50, arg1, arg2, arg3);
}
