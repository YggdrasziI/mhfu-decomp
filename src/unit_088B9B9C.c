/* unit_088B9B9C: 0x088B9B9C-0x088B9BF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;

extern char D_089BAB98;
extern char D_089BAC80;
extern int func_08897298(char **);

char **func_088B9B9C(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAC80;
        if (arg0 != 0) {
            *arg0 = &D_089BAB98;
        }
        if (arg1 > 0) {
            func_08897298(arg0);
        }
    }
    return arg0;
}
