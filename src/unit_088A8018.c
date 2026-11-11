/* unit_088A8018: 0x088A8018-0x088A8028 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_088A8018(char *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0x124) = arg1;
    *(s32 *)(arg0 + 0x12C) = arg2;
    return -arg1;
}
