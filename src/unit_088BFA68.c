/* unit_088BFA68: 0x088BFA68-0x088BFBEC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_089B4DB8;
extern char D_089B4DC4;
extern char D_089B4DC8;
extern char *D_08A62C64;
extern s32 D_08A631A0;
extern int func_0880C464(void *, s32, s32);
extern int func_0880ED70(void *, void *);
extern s32 func_088903BC(s32);
extern int sceUtilitySavedataInitStart(void *);

void func_088BFA68(char *arg0) {
    char *temp_a0;

    func_0880C464(arg0 + 0x18, 0, 0x600);
    *(s32 *)(arg0 + 0x18) = 0x600;
    *(s32 *)(arg0 + 0x1C) = func_088903BC(D_08A631A0);
    *(s32 *)(arg0 + 0x20) = 1;
    *(s32 *)(arg0 + 0x24) = 0x32;
    *(s32 *)(arg0 + 0x28) = 0x34;
    *(s32 *)(arg0 + 0x2C) = 0x33;
    *(s32 *)(arg0 + 0x30) = 0x29;
    *(s32 *)(arg0 + 0x48) = 8;
    func_0880ED70(arg0 + 0x54, &D_089B4DB8);
    func_0880ED70(arg0 + 0x64, &D_089B4DC4);
    func_0880ED70(arg0 + 0x7C, &D_089B4DC8);
    *(s32 *)(arg0 + 0x8C) = (s32) *(s32 *)(arg0 + 0x94C);
    *(s32 *)(arg0 + 0x90) = 0x16A100;
    *(s32 *)(arg0 + 0x94) = 0x16A100;
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
    func_0880C464(arg0 + 0x618, 0, 0x14);
    func_0880C464(arg0 + 0x62C, 0, 0x40);
    func_0880C464(arg0 + 0x66C, 0, 0x1C);
    *(char **)(arg0 + 0x5E8) = (char *) (arg0 + 0x618);
    temp_a0 = arg0 + 0x62C;
    *(char **)(arg0 + 0x5EC) = temp_a0;
    func_0880ED70(temp_a0, &D_089B4DB8);
    func_0880ED70(arg0 + 0x63C, &D_089B4DC4);
    *(char **)(arg0 + 0x5F0) = (char *) (arg0 + 0x66C);
    sceUtilitySavedataInitStart(arg0 + 0x18);
    *(s8 *)(arg0 + 0x970) = 1;
    *(s8 *)(D_08A62C64 + 0x17) = 1;
}
