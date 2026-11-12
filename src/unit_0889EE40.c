/* unit_0889EE40: 0x0889EE40-0x0889EEA0 (ULES01213)
 *
 * Bounds (hypothesis): a run of functions that only jump to another one (tail
 * calls), between larger functions that stay in assembly. The three runs at
 * 0x0889EA4C, 0x0889EC78 and 0x0889EE40 are probably pieces of one source file.
 * Parameters and return types are not known: the forwarders are written without
 * arguments, which compiles to the same code.
 */

typedef int s32;

extern void func_088A65D4(s32);
extern void func_088A6628(s32, s32, s32);
extern void func_088A6798(void);
extern void func_088A67D8(void);
extern void func_088A6818(s32);
extern void func_088A6868(s32);
extern void func_088A68B8(s32);
extern void func_088A68FC(s32);
extern void func_088A6940(s32, s32, s32);
extern void func_088A69DC(s32, s32, s32);
extern void func_088A6BA0(s32, s32, s32, s32);
extern void func_088A6C48(s32);

void func_0889EE40(s32 arg0) {
    func_088A65D4(arg0);
}

void func_0889EE48(s32 arg0, s32 arg1, s32 arg2) {
    func_088A6628(arg0, arg1, arg2);
}

void func_0889EE50(void) {
    func_088A6798();
}

void func_0889EE58(void) {
    func_088A67D8();
}

void func_0889EE60(s32 arg0) {
    func_088A6818(arg0);
}

void func_0889EE68(s32 arg0) {
    func_088A6868(arg0);
}

void func_0889EE70(s32 arg0) {
    func_088A68B8(arg0);
}

void func_0889EE78(s32 arg0) {
    func_088A68FC(arg0);
}

void func_0889EE80(s32 arg0, s32 arg1, s32 arg2) {
    func_088A6940(arg0, arg1, arg2);
}

void func_0889EE88(s32 arg0, s32 arg1, s32 arg2) {
    func_088A69DC(arg0, arg1, arg2);
}

void func_0889EE90(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_088A6BA0(arg0, arg1, arg2, arg3);
}

void func_0889EE98(s32 arg0) {
    func_088A6C48(arg0);
}
