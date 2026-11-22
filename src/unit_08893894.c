/* unit_08893894: 0x08893894-0x08893C6C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * The halfword at arg0+0x128 is read through its own pointer, declared
 * before `w`: without it the `lh` and the `lbu` of the store to p+0x18 swap
 * registers (99.92 %).
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    u32 unk0;
    u16 unk4;
    u16 unk6;
    u32 unk8;
    u16 unkC;
    u16 unkE;
    u32 unk10;
    u16 unk14;
    u16 unk16;
} Tex;

typedef struct {
    u8 pad0[4];
    u8 unk4;
    u8 unk5;
    s8 color;
} Item;

extern s32 D_089CBBE0;
extern s32 D_08A62C40;
extern void func_088125A4(s32, u8, Tex *);
extern s32 func_08894988(char *);
extern s32 func_088952E4(char *, u16);
extern char *func_088597FC(s32);
extern s32 func_0885981C(s32, u32);
extern int func_088596C8(s32, char *, s32, s32);
extern int func_0885980C(s32, char *);

void func_08893894(char *arg0, u16 arg1, s32 arg2, Item *arg3) {
    Tex tex;
    u32 c;
    s16 off;
    u32 col;
    u32 colA;
    s32 u;
    u32 hi;
    s32 v;
    s16 *y;
    u8 w;
    s32 list;
    u16 *ch;
    char *p;

    ch = &((u16 *)(arg0 + 0x2628))[arg1];
    if (*ch == 0xFFFF) {
        return;
    }
    if (arg3->color >= 0x30) {
        arg3->color = 0;
    }
    if (arg3->color < 0) {
        c = *(u32 *)(arg0 + 0x164);
    } else {
        c = ((u32 *)(arg0 + 0x168))[arg3->color];
    }
    colA = (c & 0xFF000000) != 0;
    col = (c & 0xFFFFFF) | 0xFF000000;
    u = *(u8 *)(arg0 + 0x118) * (*ch % *(u8 *)(arg0 + 0x11A));
    v = *(u8 *)(arg0 + 0x119) * ((*ch / *(u8 *)(arg0 + 0x11A)) % *(u8 *)(arg0 + 0x11B));
    func_088125A4(D_089CBBE0, *ch / *(u16 *)(arg0 + 0x11C) + 3, &tex);
    if (arg2 == 0 || arg2 == 2) {
        w = arg3->unk4;
    } else {
        w = arg3->unk4 >> 1;
    }
    list = func_08894988(arg0);
    if ((u8)func_088952E4(arg0, arg1) == 1) {
        if (arg3->unk5 < 0x10) {
            off = -2;
        } else if (arg3->unk5 < 0x14) {
            off = -3;
        } else if (arg3->unk5 < 0x1A) {
            off = -4;
        } else if (arg3->unk5 < 0x1E) {
            off = -5;
        } else {
            off = -6;
        }
    } else {
        off = 0;
    }
    p = func_088597FC(D_08A62C40);
    *(s32 *)(p + 0x0) = (v << 16) | u;
    *(s32 *)(p + 0x4) = col;
    y = (s16 *)(arg0 + 0x128);
    *(s32 *)(p + 0x8) = (*(s16 *)(arg0 + 0x126) & 0xFFFF) | ((*y + off) << 16);
    *(s32 *)(p + 0xC) = *(u16 *)(arg0 + 0x12A);
    *(s32 *)(p + 0x10) = ((v + *(u8 *)(arg0 + 0x119)) << 16) | (u + *(u8 *)(arg0 + 0x118));
    *(s32 *)(p + 0x14) = col;
    *(s32 *)(p + 0x18) = ((arg3->unk5 + (*y + off)) << 16) | ((*(s16 *)(arg0 + 0x126) + w) & 0xFFFF);
    *(s32 *)(p + 0x1C) = *(u16 *)(arg0 + 0x12A);
    *(s32 *)(p + 0x20) = (((u32)p & 0xFF000000) >> 8) | 0x10000000;
    *(s32 *)(p + 0x24) = ((u32)p & 0xFFFFFF) | 0x01000000;
    *(s32 *)(p + 0x28) = 0xC2000000;
    *(s32 *)(p + 0x2C) = tex.unkC | 0xC3000000;
    *(s32 *)(p + 0x30) = (tex.unk8 & 0xFFFFFF) | 0xA0000000;
    *(s32 *)(p + 0x34) = ((tex.unk8 & 0xFF000000) >> 8) | 0xA8000000 | tex.unk4;
    hi = (func_0885981C(D_08A62C40, tex.unk6) << 8) | 0xB8000000;
    *(s32 *)(p + 0x38) = hi | func_0885981C(D_08A62C40, tex.unk4);
    *(s32 *)(p + 0x3C) = (colA << 16) | 0xC500FF00 | tex.unk14;
    *(s32 *)(p + 0x40) = (tex.unk10 & 0xFFFFFF) | 0xB0000000;
    *(s32 *)(p + 0x44) = ((tex.unk10 & 0xFF000000) >> 8) | 0xB1000000;
    *(s32 *)(p + 0x48) = 0xC4000004;
    *(s32 *)(p + 0x4C) = 0xCB000000;
    *(s32 *)(p + 0x50) = 0x1E000001;
    *(s32 *)(p + 0x54) = 0x50000001;
    *(s32 *)(p + 0x58) = 0x1280011E;
    *(s32 *)(p + 0x5C) = 0x04060002;
    *(s32 *)(p + 0x60) = 0x10000000;
    *(s32 *)(p + 0x64) = 0x08000000;
    func_088596C8(D_08A62C40, p + 0x20, 0x12, list);
    func_0885980C(D_08A62C40, p + 0x68);
}
