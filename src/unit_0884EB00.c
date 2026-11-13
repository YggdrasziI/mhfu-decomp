/* unit_0884EB00: 0x0884EB00-0x0884EC3C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

extern s32 func_0884E858(s32, u32, s32);
extern int sceKernelClearEventFlag(s32, s32);
extern s32 sceKernelPollEventFlag(s32, s32, s32, s32);
extern int sceKernelSetEventFlag(s32, s32);
extern int sceKernelStartThread(s32, s32, void *);
extern int sceKernelTerminateThread(s32);

void func_0884EB00(char *arg0) {
    char *sp1C;
    char *sp18;
    char *temp_a1;

    if (sceKernelPollEventFlag(*(s32 *)(arg0 + 0x2FBE8), 1, 0, 0) == 0) {
        sceKernelTerminateThread(*(s32 *)(arg0 + 0x2FBEC));
        sceKernelClearEventFlag(*(s32 *)(arg0 + 0x2FBE8), -2);
        sceKernelSetEventFlag(*(s32 *)(arg0 + 0x2FBE8), 0x10);
        sp1C = arg0;
        sceKernelStartThread(*(s32 *)(arg0 + 0x2FBEC), 4, &sp1C);
    }
    if (sceKernelPollEventFlag(*(s32 *)(arg0 + 0x2FBC0), 1, 0, 0) == 0) {
        temp_a1 = *(char **)(arg0 + 0x2FBC8);
        if (func_0884E858((s32) arg0, *(s32 *)(temp_a1 + 4) + *(s32 *)(temp_a1 + 0xC), *(s32 *)(temp_a1 + 8)) != 0) {
            sceKernelTerminateThread(*(s32 *)(arg0 + 0x2FBC4));
            sceKernelClearEventFlag(*(s32 *)(arg0 + 0x2FBC0), -2);
            sceKernelSetEventFlag(*(s32 *)(arg0 + 0x2FBC0), 0x10);
            sp18 = arg0;
            sceKernelStartThread(*(s32 *)(arg0 + 0x2FBC4), 4, &sp18);
        }
    }
}
