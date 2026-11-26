/* unit_08831274: 0x08831274-0x08831338 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08831274: draws a list of message ids, one per line. */

typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *D_08A631A8;
extern char *D_089CC438;
extern char D_08938478;

extern void func_08890E38(char *, s8);
extern char *func_0885151C(char *, u16);
extern void func_088920A8(char *, s32, s16, char *, ...);

void func_08831274(s32 arg0, s32 x, s16 y, u16 *ids, s16 step, s8 *colors) {
    if (*ids != 0xFFFF) do {
        if (colors != 0) {
            func_08890E38(D_08A631A8, *colors);
            colors++;
        }
        func_088920A8(D_08A631A8, x, y, &D_08938478, func_0885151C(D_089CC438, *ids));
        ids++;
        y += step;
    } while (*ids != 0xFFFF);
}
