/* unit_08858008: 0x08858008-0x08858010 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_08858010(s32, s32, s32);

void func_08858008(s32 arg0, s32 arg1) {
    func_08858010(arg0, arg1, 0);
}
