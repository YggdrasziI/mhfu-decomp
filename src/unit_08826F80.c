/* unit_08826F80: 0x08826F80-0x08826FCC (ULES01213)
 *
 * Bounds (hypothesis): 1 count of used slots, divided, between unrelated code.
 */

typedef unsigned char u8;

u8 func_08826F80(char *p, int n) {
    char *e = p + 0x684;
    int i = 0;

    do {
        if (*(u8 *)(e + 2) == 0) {
            break;
        }
        i++;
        e += 0x12;
    } while (i < 0x36);
    if (i == 0) {
        return 1;
    }
    return (i - 1) / n + 1;
}
