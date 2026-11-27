/* unit_0882E53C: 0x0882E53C-0x0882E604 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Draws a rectangle filled with colour col of the table
 * D_0893AA5C (4 bytes per entry, bytes named one by one by splat) unless
 * arg1 is 0xFF; the last argument is computed by func_088303B8 from arg1
 * and whether w < 21.
 * - arg1 is an s32 masked once in place (`arg1 = (u8)arg1;`) and passed to an
 *   s32 callee parameter: a u8 parameter masks into another register.
 * - The call result goes to an s32 local first (callee returns s32).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern u8 D_0893AA5C[];
extern u8 D_0893AA5D[];
extern u8 D_0893AA5E[];

extern s32 func_088303B8(char *, s32, s32);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);

void func_0882E53C(char *arg0, s32 arg1, u8 col, u16 x, u16 y, u16 w, u16 h) {
    s32 r;

    arg1 = (u8)arg1;
    if (arg1 != 0xFF) {
        r = func_088303B8(arg0, arg1, w < 21);
        func_0882BE60(arg0, x, y, w, h, D_0893AA5C[col * 4], D_0893AA5D[col * 4],
                      D_0893AA5E[col * 4], r);
    }
}
