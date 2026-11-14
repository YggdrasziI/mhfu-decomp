/* unit_0886CEA8: 0x0886CEA8-0x0886CF78 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;
typedef float f32;

extern s32 D_09A4F060;

char *func_0886CEA8(s32 arg0, char *arg1) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    s32 var_a3;
    char *var_v0;

    var_a3 = 0;
    var_v0 = (char *) (D_09A4F060 + 4);
loop_1:
    if ((*(u16 *)(var_v0 + 0x10) != 0xFFFF) && (*(u16 *)(var_v0 + 0x18) == *(u16 *)(arg1 + 0x29A))) {
        temp_f2 = *(f32 *)(var_v0 + 4);
        temp_f1 = *(f32 *)(arg1 + 0x204);
        if ((temp_f1 >= (temp_f2 - 200.0f)) && (temp_f1 < (100.0f + temp_f2))) {
            temp_f3 = *(f32 *)(arg1 + 0x200) - *(f32 *)var_v0;
            temp_f0 = *(f32 *)(arg1 + 0x208) - *(f32 *)(var_v0 + 8);
            temp_f2_2 = *(f32 *)(var_v0 + 0xC);
            if ((temp_f2_2 * temp_f2_2) >= ((temp_f3 * temp_f3) + (temp_f0 * temp_f0))) {
                return var_v0;
            }
        }
    }
    var_a3 += 1;
    var_v0 += 0x20;
    if (var_a3 >= 0x14) {
        return 0;
    }
    goto loop_1;
}
