/* unit_088DB5C0: 0x088DB5C0-0x088DB5D8 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62C5C;
extern void func_08867008(s32, s32, s32);
extern void func_08867034(s32, s32);

void func_088DB5C0(s32 arg0, s32 arg1, s32 arg2) {
    func_08867008(D_08A62C5C, arg1, arg2);
}

void func_088DB5CC(s32 arg0, s32 arg1) {
    func_08867034(D_08A62C5C, arg1);
}
