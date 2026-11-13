/* unit_088A9FF8: 0x088A9FF8-0x088AA0BC (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char D_09A1D5D0;
extern s8 D_09A1D5F1;
extern u8 D_09A1D5F3;
extern char D_09A1D638;
extern int func_088A84B4(void *, s32, s32);
extern s32 func_088A86F0(s32);
extern s32 func_088A8720(s32);

void func_088A9FF8(void) {
    if (*((u8 *)&D_09A1D638 + D_09A1D5F3) == 4) {
        func_088A86F0((s32) &D_09A1D5D0);
        func_088A84B4(&D_09A1D5D0, (s32) D_09A1D5F3, 3);
    }
}

void func_088AA054(void) {
    if (*((u8 *)&D_09A1D638 + D_09A1D5F3) == 3) {
        func_088A8720((s32) &D_09A1D5D0);
        func_088A84B4(&D_09A1D5D0, (s32) D_09A1D5F3, 5);
        D_09A1D5F1 = 6;
    }
}
