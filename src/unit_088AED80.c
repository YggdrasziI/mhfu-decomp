/* unit_088AED80: 0x088AED80-0x088AEDA0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_0880BFF0(void *, void *, int);

s32 func_088AED80(char *arg0, char *arg1) {
    return func_0880BFF0(arg0, arg1, 0x90) != 0;
}
