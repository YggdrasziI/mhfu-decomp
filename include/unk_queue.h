/* A ring of 128 32-byte entries used by the functions of 0x088B85CC-0x088B89A8
 * (head index at +0x1004, a second index at +0x1008). Layout from the code; the
 * type and field names are descriptive, not the original ones. */

#ifndef UNK_QUEUE_H
#define UNK_QUEUE_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct UnkQueueEntry {
    u16 state; /* 0: free */
    u16 id;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 *done; /* set to 1 when the entry is dropped */
    u8 tag;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
} UnkQueueEntry;

typedef struct UnkQueue {
    s32 unk0;
    UnkQueueEntry entries[128];
    s32 head;
    s32 tail;
    s32 unk100C;
} UnkQueue;

#endif
