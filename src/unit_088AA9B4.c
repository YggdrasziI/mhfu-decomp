/* unit_088AA9B4: 0x088AA9B4-0x088AAC80 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088AA83C (NonMatching, in
 * assembly) and func_088AAC80 (still in assembly); jump table
 * 0x08931FE4-0x08932010 in the unit.
 *
 * Reads the state of a connected socket from the system socket list
 * (inet: TCP control blocks matched on the peer address and port of the
 * socket's table slot; ad hoc: PTP status matched on the socket id):
 * state, free send space and pending received bytes. The list is fetched
 * again when the caller's refresh flag is set.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 sock;
    u8 addr[0x10];
    u16 port;
    char unk16[2];
} Conn;

typedef struct {
    u16 state;
    u16 refresh;
    u16 send_free;
    u16 recv;
} ConnStat;

typedef struct TcpStat {
    struct TcpStat *next;
    s32 snd;
    s32 rcv;
    u32 laddr;
    u8 faddr[4];
    u16 lport;
    u16 fport;
    s16 state;
} TcpStat;

typedef struct PtpStat {
    struct PtpStat *next;
    s32 id;
    u8 mac[6];
    u8 peer_mac[6];
    u16 port;
    u16 peer_port;
    s32 snd;
    s32 rcv;
    s32 state;
} PtpStat;

extern s32 sceNetInetGetTcpcbstat(s32 *, void *);
extern s32 sceNetAdhocGetPtpStat(s32 *, void *);
extern s32 func_0880BFF0(void *, void *, s32);
extern s32 func_088AA14C(s32);
extern s32 D_09A1D728;
extern Conn D_09A1D72C[16];
extern char D_09A1D8AC[];

s32 func_088AA9B4(s32 sock, ConnStat *st) {
    s32 ret;
    TcpStat *t;
    PtpStat *p;
    s32 i;
    Conn *c;
    s32 len;
    Conn *q;

    st->state = 0;
    st->recv = 0;
    st->send_free = 0;
    if (D_09A1D728 != 1) {
        if (st->refresh != 0) {
            len = 0x240;
            if (sceNetInetGetTcpcbstat(&len, D_09A1D8AC) < 0) {
                return -1;
            }
            if (len <= 0) {
                return -1;
            }
        }
        if (sock < 0) {
            return -1;
        }
        i = 0;
        q = D_09A1D72C;
        do {
            c = q;
            if (sock == q->sock) {
                break;
            }
            i++;
            q++;
        } while (i < 16);
        if (i == 16) {
            return -1;
        }
        t = (TcpStat *) D_09A1D8AC;
        if (t != 0) {
            do {
                if (func_0880BFF0(t->faddr, c->addr, 4) == 0 &&
                    t->fport == c->port) {
                    switch (t->state) {
                    case 0:
                    default:
                        st->state = 0;
                        break;
                    case 1:
                        st->state = 1;
                        break;
                    case 2:
                        st->state = 2;
                        break;
                    case 3:
                        st->state = 3;
                        break;
                    case 4:
                        st->state = 4;
                        break;
                    case 5:
                        st->state = 5;
                        break;
                    case 6:
                        st->state = 6;
                        break;
                    case 7:
                        st->state = 7;
                        break;
                    case 8:
                        st->state = 8;
                        break;
                    case 9:
                        st->state = 9;
                        break;
                    case 10:
                        st->state = 10;
                        break;
                    }
                    st->send_free = 0x2000 - t->snd;
                    st->recv = t->rcv;
                    return 0;
                }
                t = t->next;
            } while (t != 0);
        }
        return -1;
    }
    if (st->refresh != 0) {
        len = 0x240;
        ret = func_088AA14C(sceNetAdhocGetPtpStat(&len, D_09A1D8AC));
        if (ret < 0) {
            return ret;
        }
        if (len <= 0) {
            return -1;
        }
    }
    if (sock < 0) {
        return -1;
    }
    p = (PtpStat *) D_09A1D8AC;
    if (p != 0) {
        do {
            if (sock == p->id) {
                switch (p->state) {
                case 1:
                    st->state = 1;
                    break;
                case 2:
                    st->state = 2;
                    break;
                case 3:
                    st->state = 3;
                    break;
                case 4:
                    st->state = 4;
                    break;
                default:
                    st->state = 0;
                    break;
                }
                st->send_free = 0x2000 - p->snd;
                st->recv = p->rcv;
                return 0;
            }
            p = p->next;
        } while (p != 0);
    }
    return -1;
}
