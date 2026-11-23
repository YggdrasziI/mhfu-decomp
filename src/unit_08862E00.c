/* unit_08862E00: 0x08862E00-0x08862E54 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08862E00: set or clear bit 1 of the word returned by func_08862E54. */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 *func_08862E54(void *arg0, s32 arg1);

void func_08862E00(void *arg0, u16 arg1, u8 arg2) {
    s32 *p = func_08862E54(arg0, arg1);
    if (arg2 == 1) {
        *p |= 2;
    } else {
        *p &= ~2;
    }
}
