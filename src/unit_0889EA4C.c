/* unit_0889EA4C: 0x0889EA4C-0x0889EAE8 (ULES01213)
 *
 * Bounds (hypothesis): a run of functions that only jump to another one (tail
 * calls), between larger functions that stay in assembly. The three runs at
 * 0x0889EA4C, 0x0889EC78 and 0x0889EE40 are probably pieces of one source file.
 * Parameters and return types are not known: the forwarders are written without
 * arguments, which compiles to the same code.
 */

typedef unsigned short u16;

extern void func_0889ECB8(int a, int b);
extern void func_0889EC78();
extern void func_0889EC80();
extern void func_0889EC88();
extern void func_0889EC90();
extern void func_0889EC98();
extern int func_0889ECA0(int i, int v);
extern void func_0889ECA8();
extern void func_0889ECB0();
extern void func_0889EE48();
extern void func_0889EE50();
extern void func_0889EE58();
extern void func_0889EE60();
extern void func_0889EE68();
extern void func_0889EE70();
extern void func_0889EE78();
extern void func_0889EE88();
extern void func_0889EE90();
extern void func_0889EE98();

void func_0889EA4C(void) {
    func_0889EC78();
}

void func_0889EA54(void) {
    func_0889EC80();
}

void func_0889EA5C(void) {
    func_0889EC88();
}

void func_0889EA64(void) {
    func_0889EC90();
}

int func_0889EA6C(int i, int v) {
    return func_0889ECA0(i, v);
}

void func_0889EA74(void) {
    func_0889ECA8();
}

void func_0889EA7C(void) {
    func_0889ECB0();
}

void func_0889EA84(void) {
    func_0889EE48();
}

void func_0889EA8C(void) {
    func_0889EE98();
}

void func_0889EA94(void) {
    func_0889EE50();
}

void func_0889EA9C(void) {
    func_0889EE60();
}

void func_0889EAA4(void) {
    func_0889EE70();
}

void func_0889EAAC(void) {
    func_0889EE58();
}

void func_0889EAB4(void) {
    func_0889EE68();
}

void func_0889EABC(void) {
    func_0889EE78();
}

void func_0889EAC4(void) {
    func_0889EE88();
}

void func_0889EACC(void) {
    func_0889EE90();
}

void func_0889EAD4(void) {
    func_0889EC98();
}

void func_0889EADC(u16 a, u16 b) {
    func_0889ECB8(a, b);
}
