/* unit_088A16A4: 0x088A16A4-0x088A173C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern s32 D_09A0B564;
extern s32 D_09A0B568;
extern int sceKernelCpuResumeIntr(s32);
extern s32 sceKernelCpuSuspendIntr(void);
extern u8 func_088A0820(s32, s32);

s32 func_088A16A4(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_v1;

    temp_a0 = D_09A0B564;
    D_09A0B564 = temp_a0 + 1;
    if (temp_a0 == 0) {
        D_09A0B568 = sceKernelCpuSuspendIntr();
    }
    *(u8 *)((char *)arg0 + 0x12) = func_088A0820(arg1, 0);
    *(s32 *)arg0 = 0;
    if (D_09A0B564 != 0) {
        temp_v1 = D_09A0B564 - 1;
        D_09A0B564 = temp_v1;
        if (temp_v1 == 0) {
            sceKernelCpuResumeIntr(D_09A0B568);
        }
    }
    return *(s32 *)arg0;
}
