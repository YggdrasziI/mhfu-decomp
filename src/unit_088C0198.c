/* unit_088C0198: 0x088C0198-0x088C0200 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_089B4DE4;
extern char D_089B4DF0;
extern char func_088C0200;
extern int sceIoDevctl(char *, s32, s32 *, s32, s32, s32);
extern s32 sceKernelCreateCallback(char *, char *, char *);

void func_088C0198(char *arg0) {
    s32 sp1C;
    s32 temp_v0;

    *(s8 *)(arg0 + 0x978) = 0;
    temp_v0 = sceKernelCreateCallback(&D_089B4DE4, &func_088C0200, arg0);
    *(s32 *)(arg0 + 0x974) = temp_v0;
    sp1C = temp_v0;
    sceIoDevctl(&D_089B4DF0, 0x02415821, &sp1C, 4, 0, 0);
}
