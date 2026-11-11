/* unit_088A177C: 0x088A177C-0x088A1798 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern void sceKernelSignalSema(s32, s32);
extern void sceKernelWaitSema(s32, s32, s32);

void func_088A177C(char *arg0) {
    sceKernelWaitSema(*(s32 *)arg0, 1, 0);
}

void func_088A178C(char *arg0) {
    sceKernelSignalSema(*(s32 *)arg0, 1);
}
