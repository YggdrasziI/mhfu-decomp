/* unit_088FCF84: 0x088FCF84-0x088FD168 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Draws a box with a title and the lines of the three records at +0x2C of
 * arg0 (stride 0x1C) whose kind is 2 and whose group is arg1.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CBBEC;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B05568;

extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern s32 func_088FCF40(char *, s32);
extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_08890DE8(char *, s8, u8);
extern char *func_09A7B790(s32, u16);
extern void func_08827918(char *, s32, s32, char *, s32, s32);
extern void func_088912BC(char *, s16, s16, char *);
extern void func_088BA664(s32, s32);

void func_088FCF84(char *arg0, s32 arg1) {
    u16 title;
    char *p;
    s32 y;
    u8 extra;
    s32 h;
    s32 i;
    char *gfx;

    extra = 1;
    switch (arg1) {
    case 0:
        title = 0x22;
        break;
    case 1:
        extra = 2;
        title = 0x29;
        break;
    case 2:
        title = 0x21;
        break;
    case 3:
        title = 0x2A;
        extra = 2;
        break;
    }
    gfx = D_089CBBEC;
    gfx[0x534] = 0xE;
    func_08890E08(D_08A631A8, 5);
    func_08825DA8(gfx);
    h = (extra + (func_088FCF40(arg0, arg1) + 4)) << 4;
    y = h >> 1;
    func_0882DCA0(D_089CBBEC, 0x78, 0x88 - y, 0xF0, h, 0xFF);
    y = 0xA0 - y;
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08827918(D_089CBBEC, 0xF0, y, func_09A7B790(D_09B22D70, (&D_09B05568)[title]), 0xE, 0x10);
    y += extra << 4;
    p = arg0 + 0x2C;
    func_08890DE8(D_08A631A8, 0x10, 0xE);
    for (i = 0; i < 3; i++) {
        if (*(u16 *)p == 2 && *(u16 *)(p + 2) == arg1) {
            func_088912BC(D_08A631A8, 0xD4, y, p + 4);
            y += 0x10;
        }
        p += 0x1C;
    }
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_088BA664(0x9C, y);
}
