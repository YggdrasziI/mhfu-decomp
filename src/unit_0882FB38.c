/* unit_0882FB38: 0x0882FB38-0x0882FC50 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Draws the decorations of a box laid out by func_0882FA24 (hypothesis):
 * when count > 0 a right-aligned "index+1/count" counter (D_08938540 is
 * "%d/%d", D_08938478 is "%s"), then one of two frame styles chosen by flag.
 * - The text width call sits inside the x expression: with the result in a
 *   local first, the font global is loaded before the sum instead of after.
 * - count is passed to the sprintf-like call (the andi a3, a3 in place).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    /* 0x00 */ u16 x;
    /* 0x02 */ u16 y;
    /* 0x04 */ u16 w;
    /* 0x06 */ u16 h;
    /* 0x08 */ u8 size;
    /* 0x09 */ u8 pad9[0x26 - 0x09];
    /* 0x26 */ u16 titleY;
} Box;

extern char *D_08A631A8;
extern char D_08938540;
extern char D_08938478;

extern int func_0880E8F0(char *, char *, ...);
extern s32 func_08890E48(char *, char *);
extern int func_088915B0(char *, s16, s16, s8, char *, ...);
extern void func_0882E6F0(char *, u16, u16, u16, s32);
extern void func_0882E604(char *, u16, u16, u16, u8, u8, u8, u8);

void func_0882FB38(char *arg0, Box *box, u16 index, u16 count, s32 colour, s32 flag)
{
    char buf[0x20];
    s32 px;

    if (count > 0) {
        func_0880E8F0(buf, &D_08938540, index + 1, count);
        px = box->x + box->w - 0x15 - (box->size >> 1) * func_08890E48(D_08A631A8, buf);
        func_088915B0(D_08A631A8, px, box->titleY, (s8)colour, &D_08938478, buf);
    }
    if ((s8)flag == 0) {
        func_0882E6F0(arg0, box->x, box->titleY, box->w - 0xE, 0xF0);
    } else {
        func_0882E604(arg0, box->x, box->titleY, box->w - 0xE, 0x20, 0x70, 0x20, 0xA0);
    }
}
