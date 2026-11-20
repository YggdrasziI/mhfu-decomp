/* unit_088AA520: 0x088AA520-0x088AA67C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AA370 and unit_088AA67C.
 *
 * Connects a socket opened by func_088AA370 to the address recorded in
 * its table slot (inet), or connects a PTP socket (ad hoc).
 */

/* Each `return` branches straight to the epilogue: conditional rebuilding
 * off, as in unit_088AAC80 (notes/MATCHING.md). */
#pragma opt_rebuildconditionals off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s32 sock;
    u8 addr[0x10];
    u16 port;
    char unk16[2];
} Conn;

typedef struct {
    u8 len;
    u8 family;
    u16 port;
    u8 addr[4];
    char zero[8];
} SockAddr;

extern s32 sceNetInetConnect(s32, SockAddr *, s32);
extern s32 sceNetInetGetPspError(void);
extern s32 sceNetAdhocPtpConnect(s32, s32, s32);
extern void memset(void *, s32, s32);
extern int memcpy(void *, void *, s32);
extern s32 func_088AA14C(s32);
extern s32 D_09A1D728;
extern Conn D_09A1D72C[16];

s32 func_088AA520(s32 sock) {
    s32 i;
    Conn *c;
    s32 err;
    SockAddr sa;

    if (D_09A1D728 != 1) {
        i = 0;
        c = D_09A1D72C;
        do {
            if (sock == c->sock) {
                break;
            }
            i++;
            c++;
        } while (i < 16);
        if (i == 16) {
            return -1;
        }
        memset(&sa, 0, 0x10);
        sa.family = 2;
        memcpy(sa.addr, D_09A1D72C[i].addr, 4);
        sa.port = D_09A1D72C[i].port;
        if (sceNetInetConnect(sock, &sa, 0x10) < 0) {
            err = sceNetInetGetPspError();
            if (err == 0x80010077 || err == 0x80010078) {
                return -1;
            }
            if (err == 0x8001007F) {
                return 0;
            }
            return func_088AA14C(err);
        }
        return 0;
    }
    err = sceNetAdhocPtpConnect(sock, 0, 1);
    if (err == 0x80410709) {
        return -1;
    }
    err = func_088AA14C(err);
    return err < 0 ? err : 0;
}
