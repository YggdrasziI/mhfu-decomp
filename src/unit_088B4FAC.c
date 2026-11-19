/* unit_088B4FAC: 0x088B4FAC-0x088B5380 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B4FA4 and unit_088B5380.
 *
 * func_088B4FAC handles a join request read from the buffer of
 * func_088AFE84 (port, 0x12-byte key, 0x18-byte name, 0xA0-byte data):
 * error 0x8014 / 0x8031 / 0x8012 / 0x8013 / 0x8011, else the peer record
 * is stored at D_09A28BFC and both peers are announced (func_088B6A80 0xF
 * and 0x11); the answer goes back through func_088B5380.
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
    s8 b[0x12];
} B12;

typedef struct {
    s8 b[0xA0];
} BA0;

typedef struct {
    s8 b[0x14];
} Id;

typedef struct {
    B6 unk0;
    u8 unk6;
    u8 unk7;
    B12 unk8;
    u16 unk1A;
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[2];
    BA0 unk20;
    u16 unkC0;
    u8 unkC2;
    u8 unkC3;
    u8 unkC4;
    u8 unkC5;
    u8 unkC6;
    u8 unkC7;
} RecC8;

typedef struct {
    u8 unk0[0x11];
    u8 unk11;
    u8 pad[2];
} Info14;

extern s32 D_09A2886C;
extern u8 D_09A28876;
extern B6 D_09A2887C;
extern u8 D_09A28882;
extern u8 D_09A28883;
extern char D_09A291BC[];
extern u8 D_09A28BED;
extern u8 D_09A28BEE;
extern u16 D_09A28BF0;
extern B6 D_09A28BFC;
extern u8 D_09A28C02;
extern u8 D_09A28C03;
extern B12 D_09A28C04;
extern u16 D_09A28C16;
extern u8 D_09A28C18;
extern u8 D_09A28C19;
extern BA0 D_09A28C1C;
extern u16 D_09A28CBC;
extern u8 D_09A28CBE;
extern u8 D_09A28CBF;
extern u8 D_09A28CC0;
extern u8 D_09A28CC1;
extern u8 D_09A28CC2;
extern u8 D_09A28CC3;
extern B6 D_09A29174;
extern u8 D_09A2917A;
extern u8 D_09A2917B;
extern u8 D_09A2917E;

extern s32 func_0880BFF0(void *, void *, s32);
extern void func_0880C464(void *, s32, s32);
extern void func_088AEF64(RecC8 *);
extern void func_088AEF98(Info14 *);
extern char *func_088AFE84(void);
extern char *func_088B0324(B12 *, char *);
extern void func_088B0370(BA0 *, char *);
extern char *func_088B03CC(u16 *, char *);
extern char *func_088B040C(char *, s32, char *);
extern void func_088B5C30(Id *, RecC8 *, B12 *, BA0 *);
extern void func_088B624C(Id *, u8);
extern s32 func_088B6768(RecC8 *);
extern void func_088B67D0(RecC8 *);
extern u8 func_088B68FC(void);
extern void func_088B6A80(s32);
extern void func_088B7860(RecC8 *);
extern s32 func_088B7C7C(s32, RecC8 *, Info14 *);

void func_088B5380(Id *arg0, RecC8 *arg1, u16 arg2);

/* NonMatching, 97.02 %: (1) the original loads D_09A28882 and D_09A28883
 * before storing either to D_09A2917A / D_09A2917B, ours stores the first
 * before loading the second (as func_088B5568); (2) in the member copies
 * to D_09A28C16... the first load of each pair goes to $v1 in the
 * original, $a0 in ours, and the load of +0x1D is scheduled after the
 * address of D_09A28C1C. Tried: a whole-structure assignment in C++
 * (copies words), member assignments on a RecC8 global, a pointer local
 * on the record (96.49 %). */
void func_088B4FAC(void) {
    u16 port;
    char key[0x16];
    Info14 info;
    RecC8 rec;
    Id b58;
    Id b44;
    Id b30;
    Id b1C;
    char *src;
    u16 err;
    s32 ok;

    src = func_088AFE84();
    err = 0;
    ok = 0;
    func_0880C464(&rec, 0, sizeof(rec));
    func_0880C464(key, 0, sizeof(key));
    func_088AEF64(&rec);
    src = func_088B03CC(&port, src);
    src = func_088B040C(key, 0x12, src);
    src = func_088B0324(&rec.unk8, src);
    func_088B0370(&rec.unk20, src);
    func_088AEF98(&info);
    if (info.unk11 != 0 && func_088B7C7C(0, &rec, &info) != 0) {
        ok = 1;
    }
    if (D_09A28876 == 0) {
        err = 0x8014;
    } else if (D_09A2886C == 5) {
        err = 0x8031;
    } else if (D_09A28BF0 != port) {
        err = 0x8014;
    } else if (func_0880BFF0(key, D_09A291BC, 0x12) != 0) {
        err = 0x8012;
    }
    if (err == 0) {
        if (ok == 0) {
            if (func_088B6768(&rec) == 0) {
                err = 0x8013;
            } else if (D_09A28BED <= D_09A28BEE) {
                err = 0x8011;
            }
        } else if (ok != 0) {
            if (func_088B6768(&rec) == 0) {
                func_088B5380(&b58, &rec, err);
                return;
            }
            if (D_09A28BED <= D_09A28BEE) {
                err = 0x8011;
            }
        }
    }
    if (err == 0) {
        func_088B67D0(&rec);
        func_088B7860(&rec);
        D_09A28BEE = func_088B68FC();
        func_088B5C30(&b44, &rec, &rec.unk8, &rec.unk20);
        func_088B624C(&b30, D_09A28BEE);
        *(B6 *) &D_09A28BFC = *(B6 *) &rec;
        D_09A28C02 = rec.unk6;
        D_09A28C03 = rec.unk7;
        *(B12 *) &D_09A28C04 = *(B12 *) &rec.unk8;
        D_09A28C16 = rec.unk1A;
        D_09A28C18 = rec.unk1C;
        D_09A28C19 = rec.unk1D;
        *(BA0 *) &D_09A28C1C = *(BA0 *) &rec.unk20;
        D_09A28CBC = rec.unkC0;
        D_09A28CBE = rec.unkC2;
        D_09A28CBF = rec.unkC3;
        D_09A28CC0 = rec.unkC4;
        D_09A28CC1 = rec.unkC5;
        D_09A28CC2 = rec.unkC6;
        D_09A28CC3 = rec.unkC7;
        func_088B6A80(0xF);
        *(B6 *) &D_09A29174 = *(B6 *) &D_09A2887C;
        D_09A2917A = D_09A28882;
        D_09A2917B = D_09A28883;
        D_09A2917E = D_09A28BEE;
        func_088B6A80(0x11);
    }
    func_088B5380(&b1C, &rec, err);
}
