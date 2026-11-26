/* unit_08820FB4: 0x08820FB4-0x08821080 (ULES01213) */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef union {
    u32 w;
    u8 c[4];
} Rgb;

extern char *D_08A62C54;

extern s32 func_0885C83C(char *, u8, u16);
extern u32 func_08830354(char *, u8, s32, s32);
extern s32 func_0883029C(char *, u8 *, s32);
extern void func_0882B624(char *, u16, u16, u8, u8, u8, s32, s32);

void func_08820FB4(char *p, u8 *item, s32 x, s32 y, s32 flags) {
    Rgb c;
    u8 r;

    r = func_0885C83C(D_08A62C54, item[1], *(u16 *)(item + 2));
    if (!((u8)flags & 8)) {
        c.w = func_08830354(p, r, 0xFF, 0);
    } else {
        c.w = 0xFF808080;
    }
    func_0882B624(p, x, y, c.c[2], c.c[1], c.c[0], func_0883029C(p, item, 0), 0);
}
