/* unit_08839824: 0x08839824-0x08839B30 (ULES01213)
 *
 * C++: flag tests keep their `sltu` (bool).
 */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box {
    u16 x;
    u8 unk2[0xA];
    u16 unkC;
    u16 y;
    u16 h;
    u8 unk12[0x16];
} Box;

extern "C" {

extern char *D_089CBBEC;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_0893B386;
extern char D_0893B37C;
extern char D_0893B390;
extern char D_0893B220;
extern u16 D_09B051B4;
extern u16 D_09B05C90[];
extern u16 D_09B05C98[];

extern int func_0880E8F0(char *, char *, ...);
extern void func_0882FA24(Box *, char *, s32, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern char *func_09A7B790(s32, u16);
extern void func_08890E38(char *, s8);
extern s32 func_08890E48(char *, char *);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_0882E6F0(char *, u16, u16, s32, s32);

void func_08839824(char *arg0) {
    Box box;
    char text[0x20];
    u16 *id;
    s16 x;
    s16 w;

    if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1) {
        D_0893B386 = 2;
    } else {
        D_0893B386 = 3;
    }
    func_0882FA24(&box, &D_0893B37C, 1, 0, 0);
    func_0880E8F0(text, &D_0893B390, func_09A7B790(D_09B22D70, D_09B051B4));
    func_0882F580(arg0, &box, text, -1, 0xFF, 1);
    func_08890E38(D_08A631A8, 5);

    id = &D_09B05C98[(s16) (*(s8 *)(D_089CBBEC + 0x608) + 3)];
    w = func_08890E48(D_08A631A8, func_09A7B790(D_09B22D70, *id));
    x = box.x + 0xC4 - (w * 7 >> 1);
    func_08891474(D_08A631A8, x, box.y, &D_0893B220, func_09A7B790(D_09B22D70, *id));

    id = &D_09B05C98[(s16) (*(s8 *)(D_089CBBEC + 0x60A) + 5)];
    w = func_08890E48(D_08A631A8, func_09A7B790(D_09B22D70, *id));
    x = box.x + 0xC4 - (w * 7 >> 1);
    func_08891474(D_08A631A8, x, box.y + box.h, &D_0893B220, func_09A7B790(D_09B22D70, *id));

    if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 0) {
        id = &D_09B05C90[(s16) (*(s8 *)(D_089CBBEC + 0x609) ^ 1)];
        w = func_08890E48(D_08A631A8, func_09A7B790(D_09B22D70, *id));
    x = box.x + 0xC4 - (w * 7 >> 1);
        func_08891474(D_08A631A8, x, box.y + box.h * 2, &D_0893B220, func_09A7B790(D_09B22D70, *id));
    }
    func_0882E6F0(arg0, box.unkC + 0x92, box.y + box.h * *(u8 *)(arg0 + 0x57F), 0x46, 0xF0);
}

}
