/* unit_088AD87C: 0x088AD87C-0x088ADA44 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AD708 and code still in
 * assembly.
 *
 * Receives a datagram from a known peer (see unit_088AD63C): reads into the
 * buffer described at 0x09A1FC50 until the sender is an active record of
 * the peer table, checks its big-endian sequence number against the last
 * one kept in the record, then returns the sender's address and port and
 * copies the payload after the sequence number.
 *
 * Compiled for speed. The peer table base is held in a local, the size
 * is passed to func_088AAF28 as an s32 (argument load order: size before
 * buffer), and the sender address is a 16-byte buffer (stack layout).
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#pragma optimize_for_size off

typedef struct {
    u8 mac[6];
    char unk6[0xA];
    u32 seq;
    u16 active;
    u16 unk16;
} Peer;

typedef struct {
    s32 len;
    s16 size;
    char *data;
} Buf;

extern Peer D_09A1FC5C[16];
extern Buf D_09A1FC50;

extern s32 func_088AAF28(s32, u8 *, u16 *, void *, s32);
extern u32 func_088AD12C(u32);
extern int func_0880BFF0(void *, void *, int);
extern void memcpy(void *, const void *, s32);

s32 func_088AD87C(s32 id, u8 *mac, u16 *port, void *out, s16 len) {
    Buf *b;
    u32 seq;
    s32 ret;
    Peer *found;
    u16 from_port;
    s32 i;
    Peer *t;
    u8 from[16];
    Peer *e;
    s32 n;

    b = &D_09A1FC50;
    t = D_09A1FC5C;
    for (;;) {
        ret = func_088AAF28(id, from, &from_port, b->data, b->size);
        if (ret <= 0) {
            return ret;
        }
        b->len = ret;
        i = 1;
        e = t + 1;
        do {
            found = e;
            if (e->active != 0 && func_0880BFF0(e, from, 6) == 0) {
                break;
            }
            i++;
            e++;
        } while (i < 16);
        if (i == 16) {
            continue;
        }
        memcpy(&seq, b->data, 4);
        if (func_088AD12C(seq) != 0) {
            if (found->active == 1) {
                found->seq = func_088AD12C(seq);
                found->active = 2;
            } else if (found->active != 2) {
                continue;
            } else if (func_088AD12C(seq) <= found->seq) {
                continue;
            }
        }
        if (func_088AD12C(seq) != 0) {
            found->seq = func_088AD12C(seq);
        }
        memcpy(mac, found, 6);
        *port = from_port;
        n = b->len - 4;
        if (len < n) {
            return -0xC;
        }
        memcpy(out, b->data + 4, n);
        return n;
    }
}
