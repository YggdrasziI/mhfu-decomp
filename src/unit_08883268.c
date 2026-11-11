/* unit_08883268: 0x08883268-0x0888334C (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D84;
extern int func_0887FD04(s32);
extern int func_0887FD2C(s32, s32);
extern int func_0887FD48(s32, s32);
extern int func_0887FE5C(s32);
extern int func_0887FEE4(s32);
extern int func_08882FA4(s32, s32);
extern int func_0888307C(s32, s32, s32);

void func_08883268(s32 arg0, s32 arg1) {
    func_0887FD04(D_08A62D84);
    func_0887FD48(D_08A62D84, arg1);
    func_0887FD2C(D_08A62D84, arg1);
}

void func_088832B4(s32 arg0, s32 arg1, s32 arg2) {
    func_0887FE5C(D_08A62D84);
    func_08882FA4(arg0, arg2);
}

void func_088832F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0887FEE4(D_08A62D84);
    func_0888307C(arg0, arg2, arg3);
}
