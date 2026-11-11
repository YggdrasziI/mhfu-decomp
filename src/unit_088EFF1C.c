/* unit_088EFF1C: 0x088EFF1C-0x088EFF78 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;

extern char D_089BAB08;
extern char D_089BAEA4;
extern int func_08860760(char **);

char **func_088EFF1C(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAEA4;
        if (arg0 != 0) {
            *arg0 = &D_089BAB08;
        }
        if (arg1 > 0) {
            func_08860760(arg0);
        }
    }
    return arg0;
}
