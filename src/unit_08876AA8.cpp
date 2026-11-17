/* unit_08876AA8: 0x08876AA8-0x08876FCC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_088765C0 and text_08876FCC). Its jump table (0x089317E0-0x089317FC)
 * is linked from this unit.
 *
 * C++: the two local tables are declared where they are copied. Optimized
 * for speed: the division by 30 is a multiplication.
 *
 * .data: the initializers of the two local s16[7] tables (each followed by 2
 * bytes of padding). Same layout as func_0887A34C, with case 6 listed
 * beside `default`; the `(bool) (x & 1) == 1` test needs C++.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {

extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern char *D_08A62C7C;
extern char *D_08A62CB4;
extern s32 D_09A4F0C4;
extern s32 D_09A44C5C;
extern s16 D_089A87E0;
extern s16 D_089A87E2;
extern s16 D_089A87E4;
extern s16 D_089A87E6;
extern u16 D_089B53B8;
extern u16 D_089B53BA;
extern u16 D_089B53BE;
extern u16 D_089B53C0;
extern u16 D_089B53CA;
extern u16 D_089B541A;
extern u16 D_089B541E;
extern u16 D_089B53C2;
extern u16 D_089B53C4;
extern u16 D_089B53C6;
extern u16 D_089B53C8;
extern u16 D_089B53CC;
extern u16 D_089B53CE;
extern u16 D_089B53D0;
extern u16 D_089B53D2;
extern u16 D_089B53D4;
extern u16 D_089B53D6;
extern u16 D_089B53E0;

extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern char *func_088DCEBC(s32, u8);
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
extern u8 func_0887CA08(char *);
extern s32 func_088D6A54(char *, s32);

void func_08876AA8(char *arg0) {
    char text[0x100];
    char *g = D_089CBBEC;
    s32 sel;
    s32 val;
    s16 x;

    g[0x534] = 9;
    func_08890E08(D_08A631A8, 0);
    func_08825DA8(g);
    func_08879488(arg0);
    func_08890E38(D_08A631A8, 0);
    func_08890DE8(D_08A631A8, 0x10, 0x10);
    s16 dx[7] = {0, 0, -4, 0, -4, 0, 0};
    sel = *(s32 *)(D_08A631A0 + 0xF7A574);
    switch (*(s16 *)(arg0 + 0xA4)) {
    default:
    case 6:
        x = dx[sel];
        func_0882A9DC(D_089CBBEC, x + 0x1C, 0xF0, 0x33);
        func_08890DFC(D_08A631A8, x + 0x30, 0xF2);
        func_08892004(D_08A631A8, func_09A63198(D_09A44C5C, D_089B53B8));
    case 4:
    case 5:
        func_0887D02C(0xF4, D_089A87E6, func_09A63198(D_09A44C5C, D_089B53BA), 0x10);
        func_08891474(D_08A631A8, 0xF4, D_089A87E6, func_09A63198(D_09A44C5C, D_089B541A), *(s32 *)(arg0 + 0x14));
    case 3:
        val = 0;
        if (func_0886A30C(D_08A62C7C, 1) == 1) {
            if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1) {
                if (func_0887CA08(arg0) == 1) {
                    val = *(s32 *)(*(char **)(D_08A62C7C + 0x68) + 4);
                }
            } else {
                val = *(s32 *)(*(char **)(D_08A62C7C + 0x68) + 4);
            }
        }
        func_0887D02C(0xF4, D_089A87E4, func_09A63198(D_09A44C5C, D_089B53BE), 0x10);
        func_08891474(D_08A631A8, 0xF4, D_089A87E4, func_09A63198(D_09A44C5C, D_089B541E), val);
    case 2:
        if (func_0886A30C(D_08A62C7C, 1) == 1) {
            if (func_088D6A54(func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)), 0x31) == 0) {
                val = *(s32 *)(D_08A62C7C + 0x14);
            } else {
                val = *(s32 *)(D_08A62C7C + 0x14) * 2;
            }
        } else {
            val = 0;
        }
        func_0887D02C(0xF4, D_089A87E2, func_09A63198(D_09A44C5C, D_089B53C0), 0x10);
        func_08891474(D_08A631A8, 0xF4, D_089A87E2, func_09A63198(D_09A44C5C, D_089B541A), val);
    case 1:
        if (func_0886A30C(D_08A62C7C, 1) == 1) {
            func_0880E8F0(text, func_09A63198(D_09A44C5C, D_089B53C2));
        } else {
            func_0880E8F0(text, func_09A63198(D_09A44C5C, D_089B53C4));
        }
        func_0887941C(arg0, 0x30, text);
        func_0887941C(arg0, D_089A87E0, func_0886BEA4(D_08A62C7C, 0));
    case 0:
        break;
    }
    func_08890DFC(D_08A631A8, 0xFC, 0xF2);
    func_08892004(D_08A631A8, func_09A63198(D_09A44C5C, D_089B53C6), *(s16 *)(arg0 + 0xAA) / 30);
    s16 dx2[7] = {0, 0, 0, 0, 0, 0x1C, 0};
    s32 x2 = dx2[sel] + 0xF4;
    func_0887D02C(x2, 0xF, func_09A63198(D_09A44C5C, D_089B53C8), 0x10);
    func_088912BC(D_08A631A8, x2, 0xF, (s32) (D_089CC438 + 0x4A0));
    func_0887D02C(0xF4, 0xB2, func_09A63198(D_09A44C5C, D_089B53CA), 0x10);
    func_08891474(D_08A631A8, 0xF4, 0xB2, func_09A63198(D_09A44C5C, D_089B541A), *(s32 *)(D_089CC438 + 0x696F0));
}

}