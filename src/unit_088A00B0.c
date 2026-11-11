/* unit_088A00B0: 0x088A00B0-0x088A00D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_088A4344(s32);

s32 func_088A00B0(char *arg0) {
    func_088A4344(*(s32 *)(arg0 + 0x10));
    return 0;
}
