/* unit_088AA67C: 0x088AA67C-0x088AA83C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088AA520 and func_088AA83C
 * (both NonMatching, in assembly).
 *
 * Opens a listening socket: an inet stream socket bound to the local port
 * on any address, or, in ad hoc mode, a PTP listening socket. Errors go
 * through func_088AA14C.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u8 addr[0x10];
    u16 port;
    u16 local_port;
} Endpoint;

typedef struct {
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
    char zero[8];
} SockAddr;

extern s32 sceNetInetSocket(s32, s32, s32);
extern s32 sceNetInetSetsockopt(s32, s32, s32, void *, s32);
extern s32 sceNetInetBind(s32, SockAddr *, s32);
extern s32 sceNetInetListen(s32, s32);
extern s32 sceNetInetClose(s32);
extern s32 sceNetInetGetPspError(void);
extern s32 sceNetGetLocalEtherAddr(u8 *);
extern s32 sceNetAdhocPtpListen(u8 *, u16, s32, s32, s32, s32, s32);
extern void func_0880C464(void *, s32, s32);
extern s32 func_088AA14C(s32);
extern s32 D_09A1D728;

s32 func_088AA67C(Endpoint *ep) {
    s32 sock;
    s32 opt;
    s32 ret;
    u8 mac[8];
    SockAddr sa;

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
        func_0880C464(&sa, 0, 0x10);
        sa.family = 2;
        sa.addr = 0;
        sa.port = __builtin_allegrex_wsbh(ep->local_port);
        if (sceNetInetBind(sock, &sa, 0x10) < 0) {
            sceNetInetClose(sock);
            return func_088AA14C(sceNetInetGetPspError());
        }
        if (sceNetInetListen(sock, 3) < 0) {
            sceNetInetClose(sock);
            return func_088AA14C(sceNetInetGetPspError());
        }
        return sock;
    }
    ret = func_088AA14C(sceNetGetLocalEtherAddr(mac));
    if (ret < 0) {
        return ret;
    }
    return func_088AA14C(sceNetAdhocPtpListen(mac, ep->local_port, 0x2000,
                                              0x3D090, 0x64, 3, 0));
}
