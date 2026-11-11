/* unit_08885D80: 0x08885D80-0x08885DB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D90;
extern void func_08885E00(s32);

s32 func_08885D80(s32 arg0) {
    D_08A62D90 = arg0;
    func_08885E00(arg0);
    return arg0;
}
