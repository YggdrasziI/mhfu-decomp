/* unit_08857058: 0x08857058-0x088570D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

s32 func_08857058(char *arg0, s32 arg1, s32 arg2) {
    s32 n;
    s32 w;

    if (arg1 >= 0x5209 && arg1 < 0x5220) {
        n = arg2 + (arg1 - 0x5209) * 5;
        w = ((s32 *)(arg0 + 0x696D4))[n / 32];
        return (w & (1 << (n % 32))) != 0;
    }
    return 0;
}
