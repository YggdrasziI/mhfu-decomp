/* unit_088BA2E0: 0x088BA2E0-0x088BA494 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088BA2E0 asm piece, 1 function
 * between unit_088BA2A0 and unit_088BA494.
 *
 * Draws the two strings D_089AC584 / D_089AC586 of the message table
 * D_089CC438 centred at x + 0xE and x + 0x5B, the selected one with style 5,
 * and a 0x54 x 0x10 frame on it when arg3 is set.
 *
 * Speed setting: with the default size setting the frame x and the text
 * widths take each other's saved registers.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A8;
extern u16 D_089AC584;
extern u16 D_089AC586;

extern char *func_0885151C(char *, u16);
extern s32 func_08890F70(char *, char *);
extern void func_08892148(char *, s16, s16, s8, char *, ...);
extern void func_08831F3C(char *, u16, u16, u16, u16, s32, s32, s32);

void func_088BA2E0(s32 x, s32 y, s32 sel, s32 show) {
    s32 s0;
    s32 s1;
    u16 fx;
    s32 w;

    if (sel != 0) {
        s0 = 5;
        s1 = 0;
        fx = x - 0x1C;
    } else {
        s0 = 0;
        s1 = 5;
        fx = x + 0x31;
    }
    if (show == 0) {
        s0 = 0;
        s1 = 0;
    }
    w = func_08890F70(D_08A631A8, func_0885151C(D_089CC438, D_089AC584));
    func_08892148(D_08A631A8, x + 0xE - w * 7 / 2, y, s0, func_0885151C(D_089CC438, D_089AC584));
    w = func_08890F70(D_08A631A8, func_0885151C(D_089CC438, D_089AC586));
    func_08892148(D_08A631A8, x + 0x5B - w * 7 / 2, y, s1, func_0885151C(D_089CC438, D_089AC586));
    if (show != 0) {
        func_08831F3C(D_089CBBEC, fx, y - 2, 0x54, 0x10, 0, 0x80, 0);
    }
}
