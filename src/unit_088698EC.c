/* unit_088698EC: 0x088698EC-0x08869904 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_088698EC(char *arg0) {
    return (**(s32 **)(arg0 + 0x68) & 0x800000) != 0;
}
