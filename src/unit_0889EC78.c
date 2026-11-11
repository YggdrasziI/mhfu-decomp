/* unit_0889EC78: 0x0889EC78-0x0889ECB8 (ULES01213)
 *
 * Bounds (hypothesis): a run of functions that only jump to another one (tail
 * calls), between larger functions that stay in assembly. The three runs at
 * 0x0889EA4C, 0x0889EC78 and 0x0889EE40 are probably pieces of one source file.
 * Parameters and return types are not known: the forwarders are written without
 * arguments, which compiles to the same code.
 */

extern int func_088A6024(int i, int v);
extern void func_088A4B5C();
extern void func_088A4BC4();
extern void func_088A4BE8();
extern void func_088A4BF0();
extern void func_088A4CB0();
extern void func_088A59C4();
extern void func_088A6014();

void func_0889EC78(void) {
    func_088A4B5C();
}

void func_0889EC80(void) {
    func_088A4BC4();
}

void func_0889EC88(void) {
    func_088A4BE8();
}

void func_0889EC90(void) {
    func_088A4BF0();
}

void func_0889EC98(void) {
    func_088A6014();
}

int func_0889ECA0(int i, int v) {
    return func_088A6024(i, v);
}

void func_0889ECA8(void) {
    func_088A59C4();
}

void func_0889ECB0(void) {
    func_088A4CB0();
}
