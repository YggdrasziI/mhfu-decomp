/* unit_088A5B50: 0x088A5B50-0x088A5D38 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

typedef struct {
    s32 unk0;
    s32 unk4;
} T;

extern s32 D_09A0B564;
extern s32 D_09A0B568;
extern s32 D_09A0EB50;
extern s32 D_09A0EB68;
extern s32 D_09A0EB6C;
extern s32 D_09A0EB74;
typedef struct {
    s32 unk0;
    char unk4[0x40];
    s32 unk44;
} E;

extern E D_09A0EB80[];
extern char D_089B2710[];
extern char D_089B2718[];
extern char D_089B2720[];
extern int func_0880D9EC(char *, ...);
extern s32 func_088A4AC0(void);
extern s32 func_088A5AFC(void);
extern int memcpy(void *, void *, s32);
extern int memset(void *, s32, s32);
extern int sceKernelCpuResumeIntr(s32);
extern s32 sceKernelCpuSuspendIntr(void);
extern int sceKernelSignalSema(s32, s32);
extern int sceKernelWaitSema(s32, s32, s32);

s32 func_088A5B50(s32 arg0, T *arg1, s32 arg2) {
    s32 id;
    T *p;
    s32 temp_a0;
    s32 temp_v1;

    id = 0;
    p = 0;
    sceKernelWaitSema(D_09A0EB68, 1, 0);
    temp_a0 = D_09A0B564;
    D_09A0B564 = temp_a0 + 1;
    if (temp_a0 == 0) {
        D_09A0B568 = sceKernelCpuSuspendIntr();
    }
    if (func_088A5AFC() >= 0) {
        p = arg1;
        if (arg1->unk4 == 0) {
            id = func_088A4AC0();
            arg1->unk4 = id;
        }
        D_09A0EB80[D_09A0EB74].unk0 = arg0;
        D_09A0EB80[D_09A0EB74].unk44 = arg2;
        memset(D_09A0EB80[D_09A0EB74].unk4, 0, 0x40);
        memcpy(D_09A0EB80[D_09A0EB74].unk4, arg1, arg2);
        D_09A0EB74 = (D_09A0EB74 + 1) & 0x3F;
        D_09A0EB6C++;
        if (arg0 == 2) {
            D_09A0EB50++;
        }
    }
    if (D_09A0B564 != 0) {
        temp_v1 = D_09A0B564 - 1;
        D_09A0B564 = temp_v1;
        if (temp_v1 == 0) {
            sceKernelCpuResumeIntr(D_09A0B568);
        }
    }
    if (id == 0) {
        func_0880D9EC(D_089B2710);
        func_0880D9EC(D_089B2718);
        func_0880D9EC(D_089B2720);
    }
    sceKernelSignalSema(D_09A0EB68, 1);
    if (p != 0) {
        return p->unk4;
    }
    return 0;
}
