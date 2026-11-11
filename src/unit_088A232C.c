/* unit_088A232C: 0x088A232C-0x088A2338 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

void func_088A232C(char *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x60) = (s32) (arg1 != 0);
}
