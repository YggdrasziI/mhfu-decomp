/* unit_088A3480: 0x088A3480-0x088A34E4 (ULES01213) */
#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;

extern volatile s32 D_09A0DA88;
extern s32 func_08897B84(s32);
extern s32 sceKernelDelayThread(u32);

void func_088A3480(void) {
    D_09A0DA88 += 1;
    if (D_09A0DA88 == 1) {
        while (func_08897B84(0) > 0) {
            sceKernelDelayThread(1000);
        }
    }
}
