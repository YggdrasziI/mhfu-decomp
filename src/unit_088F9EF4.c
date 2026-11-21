/* unit_088F9EF4: 0x088F9EF4-0x088FA6D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between matched units.
 * Draws a page with a grid of seven rows of five icons (those whose bit is
 * set in the 64-bit mask at arg1 + 0xA0), a cursor, and seven lines made of
 * a name, a caption, an optional text, a three-part bar and a counter
 * compared with two thresholds.
 *
 * .data 0x089B86A4-0x089B86B2 and 0x089B86B4-0x089B86C2: the constants of
 * the two initialised locals (seven widths each), each followed by 2 bytes
 * of padding.
 *
 * Optimized for speed: the divisions by 5 are multiplications.
 *
 * Register allocation: each loop has its own counters (shared ones move the
 * saved registers), `line` is declared first, the colours are `s32` locals and
 * the row offsets, the colour pointer and the first text column are left to
 * the compiler (strength reduction and hoisting).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

extern char *D_089CBBEC;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B04DE0;
extern u16 D_09B0557A;
extern u16 D_09B056D0[];
extern s32 D_089B81F8[];
extern u16 D_089B826C[][5];
extern u8 D_089B82B4[];
extern u16 D_089B82CC[];
extern u32 D_089B839C[];
extern char D_089B84A8[];
extern u16 D_089B8678[];
extern u32 D_089B8688[];
extern char D_089B86C4[];

extern int func_0880E8F0(char *, char *, ...);
extern void func_08825DA8(char *);
extern void func_08827918(char *, s32, s32, char *, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882B624(char *, u16, u16, s32, s32, s32, s32, s32);
extern void func_0882C11C(char *, u16, u16, s32, s32, u8, u8, u8, s32, s32);
extern void func_0882DCB0(char *, s32, s32, s32, s32, s32, s32);
extern void func_0882E2C0(char *, u16, u16, u16, s32, s32, s32, s32);
extern void func_0887D02C(s32, s32, char *, s32);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_088912BC(char *, s16, s16, char *);
extern void func_08891474(char *, s32, s16, char *, ...);
extern void func_088FBC3C(char *, s32, s32, s32, s32);
extern char *func_09A7B790(s32, u16);

void func_088F9EF4(char *arg0, char *arg1, s32 arg2) {
    s32 line;
    s32 band;
    u16 *name;
    s32 lang;
    char *temp;
    s32 *frame;
    s32 cell;
    s32 part;
    s32 y;
    s32 r;
    s32 g;
    s32 b;
    s32 sel;
    s32 icon;
    u64 mask;
    s32 k0;
    s32 k1;
    s32 k2;
    s32 row;
    s32 col;

    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xD;
    func_08890E08(D_08A631A8, 4);
    func_08825DA8(temp);
    frame = &D_089B81F8[arg2];
    func_0882DCB0(D_089CBBEC, 0x10, 0x28, 0xC0, 0xD8, 0xFF, *frame);
    {
        s16 widths[7] = { 0, 0, 0, 0xA, 0, 0x10, 0 };

        lang = *(s32 *)(D_08A631A0 + 0xF7A574);
        func_0882DCB0(D_089CBBEC, (u16) (0xE0 - widths[lang]), 0x28, (u16) (widths[lang] + 0xF0), 0x80, 0xFF, *frame);
    }
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    func_08890E38(D_08A631A8, 5);
    func_08827918(D_089CBBEC, 0x9A, 0x11, func_09A7B790(D_09B22D70, D_09B0557A), 0xE, 0x10);
    for (band = 0; band < 7; band++) {
        r = D_089B82B4[band * 3];
        g = D_089B82B4[band * 3 + 1];
        b = D_089B82B4[band * 3 + 2];
        cell = 0;
        for (k0 = 0; k0 < 4; k0++) {
            func_0882B624(D_089CBBEC, 0x18, k0 * 7 + 0x2F + band * 0x1D, r, g, b, D_089B82CC[k0], 0);
        }
        for (cell++; cell <= 9; cell++) {
            for (k1 = 0; k1 < 4; k1++) {
                func_0882B624(D_089CBBEC, cell * 0x10 + 0x18, k1 * 7 + 0x2F + band * 0x1D, r, g, b, D_089B82CC[k1 + 4], 0);
            }
        }
        for (k2 = 0; k2 < 4; k2++) {
            func_0882B624(D_089CBBEC, cell * 0x10 + 0x18, k2 * 7 + 0x2F + band * 0x1D, r, g, b, D_089B82CC[k2 + 8], 0);
        }
    }
    for (row = 0; row < 7; row++) {
        for (col = 0; col < 5; col++) {
            mask = 1;
            mask <<= (s64) (col + row * 5);
            if (*(u64 *)(arg1 + 0xA0) & mask) {
                func_0882E2C0(D_089CBBEC, D_089B826C[row][col], col * 0x22 + 0x20, row * 0x1D + 0x32, 0x18, 0x18, 1, 0xFF);
            }
        }
    }
    func_0882A9DC(D_089CBBEC, (*(s8 *)(arg0 + 0x10) % 5) * 0x22 + 0x20, (*(s8 *)(arg0 + 0x10) / 5) * 0x1D + 0x31, 0x49);
    func_08890E38(D_08A631A8, 0);
    {
        s16 widths2[7] = { 0, 0, 0, 5, -1, 0xA, 0 };

        for (line = 0, name = D_089B8678, y = 0x34; line < 7; name++, y += 0x10, line++) {
            func_08827918(D_089CBBEC, 0x110 - widths2[lang], y, func_09A7B790(D_09B22D70, D_09B056D0[*name]), 0xE, 0x10);
            func_08891474(D_08A631A8, 0x138, y, D_089B84A8, func_09A7B790(D_09B22D70, D_09B04DE0));
            if (*(s8 *)(arg1 + 0xC4 + line * 0x12) != 0) {
                func_088912BC(D_08A631A8, 0x13E, y, arg1 + 0xC4 + line * 0x12);
            }
            part = 0;
            func_0882C11C(D_089CBBEC, 0x18B, line * 0x10 + 0x33, 0x10, 0xE, 0xFF, 0xFF, 0xFF, 0x66, 0x159);
            for (part++; part <= 2; part++) {
                func_0882C11C(D_089CBBEC, part * 0x10 + 0x18B, line * 0x10 + 0x33, 0x10, 0xE, 0xFF, 0xFF, 0xFF, 0x66, 0x15A);
            }
            func_0882C11C(D_089CBBEC, part * 0x10 + 0x18B, line * 0x10 + 0x33, 0x10, 0xE, 0xFF, 0xFF, 0xFF, 0x66, 0x15B);
            if (*(u32 *)(arg1 + 0xA8 + line * 4) >= D_089B839C[line]) {
                func_08890E38(D_08A631A8, 7);
            } else if (*(u32 *)(arg1 + 0xA8 + line * 4) >= D_089B8688[line]) {
                func_08890E38(D_08A631A8, 0xB);
            }
            func_0880E8F0(arg0 + 0x88, D_089B86C4, *(u32 *)(arg1 + 0xA8 + line * 4));
            func_0887D02C(0x1C4, y, arg0 + 0x88, 0xE);
            func_08890E38(D_08A631A8, 0);
            if (*(u32 *)(arg1 + 0xA8 + line * 4) >= D_089B839C[line]) {
                func_0882A9DC(D_089CBBEC, 0x17A, y, 0x20);
            } else if (*(u32 *)(arg1 + 0xA8 + line * 4) >= D_089B8688[line]) {
                func_0882A9DC(D_089CBBEC, 0x17A, y, 0x1F);
            }
        }
    }
    sel = *(s8 *)(arg0 + 0x10);
    icon = -1;
    if (*(u64 *)(arg1 + 0xA0) & ((u64) 1 << sel)) {
        icon = D_089B826C[sel / 5][sel % 5];
    }
    func_088FBC3C(arg0, 0xE0, 0xB0, icon, arg2);
}
