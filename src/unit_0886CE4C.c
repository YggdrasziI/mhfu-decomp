/* unit_0886CE4C: 0x0886CE4C-0x0886CE90 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;

extern s32 D_09A4F060;

void func_0886CE4C(s32 arg0, s32 arg1, char *arg2) {
    s32 temp_a3;

    temp_a3 = arg1 << 5;
    *(f32 *)((char *)((temp_a3 + D_09A4F060)) + 4) = *(f32 *)arg2;
    *(f32 *)((char *)((temp_a3 + D_09A4F060)) + 8) = *(f32 *)(arg2 + 4);
    *(f32 *)((char *)((temp_a3 + D_09A4F060)) + 0xC) = *(f32 *)(arg2 + 8);
}
