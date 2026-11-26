/* unit_0884EDC8: 0x0884EDC8-0x0884EF0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884EDC8: 0x0884EDC8-0x0884EF0C (ULES01213) */

typedef int s32;
typedef unsigned int u32;
typedef long long s64;

typedef struct V18 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(s32); } V18;

extern "C" {

extern int sceKernelWaitSema(s32, s32, s32);
extern int sceKernelSignalSema(s32, s32);
extern s32 sceIoLseek(s32, s64, s32);
extern s32 sceIoRead(s32, void *, u32);
extern s32 sceKernelDelayThreadCB(u32);
extern void func_0884EC3C(char *, u32);
extern int func_0884EA1C(char *, char *, s32, u32);

s32 func_0884EDC8(char *arg0, s32 arg1, char *arg2, s32 arg3) {
    s32 pos;
    s32 r;
    s32 size;

    sceKernelWaitSema(*(s32 *)(arg0 + 0x2931C), 1, 0);
    pos = ((s32 *)(arg0 + 0x2AC0))[arg1 & 0xFFFF] << 11;
    while (1) {
        r = sceIoLseek(*(s32 *)(arg0 + 0x1010), pos, 0);
        if (r == pos) break;
        sceKernelDelayThreadCB(10000);
    }
    size = ((V18 *)arg0)->vfunc_18(arg1);
    if (arg3 != -1) {
        size = arg3;
    }
    while (1) {
        r = sceIoRead(*(s32 *)(arg0 + 0x1010), arg2, size);
        if (r == size) break;
        sceKernelDelayThreadCB(10000);
    }
    func_0884EC3C(arg0, pos / 2048);
    func_0884EA1C(arg0, arg2, size, 0);
    sceKernelSignalSema(*(s32 *)(arg0 + 0x2931C), 1);
    return size;
}

}
