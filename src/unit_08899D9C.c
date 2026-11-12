/* unit_08899D9C: 0x08899D9C-0x08899DE0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_08899E80(s32, s32);
extern s32 func_0889E47C(s32, s32, s32);

s32 func_08899D9C(s32 arg0, s32 arg1, s32 arg2) {
    func_08899E80(arg0, arg1);
    func_0889E47C(arg0 + 0x1B00, arg0 + 0x12C8, arg2);
    return arg0 + 0x12C8;
}
