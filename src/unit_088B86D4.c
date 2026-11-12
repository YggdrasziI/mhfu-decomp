/* unit_088B86D4: 0x088B86D4-0x088B871C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int sceKernelStopModule(s32, s32, void *, int *, void *);
extern int sceKernelUnloadModule(s32);

void func_088B86D4(s32 arg0, s32 arg1) {
    s32 sp1C;

    if (arg1 > 0) {
        sceKernelStopModule(arg1, 0, 0, &sp1C, 0);
        sceKernelUnloadModule(arg1);
    }
}
