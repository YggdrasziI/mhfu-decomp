/* unit_0882E0D0: 0x0882E0D0-0x0882E2C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Draws entry idx of the table D_0899D19C (24 bytes per entry) with its
 * colour from D_0893AA5C through func_0882BE60 or func_0882C3D0, then an
 * optional marker. The table bytes are read into locals before the if/else
 * between the two calls, as the original loads them once.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern u8 D_0899D19C[];
extern u8 D_0899D19D[];
extern u8 D_0899D19E[];
extern u8 D_0893AA5C[];
extern u8 D_0893AA5D[];
extern u8 D_0893AA5E[];

extern u8 func_088269C0(char *, u16);
extern s32 func_088303B8(char *, u8, s32);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);
extern void func_0882C3D0(char *, u16, u16, u16, u16, u8, u8, u8, s32, s32);
extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);

void func_0882E0D0(char *arg0, u16 idx, u16 x, u16 y, u16 w, u16 h, s8 mode) {
    s32 col;
    s32 state;
    s32 v;
    u8 r, g, b;

    if (D_0899D19D[idx * 24] != 0xFF) {
        state = 0;
        if (func_088269C0(arg0, idx) == 0) {
            col = 10;
            state = -1;
        } else {
            col = D_0899D19E[idx * 24];
            if (D_0899D19C[idx * 24] & 1) {
                state = 1;
            }
        }
        v = func_088303B8(arg0, D_0899D19D[idx * 24], w < 21);
        r = D_0893AA5C[col * 4];
        g = D_0893AA5D[col * 4];
        b = D_0893AA5E[col * 4];
        if (mode == 0) {
            func_0882BE60(arg0, x, y, w, h, r, g, b, v);
        } else {
            func_0882C3D0(arg0, x, y, w, h, r, g, b, mode <= 0, v);
        }
        if (state != 0) {
            if (state > 0) {
                func_0882AF70(arg0, x, y, w, h, w < 21 ? 0xEE : 0x84);
            } else {
                func_0882BE60(arg0, x, y, w, h, 0xFF, 0, 0, 0x85);
            }
        }
    }
}
