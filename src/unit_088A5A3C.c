/* unit_088A5A3C: 0x088A5A3C-0x088A5AFC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0B564;
extern s32 D_09A0B568;
extern s32 D_09A0EB50;
extern s32 D_09A0EB68;
extern s32 D_09A0EB6C;
extern s32 D_09A0EB70;
extern s32 D_09A0EB74;
extern char D_09A0EB80;
extern int func_0880C464(char *, s32, s32);
extern int sceKernelCpuResumeIntr(s32);
extern s32 sceKernelCpuSuspendIntr(void);
extern int sceKernelSignalSema(s32, s32);
extern int sceKernelWaitSema(s32, s32, s32);

void func_088A5A3C(void) {
    s32 temp_a0;
    s32 temp_v1;

    sceKernelWaitSema(D_09A0EB68, 1, 0);
    temp_a0 = D_09A0B564;
    D_09A0B564 = temp_a0 + 1;
    if (temp_a0 == 0) {
        D_09A0B568 = sceKernelCpuSuspendIntr();
    }
    func_0880C464(&D_09A0EB80, 0, 0x1200);
    D_09A0EB74 = 0;
    D_09A0EB70 = 0;
    D_09A0EB6C = 0;
    D_09A0EB50 = 0;
    if (D_09A0B564 != 0) {
        temp_v1 = D_09A0B564 - 1;
        D_09A0B564 = temp_v1;
        if (temp_v1 == 0) {
            sceKernelCpuResumeIntr(D_09A0B568);
        }
    }
    sceKernelSignalSema(D_09A0EB68, 1);
}
