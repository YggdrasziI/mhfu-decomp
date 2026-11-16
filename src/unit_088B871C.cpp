/* unit_088B871C: 0x088B871C-0x088B89A8 (ULES01213)
 *
 * Bounds (hypothesis): 3 functions on the ring of include/unk_queue.h between
 * code already in units.
 *
 * C++: the structure copy of func_088B88F8 is member by member only in C++ (C
 * copies it word by word).
 */

#include "unk_queue.h"

extern "C" {

extern int sceKernelSuspendDispatchThread(void);
extern int sceKernelResumeDispatchThread(int);

void func_088B88F8(UnkQueue *q, s32 i);

void func_088B871C(UnkQueue *q) {
    s32 state;
    UnkQueueEntry *e;
    s32 i;

    state = sceKernelSuspendDispatchThread();
    e = q->entries;
    for (i = 0; i < 0x80; i++, e++) {
        if (i != q->head) {
            e->state = 0;
        }
        if (e->done != 0) {
            *e->done = 1;
        }
    }
    if (q->entries[q->head].state == 0) {
        q->tail = q->head;
    } else {
        q->tail = q->head + 1;
        q->tail = q->tail & 0x7F;
    }
    sceKernelResumeDispatchThread(state);
}

void func_088B87B0(UnkQueue *q, u8 tag) {
    s32 state;
    UnkQueueEntry *e;
    s32 j;
    s32 n;

    state = sceKernelSuspendDispatchThread();
    e = &q->entries[q->head];
    if (e->state != 0) {
        if (e->tag == tag) {
            if (e->done != 0) {
                *e->done = 1;
            }
        }
        n = 0;
        j = (q->head + 1) & 0x7F;
        do {
            e = &q->entries[j];
            if (e->state == 0) {
                break;
            }
            if (e->tag == tag) {
                if (e->done != 0) {
                    *e->done = 1;
                }
                func_088B88F8(q, j);
            } else {
                j = (j + 1) & 0x7F;
            }
            n++;
        } while (n < 0x7F);
        n = 0;
        q->tail = q->head;
        do {
            if (q->entries[q->tail].state == 0) {
                break;
            }
            q->tail = (q->tail + 1) & 0x7F;
            n++;
        } while (n < 0x7F);
    }
    sceKernelResumeDispatchThread(state);
}

void func_088B88F8(UnkQueue *q, s32 i) {
    s32 j;

    j = (i + 1) & 0x7F;
    if (j != q->head) {
        do {
            q->entries[i] = q->entries[j];
            i = (i + 1) & 0x7F;
            j = (j + 1) & 0x7F;
        } while (j != q->head);
    }
    q->entries[i].state = 0;
}

}
