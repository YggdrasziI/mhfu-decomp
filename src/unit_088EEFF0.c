/* unit_088EEFF0: 0x088EEFF0-0x088EF000 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;

void func_088EEFF0(char *arg0) {
    *(s8 *)((*(char **)(arg0 + 0x1A8)) + 0x1C) = 1;
}
