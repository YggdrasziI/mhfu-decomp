/* unit_0884FC0C: 0x0884FC0C-0x0884FC74 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884FC0C: add to a counter at offset 0x696E8, clamp to [0, 9999999]. */

void func_0884FC0C(char *arg0, int arg1) {
    int v;

    v = *(int *)(arg0 + 0x696E8) + arg1;
    *(int *)(arg0 + 0x696E8) = v;
    if (v > 9999999) {
        *(int *)(arg0 + 0x696E8) = 9999999;
    }
    if (*(int *)(arg0 + 0x696E8) < 0) {
        *(int *)(arg0 + 0x696E8) = 0;
    }
}
