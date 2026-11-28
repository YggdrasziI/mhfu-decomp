/* unit_0884F190: 0x0884F190-0x0884F244 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884F190: 0x0884F190-0x0884F244 (ULES01213) */

typedef int s32;
typedef unsigned int u32;

extern s32 sceUmdGetDriveStat(void);
extern s32 sceKernelDelayThreadCB(u32);
extern s32 sceIoRead(s32, void *, u32);

void func_0884F190(char *arg0, void *buf, s32 size) {
    s32 r;

    if (((sceUmdGetDriveStat() & 0x20) != 0) ^ 1) {
        do {
            sceKernelDelayThreadCB(10000);
        } while (((sceUmdGetDriveStat() & 0x20) != 0) ^ 1);
    }
    while (1) {
        r = sceIoRead(*(s32 *)(arg0 + 0x1010), buf, size);
        if (r == size) break;
        sceKernelDelayThreadCB(10000);
    }
    *(u32 *)(arg0 + 0x2FBD0) += size;
}
