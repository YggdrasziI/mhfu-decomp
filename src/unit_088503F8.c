/* unit_088503F8: 0x088503F8-0x0885048C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char D_0899BF40;
extern u16 func_0884FF24(s32, s32);

u16 func_088503F8(s32 arg0, s32 arg1) {
    u8 *var_s2;
    u16 var_s0;
    s32 var_a1;

    var_s0 = 0;
    var_s2 = (u8 *)(((s32 *)&D_0899BF40)[(arg1 & 0xFF)]);
    for (var_a1 = *var_s2; var_a1 != 0xFF; var_a1 = *++var_s2) {
        var_s0 += func_0884FF24(arg0, var_a1);
    }
    if (var_s0 > 9999) {
        var_s0 = 9999;
    }
    return var_s0;
}
