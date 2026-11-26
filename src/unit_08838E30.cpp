/* unit_08838E30: 0x08838E30-0x08838F58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 *
 * C++: the flag test keeps its `sltu` (bool). The guard is a one-case switch
 * (`beqz` to the body, then `b` to the epilogue).
 */


typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box {
    u8 unk0[0xC];
    s16 x;
    s16 y;
    s16 h;
    u8 unk12[6];
    s32 color;
    u8 unk1C[0xC];
} Box;

extern "C" {

extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern char D_0893B340;
extern char D_0893B220;
extern u16 D_09B052C8[];

extern void func_0883488C(char *, s32);
extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern char *func_09A7B790(s32, u16);
extern void func_08892148(char *, s32, s16, s8, char *, ...);

void func_08838E30(char *arg0) {
    Box box;
    s8 marks[4];
    s32 i;
    s16 y;
    u16 *ids;
    s8 *m;

    switch (*(u8 *)(arg0 + 0x57E)) {
    case 0:
        func_0883488C(arg0, 1);
        func_0882FA24(&box, &D_0893B340, 0, 0, 0);
        func_0882F580(arg0, &box, 0, *(u8 *)(arg0 + 0x57F), 0xFF, 1);
        marks[3] = 0;
        marks[2] = 0;
        marks[1] = 0;
        marks[0] = 0;
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 0) {
            marks[2] = 10;
        }
        y = box.y;
        for (i = 0, ids = D_09B052C8, m = marks; i < 4; ids++, m++, y += box.h, i++) {
            func_08892148(D_08A631A8, box.x, y, *m, &D_0893B220, func_09A7B790(D_09B22D70, *ids));
        }
        break;
    }
}

}
