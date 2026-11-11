/* unit_088C0200: 0x088C0200-0x088C022C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

s32 func_088C0200(s32 arg0, s32 arg1, char *arg2) {
    if (arg1 == 1) {
        *(s8 *)(arg2 + 0x978) = 1;
    }
    if (arg1 == 2) {
        *(s8 *)(arg2 + 0x978) = 0;
    }
    return 0;
}
