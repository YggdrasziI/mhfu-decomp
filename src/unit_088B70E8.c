/* unit_088B70E8: 0x088B70E8-0x088B72CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B6E8C and unit_088B72CC.
 *
 * While hosting in state 2, counts down the timeout of each accepted peer
 * record (0xC bytes at D_09A2851C + 0xC6C); after five expiries the peer is
 * dropped and announced (events 0x11, 3, 0x10), else it is polled again.
 *
 * NonMatching: the image keeps the original code.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[6];
} B6;

typedef struct {
    s8 b[8];
} Addr8;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad[0x11];
} Id;

/* The 0x14-byte result given to callbacks: +0x8 an argument, +0xC a
 * status byte, +0x10 a 16-bit code. */
typedef struct {
    u8 pad0[8];
    s32 unk8;
    s8 unkC;
    u8 padD[3];
    u16 unk10;
    u8 pad12[2];
} Res;

typedef void (*ResFn)(Res *);

typedef float f32;

typedef struct {
    f32 a, b, c, d;
} F4;

/* The same result copied one member at a time through float registers. */
typedef struct {
    F4 p0;
    f32 p1;
} ResF;

typedef struct {
    u8 used;
    u8 retries;
    u8 pad2[2];
    ResFn cb;
    s32 arg;
    Id id;
    s32 timer;
    u8 handle[0x318];
} Slot;

typedef struct {
    void (*fn)(void);
    s32 unk4;
    s32 unk8;
    u8 padC[0x14];
    u8 unk20;
    u8 pad21[7];
} Ent28;

typedef struct {
    u8 pad0[4];
    ResFn cb;
    s32 arg;
    u8 pad0C[0x14];
    u8 unk20;
    u8 unk21;
    u8 unk22;
} State;

typedef struct {
    Addr8 addr;
    s16 timer;
    u8 retries;
    u8 padB;
} Peer;

extern char D_09A2851C[];
extern s32 D_09A2886C;
extern u8 D_09A28876;
extern B6 D_09A28B98;
extern u8 D_09A28B9E;
extern u8 D_09A28B9F;
extern u8 D_09A28BEE;
extern Addr8 D_09A28BFC;
extern B6 D_09A29174;
extern u8 D_09A2917A;
extern u8 D_09A2917B;
extern u8 D_09A2917E;
extern u8 D_09A299A8;
extern s32 func_088B04B4(void *);
extern s32 func_088B04EC(void *);
extern void func_088B21D0(Id *, u8);
extern u8 func_088B32B8(void);
extern void func_088B5EDC(Id *, Peer *);
extern void func_088B624C(Id *, u8);
extern s32 func_088B6864(void *);
extern u8 func_088B68FC(void);
extern void func_088B75B8(Id *, Peer *);
extern void func_088B7978(Peer *);

void func_088B6A80(s32 arg0);

/* NonMatching, 96.36 %: (1) the original loads D_09A28B9E and D_09A28B9F
 * before storing either to D_09A2917A / D_09A2917B, ours stores the first
 * before loading the second (as func_088B4FAC, func_088B5568); (2) the
 * retry test uses `slti $at` where ours uses `$v0`. Tried for (2): >= 5,
 * !(< 5), > 4, 5 <=, every order of the loop locals. */
void func_088B70E8(void) {
    Id b4C;
    Id b38;
    Id b24;
    Id b10;
    s32 i;
    Peer *r;
    char *p;

    if (D_09A28876 != 0 && D_09A2886C == 2) {
        i = 0;
        p = D_09A2851C;
        do {
            r = (Peer *) (p + 0xC6C);
            if (func_088B04EC(r) != 0) {
                if (func_088B04B4(r) != 0) {
                    if (--r->timer < 0) {
                        r->timer = 0xE1;
                        r->retries++;
                        if (r->retries >= 5) {
                            func_088B6864(r);
                            D_09A28BEE = func_088B68FC();
                            func_088B5EDC(&b4C, r);
                            func_088B624C(&b38, D_09A28BEE);
                            *(B6 *) &D_09A29174 = *(B6 *) &D_09A28B98;
                            D_09A2917A = D_09A28B9E;
                            D_09A2917B = D_09A28B9F;
                            D_09A2917E = D_09A28BEE;
                            func_088B6A80(0x11);
                            D_09A299A8 = func_088B32B8();
                            func_088B21D0(&b24, D_09A299A8);
                            func_088B6A80(3);
                            D_09A28BFC = r->addr;
                            func_088B6A80(0x10);
                            func_088B7978(r);
                        } else {
                            func_088B75B8(&b10, r);
                        }
                    }
                }
            }
            i++;
            p += sizeof(Peer);
        } while (i < 4);
    }
}
