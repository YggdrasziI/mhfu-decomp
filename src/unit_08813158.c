/* unit_08813158: 0x08813158-0x08813188 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

s32 func_08813158(char *arg0) {
    if (*(s8 *)(arg0 + 0xDC4) >= 0) {
        return 0;
    }
    if (*(u8 *)(arg0 + 0xA8D) != 0) {
        return 0;
    }
    return *(u8 *)(arg0 + 0x1DE) != 0;
}
