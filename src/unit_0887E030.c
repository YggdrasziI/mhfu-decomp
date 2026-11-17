/* unit_0887E030: 0x0887E030-0x0887E320 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly. The
 * initialised array of its last block (0x089A8A00-0x089A8A0E, in .data) is
 * linked from this unit.
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
extern u16 D_089B53C6;
extern u16 D_089B53C8;
extern u16 D_089B5418;
extern u16 D_089B5438;
extern u16 D_089B543A;
extern u16 D_089B543C;
extern u16 D_089B543E;
extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09A44C5C;

extern void func_08825DA8(char *);
extern s32 func_0882A9DC(s32, s32, s32, s32);
extern void func_0887941C(s32, s32, s32);
extern void func_08879488(char *);
extern void func_0887D02C(s32, s32, char *, s32);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890DFC(char *, s16, s16);
extern int func_08890E08(s32, s32);
extern void func_08890E38(char *, s8);
extern void func_088912BC(char *, s16, s16, s32);
extern void func_08891474(char *, s32, s32, char *, ...);
extern void func_08892004(char *, char *, ...);
extern void func_088920A8(char *, s32, s32, char *, ...);
extern char *func_09A63198(s32, u16);

void func_0887E030(char *arg0) {
    char *g = D_089CBBEC;
    s32 x;

    *(u8 *)(g + 0x534) = 9;
    func_08890E08((s32) D_08A631A8, 0);
    func_08825DA8(g);
    func_08879488(arg0);
    func_08890E38(D_08A631A8, 0);
    func_08890DE8(D_08A631A8, 0x10, 0x10);
    switch (*(s16 *)(arg0 + 0xA4)) {
    case 3:
    default:
        func_0882A9DC((s32) D_089CBBEC, 0x1C, 0xF0, 0x33);
        func_08890DFC(D_08A631A8, 0x30, 0xF2);
        func_08892004(D_08A631A8, func_09A63198(D_09A44C5C, D_089B5438));
    case 2:
        func_0887D02C(0xF4, 0x60, func_09A63198(D_09A44C5C, D_089B543C), 0x10);
        func_088920A8(D_08A631A8, 0xF4, 0x60, &D_089A891C, *(s32 *)(arg0 + 0x14));
    case 1:
        func_0887D02C(0xF4, 0x50, func_09A63198(D_09A44C5C, D_089B543A), 0x10);
        func_088920A8(D_08A631A8, 0xF4, 0x50, &D_089A891C, *(s32 *)(arg0 + 0x120));
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
    func_0887941C((s32) arg0, 0x30, (s32) func_09A63198(D_09A44C5C, D_089B543E));
    func_0887D02C(0xF4, 0xB2, func_09A63198(D_09A44C5C, D_089B5418), 0x10);
    func_08891474(D_08A631A8, 0xF4, 0xB2, &D_089A891C, *(s32 *)(D_089CC438 + 0x696E8));
}
