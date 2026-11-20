/* unit_088ADBA4: 0x088ADBA4-0x088ADD80 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088ADA44 (NonMatching, still
 * in assembly) and unit_088ADD80.
 *
 * Sends the datagrams queued by func_088ADA44 whose last send is at least
 * 250 ms old (time in microseconds): a datagram with no send left is
 * removed from the queue, the others get the new send time back. Then the
 * set-up of the network layer (func_088ACD88, func_088AD00C) with
 * func_088ADEF0 registered as event callback.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u64 time;
    u8 mac[6];
    char unkE[0xA];
    u16 port;
    u16 len;
    u16 count;
    u16 unk1E;
} Header;

typedef struct {
    s32 len;
    u32 size;
    char *data;
} Queue;

extern Queue D_09A1FC44;

extern u64 sceKernelGetSystemTimeWide(void);
extern s32 func_088AAFA4(s32, u8 *, u16, void *, s16);
extern void memcpy(void *, const void *, s32);
extern void func_088ACD88(void);
extern void func_088AD00C(void);
extern void func_088AD064(void (*)(s32, s32, void *), void *);
extern void func_088ADEF0(s32, s32, void *);

s32 func_088ADBA4(s32 id) {
    Queue *q;
    u64 now;
    s32 off;
    s32 ret;
    s32 n;
    s32 end;
    Header hdr;

    q = &D_09A1FC44;
    now = sceKernelGetSystemTimeWide();
    off = 0;
    if (D_09A1FC44.len > 0) {
        do {
            memcpy(&hdr, q->data + off, 0x20);
            if (now >= hdr.time + 250000) {
                ret = func_088AAFA4(id, hdr.mac, hdr.port, q->data + (off + 0x20), hdr.len);
                if (ret < 0) {
                    return ret;
                }
                if (ret != hdr.len) {
                    return -0xC;
                }
                hdr.time = now;
                hdr.count--;
                if (hdr.count == 0) {
                    n = hdr.len + 0x20;
                    end = off + n;
                    if (end < q->len) {
                        memcpy(q->data + off, q->data + end, q->len - end);
                    }
                    q->len -= n;
                } else {
                    memcpy(q->data + off, &hdr, 0x20);
                    off += hdr.len + 0x20;
                }
            } else {
                off += hdr.len + 0x20;
            }
        } while (off < q->len);
    }
    return 0;
}

void func_088ADD3C(char *arg0) {
    func_088ACD88();
    func_088AD00C();
    func_088AD064(func_088ADEF0, arg0);
    arg0[0xC] = 0;
    arg0[0xD] = 0;
}
