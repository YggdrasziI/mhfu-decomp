/* unit_0887D884: 0x0887D884-0x0887DD88 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_0887D65C and unit_0887DD88.
 * Its jump table (0x08931934-0x08931954) and the initialised array of its
 * last block (0x089A89E4-0x089A89F2, in .data) are linked from this unit.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char D_089A891C;
extern char D_089A89F4;
extern u16 D_089B53C6;
extern u16 D_089B53C8;
extern u16 D_089B5422;
extern u16 D_089B5424;
extern u16 D_089B5426;
extern u16 D_089B5428;
extern u16 D_089B542A;
extern u16 D_089B542C;
extern u16 D_089B542E;
extern u16 D_089B5430;
extern u16 D_089B5432;
extern u16 D_089B5434;
extern u16 D_089B5438;
extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A62CB4;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09A44C5C;

extern void func_08825DA8(char *);
extern s32 func_0882A9DC(s32, s32, s32, s32);
extern void func_0887941C(s32, s32, s32);
extern void func_08879488(char *);
extern void func_0887D02C(s32, s32, char *, s32);
extern s32 func_0887EB80(char *);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890DFC(char *, s16, s16);
extern int func_08890E08(s32, s32);
extern void func_08890E38(char *, s8);
extern void func_088912BC(char *, s16, s16, s32);
extern void func_08891474(char *, s32, s32, char *, ...);
extern void func_08892004(char *, char *, ...);
extern void func_088920A8(char *, s32, s32, char *, ...);
extern char *func_09A63198(s32, u16);

void func_0887D884(char *arg0) {
    char *g = D_089CBBEC;
    s32 t;
    s32 x;

    *(u8 *)(g + 0x534) = 9;
    func_08890E08((s32) D_08A631A8, 0);
    func_08825DA8(g);
    func_08879488(arg0);
    func_08890E38(D_08A631A8, 0);
    func_08890DE8(D_08A631A8, 0x10, 0x10);
    switch (*(s16 *)(arg0 + 0xA4)) {
    default:
        if (*(s32 *)(arg0 + 0x124) & 2) {
            func_08890E38(D_08A631A8, 5);
            func_088920A8(D_08A631A8, 0x134, 0xB2, func_09A63198(D_09A44C5C, D_089B5434));
            func_08890E38(D_08A631A8, 0);
        }
    case 7:
        func_0882A9DC((s32) D_089CBBEC, 0x1C, 0xF0, 0x33);
        func_08890DFC(D_08A631A8, 0x30, 0xF2);
        func_08892004(D_08A631A8, func_09A63198(D_09A44C5C, D_089B5438));
    case 6:
        func_0887D02C(0xF4, 0x90, func_09A63198(D_09A44C5C, D_089B542E), 0x10);
        func_088920A8(D_08A631A8, 0x104, 0x90, func_09A63198(D_09A44C5C, D_089B5430), *(s32 *)(arg0 + 0x11C));
    case 5:
        func_0887D02C(0xF4, 0x80, func_09A63198(D_09A44C5C, D_089B542C), 0x10);
        func_088920A8(D_08A631A8, 0xF4, 0x80, &D_089A891C, *(s32 *)(arg0 + 0x118));
    case 4:
        func_0887D02C(0xF4, 0x70, func_09A63198(D_09A44C5C, D_089B542A), 0x10);
        func_088920A8(D_08A631A8, 0xF4, 0x70, &D_089A891C, *(s32 *)(arg0 + 0x114));
    case 3:
        func_0887D02C(0xF4, 0x60, func_09A63198(D_09A44C5C, D_089B5428), 0x10);
        func_088920A8(D_08A631A8, 0xF4, 0x60, &D_089A891C, *(s32 *)(arg0 + 0x110));
    case 2:
        func_0887D02C(0xF4, 0x50, func_09A63198(D_09A44C5C, D_089B5426), 0x10);
        func_088920A8(D_08A631A8, 0xF4, 0x50, &D_089A891C, *(s32 *)(arg0 + 0x10C));
    case 1:
        func_0887D02C(0xF4, 0x40, func_09A63198(D_09A44C5C, D_089B5424), 0x10);
        t = func_0887EB80(arg0);
        func_088920A8(D_08A631A8, 0xFC, 0x40, &D_089A89F4, t / 60, t % 60);
        if (*(s32 *)(arg0 + 0x124) & 1) {
            func_08890E38(D_08A631A8, 5);
            func_088920A8(D_08A631A8, 0x134, 0x40, func_09A63198(D_09A44C5C, D_089B5434));
            func_08890E38(D_08A631A8, 0);
        }
    case 0:
        break;
    }
    func_08890DFC(D_08A631A8, 0xFC, 0xF2);
    func_08892004(D_08A631A8, func_09A63198(D_09A44C5C, D_089B53C6), *(s16 *)(arg0 + 0xAA) / 30);
    {
        s16 offsets[7] = {0, 0, 0, 0, 0, 0x1C, 0};

        x = offsets[*(s32 *)(D_08A631A0 + 0xF7A574)] + 0xF4;
    }
    func_0887D02C(x, 0xF, func_09A63198(D_09A44C5C, D_089B53C8), 0x10);
    func_088912BC(D_08A631A8, x, 0xF, (s32) (D_089CC438 + 0x4A0));
    func_0887941C((s32) arg0, 0x30, (s32) func_09A63198(D_09A44C5C, D_089B5422));
    func_0887D02C(0xF4, 0xB2, func_09A63198(D_09A44C5C, D_089B5432), 0x10);
    func_08891474(D_08A631A8, 0xF4, 0xB2, &D_089A891C, *(s32 *)(D_08A62CB4 + 0x14));
}
