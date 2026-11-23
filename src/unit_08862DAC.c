/* unit_08862DAC: 0x08862DAC-0x08862E00 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08862DAC: sets or clears bit 0 of the entry word returned by func_08862E54. */

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

extern s32 *func_08862E54(void *arg0, s32 arg1);

void func_08862DAC(void *arg0, u16 arg1, u8 arg2) {
    s32 *p = func_08862E54(arg0, arg1);

    if (arg2 == 1) {
        *p |= 1;
    } else {
        *p &= ~1;
    }
}
