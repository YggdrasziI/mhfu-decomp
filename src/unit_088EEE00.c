/* unit_088EEE00: 0x088EEE00-0x088EEE38 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 func_088EE0D4(s32, s32);

void func_088EEE00(char *arg0) {
    char *temp_s0;

    temp_s0 = *(char **)(arg0 + 0x1A8);
    *(s32 *)(arg0 + 0x74) = (s32) *(s32 *)(temp_s0 + 0x10);
    func_088EE0D4((s32) arg0, *(s32 *)(temp_s0 + 0x14));
    *(s8 *)(temp_s0 + 0x1C) = 1;
}
