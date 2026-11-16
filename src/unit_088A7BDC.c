/* unit_088A7BDC: 0x088A7BDC-0x088A7DC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088A7A68 and unit_088A7DC0.
 */

#include "unk_peer.h"

extern int func_0880C084(void *, void *, s32);
extern int func_0880BFF0(void *, void *, int);
extern s32 func_088AAF28(s32, char *, u16 *, char *, s32);
extern int func_088A8028(Session *, int, int);
extern s32 func_088A8C78(Session *, char *, s32, u8 *);
extern s32 func_088A7AF0(Session *, u8 *);
extern s16 D_09A11EDC;
extern char *D_09A11EE0;
extern s32 D_09A1D594;
extern char *D_09A1D598;

s32 func_088A7BDC(Session *arg0) {
    u8 hdr[6];
    char addr[0x10];
    u16 port;
    RecvBuf *g;
    s32 i;
    char *s;
    s32 r;

    g = &D_09A11ED8;
    for (;;) {
        r = func_088AAF28(arg0->unk18, addr, &port, D_09A11EE0, D_09A11EDC);
        if (r < 0) {
            return func_088A8028(arg0, 3, r);
        }
        if (r == 0) {
            break;
        }
        g->len = r;
        arg0->unkA8 += r;
        if (arg0->unk68[arg0->self] == 4) {
            continue;
        }
        i = 0;
        if (arg0->count > 0) {
            s = (char *) arg0;
            do {
                if (i != arg0->self) {
                    switch (arg0->unk20) {
                    case 1:
                        if (func_0880BFF0(s + 0x24, addr, 6) != 0) {
                            break;
                        }
                        goto done;
                    case 2:
                        if (func_0880BFF0(s + 0x24, addr, 4) == 0) {
                            goto done;
                        }
                        break;
                    default:
                        goto done;
                    }
                }
                i++;
                s += 0x10;
            } while (i < arg0->count);
        }
done:
        if (arg0->count == i) {
            continue;
        }
        r = func_088A8C78(arg0, g->buf, g->len, hdr);
        if (r <= 0) {
            continue;
        }
        if (r != g->len) {
            continue;
        }
        if (func_088A7AF0(arg0, hdr) < 0) {
            continue;
        }
        if (D_09A1D594 < D_09A1D590.pos + g->len) {
            return func_088A8028(arg0, 4, D_09A1D590.pos + g->len);
        }
        func_0880C084(D_09A1D598 + D_09A1D590.pos, g->buf, g->len);
        D_09A1D590.pos += g->len;
    }
    return 0;
}
