/* unit_08869564: 0x08869564-0x08869570 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;

void func_08869564(char *arg0) {
    *(s8 *)(arg0 + 0x11C) = 1;
}
