/* unit_088B75B8: 0x088B75B8-0x088B7958 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088B75B8 asm piece, 5 functions
 * between unit_088B7580 and unit_088B7958.
 *
 * The four 0xC-byte peer records at D_09A2851C + 0xC6C (D_09A29188: an
 * 8-byte address, a 16-bit timeout, a retry count and a flag): polls
 * (message kinds 0 and 1, as func_088B4950), timeout reset and insertion.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct {
    s8 b[8];
} Addr8;

typedef struct {
    s8 b[0x14];
} Id;

typedef struct {
    Addr8 addr;
    s16 timer;
    u8 retries;
    u8 unkB;
} Peer;

extern char D_09A2851C[];
extern char D_09A29188[];
extern char D_09A29190[];
extern char D_09A29192[];
extern char D_09A29193[];
extern s16 D_09A29182;
extern u8 D_09A29186;
extern u8 D_09A291B8;
extern u8 D_09A28876;
extern s32 D_09A2886C;

extern void func_0880C464(void *, s32, s32);
extern void func_088AEF64(Addr8 *);
extern s32 func_088AFE78(void);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, Addr8 *);
extern s32 func_088B04B4(void *);
extern s32 func_088B04EC(void *);
extern s32 func_088B0514(void *, void *);
extern s32 func_088B7A10(Addr8 *);

void func_088B7790(Id *arg0, Addr8 *arg1);

void func_088B75B8(Id *arg0, Addr8 *arg1) {
    s32 h;
    Id id;

    h = func_088AFE78();
    func_0880C464(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}

void func_088B7688(void) {
    Addr8 own;
    s32 i;
    char *p;

    func_088AEF64(&own);
    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(p + 0xC6C, &own) == 0) {
            D_09A29193[i * sizeof(Peer)] = 1;
            D_09A29192[i * sizeof(Peer)] = 0;
            *(s16 *) (D_09A29190 + i * sizeof(Peer)) = 0xE1;
            break;
        }
        i++;
        p += sizeof(Peer);
    } while (i < 4);
}

void func_088B7728(void) {
    Addr8 own;
    Id id;

    func_088AEF64(&own);
    if (D_09A28876 == 0 && D_09A2886C == 2 && func_088B7A10(&own) == 0) {
        D_09A291B8 = 1;
        func_088B7790(&id, &own);
    }
}

void func_088B7790(Id *arg0, Addr8 *arg1) {
    s32 h;
    Id id;

    h = func_088AFE78();
    func_0880C464(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 1);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}

void func_088B7860(Addr8 *arg0) {
    s32 i;
    char *p;
    Peer *q;

    if (D_09A28876 == 0) {
        D_09A29182 = 0x384;
        D_09A29186 = 0;
        D_09A291B8 = 0;
        return;
    }
    if (func_088B04EC(arg0) == 0) {
        func_0880C464(D_09A29188, 0, 0x30);
        return;
    }
    i = 0;
    p = D_09A2851C;
    do {
        q = (Peer *) (p + 0xC6C);
        if (func_088B04B4(q) == 0) {
            q->addr = *arg0;
            q->unkB = 1;
            q->retries = 0;
            q->timer = 0xE1;
            return;
        }
        i++;
        p += sizeof(Peer);
    } while (i < 4);
}
