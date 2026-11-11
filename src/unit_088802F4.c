/* unit_088802F4: 0x088802F4-0x08880324 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_0889EA94(s32, s32, s32, s32);
extern void func_0889EAAC(s32, s32, s32, s32);

void func_088802F4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg1 != 0) {
        func_0889EA94(arg0, arg1, arg2, arg3);
        return;
    }
    func_0889EAAC(arg0, arg1, arg2, arg3);
}
