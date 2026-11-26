/* unit_0882981C: 0x0882981C-0x088298E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern char *D_08A62C7C;

extern s32 func_08872D74(char *, s32);
extern s32 func_08872DC4(char *, s32);

s32 func_0882981C(void) {
    s32 i;
    s32 r;

    i = 0;
    do {
        r = func_08872D74(D_08A62C7C, i);
        if (r == 2) {
            goto check;
        } else if (r == 3) {
        check:
            if (func_08872DC4(D_08A62C7C, i) == 2 || func_08872DC4(D_08A62C7C, i) == 0x24
                || func_08872DC4(D_08A62C7C, i) == 0x47) {
                return r == 3;
            }
        }
        i++;
    } while (i < 2);
    return -1;
}
