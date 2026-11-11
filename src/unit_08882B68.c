/* unit_08882B68: 0x08882B68-0x08882BB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D94;
extern int func_08886870(s32, s32, s32, s32);

void func_08882B68(s32 arg0, s32 arg1) {
    func_08886870(D_08A62D94, 0, arg1, 0);
    func_08886870(D_08A62D94, 1, arg1, 0);
}
