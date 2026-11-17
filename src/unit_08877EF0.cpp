/* unit_08877EF0: 0x08877EF0-0x088785CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_08877C04 and text_088785CC.
 *
 * C++: the local table is declared after the first calls. Optimized for
 * speed: divisions by a constant are multiplications.
 *
 * .data: the initializer of the local offset table (7 halfwords, then 2 bytes
 * of padding before the .data of unit_08879198).
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {

extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09A44C5C;
extern s16 D_089A8874;
extern s16 D_089A8876;
extern s16 D_089A8878[2];
extern s16 D_089A887C[2];
extern s16 D_089A8880;
extern s16 D_089A8882;
extern s16 D_089A8884[2];
extern u16 D_089A8888;
extern u16 D_089A888A;
extern u16 D_089A888C;
extern u16 D_089A888E;
extern s16 D_089A8890;
extern s16 D_089A8892;
extern s16 D_089A8894;
extern s16 D_089A8896;
extern u16 D_089A8898;
extern u16 D_089A889A;
extern u16 D_089A889C;
extern u16 D_089A889E;
extern u16 D_089AC63A;
extern u16 D_089AC65C[];
extern u16 D_089B53A0[];
extern u16 D_089B53AA;
extern u16 D_089B53AE;
extern u16 D_089B53B0;
extern u16 D_089B53B6;
extern u16 D_089B53EC;

extern char *func_0882FD68(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern int func_08832548(char *, s32);
extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern char *func_09A63198(s32, u16);
extern void func_0887941C(char *, s32, char *);
extern char *func_0885151C(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern s16 func_0887959C(char *, char *, s16);
extern void func_0887D02C(u16, u16, char *, s32);
extern float func_08850238(char *, u8, u16);
extern float func_08850078(char *, u8, s32);
extern float func_08850158(char *, u8, s32);
extern u16 func_0885028C(char *, u8, s32);
extern u16 func_08850338(char *, u8, s32);
extern void func_08891474(char *, s32, s32, char *, ...);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_088920A8(char *, s32, s32, char *, ...);
extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);
extern s32 func_0882FE34(char *, u16, u16, u8, u8);
extern void func_0881A7A4(char *, char *, s32, s32, s32);

void func_08877EF0(char *arg0) {
    char text[0x100];
    u8 *e;
    char *r;
    char *g;
    u16 *msg;
    s32 a;
    s32 b;
    s32 n;
    u16 v;
    float f;

    e = (u8 *) arg0 + *(u8 *) (arg0 + 0x1F) * 4 + 0xD0;
    r = func_0882FD68(D_089CBBEC, e[0]);
    func_08890E38(D_08A631A8, 0);
    func_08890DE8(D_08A631A8, 0x10, 0x10);
    s16 offs[7] = {0, 0, 8, 8, 8, 8, 0};
    D_089A8898 = D_089A887C[0] = D_089A8878[0] = offs[*(s32 *) (D_08A631A0 + 0xF7A574)] + 0x13C;
    g = D_089CBBEC;
    g[0x534] = 9;
    func_08890E08(D_08A631A8, 0);
    func_08825DA8(g);
    func_08832548(D_089CBBEC, 0);
    func_0882DCA0(D_089CBBEC, 0x18, 0x30, 0x1B0, 0xB0, 0xFF);
    func_0887941C(arg0, D_089A8874, func_09A63198(D_09A44C5C, D_089B53AA));
    g = func_0885151C(D_089CC438, D_089AC63A);
    func_0880E8F0(text, g, func_0885151C(D_089CC438, D_089AC65C[e[0]]));
    func_0887941C(arg0, D_089A8876, text);
    switch (func_0887959C(arg0, r, *(s16 *) (e + 2))) {
    case 1:
        func_08890E38(D_08A631A8, 0xB);
        break;
    case 2:
        func_08890E38(D_08A631A8, 7);
        break;
    default:
        func_08890E38(D_08A631A8, 0);
        break;
    }
    if (e[1] == 0) {
        n = 6;
    } else if (e[1] == 1) {
        n = 9;
    } else {
        n = 10;
    }
    msg = &D_089B53A0[n];
    func_0887D02C(D_089A8878[0], D_089A8878[1], func_09A63198(D_09A44C5C, *msg), 0x10);
    f = func_08850238(D_089CC438, e[0], *(u16 *) (e + 2)) + 0.05f;
    if (*(u16 *) (e + 2) == 0) {
        func_0880E8F0(text, func_09A63198(D_09A44C5C, D_089B53B0));
    } else {
        a = f;
        b = (s32) (10.0f * f) % 10;
        func_0880E8F0(text, func_09A63198(D_09A44C5C, D_089B53B6), a, b);
    }
    func_08891474(D_08A631A8, D_089A8878[0], D_089A8878[1], text);
    if (e[1] != 2) {
        v = func_0885028C(D_089CC438, e[0], 0);
    } else {
        v = func_08850338(D_089CC438, e[0], 0);
    }
    switch (func_0887959C(arg0, r, v)) {
    case 1:
        func_08890E38(D_08A631A8, 0xB);
        break;
    case 2:
        func_08890E38(D_08A631A8, 7);
        break;
    default:
        func_08890E38(D_08A631A8, 0);
        break;
    }
    func_0887D02C(D_089A887C[0], D_089A887C[1], func_09A63198(D_09A44C5C, *msg), 0x10);
    if (e[1] != 2) {
        f = func_08850078(D_089CC438, e[0], 1) + 0.05f;
    } else {
        f = func_08850158(D_089CC438, e[0], 1) + 0.05f;
    }
    a = f;
    b = (s32) (10.0f * f) % 10;
    func_08891474(D_08A631A8, D_089A887C[0], D_089A887C[1], func_09A63198(D_09A44C5C, D_089B53B6), a, b);
    func_08890E38(D_08A631A8, 0);
    if (*(s8 *) (arg0 + 0xC1) == 0 && *(s16 *) (arg0 + 0xA8) <= 0) {
        func_08891474(D_08A631A8, D_089A8884[0], D_089A8884[1], func_09A63198(D_09A44C5C, D_089B53AE));
        func_0882A9DC(D_089CBBEC, (u16) D_089A8884[0] - 0x12, (u16) D_089A8884[1] - 1, 0x33);
    }
    func_088920A8(D_08A631A8, D_089A8880, D_089A8882, func_09A63198(D_09A44C5C, D_089B53EC), *(s16 *) (arg0 + 0xAC) / 30);
    func_0882AF70(D_089CBBEC, D_089A8888, D_089A888A, 0x50, 0x40, 0xAF);
    func_0882AF70(D_089CBBEC, D_089A8898, D_089A889A, D_089A889C, D_089A889E, 0x9C);
    func_0882FE34(D_089CBBEC, D_089A888C, D_089A888E, r[1], r[2]);
    func_0881A7A4(D_089CBBEC, r, D_089A8890, D_089A8892, *(s16 *) (e + 2));
    if (e[1] != 2) {
        v = func_0885028C(D_089CC438, e[0], 0);
    } else {
        v = func_08850338(D_089CC438, e[0], 0);
    }
    func_0881A7A4(D_089CBBEC, r, D_089A8894, D_089A8896, (s16) v);
}

}
