/* unit_088B85F8: 0x088B85F8-0x088B863C (ULES01213)
 *
 * Bounds (hypothesis): 2 functions on the ring of include/unk_queue.h between
 * code already in units (its other users: unit_088B85CC, unit_088B863C,
 * unit_088B871C).
 *
 * C++: compiled as the neighbouring unit_088B871C, which only matches as C++.
 */

#include "unk_queue.h"

extern "C" {

void func_088B85F8(UnkQueue *q) {
    q->entries[q->head].state = 0;
    q->head = q->head + 1;
    q->head = q->head & 0x7F;
    q->unk100C = 0;
}

s32 func_088B8624(UnkQueue *q) {
    return q->entries[q->head].state != 0;
}

}
