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
 * NonMatching (89.97 %): with every saved register in use, the original
 * keeps the table base in $s0 and spills `len` to the stack (`sh $t0` at
 * entry, `lh` before the size check); ours keeps `len` in $fp and spills
 * or rematerialises the table address instead. Declaration orders, a
 * table local (`register` or not) and the forms of the size check do not
 * change the choice.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

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

extern s32 func_088AAF28(s32, u8 *, u16 *, void *, s16);
extern u32 func_088AD12C(u32);
extern int func_0880BFF0(void *, void *, int);
extern void func_0880C084(void *, const void *, s32);

s32 func_088AD87C(s32 id, u8 *mac, u16 *port, void *out, s16 len) {
    u16 from_port;
    u32 seq;
    u8 from[8];
    Buf *b;
    s32 ret;
    s32 i;
    Peer *e;
    Peer *found;
    s32 n;

    b = &D_09A1FC50;
    for (;;) {
        ret = func_088AAF28(id, from, &from_port, b->data, b->size);
        if (ret <= 0) {
            return ret;
        }
        b->len = ret;
        i = 1;
        e = D_09A1FC5C + 1;
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
        func_0880C084(&seq, b->data, 4);
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
        func_0880C084(mac, found, 6);
        *port = from_port;
        n = b->len - 4;
        if (len < n) {
            return -0xC;
        }
        func_0880C084(out, b->data + 4, n);
        return n;
    }
}
