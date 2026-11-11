/* unit_08862E54: 0x08862E54-0x08862E64 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_08862E54(char *arg0, s32 arg1) {
    return *(s32 *)(arg0 + 0xC) + (arg1 * 8);
}
