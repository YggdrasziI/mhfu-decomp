/* unit_08880324: 0x08880324-0x08880350 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_0889EAE8(s32, s32, s32);

s32 func_08880324(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return (func_0889EAE8(arg1, arg2, arg3) & 0xFF) > 0;
}
