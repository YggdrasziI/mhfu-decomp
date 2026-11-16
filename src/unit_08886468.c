/* unit_08886468: 0x08886468-0x08886530 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern int func_08886850(char *, s32, s32, s16);
extern s32 func_088A2338(void *);

void func_08886468(char *arg0) {
    s16 temp_a0;
    s16 temp_a2;
    s16 temp_a3;
    s16 temp_v0;
    s32 var_s1;
    char *var_s0;

    var_s1 = 0;
    var_s0 = arg0;
    do {
        if (*(char **)var_s0 == 0) {
            *(s32 *)(var_s0 + 8) = -1;
        } else {
            temp_a0 = *(s16 *)(var_s0 + 0x16);
            if ((temp_a0 > 0) && (*(s32 *)(var_s0 + 8) == 3)) {
                temp_v0 = temp_a0 - 1;
                *(s16 *)(var_s0 + 0x16) = temp_v0;
                temp_a3 = *(s16 *)(var_s0 + 0x14);
                temp_a2 = *(s16 *)(var_s0 + 0x10);
                func_08886850(arg0, var_s1, temp_a2 + ((s32) ((*(s16 *)(var_s0 + 0x12) - temp_a2) * (temp_a3 - temp_v0)) / temp_a3), temp_a3);
            }
            *(s32 *)(var_s0 + 8) = func_088A2338(*(char **)var_s0);
        }
        var_s1 += 1;
        var_s0 += 0x18;
    } while (var_s1 < 2);
}
