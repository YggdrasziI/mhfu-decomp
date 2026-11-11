/* unit_08861604: 0x08861604-0x0886167C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;

extern char D_089BAB18;
extern char D_089BAB28;
extern char D_089BAB34;
extern int func_088626DC(char *);

char *func_08861604(char *arg0, s16 arg1) {
    if (arg0 != 0) {
        *(char **)arg0 = &D_089BAB18;
        if ((arg0 + 0x80) != 0) {
            *(char **)(arg0 + 0x80) = &D_089BAB28;
        }
        if (arg0 != 0) {
            *(char **)arg0 = &D_089BAB34;
        }
        if (arg1 > 0) {
            func_088626DC(arg0);
        }
    }
    return arg0;
}
