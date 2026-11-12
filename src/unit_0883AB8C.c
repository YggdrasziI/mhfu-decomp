/* unit_0883AB8C: 0x0883AB8C-0x0883ABE0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0B544;
extern s32 func_0889D7E8(s32, s32);
extern s32 func_0889D848(s32, s32);

s32 func_0883AB8C(s32 arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v1;

    temp_s0 = func_0889D7E8(D_09A0B544, arg1);
    temp_v0 = func_0889D848(D_09A0B544, arg1);
    var_v1 = temp_s0 != 0;
    if (var_v1 == 0) {
        var_v1 = temp_v0 != 0;
    }
    return var_v1;
}
