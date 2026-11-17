/* unit_0887AFB8: 0x0887AFB8-0x0887B7C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_0887AFB8) and unit_0887B7C4. Its jump table (0x089318F0-0x08931910)
 * is linked from this unit.
 *
 * C++: the local tables are declared where they are first used and the
 * `(bool) (x & 1) != 0` tests keep their `sltu`. Optimized for speed: the
 * division by 30 is a multiplication.
 *
 * Its jump table would be the unit's .rodata (0x089318F0-0x08931910) and the
 * initializers of the local s16[12] and s16[7] tables its .data
 * (0x089A8920-0x089A8948, the second table followed by 2 bytes of padding).
 *
 * NonMatching: func_0887AFB8 98.3 %. Two register choices differ: the original
 * loads the halfword index at D_089CC438 + 0x6AF12 into a1 and hoists the
 * 0x60000 of the table address before the D_08A631A8 load; and in
 * `pos[6] - n * 8` / `pos[2] - n * 8` it loads pos[] into a1 and n * 8 into
 * v1 (ours: the reverse). Tried: array, pointer and local-index forms of the
 * table read; s32 / s16 parameters of func_08891474 and func_088920A8; `<< 3`,
 * negated and cast forms of the subtraction; locals for n and the result;
 * s16 / u16 returns of func_08890F70 and func_088167F4.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {

extern char *D_089CBBE8;
extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern char *D_08A62C7C;
extern char *D_09A0B544;
extern s32 D_09A44C5C;
extern char D_089A8870;
extern char D_089A891C;
extern char D_089A8948;
extern u16 D_089B53C2;
extern u16 D_089B53C4;
extern u16 D_089B53C6;
extern u16 D_089B53C8;
extern u16 D_089B53CC;
extern u16 D_089B540A;
extern u16 D_089B540C;
extern u16 D_089B540E;
extern u16 D_089B5418;
extern u16 D_089B543C;

extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern void func_08879488(char *);
extern void func_08890E38(char *, s8);
extern void func_08890DE8(char *, s8, u8);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_08890DFC(char *, s16, s16);
extern void func_08892004(char *, char *, ...);
extern char *func_09A63198(s32, u16);
extern void func_0887D02C(s32, s32, char *, s32);
extern void func_08891474(char *, s32, s16, char *, ...);
extern int func_0880E8F0(char *, char *, ...);
extern s32 func_0886A30C(char *, s32);
extern void func_0887941C(char *, s32, char *);
extern char *func_0886BEA4(char *, s32);
extern void func_088912BC(char *, s16, s16, s32);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern s32 func_08890F70(char *, char *);
extern int func_088167F4(char *, char *);
extern void func_08832684(char *, u16, u16, u16, u16, s32);
extern void func_0882D6F0(char *, u16, u16, u16, u16, s32, s32, s32);

void func_0887AFB8(char *arg0) {
    char text[0x100];
    s16 pos[12] = {0x40, 0x40, 0x19E, 0x40, 0x40, 0x50, 0x19E, 0x50, 0x40, 0x60, 0x160, 0x18};
    char *g = D_089CBBEC;
    char *src;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    s32 len;
    float v;
    s16 n;

    g[0x534] = 9;
    func_08890E08(D_08A631A8, 0);
    func_08825DA8(g);
    func_08879488(arg0);
    func_08890E38(D_08A631A8, 0);
    func_08890DE8(D_08A631A8, 0x10, 0x10);
    if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) {
        if (*(u8 *)(D_089CC438 + 0x28) == 0) {
            src = D_09A0B544 + 0xC90;
        } else {
            src = D_09A0B544 + 0xBC8;
        }
    }
    switch (*(s16 *)(arg0 + 0xA4)) {
    default:
    case 7:
        func_0882A9DC(D_089CBBEC, 0x1C, 0xF0, 0x33);
        func_08890DFC(D_08A631A8, 0x30, 0xF2);
        func_08892004(D_08A631A8, func_09A63198(D_09A44C5C, D_089B540A));
    case 5:
    case 6:
        func_08891474(D_08A631A8, 0xF4, 0xB2, &D_089A891C, ((s32 *)(D_089CC438 + 0x6397C))[*(u16 *)(D_089CC438 + 0x6AF12)]);
        if (*(s16 *)(arg0 + 0xAC) != 0) {
            func_08890E38(D_08A631A8, 5);
            func_0887941C(arg0, 0xC2, func_09A63198(D_09A44C5C, D_089B540E));
            func_08890E38(D_08A631A8, 0);
        }
    case 4:
        func_0887D02C(0xF4, 0x80, func_09A63198(D_09A44C5C, D_089B53CC), 0x10);
        func_08891474(D_08A631A8, 0xF4, 0x80, &D_089A891C, *(s32 *)(arg0 + 0x120));
        func_0887D02C(0xF4, 0x90, func_09A63198(D_09A44C5C, D_089B543C), 0x10);
        func_08891474(D_08A631A8, 0xF4, 0x90, &D_089A891C, *(s32 *)(arg0 + 0x14));
    case 3:
        func_08890E38(D_08A631A8, 2);
        func_0880E8F0(text, &D_089A8948, *(s32 *)(arg0 + 0xB0));
        func_088920A8(D_08A631A8, pos[4], pos[5], &D_089A8870, text);
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0 && src != 0 && *(u16 *)src != 0) {
            func_08890E38(D_08A631A8, 0xE);
            func_0880E8F0(text, &D_089A8948, *(s32 *)(arg0 + 0xB4));
            func_088920A8(D_08A631A8, pos[6] - (s16) func_08890F70(D_08A631A8, text) * 8, pos[7], &D_089A8870, text);
        }
        func_08890E38(D_08A631A8, 0);
    case 2:
        func_08890E38(D_08A631A8, 2);
        func_088912BC(D_08A631A8, pos[0], pos[1], (s32) (D_089CC438 + 0x4A0));
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0 && src != 0 && *(u16 *)src != 0) {
            func_08890E38(D_08A631A8, 0xE);
            func_088912BC(D_08A631A8, pos[2] - (s16) func_088167F4(D_089CBBE8, src) * 8, pos[3], (s32) src);
        }
        func_08890E38(D_08A631A8, 0);
        h = pos[11];
        w = pos[10];
        y = pos[9];
        x = pos[8];
        func_08832684(D_089CBBEC, x, y, w, h, 0xFF);
        len = w - 4;
        v = (float) len * ((float) *(s32 *)(arg0 + 0xB8) / (float) (*(s32 *)(arg0 + 0xB0) + *(s32 *)(arg0 + 0xB4)));
        n = v;
        if (v - n >= 0.5f) {
            n++;
        }
        if (n > 0) {
            func_0882D6F0(D_089CBBEC, x + 2, y + 2, n, h - 4, 0xFF, 0, 0);
        }
        v = (float) len * ((float) *(s32 *)(arg0 + 0xBC) / (float) (*(s32 *)(arg0 + 0xB0) + *(s32 *)(arg0 + 0xB4)));
        n = v;
        if (v - n >= 0.5f) {
            n++;
        }
        if (n > 0) {
            func_0882D6F0(D_089CBBEC, x + w - 2, y + 2, -n, h - 4, 0, 0, 0xFF);
        }
    case 1:
        if (func_0886A30C(D_08A62C7C, 1) == 1) {
            func_0880E8F0(text, func_09A63198(D_09A44C5C, D_089B53C2));
        } else {
            func_0880E8F0(text, func_09A63198(D_09A44C5C, D_089B53C4));
        }
        func_0887941C(arg0, 0x30, text);
        func_0887941C(arg0, pos[4], func_0886BEA4(D_08A62C7C, 0));
    case 0:
        break;
    }
    func_08890DFC(D_08A631A8, 0xFC, 0xF2);
    func_08892004(D_08A631A8, func_09A63198(D_09A44C5C, D_089B53C6), *(s16 *)(arg0 + 0xAA) / 30);
    s16 dx2[7] = {0, 0, 0, 0, 0, 0x1C, 0};
    s32 x2 = dx2[*(s32 *)(D_08A631A0 + 0xF7A574)] + 0xF4;
    func_0887D02C(x2, 0xF, func_09A63198(D_09A44C5C, D_089B53C8), 0x10);
    func_088912BC(D_08A631A8, x2, 0xF, (s32) (D_089CC438 + 0x4A0));
    func_0887D02C(0xF4, 0xB2, func_09A63198(D_09A44C5C, D_089B540C), 0x10);
    func_0887D02C(0xF4, 0xD2, func_09A63198(D_09A44C5C, D_089B5418), 0x10);
    func_08891474(D_08A631A8, 0xF4, 0xD2, &D_089A891C, *(s32 *)(D_089CC438 + 0x696E8));
}

}