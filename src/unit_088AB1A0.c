/* unit_088AB1A0: 0x088AB1A0-0x088AB1CC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern void func_088AB30C(char *, s32, s32, s32);

void func_088AB1A0(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_088AB30C(arg0, arg1, arg2, arg3);
    *(s8 *)(arg0 + 0x174) = 0;
    *(s8 *)(arg0 + 0x175) = 0;
}
