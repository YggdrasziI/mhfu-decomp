/* unit_088EF380: 0x088EF380-0x088EF3E0 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef int s32;

extern s32 D_09A521A0;
extern s32 D_09A521A4;

s32 func_088EF380(char *arg0) {
    *(s32 *)((*(char **)(arg0 + 0x18)) + 4) = (s32) D_09A521A4;
    *(s32 *)((*(char **)(arg0 + 0x18)) + 0) = (s32) D_09A521A0;
    return 1;
}

void func_088EF3A8(char *arg0, s32 arg1) {
    char *temp_a0;
    char *temp_a2;

    if (arg1 > 0) {
        temp_a2 = *(char **)(arg0 + 0x18);
        *(s32 *)temp_a2 = (s32) (*(s32 *)temp_a2 + arg1);
        temp_a0 = *(char **)(arg0 + 0x18);
        *(s32 *)(temp_a0 + 4) = (s32) (*(s32 *)(temp_a0 + 4) - arg1);
    }
}

void func_088EF3D8(void) {
}
