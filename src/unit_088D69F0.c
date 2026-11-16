/* unit_088D69F0: 0x088D69F0-0x088D6A1C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

s32 func_088D69F0(char *arg0) {
    if (*(s16 *)(arg0 + 0x446) > 0) {
        return 1;
    }
    if (*(s16 *)(arg0 + 0x458) > 0) {
        return 2;
    }
    return 0;
}
