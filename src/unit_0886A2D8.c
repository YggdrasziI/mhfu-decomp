/* unit_0886A2D8: 0x0886A2D8-0x0886A30C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D90;
extern s32 func_0886A30C(s32, s32);
extern int func_09A64E48(s32, s32);

void func_0886A2D8(s32 arg0) {
    if (func_0886A30C(arg0, 1) == 0) {
        func_09A64E48(D_08A62D90, 0);
    }
}
