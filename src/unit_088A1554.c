/* unit_088A1554: 0x088A1554-0x088A16A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088A1500 and unit_088A16A4.
 */

typedef int s32;
typedef unsigned char u8;

typedef struct {
    char unk0[0x8];
    s32 unk8;
} Inner;

typedef struct {
    char unk0[0x10];
    Inner *unk10;
} Node;

extern s32 D_09A0B564;
extern s32 D_09A0B568;
extern Node *func_0889F4BC(void);
extern Node *func_0889F4F0(void);
extern Node *func_0889F444(void);
extern Node *func_0889F47C(void);
extern u8 func_0889F42C(void);
extern u8 func_0889F438(void);
extern int sceKernelCpuResumeIntr(s32);
extern s32 sceKernelCpuSuspendIntr(void);

s32 func_088A1554(char *arg0) {
    Node *node;
    s32 temp_a0;
    s32 temp_v1;
    s32 a;
    s32 b;

    a = 0;
    b = 0;
    temp_a0 = D_09A0B564;
    D_09A0B564 = temp_a0 + 1;
    if (temp_a0 == 0) {
        D_09A0B568 = sceKernelCpuSuspendIntr();
    }
    node = func_0889F4BC();
    if (node != 0) {
        do {
            a |= node->unk10->unk8;
            node = func_0889F4F0();
        } while (node != 0);
    }
    if (D_09A0B564 != 0) {
        temp_v1 = D_09A0B564 - 1;
        D_09A0B564 = temp_v1;
        if (temp_v1 == 0) {
            sceKernelCpuResumeIntr(D_09A0B568);
        }
    }
    temp_a0 = D_09A0B564;
    D_09A0B564 = temp_a0 + 1;
    if (temp_a0 == 0) {
        D_09A0B568 = sceKernelCpuSuspendIntr();
    }
    node = func_0889F444();
    if (node != 0) {
        do {
            b |= node->unk10->unk8;
            node = func_0889F47C();
        } while (node != 0);
    }
    if (D_09A0B564 != 0) {
        temp_v1 = D_09A0B564 - 1;
        D_09A0B564 = temp_v1;
        if (temp_v1 == 0) {
            sceKernelCpuResumeIntr(D_09A0B568);
        }
    }
    *(s32 *)(arg0 + 0x8) = b;
    *(s32 *)(arg0 + 0xC) = a;
    *(u8 *)(arg0 + 0x10) = func_0889F42C();
    *(u8 *)(arg0 + 0x11) = func_0889F438();
    *(s32 *)(arg0 + 0x0) = 0;
    return 0;
}
