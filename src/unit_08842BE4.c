/* unit_08842BE4: 0x08842BE4-0x08842D3C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08842BE4 (ULES01213)
 *
 * Optimized for speed: the register allocation only matches with it.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern u16 D_0893B5EC;
extern u16 D_0893B5EE;
extern u16 D_0893B5F0;
extern u16 D_0893B5F2;
extern u16 D_0893B5F4;
extern u16 D_0893B5F6;

extern u8 func_088DAB94(char *, s16);
extern void func_0882B624(char *, u16, u16, s32, s32, s32, s32, s32);

void func_08842BE4(char *arg0, u8 arg1) {
    char *p = *(char **)(arg0 + 0x530);
    s32 r;
    u16 x;
    u16 y;
    s32 g;
    s32 b;
    s32 n;
    s32 sel;
    s32 mode;

    r = g = b = 0xFF;
    switch (arg1) {
    case 0:
        x = D_0893B5EC;
        y = D_0893B5EE;
        break;
    case 1:
        x = D_0893B5F0 + (12 - *(u8 *)(p + 0x67D)) * 4;
        y = D_0893B5F2;
        break;
    case 2:
        if (func_088DAB94(p, *(s16 *)(p + 0x10F2)) == 0) {
            g = (u8)(b = 0);
        }
        x = D_0893B5F4;
        y = D_0893B5F6;
        break;
    }
    n = *(u8 *)(p + 0x67D);
    sel = n - *(u8 *)(p + 0x67C);
    mode = 0x1D;
    if (n > 0) {
        do {
            if (n <= sel) {
                mode = 0x1E;
            }
            func_0882B624(arg0, x, y, r, g, b, mode, 0);
            x += 8;
        } while (--n > 0);
    }
}
