/* unit_08850EC4: 0x08850EC4-0x08850EFC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;

s16 func_08850E58(char *);

s16 func_08850EC4(char *arg0) {
    return (s16) (func_08850E58(arg0) * 0x64);
}
