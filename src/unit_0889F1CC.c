/* unit_0889F1CC: 0x0889F1CC-0x0889F288 (ULES01213) */

typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 unk0;
    u32 unk4;
    s32 unk8;
    u32 unkC;
    char *unk10;
} Queue;

extern s32 D_09A0B5BC;
extern s32 D_09A0B5C4;
extern s32 sceKernelSuspendDispatchThread(void);
extern s32 sceKernelResumeDispatchThread(s32);
extern void memcpy(void *, void *, s32);

s32 func_0889F1CC(s32 arg0, void *dst) {
    s32 state;
    s32 ret;
    Queue *q;
    u32 next;

    state = sceKernelSuspendDispatchThread();
    switch (arg0) {
    case 0:
        q = (Queue *)&D_09A0B5BC;
        if (D_09A0B5C4 == 0) {
            ret = 0x8000001B;
        } else {
            memcpy(dst, q->unk10 + (q->unk4 << 6), 0x40);
            next = (q->unk4 + 1) % q->unkC;
            ret = q->unk8 - 1;
            q->unk8 = ret;
            q->unk4 = next;
        }
        break;
    default:
        ret = 0x80000019;
        break;
    }
    sceKernelResumeDispatchThread(state);
    return ret;
}
