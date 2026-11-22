/* unit_08882D9C: 0x08882D9C-0x08882E24 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

extern s32 D_08A62D94;
extern void func_08886834(s32, s32, s32);
extern int func_08886850(s32, s32, s32);
extern void func_08886870(s32, s32, s32, s32);
extern void func_08886780(s32, s32, s32);

void func_08882D9C(s32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_08886834(D_08A62D94, arg1, arg4);
    func_08886850(D_08A62D94, arg1, arg3);
    func_08886870(D_08A62D94, arg1, 0, arg3);
    func_08886780(D_08A62D94, arg1, arg2);
}
