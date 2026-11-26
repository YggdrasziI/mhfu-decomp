/* unit_0884AE14: 0x0884AE14-0x0884AF84 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);
extern s32 D_0893B1FC[];

void func_0884AE14(char *a0, s16 a1)
{
    s16 i;
    s16 x;

    s16 y;
    s32 k;
    s16 d;
    s16 off;
    s32 c;

    i = 0;
    x = 0;
    k = 0;
    while (1) {
        d = a1 - k;
        if (d < 0) d = 0;
        y = d * 3 - 23;
        off = (i & 1) ? -4 : 0;
        if (off < y) y = off;
        c = D_0893B1FC[*(u8 *)(a0 + 0x11AD)];
        func_0882C7B4(a0, x, y, 20, 23, 0xFF, 0xFF, 0xFF, 0xE6, c, 0);
        func_0882C7B4(a0, 0x1CC - x, 0xF9 - y, 20, 23, 0xFF, 0xFF, 0xFF, 0xE6, c, 4);
        x += 20;
        if (x >= 0x1E0) break;
        k += 2;
        i++;
    }
}
