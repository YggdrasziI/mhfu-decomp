/* unit_088912BC: 0x088912BC-0x088912F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern void func_08890DFC(void *, s16, s16);
extern int func_088911A0(char *, s32);

void func_088912BC(char *arg0, s16 arg1, s16 arg2, s32 arg3) {
    func_08890DFC(arg0, arg1, arg2);
    func_088911A0(arg0, arg3);
}
