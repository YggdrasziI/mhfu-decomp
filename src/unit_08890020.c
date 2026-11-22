/* unit_08890020: 0x08890020-0x08890080 (ULES01213)
 *
 * A thread body that registers an exit callback (func_08890060, defined right
 * after it) and then sleeps forever, waiting for callbacks.
 */

typedef int s32;
typedef unsigned int u32;

extern char D_089AD240[];
extern s32 D_08A631A4;

extern s32 sceKernelCreateCallback(char *, char *, s32);
extern int sceKernelRegisterExitCallback(s32);
extern s32 sceKernelDelayThreadCB(u32);
extern s32 sceKernelExitGame(void);

static s32 func_08890060(void);

void func_08890020(void) {
    D_08A631A4 = sceKernelCreateCallback(D_089AD240, (char *)func_08890060, 0);
    sceKernelRegisterExitCallback(D_08A631A4);
    for (;;) {
        sceKernelDelayThreadCB(10000);
    }
}

static s32 func_08890060(void) {
    sceKernelExitGame();
    return 0;
}
