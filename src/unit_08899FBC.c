/* unit_08899FBC: 0x08899FBC-0x0889A008 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_08899F30(s32, s32);
extern s32 func_0889E47C(s32, s32, s32);

void func_08899FBC(s32 arg0, s32 arg1, s32 arg2) {
    func_08899F30(arg0, arg1);
    func_0889E47C(arg0 + 0x1B00, arg1, arg2);
}
