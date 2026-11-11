/* unit_08859218: 0x08859218-0x08859224 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;

extern s8 D_08A62C44;
extern void sceKernelSleepThreadCB(void);

void func_08859218(void) {
    D_08A62C44 = 0;
    sceKernelSleepThreadCB();
}
