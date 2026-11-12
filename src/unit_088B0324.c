/* unit_088B0324: 0x088B0324-0x088B03BC (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern int func_088B03CC(u16 *, s32);
extern int func_088B040C(char *, s32, s32);

void func_088B0324(char *arg0, s32 arg1) {
    u16 sp1E;

    func_088B03CC(&sp1E, arg1);
    *(u16 *)(arg0 + 0x12) = sp1E;
    func_088B040C(arg0, 0x12, arg1);
}

void func_088B0370(char *arg0, s32 arg1) {
    u16 sp1E;

    func_088B03CC(&sp1E, arg1);
    *(u16 *)(arg0 + 0xA0) = sp1E;
    func_088B040C(arg0, 0xA0, arg1);
}
