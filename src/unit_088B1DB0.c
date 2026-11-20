/* unit_088B1DB0: 0x088B1DB0-0x088B1F2C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1CA8 and unit_088B1F2C.
 *
 * Reads the sender address and a byte from the message of func_088AFE84;
 * error 0x8000 when D_09A28876 is clear, 0x8021 when func_088B6768 accepts
 * the address, 0x8031 in state 5; otherwise the error comes from
 * func_088B33BC, and when it is 0 the address is added (func_088B3328) and
 * D_09A299A8 refreshed (func_088B32B8, func_088B21D0, func_088B6A80(3)).
 * Replies with func_088B1F2C (as func_088B5568).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[6];
} Addr6;

typedef struct {
    Addr6 unk0;
    u8 unk6;
    u8 unk7;
} Addr8;

typedef struct {
    u8 unk0[0x11];
    u8 unk11;
    u8 pad[2];
} Info14;

typedef struct {
    s8 b[0x14];
} Id;

extern s32 D_09A2886C;
extern u8 D_09A28876;
extern u8 D_09A299A8;

extern char *func_088AFE84(void);
extern void memset(void *, s32, s32);
extern void func_088AEF64(char *);
extern char *func_088B03CC(u16 *, char *);
extern void func_088B03BC(u8 *, char *);
extern void func_088AEF98(Info14 *);
extern s32 func_088B7C7C(s32, Addr8 *, Info14 *);
extern s32 func_088B6768(Addr8 *);
extern u16 func_088B33BC(Addr8 *, u8);
extern void func_088B3328(Addr8 *, u8);
extern u8 func_088B32B8(void);
extern void func_088B21D0(Id *, u8);
extern s32 func_088B6A80(s32);
extern void func_088B1F2C(Id *, Addr8 *, u16);

void func_088B1DB0(void) {
    u8 c;
    u16 port;
    Addr8 own;
    Info14 info;
    Id a;
    Id b;
    char *src;
    u16 err;
    s32 ok;

    src = func_088AFE84();
    err = 0;
    ok = 0;
    memset(&own, 0, 8);
    func_088AEF64((char *) &own);
    src = func_088B03CC(&port, src);
    func_088B03BC(&c, src);
    func_088AEF98(&info);
    if (info.unk11 != 0 && func_088B7C7C(2, &own, &info) != 0) {
        ok = 1;
    }
    if (D_09A28876 == 0) {
        err = 0x8000;
    } else if (func_088B6768(&own) != 0) {
        err = 0x8021;
    } else if (D_09A2886C == 5) {
        err = 0x8031;
    }
    if (err == 0) {
        if (ok == 0) {
            err = func_088B33BC(&own, c);
        } else if (ok != 0) {
            err = func_088B33BC(&own, c);
        }
    }
    if (err == 0) {
        func_088B3328(&own, c);
        D_09A299A8 = func_088B32B8();
        func_088B21D0(&a, D_09A299A8);
        func_088B6A80(3);
    }
    func_088B1F2C(&b, &own, err);
}
