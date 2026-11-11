/* unit_0885E9F8: 0x0885E9F8-0x0885EA08 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern void func_0885E988(s32, char *);

void func_0885E9F8(s32 arg0, char *arg1, s32 arg2) {
    ((s16 *)(arg1 + 0x6))[arg2] = 0;
    func_0885E988(arg0, arg1);
}
