/* unit_088553DC: 0x088553DC-0x08855410 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_0884FBA4(s32, s32);

void func_088553DC(char *arg0) {
    s32 temp_a1;

    temp_a1 = *(s32 *)(arg0 + 0x47C);
    if (temp_a1 != 0) {
        func_0884FBA4((s32) arg0, temp_a1);
        *(s32 *)(arg0 + 0x47C) = 0;
    }
}
