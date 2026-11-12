/* unit_088912F8: 0x088912F8-0x0889134C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern void func_08890DFC(void *, s16, s16);
extern void func_08890E38(void *, s8);
extern int func_088911A0(void *, s32);

void func_088912F8(char *arg0, s16 arg1, s16 arg2, s8 arg3, s32 arg4) {
    func_08890DFC(arg0, arg1, arg2);
    func_08890E38(arg0, arg3);
    func_088911A0(arg0, arg4);
}
