/* unit_088167F4: 0x088167F4-0x08816818 (ULES01213)
 *
 * Bounds (hypothesis): one function (length of a 16-bit string) between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

int func_088167F4(void *unused, u16 *s) {
    int n = 0;

    if (*s) {
        do {
            s++;
            n++;
        } while (*s);
    }
    return n;
}
