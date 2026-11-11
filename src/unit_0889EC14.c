/* unit_0889EC14: 0x0889EC14-0x0889EC50 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0B56C;
extern void func_088A5D38(void);
extern void func_088A600C(void);

s32 func_0889EC14(void) {
    func_088A600C();
    func_088A5D38();
    D_09A0B56C += 1;
    return 0;
}
