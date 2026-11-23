/* unit_08866BD4: 0x08866BD4-0x08866C04 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

/* Returns the word at 0x80248 plus the word at 0x80244, then adds arg1
 * to the word at 0x80244. */
s32 func_08866BD4(char *arg0, s32 arg1) {
    s32 ret = *(s32 *)(arg0 + 0x80248) + *(s32 *)(arg0 + 0x80244);
    *(s32 *)(arg0 + 0x80244) += arg1;
    return ret;
}
