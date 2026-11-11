/* unit_08882F04: 0x08882F04-0x08882F10 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D94;
extern void func_08886834(s32, s32, s32);

void func_08882F04(s32 arg0, s32 arg1, s32 arg2) {
    func_08886834(D_08A62D94, arg1, arg2);
}
