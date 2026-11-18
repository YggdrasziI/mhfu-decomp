/* unit_088AA370: 0x088AA370-0x088AA520 (ULES01213)
 *
 * Bounds (hypothesis): first function of the old asm piece text_088AA370,
 * before func_088AA520 (NonMatching, still in assembly).
 *
 * Opens a connection socket: an inet stream socket (two socket options
 * set, then recorded in the first free slot of a 16-entry table) or, in
 * ad hoc mode, a PTP socket. Errors go through func_088AA14C.
 */

typedef unsigned char u8;
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

extern s32 sceNetInetSocket(s32, s32, s32);
extern s32 sceNetInetSetsockopt(s32, s32, s32, void *, s32);
extern s32 sceNetInetClose(s32);
extern s32 sceNetInetGetPspError(void);
extern s32 sceNetGetLocalEtherAddr(u8 *);
extern s32 sceNetAdhocPtpOpen(u8 *, u16, u8 *, u16, s32, s32, s32, s32);
extern int func_0880C084(void *, void *, s32);
extern s32 func_088AA14C(s32);
extern s32 D_09A1D728;
extern Conn D_09A1D72C[16];

s32 func_088AA370(Endpoint *ep) {
    s32 sock;
    s32 opt;
    s32 i;
    Conn *c;
    s32 ret;
    u8 mac[8];

    if (D_09A1D728 != 1) {
        sock = sceNetInetSocket(2, 1, 0);
        if (sock < 0) {
            return func_088AA14C(sceNetInetGetPspError());
        }
        opt = 1;
        if (sceNetInetSetsockopt(sock, 0xFFFF, 1, &opt, 4) < 0) {
            sceNetInetClose(sock);
            return func_088AA14C(sceNetInetGetPspError());
        }
        opt = 1;
        if (sceNetInetSetsockopt(sock, 0xFFFF, 0x1009, &opt, 4) < 0) {
            sceNetInetClose(sock);
            return func_088AA14C(sceNetInetGetPspError());
        }
        i = 0;
        c = D_09A1D72C;
        do {
            if (c->sock < 0) {
                D_09A1D72C[i].sock = sock;
                func_0880C084(D_09A1D72C[i].addr, ep->addr, 4);
                D_09A1D72C[i].port = __builtin_allegrex_wsbh(ep->port);
                break;
            }
            i++;
            c++;
        } while (i < 16);
        return sock;
    }
    ret = func_088AA14C(sceNetGetLocalEtherAddr(mac));
    if (ret < 0) {
        return ret;
    }
    return func_088AA14C(sceNetAdhocPtpOpen(mac, ep->local_port, ep->addr,
                                            ep->port, 0x2000, 0x3D090, 0x64,
                                            0));
}
