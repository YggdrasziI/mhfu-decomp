/* unit_08812938: 0x08812938-0x088129B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char *D_089CBBE4;
extern char func_088129B8;
extern char func_088129F8;
extern int func_0890BEC0(char *, char *, char *, s32, s32);

char *func_08812938(char *arg0) {
    D_089CBBE4 = arg0;
    func_0890BEC0(arg0 + 0xB0, &func_088129F8, &func_088129B8, 0x1A0, 6);
    *(s8 *)(arg0 + 0xAAA) = 1;
    *(s32 *)(arg0 + 0xB70) = 0x44E20000;
    *(s32 *)(arg0 + 0xB74) = 0x44EF0000;
    *(s32 *)(arg0 + 0xC) = 0x3F5F49F5;
    *(s32 *)(arg0 + 0x10) = 0xC479C000;
    *(s32 *)(arg0 + 0xB34) = 0;
    return arg0;
}
