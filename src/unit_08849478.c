/* unit_08849478: 0x08849478-0x0884953C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_08A631A8;
extern s32 D_09A44C5C;
extern u16 D_089B5594;
extern s32 D_089CC438;

extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_08890DE8(char *, s8, u8);
extern char *func_09A63198(s32, u16);
extern s32 func_08853004(s32, char *, s16, s16);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);

void func_08849478(char *arg0) {
    u8 n = *(u8 *)(arg0 + 0x11AC);
    s16 y;
    char *str;

    if (n != 0) {
        y = (n - 1) * 34 - 7;
        func_0882DCA0(arg0, 0xB7, y - 8, 0x70, 0x1E, 0xFF);
        func_08890DE8(D_08A631A8, 0xE, 0xE);
        str = func_09A63198(D_09A44C5C, D_089B5594);
        func_088915B0(D_08A631A8, func_08853004(D_089CC438, str, 0xF0, 0xE), y, 0, str);
    }
}
