/* unit_0884054C: 0x0884054C-0x088405E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;

extern void func_0882D470(s32, s32, s32, s32, s32, s32, s32, s16, s32, s32);

void func_0884054C(s32 arg0, s32 arg1, s32 arg2) {
    s16 v = arg1 / 1800 / 5 * 0x1555;

    func_0882D470(arg0, 0x23, 0x21, 5, 0x10, 9, 0x12, v, 0xFF, arg2 ? 2 : 1);
}