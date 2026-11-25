/* unit_08849CAC: 0x08849CAC-0x08849D7C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08849CAC: draws a box at D_0893B090, then a text line from
 * func_0885151C at an x computed by func_08853004. */

typedef int s32;
typedef short s16;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_09A44C5C;
extern u16 D_089B5560;
extern u16 D_0893B090;
extern u16 D_0893B094;
extern u16 D_0893B09E;
extern u16 D_089AC588[];
extern s32 D_089CC438;
extern s32 D_08A631A8;
extern char D_0893B650[];

extern char *func_09A63198(s32, u16);
extern void func_0882FC50(char *, u16 *, char *, s32);
extern char *func_0885151C(s32, u16);
extern s16 func_08853004(s32, char *, s16, s16);
extern void func_088920A8(s32, s16, s16, char *, ...);

void func_08849CAC(char *arg0) {
    char *s;
    s16 x;
    s32 h;

    func_0882FC50(arg0, &D_0893B090, func_09A63198(D_09A44C5C, D_089B5560), 0xFF);
    s = func_0885151C(D_089CC438, D_089AC588[*(u8 *)(arg0 + 0x537)]);
    h = (u32)D_0893B094 >> 1;
    x = func_08853004(D_089CC438, s, D_0893B090 + h, 0xE);
    func_088920A8(D_08A631A8, x, D_0893B09E + 0x96, D_0893B650, s);
}
