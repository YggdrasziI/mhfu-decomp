/* unit_08882B4C: 0x08882B4C-0x08882B68 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D94;
extern void func_0888671C(s32, s32);
extern void func_08886870(s32, s32, s32, s32);

void func_08882B4C(s32 arg0, s32 arg1) {
    func_0888671C(D_08A62D94, arg1);
}

void func_08882B58(s32 arg0, s32 arg1, s32 arg2) {
    func_08886870(D_08A62D94, arg1, arg2, 0);
}
