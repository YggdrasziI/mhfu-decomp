/* unit_0889EA4C: 0x0889EA4C-0x0889EAE8 (ULES01213)
 *
 * Bounds (hypothesis): a run of functions that only jump to another one (tail
 * calls), between larger functions that stay in assembly. The three runs at
 * 0x0889EA4C, 0x0889EC78 and 0x0889EE40 are probably pieces of one source file.
 * Parameters and return types are not known: the forwarders are written without
 * arguments, which compiles to the same code.
 */

typedef int s32;

typedef unsigned short u16;

extern void func_0889ECB8(int a, int b, s32);
extern void func_0889EC78(void);
extern void func_0889EC80(void);
extern void func_0889EC88(s32);
extern void func_0889EC90(s32, s32);
extern void func_0889EC98(s32);
extern int func_0889ECA0(int i, int v);
extern void func_0889ECA8(s32);
extern void func_0889ECB0(s32, s32, s32);
extern void func_0889EE48(s32, s32, s32);
extern void func_0889EE50(void);
extern void func_0889EE58(void);
extern void func_0889EE60(s32);
extern void func_0889EE68(s32);
extern void func_0889EE70(s32);
extern void func_0889EE78(s32);
extern void func_0889EE88(s32, s32, s32);
extern void func_0889EE90(s32, s32, s32, s32);
extern void func_0889EE98(s32);

void func_0889EA4C(void) {
    func_0889EC78();
}

void func_0889EA54(s32 arg0) {
    func_0889EC80();
}

void func_0889EA5C(s32 arg0) {
    func_0889EC88(arg0);
}

void func_0889EA64(s32 arg0, s32 arg1) {
    func_0889EC90(arg0, arg1);
}

int func_0889EA6C(int i, int v) {
    return func_0889ECA0(i, v);
}

void func_0889EA74(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0889ECA8(arg0);
}

void func_0889EA7C(s32 arg0, s32 arg1, s32 arg2) {
    func_0889ECB0(arg0, arg1, arg2);
}

void func_0889EA84(s32 arg0, s32 arg1, s32 arg2) {
    func_0889EE48(arg0, arg1, arg2);
}

void func_0889EA8C(s32 arg0) {
    func_0889EE98(arg0);
}

void func_0889EA94(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0889EE50();
}

void func_0889EA9C(s32 arg0) {
    func_0889EE60(arg0);
}

void func_0889EAA4(s32 arg0) {
    func_0889EE70(arg0);
}

void func_0889EAAC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0889EE58();
}

void func_0889EAB4(s32 arg0) {
    func_0889EE68(arg0);
}

void func_0889EABC(s32 arg0) {
    func_0889EE78(arg0);
}

void func_0889EAC4(s32 arg0, s32 arg1, s32 arg2) {
    func_0889EE88(arg0, arg1, arg2);
}

void func_0889EACC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0889EE90(arg0, arg1, arg2, arg3);
}

void func_0889EAD4(s32 arg0) {
    func_0889EC98(arg0);
}

void func_0889EADC(u16 a, u16 b, s32 arg2) {
    func_0889ECB8(a, b, arg2);
}
