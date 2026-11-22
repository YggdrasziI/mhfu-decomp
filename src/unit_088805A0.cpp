/* unit_088805A0: 0x088805A0-0x08880660 (ULES01213)
 *
 * Thread entry; loads utility modules 0x300-0x302, stores
 * their results in the state block passed through argp, then waits until
 * the 0x38 virtual method of D_089CC434 returns 0.
 *
 * C++: one virtual call.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef struct V38 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual s32 vfunc_38(); } V38;

extern "C" {

extern V38 *D_089CC434;
extern char D_089B918C;
extern s32 sceUtilityLoadModule(s32);
extern s32 sceKernelDelayThreadCB(u32);
extern s32 sceKernelExitDeleteThread(s32);

s32 func_088805A0(u32 args, void *argp) {
    char *p = *(char **)argp;

    *(s32 *)(p + 0x562428) = sceUtilityLoadModule(0x300);
    *(s32 *)(p + 0x56242C) = sceUtilityLoadModule(0x301);
    *(s32 *)(p + 0x562430) = sceUtilityLoadModule(0x302);
    *(char **)(p + 0x308BC4) = &D_089B918C;
    for (;;) {
        if (!D_089CC434->vfunc_38()) break;
        sceKernelDelayThreadCB(10000);
    }
    *(u8 *)(p + 0x562421) = 1;
    sceKernelExitDeleteThread(0);
    return 0;
}

}
