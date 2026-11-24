/* unit_08857148: 0x08857148-0x088571C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08857148: sets bit ((arg1 - 0x5209) * 5 + arg2) of the bit array at arg0 + 0x696D4 */

typedef int s32;

void func_08857148(char *arg0, s32 arg1, s32 arg2) {
    s32 n;

    if (arg1 >= 0x5209 && arg1 < 0x5220) {
        n = arg2 + (arg1 - 0x5209) * 5;
        ((s32 *)(arg0 + 0x696D4))[n / 32] |= 1 << (n % 32);
    }
}
