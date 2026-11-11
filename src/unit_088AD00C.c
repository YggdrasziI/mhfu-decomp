/* unit_088AD00C: 0x088AD00C-0x088AD064 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_089B2828;
extern char D_089B2830;
extern char func_088ACE0C;
extern char func_088ACE74;
extern s32 sceKernelCreateCallback(char *, char *, s32);
extern int sceKernelRegisterExitCallback(s32);
extern int scePowerRegisterCallback(s32, s32);

void func_088AD00C(void) {
    sceKernelRegisterExitCallback(sceKernelCreateCallback(&D_089B2828, &func_088ACE0C, 0));
    scePowerRegisterCallback(0, sceKernelCreateCallback(&D_089B2830, &func_088ACE74, 0));
}
