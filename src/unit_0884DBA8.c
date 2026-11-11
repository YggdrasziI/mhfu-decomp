/* unit_0884DBA8: 0x0884DBA8-0x0884DBB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void sceKernelDeleteThread(s32);

void func_0884DBA8(char *arg0) {
    sceKernelDeleteThread(*(s32 *)(arg0 + 0x29344));
}
