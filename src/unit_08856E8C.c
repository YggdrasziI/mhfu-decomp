/* unit_08856E8C: 0x08856E8C-0x08856F04 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern s32 func_08857058(char *, s32, s32);

s32 func_08856E8C(char *arg0) {
    s32 i;
    s32 j;

    i = 0x5209;
    do {
        j = 0;
        do {
            if (func_08857058(arg0, i, j) == 0) {
                return 0;
            }
            j++;
        } while (j < 5);
        i++;
    } while (i < 0x5213);
    return 1;
}
