/* unit_088B826C: 0x088B826C-0x088B8320 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088B81F8 (still in assembly) and
 * unit_088B8320.
 */

#include "unk_msg.h"

typedef struct {
    s32 w[15];
} T3C;

extern s32 func_088B8164(float);
extern s32 func_088B81F8(float);
extern void func_0889EADC(s32, s32, T3C *);

void func_088B826C(float f, s32 arg0, s32 arg1, T3C *src) {
    T3C t;

    clear((char *) &t, sizeof(T3C));
    if (src != 0) {
        t = *src;
    }
    t.w[0] |= 0x1100;
    t.w[13] = func_088B8164(f) & 0xFF;
    t.w[9] = func_088B81F8(f);
    func_0889EADC(arg0, arg1, &t);
}
