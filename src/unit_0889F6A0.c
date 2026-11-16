/* unit_0889F6A0: 0x0889F6A0-0x0889F744 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_0889F5D8 (still in assembly) and
 * unit_0889F744.
 */

#include "unk_msg.h"

typedef struct {
    s32 w[18];
} T48;

extern void func_088A4184(void);
extern s32 func_088A4248(s32);
extern T48 D_09A0C838[32];

s32 func_0889F6A0(void) {
    T48 t;
    s32 i;
    T48 *p;

    clear((char *) &t, sizeof(T48));
    func_088A4184();
    for (i = 0, p = D_09A0C838; i < 32; i++, p++) {
        *p = t;
        p->w[0] = 0;
        p->w[4] = func_088A4248(i);
    }
    return 0;
}
