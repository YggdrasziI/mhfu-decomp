/* unit_088A8B98: 0x088A8B98-0x088A8C78 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088A8988 (NonMatching) and
 * func_088A8C78 (still in assembly).
 *
 * Records the sequence number and counter of a packet header for its sender.
 */

#include "unk_peer.h"

extern u16 func_088AD0F0(u16);

s32 func_088A8B98(Session *arg0, Header *h) {
    if (arg0->count <= h->from) {
        return 0;
    }
    if (arg0->self == h->from) {
        return 0;
    }
    if (arg0->unk110[h->from] == 0) {
        arg0->unk110[h->from] = h->seq;
    } else {
        arg0->unk114[h->from]++;
    }
    arg0->unk114[h->from] = h->seq;
    if (arg0->unkBC[h->from] < 0xFFFEFFFF) {
        arg0->unkBC[h->from] += arg0->unk118[h->from];
    }
    arg0->unk118[h->from] = func_088AD0F0(h->n);
    return 0;
}
