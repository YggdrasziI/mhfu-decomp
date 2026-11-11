/* unit_0889F9A0: 0x0889F9A0-0x0889F9C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0D138;
extern void func_088A0BEC(s32, s32, s32, s32);

s32 func_0889F9A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_09A0D138 = arg0;
    func_088A0BEC(arg0, arg1, arg2, arg3);
    return 0;
}
