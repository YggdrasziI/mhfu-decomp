/* unit_08818028: 0x08818028-0x088180CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08818028: draws the text entry `id` at (x, y) with a colour chosen
 * from two flags (hypothesis on the purpose). */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern char *D_089CC438;
extern char *D_08A631A8;
extern char D_08938478[];
extern char *func_08851528(char *, u16);
extern int func_088915B0(char *, s16, s16, s8, char *, ...);

void func_08818028(s32 arg0, s16 x, s16 y, u8 sel, u16 id, u8 flag) {
    s8 col;

    if (id == 0xFFFF) {
        return;
    }
    if (flag == 1) {
        col = 5;
    } else {
        col = (sel != 0xFF) ? 0 : 10;
    }
    func_088915B0(D_08A631A8, x, y, col, D_08938478, func_08851528(D_089CC438, id));
}
