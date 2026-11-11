/* unit_0889EE40: 0x0889EE40-0x0889EEA0 (ULES01213)
 *
 * Bounds (hypothesis): a run of functions that only jump to another one (tail
 * calls), between larger functions that stay in assembly. The three runs at
 * 0x0889EA4C, 0x0889EC78 and 0x0889EE40 are probably pieces of one source file.
 * Parameters and return types are not known: the forwarders are written without
 * arguments, which compiles to the same code.
 */

extern void func_088A65D4();
extern void func_088A6628();
extern void func_088A6798();
extern void func_088A67D8();
extern void func_088A6818();
extern void func_088A6868();
extern void func_088A68B8();
extern void func_088A68FC();
extern void func_088A6940();
extern void func_088A69DC();
extern void func_088A6BA0();
extern void func_088A6C48();

void func_0889EE40(void) {
    func_088A65D4();
}

void func_0889EE48(void) {
    func_088A6628();
}

void func_0889EE50(void) {
    func_088A6798();
}

void func_0889EE58(void) {
    func_088A67D8();
}

void func_0889EE60(void) {
    func_088A6818();
}

void func_0889EE68(void) {
    func_088A6868();
}

void func_0889EE70(void) {
    func_088A68B8();
}

void func_0889EE78(void) {
    func_088A68FC();
}

void func_0889EE80(void) {
    func_088A6940();
}

void func_0889EE88(void) {
    func_088A69DC();
}

void func_0889EE90(void) {
    func_088A6BA0();
}

void func_0889EE98(void) {
    func_088A6C48();
}
