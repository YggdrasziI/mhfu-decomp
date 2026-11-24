/* unit_0885058C: 0x0885058C-0x088505E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885058C: adds to a counter at +0x696EC, capped at 9999999. */

typedef unsigned int u32;

u32 func_0885058C(char *arg0, u32 arg1) {
    u32 v = *(u32 *)(arg0 + 0x696EC) + arg1;

    if (v > 9999999) {
        *(u32 *)(arg0 + 0x696EC) = 9999999;
    } else {
        *(u32 *)(arg0 + 0x696EC) = v;
    }
    return *(u32 *)(arg0 + 0x696EC);
}
