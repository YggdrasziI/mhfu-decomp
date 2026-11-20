/* unit_088B5568: 0x088B5568-0x088B57A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B5560 and code still in
 * assembly.
 *
 * NonMatching: the image keeps the original code.
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
    u8 unk0[0x14];
} Buf14;

extern s32 D_09A2886C;
extern u8 D_09A28876;
extern Addr6 D_09A2887C;
extern u8 D_09A28882;
extern u8 D_09A28883;
extern u8 D_09A28BEE;
extern Addr6 D_09A28BFC;
extern u8 D_09A28C02;
extern u8 D_09A28C03;
extern Addr6 D_09A29174;
extern u8 D_09A2917A;
extern u8 D_09A2917B;
extern u8 D_09A2917E;

extern char *func_088AFE84(void);
extern void memset(void *, s32, s32);
extern void func_088AEF64(char *);
extern char *func_088B03CC(char *, char *);
extern void func_088AEF98(Info14 *);
extern s32 func_088B7C7C(s32, Addr8 *, Info14 *);
extern s32 func_088B3424(Addr8 *);
extern s32 func_088B6768(Addr8 *);
extern void func_088B5380(Buf14 *, Addr8 *, u16);
extern s32 func_088B6864(Addr8 *);
extern void func_088B7978(Addr8 *);
extern u8 func_088B68FC(void);
extern void func_088B5EDC(Buf14 *, Addr8 *);
extern void func_088B624C(Buf14 *, u8);
extern void func_088B6A80(s32);
extern void func_088B57A0(Buf14 *, Addr8 *, u16);

/* NonMatching, 96.97 %: the original loads D_09A28882 and D_09A28883 before
 * storing either to D_09A2917A / D_09A2917B; this stores the first before
 * loading the second. Tried: temporaries (u8, s32), a 2-byte structure copy,
 * an inline pointer helper, const sources, whole Addr8 copies in C and C++. */
void func_088B5568(void) {
    u16 port;
    Addr8 own;
    Info14 info;
    Buf14 b4C;
    Buf14 b38;
    Buf14 b24;
    Buf14 b10;
    char *src;
    u16 err;
    s32 ok;

    src = func_088AFE84();
    err = 0;
    ok = 0;
    memset(&own, 0, 8);
    func_088AEF64((char *) &own);
    func_088B03CC((char *) &port, src);
    func_088AEF98(&info);
    if (info.unk11 != 0 && func_088B7C7C(1, &own, &info) != 0) {
        ok = 1;
    }
    if (D_09A28876 != 0 && D_09A2886C == 5 && func_088B3424(&own) != 0) {
        err = 0x8031;
    }
    if (err == 0 && ok != 0) {
        if (ok != 0 && func_088B6768(&own) != 0) {
            func_088B5380(&b4C, &own, err);
            return;
        }
    }
    if (err == 0 && D_09A28876 != 0 && func_088B6864(&own) != 0) {
        func_088B7978(&own);
        D_09A28BEE = func_088B68FC();
        func_088B5EDC(&b38, &own);
        func_088B624C(&b24, D_09A28BEE);
        *(Addr6 *) &D_09A28BFC = *(Addr6 *) &own;
        D_09A28C02 = own.unk6;
        D_09A28C03 = own.unk7;
        func_088B6A80(0x10);
        *(Addr6 *) &D_09A29174 = *(Addr6 *) &D_09A2887C;
        D_09A2917A = D_09A28882;
        D_09A2917B = D_09A28883;
        D_09A2917E = D_09A28BEE;
        func_088B6A80(0x11);
    }
    func_088B57A0(&b10, &own, err);
}
