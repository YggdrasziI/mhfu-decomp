/* unit_08890494: 0x08890494-0x088905B0 (ULES01213)
 *
 * Bounds (hypothesis): a thread entry that never returns, followed by
 * func_08890544 which wakes it up.
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CC438;
extern s32 sceKernelSuspendDispatchThread(void);
extern s32 sceKernelResumeDispatchThread(s32);
extern s32 sceKernelCpuSuspendIntr(void);
extern int sceKernelCpuResumeIntr(s32);
extern int sceKernelChangeThreadPriority(s32, s32);
extern int sceKernelSleepThread(void);
extern int sceKernelWakeupThread(s32);

void func_08890494(s32 args, char **argp) {
    char *p;
    s32 state;
    s32 intr;

    for (;;) {
        if ((*(s32 *)(D_089CC438 + 0x6AF14) & 0x200) == 0) {
            goto sleep;
        }
        {
            p = *argp;
            state = sceKernelSuspendDispatchThread();
            intr = sceKernelCpuSuspendIntr();
            sceKernelChangeThreadPriority(*(s32 *)(p + 0xF7F024), 0x26);
            if (*(u8 *)(p + 0xF7F034) != 0) {
                sceKernelChangeThreadPriority(*(s32 *)(p + 0xF7F030), 0x27);
            }
            sceKernelCpuResumeIntr(intr);
            sceKernelResumeDispatchThread(state);
        }
sleep:
        sceKernelSleepThread();
    }
}

void func_08890544(char *arg0) {
    sceKernelChangeThreadPriority(*(s32 *)(arg0 + 0xF7F024), 0x30);
    if (*(u8 *)(arg0 + 0xF7F034) != 0) {
        sceKernelChangeThreadPriority(*(s32 *)(arg0 + 0xF7F030), 0x31);
    }
    sceKernelWakeupThread(*(s32 *)(arg0 + 0xF7F020));
}
