/* unit_0886C1E0: 0x0886C1E0-0x0886C218 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern s32 func_0886C008(s32, s32, s32);

void func_0886C1E0(s32 arg0, s32 arg1, s16 arg2) {
    func_0886C008(arg0, arg1, (s32) (s16) -arg2);
    *(s8 *)(arg0 + 0x81) = 1;
}
