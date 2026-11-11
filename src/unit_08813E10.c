/* unit_08813E10: 0x08813E10-0x08813E20 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;

u8 func_08813E10(char *arg0) {
    return *(u8 *)(arg0 + 0x9BE);
}

u8 func_08813E18(char *arg0) {
    return *(u8 *)(arg0 + 0xA0A);
}
