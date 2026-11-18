/* unit_088A8988: 0x088A8988-0x088A8B98 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088A88E0 (NonMatching) and
 * func_088A8B98 (still in assembly). NonMatching: the code stays in the asm
 * piece text_088A8988.
 *
 * Splits a received buffer into packets (4-byte header, length first) and
 * hands each one to a handler chosen by the low nibble of the flags.
 */

#include "unk_peer.h"

extern int func_0880C084(void *, void *, s32);
extern s32 func_088A8028(Session *, s32, s32);
extern s32 func_088A874C(Session *, s32, Packet *);
extern s32 func_088A88C4(Session *, s32, Packet *);

/* NonMatching, 95.4 %: the state test (same shape as func_088A88E0: state 5
 * branches to a separate `v0 = 0; b end` block, ours goes to the end with a
 * beql), `blezl n` before the loop where ours enters it with `b`, and the
 * registers (the original keeps data in s7, the packet in s3, the flags in
 * fp and the size in s6). Tried: if / switch forms and case orders for the
 * state, a flags local, loop forms (for, while, do-while), a 6-byte Header
 * instead of u8[4], the speed pragma, declaration orders.
 */
s32 func_088A8988(Session *arg0, s32 idx, u8 flags, char *data, u8 size) {
    u8 hdr[4];
    s32 pos;
    s32 n;
    s32 type;
    s32 r;
    u8 st;
    char *p;
    Packet *pkt;

    pkt = &D_09A11F70;
    pos = 0;
    if (arg0->count <= (u8) idx) {
        return 0;
    }
    st = arg0->unk68[(u8) idx];
    switch (st) {
    case 0:
    case 5:
        return 0;
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
    type = flags & 0xF;
    for (; pos < n; pos += hdr[0]) {
        if (n - pos < 4) {
            break;
        }
        p = data + pos;
        func_0880C084(&hdr, p, 4);
        if (hdr[0] < 4) {
            return func_088A8028(arg0, 5, hdr[0]);
        }
        func_0880C084(pkt, p, hdr[0]);
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
    }
    return 0;
}
