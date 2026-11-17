/* unit_0887CDFC: 0x0887CDFC-0x0887D02C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char D_089A8870;
extern u16 D_089B53A0;
extern u16 D_089B53AE;
extern u16 D_089B53E2;
extern u16 D_089B53EC;
extern u16 D_089B5408;
extern char *D_089CC438;
extern char *D_089CBBEC;
extern char *D_08A631A8;
extern s32 D_09A44C5C;

extern int func_0880E8F0(char *, char *, ...);
extern void func_08825DA8(char *);
extern s32 func_0882A9DC(s32, s32, s32, s32);
extern void func_0882DCA0(s32, u16, u16, u16, u16, s32);
extern int func_08832548(s32, s32);
extern void func_0887941C(s32, s32, char *);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890DFC(char *, s16, s16);
extern int func_08890E08(s32, s32);
extern void func_08890E38(char *, s8);
extern void func_08892004(char *, char *, ...);
extern char *func_09A63198(s32, u16);

void func_0887CDFC(char *arg0) {
    char text[0x100];
    char *g = D_089CBBEC;

    g[0x534] = 9;
    func_08890E08((s32) D_08A631A8, 0);
    func_08825DA8(g);
    func_08832548((s32) D_089CBBEC, 0);
    func_0882DCA0((s32) D_089CBBEC, 0x18, 0x30, 0x1B0, 0xB0, 0xFF);
    func_08890E38(D_08A631A8, 0);
    func_08890DE8(D_08A631A8, 0x10, 0x10);
    func_0880E8F0(text, &D_089A8870, func_09A63198(D_09A44C5C, D_089B53A0));
    func_0887941C((s32) arg0, 0x40, text);
    func_0880E8F0(text, func_09A63198(D_09A44C5C, D_089B53E2), *(u8 *)(D_089CC438 + 0x44BC) + 1);
    func_0887941C((s32) arg0, 0x70, text);
    func_0880E8F0(text, &D_089A8870, func_09A63198(D_09A44C5C, D_089B5408));
    func_0887941C((s32) arg0, 0x60, text);
    if (*(s8 *)(arg0 + 0xC1) == 0 && *(s16 *)(arg0 + 0xAA) < 0x32B) {
        func_0880E8F0(text, func_09A63198(D_09A44C5C, D_089B53AE));
        func_08890DFC(D_08A631A8, 0x190, 0xC0);
        func_08892004(D_08A631A8, &D_089A8870, text);
        func_0882A9DC((s32) D_089CBBEC, 0x17E, 0xBF, 0x33);
    }
    func_08890DFC(D_08A631A8, 0x40, 0xC0);
    func_08892004(D_08A631A8, func_09A63198(D_09A44C5C, D_089B53EC), *(s16 *)(arg0 + 0xAA) / 30);
}