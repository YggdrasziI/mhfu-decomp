/* unit_088A173C: 0x088A173C-0x088A177C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_089B243C;
extern s32 sceKernelCreateSema(char *, s32, s32, s32, s32);

void func_088A173C(s32 *arg0) {
    *arg0 = sceKernelCreateSema(&D_089B243C, 0x100, 1, 1, 0);
}
