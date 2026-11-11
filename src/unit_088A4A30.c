/* unit_088A4A30: 0x088A4A30-0x088A4B5C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0B564;
extern s32 D_09A0B568;
extern s32 D_09A0EB08;
extern s32 D_09A0EB0C;
extern int sceKernelCpuResumeIntr(s32);
extern s32 sceKernelCpuSuspendIntr(void);

s32 func_088A4A30(void) {
    s32 temp_a0;
    s32 temp_v1;

    if (D_09A0EB08 == 0) {
        temp_a0 = D_09A0B564;
        D_09A0B564 = temp_a0 + 1;
        if (temp_a0 == 0) {
            D_09A0B568 = sceKernelCpuSuspendIntr();
        }
        D_09A0EB0C = 0;
        if (D_09A0B564 != 0) {
            temp_v1 = D_09A0B564 - 1;
            D_09A0B564 = temp_v1;
            if (temp_v1 == 0) {
                sceKernelCpuResumeIntr(D_09A0B568);
            }
        }
        D_09A0EB08 = 1;
    }
    return 0;
}

s32 func_088A4AC0(void) {
    s32 temp_a0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;

    temp_a0 = D_09A0B564;
    D_09A0B564 = temp_a0 + 1;
    if (temp_a0 == 0) {
        D_09A0B568 = sceKernelCpuSuspendIntr();
    }
    var_s0 = D_09A0EB0C;
    temp_v1 = var_s0 + 1;
    D_09A0EB0C = temp_v1;
    if (var_s0 == 0) {
        var_s0 = temp_v1;
        D_09A0EB0C = temp_v1 + 1;
    }
    if (D_09A0B564 != 0) {
        temp_v1_2 = D_09A0B564 - 1;
        D_09A0B564 = temp_v1_2;
        if (temp_v1_2 == 0) {
            sceKernelCpuResumeIntr(D_09A0B568);
        }
    }
    return var_s0;
}
