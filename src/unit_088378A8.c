/* unit_088378A8: 0x088378A8-0x08837CA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

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
} Layout;

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
    s32 w10;   /* 0x10 */
} Box;

extern char *D_08A631A0;
extern char *D_08A631A8;
extern char *D_089CC438;
extern char *D_09A0B544;
extern s32 D_09A4F0C4;
extern s32 D_09B22D70;
extern u16 D_09B05C90;
extern u16 D_09B05C92;
extern const u16 D_0893B248;
extern const u16 D_0893B24A;
extern const u16 D_0893B24C;
extern const u16 D_0893B24E;
extern const u8 D_0893B250;
extern const u8 D_0893B251;
extern const u8 D_0893B252;
extern const u8 D_0893B253;
extern const u16 D_0893B254;
extern const u16 D_0893B256;
extern const u16 D_0893B258;
extern const u16 D_0893B25A;
extern const u32 D_0893B25C;
extern const u32 D_0893B260;
extern const u16 D_0893B264;
extern const u16 D_0893B266;
extern const u16 D_0893B268;
extern const u16 D_0893B26A;
extern const u16 D_0893B26C;
extern const u16 D_0893B26E;

extern void func_08890E08(char *, s8);
extern void func_08825DA8(char *);
extern char *func_09A7B790(s32, u16);
extern void func_0882FC50(char *, Box *, char *, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882F580(char *, Layout *, char *, s32, s32, s32);
extern char *func_088DCEBC(s32, u8);
extern s32 func_0883B498(char *, u16);
extern void func_0883B53C(char *, s16, s16, s32, s32);
extern u8 *func_0889C518(char *);
extern s32 func_0880BFF0(void *, void *, s32);

void func_088378A8(char *arg0, u32 arg1) {
    char *p;
    s32 n;
    s32 i;
    s32 c;

    if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
        return;
    }
    switch (arg1) {
    case 0:
        *(u8 *)(arg0 + 0x534) = 9;
        break;
    case 1:
        *(u8 *)(arg0 + 0x534) = 10;
        break;
    case 2:
        *(u8 *)(arg0 + 0x534) = 11;
        break;
    case 3:
        *(u8 *)(arg0 + 0x534) = 12;
        break;
    case 4:
        *(u8 *)(arg0 + 0x534) = 13;
        break;
    case 5:
        *(u8 *)(arg0 + 0x534) = 14;
        break;
    }
    func_08890E08(D_08A631A8, arg1);
    func_08825DA8(arg0);
    {
        Box box = { 0x170, 0, 0x68, 0x20, 0xE, 0xE, 0, 1, 0x190, 0xA, 0x10 };
        Layout lay;
        if (*(s32 *)(arg0 + 0x528) & 0x2000) {
            func_0882FC50(arg0, &box, func_09A7B790(D_09B22D70, D_09B05C90), 0xFF);
            func_0882A9DC(arg0, box.hC - 0x18, box.hE - 2, 0x36);
            return;
        }
        func_0882FC50(arg0, &box, func_09A7B790(D_09B22D70, D_09B05C92), 0xFF);
        func_0882A9DC(arg0, box.hC - 0x18, box.hE - 2, 0x36);
        lay.x = D_0893B248;
        lay.y = D_0893B24A;
        lay.w = D_0893B24C;
        lay.h = D_0893B24E;
        lay.b8 = D_0893B250;
        lay.b9 = D_0893B251;
        lay.bA = D_0893B252;
        lay.bB = D_0893B253;
        lay.hC = D_0893B254;
        lay.hE = D_0893B256;
        lay.h10 = D_0893B258;
        lay.h12 = D_0893B25A;
        lay.w14 = D_0893B25C;
        lay.w18 = D_0893B260;
        lay.h1C = D_0893B264;
        lay.h1E = D_0893B266;
        lay.h20 = D_0893B268;
        lay.h22 = D_0893B26A;
        lay.tx = D_0893B26C;
        lay.ty = D_0893B26E;
        c = *(s8 *)(D_09A0B544 + 0xEE3);
        lay.h12 = c;
        lay.h = lay.h - ((4 - c) << 4);
        func_0882F580(arg0, &lay, 0, -1, 0xFF, 0);
        p = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
        if (func_0883B498(arg0, *(u16 *)(p + 0x1E6)) != -1) {
            func_0883B53C(arg0, (s16)lay.hC, (s16)lay.hE, func_0883B498(arg0, *(u16 *)(p + 0x1E6)), 0);
        }
        n = 1;
        for (i = 0; i < *(s8 *)(D_09A0B544 + 0xEE3); i++) {
            p = D_09A0B544;
            if (func_0880BFF0(func_0889C518(p), p + (u8)i * 0xC8 + 0x57C, 6) != 0) {
                func_0883B53C(arg0, (s16)lay.hC, lay.hE + lay.h10 * n, i, 0);
                n++;
            }
        }
    }
}
