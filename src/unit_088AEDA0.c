/* unit_088AEDA0: 0x088AEDA0-0x088AEE04 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AED80 and unit_088AEE04.
 *
 * Returns 1 when func_088B0514 accepts arg0 against each of the 18
 * 8-byte entries at arg1, 0 at the first refusal.
 */

typedef int s32;

extern s32 func_088B0514(char *, char *);

s32 func_088AEDA0(char *arg0, char *arg1) {
    s32 i;

    i = 0;
    do {
        if (!func_088B0514(arg0, arg1)) {
            return 0;
        }
        i++;
        arg1 += 8;
    } while (i < 0x12);
    return 1;
}
