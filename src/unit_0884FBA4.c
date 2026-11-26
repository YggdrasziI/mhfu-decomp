/* unit_0884FBA4: 0x0884FBA4-0x0884FC0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884FBA4: adds to a signed counter at +0x696F0, clamped to 0..9999999. */

void func_0884FBA4(char *arg0, int arg1) {
    int v = *(int *)(arg0 + 0x696F0) + arg1;

    *(int *)(arg0 + 0x696F0) = v;
    if (v > 9999999) {
        *(int *)(arg0 + 0x696F0) = 9999999;
    }
    if (*(int *)(arg0 + 0x696F0) < 0) {
        *(int *)(arg0 + 0x696F0) = 0;
    }
}
