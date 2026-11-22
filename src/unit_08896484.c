/* unit_08896484: 0x08896484-0x088965D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[0xC];
    s16 x;
    s16 y;
    s16 step;
    u8 pad12[0x16];
} Layout08896484;

extern s32 D_09A44C5C;
extern u16 D_089B54E8;
extern u16 D_089B5614;
extern char *D_08A631A8;
extern char D_089B167C[];

extern char *func_09A63198(s32, u16);
extern void func_08896D24(char *, Layout08896484 *, char *, s8, u8, u8, s32);
extern u8 func_08896C2C(char *, u8, u8);
extern char *func_08896C58(char *, u8, u8);
extern int func_088915B0(char *, s32, s16, s32, char *, ...);
extern s32 func_088965D8(s32, s32);

void func_08896484(u8 *arg0) {
    Layout08896484 lay;
    s16 y;
    s32 color;
    u8 idx;
    s32 i;
    char *str;

    switch (arg0[0x10FC]) {
    case 0:
    func_08896D24((char *) arg0, &lay, func_09A63198(D_09A44C5C, D_089B54E8),
                  (s8) arg0[0x1107], arg0[0x1108], arg0[0x1109], 0);
    y = lay.y;
    i = 0;
    idx = arg0[0x1108] * 8;
    do {
        if (func_08896C2C((char *) arg0, arg0[0x1111], idx) == 1) {
            color = 0;
            str = func_08896C58((char *) arg0, arg0[0x1111], idx);
        } else {
            color = 10;
            str = func_09A63198(D_09A44C5C, D_089B5614);
        }
        func_088915B0(D_08A631A8, lay.x, y, color, D_089B167C, str);
        idx++;
        if (idx >= arg0[0x1114]) {
            break;
        }
        i++;
        y += lay.step;
    } while (i < 8);
        break;
    case 1:
        func_088965D8((s32) arg0, 1);
        break;
    }
}
