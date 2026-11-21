/* unit_088A748C: 0x088A748C-0x088A7788 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088A73B8 and unit_088A7788. Its
 * switch has a jump table (0x08931F9C-0x08931FC0, in `.data`), linked
 * from this unit.
 */

#include "unk_peer.h"

typedef struct {
    char addr[0x10];
    u16 port;
    u16 unk12;
} SockAddr;

extern int memcpy(void *, void *, s32);
extern int func_0880BFF0(void *, void *, int);
extern s32 func_088AA9B4(s32, char *);
extern s32 func_088AA370(SockAddr *);
extern s32 func_088AA520(s32);
extern s32 func_088AA67C(SockAddr *);
extern s32 func_088AA83C(s32, char *, u16 *);
extern int func_088AAE10(char *);

/* Code matches; only the jump-table relocation differs (the compiler's own
 * table vs jtbl_08931F9C): linking it needs the 9 words at 0x08931F9C moved
 * from the `.data` assembly into this unit. The second loop reuses the first
 * loop's counter `i` with its own pointer `f`. */
s32 func_088A748C(Session *arg0) {
    s32 r;
    SockAddr sa;
    char mac[0x10];
    u16 port;
    s32 i;
    Peer *e;
    s32 st;
    Peer *f;

    arg0->unkDA = 1;
    func_088AA9B4(-1, arg0->unkD8);
    arg0->unkDA = 0;
    i = 0;
    if (arg0->count > 0) {
        e = D_09A11EF0;
        do {
            switch (e->state) {
            case 1:
                if (1.0f + e->unk4 < arg0->unk78) {
                    e->state = 2;
                    e->unk4 = arg0->unk78;
                }
                break;
            case 2:
                memcpy(sa.addr, e->addr, 0x10);
                sa.port = arg0->self + 0x4E20;
                sa.unk12 = 0;
                r = func_088AA370(&sa);
                if (r < 0) {
                    e->state = 7;
                } else {
                    e->unk1C = r;
                    e->state = 3;
                }
                break;
            case 3:
                if (e->unk8 + arg0->unk134 < arg0->unk78) {
                    e->state = 7;
                    break;
                }
                r = func_088AA520(e->unk1C);
                if (r == 0) {
                    e->state = 6;
                    break;
                }
                if (r == -1) {
                    if (arg0->unk78 < 10.0f + e->unk4) {
                        break;
                    }
                }
                func_088AAE10((char *) &e->unk1C);
                e->state = 1;
                e->unk4 = arg0->unk78;
                break;
            case 4:
                sa.unk12 = i + 0x4E20;
                r = func_088AA67C(&sa);
                if (r < 0) {
                    e->state = 7;
                } else {
                    e->unk1C = r;
                    e->state = 5;
                }
                break;
            case 5:
                if (e->unk8 + arg0->unk134 < arg0->unk78) {
                    e->state = 7;
                    break;
                }
                r = func_088AA83C(e->unk1C, mac, &port);
                if (r == -1) {
                    break;
                }
                if (r < -1) {
                    e->state = 7;
                    break;
                }
                if (arg0->unk20 == 2 || func_0880BFF0(mac, e->addr, 6) == 0) {
                    func_088AAE10((char *) &e->unk1C);
                    e->unk1C = r;
                    e->state = 6;
                } else {
                    func_088AAE10((char *) &r);
                }
                break;
            case 7:
                func_088AAE10((char *) &e->unk1C);
                e->state = 8;
                break;
            case 8:
                break;
            }
            i++;
            e++;
        } while (i < arg0->count);
    }
    i = 0;
    if (arg0->count > 0) {
        f = D_09A11EF0;
        do {
            st = f->state;
            if (st != 0 && st != 8 && st != 6) {
                return 0;
            }
            i++;
            f++;
        } while (i < arg0->count);
    }
    return 1;
}
