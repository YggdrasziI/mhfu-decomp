/* unit_0884EF0C: 0x0884EF0C-0x0884F0D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* unit_0884EF0C: 0x0884EF0C-0x0884F0D8 (ULES01213) */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u16 used;
    u16 id;
    s32 data;
    s32 size;
    s32 offset;
    s32 total;
    s32 arg5;
    u8 arg4;
    u8 first;
    u8 last;
    u8 flag;
    u8 rnd;
    u8 pad[3];
} Entry;

typedef struct V18 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(s32); } V18;

extern "C" {

extern char *D_08A631A0;
extern s32 sceKernelSuspendDispatchThread(void);
extern s32 sceKernelResumeDispatchThread(s32);
extern int sceKernelWakeupThread(s32);
extern u16 func_088900C4(char *, s32);

s32 func_0884EF0C(char *arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5, u8 arg6) {
    s32 state;
    s32 total;
    s32 offset;
    u8 first;
    u8 rnd;
    Entry *e;

    state = sceKernelSuspendDispatchThread();
    if (arg3 == -1) {
        arg3 = ((V18 *)arg0)->vfunc_18(arg1);
    }
    total = arg3;
    offset = 0;
    first = 1;
    rnd = 0;
    if (*(u8 *)(arg0 + 0x2FBCC) != 0) {
        if (func_088900C4(D_08A631A0, 1) % 100 < 5) {
            rnd = first;
        }
    }
    while (1) {
        e = (Entry *)(arg0 + *(s32 *)(arg0 + 0x1008) * 32 + 4);
        e->used = 1;
        e->offset = offset;
        e->id = arg1;
        e->data = arg2;
        e->arg4 = arg4;
        e->arg5 = arg5;
        e->first = first;
        e->flag = *(u8 *)(arg0 + 0x2FBCC);
        e->rnd = rnd;
        e->total = total;
        if (arg3 < 0x20001) {
            e->size = arg3;
            *(s32 *)(arg0 + 0x1008) = *(s32 *)(arg0 + 0x1008) + 1;
            *(s32 *)(arg0 + 0x1008) = *(s32 *)(arg0 + 0x1008) & 0x7F;
            e->last = 1;
            break;
        }
        e->size = 0x20000;
        offset += 0x20000;
        e->last = 0;
        arg3 -= 0x20000;
        first = 0;
        *(s32 *)(arg0 + 0x1008) = *(s32 *)(arg0 + 0x1008) + 1;
        *(s32 *)(arg0 + 0x1008) = *(s32 *)(arg0 + 0x1008) & 0x7F;
    }
    sceKernelResumeDispatchThread(state);
    if (arg6) {
        sceKernelWakeupThread(*(s32 *)(arg0 + 0x29344));
    }
    return 1;
}

}
