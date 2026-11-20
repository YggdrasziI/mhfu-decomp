/* unit_088B7350: 0x088B7350-0x088B7580 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088B7350 asm piece, 1 function
 * between unit_088B72CC and unit_088B7580.
 *
 * Handles the address arg0 of a peer that joined or left: records it in
 * D_09A28AD0, then either announces it (event 0xD) or, for a known peer,
 * drops it while hosting (as func_088B70E8: events 0x11 and 3) and records
 * it in D_09A28BFC (event 0x10); event 6 in every case.
 *
 * NonMatching: the image keeps the original code.
 */

typedef signed char s8;
typedef unsigned char u8;
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

extern s32 D_09A2886C;
extern u8 D_09A28876;
extern char D_09A28AD0[];
extern B6 D_09A28B98;
extern u8 D_09A28B9E;
extern u8 D_09A28B9F;
extern u8 D_09A28BEE;
extern char D_09A28BFC[];
extern B6 D_09A29174;
extern u8 D_09A2917A;
extern u8 D_09A2917B;
extern u8 D_09A2917E;
extern u8 D_09A299A8;
extern char D_09A29CD0[];

extern void memset(void *, s32, s32);
extern void func_088B21D0(Id *, u8);
extern u8 func_088B32B8(void);
extern s32 func_088B6594(void *);
extern void func_088B624C(Id *, u8);
extern s32 func_088B66D0(void *);
extern s32 func_088B6768(void *);
extern s32 func_088B6864(void *);
extern u8 func_088B68FC(void);
extern void func_088B6A80(s32);
extern s32 func_088B7A10(Addr8 *);
extern void func_088B7A50(s32);
extern void func_088B7978(Addr8 *);

/* NonMatching, 96.93 %: the original loads D_09A28B9E and D_09A28B9F before
 * storing either to D_09A2917A / D_09A2917B, ours stores the first before
 * loading the second (as func_088B70E8, func_088B5568, func_088B4FAC).
 * Tried there: temporaries, one-byte structures, a two-byte sub-structure
 * (C and C++), an 8-byte structure copy, enum types. */
void func_088B7350(Addr8 *arg0) {
    Id b2C;
    Id b18;

    memset(D_09A28AD0, 0, 0xC8);
    *(Addr8 *) D_09A28AD0 = *arg0;
    if (func_088B6594(arg0) == 0) {
        if (func_088B7A10(arg0) == 0 && D_09A2886C == 2) {
            func_088B7A50(4);
            func_088B6A80(0xE);
        }
        if (func_088B66D0(arg0) != 0) {
            *(Addr8 *) D_09A29CD0 = *arg0;
            func_088B6A80(0xD);
        }
    } else if (func_088B6768(arg0) == 0) {
        if (D_09A28876 != 0) {
            func_088B6864(arg0);
            func_088B7978(arg0);
            D_09A28BEE = func_088B68FC();
            func_088B624C(&b2C, D_09A28BEE);
            *(B6 *) &D_09A29174 = *(B6 *) &D_09A28B98;
            D_09A2917A = D_09A28B9E;
            D_09A2917B = D_09A28B9F;
            D_09A2917E = D_09A28BEE;
            func_088B6A80(0x11);
            D_09A299A8 = func_088B32B8();
            func_088B21D0(&b18, D_09A299A8);
            func_088B6A80(3);
        }
        memset(D_09A28BFC, 0, 0xC8);
        *(Addr8 *) D_09A28BFC = *arg0;
        func_088B6A80(0x10);
    }
    func_088B6A80(6);
}
