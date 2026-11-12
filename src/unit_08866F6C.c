/* unit_08866F6C: 0x08866F6C-0x08866FB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_088673CC(s32, s32, s32);

s32 func_08866F6C(s32 arg0, s32 arg1, s32 arg2) {
    return (func_088673CC(arg0, ((arg2 & 0xFFFF) + 0xD50) & 0xFFFF, (((arg1 & 0xFF) * 8) + 6) & 0xFF) & 0xFF) == 1;
}
