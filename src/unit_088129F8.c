/* unit_088129F8: 0x088129F8-0x08812A08 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;

char *func_088129F8(char *arg0) {
    *(s8 *)(arg0 + 0x90) = 0;
    *(s8 *)(arg0 + 0x92) = 0;
    return arg0;
}
