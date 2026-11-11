/* unit_088A5EF8: 0x088A5EF8-0x088A5FC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0B564;
extern s32 D_09A0B568;
extern char D_09A0EB54;
extern int func_0880C084(char *, s32, s32);
extern s32 func_088A4654(s32, s32, s32);
extern int sceKernelCpuResumeIntr(s32);
extern s32 sceKernelCpuSuspendIntr(void);

char *func_088A5EF8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_v1;

    if (arg0 != 0x64) {
        return 0;
    }
    temp_a0 = D_09A0B564;
    D_09A0B564 = temp_a0 + 1;
    if (temp_a0 == 0) {
        D_09A0B568 = sceKernelCpuSuspendIntr();
    }
    func_0880C084(&D_09A0EB54, func_088A4654(arg0, arg1, arg2), 0x14);
    if (D_09A0B564 != 0) {
        temp_v1 = D_09A0B564 - 1;
        D_09A0B564 = temp_v1;
        if (temp_v1 == 0) {
            sceKernelCpuResumeIntr(D_09A0B568);
        }
    }
    return &D_09A0EB54;
}
