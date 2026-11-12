/* unit_088AD134: 0x088AD134-0x088AD188 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char D_089B2838;
extern s32 D_09A1DBB8;
extern s32 sceKernelCreateSema(char *, s32, s32, s32, s32);

void func_088AD134(char *arg0) {
    if ((*(u16 *)(arg0 + 0x14) != 0) && (D_09A1DBB8 < 0)) {
        D_09A1DBB8 = sceKernelCreateSema(&D_089B2838, 0, 1, 1, 0);
    }
}
