/* unit_088A8988: 0x088A8988-0x088A8B98 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088A88E0 and
 * func_088A8B98 (still in assembly).
 *
 * Splits a received buffer into packets (4-byte header, length first) and
 * hands each one to a handler chosen by the low nibble of the flags.
 *
 * #pragma optimize_for_size off: the loop is entered behind a guard and
 * tested at the bottom.
 */

#include "unk_peer.h"

extern int memcpy(void *, void *, s32);
extern s32 func_088A8028(Session *, s32, s32);
extern s32 func_088A874C(Session *, s32, Packet *);
extern s32 func_088A88C4(Session *, s32, Packet *);

#pragma optimize_for_size off

s32 func_088A8988(Session *arg0, s32 idx, u8 flags, char *data, u8 size) {
    Packet *pkt;
    s32 r;
    s32 n;
    u8 hdr[4];
    s32 type;
    s32 pos;
    u8 st;
    char *p;

    pkt = &D_09A11F70;
    pos = 0;
    if (arg0->count <= (u8) idx) {
        return 0;
    }
    st = arg0->unk68[(u8) idx];
    switch (st) {
    case 0:
    case 5:
    case 6:
        return 0;
    }
    if (flags & 0xF0) {
        if (size == 4) {
            return 0;
        }
        data += 4;
        size -= 4;
    }
    n = size;
    if (pos < n) {
        type = flags & 0xF;
        do {
            if (n - pos < 4) {
                break;
            }
            p = data + pos;
            memcpy(&hdr, p, 4);
            if (hdr[0] < 4) {
                return func_088A8028(arg0, 5, hdr[0]);
            }
            memcpy(pkt, p, hdr[0]);
            switch (type) {
            case 0:
                break;
            case 1:
                r = func_088A874C(arg0, idx, pkt);
                if (r < 0) {
                    return func_088A8028(arg0, 0xC, r);
                }
                break;
            case 2:
            case 3:
                r = func_088A88C4(arg0, idx, pkt);
                if (r < 0) {
                    return func_088A8028(arg0, 0xC, r);
                }
                break;
            default:
                return func_088A8028(arg0, 5, flags);
            }
            pos += hdr[0];
        } while (pos < n);
    }
    return 0;
}
