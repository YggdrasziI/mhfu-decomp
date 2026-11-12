/* unit_0885F9A0: 0x0885F9A0-0x0885FA0C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_0885F848(s32, s32, s32, s32, s32);
extern int func_0885F928(int, int, int);

void func_0885F9A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    temp_v0 = func_0885F928(arg0, arg0, arg2);
    if (temp_v0 != 0) {
        func_0885F848(arg0, temp_v0, arg1, arg2, arg3);
    }
}
