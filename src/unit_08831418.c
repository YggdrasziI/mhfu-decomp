/* unit_08831418: 0x08831418-0x088314A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 pad;
    u8 b;
    u16 h;
    u8 pad2[8];
} Key;

extern s32 func_0883029C(char *, Key *, s32);
extern void func_0882C11C(char *, u16, u16, s32, s32, u8, u8, u8, u8, s32);

void func_08831418(char *arg0, u8 arg1, u16 arg2, u16 x, u16 y, u8 *col) {
    Key k;
    s32 r;

    k.b = arg1;
    k.h = arg2;
    r = func_0883029C(arg0, &k, 1);
    func_0882C11C(arg0, x, y, 0x10, 0x10, col[2], col[1], col[0], col[3], r);
}
