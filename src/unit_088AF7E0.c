/* unit_088AF7E0: 0x088AF7E0-0x088AF848 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AF75C and unit_088AF848.
 *
 * Returns 1 when func_088B0514 accepts arg0 against each of the four
 * 0xC8-byte records at D_09A1FE98, 0 at the first refusal (as
 * func_088AEDA0).
 */

typedef int s32;

extern char D_09A1FE98[];

extern s32 func_088B0514(char *, char *);

s32 func_088AF7E0(char *arg0) {
    s32 i;
    char *r;

    r = D_09A1FE98;
    i = 0;
    do {
        if (!func_088B0514(r, arg0)) {
            return 0;
        }
        i++;
        r += 0xC8;
    } while (i < 4);
    return 1;
}
