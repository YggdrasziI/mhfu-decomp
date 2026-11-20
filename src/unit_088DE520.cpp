/* unit_088DE520: 0x088DE520-0x088DE6A0 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088DE4BC and unit_088DE6A0.
 *
 * Volatile memory of the resource table (unit_088DD8A8): func_088DE520
 * unlocks it and clears the bump area; func_088DE560 is a callback
 * (events 1 and 2) that gives the memory back with thread dispatch
 * suspended.
 *
 * Optimized for speed, as unit_088DD8A8 (same unrolled loop, written
 * `i <= 42`).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct Entry {
    u16 flags;
    u16 id;
    s32 ptr;
    s32 unk8;
};

struct Table {
    Entry e[43];
    u32 unk204;
    u32 unk208;
    u32 unk20C;
    u32 unk210;
    u8 unk214;
    u8 unk215;
    u8 unk216;
};

extern "C" {

extern char *D_089CC434;
extern char *D_089CC438;

extern void func_0884EB00(char *);
extern void func_088B87B0(char *, u8);
extern s32 sceKernelSuspendDispatchThread(void);
extern s32 sceKernelResumeDispatchThread(s32);
extern s32 sceKernelVolatileMemUnlock(s32);

static inline void table_rewind(Table *t) {
    s32 i;

    t->unk210 = t->unk204;
    t->unk20C = t->unk208;
    for (i = 0x15; i <= 42; i++) {
        t->e[i].flags &= ~2;
    }
    func_088B87B0(D_089CC434, 1);
}

void func_088DE520(Table *arg0) {
    sceKernelVolatileMemUnlock(0);
    arg0->unk204 = 0;
    arg0->unk208 = 0;
    arg0->unk20C = arg0->unk208;
    arg0->unk210 = arg0->unk204;
}

s32 func_088DE560(s32 arg0, s32 arg1, Table *arg2) {
    s32 state;

    if (arg1 != 2) {
        if (arg1 != 1) {
            return 0;
        }
    }
    {
        *(u8 *)(D_089CC438 + 0x2A) |= 1;
        arg2->unk215 = 0;
        if (arg2->unk214 != 0) {
            func_0884EB00(D_089CC434);
            state = sceKernelSuspendDispatchThread();
            arg2->unk214 = 0;
            table_rewind(arg2);
            func_088DE520(arg2);
            sceKernelResumeDispatchThread(state);
        }
    }
    return 0;
}

}
