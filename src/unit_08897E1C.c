/* unit_08897E1C: 0x08897E1C-0x08897E5C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A631A0;
extern int func_0888FD38(s32);
extern void func_0890DE0C(void);
extern void func_0890DE14(void);
extern int sceKernelChangeThreadPriority(s32, s32);

s32 func_08897E1C(void) {
    sceKernelChangeThreadPriority(0, 0x30);
    func_0890DE14();
    func_0888FD38(D_08A631A0);
    func_0890DE0C();
    return 0;
}
