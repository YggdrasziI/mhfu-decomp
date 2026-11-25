/* unit_0885C718: 0x0885C718-0x0885C75C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885C718: counts the leading D_089A5B58 thresholds (at most 6) that
 * are strictly greater than arg0. */

typedef signed char s8;
typedef unsigned char u8;

extern u8 D_089A5B58[];

u8 func_0885C718(s8 arg0) {
    u8 i = 0;

    do {
        if (arg0 >= D_089A5B58[i]) {
            break;
        }
        i++;
    } while (i < 6);
    return i;
}
