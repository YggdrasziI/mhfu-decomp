/* unit_0889842C: 0x0889842C-0x088984A8 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef short s16;

extern char D_089BAAA8;
extern char D_089BABAC;
extern char D_089BAC20;
extern char **D_089CC434;
extern void func_0890BFA4(char **);

char **func_0889842C(char **arg0) {
    D_089CC434 = arg0;
    *arg0 = &D_089BAC20;
    *arg0 = &D_089BAAA8;
    *arg0 = &D_089BABAC;
    return arg0;
}

char **func_08898460(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAC20;
        if (arg1 > 0) {
            func_0890BFA4(arg0);
        }
    }
    return arg0;
}
