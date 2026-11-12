/* unit_08872FB8: 0x08872FB8-0x08873044 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern s32 func_08872BFC(s32, s32);

void func_08872FB8(s32 arg0, char *arg1) {
    s32 var_t1;
    u16 temp_a2;
    char *temp_a3;
    char *var_t0;

    temp_a2 = *(u16 *)(arg1 + 0x1E6);
    if ((s32) temp_a2 < 2) {
        var_t1 = 0;
        var_t0 = (char *) (arg0 + (temp_a2 * 0x2C));
loop_2:
        temp_a3 = *(char **)(var_t0 + 0x768);
        if ((temp_a3 != 0) && (*(s16 *)(arg1 + 0x4AC) == *(s16 *)(temp_a3 + 0x2C))) {
            *(s8 *)(arg1 + 0x4BC) = (s8) *(s8 *)(temp_a3 + 5);
            func_08872BFC(arg0, (s32) (arg1 + 0x4BC));
            return;
        }
        var_t1 += 1;
        var_t0 += 4;
        if (var_t1 >= 5) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    *(s8 *)(arg1 + 0x4BC) = (s8) *(s8 *)(arg0 + 0x7C0);
}
