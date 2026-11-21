/* unit_088FA6D8: 0x088FA6D8-0x088FAB0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws a grid of three rows of eight cells: the cells whose bit is set in
 * the 64-bit mask at +0x148 of arg1 show an icon (two pages of 24), then the
 * cursor, the detail of the selected cell and the page number.
 *
 * #pragma optimize_for_size off: the loops step their coordinates and the
 * table offset instead of multiplying (notes/COMPILER.md, "Speed and space").
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef long long s64;
typedef unsigned long long u64;

extern char *D_089CBBEC;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B0557E;
extern u16 D_09B05582;
extern s32 D_089B81F8[];
extern s16 D_089B82E4[][8];
extern u8 D_089B8344[];
extern u8 D_089B8345[];
extern u8 D_089B8346[];
extern char D_089B8588[];

extern void func_08825DA8(char *);
extern void func_08827918(char *, s32, s32, char *, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882B94C(char *, u16, u16, u8, u8, u8, s32, s32);
extern void func_0882DCB0(char *, s32, s32, s32, s32, s32, s32);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_08891474(char *, s32, s16, char *, ...);
extern void func_088FBE4C(char *, s32, s32, s32, s32);
extern char *func_09A7B790(s32, u16);

void func_088FA6D8(char *arg0, char *arg1, s32 arg2) {
    char *temp;
    s32 *frame;
    u8 r;
    u8 g;
    u8 b;
    u64 mask;
    s32 row;
    s32 col;
    s32 found;
    s32 index;

    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xD;
    func_08890E08(D_08A631A8, 4);
    func_08825DA8(temp);
    frame = &D_089B81F8[arg2];
    func_0882DCB0(D_089CBBEC, 0x10, 0x28, 0x1C0, 0x80, 0xFF, *frame);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    func_08890E38(D_08A631A8, 5);
    func_08827918(D_089CBBEC, 0x9A, 0x11, func_09A7B790(D_09B22D70, D_09B0557E), 0xE, 0x10);
    r = D_089B8344[arg2 * 3];
    g = D_089B8345[arg2 * 3];
    b = D_089B8346[arg2 * 3];
    mask = 1;
    if (*(s8 *)(arg0 + 0xF) != 0) {
        mask <<= 24;
    }
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 8; col++, mask <<= 1) {
            func_0882B94C(D_089CBBEC, col * 0x34 + 0x2A, row * 0x24 + 0x34, r, g, b, 0xFF, 0x102);
            if (*(u64 *)(arg1 + 0x148) & mask) {
                func_0882A9DC(D_089CBBEC, col * 0x34 + 0x2E, row * 0x24 + 0x38, D_089B82E4[row + *(s8 *)(arg0 + 0xF) * 3][col]);
            }
        }
    }
    func_0882A9DC(D_089CBBEC, (*(s8 *)(arg0 + 0x10) % 8) * 0x34 + 0x2E, (*(s8 *)(arg0 + 0x10) / 8) * 0x24 + 0x38, 0x49);
    found = -1;
    index = *(s8 *)(arg0 + 0x10) + *(s8 *)(arg0 + 0xF) * 0x18;
    if (*(u64 *)(arg1 + 0x148) & ((u64) 1 << (s64) index)) {
        found = index;
    }
    func_088FBE4C(arg0, 0xE0, 0xB0, found, arg2);
    func_08890E38(D_08A631A8, 0);
    func_0882DCB0(D_089CBBEC, 0x4C, 0xB0, 0x90, 0x18, 0xFF, *frame);
    func_0882A9DC(D_089CBBEC, 0x5A, 0xB4, 0x35);
    func_08891474(D_08A631A8, 0x6E, 0xB6, func_09A7B790(D_09B22D70, D_09B05582));
    func_08890E38(D_08A631A8, 5);
    func_08891474(D_08A631A8, 0xBC, 0xB6, D_089B8588, *(s8 *)(arg0 + 0xF) + 1, 2);
}
