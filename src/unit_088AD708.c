/* unit_088AD708: 0x088AD708-0x088AD87C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AD63C and code still in
 * assembly.
 *
 * Synchronises the peer table at 0x09A1FC5C (see unit_088AD63C) with a list
 * of peers (6-byte address at +0x84): adds the addresses not yet in the
 * table to a free record, then frees the records whose address is no
 * longer in the list. Record 0 is this console and is left alone.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 mac[6];
    char unk6[0xA];
    s32 unk10;
    u16 active;
    u16 unk16;
} Peer;

typedef struct Entry {
    struct Entry *next;
    char unk4[0x80];
    u8 mac[6];
} Entry;

extern Peer D_09A1FC5C[16];

extern int func_0880BFF0(void *, void *, int);
extern void memcpy(void *, const void *, s32);

s32 func_088AD708(Entry *list, s32 valid) {
    Peer *t;
    Entry *p;
    s32 i;
    Peer *e;
    s32 j;
    Entry *q;

    t = D_09A1FC5C;
    p = valid ? list : 0;
    if (p != 0) {
        do {
            i = 1;
            e = t + 1;
            do {
                if (e->active != 0 && func_0880BFF0(e, p->mac, 6) == 0) {
                    break;
                }
                i++;
                e++;
            } while (i < 16);
            if (i == 16) {
                j = 1;
                e = t + 1;
                do {
                    if (e->active == 0) {
                        memcpy(e, p->mac, 6);
                        e->unk10 = 1;
                        e->active = 1;
                        e->unk16 = 0xAAAA;
                        break;
                    }
                    j++;
                    e++;
                } while (j < 16);
            }
            p = p->next;
        } while (p != 0);
    }
    i = 1;
    e = t + 1;
    do {
        if (e->active != 0) {
            q = valid ? list : 0;
            if (q != 0) {
                do {
                    if (func_0880BFF0(e, q->mac, 6) == 0) {
                        break;
                    }
                    q = q->next;
                } while (q != 0);
            }
            if (q == 0) {
                e->active = 0;
            }
        }
        i++;
        e++;
    } while (i < 16);
    return 0;
}
