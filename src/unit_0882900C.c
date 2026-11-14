/* unit_0882900C: 0x0882900C-0x088290A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern char D_08938AFC;
extern char D_08939140;
extern char *D_089CC438;

void func_0882900C(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3, s32 arg4) {
    s32 temp_a5;
    u32 temp_a0;
    char *var_a6;

    temp_a5 = arg4 & 0xFFFF;
    var_a6 = &D_08938AFC + (temp_a5 * 6);
    if (*(u8 *)(D_089CC438 + 0x6AF10) == 0xF) {
        temp_a0 = temp_a5 - 0x80;
        if (temp_a0 < 2U) {
            var_a6 = &D_08939140 + (temp_a0 * 6);
        }
    }
    *arg1 = (f32) *(s16 *)var_a6;
    *arg2 = (f32) *(s16 *)(var_a6 + 2);
    *arg3 = (f32) *(s16 *)(var_a6 + 4);
}
