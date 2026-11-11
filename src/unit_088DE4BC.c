/* unit_088DE4BC: 0x088DE4BC-0x088DE520 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 sceKernelVolatileMemLock(s32, char *, char *);

s32 func_088DE4BC(char *arg0) {
    s32 temp_v0;

    *(s32 *)(arg0 + 0x204) = 0;
    *(s32 *)(arg0 + 0x208) = 0;
    temp_v0 = sceKernelVolatileMemLock(0, arg0 + 0x208, arg0 + 0x204);
    if (temp_v0 < 0) {
        *(s32 *)(arg0 + 0x204) = 0;
    }
    *(s32 *)(arg0 + 0x20C) = (s32) *(s32 *)(arg0 + 0x208);
    *(s32 *)(arg0 + 0x210) = (s32) *(s32 *)(arg0 + 0x204);
    if (temp_v0 == 0) {
        return 1;
    }
    return 0;
}
