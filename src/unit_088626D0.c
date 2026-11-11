/* unit_088626D0: 0x088626D0-0x088626DC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_08862518(char *, s32, s32, s32);

void func_088626D0(char *arg0, s32 arg1, s32 arg2) {
    func_08862518(arg0 + 0x70, arg1, arg2, 0);
}
