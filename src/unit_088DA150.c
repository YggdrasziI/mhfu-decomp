/* unit_088DA150: 0x088DA150-0x088DA168 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

s32 func_088DA150(s32 arg0, s16 arg1) {
    return ((s16 *)((char *)arg0 + 0x6A0))[arg1] > 0;
}
