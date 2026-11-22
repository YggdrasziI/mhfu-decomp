/* unit_088905EC: 0x088905EC-0x0889064C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char func_0889064C;
extern s32 sceKernelSetVTimerHandlerWide(s32, long long, void *, void *);
extern int sceKernelStartVTimer(s32);

void func_088905EC(char *arg0) {
    sceKernelSetVTimerHandlerWide(*(s32 *)(arg0 + 0xF7F028), 0, &func_0889064C, arg0);
    sceKernelStartVTimer(*(s32 *)(arg0 + 0xF7F028));
    *(s32 *)(arg0 + 0xF7F02C) = 0;
}
