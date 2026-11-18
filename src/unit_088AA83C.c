/* unit_088AA83C: 0x088AA83C-0x088AA9B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AA67C and unit_088AA9B4.
 *
 * Accepts a connection on a socket of func_088AA67C, returns the peer
 * address and port, and records the inet socket in the 16-slot table of
 * func_088AA370 (ad hoc: PTP accept).
 */

/* Each `return` branches straight to the epilogue: conditional rebuilding
 * off, as in unit_088AAC80 (notes/MATCHING.md). */
#pragma opt_rebuildconditionals off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
    char zero[8];
} SockAddr;

typedef struct {
    s32 sock;
    u8 addr[0x10];
    u16 port;
    char unk16[2];
} Conn;

extern s32 sceNetInetAccept(s32, SockAddr *, s32 *);
extern s32 sceNetInetGetpeername(s32, SockAddr *, s32 *);
extern s32 sceNetInetGetPspError(void);
extern s32 sceNetAdhocPtpAccept(s32, u8 *, u16 *, s32, s32);
extern int func_0880C084(void *, void *, s32);
extern s32 func_088AA14C(s32);
extern s32 D_09A1D728;
extern Conn D_09A1D72C[16];

s32 func_088AA83C(s32 lsock, u8 *addr, u16 *port) {
    SockAddr sa;
    s32 len;
    s32 sock;
    s32 err;
    s32 i;
    Conn *c;

    if (D_09A1D728 != 1) {
        len = 0x10;
        sock = sceNetInetAccept(lsock, &sa, &len);
        if (sock < 0) {
            err = sceNetInetGetPspError();
            if (err == 0x8001000B) {
                return -1;
            }
            return func_088AA14C(err);
        }
        len = 0x10;
        if (sceNetInetGetpeername(sock, &sa, &len) < 0) {
            return func_088AA14C(sceNetInetGetPspError());
        }
        func_0880C084(addr, &sa.addr, 4);
        *port = __builtin_allegrex_wsbh(sa.port);
        i = 0;
        c = D_09A1D72C;
        do {
            if (c->sock < 0) {
                D_09A1D72C[i].sock = sock;
                func_0880C084(D_09A1D72C[i].addr, &sa.addr, 4);
                D_09A1D72C[i].port = sa.port;
                break;
            }
            i++;
            c++;
        } while (i < 16);
        return sock;
    }
    err = sceNetAdhocPtpAccept(lsock, addr, port, 0, 1);
    if (err == 0x80410709) {
        return -1;
    }
    return func_088AA14C(err);
}
