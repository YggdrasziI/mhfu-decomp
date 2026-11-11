/* unit_088AD188: 0x088AD188-0x088AD1EC (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern s32 D_09A1DBB8;
extern int sceKernelSignalSema(s32, s32);
extern int sceKernelWaitSema(s32, s32, s32);

void func_088AD188(char *arg0) {
    if (*(u16 *)(arg0 + 0x14) != 0) {
        sceKernelWaitSema(D_09A1DBB8, 1, 0);
    }
}

void func_088AD1BC(char *arg0) {
    if (*(u16 *)(arg0 + 0x14) != 0) {
        sceKernelSignalSema(D_09A1DBB8, 1);
    }
}
