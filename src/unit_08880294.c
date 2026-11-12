/* unit_08880294: 0x08880294-0x088802F4 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern int func_0889EA9C(s32);
extern int func_0889EAA4(s32);
extern int func_0889EAB4(s32);
extern int func_0889EABC(s32);

void func_08880294(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        func_0889EAA4(arg1);
        return;
    }
    func_0889EABC(arg1);
}

void func_088802C4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 != 0) {
        func_0889EA9C(arg1);
        return;
    }
    func_0889EAB4(arg1);
}
