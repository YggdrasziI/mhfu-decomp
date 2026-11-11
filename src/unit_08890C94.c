/* unit_08890C94: 0x08890C94-0x08890CE0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

void func_08890C94(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *var_v1;

    if (arg1 < 0) {
        var_v1 = (int *) (arg0 + 0x164);
    } else {
        var_v1 = (int *) (arg0 + (arg1 * 4) + 0x168);
    }
    *var_v1 = ((arg3 & 0xFF) << 0x10) | ((arg3 & 0xFF00) | ((arg2 & 0xFF000000) | ((u32) (arg3 & 0xFF0000) >> 0x10)));
}
