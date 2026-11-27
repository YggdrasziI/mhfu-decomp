/* unit_0882FC50: 0x0882FC50-0x0882FD68 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Draws a box (Dst layout of func_0882FA24) with the frame style picked by
 * byte 0x0B, sets colours and font, then prints an optional text.
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
    /* 0x08 */ u8 b8;
    /* 0x09 */ u8 b9;
    /* 0x0A */ s8 bA;
    /* 0x0B */ u8 bB;
    /* 0x0C */ s16 hC;
    /* 0x0E */ s16 hE;
    /* 0x10 */ u8 b10;
} Box;

extern char *D_08A631A8;
extern char D_08938478[];

extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_0882DCA8(char *, u16, u16, u16, u16, s32);
extern void func_08832228(char *, u16, u16, u16, u16, s32);
extern void func_08890DE8(char *, u8, u8);
extern void func_08890E40(char *, s32);
extern void func_08890E38(char *, s32);
extern void func_088920A8(char *, s32, s32, char *, ...);

void func_0882FC50(char *arg0, Box *box, char *text, s32 arg3)
{
    switch (box->bB) {
    case 0:
    case 2:
        func_0882DCA0(arg0, box->x, box->y, box->w, box->h, arg3);
        break;
    case 1:
    case 3:
        func_0882DCA8(arg0, box->x, box->y, box->w, box->h, arg3);
        break;
    case 4:
        func_08832228(arg0, box->x, box->y, box->w, box->h, arg3);
        break;
    }
    func_08890DE8(D_08A631A8, box->b8, box->b9);
    func_08890E40(D_08A631A8, box->b10);
    func_08890E38(D_08A631A8, box->bA);
    if (text != 0) {
        func_088920A8(D_08A631A8, box->hC, box->hE, D_08938478, text);
    }
}
