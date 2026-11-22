/* unit_0888051C: 0x0888051C-0x088805A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_089AC554[];
extern s32 func_088805A0(unsigned int, void *);
extern s32 sceKernelCreateThread(const char *, void *, s32, s32, s32, void *);
extern s32 sceKernelStartThread(s32, s32, void *);

void func_0888051C(char *arg0) {
    char *self;

    if (*(u8 *) (arg0 + 0x562421) != 1) {
        *(s32 *) (arg0 + 0x562424) = sceKernelCreateThread(D_089AC554, func_088805A0, 0x10, 0x1000, 0, 0);
        self = arg0;
        sceKernelStartThread(*(s32 *) (arg0 + 0x562424), 4, &self);
    }
}
