/* unit_08882F64: 0x08882F64-0x08882FA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_0888671C(s32, s32);
extern s32 D_08A62D94;

s32 func_08882F64(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_0888671C(D_08A62D94, arg1);
    if ((temp_v0 > 0) && (temp_v0 < 5)) {
        return 1;
    }
    return 0;
}
