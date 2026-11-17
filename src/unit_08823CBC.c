/* unit_08823CBC: 0x08823CBC-0x08823DB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_08823DB0. Its initialised array (0x08938614-0x08938620, in .data) is
 * linked from this unit.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern char D_08938620;
extern char *D_089CC438;
extern char *D_08A631A8;

extern int func_0880E8F0(char *, char *, ...);
extern void func_0882DCA0(s32, s32, s32, s32, s32, s32);
extern void func_0887D02C(s32, s32, char *, s32);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);

void func_08823CBC(s32 arg0, u8 arg1, s32 arg2) {
    u16 pos[6] = {0x168, 4, 0x70, 0x18, 0x1CC, 0xA};
    char text[0x20];

    if (arg2 != 0) {
        pos[1] += 0x1C;
        pos[5] += 0x1C;
    }
    func_0882DCA0(arg0, pos[0], pos[1], pos[2], pos[3], 0xFF);
    func_0880E8F0(text, &D_08938620, *(s32 *)(D_089CC438 + 0x696F0));
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, arg1 == 0 ? 0 : 0xA);
    func_0887D02C(pos[4], pos[5], text, 0xE);
}