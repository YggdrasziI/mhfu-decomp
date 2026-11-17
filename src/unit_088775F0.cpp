/* unit_088775F0: 0x088775F0-0x08877BE8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (unit_08877100 and unit_08877BE8). Its jump table (0x08931814-0x0893182C)
 * is linked from this unit.
 *
 * C++: the two local tables are declared where they are copied. Optimized
 * for speed: the divisions by 30 and 10 are multiplications.
 *
 * .data: the initializers of the two local s16[7] tables (each followed by 2
 * bytes of padding). Same layout as func_0887A34C. `> 10` (not `>= 0xB`)
 * gives the `slti at` compare; func_0882E2C0 / func_0882E6F0 take s32 for
 * the halfwords loaded last, so the D_089CBBEC load comes after them.
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
extern char D_0899D198;
extern u16 D_089A8808;
extern u16 D_089A880A;
extern u16 D_089A880C;
extern s16 D_089A8820;
extern s16 D_089A8822;
extern s16 D_089A8824;
extern s16 D_089A8826;
extern s16 D_089A8828;
extern s16 D_089A882A;
extern u16 D_089A882C;
extern u16 D_089A882E;
extern s16 D_089A8838;
extern s16 D_089A883A;
extern s16 D_089A8842;
extern s16 D_089A8846;
extern u16 D_089B53B8;
extern u16 D_089B53EA;
extern u16 D_089B5412;
extern u16 D_089B5414;
extern u16 D_089B5416;
extern u16 D_089B5418;
extern u16 D_089B541C;
extern u16 D_089B5420;
extern u16 D_089B53CA;
extern u16 D_089B541A;
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
extern void func_0882E2C0(char *, u16, u16, u16, s32, s32, s32, s32);
extern char *func_08851528(char *, u16);
extern void func_0882E6F0(char *, s32, s32, s32, s32);

void func_088775F0(char *arg0) {
    char text[0x100];
    char *g = D_089CBBEC;
    s32 sel;
    s32 row;
    s32 col;
    u16 *p;
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
    case 5:
        x = dx[sel];
        func_0882A9DC(D_089CBBEC, x + 0x1C, 0xF0, 0x33);
        func_08890DFC(D_08A631A8, x + 0x30, 0xF2);
        func_08892004(D_08A631A8, func_09A63198(D_09A44C5C, D_089B53B8));
    case 3:
    case 4:
        func_0887D02C(0xF4, D_089A8846, func_09A63198(D_09A44C5C, D_089B5414), 0x10);
        func_08891474(D_08A631A8, 0xF4, D_089A8846, func_09A63198(D_09A44C5C, D_089B5416), *(s32 *)(arg0 + 0x10), *(s32 *)(arg0 + 0x14));
    case 2:
        func_08890DE8(D_08A631A8, 0xE, 0xE);
        p = (u16 *)(arg0 + *(s32 *)(arg0 + 0x20) * 40 + 0x28);
        for (row = 0; row < 2; row++) {
            for (col = 0; col < 5; col++, p += 2) {
                if (p[0] != 0) {
                    func_0882E2C0(D_089CBBEC, p[0], D_089A8820 + D_089A8828 * row, D_089A8822 + D_089A882A * col, D_089A882C, D_089A882E, 1, 0xFF);
                    func_08891474(D_08A631A8, (s16) (D_089A8824 + D_089A8828 * row), D_089A8826 + D_089A882A * col, func_08851528(D_089CC438, p[0]));
                    func_08891474(D_08A631A8, (s16) (D_089A8838 + D_089A8828 * row), D_089A883A + D_089A882A * col, func_09A63198(D_09A44C5C, D_089B5412), *(s32 *)(&D_0899D198 + p[0] * 0x18 + 0x10), (s16) p[1]);
                }
            }
        }
        func_08890DE8(D_08A631A8, 0x10, 0x10);
        if (*(s32 *)(arg0 + 0x24) > 10) {
            func_0882E6F0(D_089CBBEC, D_089A8808, D_089A880A, D_089A880C, 0xF0);
            func_08891474(D_08A631A8, 0x192, 0x30, func_09A63198(D_09A44C5C, D_089B5420), *(s32 *)(arg0 + 0x20) + 1, (*(s32 *)(arg0 + 0x24) - 1) / 10 + 1);
        }
    case 1:
        func_0880E8F0(text, func_09A63198(D_09A44C5C, D_089B53EA));
        func_0887941C(arg0, 0x30, text);
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
    func_0887D02C(0xF4, D_089A8842, func_09A63198(D_09A44C5C, D_089B5418), 0x10);
    func_08891474(D_08A631A8, 0xF4, D_089A8842, func_09A63198(D_09A44C5C, D_089B541C), *(s32 *)(D_089CC438 + 0x696E8));
}

}