/* unit_088CE05C: 0x088CE05C-0x088CE1AC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern char D_089BAB28;
extern char D_089BADAC;
extern int func_0880C464(char *, s32, s32);
extern char func_0886159C;
extern void func_08864440(char *);
extern char func_088CE1AC;
extern int func_0890BEC0(char *, char *, char *, s32, s32);

char *func_088CE05C(char *arg0) {
    func_08864440(arg0);
    *(char **)arg0 = &D_089BADAC;
    func_0890BEC0(arg0 + 0x8D0, &func_088CE1AC, &func_0886159C, 0x140, 5);
    *(char **)(arg0 + 0xF80) = &D_089BAB28;
    *(s32 *)(arg0 + 0x1090) = 0;
    *(s32 *)(arg0 + 0x1094) = 0;
    *(s32 *)(arg0 + 0x1098) = 0;
    *(s32 *)(arg0 + 0x109C) = 0;
    *(s8 *)(arg0 + 0x10A8) = 0;
    *(s16 *)(arg0 + 0x10B0) = 0;
    *(s16 *)(arg0 + 0x10B8) = 0;
    *(s8 *)(arg0 + 0x10A9) = 0;
    *(s16 *)(arg0 + 0x10B2) = 0;
    *(s16 *)(arg0 + 0x10BA) = 0;
    *(s8 *)(arg0 + 0x10AA) = 0;
    *(s16 *)(arg0 + 0x10B4) = 0;
    *(s16 *)(arg0 + 0x10BC) = 0;
    *(s8 *)(arg0 + 0x10AB) = 0;
    *(s16 *)(arg0 + 0x10B6) = 0;
    *(s16 *)(arg0 + 0x10BE) = 0;
    *(s16 *)(arg0 + 0x10A0) = 0;
    *(s16 *)(arg0 + 0x10A2) = 0;
    *(s8 *)(arg0 + 0x1E9) = 0;
    *(s32 *)(arg0 + 0x614) = 0;
    *(s8 *)(arg0 + 0x2A4) = 0;
    *(s32 *)(arg0 + 0x618) = 0;
    func_0880C464(arg0 + 0x830, 0, 0xA0);
    func_0880C464(arg0 + 0x8D0, 0, 0x640);
    func_0880C464(arg0 + 0xF10, 0, 0x50);
    func_0880C464(arg0 + 0xF60, 0, 0x20);
    func_0880C464(arg0 + 0xF80, 0, 0x140);
    func_0880C464(arg0 + 0x10C0, 0, 0x10);
    func_0880C464(arg0 + 0x1DC, 0, 8);
    *(s8 *)(arg0 + 0x7F0) = 0;
    *(s8 *)(arg0 + 0x612) = 0;
    *(s32 *)(arg0 + 0x7F4) = 0;
    func_0880C464(arg0 + 0x7F8, 0, 0x30);
    *(s32 *)(arg0 + 0x408) = 1;
    *(s32 *)(arg0 + 0x40C) = 0;
    return arg0;
}
