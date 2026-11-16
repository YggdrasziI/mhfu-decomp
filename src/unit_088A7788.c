/* unit_088A7788: 0x088A7788-0x088A7860 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088A748C and func_088A7860 (both
 * still in assembly).
 */

#include "unk_peer.h"

typedef struct {
    char unk0[0x12];
    u16 unk12;
} T14;

extern s32 func_088A748C(Session *);
extern int func_088A84B4(void *, s32, s32);
extern s32 func_088AAED0(T14 *);

s32 func_088A7788(Session *arg0) {
    T14 t;
    s32 ret;
    s32 i;
    Peer *e;
    s32 *d;
    s32 st;

    ret = func_088A748C(arg0);
    if (ret != 0) {
        i = 0;
        if (arg0->count > 0) {
            e = D_09A11EF0;
            d = (s32 *) arg0;
            do {
                st = e->state;
                if (st != 0) {
                    if (st == 8) {
                        func_088A84B4(arg0, i & 0xFF, 6);
                    } else if (st == 6) {
                        d[2] = e->unk1C;
                    }
                }
                i++;
                e++;
                d++;
            } while (i < arg0->count);
        }
        t.unk12 = 0x4E21;
        arg0->unk18 = func_088AAED0(&t);
    }
    return ret;
}
