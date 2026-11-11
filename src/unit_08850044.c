/* unit_08850044: 0x08850044-0x08850078 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_08850520(s32, s32);

s32 func_08850044(s32 arg0, s32 arg1, s32 arg2) {
    return (func_08850520(arg0, arg1) & 0xFFFF) >= (arg2 & 0xFFFF);
}
