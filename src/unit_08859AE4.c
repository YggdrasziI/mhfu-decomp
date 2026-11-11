/* unit_08859AE4: 0x08859AE4-0x08859AF0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_08859AF0(char *);

void func_08859AE4(char *arg0, s32 arg1, s32 arg2) {
    *(s32 *)arg0 = arg2;
    *(s32 *)(arg0 + 0x4) = arg1;
    func_08859AF0(arg0);
}
