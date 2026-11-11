/* unit_08894B00: 0x08894B00-0x08894B0C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_089AD404;
extern void func_08891E0C(s32, s32, s32);

void func_08894B00(s32 arg0, s32 arg1, s32 arg2) {
    func_08891E0C(arg0, D_089AD404, arg2);
}
