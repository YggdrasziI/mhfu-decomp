/* unit_088EF460: 0x088EF460-0x088EF488 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between two units; it is the first
 * callback stored by func_088EF4A8.
 */

typedef int s32;

extern volatile s32 D_09A52180;
extern int sceKernelExitThread(s32);

void func_088EF460(void) {
    if (D_09A52180 == 0) {
        D_09A52180 = 2;
    }
    sceKernelExitThread(D_09A52180);
}
