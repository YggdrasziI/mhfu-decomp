/* unit_08878B60: 0x08878B60-0x08878BC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between text_088785CC and unit_08878BC0.
 *
 * The sltu/xori test comes from `!!`; the loop is a do-while (no jump to the
 * test on entry).
 */

typedef int s32;

extern s32 func_088785CC(char *, s32);

s32 func_08878B60(char *arg0) {
    s32 i;

    i = 0;
    do {
        if (!!func_088785CC(arg0, i)) {
            return 1;
        }
        i++;
    } while (i < 0x1B);
    return 0;
}