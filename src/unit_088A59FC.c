/* unit_088A59FC: 0x088A59FC-0x088A5A3C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_089B26FC;
extern s32 D_09A0EB68;
extern void func_088A5A3C(void);
extern s32 sceKernelCreateSema(char *, s32, s32, s32, s32);

s32 func_088A59FC(void) {
    D_09A0EB68 = sceKernelCreateSema(&D_089B26FC, 0x100, 1, 1, 0);
    func_088A5A3C();
    return 0;
}
