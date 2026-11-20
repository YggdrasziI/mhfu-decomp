/* unit_088DBD98: 0x088DBD98-0x088DBE28 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088DBBBC and unit_088DBE28.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern s32 D_08A62C54;
extern char *D_09A4F0D0;
extern u16 D_089B6540[];

extern s32 func_08851F20(char *, s32);
extern u8 func_0885CCD0(s32, u16);
extern void func_088DDBD8(char *, s32, s32, s32);

void func_088DBD98(s32 arg0, s32 arg1) {
    char *g = D_089CC438;

    if (*(u8 *)(g + arg1 * 0x8C + 0x30) != 0) {
        func_088DDBD8(D_09A4F0D0, arg1 + 1, D_089B6540[(u8) func_0885CCD0(D_08A62C54, func_08851F20(g, arg1))], 0);
    }
}
