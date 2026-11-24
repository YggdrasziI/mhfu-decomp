/* unit_088551F0: 0x088551F0-0x08855278 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned long long u64;

extern void func_08858840(char *, s32, s32);

void func_088551F0(char *arg0, s32 arg1) {
    *(u64 *)(arg0 + 0x678A0) |= (u64)1 << arg1;
    func_08858840(arg0, 8, arg1);
}
