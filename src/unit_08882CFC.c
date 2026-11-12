/* unit_08882CFC: 0x08882CFC-0x08882D20 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_0888670C(s32, s32);
extern s32 D_08A62D94;

s32 func_08882CFC(s32 arg0, s32 arg1) {
    return func_0888670C(D_08A62D94, arg1) & 0xFFFF;
}
