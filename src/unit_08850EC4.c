/* unit_08850EC4: 0x08850EC4-0x08850EFC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;

s16 func_08850E58();

s16 func_08850EC4(void) {
    return (s16) (func_08850E58() * 0x64);
}
