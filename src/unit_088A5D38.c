/* unit_088A5D38: 0x088A5D38-0x088A5ECC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

typedef struct {
    s32 unk0;
    char unk4[0x40];
    s32 unk44;
} T;

extern s32 D_09A0B564;
extern s32 D_09A0B568;
extern s32 D_09A0EB50;
extern s32 D_09A0EB68;
extern s32 D_09A0EB6C;
extern s32 D_09A0EB70;
extern T D_09A0EB80[];
extern char D_089B2710[];
extern char D_089B2718[];
extern char D_089B2748[];
extern int func_0880D9EC(char *, ...);
extern s32 func_088A4654(s32, s32, s32);
extern int sceKernelCpuResumeIntr(s32);
extern s32 sceKernelCpuSuspendIntr(void);
extern int sceKernelPollSema(s32, s32);
extern int sceKernelSignalSema(s32, s32);

s32 func_088A5D38(void) {
    s32 count;
    s32 result;
    s32 temp_a0;
    s32 temp_v1;
    T *entry;

    if (sceKernelPollSema(D_09A0EB68, 1) != 0) {
        return 0;
    }
    count = D_09A0EB6C;
    if (count != 0) do {
        temp_a0 = D_09A0B564;
        D_09A0B564 = temp_a0 + 1;
        if (temp_a0 == 0) {
            D_09A0B568 = sceKernelCpuSuspendIntr();
        }
        entry = &D_09A0EB80[D_09A0EB70];
        result = *(s32 *)func_088A4654(entry->unk0, (s32)entry->unk4, entry->unk44);
        if (D_09A0B564 != 0) {
            temp_v1 = D_09A0B564 - 1;
            D_09A0B564 = temp_v1;
            if (temp_v1 == 0) {
                sceKernelCpuResumeIntr(D_09A0B568);
            }
        }
        if (result >= 0) {
            D_09A0EB6C--;
            if (D_09A0EB80[D_09A0EB70].unk0 == 2) {
                D_09A0EB50--;
            }
        } else {
            func_0880D9EC(D_089B2710);
            func_0880D9EC(D_089B2718);
            func_0880D9EC(D_089B2748);
            break;
        }
        D_09A0EB70 = (D_09A0EB70 + 1) & 0x3F;
    } while (--count != 0);
    sceKernelSignalSema(D_09A0EB68, 1);
    return D_09A0EB6C;
}
