/* unit_088BA54C: 0x088BA54C-0x088BA5BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088BA494 and unit_088BA5BC.
 *
 * Draws string arg2 of the message table D_089CC438 at (x, y) in font 0x10.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern char *D_08A631A8;

extern void func_08890E40(char *, s32);
extern char *func_08851680(char *, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);

void func_088BA54C(s32 x, s32 y, u16 id) {
    func_08890E40(D_08A631A8, 0x10);
    func_088920A8(D_08A631A8, x, y, func_08851680(D_089CC438, id));
}
