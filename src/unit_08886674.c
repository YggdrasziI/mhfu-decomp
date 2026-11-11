/* unit_08886674: 0x08886674-0x088866D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_088A1914(s32, s32, s32, s32);

void func_08886674(s32 arg0, s32 arg1) {
    s32 *temp_s0;

    temp_s0 = (int *) (arg0 + (arg1 * 0x18));
    if (*temp_s0 == 0) {
        *temp_s0 = func_088A1914(arg1, arg1 + 1, arg0 + (arg1 * 0x4400) + 0x180, 0x4400);
    }
}
