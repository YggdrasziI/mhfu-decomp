/* unit_088BA664: 0x088BA664-0x088BA704 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088BA5BC and unit_088BA704.
 *
 * Draws the string D_089AD050 of the message table D_089CC438 right-aligned
 * at x = 0xF0 on line y.
 */

typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern char *D_08A631A8;
extern u16 D_089AD050;

extern char *func_0885151C(char *, u16);
extern s32 func_08890F70(char *, char *);
extern void func_08892148(char *, s16, s16, s8, char *, ...);

void func_088BA664(s32 arg0, s32 y) {
    s32 x;

    x = 0xF0 - func_08890F70(D_08A631A8, func_0885151C(D_089CC438, D_089AD050)) * 14 / 4;
    func_08892148(D_08A631A8, x, y, 0, func_0885151C(D_089CC438, D_089AD050));
}
