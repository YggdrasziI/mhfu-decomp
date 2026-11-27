/* unit_08818F74: 0x08818F74-0x0881908C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08818F74: draws two text items then a box. */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_08A631A8;
extern char *D_08A631A0;
extern s32 D_09A44C5C;
extern u16 D_089B5558[];
extern u16 D_089B555C;

extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern char *func_09A63198(s32, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern void func_0882DCA8(char *, u16, s32, u16, s32, s32);

void func_08818F74(char *p)
{
    s16 x;
    s16 y;

    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    func_088920A8(D_08A631A8, 0x170, 0xB1,
                  func_09A63198(D_09A44C5C, D_089B5558[*(u8 *)(p + 0x576) & 1]));
    x = 0x168;
    y = 0x70;
    if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 1) {
        x -= 0x40;
        y += 0x40;
        func_088920A8(D_08A631A8, 0x130, 0xB1, func_09A63198(D_09A44C5C, D_089B555C));
    }
    func_0882DCA8(p, x, 0xA8, y, 0x20, 0xFF);
}
