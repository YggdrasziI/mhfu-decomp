/* unit_08818C94: 0x08818C94-0x08818F74 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_08816BE4 and text_08818F74). Same shape as func_0883488C, which it
 * calls.
 *
 * C++: flag tests keep their `sltu` (bool). Optimized for speed: the division
 * by 6 is a multiplication.
 *
 * `first = (s16) first;` gives the sign extension of `first` in its own
 * register that the original does before the subtraction (an `s16` local
 * extends into a temporary at each use). func_088915B0's fourth parameter is
 * `s8` here, `s32` in unit_0883488C: each is the only type that matches its
 * unit (the real prototype is not settled).
 */

#pragma optimize_for_size off

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

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09A44C5C;
extern u16 D_089AC850;
extern char D_0893854C;
extern char D_0893AF8C;
extern u16 D_089B54E0[];

extern void func_0883488C(char *arg0, s32 arg1);
extern char *func_0885151C(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_0882FB38(char *, Box *, u16, u16, s32, s32);
extern s32 func_088239FC(char *);
extern s32 func_0882A864(char *, s32);
extern s32 func_09A6E5A8(char *);
extern s32 func_0884FA5C(char *, s32);
extern char *func_09A63198(s32, u16);
extern int func_088915B0(char *, s32, s16, s8, char *, ...);

void func_08818C94(char *arg0, s32 arg1) {
    Box box;
    char text[0x20];
    s8 marks[8];
    s16 q;
    s32 first;
    s16 y;
    s32 i;
    u16 *ids;
    s8 *m;

    if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 1) {
        func_0883488C(arg0, arg1);
        return;
    }
    q = *(u8 *)(arg0 + 0x57D) / 6;
    first = (s16) (q * 6);
    func_0880E8F0(text, &D_0893854C, func_0885151C(D_089CC438, D_089AC850));
    func_0882FA24(&box, &D_0893AF8C, text, 0, 0);
    if ((s8) arg1 != 0) {
        box.color = 0x80808080;
    }
    first = (s16) first;
    func_0882F580(arg0, &box, text, *(u8 *)(arg0 + 0x57D) - first, 0xFF, 0);
    func_0882FB38(arg0, &box, q, 2, 0, arg1);
    marks[5] = 0;
    marks[4] = 0;
    marks[3] = 0;
    marks[2] = 0;
    marks[1] = 0;
    marks[0] = 0;
    if (q == 0) {
        char *o = *(char **)(arg0 + 0x530);

        if ((u8) func_088239FC(arg0) == 0 || (u8) func_0882A864(arg0, 0) == 0 || (u8) func_09A6E5A8(o) == 1) {
            marks[1] = 10;
        }
        if ((bool) *(u8 *)(o + 0x1E0) == 1) {
            marks[3] = 10;
        }
        if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 0x100) == 0) {
            marks[4] = 10;
        }
        if ((u8) func_0884FA5C(D_089CC438, 0) == 1) {
            marks[5] = 10;
            marks[4] = 10;
        }
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1) {
            marks[5] = 10;
        }
    } else {
        if ((u8) func_0884FA5C(D_089CC438, 0) == 1) {
            marks[4] = 10;
        }
        marks[5] = 10;
    }
    y = box.y;
    for (i = 0, ids = &D_089B54E0[first], m = marks; i < 6; i++, ids++, m++, y += box.h) {
        func_088915B0(D_08A631A8, box.x, y, *m, func_09A63198(D_09A44C5C, *ids));
    }
}

}
