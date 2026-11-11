/* unit_0885AA20: 0x0885AA20-0x0885AA7C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;

extern char D_089BAAF4;
extern char D_089BAB98;
extern int func_08897298(char **);

char **func_0885AA20(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAAF4;
        if (arg0 != 0) {
            *arg0 = &D_089BAB98;
        }
        if (arg1 > 0) {
            func_08897298(arg0);
        }
    }
    return arg0;
}
