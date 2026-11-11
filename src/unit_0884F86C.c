/* unit_0884F86C: 0x0884F86C-0x0884F8D4 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef short s16;

extern char D_0899A1DC;
extern char D_089BAAA8;
extern char D_089BAC20;
extern int func_0890BFA4(char **);

char *func_0884F86C(void) {
    return &D_0899A1DC;
}

char **func_0884F878(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAAA8;
        if (arg0 != 0) {
            *arg0 = &D_089BAC20;
        }
        if (arg1 > 0) {
            func_0890BFA4(arg0);
        }
    }
    return arg0;
}
