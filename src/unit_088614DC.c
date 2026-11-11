/* unit_088614DC: 0x088614DC-0x0886159C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern char D_089BAB18;
extern char D_089BAB28;
extern char D_089BAB34;
extern int func_0880C464(char *, s32, s32);

char *func_088614DC(char *arg0) {
    *(char **)arg0 = &D_089BAB34;
    *(char **)arg0 = &D_089BAB18;
    *(char **)(arg0 + 0x80) = &D_089BAB28;
    *(s32 *)(arg0 + 0x190) = 0;
    *(s32 *)(arg0 + 0x194) = 0;
    *(s32 *)(arg0 + 0x198) = 0;
    *(s32 *)(arg0 + 0x19C) = 0;
    *(s8 *)(arg0 + 0x1A8) = 0;
    *(s16 *)(arg0 + 0x1B0) = 0;
    *(s16 *)(arg0 + 0x1B8) = 0;
    *(s8 *)(arg0 + 0x1A9) = 0;
    *(s16 *)(arg0 + 0x1B2) = 0;
    *(s16 *)(arg0 + 0x1BA) = 0;
    *(s8 *)(arg0 + 0x1AA) = 0;
    *(s16 *)(arg0 + 0x1B4) = 0;
    *(s16 *)(arg0 + 0x1BC) = 0;
    *(s8 *)(arg0 + 0x1AB) = 0;
    *(s16 *)(arg0 + 0x1B6) = 0;
    *(s16 *)(arg0 + 0x1BE) = 0;
    *(s16 *)(arg0 + 0x1A0) = 0;
    *(s16 *)(arg0 + 0x1A2) = 0;
    func_0880C464(arg0 + 0x50, 0, 0x20);
    func_0880C464(arg0 + 0x80, 0, 0x140);
    func_0880C464(arg0 + 0x70, 0, 0x10);
    return arg0;
}
