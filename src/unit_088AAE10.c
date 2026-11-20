/* unit_088AAE10: 0x088AAE10-0x088AB028 (ULES01213)
 *
 * Bounds (hypothesis): 4 functions between unit_088AAD58 (NonMatching, in
 * assembly) and unit_088AB028.
 *
 * Socket close (inet with reset, or PTP; the inet table slot is freed),
 * then the ad hoc datagram (PDP) socket: create, receive, send.
 */

/* Same file as unit_088AAC80: conditional rebuilding off
 * (notes/MATCHING.md). */
#pragma opt_rebuildconditionals off

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 addr[0x10];
    u16 port;
    u16 local_port;
} Endpoint;

typedef struct {
    s32 sock;
    u8 addr[0x10];
    u16 port;
    char unk16[2];
} Conn;

extern s32 sceNetInetCloseWithRST(s32);
extern s32 sceNetAdhocPtpClose(s32, s32);
extern s32 sceNetGetLocalEtherAddr(u8 *);
extern s32 sceNetAdhocPdpCreate(u8 *, u16, s32, s32);
extern s32 sceNetAdhocPdpRecv(s32, u8 *, u16 *, void *, s32 *, s32, s32);
extern s32 sceNetAdhocPdpSend(s32, u8 *, u16, void *, s32, s32, s32);
extern int memcpy(void *, void *, s32);
extern s32 func_088AA14C(s32);
extern s32 D_09A1D728;
extern Conn D_09A1D72C[16];

s32 func_088AAE10(s32 *sock) {
    s32 i;
    Conn *c;
    s32 s;

    if (D_09A1D728 != 1) {
        s = *sock;
        if (s >= 0) {
            i = 0;
            c = D_09A1D72C;
            do {
                if (s == c->sock) {
                    D_09A1D72C[i].sock = -1;
                    break;
                }
                i++;
                c++;
            } while (i < 16);
            sceNetInetCloseWithRST(*sock);
            *sock = -1;
        }
        return 0;
    }
    if (*sock >= 0) {
        sceNetAdhocPtpClose(*sock, 0);
        *sock = -1;
    }
    return 0;
}

s32 func_088AAED0(Endpoint *ep) {
    s32 ret;
    u8 mac[8];

    ret = func_088AA14C(sceNetGetLocalEtherAddr(mac));
    if (ret < 0) {
        return ret;
    }
    return func_088AA14C(sceNetAdhocPdpCreate(mac, ep->local_port, 0x2000, 0));
}

s32 func_088AAF28(s32 id, u8 *mac, u16 *port, void *buf, s16 len) {
    s32 n;
    s32 ret;
    u8 from[8];

    n = len;
    ret = sceNetAdhocPdpRecv(id, from, port, buf, &n, 0, 1);
    if (ret == 0x80410709) {
        return 0;
    }
    ret = func_088AA14C(ret);
    if (ret < 0) {
        return ret;
    }
    memcpy(mac, from, 6);
    return n;
}

s32 func_088AAFA4(s32 id, u8 *mac, u16 port, void *buf, s16 len) {
    s32 ret;
    u8 to[8];

    memcpy(to, mac, 6);
    ret = func_088AA14C(sceNetAdhocPdpSend(id, to, port, buf, len, 0, 0));
    return ret < 0 ? ret : len;
}
