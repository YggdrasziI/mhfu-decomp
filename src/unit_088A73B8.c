/* unit_088A73B8: 0x088A73B8-0x088A748C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088A73A8 and func_088A748C (still
 * in assembly).
 */

#include "unk_peer.h"

extern int func_0880C464(void *, s32, s32);
extern int func_0880C084(void *, void *, s32);

void func_088A73B8(Session *arg0) {
    s32 i;
    Peer *e;
    char *s;

    func_0880C464(D_09A11EF0, 0, sizeof(D_09A11EF0));
    i = 0;
    if (arg0->count > 0) {
        e = D_09A11EF0;
        s = (char *) arg0;
        do {
            func_0880C084(e->addr, s + 0x24, 0x10);
            if (i == arg0->self) {
                e->state = 6;
            } else if (i < arg0->self) {
                e->state = 1;
                e->unk4 = arg0->unk78;
            } else {
                e->state = 4;
            }
            e->unk8 = arg0->unk78;
            e->unk1C = -1;
            i++;
            s += 0x10;
            e++;
        } while (i < arg0->count);
    }
}
