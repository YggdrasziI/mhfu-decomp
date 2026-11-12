/* unit_0890BE00: 0x0890BE00-0x0890BE54 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern char D_08933190;
extern char D_089BAEDC;
extern int func_0890BFA4(s32);

char **func_0890BE00(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAEDC;
        if (arg1 > 0) {
            func_0890BFA4((s32) arg0);
        }
    }
    return arg0;
}

char *func_0890BE48(void) {
    return &D_08933190;
}
