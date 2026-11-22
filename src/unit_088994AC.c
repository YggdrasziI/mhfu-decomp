/* unit_088994AC: 0x088994AC-0x08899874 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly. The
 * id comparison, peer lookup and state helpers are inlined (speed setting).
 */
#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s8 b[6];
} Addr6;

typedef struct {
    u8 b[2];
} B2;

typedef struct {
    Addr6 id;
    u8 unk6;
    u8 unk7;
} Entry;

typedef struct {
    Addr6 id;
    u8 unk6;
    u8 unk7;
    u8 pad8[0xBF - 8];
    u8 state;
    u8 padC0[8];
} Peer;

typedef struct {
    u8 pad0[0x57C];
    Peer peers[4];
    u8 pad89C[0xEE3 - 0x89C];
    s8 count;
    u8 padEE4[0x12D5 - 0xEE4];
    u8 mode;
} Ctx;

extern char *D_09A0B544;
extern int memset(void *, s32, s32);
extern int func_0889DF10(char *, Addr6 *);

static inline int cmp_id(Addr6 *a, Addr6 *b) {
    int i;
    for (i = 0; i < 6; i++) {
        if ((u8) b->b[(unsigned int) i] < (u8) a->b[(unsigned int) i]) {
            return -1;
        }
        if ((u8) a->b[(unsigned int) i] < (u8) b->b[(unsigned int) i]) {
            return 1;
        }
    }
    return 0;
}

static inline Peer *get_peer(Ctx *p, u8 i) {
    return &p->peers[i];
}

static inline int is_active(u8 s) {
    return (s == 2) | (s == 3) | (s == 4) | (s == 5);
}

static inline int peer_active(Ctx *p, s8 i) {
    return is_active(get_peer(p, i)->state);
}

static inline Peer *find_peer(Ctx *p, Addr6 *id) {
    s32 i;
    for (i = 0; i < p->count; i++) {
        if (cmp_id(&p->peers[i].id, id) == 0) {
            return &p->peers[i];
        }
    }
    return 0;
}

static inline int id_empty(s8 *b) {
    return (b[0] | b[1] | b[2] | b[3] | b[4] | b[5]) == 0;
}

u8 func_088994AC(Ctx *arg0, Entry *list) {
    s32 i;
    Peer *p0;
    s32 k;
    Peer *peer;
    u8 found;
    s32 j;
    s32 m;
    s32 n;
    u8 result = 0;

    if (is_active(arg0->mode)) {
        for (i = 1; i < 4; i++) {
            p0 = find_peer(arg0, &list[i].id);
            if (p0 != 0) {
                u8 st = p0->state;
                if (st == 2 || st == 3 || st == 4) {
                    continue;
                }
                if (st == 5 && func_0889DF10(D_09A0B544, &p0->id) != 0) {
                    continue;
                }
            }
            memset(&list[i], 0, 8);
        }
        for (k = 0; k < arg0->count; k++) {
            peer = get_peer(arg0, k);
            if (peer_active(arg0, k)) {
                if (get_peer(arg0, k)->state != 5) {
                    found = 0;
                    for (j = 0; j < 4; j++) {
                        if (!id_empty(list[j].id.b)) {
                            if (cmp_id(&peer->id, &list[j].id) == 0) {
                                found = 1;
                                break;
                            }
                        }
                    }
                    if (!found) {
                        for (m = 0; m < 4; m++) {
                            if (id_empty(list[m].id.b)) {
                                list[m].id = peer->id;
                                result |= (u8) (1 << m);
                                *(B2 *) &list[m].unk6 = *(B2 *) &peer->unk6;
                                break;
                            }
                        }
                    }
                }
            }
        }
    } else {
        for (n = 1; n < 4; n++) {
            memset(&list[n], 0, 8);
        }
    }
    return result;
}
