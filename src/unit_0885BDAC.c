/* unit_0885BDAC: 0x0885BDAC-0x0885BE08 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_0885B5B8(s32, s32, s32, s32, s32, s32);
extern s32 func_0885BE08(s32, s32, s32);

s32 func_0885BDAC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    temp_v0 = func_0885B5B8(arg0, arg1, arg2, arg3 == 1, 0, 0);
    if (temp_v0 == 0) {
        return -1;
    }
    return func_0885BE08(arg0, temp_v0, arg3);
}
