/* unit_088A4004: 0x088A4004-0x088A407C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between its neighbours.
 */

/* func_088A4004: thread entry; runs a callback each tick until D_09A0E380
 * is set, then exits the thread.
 */
#pragma optimize_for_size off

typedef int s32;

extern s32 D_09A0E380;
extern void func_0889EF20(s32);
extern s32 sceKernelExitThread(s32);

typedef struct {
    s32 unk0;
    s32 unk4;
    void (*unk8)(s32);
} T;

s32 func_088A4004(s32 args, void *argp) {
    volatile T *s = *(volatile T **)argp;

    while (D_09A0E380 == 0) {
        func_0889EF20(0);
        if (s->unk8 != 0) {
            s->unk8(s->unk4);
        }
        s->unk4++;
    }
    sceKernelExitThread(0);
    return 0;
}
