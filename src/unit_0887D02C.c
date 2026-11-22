/* unit_0887D02C: 0x0887D02C-0x0887D0B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;

extern char *D_08A631A8;
extern s32 func_08890F70(char *, char *);
extern void func_088920A8(char *, s16, s16, char *, ...);

void func_0887D02C(s32 x, s32 y, char *str, s32 scale)
{
    s32 w = func_08890F70(D_08A631A8, str);

    func_088920A8(D_08A631A8, x - w * scale / 2, y, str);
}
