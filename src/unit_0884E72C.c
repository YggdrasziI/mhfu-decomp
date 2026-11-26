/* unit_0884E72C: 0x0884E72C-0x0884E788 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884E72C: 0x0884E72C-0x0884E788 (ULES01213) */

typedef int s32;
typedef unsigned int u32;

extern void sceKernelDcacheInvalidateRange(const void *, u32);
extern s32 sceIoRead(s32, void *, u32);

s32 func_0884E72C(char *arg0, s32 arg1, char *arg2) {
    sceKernelDcacheInvalidateRange(arg0 + 0x9300, 0x20000);
    return sceIoRead(arg1, arg0 + 0x9300, *(u32 *)(arg2 + 8));
}
