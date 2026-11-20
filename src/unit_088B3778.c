/* unit_088B3778: 0x088B3778-0x088B3A3C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_088B3744) and unit_088B3A3C. Its jump table (0x0893216C-0x08932188)
 * is linked from this unit.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s8 b[6];
} B6;

typedef struct {
    s8 b[8];
} B8;

typedef struct {
    s8 b[0x12];
} B12;

typedef struct {
    s8 b[0xA0];
} BA0;

typedef struct {
    s16 h[0xB];
} H0B;

typedef struct {
    s16 h[0x23];
} H23;

typedef struct {
    u8 pad0[0x50];
    s32 unk50;
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
    u16 unk58;
    u8 unk5A;
    u8 unk5B;
    u8 unk5C[8];
} Rec64;

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
    u8 padC4[4];
} RecC8;

typedef struct {
    u8 pad[0x14];
} Res14;

extern u32 D_09A2886C;
extern s32 D_09A28870;
extern u8 D_09A28876;
extern u8 D_09A28877;
extern B6 D_09A2887C;
extern u8 D_09A28882;
extern u8 D_09A28883;
extern B12 D_09A28884;
extern u16 D_09A28896;
extern u8 D_09A28898;
extern u8 D_09A28899;
extern BA0 D_09A2889C;
extern u16 D_09A2893C;
extern u8 D_09A2893E;
extern u8 D_09A2893F;
extern Rec64 D_09A28B98;
extern H0B D_09A291BC;
extern char D_09A29364;

extern void func_088B6A08(s32, s32, s32);
extern void func_088B7A50(s32);
extern void memset(void *, s32, s32);
extern void memcpy(void *, void *, s32);
extern u16 func_088B650C(void);
extern void func_088B67D0(RecC8 *);
extern void func_088B4B94(Res14 *);
extern void func_088B7860(RecC8 *);

s32 func_088B3778(char *arg0, s32 arg1, s32 arg2) {
    RecC8 rec;
    Res14 res;
    Rec64 *g = &D_09A28B98;

    switch (D_09A2886C) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        func_088B6A08(0x8013, arg1, arg2);
        return 0;
    case 0:
        break;
    }
    func_088B7A50(2);
    D_09A28876 = 1;
    memset(&D_09A29364, 0, 0x320);
    D_09A28870 = 0;
    D_09A28877 = 0;
    memset(&D_09A28B98, 0, 0x64);
    *(B8 *) g = *(B8 *) &D_09A2887C;
    g->unk58 = func_088B650C();
    D_09A291BC = *(H0B *) arg0;
    if (arg0[0] != 0) {
        g->unk54 = 1;
    }
    *(H23 *) ((char *) g + 8) = *(H23 *) (arg0 + 0x18);
    g->unk55 = *(u8 *) (arg0 + 0x64);
    g->unk50 = *(s32 *) (arg0 + 0x60);
    g->unk56 = 1;
    memcpy(g->unk5C, arg0 + 0x68, 8);
    memset(&rec, 0, 0xC8);
    rec.unk0 = *(B6 *) &D_09A2887C;
    rec.unk6 = D_09A28882;
    rec.unk7 = D_09A28883;
    rec.unk8 = D_09A28884;
    rec.unk1A = D_09A28896;
    rec.unk1C = D_09A28898;
    rec.unk1D = D_09A28899;
    rec.unk20 = D_09A2889C;
    rec.unkC0 = D_09A2893C;
    rec.unkC2 = D_09A2893E;
    rec.unkC3 = D_09A2893F;
    func_088B67D0(&rec);
    func_088B4B94(&res);
    func_088B7860((RecC8 *) &D_09A2887C);
    func_088B6A08(0, arg1, arg2);
    return 0;
}
