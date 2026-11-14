/* unit_088A73A8: 0x088A73A8-0x088A73B8 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern void func_088A9F4C(s32, s32, s32, s32);
extern void func_088A9FF8(void);

void func_088A73A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_088A9F4C(arg0, arg1, arg2, arg3);
}

void func_088A73B0(void) {
    func_088A9FF8();
}
