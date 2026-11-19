/* unit_088C30B8: 0x088C30B8-0x088C3138 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088C30B8 asm piece, 1 function
 * between unit_088C3054 and unit_088C3138.
 *
 * Starts the save worker thread func_088C3010 (name D_089B4F2C, priority
 * 0x35, 0x1000-byte stack) on the image at +0x94C or +0x950, with arg0 as
 * its argument.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_089B4F2C[];

extern void func_088C3010(void);
extern s32 sceKernelCreateThread(const char *, void *, s32, s32, s32, void *);
extern s32 sceKernelStartThread(s32, s32, void *);

void func_088C30B8(char *arg0, u8 mode, s32 second) {
    char *self;

    *(u8 *) (arg0 + 0x4A88) = 1;
    *(u8 *) (arg0 + 0x4A8A) = mode;
    if (second == 0) {
        *(s32 *) (arg0 + 0x4A8C) = *(s32 *) (arg0 + 0x94C);
    } else {
        *(s32 *) (arg0 + 0x4A8C) = *(s32 *) (arg0 + 0x950);
    }
    *(s32 *) (arg0 + 0x4A84) = sceKernelCreateThread(D_089B4F2C, func_088C3010, 0x35, 0x1000, 0, 0);
    self = arg0;
    sceKernelStartThread(*(s32 *) (arg0 + 0x4A84), 4, &self);
}
