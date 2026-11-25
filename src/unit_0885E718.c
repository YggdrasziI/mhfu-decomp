/* unit_0885E718: 0x0885E718-0x0885E748 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885E718: counts the non-zero u16 values among the three at arg1 + 6.
 * arg0 is unused (its register is reused as the loop counter).
 */

typedef unsigned short u16;
typedef int s32;

s32 func_0885E718(s32 arg0, u16 *arg1) {
    s32 n = 0;
    s32 i;

    for (i = 0; i < 3; i++) {
        if (arg1[3] != 0) {
            n++;
        }
        arg1++;
    }
    return n;
}
