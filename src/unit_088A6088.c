/* unit_088A6088: 0x088A6088-0x088A6100 (ULES01213)
 *
 * Bounds (hypothesis): 1 function. Copies the halfword at +4 of arg0 to
 * arg1 with bit 2 set or cleared (cleared when bit 1 is set), calls the
 * optional hook D_09A0FD80, then func_088A6690.
 */

typedef unsigned short u16;
typedef int s32;

typedef void (*Hook)(u16 *, void *);

extern Hook D_09A0FD80;
extern s32 func_088A6690(u16 *arg0, s32 arg1);

void func_088A6088(void *arg0, u16 *arg1, u16 arg2) {
    u16 v = *(u16 *)((char *)arg0 + 4);

    if (v & 2) {
        *arg1 = v & ~4;
    } else {
        *arg1 = v | 4;
    }
    if (D_09A0FD80 != 0) {
        D_09A0FD80(arg1, arg0);
    }
    func_088A6690(arg1, arg2);
}
