/* unit_088C3054: 0x088C3054-0x088C30B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_089B4F1C;
extern char func_088C2FD8;
extern s32 sceKernelCreateThread(const char *, void *, int, int, unsigned int, void *);
extern int sceKernelStartThread(s32, s32, char **);

void func_088C3054(char *arg0) {
    char *sp1C;

    *(s8 *)(arg0 + 0x4A88) = 1;
    *(s32 *)(arg0 + 0x4A80) = sceKernelCreateThread(&D_089B4F1C, &func_088C2FD8, 0x35, 0x1000, 0, 0);
    sp1C = arg0;
    sceKernelStartThread(*(s32 *)(arg0 + 0x4A80), 4, &sp1C);
}
