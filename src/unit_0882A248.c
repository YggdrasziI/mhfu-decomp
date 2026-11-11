/* unit_0882A248: 0x0882A248-0x0882A28C (ULES01213)
 *
 * Bounds (hypothesis): 1 free-slot search, between unrelated code.
 */

typedef signed char s8;

char *func_0882A248(char *p) {
    int i = 0;
    char *q = p;

    do {
        if (*(s8 *)(q + 0x112C) == 0) {
            return p + i * 0xC + 0x112A;
        }
        i++;
        q += 0xC;
    } while (i < 6);
    return 0;
}
