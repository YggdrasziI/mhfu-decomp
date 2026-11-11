/* unit_088E0DE4: 0x088E0DE4-0x088E0DFC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_088EF224(s32, s32, s32, s32, s32, s32);

void func_088E0DE4(char *arg0, char *arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_088EF224(*(s32 *)arg1, arg2, arg3, 0, arg4, *(s32 *)(arg0 + 0x5c));
}
