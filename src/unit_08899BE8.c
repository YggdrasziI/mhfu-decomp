/* unit_08899BE8: 0x08899BE8-0x08899D00 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern int func_0880C084(void *, void *, s32);
extern int func_0880C464(void *, s32, s32);
extern char func_0889A614;
extern int func_088B3778(char *, char *, char *);

void func_08899BE8(char *arg0, char *arg1, char *arg2, s32 arg3, s8 arg4, char *arg5, s32 arg6) {
    *(s32 *)(arg0 + 0x12C0) = (s32) (*(s32 *)(arg0 + 0x12C0) | 0x80);
    if (arg1 != 0) {
        func_0880C084(arg0 + 0xEE8, arg1, 0x12);
    } else {
        func_0880C464(arg0 + 0xEE8, 0, 0x12);
    }
    *(s16 *)(arg0 + 0xEFA) = 0x12;
    if (arg2 != 0) {
        func_0880C084(arg0 + 0xF00, arg2, 0x42);
    } else {
        func_0880C464(arg0 + 0xF00, 0, 0x42);
    }
    *(s16 *)(arg0 + 0xF42) = 0x42;
    if (arg5 != 0) {
        func_0880C084(arg0 + 0xF50, arg5, arg6);
    } else {
        func_0880C464(arg0 + 0xF50, 0, 8);
    }
    *(s32 *)(arg0 + 0xF48) = arg3;
    *(s8 *)(arg0 + 0xF4C) = arg4;
    func_088B3778(arg0 + 0xEE8, &func_0889A614, arg0);
    *(s8 *)(arg0 + 0x146C) = 0;
}
