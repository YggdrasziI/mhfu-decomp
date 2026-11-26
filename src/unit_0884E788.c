/* unit_0884E788: 0x0884E788-0x0884E7FC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884E788: 0x0884E788-0x0884E7FC (ULES01213) */

typedef int s32;

extern s32 func_0884E7FC(char *, char *);
extern void memcpy(void *, void *, s32);
extern void sceKernelDcacheWritebackAll(void);

void func_0884E788(char *arg0, char *arg1) {
    if (func_0884E7FC(arg0, arg1) != 0) {
        memcpy(*(char **)(arg1 + 0x4) + *(s32 *)(arg1 + 0xC), arg0 + 0x9300,
               *(s32 *)(arg1 + 0x8));
        sceKernelDcacheWritebackAll();
    } else if (*(s32 **)(arg1 + 0x14) != 0) {
        **(s32 **)(arg1 + 0x14) = 1;
    }
}
