/* unit_0889EC78: 0x0889EC78-0x0889ECB8 (ULES01213)
 *
 * Bounds (hypothesis): a run of functions that only jump to another one (tail
 * calls), between larger functions that stay in assembly. The three runs at
 * 0x0889EA4C, 0x0889EC78 and 0x0889EE40 are probably pieces of one source file.
 * Parameters and return types are not known: the forwarders are written without
 * arguments, which compiles to the same code.
 */

typedef int s32;

extern int func_088A6024(int i, int v);
extern void func_088A4B5C(void);
extern void func_088A4BC4(void);
extern void func_088A4BE8(s32);
extern void func_088A4BF0(s32, s32);
extern void func_088A4CB0(s32, s32, s32);
extern void func_088A59C4(s32);
extern void func_088A6014(s32);

void func_0889EC78(void) {
    func_088A4B5C();
}

void func_0889EC80(void) {
    func_088A4BC4();
}

void func_0889EC88(s32 arg0) {
    func_088A4BE8(arg0);
}

void func_0889EC90(s32 arg0, s32 arg1) {
    func_088A4BF0(arg0, arg1);
}

void func_0889EC98(s32 arg0) {
    func_088A6014(arg0);
}

int func_0889ECA0(int i, int v) {
    return func_088A6024(i, v);
}

void func_0889ECA8(s32 arg0) {
    func_088A59C4(arg0);
}

void func_0889ECB0(s32 arg0, s32 arg1, s32 arg2) {
    func_088A4CB0(arg0, arg1, arg2);
}
