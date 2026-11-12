/* unit_08882EA0: 0x08882EA0-0x08882F04 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_08882C24(s32, s32, s32, s32);
extern s32 func_08882D9C(s32, s32, s32, s32, s32);

void func_08882EA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_08882D9C(arg0, arg1, arg2, 0, 0);
    func_08882C24(arg0, arg1, arg3, arg4);
}
