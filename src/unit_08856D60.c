/* unit_08856D60: 0x08856D60-0x08856DA0 (ULES01213)
 *
 * Bounds (hypothesis): one function (is a byte among 5) between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_08856D60(char *o, u8 v) {
    u8 *p = (u8 *)(o + 0x69942);
    int i = 0;

    do {
        if (*p == v) {
            return 1;
        }
        i++;
        p++;
    } while (i < 5);
    return 0;
}
