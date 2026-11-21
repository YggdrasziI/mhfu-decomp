/* unit_088ADA44: 0x088ADA44-0x088ADBA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AD87C and unit_088ADBA4.
 *
 * Queues a datagram for a peer in the send buffer described at 0x09A1FC44:
 * a 0x20-byte header (send time, cleared here; address; port; length;
 * number of sends left), the big-endian sequence number (0 for a datagram
 * sent once, otherwise the running byte count kept in record 0 of the peer
 * table), then the payload. func_088ADBA4 sends the queue.
 *
 * The length is taken as an s32 and narrowed into an s16 local, with a
 * fresh (s16) cast for the payload copy: the original keeps the raw
 * argument in a saved register and sign-extends it again there. The size
 * word is read through its own symbol D_09A1FC48 (as in unit_088AD63C).
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u32 time_lo;
    u32 time_hi;
    u8 mac[6];
    char unkE[0xA];
    u16 port;
    u16 len;
    u16 count;
    u16 unk1E;
    u32 unk20;
} Header;

typedef struct {
    s32 len;
    u32 size;
    char *data;
} Queue;

extern Queue D_09A1FC44;
extern u32 D_09A1FC6C;

extern u32 func_088AD0F8(u32);
extern void memcpy(void *, const void *, s32);
extern u32 D_09A1FC48;
s32 func_088ADA44(s32 id, u8 *mac, u16 port, void *data, s32 len, u16 count) {
    u32 seq;
    Header hdr;
    Queue *q;
    s32 n;
    s16 l;

    q = &D_09A1FC44;
    l = len;
    if (D_09A1FC48 < D_09A1FC44.len + l + 0x24) {
        return -0xC;
    }
    hdr.time_lo = 0;
    hdr.time_hi = 0;
    memcpy(hdr.mac, mac, 6);
    n = l + 4;
    hdr.port = port;
    hdr.len = n;
    hdr.count = count == 0 ? 1 : count;
    if (count == 0) {
        seq = func_088AD0F8(0);
    } else {
        seq = func_088AD0F8(D_09A1FC6C);
        D_09A1FC6C += n;
    }
    memcpy(q->data + q->len, &hdr, 0x20);
    q->len += 0x20;
    memcpy(q->data + q->len, &seq, 4);
    q->len += 4;
    memcpy(q->data + q->len, data, (s16)len);
    q->len += l;
    return l;
}
