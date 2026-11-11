/* unit_08899DE0: 0x08899DE0-0x08899E80 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern int func_0880C084(char *, s32, s32);
extern int func_0880C464(char *, s32, s32);
extern char func_0889A700;
extern int func_088B3A68(char *, char *, char *, char *);

void func_08899DE0(char *arg0, s8 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0x12C0) = (s32) (*(s32 *)(arg0 + 0x12C0) | 0x100);
    if (arg2 != 0) {
        func_0880C084(arg0 + 0x12A8, arg2, 0x12);
    } else {
        func_0880C464(arg0 + 0x12A8, 0, 0x12);
    }
    *(s16 *)(arg0 + 0x12BA) = 0x12;
    func_088B3A68(arg0 + (arg1 * 0x64) + 0x12DC, arg0 + 0x12A8, &func_0889A700, arg0);
}
