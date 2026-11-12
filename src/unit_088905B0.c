/* unit_088905B0: 0x088905B0-0x088905EC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_089AD258;
extern s32 sceKernelCreateVTimer(const char *, void *);

void func_088905B0(char *arg0) {
    *(s32 *)((char *)arg0 + 0xF7F028) = sceKernelCreateVTimer(&D_089AD258, 0);
}
