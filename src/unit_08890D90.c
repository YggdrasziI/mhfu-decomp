/* unit_08890D90: 0x08890D90-0x08890DE8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern void func_08890C94(s32, s32, s32, s32);
extern void func_08890E38(void *, s8);

s8 func_08890D90(char *arg0, s32 arg1) {
    s8 temp_s0;

    temp_s0 = *(s8 *)(arg0 + 0x131);
    func_08890C94((s32) arg0, (s32) temp_s0, 0, arg1);
    func_08890E38(arg0, temp_s0);
    *(s8 *)(arg0 + 0x131) = (s8) (*(s8 *)(arg0 + 0x131) + 1);
    return temp_s0;
}
