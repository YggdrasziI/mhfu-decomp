/* unit_08831CB0: 0x08831CB0-0x08831F3C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08831CB0: two gradient quads in a display list. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern s32 D_08A62C40;
extern int func_088596C8(s32, char *, s32, s32);
extern char *func_088597FC(s32);
extern int func_0885980C(s32, char *);

void func_08831CB0(char *arg0, u16 arg1, u16 y, u16 arg3, u16 h, u8 r, u8 g, u8 b, u8 a) {
    char *p;
    u32 col;
    u32 col2;
    u32 y0;
    u32 y1;
    u32 mid0;
    u32 mid1;
    u16 mid;
    u16 x2;
    s32 x;
    s32 w;

    w = arg3;
    x = arg1;
    p = func_088597FC(D_08A62C40);
    col = r | (g << 8) | (b << 16);
    y0 = y << 16;
    y1 = (y + h) << 16;
    *(u32 *)(p + 0x0) = col;
    *(u32 *)(p + 0x4) = y0 | (u16)x;
    *(u32 *)(p + 0x8) = 0;
    *(u32 *)(p + 0xC) = col;
    *(u32 *)(p + 0x10) = (u16)x | y1;
    mid = (s16)(x + ((s32)w >> 1));
    col2 = (a << 24) | col;
    mid0 = y0 | mid;
    mid1 = mid | y1;
    *(u32 *)(p + 0x14) = 0;
    *(u32 *)(p + 0x18) = col2;
    *(u32 *)(p + 0x1C) = mid0;
    *(u32 *)(p + 0x20) = 0;
    *(u32 *)(p + 0x24) = col2;
    *(u32 *)(p + 0x28) = mid1;
    *(u32 *)(p + 0x2C) = 0;
    *(u32 *)(p + 0x30) = (((u32)p & 0xFF000000) >> 8) | 0x10000000;
    *(u32 *)(p + 0x34) = (((u32)p << 8) >> 8) | 0x01000000;
    *(u32 *)(p + 0x38) = 0x1E000000;
    *(u32 *)(p + 0x3C) = 0x50000001;
    *(u32 *)(p + 0x40) = 0x1280011C;
    *(u32 *)(p + 0x44) = 0x04040004;
    *(u32 *)(p + 0x48) = 0x10000000;
    *(u32 *)(p + 0x4C) = 0x08000000;
    func_088596C8(D_08A62C40, p + 0x30, 8, *(u8 *)(arg0 + 0x534));
    func_0885980C(D_08A62C40, p + 0x50);

    p = func_088597FC(D_08A62C40);
    x2 = x + w;
    *(u32 *)(p + 0x0) = col2;
    *(u32 *)(p + 0x4) = mid0;
    *(u32 *)(p + 0x8) = 0;
    *(u32 *)(p + 0xC) = col2;
    *(u32 *)(p + 0x10) = mid1;
    *(u32 *)(p + 0x14) = 0;
    *(u32 *)(p + 0x18) = col;
    *(u32 *)(p + 0x1C) = y0 | x2;
    *(u32 *)(p + 0x20) = 0;
    *(u32 *)(p + 0x24) = col;
    *(u32 *)(p + 0x28) = y1 | x2;
    *(u32 *)(p + 0x2C) = 0;
    *(u32 *)(p + 0x30) = (((u32)p & 0xFF000000) >> 8) | 0x10000000;
    *(u32 *)(p + 0x34) = (((u32)p << 8) >> 8) | 0x01000000;
    *(u32 *)(p + 0x38) = 0x1E000000;
    *(u32 *)(p + 0x3C) = 0x50000001;
    *(u32 *)(p + 0x40) = 0x1280011C;
    *(u32 *)(p + 0x44) = 0x04040004;
    *(u32 *)(p + 0x48) = 0x10000000;
    *(u32 *)(p + 0x4C) = 0x08000000;
    func_088596C8(D_08A62C40, p + 0x30, 8, *(u8 *)(arg0 + 0x534));
    func_0885980C(D_08A62C40, p + 0x50);
}
