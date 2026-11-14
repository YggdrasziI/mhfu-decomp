/* unit_0888E1C8: 0x0888E1C8-0x0888E1F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;

f32 func_0888E1C8(s32 arg0, char *arg1, char *arg2) {
    return (*(f32 *)(arg1 + 8) * *(f32 *)(arg2 + 8)) + ((*(f32 *)arg1 * *(f32 *)arg2) + (*(f32 *)(arg1 + 4) * *(f32 *)(arg2 + 4)));
}
