/* unit_088B0318: 0x088B0318-0x088B0324 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_088B040C(s32, s32, s32);

void func_088B0318(s32 arg0, s32 arg1) {
    func_088B040C(arg0, 6, arg1);
}
