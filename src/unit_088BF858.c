/* unit_088BF858: 0x088BF858-0x088BFA68 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_089B2D94;
extern char D_089B2DB4;
extern char D_089B2DC0;
extern char D_089B4DB8;
extern char D_089B4DC4;
extern char D_089B4DC8;
extern char *D_08A62C64;
extern s32 D_08A631A0;
extern int func_0880C464(void *, s32, s32);
extern int func_0880ED70(void *, void *);
extern s32 func_088903BC(s32);
extern int sceUtilitySavedataInitStart(void *);

void func_088BF858(char *arg0, s32 arg1) {
    func_0880C464(arg0 + 0x18, 0, 0x600);
    *(s32 *)(arg0 + 0x18) = 0x600;
    *(s32 *)(arg0 + 0x1C) = func_088903BC(D_08A631A0);
    *(s32 *)(arg0 + 0x20) = 1;
    *(s32 *)(arg0 + 0x24) = 0x32;
    *(s32 *)(arg0 + 0x28) = 0x34;
    *(s32 *)(arg0 + 0x2C) = 0x33;
    *(s32 *)(arg0 + 0x30) = 0x29;
    *(s32 *)(arg0 + 0x48) = arg1;
    *(s32 *)(arg0 + 0x50) = 1;
    *(s32 *)(arg0 + 0x94) = 0x16A100;
    func_0880ED70(arg0 + 0x98, &D_089B2D94);
    func_0880ED70(arg0 + 0x118, &D_089B2DB4);
    func_0880ED70(arg0 + 0x198, &D_089B2DC0);
    *(u8 *)(arg0 + 0x598) = 5;
    *(s32 *)(arg0 + 0x5A4) = 0x65F1;
    *(s32 *)(arg0 + 0x5B4) = 0;
    *(s32 *)(arg0 + 0x5C4) = 0x3E2AC;
    *(s32 *)(arg0 + 0x5D4) = 0;
    func_0880ED70(arg0 + 0x54, &D_089B4DB8);
    func_0880ED70(arg0 + 0x64, &D_089B4DC4);
    func_0880ED70(arg0 + 0x7C, &D_089B4DC8);
    *(s32 *)(arg0 + 0x8C) = (s32) *(s32 *)(arg0 + 0x94C);
    *(s32 *)(arg0 + 0x90) = 0x16A100;
    *(s32 *)(arg0 + 0x59C) = (s32) *(s32 *)(arg0 + 0x10);
    *(s32 *)(arg0 + 0x5A0) = 0x7000;
    *(s32 *)(arg0 + 0x5A4) = 0x7000;
    *(s32 *)(arg0 + 0x5AC) = 0;
    *(s32 *)(arg0 + 0x5B0) = 0;
    *(s32 *)(arg0 + 0x5B4) = 0;
    *(s32 *)(arg0 + 0x5BC) = (s32) *(s32 *)(arg0 + 0x14);
    *(s32 *)(arg0 + 0x5C0) = 0x3E800;
    *(s32 *)(arg0 + 0x5C4) = 0x3E800;
    *(s32 *)(arg0 + 0x5CC) = 0;
    *(s32 *)(arg0 + 0x5D0) = 0;
    *(s32 *)(arg0 + 0x5D4) = 0;
    *(s32 *)(arg0 + 0x5DC) = 0;
    *(u8 *)(arg0 + 0x5F4) = 0x4A;
    *(u8 *)(arg0 + 0x5F5) = 0x1F;
    *(u8 *)(arg0 + 0x5F6) = 0xF3;
    *(u8 *)(arg0 + 0x5F7) = 0x59;
    *(u8 *)(arg0 + 0x5F8) = 0xAE;
    *(u8 *)(arg0 + 0x5F9) = 0xB6;
    *(u8 *)(arg0 + 0x5FA) = 0xEF;
    *(u8 *)(arg0 + 0x5FB) = 0xF8;
    *(u8 *)(arg0 + 0x5FC) = 0x1C;
    *(u8 *)(arg0 + 0x5FD) = 0xA8;
    *(u8 *)(arg0 + 0x5FE) = 0xCB;
    *(u8 *)(arg0 + 0x5FF) = 0x23;
    *(u8 *)(arg0 + 0x600) = 0xBC;
    *(u8 *)(arg0 + 0x601) = 0xA5;
    *(u8 *)(arg0 + 0x602) = 0x7B;
    *(u8 *)(arg0 + 0x603) = 0xB3;
    *(s32 *)(arg0 + 0x604) = 0;
    sceUtilitySavedataInitStart(arg0 + 0x18);
    *(u8 *)(arg0 + 0x970) = 1;
    *(u8 *)(D_08A62C64 + 0x17) = 1;
}
