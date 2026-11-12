/* unit_08813E70: 0x08813E70-0x08813E90 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;

extern char *D_089CC438;

s16 func_08813E70(char *arg0) {
    if (*(u8 *)(D_089CC438 + 0x422) == 0) {
        return -1;
    }
    return *(s16 *)(arg0 + 0x964);
}
