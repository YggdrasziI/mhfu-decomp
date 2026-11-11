/* unit_08882F58: 0x08882F58-0x08882F64 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D94;
extern void func_088867F4(s32, s32);

void func_08882F58(s32 arg0, s32 arg1) {
    func_088867F4(D_08A62D94, arg1);
}
