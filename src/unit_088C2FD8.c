/* unit_088C2FD8: 0x088C2FD8-0x088C3054 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern s8 func_088C022C(char *, s32, u8);
extern int func_088C0468(char *);
extern int sceKernelExitDeleteThread(s32);

s32 func_088C2FD8(s32 arg0, char **arg1) {
    char *temp_s0;

    temp_s0 = *arg1;
    func_088C0468(temp_s0);
    *(s8 *)(temp_s0 + 0x4A88) = 0;
    sceKernelExitDeleteThread(0);
    return 0;
}

s32 func_088C3010(s32 arg0, char **arg1) {
    char *temp_s0;

    temp_s0 = *arg1;
    *(s8 *)(temp_s0 + 0x4A89) = func_088C022C(temp_s0, *(s32 *)(temp_s0 + 0x4A8C), *(u8 *)(temp_s0 + 0x4A8A));
    *(s8 *)(temp_s0 + 0x4A88) = 0;
    sceKernelExitDeleteThread(0);
    return 0;
}
