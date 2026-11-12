/* unit_08816A60: 0x08816A60-0x08816AE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern char *D_089CBBEC;
extern int func_0880C464(char *, s32, s32);
extern char func_08816B24;
extern char func_08816B64;
extern int func_0890BEC0(char *, char *, char *, s32, s32);

char *func_08816A60(char *arg0) {
    D_089CBBEC = arg0;
    func_0890BEC0(arg0 + 0xE28, &func_08816B64, &func_08816B24, 0x24, 0x14);
    func_0880C464(arg0, 0, 0x1220);
    *(s32 *)(arg0 + 0x5A8) = 0;
    func_0880C464(arg0 + 0xE28, 0, 0x2D0);
    *(s32 *)(arg0 + 0x1198) = 0;
    *(s16 *)(arg0 + 0x119E) = 0;
    *(s16 *)(arg0 + 0x119C) = 0;
    *(s32 *)(arg0 + 0x528) = 0;
    *(s8 *)(arg0 + 0x608) = 0;
    return arg0;
}
