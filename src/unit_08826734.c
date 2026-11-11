/* unit_08826734: 0x08826734-0x0882675C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

s16 *func_08856884(s32, s32);
extern s32 D_089CC438;

s16 func_08826734(s32 arg0, s32 arg1) {
    return *func_08856884(D_089CC438, arg1 & 0xFF);
}
