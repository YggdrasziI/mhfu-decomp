/* unit_08890430: 0x08890430-0x08890494 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_089AD248;
extern char D_08A631A0;
extern char func_08890494;
extern s32 sceKernelCreateThread(const char *, void *, int, int, unsigned int, void *);
extern int sceKernelStartThread(s32, s32, void *);

void func_08890430(char *arg0) {
    s32 temp_v0;

    temp_v0 = sceKernelCreateThread(&D_089AD248, &func_08890494, 0x28, 0x200, 0, 0);
    *(s32 *)((char *)arg0 + 0xF7F020) = temp_v0;
    sceKernelStartThread(temp_v0, 4, &D_08A631A0);
}
