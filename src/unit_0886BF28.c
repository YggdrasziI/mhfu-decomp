/* unit_0886BF28: 0x0886BF28-0x0886BFBC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886BF28: copies the -1 terminated word list of arg0 into bytes. */

typedef unsigned char u8;
typedef int s32;

extern s32 *func_08869774(char *, s32);

s32 func_0886BF28(char *arg0, u8 *arg1) {
    s32 *list;
    s32 *other;
    s32 n;

    n = 0;
    list = func_08869774(arg0, 0);
    other = func_08869774(arg0, 1);
    if (list == 0) {
        return 0;
    }
    if (other == 0) {
        return 0;
    }
    for (;;) {
        if (*list == -1) {
            break;
        }
        *arg1 = *list;
        n++;
        arg1++;
        list++;
    }
    return n;
}
