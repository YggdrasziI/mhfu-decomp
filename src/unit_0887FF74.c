/* unit_0887FF74: 0x0887FF74-0x0887FFE0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern s32 func_0889EA7C(s32, s32, s32);

s32 func_0887FF74(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a0;
    s32 var_v0;
    char *temp_s0;
    char *temp_v0;

    temp_v0 = (char *) (arg0 + (arg1 * 0x14));
    temp_a0 = *(s32 *)(temp_v0 + 0x18);
    temp_s0 = temp_v0 + 0x18;
    var_v0 = -1;
    if ((temp_a0 != 0) && (*(u16 *)(temp_s0 + 0xC) == 0xFFFF)) {
        var_v0 = func_0889EA7C(temp_a0, arg2, arg3);
        if (var_v0 > 0) {
            *(u16 *)(temp_s0 + 0x12) = (u16) (*(u16 *)(temp_s0 + 0x12) | 1);
        }
    }
    return var_v0;
}
