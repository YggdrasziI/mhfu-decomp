/* unit_08854D64: 0x08854D64-0x08854D88 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_08854BEC(s32, s32);

s32 func_08854D64(s32 arg0) {
    return (func_08854BEC(arg0, 4) & 0xFF) != 0;
}
