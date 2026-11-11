/* unit_0886A73C: 0x0886A73C-0x0886A77C (ULES01213)
 *
 * Bounds (hypothesis): one function (counts two entries below their maximum) between unrelated code.
 */

int func_0886A73C(signed char *o) {
    int n = 0;
    int i;

    for (i = 0; i < 2; i++, o += 0x2C) {
        if (o[0x786] > 0 && o[0x787] < o[0x786]) {
            n++;
        }
    }
    return n;
}
