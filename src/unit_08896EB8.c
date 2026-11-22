/* unit_08896EB8: 0x08896EB8-0x088971A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;     /* 0x00 */
    u16 y;     /* 0x02 */
    u16 w;     /* 0x04 */
    u16 h;     /* 0x06 */
    u8 b8;     /* 0x08 */
    u8 b9;     /* 0x09 */
    u8 bA;     /* 0x0A */
    u8 bB;     /* 0x0B */
    u16 hC;    /* 0x0C */
    u16 hE;    /* 0x0E */
    u16 h10;   /* 0x10 */
    u16 h12;   /* 0x12 */
    u32 w14;   /* 0x14 */
    u32 w18;   /* 0x18 */
    u16 h1C;   /* 0x1C */
    u16 h1E;   /* 0x1E */
    u16 h20;   /* 0x20 */
    u16 h22;   /* 0x22 */
    u16 tx;    /* 0x24 */
    u16 ty;    /* 0x26 */
} Layout08896EB8;

extern const u16 D_089B1694;
extern const u16 D_089B1696;
extern const u16 D_089B1698;
extern const u16 D_089B169A;
extern const u8 D_089B169C;
extern const u8 D_089B169D;
extern const u8 D_089B169E;
extern const u8 D_089B169F;
extern const u16 D_089B16A0;
extern const u16 D_089B16A2;
extern const u16 D_089B16A4;
extern const u16 D_089B16A6;
extern const u32 D_089B16A8;
extern const u32 D_089B16AC;
extern const u16 D_089B16B0;
extern const u16 D_089B16B2;
extern const u16 D_089B16B4;
extern const u16 D_089B16B6;
extern const u16 D_089B16B8;
extern const u16 D_089B16BA;
extern char D_089B16BC[];
extern char D_089B167C[];
extern char *D_08A631A8;
extern char *D_089CC438;
extern u16 D_089AD0BA;

extern void func_0882F580(char *, Layout08896EB8 *, char *, s32, s32, s32);
extern s32 func_08890E48(char *, char *);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);
extern void func_0882D6F0(char *, u16, u16, u16, u16, s32, s32, s32);
extern void func_08832F20(char *, s16, s16, s32, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_08890DFC(char *, s16, s16);
extern char *func_0885151C(char *, u16);
extern void func_08892004(char *, char *, ...);

void func_08896EB8(char *arg0, Layout08896EB8 *lay, char *str, s32 arg3,
                   s32 arg4, s32 arg5) {
    Layout08896EB8 local;

    if (lay == 0) {
        lay = &local;
    }
    lay->x = D_089B1694;
    lay->y = D_089B1696;
    lay->w = D_089B1698;
    lay->h = D_089B169A;
    lay->b8 = D_089B169C;
    lay->b9 = D_089B169D;
    lay->bA = D_089B169E;
    lay->bB = D_089B169F;
    lay->hC = D_089B16A0;
    lay->hE = D_089B16A2;
    lay->h10 = D_089B16A4;
    lay->h12 = D_089B16A6;
    lay->w14 = D_089B16A8;
    lay->w18 = D_089B16AC;
    lay->h1C = D_089B16B0;
    lay->h1E = D_089B16B2;
    lay->h20 = D_089B16B4;
    lay->h22 = D_089B16B6;
    lay->tx = D_089B16B8;
    lay->ty = D_089B16BA;
    func_0882F580(arg0, lay, D_089B16BC, -1, 0xFF, 0);
    lay->tx = lay->x + ((lay->w - func_08890E48(D_08A631A8, str) * 7) >> 1);
    func_088915B0(D_08A631A8, lay->tx, lay->ty - 8, 5, D_089B167C, str);
    func_0882D6F0(arg0, lay->x + 8, lay->hE + lay->b9 + lay->h10 * 7, lay->w - 16,
                  1, 0x80, 0x80, 0x80);
    func_08832F20(arg0, lay->x + (lay->w >> 1), lay->hE + lay->h10 * 8 + 2, arg3,
                  arg4, 0);
    if (arg5 == 0) {
        func_0882A9DC(arg0, lay->hC + 0x108, lay->hE + lay->h10 * 8, 0x32);
        func_08890DFC(D_08A631A8, lay->hC + 0x118, lay->hE + lay->h10 * 8 + 2);
        func_08892004(D_08A631A8, func_0885151C(D_089CC438, D_089AD0BA));
    }
}
