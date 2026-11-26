/* unit_0884BB00: 0x0884BB00-0x0884BB58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884BB00: 0x0884BB00-0x0884BB58 (ULES01213) */

typedef int s32;
typedef signed char s8;

extern s8 D_0893B7BC[];

void func_0884BB00(char *arg0) {
    s32 i;
    s32 j;
    s8 *tbl;
    s32 off;

    i = 0;
    tbl = D_0893B7BC;
    do {
        j = 0;
        if (j < *tbl) {
            off = 0;
            do {
                *(s32 *)(*(char **)(arg0 + 0x1BC) + off) = 0;
                j++;
                off += 4;
            } while (j < *tbl);
        }
        i++;
        arg0 += 4;
        tbl++;
    } while (i < 20);
}
