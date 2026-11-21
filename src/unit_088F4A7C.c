/* unit_088F4A7C: 0x088F4A7C-0x088F56B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws one page of eight lines of a list (number, kind, name, a value shown
 * with two decimals, three numbers), its five column captions, the page
 * number and the button captions shifted by per-language offsets.
 *
 * .data 0x089B8444-0x089B849C: the constants of the two initialised locals
 * (seven offsets and 2 bytes of padding, then seven rows of five offsets and
 * 2 bytes of padding).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CBBEC;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_089B841C;
extern u16 D_089B841E;
extern u16 D_089B8428;
extern u16 D_089B842A;
extern u16 D_089B842C;
extern s32 D_089B8434;
extern u16 D_089B8438;
extern u16 D_089B843A;
extern u16 D_089B843C;
extern u16 D_089B843E;
extern char D_089B849C;
extern char D_089B84A4;
extern char D_089B84A8;
extern char D_089B84AC;
extern char D_089B84B8;
extern char D_089B84C8;
extern u16 D_09B0558A;
extern u16 D_09B0558C;
extern u16 D_09B0558E;
extern u16 D_09B05590;
extern u16 D_09B05598;
extern u16 D_09B0559A;
extern u16 D_09B0559C;
extern u16 D_09B055CA;
extern u16 D_09B055CC;
extern u16 D_09B055D4;
extern u16 D_09B055D6;
extern u16 D_09B055D8;
extern u16 D_09B055F8[];

extern void func_08825DA8(char *);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882D6F0(char *, u16, u16, u16, u16, s32, s32, s32);
extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_0882DCA8(char *, s32, s32, s32, s32, s32);
extern void func_0882E6F0(char *, u16, u16, s32, s32);
extern void func_0882F4A4(char *, u16, u16, u16, u16, s32);
extern void func_0882F580(char *, u16 *, char *, s32, s32, s32);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
extern void func_08890E38(char *, s32);
extern s32 func_08890E48(char *, char *);
extern void func_088912BC(char *, s16, s16, char *);
extern void func_08891474(char *, s16, s16, char *, ...);
extern char *func_09A7B790(s32, u16);

typedef struct {
    char pad0[0xA730];
    char *names[0x60];
    char *items[0x60];
    u32 values[0x60];
} Menu;

#define M ((Menu *) arg0)
#define ITEMS ((char **) (arg0 + 0xA8B0))
#define NAMES ((char **) (arg0 + 0xA730))

void func_088F4A7C(char *arg0) {
    s8 colors[5];
    char *temp;
    s32 idx;
    char *name;
    char *item;
    s32 j;
    u16 x;
    s32 w;
    s8 mode;

    colors[0] = colors[1] = colors[2] = colors[3] = colors[4] = 5;
    if (*(s8 *)(arg0 + 0x16)) {
        colors[*(s8 *)(arg0 + 0x16)] = 4;
    }
    mode = *(s8 *)(arg0 + 0xD);
    if (mode == 7) {
        if (*(s8 *)(arg0 + 0x14) == *(s8 *)(arg0 + 0x13)) {
            func_0882F4A4(D_089CBBEC, D_089B8438, (*(s8 *)(arg0 + 0x12) << 4) + 0x3B, D_089B843C, 0x10, 0x400000);
        }
        D_089B843A = 0x39;
        D_089B843E = 4;
    } else {
        D_089B843A = 0x3B;
        D_089B843E = 0x10;
        if (mode == 5) {
            D_089B8434 = 0x80808080;
        } else {
            D_089B8434 = 0x8000C040;
        }
    }
    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xD;
    func_08890E08(D_08A631A8, 4);
    func_08825DA8(temp);
    func_0882F580(D_089CBBEC, &D_089B841C, func_09A7B790(D_09B22D70, D_09B0558A), *(s8 *)(arg0 + 0x11), 0xFF, 3);
    func_08891474(D_08A631A8, D_089B841C + 0x119, D_089B841E + 8, &D_089B849C, *(s8 *)(arg0 + 0x14) + 1, 0xC);
    func_08890E38(D_08A631A8, colors[0]);
    func_08891474(D_08A631A8, D_089B841C + 0xC, D_089B841E + 0x18, func_09A7B790(D_09B22D70, D_09B0558C));
    func_08890E38(D_08A631A8, colors[1]);
    func_08891474(D_08A631A8, D_089B841C + 0x4A, D_089B841E + 0x18, func_09A7B790(D_09B22D70, D_09B055CA));
    func_08890E38(D_08A631A8, colors[2]);
    func_08891474(D_08A631A8, D_089B841C + 0xB4, D_089B841E + 0x18, func_09A7B790(D_09B22D70, D_09B0558E));
    func_08890E38(D_08A631A8, colors[3]);
    func_08891474(D_08A631A8, D_089B841C + 0xF3, D_089B841E + 0x18, func_09A7B790(D_09B22D70, D_09B05590));
    func_08890E38(D_08A631A8, colors[4]);
    func_08891474(D_08A631A8, D_089B841C + 0x15C, D_089B841E + 0x18, func_09A7B790(D_09B22D70, D_09B055CC));
    func_0882D6F0(D_089CBBEC, D_089B841C + 7, D_089B841E + 0x27, 0x1AE, 1, 0x80, 0x80, 0x80);
    func_0882D6F0(D_089CBBEC, D_089B841C + 7, D_089B841E + 0xAE, 0x1AE, 1, 0x80, 0x80, 0x80);
    func_0882E6F0(D_089CBBEC, D_089B841C, D_089B841E + 8, 0x1AC, 0xF0);
    if (*(s8 *)(arg0 + 0xD) == 5) {
        func_0882E6F0(D_089CBBEC, D_089B8428 + 0x1C, D_089B842A + D_089B842C * *(s8 *)(arg0 + 0x11), 0x62, 0xF0);
    }
    idx = *(s8 *)(arg0 + 0x14) * 8;
    name = NAMES[idx];
    item = ITEMS[idx];
    func_08890E38(D_08A631A8, 0);
    for (j = 0; j < 8; j++) {
        if (name != 0) {
            func_08891474(D_08A631A8, D_089B8428, D_089B842A + D_089B842C * j, &D_089B84A4, idx + 1);
            if (*(s8 *)(item + 0x26) & 0x7F) {
                if (*(s8 *)(item + 0x26) != 0x18) {
                    w = func_08890E48(D_08A631A8, func_09A7B790(D_09B22D70, D_09B055F8[*(s8 *)(item + 0x26) - 1]));
                    x = D_089B8428 + 0x54 - ((w * 14) >> 2);
                    func_08891474(D_08A631A8, x, D_089B842A + D_089B842C * j, &D_089B84A8, func_09A7B790(D_09B22D70, D_09B055F8[*(s8 *)(item + 0x26) - 1]));
                } else {
                    func_0882A9DC(D_089CBBEC, D_089B8428 + 0x4E, D_089B842A + D_089B842C * j, 0x1D3);
                }
            }
            func_08890DE8(D_08A631A8, 0x10, 0xE);
            func_088912BC(D_08A631A8, D_089B8428 + 0x9A, D_089B842A + D_089B842C * j, name);
            func_08890DE8(D_08A631A8, 0xE, 0xE);
            func_08891474(D_08A631A8, D_089B8428 + 0xFC, D_089B842A + D_089B842C * j, &D_089B84AC, M->values[idx] / 100, M->values[idx] % 100);
            if (*(s32 *) item != 0) {
                func_08891474(D_08A631A8, D_089B8428 + 0x150, D_089B842A + D_089B842C * j, &D_089B84B8, *(u8 *) item, *(u8 *)(item + 1), *(u16 *)(item + 2));
            } else {
                func_08891474(D_08A631A8, D_089B8428 + 0x150, D_089B842A + D_089B842C * j, &D_089B84C8);
            }
        }
        idx++;
        name = M->names[idx];
        item = M->items[idx];
    }
    {
        s16 widths[7] = { 0, 0xC, 0xC, 8, 8, 4, 0 };
        s32 lang = *(s32 *)(D_08A631A0 + 0xF7A574);
        s16 offs[7][5] = {
            { 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0 },
            { 0, -0x18, -0xE, -0xA, 3 },
            { 0, 0, 0, 0, 0 },
            { 0, -8, 2, 0xD, 0x15 },
            { 0, -0x10, -8, -7, 0 },
            { 0, 0, 0, 0, 0 },
        };
        s32 off;

        func_08891474(D_08A631A8, widths[lang] + 0x150, 0xE2, func_09A7B790(D_09B22D70, D_09B055D8));
        off = offs[lang][0];
        func_0882A9DC(D_089CBBEC, D_089B841C + 0x7C + off, D_089B841E + 0xAF, 0x34);
        func_08891474(D_08A631A8, D_089B841C + 0x8C + off, D_089B841E + 0xB1, func_09A7B790(D_09B22D70, D_09B055CA));
        off = offs[lang][1];
        func_0882A9DC(D_089CBBEC, D_089B841C + 0xC0 + off, D_089B841E + 0xAF, 0x32);
        func_08891474(D_08A631A8, D_089B841C + 0xD0 + off, D_089B841E + 0xB1, func_09A7B790(D_09B22D70, D_09B0559A));
        off = offs[lang][2];
        func_0882A9DC(D_089CBBEC, D_089B841C + 0xF8 + off, D_089B841E + 0xAF, 0x33);
        func_08891474(D_08A631A8, D_089B841C + 0x108 + off, D_089B841E + 0xB1, func_09A7B790(D_09B22D70, D_09B05598));
        off = offs[lang][3];
        func_0882A9DC(D_089CBBEC, D_089B841C + 0x132 + off, D_089B841E + 0xAF, 0x3A);
        func_08891474(D_08A631A8, D_089B841C + 0x148 + off, D_089B841E + 0xB1, func_09A7B790(D_09B22D70, D_09B0559C));
        off = offs[lang][4];
        func_0882A9DC(D_089CBBEC, D_089B841C + 0x16A + off, D_089B841E + 0xAF, 0x39);
        func_08891474(D_08A631A8, D_089B841C + 0x180 + off, D_089B841E + 0xB1, func_09A7B790(D_09B22D70, D_09B055D4));
    }
    func_0882DCA8(D_089CBBEC, 0x130, 0xD8, 0x70, 0x20, 0xFF);
    func_0882A9DC(D_089CBBEC, 0x138, 0xE0, 0x36);
    func_0882A9DC(D_089CBBEC, 0x188, 0xE0, 0x37);
    if (*(s8 *)(arg0 + 0x16) == 0) {
        func_0882A9DC(D_089CBBEC, D_089B841C + 0xC, D_089B841E + 0xAF, 0x35);
        func_08891474(D_08A631A8, D_089B841C + 0x1C, D_089B841E + 0xB1, func_09A7B790(D_09B22D70, D_09B055D6));
    }
    item = ITEMS[*(s8 *)(arg0 + 0x11) + *(s8 *)(arg0 + 0x14) * 8];
    if (item != 0) {
        if (*(u16 *)(item + 4) != 0) {
            func_0882DCA0(D_089CBBEC, 0x10, 0xD8, 0xEE, 0x20, 0xFF);
            func_088912BC(D_08A631A8, 0x18, 0xE2, item + 4);
        }
    }
}
