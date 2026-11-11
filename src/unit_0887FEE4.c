/* unit_0887FEE4: 0x0887FEE4-0x0887FF1C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_0889EA54(s32);

void func_0887FEE4(char *arg0, s32 arg1) {
    func_0889EA54(arg1);
    *(s32 *)(arg0 + 8) = arg1;
}
